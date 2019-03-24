---------------------------------------------------------------------
--
--  Fichero:
--    ps2ReceiverTest.vhd  6/10/2015
--
--    (c) J.M. Mendias
--    Dise�o Autom�tico de Sistemas
--    Facultad de Inform�tica. Universidad Complutense de Madrid
--
--  Prop�sito:
--    Testbench para la validaci�n funcional de ps2receiver
--
--  Notas de dise�o:
--    - El modelo de an�lisis de respuesta solo es v�lido para 
--      modelos de la uut sin retardo 
--
---------------------------------------------------------------------

entity ps2ReceiverTest is
end ps2ReceiverTest;

---------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_textio.all;
use work.common.all;
use std.textio.all;

architecture sim of ps2ReceiverTest is

  constant clkPeriod : time := 20 ns;   -- Periodo del reloj (50 MHz)
  
  -- Se�ales 
  signal clk     : std_logic := '1';      
  signal rst_n   : std_logic := '0';
  signal ps2clk  : std_logic := '1';
  signal ps2Data : std_logic := '1';
  signal data    : std_logic_vector(7 downto 0) := (others => '0');
  signal dataRdy : std_logic := '0';
         
  type stimulusT is
    record
      ps2clk   : std_logic;
      ps2data  : std_logic;
    end record;
    
  type stimuliT is array (natural range <>) of stimulusT;
  
  -- Trama PS/2 correspondiente al scancode de la tecla A
  constant Astimuli : stimuliT(1 to 23) :=
    (
      ( '1', '0' ),   -- start (0)
      ( '0', '0' ),
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '1' ),   -- 1
      ( '0', '1' ),     
      ( '1', '1' ),   -- 1
      ( '0', '1' ),     
      ( '1', '1' ),   -- 1
      ( '0', '1' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- paridad (0)
      ( '0', '0' ),     
      ( '1', '1' ),   -- stop
      ( '0', '1' ),     
      ( '1', '1' )    -- reposo
    );

  -- Trama PS/2 correspondiente al c�digo de depresi�n
  constant F0stimuli : stimuliT(1 to 23) :=
    (
      ( '1', '0' ),   -- start (0)
      ( '0', '0' ),
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '0' ),   -- 0
      ( '0', '0' ),     
      ( '1', '1' ),   -- 1
      ( '0', '1' ),     
      ( '1', '1' ),   -- 1
      ( '0', '1' ),     
      ( '1', '1' ),   -- 1
      ( '0', '1' ),
      ( '1', '1' ),   -- 1
      ( '0', '1' ),         
      ( '1', '1' ),   -- paridad (1)
      ( '0', '1' ),     
      ( '1', '1' ),   -- stop
      ( '0', '1' ),     
      ( '1', '1' )    -- reposo
    );
    
begin

  uut : ps2Receiver
    generic map ( REGOUTPUTS => true )
    port map ( rst_n => rst_n, clk => clk, dataRdy => dataRdy, data => data, ps2Clk => ps2Clk, ps2Data => ps2Data );

  rstGen :
  rst_n <= 
    '1' after (50 us + 5 ns), 
    '0' after (500 ms + 5 ns), 
    '1' after (500 ms + 50 us + 5 ns);

  clkGen :
  clk <= not clk after clkPeriod/2;
  
  stimuliGen :
  process
    variable linea : line;
  begin
  
    write( linea, string'("Comienza la simulacion...") );
    --writeline( linea, consoleBuff );
  
    wait for 5 ns;  -- Evita que coincidan los flancos de clk y de los est�mulos
    loop

      wait for 100 ms;               
      for i in Astimuli'range loop       -- Genera scancode de presi�n de A 
        ps2clk <= Astimuli(i).ps2clk;
        ps2data <= Astimuli(i).ps2data;
        wait for 40 us;
      end loop;

      wait for 100 ms;
      for i in Astimuli'range loop       -- Genera scancode de repetici�n de A
        ps2clk <= Astimuli(i).ps2clk;
        ps2data <= Astimuli(i).ps2data;
        wait for 40 us;
      end loop;

      wait for 100 ms;        
      for i in F0stimuli'range loop       -- Genera c�digo de depresi�n
        ps2clk <= F0stimuli(i).ps2clk;
        ps2data <= F0stimuli(i).ps2data;
        wait for 40 us;
      end loop;

      wait for 100 ms;
      for i in Astimuli'range loop       -- Genera scancode de depresi�n de A
        ps2clk <= Astimuli(i).ps2clk;
        ps2data <= Astimuli(i).ps2data;
        wait for 40 us;
      end loop;

      wait for 500 ms;          

    end loop;
  end process;
  
  dataCheck :
  process
  begin

    wait until dataRdy='1';
    assert data=X"1C" 
      report "La uut ha le�do err�neamente el scancode de presi�n de la tecla A" 
      severity error;
 
    wait until dataRdy='1';
    assert data=X"1C" 
      report "La uut ha le�do err�neamente el scancode de repetici�n de la tecla A" 
      severity error;
   
    wait until dataRdy='1';
    assert data=X"F0" 
      report "La uut ha le�do err�neamente el c�digo de depresi�n" 
      severity error;
    
    wait until dataRdy='1';
    assert data=X"1C" 
      report "La uut ha le�do err�neamente el scancode de depresi�n de la tecla A" 
      severity error;
  
  end process;
  
  rstCheck:
  process (rst_n'delayed)
  begin
    if rst_n='0' then
      assert dataRdy='0' and data=(others=>'0')
        report "La uut no se resetea adecuadamente"
        severity warning;
    end if;
  end process;    
  
  dataRdyCheck :
  process (dataRdy)
  begin
    if dataRdy='0' then
      assert dataRdy'delayed'last_event <= clkPeriod
        report "La uut activa durante m�s de un ciclo la se�al dataRdy"
        severity warning;
    end if;
  end process;
    
end sim;
