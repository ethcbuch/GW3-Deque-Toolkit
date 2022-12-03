#include "deque.h"
#include <unistd.h>

using namespace std;

int main()
{


  //Test 1 Default Constructor and its Modifcations
  
  //Default Constructor when empty, what happens?
  deque Test_1;
  cout << "This is what happens when the deque is empty!" << endl;
  cout << Test_1[3] << endl;
  Test_1.pop_back();
  Test_1.pop_front();
  //Pushing to front or back when empty?
  cout << "Push one to front: " << endl;
  Test_1.push_front(1);
  Test_1.print();
  cout << "Pop one from front: " << endl;
  Test_1.pop_front();
  Test_1.print();
  cout << endl;
  cout << "Push one to back: " << endl;
  Test_1.push_back(1);
  Test_1.print();
  cout << "Pop one from back: " << endl;
  Test_1.pop_back();
  Test_1.print();
  cout << endl;
  //Lots of Pushing to front
  for(int i = 1; i <= 5000; i++)
    {
      Test_1.push_front(i);
    }
  cout << "So you can actually see the first section of Test 1 above I have implemented a pause before the current physical version of Test_1 is printed as it is massive!" << endl;
  cout << "Now I am going to push_front 100,000 integers!" << endl;
  for(int i = 20; i >= 1; i--)
    {
      if(i <= 5)
	{
	  cout << i << endl;
	}
      //      sleep(1);
    }
  Test_1.print();
  cout << "See I told you it was big ranging from 100,000 to 1! The stats are as follows: " << endl << endl;
  cout << "(Front, Back, Is Empty?, Size)" << endl;
  cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;
  cout << "Now I am going to pop from the front half of the numbers!" << endl;
  for(int i = 0; i < 4500; i++)
    {
      Test_1.pop_front();
    }
  cout << "Now another brief pause to read the stats and catch your breath from the last one!" << endl;
  for(int i = 30; i >= 1; i--)
    {
      if(i == 5)
	{
	  cout << "Hope you're ready cause here it comes!" << endl;
	  // sleep(1);
	}
      if(i <= 5)
	{
	  cout << i << endl;
	}
      // sleep(1);
    }
  Test_1.print();
  cout << "And the stats for this one are as follows: " << endl << endl;
  cout << "(Front, Back, Is Empty?, Size)" << endl;
  cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;
  cout << "Now then, let's push to the back 2000 EVEN integers!" << endl;
  for(int i = 1; i <= 2500 ; i++)
    {
      Test_1.push_back((i * 2));
    }
   cout << "Another Pause for your viewing pleasure!" << endl;
    for(int i = 30; i >= 1; i--)
    {
      if(i == 5)
	{
	  cout << "Please remain seated at all times during the flight, prepare for take off in..." << endl;
	  //	  sleep(1);
	}
      if(i <= 5)
	{
	  cout << i << endl;
	}
      //  sleep(1);
    }
    Test_1.print();
    cout << "I hope you enjoyed your flight, here are the stats for it!" << endl << endl;
    cout << "(Front, Back, Is Empty?, Size)" << endl;
    cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;



  //Test 2 Using a parameterized Constructor and reading from a file




































  /*
  deque test(10);
  test.push_from_file(file);
  test.print();
  for(int i = 5000; i < 10003; i++)
    {
      cout << test[i] << endl;
    }
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
  */
  return 0;
}
