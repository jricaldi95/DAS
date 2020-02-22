---------------------------------------------------------------------
--
--  Fichero:
--    lab2.vhd  14/7/2015
--
--    (c) J.M. Mendias
--    Dise�o Autom�tico de Sistemas
--    Facultad de Inform�tica. Universidad Complutense de Madrid
--
--  Prop�sito:
--    Laboratorio 2
--
--  Notas de dise�o:
--
---------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity lab2 is
port
(
  rstPb_n     : in  std_logic;

  osc         : in  std_logic;
  startStop_n : in  std_logic;
  clear_n     : in  std_logic;
  lap_n       : in  std_logic;
  leftSegs    : out std_logic_vector(7 downto 0);
  rightSegs   : out std_logic_vector(7 downto 0)
);
end lab2;

---------------------------------------------------------------------

use work.common.all;

architecture syn of lab2 is

  component modCounter
  generic
  (
    MAXVALUE : natural   -- valor maximo alcanzable
  );
  port
  (
    rst_n : in  std_logic;   -- reset as�ncrono del sistema (a baja)
    clk   : in  std_logic;   -- reloj del sistema
    clear : in  std_logic;   -- puesta a 0 sincrona
    ce    : in  std_logic;   -- capacitacion de cuenta
    tc    : out std_logic;   -- fin de cuenta
    count : out std_logic_vector(log2(MAXVALUE)-1 downto 0)   -- cuenta
  );
  end component;

  signal clk , rst_n: std_logic;
  
  signal startStopSync_n, clearSync_n, lapSync_n : std_logic;
  signal startStopDeb_n,  clearDeb_n,  lapDeb_n  : std_logic;
  signal startStopFall,   clearFall,   lapFall   : std_logic;
  
  signal lapTFF, startStopTFF : std_logic;
  
  signal cycleCntTC, decCntTC, secLowCntTC : std_logic;
    
  signal decCnt, secLowCnt : std_logic_vector(3 downto 0); 
  signal secHighCnt        : std_logic_vector(2 downto 0);
    
  signal secLowReg  : std_logic_vector(3 downto 0); 
  signal secHighReg : std_logic_vector(2 downto 0);
  
  signal secLowMux, secHighMux : std_logic_vector(3 downto 0); 

begin

  clk   <= osc;
  
  rst_n <= rstPb_n;

  

  ------------------  

  
	startStopSynchronizer : synchronizer
	 generic map ( STAGES => 2, INIT => '1' )
	 port map ( rst_n => rst_n, clk => clk , x => startStop_n, xSync =>startStopSync_n );

	startStopDebouncer : debouncer
	 generic map ( FREQ => 50_000, BOUNCE => 50 )
	 port map ( rst_n => rst_n, clk => clk , x_n => startStopSync_n , xdeb_n => startStopDeb_n ); 
	 
	startStopEdgeDetector : edgeDetector
	 port map ( rst_n => rst_n, clk => clk , x_n => startStopDeb_n ,xFall => startStopFall ,xRise => open );
	 
	--En el clear el numero de STATES = 2 ,pero el INIT es '1' o '0'. Al cargar el clear seguira la misma estructura de starStop
	-- o ha de ser logica inversa de manera que se ejecute cuando clear 0 y starstop 1

	clearSynchronizer : synchronizer  
	 generic map ( STAGES => 2, INIT => '1')
	 port map ( rst_n => rst_n, clk => clk , x => clear_n, xSync => clearSync_n );

	clearDebouncer : debouncer
	 generic map ( FREQ => 50_000, BOUNCE => 50 )
	 port map ( rst_n => rst_n, clk => clk , x_n => clearSync_n , xdeb_n => clearDeb_n );
	 
	clearEdgeDetector : edgeDetector
	 port map ( rst_n => rst_n, clk => clk , x_n => clearDeb_n ,xFall => clearFall ,xRise => open );
	 

	lapSynchronizer : synchronizer
	 generic map (STAGES => 2, INIT => '1' ) 
	 port map ( rst_n => rst_n, clk => clk , x => lap_n , xSync =>lapSync_n );

	lapDebouncer : debouncer
	 generic map ( FREQ => 50_000, BOUNCE => 50 )
	 port map (  rst_n => rst_n, clk => clk , x_n => lapSync_n , xdeb_n => lapDeb_n );
	 
	lapEdgeDetector : edgeDetector
	 port map ( rst_n => rst_n, clk => clk , x_n => lapDeb_n ,xFall => lapFall ,xRise => open );
  
  ------------------  


  toggleFF :
  process (rst_n, clk)
  begin
    if rst_n='0' then
      startStopTFF <= '0';
      lapTFF       <= '0';
	elsif rising_edge(clk) then
      if startStopFall = '1' then
        startStopTFF <=  not(startStopTFF);
      end if;
      if lapFall ='1' then
        lapTFF <= not(lapTFF);
      end if;
    end if;
  end process;
 

 cycleCounter : modCounter 
    generic map ( MAXVALUE => 5_000_000-1 )
    port map ( rst_n => rst_n, clk => clk, clear => clearFall, ce => startStopTFF, tc => cycleCntTC, count  => open  );
  
  decCounter : modCounter 
    generic map ( MAXVALUE => 9 )
    port map ( rst_n => rst_n, clk => clk, clear => clearFall, ce => cycleCntTC, tc => decCntTC , count  => decCnt );
    
  secLowCounter : modCounter 
    generic map ( MAXVALUE => 9 )
    port map (  rst_n => rst_n, clk => clk, clear => clearFall, ce => decCntTC, tc => secLowCntTC , count  => secLowCnt  );
	
  secHighCounter : modCounter 
    generic map ( MAXVALUE => 5 )
    port map ( rst_n => rst_n, clk => clk, clear => clearFall, ce => secLowCntTC, tc => open , count  => secHighCnt );
  
  lapRegister :
  process (rst_n, clk)
  begin
    if rst_n='0' then
      secLowReg  <= (others => '0');
      secHighReg <= (others => '0');
    elsif rising_edge(clk) then
      if clearFall = '1' then
        secLowReg  <= (others => '0');
        secHighReg <= (others => '0');       
      elsif lapFall = '1' then
        secLowReg <= secLowCnt;
        secHighReg <= secHighCnt;        
      end if;
    end if;
  end process;

  leftConverterMux :
    secHighMux <= '0' & secHighCnt when lapTFF = '0' else '0' & secHighReg;
  
  rigthConverterMux :
    secLowMux <= secLowCnt when lapTFF = '0' else secLowReg;
  
  leftConverter : bin2segs 
    port map ( bin => secHighMux, dp => decCnt(3), segs =>leftSegs) ;
  
  rigthConverter : bin2segs 
    port map ( bin => secLowMux, dp => decCnt(3), segs =>rightSegs );
  
end syn;
