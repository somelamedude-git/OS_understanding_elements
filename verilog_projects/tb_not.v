module tb_not;
    reg a;
    wire y;

    not_gate uui (.a(a), .y(y));

    initial begin
        a = 0;
        #1;
        $display("y=%b", y);
    end
endmodule
