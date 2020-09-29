#!/bin/bash

ghdl -a adder.vhdl

ghdl -a --ieee=synopsys test.vhdl
ghdl -e --ieee=synopsys adder_tb
ghdl -r --ieee=synopsys adder_tb --ieee-asserts=disable
