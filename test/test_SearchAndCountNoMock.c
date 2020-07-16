#include "unity.h"
#include "ReadLine.h"
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
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "happy";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(3, count);
}

void test_SearchAndCountWordInLines_given_hap_as_wordtofind_and_a_file_with_3_lines_expect_count_2(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "hap";
    
    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(5, count);
}

void test_SearchAndCountWordInLines_given_hello_as_wordtofind_and_a_file_with_2_lines_expect_count_2(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "hello";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(2, count);
}

void test_SearchAndCountWordInLines_given_he_as_wordtofind_and_a_file_with_4_lines_expect_count_6(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "he";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(6, count);
}