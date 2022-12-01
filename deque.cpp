#include "deque.h"

using namespace std;

int deque::getColumns()
{
  return columns;
}


void deque::Allocation(string fileName)
{
  ifstream inputFile;
  int **temp;
  int temp2;
  inputFile.open(fileName);
  columns = 1;
  blockmap = new int*[columns];
  for(int i = 0; i < columns; i++)
    {
      blockmap[i] = new int[bsize];
      for(int v = 0; v < bsize; v++)
	{
	  temp2 = inputFile.peek();
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
  /* size = size - 1;
  if(size%bsize == 0)
    {
      columns - 1;
    }
  */
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
  cout << endl << size << endl;
}
