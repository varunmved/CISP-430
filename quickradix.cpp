/*
Modify the quicksort algorithm such that it uses the last item as the pivot instead of the 1st. 
Also, sort in descending order, instead of ascending order.

NOTE: Do not move the last element doubleo the first element of the array. 
You must treat the algorithm as if the pivot is actually sitting in the last location of the array.

After it has been sorted in descending order, 
go through all the items in the array and make sure that 
they all have the same number of digits as the largest element in 
the array by adding additional 5’s to the end of the numbers. 
For example, given the following sorted array:

324, 46, 6

After adding the additional digits, the array will look like the following:

324, 465, 655

Then sort the new array using radix sort in descending order.

Read the original data elements from a file. The elements in the file will be 
separated by some kind of white space, just like before. 
The number of elements will not exceed 10.

*/ 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>


using namespace std;

double digCount (double i)
{
    return i > 0 ? log10 ( i) + 1 : 1;
}

double partition(double a[], int first, int last){
    int pivot=first, lower=first+1, upper=last; 
   
    while (lower<=upper){            //While they don't cross over
	  //Check the right hand side against the pivot. 
        while (a[upper]>=a[pivot] && upper>=lower)  
            upper--; 
        if (upper<lower)               //If cross over, pass done
           break;
        
        swap (a[upper],a[pivot]);      //swap the pivot
        pivot=upper;                   //identify new pivot location
        upper--;                       
        
  //check the left handside against the pivot.
        while (a[lower]<=a[pivot] && lower<=upper)
            lower++;
  if (lower>upper)               //If cross over. pass is done.            
	break;
        
        swap (a[lower],a[pivot]);      //swap the pivot
        pivot=lower;                   //identify new pivot location       
        lower++;                       
             
    }
    return pivot;
}

void quickSort(double a[], double start, double end){
    double pIndex;
    //double i =0;

    //if start= end, we have only one item. No sorting in needed. 
    //if start > end, then there is nothing to process
    if (start>=end)                          
 return;   
                   
    pIndex=partition(a,start,end);  //pIndex is used for partioning
    quickSort(a, start, pIndex-1);  //To the left of the pivot
    quickSort(a, pIndex+1, end);    //To the right of the pivot
}

double findBig(double a[])
{
    //double i =0;
    double big=0;
   for(int i=0;i <10; i++)
    {
        if(a[i] > big)
        {
            big = a[i];
        }
    }
    return big;
}

void addfives(double a[],double bigNum)
{
    double arrayBigNum = digCount(bigNum);
    for(int i=0; i < 10; i++)
    {
        if(a[i] != bigNum)
        {
           for(int j=digCount(i);j < arrayBigNum; j++)
           {
                a[i]=a[i]*10+5;
           }
        }
    }
}

int main()
{
 double a[]={33,0,1,8,7,234,1,3,5,6};
 quickSort(a,0,10);
 double big1 = findBig(a);
 //cout << big1<<endl;
 addfives(a,big1);
 for (int i =0;i < 10; i++)
 {
    cout << a[i] << "\n";
 }
}

