/*
Varun Ved
stack.cpp

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//int stackSize = 20;

struct stack
{	
	int data[50];
	int top;
};

bool isFullStack(struct stack *myStack)
{
	if(myStack->top==49)
		return true;
	else return false;

}

bool isEmptyStack(struct stack *myStack)
{
	if(myStack->top == -1)
		return true;
	else return false;
}

int pop(struct stack *myStack)
{
	int popElement;
	popElement=myStack->data[myStack->top];
	myStack->top=myStack->top-1;
	return popElement;
}

void push(int pushElement, struct stack *myStack)
{
	 myStack->top=myStack->top+1;
 	 myStack->data[myStack->top]=pushElement;
}

int main()
{

	const char* hex_table = "0123456789ABCDEF"; 

	stack myStack;
	stack myStack2;
	
	int input = 0;
	myStack.top=-1;
	cout << "enter a number: ";
	cin >> input;
	//input =16;
	int hexVal = input;
	int n,number,rem2;
	number = input;


	while(input!=0)
	{
		push(input%2,&myStack);
		input = input/2;
	}
	
	while(isEmptyStack(&myStack)!=true)
	{
		input=pop(&myStack);
		cout << input;
	//cout << endl;
	}
	cout << endl;
	/*
	while (number != 0)
	{
		rem2 = number % 16;
		
		push(rem2,&myStack2);
		if (rem2==10)
		{
			rem2='A';
			rem2=number;
		}
		else if (rem2==11)
		{
			rem2='B';
			rem2=number;
		}
		else if (rem2==12)
		{
			rem2='C';
			rem2=number;
		}
		else if (rem2==13)
		{
			rem2='D';
			rem2=number;
		}
		else if (rem2==14)
		{
			rem2='E';
			rem2=number;
		}
		else if (rem2==15)
		{
			rem2='F';
			rem2=number;
		}
		number /= 16;
	}
	
	//cout << "Base 16 representation of " << n << " is ";
	while (isEmptyStack(&myStack2)!=true)
	{
		pop(&myStack2);
		cout << rem2;
	}
	cout << endl;
	*/
	printf("%X",number);
	//return 0;

}