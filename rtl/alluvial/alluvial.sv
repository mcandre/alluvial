`include "rtl/alluvial/fulladder_chain.sv"

typedef enum {
    ADD,
    XOR,
    NAND
} Op /*verilator public*/;

module alluvial(input [31:0] op, [7:0] a, [7:0] b, output reg error, reg [7:0] result);
    reg [7:0] add_a,
              add_b;
    wire add_carry;
    wire [7:0] add_sum;
    fulladder_chain #(.WIDTH(8)) fac(add_a, add_b, add_carry, add_sum);

    always case (op)
        ADD: begin
            assign add_a = a;
            assign add_b = b;
            assign error = add_carry;
            assign result = add_sum;
        end

        XOR: begin
            assign result = a ^ b;
        end

        default: result = ~(a & b);
    endcase
endmodule
