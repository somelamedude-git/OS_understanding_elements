module full_adder(input wire a, input wire c_in, output wire c_out, output wire s);
    assign s = a^b^c_in;
    wire temp_one = a&b;
    wire temp_two = a&c_in;
    wire temp_three = b&c_in;

    assign c_out = temp_one | temp_two | temp_three;

endmodule
