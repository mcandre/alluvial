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

User applications may implement a variety of complex algorithms in terms of the core operators.

* INC (via ADD with 1): Increment A
* DEC (via ADD with -1): Decrement A
* SUB (via ADD with negative values): Difference of A with B
* MUL (via repeated ADD): Product of A with B
* DIV (via repeated subtraction): Quotient of A with B
* MOD (via repeated subtraction): Remainder of A with B
* EQU (via XOR): Equality of A with B
* RST (via XOR): Reset A to zero
* FOR (via repeated subtraction): Finite loop of A iterations
* SUM (via repeated ADD): Summation of a multitude of elements
* AVG (via SUM with DIV): Arithmetic average of a multitude of elements
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
