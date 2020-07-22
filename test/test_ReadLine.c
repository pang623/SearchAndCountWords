#include "unity.h"

#include "ReadLine.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_readLines_given_file_expect_line_is_read_correctly() {
  char **lines;
  char *filename = "./test/data/my_file.txt";
  lines = readLines(filename);
  TEST_ASSERT_EQUAL_STRING("Sad hPY happy APPy\n", lines[7]);
}
