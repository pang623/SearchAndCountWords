#include "unity.h"
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

void test_SearchAndCountWordInLine_given_key_as_wordtofind_expect_count_3(void)
{
    int count = searchAndCountWordInLine("key", "There are two keys, key1 and key");
    TEST_ASSERT_EQUAL(3, count);
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

void test_SearchAndCountWordInLines_given_happy_as_wordtofind_and_a_file_with_5_lines_expect_count_9(void)
{
    int count;
    char *filename = "./test/data/my_file.txt";
    char *word = "happy";
    char *lines[] = {
      "I am very happy, TDD makes me happy",
      "Not doing TDD makes me unhappy",
      "Happy Sad hApPy sad",
      "Sad haPPY happy HAPPy",
      "hAPPy and SAD",
      NULL
    };
    //Mock
    readLines_ExpectAndReturn(filename, (char**)&lines);
    
    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(9, count);
}

void test_SearchAndCountWordInLines_given_hap_as_wordtofind_and_a_file_with_3_lines_expect_count_2(void)
{
    int count;
    char *filename = "./test/data/my_file.txt";
    char *word = "hap";
    char *lines[] = {
      "I am very hapy, TDD makes me hay",
      "Not doing TDD makes me unhapy",
      "hPPy and SAD",
      NULL
    };
    //Mock
    readLines_ExpectAndReturn(filename, (char**)&lines);
    
    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(2, count);
}

void test_SearchAndCountWordInLines_given_hello_as_wordtofind_and_a_file_with_2_lines_expect_count_2(void)
{
    int count;
    char *filename = "./test/data/my_file.txt";
    char *word = "hello";
    char *lines[] = {
      "HellO, my friend",
      "Hello from the other side",
      NULL
    };
    //Mock
    readLines_ExpectAndReturn(filename, (char**)&lines);
    
    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(2, count);
}

void test_SearchAndCountWordInLines_given_he_as_wordtofind_and_a_file_with_4_lines_expect_count_6(void)
{
    int count;
    char *filename = "./test/data/my_file.txt";
    char *word = "he";
    char *lines[] = {
      "hl, my friend",
      "Helo from the other side",
      "hELLO, are you there h",
      "anyone? HELLO",
      NULL
    };
    //Mock
    readLines_ExpectAndReturn(filename, (char**)&lines);
    
    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(6, count);
}




