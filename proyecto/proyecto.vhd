---------------------------------------------------------------------
--
--  	Engineer: Javier Antonio Ricaldi Esquivel
--					 Dario Fernado Gallegos Quispe
--
--    Profesor: J.M. Mendias
--    Diseño Automático de Sistemas
--    Facultad de Informática. Universidad Complutense de Madrid
--
--  	Propósito:
-- 		Proyecto final Juego ArkaPong
--
--  	Notas de diseño:
--
---------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity proyecto is
	port ( 
		rstPb_n : in  std_logic;
		osc     : in  std_logic;
		ps2Clk  : in  std_logic;
		ps2Data : in  std_logic;
		hSync   : out std_logic;
		vSync   : out std_logic;
		RGB     : out std_logic_vector(8 downto 0);
		switches_n : in std_logic_vector(3 downto 0);
		display : out std_logic_vector(7 downto 0)
	);
end proyecto;

---------------------------------------------------------------------

library ieee;
use ieee.numeric_std.all;
use work.common.all;

architecture syn of proyecto is

	constant CLKFREQ : natural := 50_000_000;  -- frecuencia del reloj en MHz

	constant	DATA_WIDTH	: natural := 4;
	constant MAX_SIZE		: natural := 19_200;

	signal clk, rst_n : std_logic;
	--Señales para PS2
	signal data: std_logic_vector(7 downto 0);
	signal dataRdy: std_logic;
	signal qP, aP, pP, lP, spcP: boolean;

	--Señales para RAM
	signal weB: std_logic;
	signal dInB: std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal addrA : std_logic_vector(log2(MAX_SIZE)-1 downto 0);
	signal addrB : std_logic_vector(log2(MAX_SIZE)-1 downto 0);
	signal dOutA: std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal dOutB: std_logic_vector(DATA_WIDTH - 1 downto 0);
	
	signal level: std_logic_vector(3 downto 0);
	signal we1 : std_logic;
	signal we2 : std_logic;
	signal we3 : std_logic;
	signal dOutA1 : std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal dOutA2 : std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal dOutA3 : std_logic_vector(DATA_WIDTH - 1 downto 0);
	
	signal dOutB1 : std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal dOutB2 : std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal dOutB3 : std_logic_vector(DATA_WIDTH - 1 downto 0);



	signal colorR : std_logic_vector(2 downto 0);
	signal colorG : std_logic_vector(2 downto 0);
	signal colorB : std_logic_vector(2 downto 0);
	signal color : std_logic;
	signal colorAux : std_logic_vector(1 downto 0);

	--Señales
	signal raquetaDer, raquetaIzq, pelota: std_logic;

	signal mover, finPartida, reiniciar: boolean;

	signal lineAux, pixelAux : std_logic_vector(9 downto 0);

	signal line, yRight, yLeft, yBall: unsigned(7 downto 0);
	signal pixel, xBall: unsigned(7 downto 0);
	
	signal speed : natural := 1_020_408;
  
begin

	clk <= osc;
	
	
	resetSyncronizer : synchronizer
		generic map ( STAGES => 2, INIT => '0' )
		port map ( rst_n => rstPb_n, clk => clk, x => '1', xSync => rst_n );
		
		
	switchesSynchronizer : 
	for i in switches_n'range generate
	begin
		switchsynchronizer : synchronizer
			generic map ( STAGES => 2, INIT => '1' )
			port map ( rst_n => rst_n, clk => clk, x => not(switches_n(i))  ,xSync => level(i) );
	end generate;
	
	display7 : bin2segs 
  port map( bin => level , dp => '0', segs => display);

	------------------  

	ps2KeyboardInterface : ps2Receiver
		generic map ( REGOUTPUTS => false )
		port map ( rst_n => rst_n, clk => clk, dataRdy => dataRdy, data => data, ps2Clk => ps2Clk, ps2Data => ps2Data);

	keyScanner:
	process( rst_n, clk )
	 type states is (keyON, keyOFF);
	 variable state : states;
	 begin
	 if rst_n='0' then
		state := keyON;
		qP <= false;
		aP <= false;
		lP <= false;
		pP <= false;
		spcP <= false;
	 elsif rising_edge(clk) then
		if dataRdy='1' then
		  case state is
			 when keyON =>
				case data is
				  when X"F0" => state := keyOFF;
				  when X"15" => qP <= true;
				  when X"1C" => aP <= true;
				  when X"4B" => lP <= true;
				  when X"4D" => pP <= true;
				  when X"29" => spcP <= true;
				  when others => state := keyON;
				end case;
			 when keyOFF =>
				state := keyON;
				case data is
				  when X"15" => qP <= false; 
				  when X"1C" => aP <= false;
				  when X"4B" => lP <= false;
				  when X"4D" => pP <= false;
				  when others => spcP <= false;
			 end case;
		  end case;
		end if;
	 end if;
	end process;        

	------------------  

	screenInteface: vgaInterface
		generic map ( FREQ => 50_000, SYNCDELAY => 0 )
		port map ( rst_n => rst_n, clk => clk, line => lineAux, pixel => pixelAux, R => colorR, G => colorG, B => colorB, hSync => hSync, vSync => vSync, RGB => RGB);

	pixel <= unsigned(pixelAux(9 downto 2));
	line <= unsigned(lineAux(9 downto 2));


	colorAux <= "11" when dOutA(2 downto 0) = "111" else "00";
	
	colorR <= "111" when color = '1' else dOutA(2) & colorAux;
	colorG <= "111" when color = '1' else dOutA(1) & colorAux;
	colorB <= "111" when color = '1' else dOutA(0) & colorAux;
	
	color <= '1' when raquetaIzq = '1' or raquetaDer = '1'  or pelota ='1' else '0';

	
	
	
	------------------
	level1: ram1
		port map (rst_n => rst_n, clk => clk, dInB => dInB, addrA => addrA, addrB => addrB, weB => we1, dOutA => dOutA1, dOutB => dOutB1);
	level2: ram2
		port map (rst_n => rst_n, clk => clk, dInB => dInB, addrA => addrA, addrB => addrB, weB => we2, dOutA => dOutA2, dOutB => dOutB2);
	level3: ram3
		port map (rst_n => rst_n, clk => clk, dInB => dInB, addrA => addrA, addrB => addrB, weB => we3, dOutA => dOutA3, dOutB => dOutB3);
		
		
	dInB <= X"8";	
		
	addrA<= std_logic_vector(line * 160 + pixel);
	addrB <= std_logic_vector(yBall * 160 + xBall);	
	
	changeLevel:
	process (level)
	begin
		we1 <= '0';
		we2 <= '0';
		we3 <= '0';
		case level is
			when "0000" => 
				dOutA <= dOutA1;
				dOutB <= dOutB1;
				we1 <= weB;
			when "0001" => 
				dOutA <= dOutA2;
				dOutB <= dOutB2;
				we2 <= weB;
			when others => 
				dOutA <= dOutA3;
				dOutB <= dOutB3;
				we3 <= weB;
		end case;
	end process;
	
	

	------------------
	raquetaIzq <= '1' when pixel=8 and (line >= yLeft and line < yLeft+16) else '0';
	raquetaDer <= '1' when pixel=151 and (line >= yRight and line < yRight+16) else '0';
	pelota     <= '1' when line = yBall and pixel = xBall else '0';	
	------------------

	finPartida <= true when ((xBall = 0 or xBall = 159 ) and reiniciar = false) else false;
	reiniciar <=  true when finPartida = true and spcP = true else false;   
	
	
	------------------


	pulseGen:
	process (rst_n, clk, speed)
	 --constant maxValue : natural := CLKFREQ/speed; --CLKFREQ/50-1;
	 variable count: natural := 0;
	begin
	if rst_n = '0' then
		mover <= false;
		count := 0;
	 elsif rising_edge(clk) then
		if count = speed then
			mover <= true;
			count := 0;
		else
			mover<= false;
			count := count + 1;
		end if;
	 end if;
	end process;    
		  
	-------------------

	yRightRegister:
	process (rst_n, clk)
	begin
	 if rst_n = '0' then
		yRight <="00110000";
	 elsif rising_edge(clk) then
		if mover = true and finPartida = false then
			if pP = true and  yRight > 10 then
				yRight <= yRight - 1;
			elsif lP = true and yRight < (111 - 16) then
				yRight <= yRight + 1;
			end if;
		end if;
	 
	 end if;
	 
	end process;

	yLeftRegister:
	process (rst_n, clk)
	begin
	  if rst_n = '0' then
		yLeft <= "00110000";
	 elsif rising_edge(clk) then
		if mover = true  and finPartida = false then
			if qP = true and yLeft>10 then
				yLeft <= yLeft - 1;
			elsif aP = true and yLeft < (111 - 16) then
				yLeft <= yLeft + 1;
			end if;
		end if;
	 end if;
	end process;

	--------------------

	xBallRegister:
	process (rst_n, clk)
	 type sense is (left, right);
	 variable dir: sense;
	 begin
	 if rst_n = '0' then
		xBall <= "00001010";
		weB<='0';
		dir:= right;
	 elsif rising_edge(clk) then
		weB <= '0';
		if mover = true and finPartida = false then
			if dir = right then
				if (xBall = 151 and yBall >= yRight and yBall <= ( yRight + 16 )) or (dOutB(2 downto 0) /= "000" ) then -- Si choca con la barra derecha o con algo
						speed <= 1_020_408;
						if (xBall = 151 and yBall >= yRight and yBall <= (yRight + 2)) or (xBall = 151 and yBall >= (yRight + 14) and yBall <= ( yRight + 16 )) then 
							speed <= 390_000;
							dir := left;
						else
							--speed <= 1_020_408;
							if dOutB(2 downto 0) /= "111" then --si no es blanco(pixel impenetrable)
								weB <= '1';
							else 
								xBall<= xBall - 1; -- actualizamos en este caso para evitar el bloqueo
							end if;
							
							if dOutB(3) = '1' then 
								dir := left;		
							end if;
						end if;
				else
					xBall<= xBall + 1;	
				end if;
			elsif dir = left then 
				if (xBall= 8 and yBall >= yLeft and yBall <= ( yLeft + 16 )) or (dOutB(2 downto 0) /= "000") then --si choca con la barra izquierda o con algo
						speed <= 1_020_408;
						if (xBall= 8 and yBall >= yLeft and yBall <= (yLeft + 2)) or (xBall= 8 and yBall >= 14 and yBall <= ( yLeft + 16 )) then
							speed <= 390_000;
							dir := right;
						else
							--speed <= 1_020_408;
							if dOutB(2 downto 0) /= "111" then
								weB <= '1';
							else
								xBall<= xBall + 1; -- actualizamos en este caso para evitar el bloqueo
							end if;
							
							if dOutB(3) = '1' then
								dir := right;
							end if;
						end if;
				else
					xBall<= xBall - 1;					
				end if;
			end if;
		end if;
	 end if;-- clock
	 if reiniciar = true then
			xBall <= "00100000";
			weB <= '0';
			dir:= right;
		end if;
	end process;

	yBallRegister:
	process (rst_n, clk)
	 type sense is (up, down);
	 variable dir: sense;
	begin
	 if rst_n = '0' then
		yBall <= "00110011";
		dir := up;
	 elsif rising_edge(clk) then
		if mover = true and finPartida = false then
			if dir = up then
				if dOutB(2 downto 0) /= "000" then --si choca contra algo	
					
					if dOutB(3) = '0' then --si el pixel es horizontal
						if dOutB(2 downto 0) = "111" then 
							yBall <= yBall + 1;
						end if;
							dir := down;
					end if;		
									
				else

					if aP = true and (xBall= 8 and yBall >= yLeft and yBall <= ( yLeft + 16 )) then
						yBall <= yBall + 1;
						dir := down;
					elsif lP = true and (xBall = 151 and yBall >= yRight and yBall <= ( yRight + 16 )) then
						yBall <= yBall + 1;
						dir := down;
					else
						yBall <= yBall - 1;
					end if;	
					
				end if;
			elsif dir = down then
				if dOutB(2 downto 0) /= "000" then -- choca contra algo							
						if dOutB(3) = '0' then --si el pixel es horizontal
							if dOutB(2 downto 0) = "111" then 
								yBall <= yBall - 1;
							end if;
							dir:= up;
						end if;	
				else
					if pP = true and (xBall = 151 and yBall >= yRight and yBall <= ( yRight + 16 )) then --jug der arriba y choque con la raqueta der
						yBall <= yBall - 1;
						dir:= up;
					elsif qP = true and (xBall= 8 and yBall >= yLeft and yBall <= ( yLeft + 16 )) then --jug iz arriba y choque con la raqueta iz
						yBall <= yBall - 1;
						dir:= up;						
					else
						yBall <= yBall + 1;
					end if;
					
				end if;
			end if;
		end if;
	 end if;-- clock
	 if reiniciar = true then
			yBall <= "00110000";
			dir := up;
		end if;
	end process;

end syn;

