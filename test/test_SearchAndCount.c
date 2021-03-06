#include "unity.h"
#include <malloc.h>
#include <stdlib.h>
#include "mock_ReadLine.h"
#include "SearchAndCount.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_SearchAndCountWordInLine_given_compute_as_wordtofind_expect_count_2(void)
{
  int count = searchAndCountWordInLine("compute", "A computer can compute calculations");
  TEST_ASSERT_EQUAL(2, count);
}

void test_SearchAndCountWordInLine_given_compute_as_wordtofind_line_contains_caps_expect_count_2(void)
{
  int count = searchAndCountWordInLine("compute", "A computer can comPute calculations");
  TEST_ASSERT_EQUAL(2, count);
}

void test_SearchAndCountWordInLine_given_key_as_wordtofind_expect_count_6(void)
{
  int count = searchAndCountWordInLine("key", "There are two keys, keykeykey1key and key");
  TEST_ASSERT_EQUAL(6, count);
}

void test_SearchAndCountWordInLine_given_balls_as_wordtofind_expect_count_0(void)
{
  int count = searchAndCountWordInLine("balls", "There are two keys, key1 and key");
  TEST_ASSERT_EQUAL(0, count);
}

void test_SearchAndCountWordInLine_given_none_as_wordtofind_expect_count_0(void)
{
  int count = searchAndCountWordInLine("none", "A computer can compute calculations");
  TEST_ASSERT_EQUAL(0, count);
}

void test_SearchAndCountWordInLine_given_key_as_wordtofind_expect_count_0(void)
{
  int count = searchAndCountWordInLine("key", "This is a ke");
  TEST_ASSERT_EQUAL(0, count);
}

void test_SearchAndCountWordInLines_given_happy_as_wordtofind_and_a_file_with_9_lines_expect_count_3(void)
{
  int count;
  char *filename = "./test/data/my_file.txt";
  char *word = "happy";
  char **Lines = malloc(sizeof(char *) * 1024);
  char *lines[] = {
    "hl, my friend",
    "Helo from the other side",
    "hELLO, are you there h",
    "anyone? HELLO",
    "I am very haphapy, TDD makes me hay",
    "Not doing TDD makes me unhappy",
    "Hap Sad hA sad",
    "Sad hPY happy APPy",
    "hApPy and SAD",
    NULL
  };
  for(int i = 0; lines[i] != NULL; i++)
    Lines[i] = lines[i];
  //Mock
  readLines_ExpectAndReturn(filename, Lines);

  count = searchAndCountWordInLines(word, filename);
  TEST_ASSERT_EQUAL(3, count);
}

void test_SearchAndCountWordInLines_given_hap_as_wordtofind_and_a_file_with_9_lines_expect_count_6(void)
{
  int count;
  char *filename = "./test/data/my_file.txt";
  char *word = "hap";
  char **Lines = malloc(sizeof(char *) * 1024);
  char *lines[] = {
    "hl, my friend",
    "Helo from the other side",
    "hELLO, are you there h",
    "anyone? HELLO",
    "I am very haphapy, TDD makes me hay",
    "Not doing TDD makes me unhappy",
    "Hap Sad hA sad",
    "Sad hPY happy APPy",
    "hApPy and SAD",
    NULL
  };
  for(int i = 0; lines[i] != NULL; i++)
    Lines[i] = lines[i];
  //Mock
  readLines_ExpectAndReturn(filename, Lines);

  count = searchAndCountWordInLines(word, filename);
  TEST_ASSERT_EQUAL(6, count);
}

void test_SearchAndCountWordInLines_given_sun_as_wordtofind_and_a_file_with_9_lines_expect_count_0(void)
{
  int count;
  char *filename = "./test/data/my_file.txt";
  char *word = "sun";
  char **Lines = malloc(sizeof(char *) * 1024);
  char *lines[] = {
    "hl, my friend",
    "Helo from the other side",
    "hELLO, are you there h",
    "anyone? HELLO",
    "I am very haphapy, TDD makes me hay",
    "Not doing TDD makes me unhappy",
    "Hap Sad hA sad",
    "Sad hPY happy APPy",
    "hApPy and SAD",
    NULL
  };
  for(int i = 0; lines[i] != NULL; i++)
    Lines[i] = lines[i];
  //Mock
  readLines_ExpectAndReturn(filename, Lines);

  count = searchAndCountWordInLines(word, filename);
  TEST_ASSERT_EQUAL(0, count);
}