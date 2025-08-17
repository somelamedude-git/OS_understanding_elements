module tb_and;
    reg a;
    reg b;
    wire y;

    and_gate uui(.a(a), .b(b), .y(y));

    initial begin
        a = 1;
        b=0;
        #3;
        $display("y=%b", y);
     end
endmodule
