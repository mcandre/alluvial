# alluvial: Poor Man's Digital Signal Processor

![gold prospector](alluvial.png)

# LICENSE

FreeBSD

# FEATURES

* 8-bit integer I/O
* Format: Unsigned or Signed (Two's Complement)
* Closed instruction space (defaults to NAND for unimplemented operator values)

# CORE OPERATORS

* ADD: Addition of A with B
* XOR: Bitwise exclusive-or of A with B
* NAND: Bitwise negation of intersection of A with B

## Extensions

User applications may implement a variety of high level algorithms by composing low level operators. A few examples:

* AND (via NAND): Bitwise intersection A with B.
* OR (via NAND): Bitwise union A with B.
* NOT (via NAND): Bitwise inverse A.
* INC (via ADD A 1): Increment A.
* DEC (via ADD A -1): Decrement A.
* SUB (via ADD with negative values): Difference of A with B.
* ATI (via SUB): Parse decimal ASCII digit A.
* ITA (via ADD): Format A as decimal ASCII digit.
* CPY (via XOR A 0): Copy A.
* ABS (via XOR): Absolute value of A.
* IF (via XOR): Yield non-zero A, or else yield B.
* FOR (via SUB A 2): Loop of A/2 iterations. Supply odd A to enable infinite loops.
* MUL (via FOR, ADD): Product of A with B.
* DIV (via FOR, SUB): Quotient of A with B.
* MOD (via FOR, SUB): Remainder of A with B.
* EXP (via FOR, MUL): Exponential of A to the B power.
* LOG (via FOR, DIV): Logarithm of A base B.
* SLL (via MUL A 2): Shift A logical left B places.
* SLR (via DIV A 2): Shift A logical right B places.
* HTI (via SUB, IF, XOR): Parse hexadecimal digit A.
* ITH (via ADD, IF, XOR): Format A as hexadecimal digit.
* SGN (via FOR, GT): -1, 0, +1 sign of A.
* EQU (via XOR): Equality of A with B.
* LT (via SGN, SUB): Whether A is less than B.
* LTE (via SGN, SUB): Whether A is less than or equal to B.
* GT (via SGN, SUB): Whether A is greater than B.
* GTE (via SGN, SUB): Whether A is greater than or equal to B.
* RST (via XOR): Reset A to zero.
* SWP (via RST, XOR): Swap values A and B.
* FCT (via FOR, MOD): Factor A into prime components.
* NTH (via FOR, IF): Retrieve nth element in a series.
* FRQ (via FOR, NTH, ADD): Generate frequency map for occurences of elements in a series.
* SRT (via FOR, NTH, SWP): Sort elements in a series.
* SUM (via FOR, ADD): Sum elements in a series.
* AVG (via DIV, SUM): Arithmetic average elements in a series.
* MED (via NTH, SRT): Median element in a series.
* MDE (via NTH, SRT, FRQ): Mode element in a series.
* RDM (via CPY A): Sample input source A for random data.
* RDR (via FOR, CPY): Render image onto a frame buffer.
* UTM (via NAND): Universal Turning Machine.

# WARNING

Unstable opcodes.

# TEST

```console
$ make
```

# REQUIREMENTS

* [g++](https://gcc.gnu.org/) 9+
* [GNU make](https://www.gnu.org/software/make/) 4+
* [verilator](https://www.veripool.org/verilator/) 4.212-48-g2560fc86 or higher

```text
///
\\\*
///
```
