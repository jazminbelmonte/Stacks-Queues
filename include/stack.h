#ifndef _STACK_H_
#define _STACK_H_
#include <stdexcept>

template <typename T>
class StackADT {
public:
  virtual bool full() const = 0;
  virtual bool empty() const = 0;
  virtual void push(T e) = 0;
  virtual T top() const = 0;
  virtual void pop() = 0;
  virtual ~StackADT(){}
};

template <typename T>
struct Node {
  T info;
  Node* link;
  Node(T info): info(info), link(nullptr){}
};

template <typename T>
class LinkedStack : public StackADT<T> {
public:
  LinkedStack();
  LinkedStack(const LinkedStack<T>& s);
  LinkedStack<T>& operator=(const LinkedStack<T>& s);
  bool full() const;
  bool empty() const;
  void push(T e);
  T top() const;
  void pop();
  ~LinkedStack();

private:
  Node<T>* first;
  LinkedStack<T>& copy(const LinkedStack<T>& s);
  void destroy();
};

// Implementation
template <typename T>
LinkedStack<T>::LinkedStack(): first(nullptr){}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& s){
  copy(s);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& s){
  destroy();
  return copy(s);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::copy(const LinkedStack<T>& s){
  first = nullptr;
  Node<T>* last = nullptr;
  auto current = s.first;
  while(current){
    auto newNode = new Node<T>(current->info);
    if(first == nullptr){ // empty list
      first = newNode;
    } else {
      last->link = newNode;
    }
    last = newNode;
    current = current->link;
  }

  return *this;
}

template <typename T>
void LinkedStack<T>::destroy(){
  auto current = first;
  while(current){
    auto temp = current;
    current = current->link;
    delete temp;
  }
}

template <typename T>
bool LinkedStack<T>::full() const{
  return false;
}

template <typename T>
bool LinkedStack<T>::empty() const{
  return first == nullptr;
}

template <typename T>
void LinkedStack<T>::push(T e){
  auto node = new Node<T>(e);
  node->link = first;
  first = node;
}

template <typename T>
T LinkedStack<T>::top() const {
  if(empty()){
    throw std::runtime_error("Stack is empty");
  }
  return first->info;
}

template <typename T>
void LinkedStack<T>::pop(){
  if(empty()){
    throw std::runtime_error("Stack is empty");
  }

  auto tmp = first;
  first = first->link;
  delete tmp;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
  destroy();
}

#endif