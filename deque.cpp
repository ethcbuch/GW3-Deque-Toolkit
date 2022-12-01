#include "deque.h"
#include <iomanip>
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
  int n = size%bsize;
  if(n > 0)
    {
      return blockmap[columns - 1][n - 1];
    }
  else
    {
      return blockmap[columns - 1][bsize - 1];
    }
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










  
}

void deque::push_back(int n)
{
  int r = size%bsize;
  if(r > 0)
    {
      blockmap[columns - 1][r] = n;
    }
  if(r == 0)
    {
      int **temp;
      columns++;
      temp = new int*[columns];
      for(int f = 0; f < (columns - 1); f++)
	{
	  temp[f] = blockmap[f];
	}
      blockmap = temp;
      temp = new int*[columns];
      delete[] temp;
      blockmap[columns - 1] = new int[bsize];
      blockmap[columns - 1][0] = n;
      blockmap[columns - 1][1] = 0;
      blockmap[columns - 1][2] = 0;
    }
  size++;
}


void deque::setbsize(int n)
{
  bsize = n;
}

void deque::print()
{
  for(int i = 0; i < columns; i++)
    {
      for(int v = 0; v < bsize; v++)
	{
	  cout << "|" << setw(5) << blockmap[i][v] << " |";
	}
      cout << endl;
    }  
}


void deque::Allocation(string fileName)
{
  ifstream inputFile;
  int **temp;
  int temp2;
  inputFile.open(fileName);
  blockmap = new int*[columns];
  temp2 = inputFile.peek();
  for(int i = 0; i < columns; i++)
    {
      blockmap[i] = new int[bsize];
      for(int v = 0; v < bsize; v++)
	{
	  if(temp2 != -1)
	    {
	      inputFile >> blockmap[i][v];
	      inputFile.get();
	      temp2 = inputFile.peek();
	      size++;
	    }
	  else
	    {
	      blockmap[i][v] = 0;
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


