# alluvial: Poor Man's Digital Signal Processor

![gold prospector](alluvial.png)

# LICENSE

FreeBSD

# FEATURES

* 8-bit argument width
* Format: Unsigned or Signed (Two's Complement)

# CORE OPERATORS

* ADD: Addition of A with B
* XOR: Bitwise exclusive-or of A with B
* NAND: Bitwise negation of intersection of A with B

## Extensions

User applications may implement a variety of high level algorithms by composing low level operators. A few examples:

* AND (via NAND): Bitwise intersection A with B
* OR (via NAND): Bitwise union A with B
* NOT (via NAND): Bitwise inverse A
* INC (via ADD with 1): Increment A
* DEC (via ADD with -1): Decrement A
* SUB (via ADD with negative values): Difference of A with B
* MUL (via repeated ADD): Product of A with B
* DIV (via repeated SUB): Quotient of A with B
* MOD (via repeated SUB): Remainder of A with B
* EQU (via XOR): Equality of A with B
* LT (via EQU, XOR, SUB): Whether A is less than B
* LTE (via OR, LT): Whether A is less than or equal to B
* GT (via EQU, XOR, SUB): Whether A is greater than B
* GTE (via OR, GT): Whether A is greater than or equal to B
* RST (via XOR): Reset A to zero
* SWP (via RST, XOR): Swap values A and B.
* FOR (via repeated SUB 2): Loop of A/2 iterations. Supply odd A to enable infinite loops.
* FCT (via FOR, MOD): Factor A into prime components.
* SRT (via FOR, SWP): Sort elements in a series
* SUM (via repeated ADD): Sum elements in a series
* AVG (via SUM with DIV): Arithmetic average elements in a series
* UTM (via NAND): Universal Turning Machine

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
