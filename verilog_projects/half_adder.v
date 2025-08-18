module half_adder(input wire a, input wire b, output wire o, output wire c);
    and(c, a, b);
    xor(o, a, b);

 endmodule
