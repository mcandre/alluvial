#include <cstdlib>

#include "Valluvial.h"
#include "Valluvial__Syms.h"

constexpr int WIDTH = 8;
constexpr int RANGE = 1 << WIDTH;
constexpr int MIN_UNSIGNED = 0;
constexpr int MAX_UNSIGNED = RANGE - 1;
constexpr int MIN_SIGNED = -1 * (1 << (WIDTH - 1));
constexpr int MAX_SIGNED = (1 << (WIDTH - 1)) - 1;
constexpr int MASK = MAX_UNSIGNED;

static int to_2c(int x) {
    if (x > -1) {
        return x;
    }

    x = -1 * x;
    x = (~x) & MASK;
    x = (x + 1) & MASK;
    return x;
}

static int from_2c(int x) {
    if (!(x >> WIDTH)) {
        return x;
    }

    x = (~x) & MASK;
    x = (x + 1) & MASK;
    return -1 * x;
}

static void test_add_unsigned(Valluvial &top) {
    top.op = Valluvial___024unit::Op::ADD;

    for (int i = MIN_UNSIGNED; i <= MAX_UNSIGNED; i++) {
        for (int j = MIN_UNSIGNED; j <= MAX_UNSIGNED; j++) {
            top.a = i;
            top.b = j;
            top.eval();
            assert(top.error == ((i + j) > MAX_UNSIGNED));
            assert(top.result == ((i + j) & MASK));
        }
    }
}

static void test_add_signed(Valluvial &top) {
    top.op = Valluvial___024unit::Op::ADD;

    for (int i = MIN_SIGNED; i <= MAX_SIGNED; i++) {
        for (int j = MIN_SIGNED; j <= MAX_SIGNED; j++) {
            top.a = to_2c(i);
            top.b = to_2c(j);
            top.eval();
            assert(from_2c(top.result) == ((i + j) & MASK));
        }
    }
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Valluvial top{"top"};
    test_add_unsigned(top);
    test_add_signed(top);
    return EXIT_SUCCESS;
}
