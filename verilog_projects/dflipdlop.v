module dff(input d, rstn, clk, output q);
reg q   //Stores 1 bit, can cosplay a flipflop

    always @ (posedge clk) begin
        if(!rstn)
            q<=0;
         else
             q<=d;
    end
endmodule

