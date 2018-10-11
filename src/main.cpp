#include "util_functions.h"
using namespace std;


int main(){

    //PALINDROME
    cout << palindrome("A car, a man, a maraca.") << endl;
    cout << palindrome("A Toyota! Ra;;;;ce fast, safe car! A Toyota!!!!!!") << endl;

    //BALANCEDBRACKETS
    cout << balancedBrackets("(<[]>)") << endl;
    cout << balancedBrackets("(this is()a test[[]])") << endl;

    //POSTFIX
    cout << (evaluatePostfixExpression("4 2 + 3 5 1 -  * + ")== -6) << endl;
    cout << (evaluatePostfixExpression("10 2 8 * + 3 -") == -23) << endl;

    return 0;
}
