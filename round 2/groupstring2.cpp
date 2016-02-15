// GroupString.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <istream>
//#include <string>
#include <stdio.h>
using namespace std;

ifstream in("in.txt");
ofstream out("output.txt");

//FILE *fin;
//FILE *fout;


void stringCopy(char *A, char *B)
{
	int i = 0;
	while (A[i] >= 32)
	{
	    A[i] = B[i];
		  i++;
	}
}

bool stringCompare(char *A, char *B)
{
	bool same = true;
	int i = 0;
	while (same)
	{
		if (A[i] != B[i])
			same = false;
		break;
	}
	return same;
}

void stringConcatenation(char *A, char *B)
{
	int h = 0;
	int a = 0;
	int j = 0;
	int k = 0; 
	while (B[h] >= 32)
	{
		h++;
		j++;
	}
	while (A[a] >=32)
	{
		a++;
		k++;
	}

	char *C = new char[k];

	for (int i = 0; i < k; ++i)
	{
		C[i] = A[i];
	}

	int length = j + k;

	A = new char[length];

	for (int i = 0; i < length; ++i)
	{
		A[i] = C[i];
	}
	
	for (int i = 0; i < j; ++i)
	{
		A[i + k] = B[i];
	}
	/*
	//commenting out the output test"
	for (int i = 0; i < 10; i++)
	{
		cout<<A[i];
	}
	*/
}

int stringPosition(char *A, char B)
{
	int i = 0;
	int sizelol = 0;
	while (A[i] >= 32)
	{
		i++;
		sizelol++;
	}
	//cout << "i " << i << endl;
	//cout << "size " << sizelol << endl;
	
	for (int i = 0; i < sizelol+1; ++i) {
		if (A[i] == B) return i;
		//cout << A[i] << endl;
	}
	return -1;
}

int stringLength(char *A)
{
	int i = 0;
	int j = 0;
	while (A[i] != '\0')
	{
		i++;
		j++;
	}

	for (int k = 1; k < j + 1; k++)
	{
		for (int i = 0; i < j; i++)
		{
			A[i] = A[k];
		}
	}
	A[0] = j;
	return A[0];
}

int main()
{
	int MAX_SIZE = 22;
	char* lineArray = new char[MAX_SIZE];
	char* A = new char[11];
	char* B = new char[11];
	char* C = new char[11];
	char* D = new char[11];
	char* E = new char[11];
	char* F = new char[11];
	char* G = new char[11];
	char* H = new char[11];
	char* I = new char[11];
	
	int i = 0;
	FILE *pfile;
	FILE *pfile2;
	pfile = fopen("in.txt", "r");
	fscanf(pfile, "%s", A);
	fscanf(pfile, "%s", B);
	fscanf(pfile, "%s", C);
	fscanf(pfile, "%s", D);
	fscanf(pfile, "%s", E);
	fscanf(pfile, "%s", F);
	fscanf(pfile, "%s", G);
	fscanf(pfile, "%s", H);
	fscanf(pfile, "%s", I);
	
	fclose(pfile);

	//open file
	pfile2 = fopen("output.txt", "w");
	//print to file (not working)

	
	//cout<<"stringcompare of Good and Good " <<myVal <<endl;
	stringConcatenation(E,F);
	int myPos = stringPosition(G,'m');
	//cout << "string position of m in Salaam " << myPos <<endl;
	int myStrlen = stringLength(I);
	
	///print after the function call
	fprintf(pfile2, "%s", "\n printing standard array \n");
	
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", A);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", B);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", C);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", D);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", E);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", F);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", G);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", H);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", I);
	///------------
		//string copy first, reprint arrays (working)
	stringCopy(A, B);
	fprintf(pfile2, "%s", "\n printing result of strcpy on Hello and Hi \n");
	for(int i = 0; i < 10; i++){
	  fprintf(pfile2,"%s", &A[i]);
	}
	fprintf(pfile2, "%s", "\n");
	for(int i = 0; i < 10; i++){
	  fprintf(pfile2,"%s", &B[i]);
	}
		///print after the function call
	fprintf(pfile2, "%s", "\n printing the arrays after the previousfunction call \n");
	
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", A);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", B);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", C);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", D);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", E);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", F);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", G);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", H);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", I);
	///------------
	bool myVal = stringCompare(D,E);
	fprintf(pfile2, "%s", "\nstringCompare of Good and Good ");
	fprintf(pfile2, "%d", myVal);
	///print after the function call
	fprintf(pfile2, "%s", "\n printing the arrays after the previousfunction call \n");
	
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", A);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", B);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", C);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", D);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", E);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", F);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", G);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", H);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", I);
	///------------
	
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2, "%s", "\nstringPosition of m in Salaam ");
	fprintf(pfile2, "%d", myPos);
		///print after the function call
	fprintf(pfile2, "%s", "\n printing the arrays after the previousfunction call \n");
	
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", A);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", B);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", C);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", D);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", E);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", F);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", G);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", H);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", I);
	///------------

	fprintf(pfile2, "%s", "\nstringLenth of 'Bonjour' for this case ");
	fprintf(pfile2,"%d", myStrlen);
		///print after the function call
	fprintf(pfile2, "%s", "\n printing the arrays after the previousfunction call \n");
	
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", A);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", B);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", C);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", D);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", E);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", F);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", G);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", H);
	fprintf(pfile2, "%s", "\n");
	fprintf(pfile2,"%s", I);
	///------------

	fclose(pfile2);
	for(int i=0; i < 10; i++)
	{
	  cout<<E[i];
	}
}
