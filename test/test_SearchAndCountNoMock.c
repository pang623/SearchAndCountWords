#include "unity.h"
#include "ReadLine.h"
#include "SearchAndCount.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_SearchAndCountWordInLines_given_happy_as_wordtofind_and_a_file_with_9_lines_expect_count_3(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "happy";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(3, count);
}

void test_SearchAndCountWordInLines_given_hap_as_wordtofind_and_a_file_with_9_lines_expect_count_5(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "hap";
    
    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(5, count);
}

void test_SearchAndCountWordInLines_given_hello_as_wordtofind_and_a_file_with_9_lines_expect_count_2(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "hello";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(2, count);
}

void test_SearchAndCountWordInLines_given_he_as_wordtofind_and_a_file_with_9_lines_expect_count_6(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "he";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(6, count);
}

void test_SearchAndCountWordInLines_given_sun_as_wordtofind_and_a_file_with_9_lines_expect_count_0(void)
{
    int count;
    char *filename = "C:/PANG/Projects/C/SearchAndCountWord/test/data/my_file.txt";
    char *word = "sun";

    count = searchAndCountWordInLines(word, filename);
    TEST_ASSERT_EQUAL(0, count);
}
