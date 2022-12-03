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
  for(int i = 1; i <= 100000; i++)
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
      sleep(1);
    }
  Test_1.print();
  cout << "See I told you it was big ranging from 100,000 to 1! The stats are as follows: " << endl << endl;
  cout << "(Front, Back, Is Empty?, Size)" << endl;
  cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;
  cout << "Now I am going to pop from the front half of the numbers!" << endl;
  for(int i = 0; i < 50000; i++)
    {
      Test_1.pop_front();
    }
  cout << "Now another brief pause to read the stats and catch your breath from the last one!" << endl;
  for(int i = 30; i >= 1; i--)
    {
      if(i == 5)
	{
	  cout << "Hope you're ready cause here it comes!" << endl;
	  sleep(1);
	}
      if(i <= 5)
	{
	  cout << i << endl;
	}
      sleep(1);
    }
  Test_1.print();
  cout << "And the stats for this one are as follows: " << endl << endl;
  cout << "(Front, Back, Is Empty?, Size)" << endl;
  cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;
  cout << "Now then, let's push to the back 25000 EVEN integers!" << endl;
  for(int i = 1; i <= 25000 ; i++)
    {
      Test_1.push_back((i * 2));
    }
   cout << "Another Pause for your viewing pleasure!" << endl;
    for(int i = 30; i >= 1; i--)
    {
      if(i == 5)
	{
	  cout << "Please remain seated at all times during the flight, prepare for take off in..." << endl;
	  sleep(1);
	}
      if(i <= 5)
	{
	  cout << i << endl;
	}
      sleep(1);
    }
    Test_1.print();
    cout << "I hope you enjoyed your flight, here are the stats for it!" << endl << endl;
    cout << "(Front, Back, Is Empty?, Size)" << endl;
    cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;
    cout << "And to finish off the first section of Testing I will be popping from the back the 12500 integers!" << endl;
    for(int i = 0; i < 12500; i++)
      {
	Test_1.pop_back();
      }
    cout << "Now by now you must be getting annoyed by the huge arrays, but its 'Stress Testing', I swear ;)! And after this commercial break will be the final massive array!" << endl;
    for(int i = 30; i >= 1; i--)
      {
	if(i == 5)
	  {
	    cout << "Do you or a love one struggle with Mesothelioma? Call 555-NOT-REAL today or talk to your doctor today!" << endl;
	    sleep(1);
	  }
	if(i == 10)
	  {
	    cout << "The scrub daddy can get out any stain or grime from any of your daily kitchen products!\n If you call within the next 20 minutes, you won't receive one, but two Scrub Daddy's for the price of one, just call SCR-UBD-ADDY that is SCR-UBD-DADDY today!" << endl;
	  }
	if(i == 15)
	  {
	    cout << "Do you struggle with not seeing that one missing semicolon? Do you rage because you missed that one key thing in your huge program?\n Then get yourself the AI checker today! It totally exists, just contact [REDACTED] today!" << endl;
	  }
	if(i <= 5)
	  {
	    cout << i << endl;
	  }
	sleep(1);
      }
    Test_1.print();    
    cout << "Bet you never thought I'ld put a commercial break in this program, well it was late and I like making things interesting, any-who here's the stats:" << endl << endl;
    cout << "(Front, Back, Is Empty?, Size)" << endl;
    cout << "(" << Test_1.front() << ", " << Test_1.back() << ", " << Test_1.empty() << ", " << Test_1.Size() << ")"  << endl << endl;
    
  //Test 2 Using a parameterized Constructor and reading from a file
    deque Test_2(10);
    Test_2.push_from_file("inputfile.txt");
    cout << "Now it's time for the second section of Testing this time the deque will be read in from a file, and we will be showing off the Index [] operator!" << endl;
    cout << "Firstly, here's the base array!" << endl;
    for(int i = 30; i >= 1; i--)
      {
	if(i == 5)
	  {
	    cout << "This one is going to be smaller, promise (*_*)" << endl;
	    sleep(1);
	  }
	if(i <= 5)
	  {
	    cout << i << endl;
	  }
	sleep(1);
      }
    Test_2.print();
    cout << "See this matrix is a lot more tame than the other ones just for easy viewing!" << endl;
    cout << "(Front, Back, Is Empty?, Size)" << endl;
    cout << "(" << Test_2.front() << ", " << Test_2.back() << ", " << Test_2.empty() << ", " << Test_2.Size() << ")"  << endl << endl;
    sleep(20);
    cout << "Now for testing the [] operator: " << endl;
    for(int i = 7; i < 23; i++)
      {
	cout << "Index " << i << ": " << Test_2[i] << endl;
      }
    cout << "When out of index range: " << endl;
    cout << "Index 153: " << Test_2[153] << endl;
    cout << "When it is empty: " << endl;
    for(int i = 0; i < 100; i++)
      {
	Test_2.pop_back();
      }
    cout << "Is Empty: " << Test_2.empty() << endl;
    cout << "Index 0: " << Test_2[0] << endl;
    for(int i = 30; i >= 1; i--)
      {
	if(i == 5)
	  {
	    cout << "This next test is nice to look at so on to Section 3 of Testing!" << endl;
	    sleep(1);
	  }
	if(i <= 5)
	  {
	    cout << i << endl;
	  }
	sleep(1);
      }
    
    //Test 3 Multiple Bsizes work
    for(int i = 1; i <= 10; i++)
      {
	cout << "For a Block size of " << i << ": " << endl;
	deque Test_3(i);
	for(int v = 1; v <= i * i; v++)
	  {
	    Test_3.push_back(v);
	  }
	Test_3.print();
      }
    
  return 0;
}
