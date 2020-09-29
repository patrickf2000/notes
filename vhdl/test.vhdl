library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_signed.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;
use std.textio.all;

--  A testbench has no ports.
entity adder_tb is
end adder_tb;

architecture behav of adder_tb is
    constant WIDTH : integer := 8;

    --  Declaration of the component that will be instantiated.
    component adder
        port (
            vec1 : in std_logic_vector(WIDTH-1 downto 0);
            vec2 : in std_logic_vector(WIDTH-1 downto 0);
            out_vec : out std_logic_vector(WIDTH-1 downto 0);
            co : out std_logic
        );
    end component;

    --  Specifies which entity is bound with the component.
    for add0: adder use entity work.adder;
    signal vec1, vec2, out_vec : std_logic_vector(WIDTH-1 downto 0);
    signal co : std_logic;

begin
    --  Component instantiation.
    add0: adder port map (vec1 => vec1, vec2 => vec2, out_vec => out_vec, co => co);

    --  This process does the real job.
    process
  
        -- For input
        variable in_buf1 : line;
        variable in_buf2 : line;
        variable in_num1 : integer;
        variable in_num2 : integer;
        
        variable val1 : std_logic_vector(WIDTH-1 downto 0);
        variable val2 : std_logic_vector(WIDTH-1 downto 0);
      
        -- For output
        variable l : line;
        variable out_num : integer;
    begin
      
        -- Get all the input
        write(l, String'("Enter two numbers"));
        writeline(output, l);
      
        readline(input, in_buf1);
        read(in_buf1, in_num1);
        
        readline(input, in_buf2);
        read(in_buf2, in_num2);
        
        val1 := conv_std_logic_vector(in_num1, WIDTH);
        val2 := conv_std_logic_vector(in_num2, WIDTH);
        
        wait for 50 ns;
      
        -- Do the calculations
        vec1 <= val1;
        vec2 <= val2;
        wait for 50 ns;
        
        -- Output everything
        write(l, String'("Num1: "));
        write(l, to_bitvector(val1));
        write(l, String'(" | Num2: "));
        write(l, to_bitvector(val2));
        writeline(output, l);
        
        out_num := conv_integer(out_vec);
        
        write(l, String'(""));
        writeline(output, l);
        write(l, String'("Result: "));
        write(l, out_num);
        writeline(output, l);
        
        write(l, String'("Output: "));
        write(l, to_bitvector(out_vec));
        writeline(output, l);
        
        wait;
    end process;

end behav;

