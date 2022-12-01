#include "deque.h"

using namespace std;

deque::deque()
{
  blockmap = NULL;
  size = 0;
  bsize = 0;
  columns = 1;
}

deque::deque(string fileName, int n)
{
  bsize = n;
  columns = 1;
  size = 0;
  Allocation(fileName);
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
  return blockmap[0][0];
}

int deque::back()
{
  return blockmap[columns - 1][bsize - 1];
}

bool deque::empty()
{
  if(blockmap == NULL)
    {
      return true;
    }
  else if(blockmap != NULL)
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
  
}

void deque::push_back(int n)
{
  
}


void deque::setbsize(int n)
{
  bsize = n;
}

void deque::print()
{
  for(int i = 0; i < columns; i++)
    {
      cout << "Pointer " << i << " elements: ";
      for(int v = 0; v < bsize; v++)
	{
	  cout << blockmap[i][v] << " - ";
	}
      cout << "end" << endl;
    }
}


void deque::Allocation(string fileName)
{
  ifstream inputFile;
  int **temp;
  int temp2;
  inputFile.open(fileName);
  blockmap = new int*[columns];
  for(int i = 0; i < columns; i++)
    {
      blockmap[i] = new int[bsize];
      for(int v = 0; v < bsize; v++)
	{
	  temp2 = inputFile.peek();
	  cout << temp2 << endl;
	  if(temp2 != -1)
	    {
	      inputFile >> blockmap[i][v];
	      inputFile.get();
	      size++;
	    }
	}
      if(inputFile)
	{
	  columns++;
	  temp = new int*[columns];
	  for(int f = 0; f < (columns - 1); f++)
	    {
	      temp[f] = blockmap[f];
	    }
	  blockmap = temp;
	}
      if(temp2 == -1)
	{
	  columns--;
	}
    }
  temp = new int*[columns];
  delete[] temp;
  inputFile.close();
}


