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
    //create two queues
    LinkedQueue<char> forwardQueue;
    LinkedQueue<char> backwardQueue;

    int sz = spalindrome.length();

    //this will copy only the character symbols of the string backwards
    for (int i = sz-1; i >= 0; i--){
        if(isalpha(spalindrome[i])){
            backwardQueue.enqueue(static_cast<char>(std::toupper(spalindrome[i])));
        }
    }
    //this will copy only the character symbols of the string forward
    for (int i = 0; i <= sz; i++){
        if(isalpha(spalindrome[i])){
            forwardQueue.enqueue(static_cast<char>(std::toupper(spalindrome[i])));
        }
    }
    //while the queue is not empty
    while (!forwardQueue.empty()){
        //if the two characters on both queues are the same then remove them
        if(forwardQueue.peekFront() == backwardQueue.peekFront()){
            forwardQueue.dequeue();
            backwardQueue.dequeue();
        }
        //if they aren't the same immediately return false, since it will
        //not be a palindrome
        else {
            return false;
        }
    }
    //returns true if empty which means all characters have matched
    //and been removed from queue
    return forwardQueue.empty();
}

bool balancedBrackets(std::string string, char start = '(', char end = ')'){
    //create a stack of chars
    LinkedStack<char> balancedStack;

    int sz = string.length();

    //go through the string one by one and check to see if there is a start or and end
    for (int i = 0; i <= sz; i++){
        //if start push it into the stack
        if(string[i] == start) {
            balancedStack.push(start);
        }
        //if it is an end pop out its corresponding start
        else if(string[i] == end) {
          //if it is empty automatically send false
          if(balancedStack.empty()){
            return false;
          }
            balancedStack.pop();
        }
    }
    //if empty then all brackets had corresponding start and end,
    //if not empty then it was not balanced
    return balancedStack.empty();
}

double evaluatePostfixExpression(std::string postfixString){
    //create stack of doubles
    LinkedStack<double> postfixStack;

    //stringstream to read in the postfix string
    std::stringstream sin;
    sin << postfixString;
    std::string token;

    while(sin>>token){
        //if addition
        if (token == "+"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 + op2);
        }//if subtraction
        else if (token == "-"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 - op2);
        }//if multiplication
        else if (token == "*"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();
            postfixStack.push(op1 * op2);
        }//if division
        else if (token == "/"){
            double op1 = postfixStack.top();
            postfixStack.pop();
            double op2 = postfixStack.top();
            postfixStack.pop();

            //if the second operand is a 0, throw divide by zero error
            if (op2 == 0) {
                throw std::runtime_error("Cannot divide by zero");
            } else {
                postfixStack.push(op1 / op2);
            }
        }
        //if token is a number turn it into a double and push it into the stack
        else if (token == "0" || "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9"){
            postfixStack.push(std::stod(token));
        }
        //if it's anything but a number or an operation symbol throw error
        else {
            throw std::runtime_error("Invalid operation");
        }
    }
    //there should only be one number in the stack (the result) so that is what we return
    return postfixStack.top();
}

#endif
