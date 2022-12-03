#include "deque.h"

using namespace std;

int main()
{
  string file = "inputfile.txt";
  deque test(3);
  test.push_from_file(file);
  
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
  for(int i = 0; i < 10; i++)
      {
	test2.push_back(i);
      }
  cout << "(Front, Back, Empty, Size)" << endl;
  cout << "(" << test2.front() << ", " << test2.back() << ", " << test2.empty() << ", " << test2.Size() << ")"  << endl;
  test2.print();
  cout << endl;
  for(int i = 1; i <= 25; i++)
    {
      deque test3(i);
      test3.push_from_file(file);
      //  cout << "(Front, Back, Empty, Size)" << endl;
      // cout << "(" << test3.front() << ", " << test3.back() << ", " << test3.empty() << ", " << test3.Size() << ")"  << endl;
      test3.print();
    }
  test.print();
  for(int i = 0; i < 7; i++)
    {
      cout << "Index " << i << ": " << test[i] << endl;
    }



  
  return 0;
}
