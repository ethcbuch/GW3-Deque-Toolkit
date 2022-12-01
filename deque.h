#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <fstream>
#include <string>


class deque {
 public:
  deque();
  deque(std::string fileName, int n);
  ~deque();
  void push_front(int n);
  void push_back(int n);
  void pop_front();
  void pop_back();
  int front();
  int back();
  bool empty();
  int Size();
  void setbsize(int n);
  void print();
  void Allocation(std::string fileName);
  //  &int operator[](unsigned int index);

 private:
  int **blockmap;
  int size;
  int columns;
  int bsize;
  
};



#endif
