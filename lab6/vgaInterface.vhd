---------------------------------------------------------------------
--
--  Fichero:
--    vgaInterface.vhd  15/7/2015
--
--    (c) J.M. Mendias
--    DiseÃ±o AutomÃ¡tico de Sistemas
--    Facultad de InformÃ¡tica. Universidad Complutense de Madrid
--
--  PropÃ³sito:
--    Genera las seÃ±ales de color y sincronismo de un interfaz VGA
--    con resoluciÃ³n 640x420 px
--
--  Notas de diseÃ±o:

--    - Para frecuencias a partir de 50 Mhz en multiplos de 25 MHz 
--
---------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity vgaInterface is

  generic(
    FREQ      : natural;  -- frecuencia de operacion en KHz
    SYNCDELAY : natural   -- numero de pixeles a retrasar las seÃ±ales de sincronismo respecto a las de posiciÃ³n
  );
  port ( 
    -- host side
    rst_n : in  std_logic;   -- reset asÃ­ncrono del sistema (a baja)
    clk   : in  std_logic;   -- reloj del sistema
    line  : out std_logic_vector(9 downto 0);   -- numero de linea que se esta barriendo
    pixel : out std_logic_vector(9 downto 0);   -- numero de pixel que se esta barriendo
    R     : in  std_logic_vector(2 downto 0);   -- intensidad roja del pixel que se esta barriendo
    G     : in  std_logic_vector(2 downto 0);   -- intensidad verde del pixel que se esta barriendo
    B     : in  std_logic_vector(2 downto 0);   -- intensidad azul del pixel que se esta barriendo
    -- VGA side
    hSync : out std_logic;   -- sincronizacion horizontal
    vSync : out std_logic;   -- sincronizacion vertical
    RGB   : out std_logic_vector(8 downto 0)   -- canales de color
  );
end vgaInterface;

---------------------------------------------------------------------


library ieee;
use ieee.numeric_std.all;

architecture syn of vgaInterface is
  
  constant CYCLESxPIXEL : natural := FREQ/25_000;
  constant PIXELSxLINE  : natural  := 800; 
  constant LINESxFRAME  : natural  := 525;
  
  signal hSyncInt, vSyncInt : std_logic;


  signal pixelCnt : unsigned(pixel'range);
  signal lineCnt  : unsigned(line'range);
  signal blanking : std_logic;

  

  signal cycleCntTC : std_logic;
  signal pixelCntTC : std_logic;

begin

  cycleCounter:
  process (rst_n, clk)
    variable cycleCnt : natural range 0 to CYCLESxPIXEL-1;
  begin
	 cycleCntTC <='0';
	 if cycleCnt = CYCLESxPIXEL-1 then
		cycleCntTC <='1';
	 end if;
	 
    if rst_n='0' then
      cycleCnt := 0;
    elsif rising_edge(clk) then
      if cycleCnt = (CYCLESxPIXEL-1) then 
			cycleCnt := 0;
		else
			cycleCnt := cycleCnt + 1;
		end if;
    end if; 
  end process;
  
	
  pixelCounter:
  process (rst_n, clk)
  begin 
    if rst_n='0' then
      pixelCnt <= (others => '0');
    elsif rising_edge(clk) then
      if cycleCntTC = '1' then
			if (pixelCnt = PIXELSxLINE-1) then 
				pixelCnt <= (others => '0');
			else
				pixelCnt <= pixelCnt + 1;
			end if;
		end if; 
	  end if;
	end process;

	pixelCntTC <= '1' when pixelCnt = PIXELSxLINE-1 else '0';
	
  lineCounter:
  process (rst_n, clk)
  begin
	 
    if rst_n='0' then
      lineCnt <= (others => '0');
    elsif rising_edge(clk) then
		if pixelCntTC = '1' then
			if lineCnt = (LINESxFRAME-1) then 
				lineCnt <= (others => '0');
			else
				lineCnt <= lineCnt+1;
			end if;
		end if; 
	 end if;
	end process;

  pixel <= std_logic_vector(pixelCnt); 
  line  <= std_logic_vector(lineCnt); 
  
  hSyncInt <= '0' when (pixelCnt >= (656 + SYNCDELAY) and pixelCnt < (752 + SYNCDELAY )) else '1';
  vSyncInt <= '0' when (lineCnt >= 494 and lineCnt < 496) else '1';     
 
  blanking <= '1' when (pixelCnt >= (640 + SYNCDELAY) or lineCnt >=480 or pixelCnt < SYNCDELAY ) else '0';--preguntar(puede fallar)
  --rgb debe valer 0 cuando pixelCnt > = 640 o lineCnt >=480
  
  outputRegisters:
  process (rst_n, clk)
  begin
   if rst_n = '0' then
		RGB <=(others =>'0');
	elsif rising_edge(clk) then
		RGB(8)<= R(2)and not(blanking);
		RGB(7)<= R(1)and not(blanking);
		RGB(6)<= R(0)and not(blanking);
		RGB(5)<= G(2)and not(blanking);
		RGB(4)<= G(1)and not(blanking);
		RGB(3)<= G(0)and not(blanking);
		RGB(2)<= B(2)and not(blanking);
		RGB(1)<= B(1)and not(blanking);
		RGB(0)<= B(0)and not(blanking);
		
		hSync<= hSyncInt;
		vSync<= vSyncInt;	
		
	end if;
  end process;
    
end syn;
