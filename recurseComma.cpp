#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

string putCommas(long n);

int main()
{
	//long longIn=1000;
	long longIn;
	cout << "what number?";
	cin >> longIn;
	string result = putCommas(longIn);
	/*
	for(int i =0; i < 14; i++)
	{
		cout << result[i];
	}
	*/
	cout << result;
	return 0;
}

string putCommas(long n)
{
	string n2;
	n2 = char(n%1000);
	if((n/1000)==0) return n2;
	else
	{
		while(n2.size() < 3)
		{
			n2 = '0'+n2;
		}
		return putCommas(n/1000)+',' + n2;
	}

	
	
}