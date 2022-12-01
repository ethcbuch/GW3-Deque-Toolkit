#include "deque.h"

using namespace std;

int main()
{
  string file = "inputfile.txt";
  deque test(file, 3);
  cout << "front: " << test.front() << endl;
  cout << "back: " << test.back() << endl;
  cout << "empty: " << test.empty() << endl;
  cout << "size: " << test.Size() << endl;
  test.print();
  return 0;
}
