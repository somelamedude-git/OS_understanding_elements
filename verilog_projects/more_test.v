module more_hello;
    reg[8*5-1:0] hello = "Hello";

    always @(*) begin
        $display("%s", hello);
    end
endmodule
