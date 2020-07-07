#ifndef TEST_H
#define TEST_H

#include <stdio.h>

/* Define our colors for terminal output */
#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RESET	"\x1b[0m"

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
    printf("[" ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "]" \
		": TEST[%s] LINE NUMBER[%d] ASSERT[" #EXP "]\n", __FUNCTION__, __LINE__); \
  } else { \
    printf("[" ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "]" \
		": TEST[%s] LINE NUMBER[%d] ASSERT[" #EXP "]\n", __FUNCTION__, __LINE__); \
  } \
} while(0)

#endif
