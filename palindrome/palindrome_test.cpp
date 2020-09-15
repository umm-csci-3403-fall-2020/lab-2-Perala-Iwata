#include <gtest/gtest.h>

#include "palindrome.h"

char *assertionPalindrome;

void is_palindrome(char const *str) {
  // Can not free a direct method call as it originally was
  // Assigned the method call to a variable to free after use
  assertionPalindrome = palindrome(str);
  ASSERT_STREQ(assertionPalindrome, "Yes");
  free(assertionPalindrome);
}

void not_palindrome(char const *str) {
  // Can not free a direct method call as it originally was
  // Assigned the method call to a variable to free after use
  assertionPalindrome = palindrome(str);
  ASSERT_STREQ(assertionPalindrome, "No");
  free(assertionPalindrome);
}

TEST(Palindrome, HandlesEmptyString) {
  is_palindrome("");
}

TEST(Palindrome, HandlesSingletons) {
  is_palindrome("a");
  is_palindrome("b");
  is_palindrome("c");
}

TEST(Palindrome, HandlesLengthTwo) {
  is_palindrome("aa");
  is_palindrome("bb");
  not_palindrome("ab");
}

TEST(Palindrome, HandlesLengthThree) {
  is_palindrome("aaa");
  is_palindrome("bab");
  not_palindrome("abc");
  not_palindrome("abb");
}

TEST(Palindrome, HandlesLengthFour) {
  is_palindrome("aaaa");
  is_palindrome("baab");
  not_palindrome("abcd");
  not_palindrome("aabb");
  not_palindrome("abbc");
  not_palindrome("abca");
}

TEST(Palindrome, HandlesLongerStrings) {
  is_palindrome("aaaaaaaaaaa");
  is_palindrome("aaaaaaaaaaaa");
  is_palindrome("abcdefgfedcba");
  is_palindrome("abcdefggfedcba");
  not_palindrome("abcdefghijk");
  not_palindrome("aaaaaaaaaaaabaaaa");
  not_palindrome("abcdxfgfedcba");
  not_palindrome("abcdefggfexcba");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
