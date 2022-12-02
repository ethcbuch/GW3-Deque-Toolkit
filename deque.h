#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <fstream>
#include <string>


class deque {
 public:
  deque();
  deque(int n);
  ~deque();
  void coords();
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
  void push_from_file(std::string fileName);
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
  void allocate();
  
};



#endif
