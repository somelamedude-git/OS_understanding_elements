module mux8to1(input wire[7:0] in, input wire[2:0] sel, output wire y);
	assign y = in[sel];
endmodule
