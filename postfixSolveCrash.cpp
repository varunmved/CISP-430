#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
//# define MAX 20
//using namespace std;

void infixtoprefix(char infix[20],char prefix[20]);
void reverse(char array[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(char symbol);
int solve(char prefix[20]);
void toHex(int intSolve);
int top=-1;
char stack[20];
int s[20];
int main() {
	char infix[20],prefix[20],temp;
	//FILE *in1;
	//in1= fopen("input.txt","r");
	//fscanf(in1,"%s",infix);
	//fclose(in1);
	std::cout << "infix?";
	std::cin >> infix;
	infixtoprefix(infix,prefix);
	reverse(prefix);
	//puts((prefix));
	int intSolve=solve(prefix);
	toHex(intSolve);

}
//--------------------------------------------------------
void infixtoprefix(char infix[20],char prefix[20]) {
	int i,j=0;
	int top =-1;
	char symbol;
	stack[++top]='#';
	reverse(infix);
	for (i=0;i<strlen(infix);i++) {
		symbol=infix[i];
		if (isOperator(symbol)==0) {
			prefix[j]=symbol;
			j++;
		} else {
			if (symbol==')') {
				push(symbol);
			} else if(symbol == '(') {
				while (stack[top]!=')') {
					prefix[j]=pop();
					j++;
				}
				pop();
			} else {
				if (prcd(stack[top])<=prcd(symbol)) {
					push(symbol);
				} else {
					while(prcd(stack[top])>=prcd(symbol)) {
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
				//end for else
			}
		}
		//end for else
	}
	//end for for
	while (stack[top]!='#') {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}
////--------------------------------------------------------

void reverse(char array[30]) // for reverse of the given expression 
{
	int temp, i;
	int count = strlen(array);
  for (i = 0; i < count/2; ++i) {
    temp = array[count-i-1];
    array[count-i-1] = array[i];
    array[i] = temp;
}
}

//--------------------------------
char pop() {
	//int top=-1;
	char a;
	a=stack[top];
	top--;
	return a;
}
//----------------------------------
void push(char symbol) {
	//int top =-1;
	top++;
	stack[top]=symbol;
}
void push1(int elem)
{                       /* Function for PUSH operation */
 s[++top]=elem;
}
 
int pop1()
{                      /* Function for POP operation */
 return(s[top--]);
}
//------------------------------------------
int prcd(char symbol) // returns the value that helps in the precedence 
{
	switch(symbol) {
		case '+':
		case '-':
			return 2;
		break;
		case '*':
		case '/':
			return 4;
		break;
		case '(':
		case ')':
			return 1;
		break;
		default: return 0;
	}
}
//-------------------------------------------------
int isOperator(char symbol) {
	switch(symbol) {
				case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '(':
		        case ')':
		        return 1;
		break;
		default:
		        return 0;
		// returns 0 if the symbol is other than given above
	}
}


int solve(char prefix[20])
{
 //int s[20];
 //int top=-1; 
 int i=0,op1,op2;
 char ch;
 while( (ch=prefix[i++]) != '\0')
 {
  if(isdigit(ch)) 
  	push1(ch-'0'); /* Push the operand */
  else
  {        /* Operator,pop two  operands */
   op2=pop1();
   op1=pop1();
   switch(ch)
   {
   case '+':
   	push1(op1+op2);
   	break;
   case '-':
   	push1(op1-op2);
  	break;
   case '*':
   	push1(op1*op2);
   	break;
   case '/':
   	push1(op1/op2);
   	break;
   }
  }
 }
 	int intSolve=s[top];
 	return intSolve;

}

void toHex(int intSolve)
{
	printf("%d",intSolve);
}