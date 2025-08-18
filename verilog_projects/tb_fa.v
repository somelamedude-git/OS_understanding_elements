module tb_full_adder;
    reg a; reg b; reg c_in; wire c_out; wire s;

    full_adder uui(.a(a), .b(b), .c_in(c_in), .c_out(c_out), .s(s));
        initial begin
            a = 0; b=0; c_in=0;
            #5;
            $display("c_out=%b, s=%b", c_out, s);
            a = 0; b =0; c_in=1;
            #5;
            $display("c_out=%b, s=%b", c_out, s);
            a = 0; b =1; c_in=0;
            #5;
            $display("c_out=%b, s=%b", c_out, s);
            a = 0; b =1; c_in=1;
            #5;
            $display("c_out=%b, s=%b", c_out, s);
            a =1; b=0; c_in=0;
            #5;
            $display("c_out=%b, s=%b", c_out, s);
       end
endmodule

