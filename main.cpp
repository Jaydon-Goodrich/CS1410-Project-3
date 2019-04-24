// This is my own work. Jaydon Goodrich
/* a simple attempt to recursion. This program uses recursive functions to guess a users number between 1-100. */
#include <iostream>
using namespace std;

// following several lines for unit testing purposes
#include "RecursionCounter.h"
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

void mysort(int nums[], int nelems);
void sorthelp(int myarray[], int start, int n);
void GuessNumber(int lowVal, int highVal);
void hilo(int maxNumber);

const int HUNDRED = 100;
const int SIZE = 5;
int myarray[] = {5,4,3,2,1};
//int data[SIZE] = {5,4,3,2,1};
//mysort() will call the helper function sorthelp() recursivly.
//That helper function MUST have a local variable of type RecursionCount
//as shown below:
void sorthelp(int myarray[], int start, int n)
{
	RecursionCounter rc;  // REQUIRED for Unit test
   int i;
   if (start == n){
      return;
   }
   for (i = start; i < n; i++){
      int small = myarray[start];
      if (myarray[i] < small){
         myarray[start] = myarray[i];
         myarray[i] = small;
      }
   }
   sorthelp(myarray,start + 1, n);
}
void mysort(int nums[], int nelems){
   unsigned int i = 0;
   int start = 0;
   sorthelp(nums,start,nelems);
   cout << "Sorted result:" << endl;
   for (i = 0; i < SIZE; i++){
      cout << myarray[i] << endl;
   }
}

void GuessNumber(int lowVal, int highVal) {
   int midVal;
   char userAnswer;
   
   midVal = (highVal + lowVal) / (1+1);
   
   if (highVal - lowVal == 0){
      cout << "Your number is " << midVal << endl;
   }
   else if (highVal < lowVal){
      cout << "You cheated!" << endl;
   }
   else{
      cout << "Is it " << midVal << " (l,y,h)? " << endl;
      cin >> userAnswer;
      if (highVal - lowVal == 0){
         cout << "Your number is " << midVal << endl;
      }
      else{
         if( (userAnswer != 'l') && (userAnswer != 'h') ) {
            cout << "Your number is " << midVal << endl;                   
         }
         else if (userAnswer == 'h') {
             GuessNumber(lowVal, midVal - 1);
         }
         else if (userAnswer == 'l') {
            GuessNumber(midVal + 1, highVal);
         }
      }
   }
}
void hilo(int maxNumber){
   GuessNumber(1,maxNumber);
}


int main() {

   cout << "Think of a number between 1 and 100" << endl;
   cout << "I will try and guess it with your help." << endl;
   cout << endl;
   hilo(HUNDRED);
   cout << endl;
   
   mysort(myarray,SIZE);
   
   
   
   
   return 0;
}
