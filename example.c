#include "test.h"

START_SUITE

START_TEST(add) {
  int x = 9;
  int y = 10;
  ASSERT((x + y == 19));
  ASSERT((x - y == -1));
  ASSERT((x == y));
} END_TEST

TESTS = {add};

END_SUITE
