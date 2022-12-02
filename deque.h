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
  int front();
  int back();
  void coords();
  bool empty();
  int Size();
  void setbsize(int n);
  void push_front(int n);
  void push_back(int n);
  void pop_front();
  void pop_back();
  void print();
  void Allocation(std::string fileName);
  //  &int operator[](unsigned int index);

 private:
  int **blockmap;
  int size;
  int columns;
  int bsize;
  int rearX;
  int rearY;
  int frontX;
  int frontY;
  
};



#endif
