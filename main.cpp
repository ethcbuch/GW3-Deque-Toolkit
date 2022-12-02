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
  deque test(file, 19);
  cout << "front: " << test.front() << endl;
  cout << "back: " << test.back() << endl;
  cout << "empty: " << test.empty() << endl;
  cout << "size: " << test.Size() << endl;
  test.print();
  for(int i = 0; i < 10000; i++)
    {
      test.push_back(102 - i);
      test.push_front(102 + i);
      cout << "front: " << test.front() << endl;
      cout << "back: " << test.back() << endl;
      cout << "empty: " << test.empty() << endl;
      cout << "size: " << test.Size() << endl;
      //test.print();
    }
  test.print();
  deque test2;
  //test2.setbsize(3);
  //test2.coords();
  for(int i = 0; i < 40; i++)
  {
    test2.push_back(i);
    test2.push_front(-i);
  }
  cout << endl;
  cout << test2.front() << endl;
  cout << test2.back() << endl;
  test2.print();
  return 0;
}

