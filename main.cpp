#include "deque.h"

using namespace std;

int main()
{
  string file = "inputfile.txt";
  /*  ofstream outputFile;
  outputFile.open(file);
  for(int i = 0; i < 101; i++)
    {
      outputFile << i << endl;
    }
  outputFile.close();
  */
  deque test(file, 3);
  cout << "front: " << test.front() << endl;
  cout << "back: " << test.back() << endl;
  cout << "empty: " << test.empty() << endl;
  cout << "size: " << test.Size() << endl;
  test.print();
  for(int i = 0; i < 6; i++)
    {
      test.push_back(102 + i);
      cout << "front: " << test.front() << endl;
      cout << "back: " << test.back() << endl;
      cout << "empty: " << test.empty() << endl;
      cout << "size: " << test.Size() << endl;
      test.print();
    }
  return 0;
}
