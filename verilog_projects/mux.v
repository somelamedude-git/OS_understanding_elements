module mux(input wire I_0, input wire I_1, input wire I_2, input wire I_3, input wire S_0, input wire S_1, output wire Y);
	wire and_one = S_0 & S_1 & I_0;
	wire and_two = S_0 & S_1 & I_1;
	wire and_three = S_0 & S_1 & I_2;
	wire and_four = S_0 & S_1 & I_3;

	assign Y = and_one | and_two | and_three | and_four;
endmodule
