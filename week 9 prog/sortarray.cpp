#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//bubble sort based on the 1st column in ascending order 
void bubbleSort(int myArray[5][4]);

//selection sort based on the 2nd column in descending order 
void selectionSort(int myArray[5][4]);

//insertion sort based on the 5th   row in ascending order 
void insertionSort(int myArray[5][4]);

//Ask the user for a number, search for that number 
//in the 5th row of the array that was sorted via insertion sort, using binary search
int binarySearch(int index);

void printRow(int myArray[5][4]);
void printCol(int myArray[5][4]);


int main()
{
	
	int array[5][4] = {{5,3,2,16},{9,8,10,17},{4,7,11,18},{2,5,9,12},{7,9,4,10}};
	int x, y,searchIndex;
	/*
	for(x = 0; x < 5; x ++) {
    for(y = 0; y < 4; y ++) array[x][y] = 0;
	}
	*/
	bubbleSort(array);
	selectionSort(array);
	insertionSort(array);
	cout << "what number do you want to search for in the fifth row?\n";
	cin >> searchIndex;

	int result = binarySearch(searchIndex);

	for(int j= 0; j< 5;j++)
	{
		printCol();
	}
}

void bubbleSort(int myArray[5][4])
{
	
}
