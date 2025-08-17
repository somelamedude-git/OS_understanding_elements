module tb_dff;
    reg d;
    reg rstn;
    reg clk;
    wire q;

    dff uut(.d(d), .rstn(rstn), .clk(clk), .q(q));

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        rstn = 0; d=0;
        #10 rstn = 1; d=1;
        #10 d =0;
        #10 d = 1;
        #20 $finish;
    end

 always @(posedge clk) begin
    $display("Time=%0t, clk=%b, d=%b, q=%b", $time, clk, d, q);
end
endmodule
