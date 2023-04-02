//  Created by Ahmed Tarek


#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include<string>
using namespace std;
template <class Type>

class Queue {
private:
 
  Type *a;
  int rear;
  int front;
  int nItems;

public:
  Queue() {
   
    a = new Type[100];
    rear = -1;
    front = 0;
    nItems = 0;
  }
  void push(Type x) {
   
    if (rear == 99)
      rear = 0;
    else
      rear++;
    a[rear] = x;

    nItems++;
  }
  Type pop() {
    Type x = a[front];
  
    if (front == 99)
      front = 0;
    else
      front++;

    nItems--;

    return x;
  }
  bool isEmpty() {
    if (nItems == 0)
      return true;
    else
      return false;
  }
  int length() { return nItems; }
};

#endif 
