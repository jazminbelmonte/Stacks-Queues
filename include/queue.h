#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "stack.h"

template <typename T>
class QueueADT {
public:
  virtual bool full() const = 0;
  virtual bool empty() const = 0;
  virtual void enqueue(T e) = 0;
  virtual T peekFront() const = 0;
  virtual T peekRear() const = 0;
  virtual void dequeue() = 0;
  virtual ~QueueADT(){}
};

template <typename T>
class LinkedQueue : public QueueADT<T> {
public:
  LinkedQueue();
  LinkedQueue(const LinkedQueue<T>& q);
  LinkedQueue<T>& operator=(const LinkedQueue<T>& q);
  bool full() const;
  bool empty() const;
  void enqueue(T e);
  T peekFront() const;
  T peekRear() const;
  void dequeue();
  ~LinkedQueue();

private:
  Node<T>* front;
  Node<T>* rear;
  LinkedQueue<T>& copy(const LinkedQueue<T>& q);
  void destroy();
};

// Implemenation
template <typename T>
LinkedQueue<T>::LinkedQueue(): front(nullptr), rear(nullptr){}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& q){
  copy(q);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& q){
  destroy();
  return copy(q);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::copy(const LinkedQueue<T>& q){
  front = nullptr;
  rear = nullptr;
  auto current = q.front;
  while(current){
    auto newNode = new Node<T>(current->info);
    if(front == nullptr){ // empty list
      front = newNode;
    } else {
      rear->link = newNode;
    }
    rear = newNode;
    current = current->link;
  }

  return *this;
}

template <typename T>
void LinkedQueue<T>::destroy(){
  auto current = front;
  while(current){
    auto temp = current;
    current = current->link;
    delete temp;
  }
}

template <typename T>
bool LinkedQueue<T>::full() const{
  return false;
}

template <typename T>
bool LinkedQueue<T>::empty() const{
  return front == nullptr;
}

template <typename T>
void LinkedQueue<T>::enqueue(T e){
  auto node = new Node<T>(e);
  if(front == nullptr){
    front = node;
  }else{
    rear->link = node;
  }

  rear = node;
}

template <typename T>
T LinkedQueue<T>::peekFront() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }
  return front->info;
}

template <typename T>
T LinkedQueue<T>::peekRear() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }
  return rear->info;
}

template <typename T>
void LinkedQueue<T>::dequeue(){
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }

  auto tmp = front;
  front = front->link;
  delete tmp;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
  destroy();
}

#endif