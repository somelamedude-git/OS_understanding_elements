module tb_half_adder;
    reg a;
    reg b;
    wire o;
    wire c;

    half_adder uui (.a(a), .b(b), .o(o), .c(c));
        initial begin
            a = 0; b=0;
            #5;
            $display("o=%b, c=%b", o, c);
            a=0; b=1;
            #5;
            $display("o=%b, c=%b", o,c);
            a=1; b=0;
            #5;
            $display("o=%b, c=%b", o,c);
            a =1; b=1;
            #5;
            $display("o=%b, c=%b", o,c);
       end
endmodule
            
            

