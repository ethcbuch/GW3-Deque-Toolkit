#include "deque.h"
#include <iomanip>
#define underline "\033[4m"
#define ununderline "\033[0m"
using namespace std;

deque::deque()
{
  blockmap = NULL;
  bsize = 11;
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
  for(int i = 0; i < columns; i++)
    {
      delete[] blockmap[i];
    }
  delete[] blockmap;
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
  if (empty()) {
    allocate();
    blockmap[0][0] = n;
  }
  else if(frontX != 0)
    {
      blockmap[frontY][frontX - 1] = n;
      frontX = frontX - 1;
    }
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

void deque::push_back(int n) {
  if (empty()) {
    allocate();
    blockmap[0][0] = n;
  }
  else if(size < (columns*bsize))
         {
           blockmap[rearY][rearX+1] = n;
           rearX++;
         }
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
      blockmap[columns-1] = new int[bsize]();
      blockmap[columns-1][0] = n;
      rearY = rearY + 1;
      rearX = 0;
    }
  size++;
}

void deque::pop_front()
{
  if(frontX != (bsize - 1))
    {
      blockmap[0][frontX] = 0;
      frontX = frontX + 1;
    }
  else
    {
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

void deque::pop_back()
{
  if(rearX != 0)
    {
      blockmap[columns - 1][rearX] = 0;
      rearX = rearX - 1;
    }
  else
    {
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

void deque::print()
{
  int n = 0;
  cout << underline;
  cout << "The Physical Interpretation of this Deque:";
  for(int i = 0; i < (bsize * 6) - 41; i++)
    {
      cout << " ";
    }
  cout << endl;
  for(int i = 0; i < bsize; i++)
    {
      if(i < frontX)
	{
	  cout << "|" << setw(5) << " ";
	}
      else if(i >= frontX && i < size)
	{
	  cout << "|" << setw(4) << blockmap[0][i] << " ";
	  n++;
	}
      else if(i >= size)
	{
	  cout << "|" << setw(5) << " ";
	}
    }
  cout << "|" << endl;
  for(int i = 1; i < columns; i++)
    {
      for(int v = 0; v < bsize; v++)
	{
	  if(n < size)
	    {
	      cout << "|" << setw(4) << blockmap[i][v] << " ";
	      n++;
	    }
	  else
	    {
	      cout << "|" << setw(5) << " ";
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
      push_front(value);
      
      inputFile >> value;
    }

  inputFile.close();
}


int deque::operator[](unsigned int index)
{
  int X;
  int Y = 0;
  int temp;
  temp = (index + 1) - bsize;
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
 
}


