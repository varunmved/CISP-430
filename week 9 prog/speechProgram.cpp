#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	string name;
	int numOfPrint;
	int i=0;

	cout << "hello, what is your name? ";
	cin >> name;

	cout << "\n# of times you want to print your name? ";
	cin >> numOfPrint;
	if(numOfPrint < 0) cout << "sorry I can't do that!\n";

	else for (i; i <numOfPrint; i++)
	{
		cout <<"hello "<< name << endl;
	}
	return 0;

}