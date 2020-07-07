# scunit: simple C unit tester

This repo holds the source code for the simple C unit testing framework. The motive of this project is provide a very basic and extensible unit testing environment for C code.

## Tutorial

The framework provides the ability to write and run unit tests with very little configuration. It does this from a series of macros in a single header file. The example.c file shows off the format and ability of the framework. 

A unit testing file with basic functionality should have 3 elements:
1. Unit testing functions as such:
```
START_TEST(foo) {
	...
} END_TEST
```

2. Setting the macro TESTS to an array of all function names:
```
TESTS = {foo, bar, ...};
```

3. All the tests and declaration of TESTS should be surrounded by a SUITE block:
```
START_SUITE

...

END_SUITE
```

The last defined macro is the ASSERT(EXP) macro, which treats EXP as a boolean and reports the pass/fail state to stdout with the function, line number, and original expression. This macro should be used in each test function.

