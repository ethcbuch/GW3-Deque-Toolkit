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
  int front();
  int back();
  bool empty();
  int Size();
  void push_front(int n);
  void push_back(int n);
  void pop_front();
  void pop_back();
  void print();
  void allocate();
  void push_from_file();
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
