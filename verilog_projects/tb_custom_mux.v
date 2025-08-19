module test_custom_mux;
	parameter WIDTH = 16;
	parameter WIDTH_ROOT = 4;

	reg[WIDTH-1:0] in;
	reg[WIDTH_ROOT-1:0] sel;
	wire Y;

	custom_mux #(.WIDTH(WIDTH), .WIDTH_ROOT(WIDTH_ROOT)) uut (.in(in), .sel(sel), .Y(Y));
	
	initial begin
		in = 16'b1010101010101010;
		sel = 4'b1100;
		#5;
		$display("Y=%b", Y);
	end
endmodule
