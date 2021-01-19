// Copyright 2021 Islam Osmanov
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
private:
  T* database;
  int top;
  int size;

public:
  ~MyStack() {
    delete[] database;
    this->top = -1;
    this->size = 0;
  }

  MyStack(int length) : top(-1), 
                      size(length), 
                      database(new T[length]) {}

  MyStack(const MyStack& OtherStack) {
    database = new T[OtherStack.size];
    for (int n = 0; n < OtherStack.size + 1; n++) {
      database[n] = OtherStack.database[n];
    }
    top = OtherStack.top;
    size = OtherStack.size;
  }

  bool isFull() const {
    if (size == top) {
      return true;
    }
    else {
      return false;
    }
  }

  T get() const {
    return database[top];
  }

  bool isEmpty() const {
    if (top < 0) {
      return true;
    }
    else {
      return false;
    }
  }

  T pop() {
    return database[top--];
  }

  void push(T th) {
    database[++top] = th;
  }
};

#endif  // INCLUDE_MYSTACK_H_
