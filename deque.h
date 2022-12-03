/**
 * @file deque.h
 * @author Ethan Buchanan and Hunter Johnson
 * @date 2022-12-02
 * @brief Deque Class definition
 * 
 * Implementation of a deque backed by a 2D dynamic array.
 */

#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <fstream>
#include <string>



/**
 * Deque class
 *
 * @class deque deque.h "GW3-Deque-Toolkit/deque.h"
 * @brief Deque backed by a 2d array
 *
 */
class deque {
 public:

/**
 * Default constructor for deque, creates a blockmap with a default bsize
 *
 * @pre 
 * @post Creates an empty deque
 * 
 */
  deque();

/**
 * Paramertised constructor, creates a blockmap with a custom bsize
 *
 * @param int n The blocksize you want to set
 * @pre 
 * @post Creates a empty deque with a custom blocksize
 * 
 */
  deque(int n);

/**
 * Class destructor, deletes the deque
 *
 * @pre 
 * @post THe deque has been deleted
 * 
 */
  ~deque();

/**
 * returns the frontmost element of the deque
 *
 * @pre The deque is not empty
 * @return int The frontmost element of the deque
 * @post 
 * 
 */
  int front();

/**
 * Returns the backmost element in the deque
 *
 * @pre The deque is not empty
 * @return int the backmost element of the deque
 * @post 
 * 
 */
  int back();

/**
 * Returns whether the deque is empty or not
 *
 * @pre 
 * @return bool Returns true if empty false otherwise
 * @post 
 * 
 */
  bool empty();

/**
 * Returns the number of elements in the deque
 *
 * @pre the deque is not empty
 * @return int The number of elements in the deque
 * @post 
 * 
 */
  int Size();

/**
 * Pushes an element to the front of the deque and adds a new array if the deque is full
 *
 * @param int n The element to put in the deque
 * @pre if the deque is empty allocates new array and sets (0,0) to n;
 * @return void 
 * @post A new element has been added to the front of the deque
 * 
 */
  void push_front(int n);

/**
 * Pushes an element to the back of the deque and adds a new array if the deque is full
 *
 * @param int n Th eleement to be pushed to the deque
 * @pre If the deque is empty allocates the new array and sets (0,0) to n
 * @return void 
 * @post If the deque is empty allocates the new array and sets (0,0) to n
 * 
 */
  void push_back(int n);

/**
 * Removes an element from the front of the deque
 *
 * @pre 
 * @return void 
 * @post The front of the deque has been removed
 * 
 */
  void pop_front();

/**
 * Removes the element from the back of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void pop_back();

/**
 * Prints out the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print();

/**
 * Allocates an array to the first pointer in the 2D dynamic array
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void allocate();

/**
 * Reads from a file and pushes the values into a deque
 *
 * @param std::string fileName The name fo the file
 * @pre 
 * @return void 
 * @post The deque is filled with numbers from the file
 * 
 */
  void push_from_file(std::string fileName);

/**
 * Returns the value of an index from just one number and not the coordinates of its position in the 2D dynamic array
 *
 * @param unsigned int index The index you want to find
 * @pre 
 * @return int The element at the index
 * @post 
 * 
 */
  int operator[](unsigned int index);

 private:
  //2D-dynamic array
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
