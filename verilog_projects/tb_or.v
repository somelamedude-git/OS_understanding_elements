module tb_or;
    reg a, b;
    wire y;
    or_gate  uut(.a(a), .b(b), .y(y));
    initial begin
        a = 1;
        b=0;
        #5;
        $display("y=%b", y);
    end
endmodule
