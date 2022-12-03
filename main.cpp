#include "deque.h"

using namespace std;

int main()
{
  
  /* ofstream outputFile;
  outputFile.open("inputfile.txt");
  for(int i = 1; i <= 10000; i++)
    {
      outputFile << i << endl;
    }
  outputFile.close();*/
  string file = "inputfile.txt";
  deque test(10);
  test.push_from_file(file);
  
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test.front() << ", " << test.back() << ", " << test.empty() << ", " << test.Size() << ")"  << endl;
  test.print();
  /* for(int i = 5000; i < 10003; i++)
    {
      cout << test[i] << endl;
    }
  */
  deque test4;
  cout << test4[3] << endl;
  test4.pop_back();
  test4.pop_front();
  /*  test.push_back(5);
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
  for(int i = 0; i < 10; i++)
      {
	test2.push_back(i);
      }
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test2.front() << ", " << test2.back() << ", " << test2.empty() << ", " << test2.Size() << ")"  << endl;
  test2.print();
  cout << endl;

  */
  /*  for(int i = 1; i <= 25; i++)
    {
      deque test3(i);
      test3.push_from_file(file);
      //  cout << "(Front, Back, Empty, Size)" << endl;
      // cout << "(" << test3.front() << ", " << test3.back() << ", " << test3.empty() << ", " << test3.Size() << ")"  << endl;
      test3.print();
    }
  */
  return 0;
}
