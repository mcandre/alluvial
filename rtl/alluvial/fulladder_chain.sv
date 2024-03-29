`include "rtl/alluvial/fulladder.sv"

module fulladder_chain #(parameter WIDTH)(input [WIDTH-1:0] a, [WIDTH-1:0] b, output carry_out, [WIDTH-1:0] sum);
    wire [WIDTH:0] carries;
    assign carries[0] = 0;
    assign carry_out = carries[WIDTH];
    genvar i;

    generate
        for (i = 0; i < WIDTH; i++)
            fulladder fa(carries[i], a[i], b[i], carries[i+1], sum[i]);
    endgenerate
endmodule
