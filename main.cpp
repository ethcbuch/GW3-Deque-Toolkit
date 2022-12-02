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
  deque test(file, 8);
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test.front() << ", " << test.back() << ", " << test.empty() << ", " << test.Size() << ")"  << endl;
  test.print();
  
  test.push_back(5);
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test.front() << ", " << test.back() << ", " << test.empty() << ", " << test.Size() << ")"  << endl;
  test.print();

  test.pop_back();
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test.front() << ", " << test.back() << ", " << test.empty() << ", " << test.Size() << ")"  << endl;
  test.print();
  
  for(int i = 0; i < 20; i++)
    {
      test.push_back(102 + i);
      test.push_front(0 - i);
      cout << "(Front, Back, Empty, Size)" << endl;
      cout << "(" << test.front() << ", " << test.back() << ", " << test.empty() << ", " << test.Size() << ")"  << endl;
      test.print();
    }
  
  deque test2;
  test2.setbsize(8);
  for(int i = 0; i < 10; i++)
      {
	test2.push_back(i);
      }
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test2.front() << ", " << test2.back() << ", " << test2.empty() << ", " << test2.Size() << ")"  << endl;
  test2.print();
  
  test2.setbsize(3);
  test2.coords();

  cout << endl;
  cout << test2.front() << endl;
  cout << test2.back() << endl;
  test2.print();
  return 0;
}
