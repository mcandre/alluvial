# alluvial: Poor Man's Digital Signal Processor

```text
///
\\\*
///
```

# CAPABILITIES

* 8-bit argument width
* Formats: Unsigned or Signed (Two's Complement)
* Addition
* Subtraction (via adding with negative values)
* XOR
* NAND
* Equality (via XOR)
* Anything (via NAND)

# WARNING

Opcode values presently unstable.

# TEST

```console
$ make
```

# REQUIREMENTS

* [g++](https://gcc.gnu.org/) 9+
* [GNU make](https://www.gnu.org/software/make/) 4+
* [verilator](https://www.veripool.org/verilator/) 4.212-48-g2560fc86 or higher
