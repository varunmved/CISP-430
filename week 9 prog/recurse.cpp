#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int solveF(int entry);

int main()
{
	int num;
	cout << "num pls \n";
	cin >> num;
	int solution = solveF(num);
	cout << solution;
}

int solveF(int entry)
{
	int f1;
	if(entry == 0) return 0;
	else return (entry%10) + solveF(entry/10);
}