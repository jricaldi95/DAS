---------------------------------------------------------------------
--
--  Fichero:
--    lab6.vhd  15/7/2015
--
--    (c) J.M. Mendias
--    Diseño Automático de Sistemas
--    Facultad de Informática. Universidad Complutense de Madrid
--
--  Propósito:
--    Laboratorio 6
--
--  Notas de diseño:
--
---------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity lab6 is
  port ( 
    rstPb_n : in  std_logic;
    osc     : in  std_logic;
    ps2Clk  : in  std_logic;
    ps2Data : in  std_logic;
    hSync   : out std_logic;
    vSync   : out std_logic;
    RGB     : out std_logic_vector(8 downto 0)
  );
end lab6;

---------------------------------------------------------------------

library ieee;
use ieee.numeric_std.all;
use work.common.all;

architecture syn of lab6 is

  constant CLKFREQ : natural := 50_000_000;  -- frecuencia del reloj en MHz

  signal clk, rst_n : std_logic;

  signal data: std_logic_vector(7 downto 0);
  signal dataRdy: std_logic;
  signal qP, aP, pP, lP, spcP: boolean;
  
  signal color : std_logic_vector(2 downto 0);
  
  signal campoJuego, raquetaDer, raquetaIzq, pelota: std_logic;
  
  signal mover, finPartida, reiniciar: boolean;

  signal lineAux, pixelAux : std_logic_vector(9 downto 0);
  
  signal line, yRight, yLeft, yBall: unsigned(7 downto 0);
  signal pixel, xBall: unsigned(7 downto 0);
  
begin

  clk <= osc;
  
  resetSyncronizer : synchronizer
    generic map ( STAGES => 2, INIT => '0' )
    port map ( rst_n => rstPb_n, clk => clk, x => '1', xSync => rst_n );

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
				  when X"4D" => lP <= true;
				  when X"4B" => pP <= true;
				  when X"29" => spcP <= true;
				  when others => state := keyON;
            end case;
          when keyOFF =>
            state := keyON;
            case data is
              when X"15" => qP <= false; 
				  when X"1C" => aP <= false;
				  when X"4D" => lP <= false;
				  when X"4B" => pP <= false;
				  when others => spcP <= false;
          end case;
        end case;
      end if;
    end if;
  end process;        

------------------  

  screenInteface: vgaInterface
    generic map ( FREQ => 50_000, SYNCDELAY => 0 )
    port map ( rst_n => rst_n, clk => clk, line => lineAux, pixel => pixelAux, R => color, G => color, B => color, hSync => hSync, vSync => vSync, RGB => RGB);

  pixel <= unsigned(pixelAux(9 downto 2));
  line <= unsigned(lineAux(9 downto 2));
  
  color <= "111" when campoJuego = '1' or raquetaIzq = '1' or raquetaDer = '1'  or pelota ='1' else "000";

------------------
  
  campoJuego <= '1' when line=8 or line=111 or (pixel=79 and line(3) = '1')  else '0';
  raquetaIzq <= '1' when pixel=8 and (line>=yLeft and line<yLeft+16) else '0';
  raquetaDer <= '1' when pixel=151 and (line>=yRight and line<yRight+16) else '0';
  pelota     <= '1' when line = yBall and pixel = xBall else '0';	
------------------

  finPartida <= true when ((xBall = 0 or xBall = 159 ) and reiniciar = false) else false;
  reiniciar <=  true when finPartida = true and spcP = true else false;   
------------------
  
  pulseGen:
  process (rst_n, clk)
    constant maxValue : natural := CLKFREQ/50-1;
    variable count: natural range 0 to maxValue;
  begin
   if rst_n = '0' then
		mover <= false;
		count := 0;
	 elsif rising_edge(clk) then
		if count = maxValue then
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
			if pP = true and  yRight < (111 -16) then
				yRight <= yRight + 1;
			elsif lP = true and yRight > 8 then
				yRight <= yRight - 1;
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
			if qP = true and yLeft>8 then
				yLeft <= yLeft - 1;
			elsif aP = true and yLeft < (111-16) then
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
		xBall <= "00100000";
		dir:= right;
	 elsif rising_edge(clk) then
		if mover = true and finPartida = false then
			if dir = right then
				if xBall = 151 and yBall >= yRight and yBall <= (yRight +16 )then
					dir := left;
				else
					xBall<= xBall + 1;	
				end if;
			elsif dir = left then 
				if xBall= 8 and yBall >= yLeft and yBall <= (yLeft +16) then
					dir := right;
				else
					xBall<= xBall -1;					
				end if;
			end if;
		end if;
	 end if;-- clock
	 if reiniciar = true then
			xBall <= "00100000";
			dir:= right;
		end if;
  end process;

  yBallRegister:
  process (rst_n, clk)
    type sense is (up, down);
    variable dir: sense;
  begin
    if rst_n = '0' then
		yBall <= "00110000";
		dir := up;
	 elsif rising_edge(clk) then
		if mover = true and finPartida = false then
			if dir = up then
				if yBall = 8 then
					dir:= down;
				else
					yBall <= yBall - 1;
				end if;
			elsif dir = down then
				if yBall = 111 then
					dir:= up;
				else
					yBall <= yBall + 1;
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

