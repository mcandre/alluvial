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
* NAND: Bitwise negation of intersection of A with B
* XOR: Bitwise exclusive-or of A with B

## Extensions

User applications may implement a variety of high level algorithms by composing low level operators. A few examples:

* ABS (via XOR): Absolute value of A.
* AND (via NAND): Bitwise intersection A with B.
* ATI (via SUB): Parse decimal ASCII digit A.
* AVG (via DIV, SUM): Arithmetic average elements in a series.
* CAT (via SWP): Concatenate A with B.
* CPY (via XOR A 0): Copy A.
* DEC (via ADD A -1): Decrement A.
* DIV (via FOR, SUB): Quotient of A with B.
* EQU (via XOR): Equality of A with B.
* EXP (via FOR, MUL): Exponential of A to the B power.
* FCT (via FOR, MOD): Factor A into prime components.
* FOR (via SUB A 2): Loop of A/2 iterations. Supply odd A to enable infinite loops.
* FRQ (via FOR, NTH, ADD): Generate frequency map for occurences of elements in a series.
* GCD (via FOR): Greatest common denominator of A and B.
* GT (via SGN, SUB): Whether A is greater than B.
* GTE (via SGN, SUB): Whether A is greater than or equal to B.
* HTI (via SUB, IF, XOR): Parse hexadecimal digit A.
* IF (via XOR): Yield non-zero A, or else yield B.
* INC (via ADD A 1): Increment A.
* ITA (via ADD): Format A as decimal ASCII digit.
* ITH (via ADD, IF, XOR): Format A as hexadecimal digit.
* LOG (via FOR, DIV): Logarithm of A base B.
* LT (via SGN, SUB): Whether A is less than B.
* LTE (via SGN, SUB): Whether A is less than or equal to B.
* MDE (via NTH, SRT, FRQ): Mode element in a series.
* MED (via NTH, SRT): Median element in a series.
* MUL (via FOR, ADD): Product of A with B.
* NOT (via NAND): Bitwise inverse A.
* NTH (via FOR, IF): Retrieve nth element in a series.
* OR (via NAND): Bitwise union A with B.
* PDL (via FOR, XOR): Pad A left to B total places.
* PDR (via FOR, XOR): Pad A right to B total places.
* RDM (via CPY A): Sample input source A for random data.
* RDR (via FOR, CPY): Render image onto a frame buffer.
* REM (via FOR, SUB): Remainder of A with B.
* RST (via XOR): Reset A to zero.
* SGN (via FOR, GT): -1, 0, +1 sign of A.
* SLL (via MUL A 2): Shift A logical left B places.
* SLR (via DIV A 2): Shift A logical right B places.
* ROL (via XOR, SLL): Rotate A left B places.
* ROR (via XOR, SLR): Rotate A right B places.
* SH2 (via FOR, ITH, PADR, SLL, SLR, ROL, ROR): SHA-2(56) cryptographic hash.
* SRT (via FOR, NTH, SWP): Sort elements in a series.
* SQT (via FOR): Square root of A.
* SUB (via ADD with negative values): Difference of A with B.
* SUM (via FOR, ADD): Sum elements in a series.
* SVE (via FOR, FCT): Generate prime sieve.
* SWP (via RST, XOR): Swap values A and B.
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
