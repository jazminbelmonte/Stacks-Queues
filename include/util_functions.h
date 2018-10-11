#ifndef _UTIL_FUNCTIONS_H
#define _UTIL_FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <stdexcept>
#include "stack.h"
#include "queue.h"

bool palindrome(const std::string& spalindrome) {
    LinkedQueue<char> forwardQueue;
    LinkedQueue<char> backwardQueue;

    int sz = spalindrome.length();

    for (int i = sz-1; i >= 0; i--){
        if(isalpha(spalindrome[i])){
            backwardQueue.enqueue(static_cast<char>(std::toupper(spalindrome[i])));
        }
    }

    for (int i = 0; i <= sz; i++){
        if(isalpha(spalindrome[i])){
            forwardQueue.enqueue(static_cast<char>(std::toupper(spalindrome[i])));
        }
    }

    while (!forwardQueue.empty()){
        if(forwardQueue.peekFront() == backwardQueue.peekFront()){
            forwardQueue.dequeue();
            backwardQueue.dequeue();
        } else {
            return false;
        }
    }

    return forwardQueue.empty();
}

bool balancedBrackets(std::string string, char start = '(', char end = ')'){
    LinkedStack<char> balancedStack;

    int sz = string.length();

    for (int i = 0; i <= sz; i++){
        if(string[i] == start) {
            balancedStack.push(start);
        }
        else if(string[i] == end) {
          if(balancedStack.empty()){
            return false;
          }
            balancedStack.pop();
        }
    }
    return balancedStack.empty();
}

double evaluatePostfixExpression(std::string postfixString){
    LinkedStack<double> postfixStack;

    std::stringstream sin;
    sin << postfixString;
    std::string token;

    while(sin>>token){
        if (token == "+"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 + op2);
        } else if (token == "-"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 - op2);
        } else if (token == "*"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 * op2);
        } else if (token == "/"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 / op2);
        } else {
            postfixStack.push(std::stod(token));
        }
    }
    return postfixStack.top();
}

#endif
