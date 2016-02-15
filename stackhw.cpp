#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data[20];
	int top;
}stack;

bool isFullStack(stack *myStack)
{
	if(myStack->top==19)
		return true;
	else return false;

}

bool isEmptyStack(stack *myStack)
{
	if(myStack->top == -1)
		return true;
	else return false;
}

void pop(int popElement, struct *myStack)
{
	popElement=myStack->data[myStack->top];
	myStack->top=myStack->top-1;
	return popElement;
}

void push()