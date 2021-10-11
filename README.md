# alluvial: Poor Man's Digital Signal Processor

![gold prospector](alluvial.png)

# LICENSE

FreeBSD

# FEATURES

* 8-bit argument width
* Format: Unsigned or Signed (Two's Complement)

## Operators

* ADD
* XOR
* NAND

## Applications

* Increment (via ADD with 1)
* Decrement (via ADD with -1)
* Subtraction (via ADD with negative values)
* Multiplication (via repeated ADD)
* Division (via repeated subtraction)
* Modulus (via repeated subtraction)
* Equality (via XOR)
* Finite loops (via repeated subtraction)
* Anything (via NAND)

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
