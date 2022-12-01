#include "deque.h"

using namespace std;



void deque::Allocation(string fileName)
{
  ifstream inputFile;
  inputFile.open(fileName);
  columns = 1;
  blockmap = new *int[columns];
  for(int i = 0; i < columns; i++)
    {
      blockmap[i] = new int[bsize];
      for(int v = 0; v < bsize; v++)
	{
	  if(inputFile)
	    {
	      inputFile >> blockmap[i][v];
	    }
	}
      if(inputFile)
	{
	  columns++;
	  int **temp;
	  temp = new *int[columns];
	  for(int f = 0; f < (columns - 1); f++)
	    {
	      temp[f] = blockmap[f];
	    }
	  blockmap = temp;
	  delete[] temp;
	}
    }
  inputFile.close();
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
