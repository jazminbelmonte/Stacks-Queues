#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "util_functions.h"
using namespace std;

TEST_CASE("Test palindrome") {
    CHECK(palindrome("u"));
    CHECK(palindrome("radar"));
    CHECK(!palindrome("Welcome!"));
    CHECK(palindrome("noon"));
    CHECK(palindrome("Madam, I'm Adam"));
    CHECK(palindrome("Never odd or even"));
}

TEST_CASE("Test balancedBrackets") {
    CHECK(balancedBrackets("(2 + 0) + 4"));
    CHECK(!balancedBrackets("(8 + 9 * (34 * 6)"));
    CHECK(balancedBrackets("class A { double x, y;}", '{', '}'));
    CHECK(!balancedBrackets("[4,5, [9, 8, 0, 3]]]", '[', ']'));
    CHECK(balancedBrackets("[[4,5, [9, 8, 0, 3]]]", '[', ']'));
}


TEST_CASE("Test evaluatePostfixExpression()") {
    CHECK(evaluatePostfixExpression("6 3 + 2 *") == 18);
    CHECK(evaluatePostfixExpression("15 7 1 1 + - / 3 * 2 1 1 + + -") == 5);
    CHECK(evaluatePostfixExpression("1 2 + 4 * 5 + 3 -") == -14);
    CHECK(static_cast<int>(1000 * evaluatePostfixExpression("12 25 5 1 / / * 8 7 + -")) == 14904);
    CHECK(static_cast<int>(1000 * evaluatePostfixExpression("70 14 4 5 15 3 / * - - / 6 +")) == 5757);
    CHECK(static_cast<int>(1000 * evaluatePostfixExpression("3 5 6 * + 13 - 18 2 / +")) == -19888);
    CHECK_THROWS(evaluatePostfixExpression("7 6 + 3 ; 6 -"));
    CHECK_THROWS(evaluatePostfixExpression("14 + 2 3 *"));
    CHECK_THROWS(evaluatePostfixExpression("14 2 3 +)"));
}
