#ifndef TEST_H
#define TEST_H

#include <stdio.h>

/*
 * Need to define test functions in advance to know to
 * run them all
 */
#define TESTS void (*funcs[])()

/*
 *
 */
#define START_SUITE

#define END_SUITE int main() { \
  printf("*****STARTING UNIT TESTS FOR %s*****\n\n", __FILE__); \
  int i; \
  for(i = 0; i < sizeof(funcs)/sizeof(void (*)()); i++) { \
    funcs[i](); \
  } \
  printf("\n*****ENDING UNIT TESTS FOR %s*****\n", __FILE__); \
}

/*
 * Leaving for extensibility
 */
#define START_TEST(__testname)\
static void __testname();\
static void __testname()

#define END_TEST

#define ASSERT(EXP) \
do { if(EXP) { \
    printf("PASS: %s %s %d " #EXP "\n", __FILE__, __FUNCTION__, __LINE__); \
  } else { \
    printf("FAIL: %s %s %d " #EXP "\n", __FILE__, __FUNCTION__, __LINE__); \
  } \
} while(0)

#endif
