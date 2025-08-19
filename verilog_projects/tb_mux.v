module tb_mux;
	reg I_0; reg I_1; reg I_2; reg I_3; reg S_0; reg S_1; wire Y;
	
	mux uui(.I_0(I_0), .I_1(I_1), .I_2(I_2), .I_3(I_3), .S_0(S_0), .S_1(S_1), .Y(Y));
		initial begin
			I_0 = 0; I_1 = 1; I_2 = 1; I_3 = 1; S_0 = 0; S_1 = 1;
			#5;
			$display("Y=%b", Y);
			I_0 = 1; I_1 = 0; I_2 = 1; I_3 = 1; S_0 = 0; S_1 = 1;
			#5;
			$display("Y=%b", Y);
		end
endmodule
