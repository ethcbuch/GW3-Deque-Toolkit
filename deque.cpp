/**
 * @file deque.cpp
 * @author Ethan Buchanan
 * @date 2022-12-02
 * @brief DEque implementation
 * 
 * DEque Class implementation push/pop front/back and accesors for front/back
 */

#include "deque.h"
#include <iomanip>
#define underline "\033[4m"
#define ununderline "\033[0m"
using namespace std;

deque::deque()
{
  //initilizes a empty deque
  blockmap = NULL;
  bsize = 17;
  columns = 1;
  size = 0;
  rearX = 0;
  rearY = 0;
  frontX = 0;
  frontY = 0;
}

deque::deque(int n)
{
  blockmap = NULL;
  bsize = n;
  columns = 1;
  size = 0;
  rearX = 0;
  rearY = 0;
  frontX = 0;
  frontY = 0;
}

deque::~deque()
{
  //If empty nothing to delete
  if(empty())
    {
      return;
    }
  else
    { 
      for(int i = 0; i < columns; i++)
	{
	  delete[] blockmap[i];
	}
      delete[] blockmap;
    }
}

int deque::front()
{
  return blockmap[frontY][frontX];
}

int deque::back()
{
  return blockmap[rearY][rearX];
}
  
bool deque::empty()
{
  if(blockmap == NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

int deque::Size()
{
  return size;
}

void deque::push_front(int n)
{
  //If empty create allocate a array block and push to the frontmost which is (0,0)
  if (empty())
    {
      allocate();
      blockmap[0][0] = n;
    }
  else if(frontX != 0)
    {
      blockmap[frontY][frontX - 1] = n;
      frontX = frontX - 1;
    }
  //if array is full, create new array block and put n at the end/front
  else
    {
      int **temp;
      columns++;
      temp = new int*[columns];
      for(int i = 1; i <= columns - 1; i++)
	{
	  temp[i] = blockmap[i - 1];
	}
      blockmap = temp;
      temp = new int*[columns];
      delete[] temp;
      blockmap[0] = new int[bsize]();
      blockmap[0][bsize - 1] = n;
      frontX = bsize - 1;
      rearY = rearY + 1;
    }
size++;
}

void deque::push_back(int n)
{
  //If empty allocate new array block and put n at (0,0)
  if (empty())
    {
      allocate();
      blockmap[0][0] = n;
    }
  //If size is less than capacity(bsize*columns) put at back of array
  else if(size < (columns * bsize))
    {
      blockmap[rearY][rearX + 1] = n;
      rearX++;
    }
  //If size is more than capacity create new array block and put at the back/front
  else
    {
      int **temp;
      columns++;
      temp = new int*[columns];
      for(int i = 0; i < columns - 1; i++)
	{
	  temp[i] = blockmap[i];
	}
      blockmap = temp;
      temp = new int*[columns];
      delete[] temp;
      blockmap[columns - 1] = new int[bsize]();
      blockmap[columns - 1][0] = n;
      rearY = rearY + 1;
      rearX = 0;
    }
  size++;
}

void deque::pop_front()
{
  //If empty nothing to pop from front. return
  if(empty())
    {
      cout << "Empty, no front" << endl;
      return;
    }
  else
    {
      if(frontX != (bsize - 1))
	{
	  if(frontX == 0 && columns == 1)
	    {
	      size--;
	      delete[] blockmap[0];
	      delete[] blockmap;
	      blockmap = NULL;
	      return;
	    }
	  blockmap[0][frontX] = 0;
	  frontX = frontX + 1;
	}
      else
	{
	  //If left with empty array block delete it
	  int **temp;
	  columns--;
	  temp = new int*[columns];
	  delete blockmap[0];
	  for(int i = 0; i < columns; i++)
	    {
	      temp[i] = blockmap[i+1];
	    }
	  blockmap = temp;
	  temp = new int*[columns];
	  delete[] temp;
	  frontX = 0;
	  rearY = rearY - 1;
	}
      size--;
    }
}
  

void deque::pop_back()
{
  //If empty nothing to pop from back
  if(empty())
    {
      cout << "Empty, no back" << endl;
      return;
    }
  else
    {
      if(rearX != 0)
	{
	  blockmap[columns - 1][rearX] = 0;
	  rearX = rearX - 1;
	}
      else
	{
	  //If left with empty deque at start delete everything and set blockmap to NULL
	  if(frontX == 0 && columns == 1)
	    {
	      size--;
	      delete[] blockmap[0];
	      delete[] blockmap;
	      blockmap = NULL;
	      return;
	    }
	  //If left with empty array block delete it
	  int **temp;
	  columns--;
	  temp = new int*[columns];
	  delete blockmap[columns];
	  for(int i = 0; i < columns; i++)
	    {
	      temp[i] = blockmap[i];
	    }
	  blockmap = temp;
	  temp = new int*[columns];
	  delete[] temp;
	  rearX = (bsize - 1);
	  rearY = rearY - 1;
	}
      size--;
    }
}

void deque::print()
{
  //If empty nothing to print
  if (empty())
    {
      cout << "Deque is empty. Nothing to print!" << endl;
      return;
    }
  int max = 0;
  for(int i = 0; i < columns - 1; i++)
    {
      for (int v = 0; v < bsize; v++)
	{
	  if(max < blockmap[i][v])
	    {
	      max = blockmap[i][v];
	    }
	}
    }
  //Find a nice setW for chart
  int gap;
  string str = to_string(max);
  gap = str.size() + 2;
  
  int n = 0;
  cout << underline;
  cout << "The Physical Interpretation of this Deque:";
  for(int i = 0; i < (bsize * (gap + 1)) - 41; i++)
    {
      cout << " ";
    }
  cout << endl;
  for(int i = 0; i < bsize; i++)
    {
      if(i < frontX)
	{
	  cout << "|" << setw(gap) << " ";
	}
      else if(i >= frontX && i < size)
	{
	  cout << "|" << setw(gap - 1) << blockmap[0][i] << " ";
	  n++;
	}
      else if(i >= size)
	{
	  cout << "|" << setw(gap) << " ";
	}
    }
  cout << "|" << endl;
  for(int i = 1; i < columns; i++)
    {
      for(int v = 0; v < bsize; v++)
	{
	  if(n < size)
	    {
	      cout << "|" << setw(gap - 1) << blockmap[i][v] << " ";
	      n++;
	    }
	  else
	    {
	      cout << "|" << setw(gap) << " ";
	    }
	}
      cout << "|" << endl;
    }
  cout << ununderline << endl;
}

void deque::allocate()
{
  blockmap = new int*[columns];
  blockmap[0] = new int[bsize]();
}

void deque::push_from_file(string fileName)
{
  ifstream inputFile;
  int value;
  inputFile.open(fileName);

  inputFile >> value;
  
  while (inputFile)
    {
      push_back(value);      
      inputFile >> value;
    }

  inputFile.close();
}


int deque::operator[](unsigned int index)
{
  //If empty no index to search
  if(empty())
    {
      cout << "Is empty no index's available, heres a zero: ";
      return 0;
    }
  //If too big, cant search for it
  if(index >= (unsigned) size)
    {
      cout << "Out of Range, heres a zero: ";
      return 0;
    }
  int X;
  int Y = 0;
  int temp;
  temp = (index + 1 + frontX) - bsize;
  while(temp > 0)
    {
      if(Y == 0)
	{
	  Y++;
	}
      temp = temp - bsize;
      if(temp > 0)
	{
	  Y++;
	}
    }
  temp = temp + bsize;
  X = temp - 1;
  return blockmap[Y][X];
}
