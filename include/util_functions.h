#ifndef _UTIL_FUNCTIONS_H
#define _UTIL_FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include "stack.h"
#include "queue.h"

// TODO: bool palindrome(const std::string& s) QUEUE
//start by removing all the non-alphabet characters and convert everything to upper
//use a queue data structure to process and return the string
bool palindrome(const std::string& s) {
    LinkedQueue<char> queue;
    LinkedQueue<char> queue2;

    for (int i = s.length()-1; i >= 0; i--){
        if(isalpha(s[i])){
            queue.enqueue(static_cast<char>(std::toupper(s[i])));
        }
    }
    for (int i = 0; i <= s.length(); i++){
        if(isalpha(s[i])){
            queue2.enqueue(static_cast<char>(std::toupper(s[i])));
        }
    }
    while (!queue.empty()){
        if(queue.peekFront() == queue2.peekFront()){
            queue.dequeue();
            queue2.dequeue();
        } else {
            return false;
        }
    }
    return queue.empty();
}

// TODO: bool balancedBrackets(std::string s, char start = '(', char end = ')') STACK
//returns whether the braces are balanced or not
bool balancedBrackets(std::string s, char start = '(', char end = ')'){
    LinkedStack<char> stack;
    for (int i = 0; i <= s.length(); i++){
        if(s[i] == start) {
            stack.push(start);
        }
        else if(s[i] == end) {
          //if empty do not pop return false
            stack.pop();
        }
    }
    return stack.empty();
}

// TODO: double evaluatePostfixExpression(std::string s) STACK
//given post fix expression return the value
//read the operation one token at a time, if it is a number push it onto the stack
//if the token is a operation then do the following
  //read the top of the stack for the first operand then pop
  //read the top of the stack again for the second operand then pop
  //finally perform the operation on the first and second operands then
  //push the result to the stack
  //(if the second operand of a / operation is 0 throw divide by zero error
  //6 3 + 2 *
//create a string stream
//std::stringstream sin;
//sin << s;
//define a string
//string token;
//while(sin>>token)
//return stod to make string into double

/*double evalutePostfixExpression(std::string s){
  LinkedStack<double> stack;
  for(int i = 0; i <= s.length(); i++) {
    if(isdigit(s[i])){
      stack.push(static_cast<double>((s[i])));
    } else if ()
    else {
      double op1 = stack.top();
      stack.pop();
      double op2 = stack.top();
      stack.pop();
      switch (s[i]){
        case '+':
          stack.push(op1 + op2);
          break;
        case '-':
          stack.push(op1 - op2);
          break;
        case '/':
          stack.push(op1 / op2);
          break;
        case '*':
          stack.push(op1 * op2);
          break;
        case ' ':
          break;
        default:
          std::cout << "illegal operator" << std::endl;
      }//end switch
    }//end else
  }//end for
  return stack.top();*/
//}

#endif