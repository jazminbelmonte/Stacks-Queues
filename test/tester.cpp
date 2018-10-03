#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "util_functions.h"
using namespace std;

TEST_CASE("Test palindrome") {
    REQUIRE(palindrome("u"));
    REQUIRE(palindrome("radar"));
    REQUIRE(!palindrome("Welcome!"));
    REQUIRE(palindrome("noon"));
    REQUIRE(palindrome("Madam, I'm Adam"));
    REQUIRE(palindrome("Never odd or even"));
}

TEST_CASE("Test balancedBrackets") {
    REQUIRE(balancedBrackets("(2 + 0) + 4"));
    REQUIRE(!balancedBrackets("(8 + 9 * (34 * 6)"));
    REQUIRE(balancedBrackets("class A { double x, y;}", '{', '}'));
    REQUIRE(!balancedBrackets("[4,5, [9, 8, 0, 3]]]", '[', ']'));
    REQUIRE(balancedBrackets("[[4,5, [9, 8, 0, 3]]]", '[', ']'));
}

TEST_CASE("Test evalutePostfixExpression") {
    REQUIRE(evalutePostfixExpression("6 3 + 2 *") == 18);
    REQUIRE(evalutePostfixExpression("15 7 1 1 + - / 3 * 2 1 1 + + -") == 5);
    REQUIRE(evalutePostfixExpression("1 2 + 4 * 5 + 3 -") == -14);
    REQUIRE(static_cast<int>(1000 * evalutePostfixExpression("12 25 5 1 / / * 8 7 + -")) == 14904);
    REQUIRE(static_cast<int>(1000 * evalutePostfixExpression("70 14 4 5 15 3 / * - - / 6 +")) == 5757); 
    REQUIRE(static_cast<int>(1000 * evalutePostfixExpression("3 5 6 * + 13 - 18 2 / +")) == -19888);
    REQUIRE_THROWS(evalutePostfixExpression("7 6 + 3 ; 6 -"));
    REQUIRE_THROWS(evalutePostfixExpression("14 + 2 3 *"));
    REQUIRE_THROWS(evalutePostfixExpression("14 2 3 +)"));
}
