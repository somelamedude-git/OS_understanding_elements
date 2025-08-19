module custom_mux #(
parameter WIDTH = 8, parameter WIDTH_ROOT = 2)(input wire [WIDTH-1:0] in, input wire [WIDTH_ROOT-1:0] sel, output wire Y);
	assign Y = in[sel];
endmodule
