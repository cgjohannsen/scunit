#include "scunit.h"

START_SUITE

START_TEST(add) {
  int x = 9;
  int y = 10;
  ASSERT(x + y == 19);
} END_TEST

START_TEST(subtract) {
	int x = 9;
	int y = 10;
	ASSERT(x - y == 1);
} END_TEST

TESTS = {add, subtract};

END_SUITE
