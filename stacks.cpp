/*
while (int != 0)
{

if(int mod 2 == 0)
	i = 1;
	pushback(i);

else 
{
	i = 0;
	pushback(i);
}


#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data[20];
	int front;
}
*/

#include <stdio.h>
#include <iostream>
//#include <conio.h>
//#include <process.h>
#define MAX 10
using namespace std;

typedef struct stack
{
 int data[MAX];
 int top;
}stack;
//---------------------
int empty(stack *s)
{
 if(s->top==-1)
      return(1);
 return(0);
}
//----------------------
int full(stack *s)
{
 if(s->top==MAX-1)
     return(1);
 return(0);
}
//-----------------------
void push(stack *s,int x)
{
 s->top=s->top+1;
 s->data[s->top]=x;
}
//-----------------------
int pop(stack *s)
{
 int x;
 x=s->data[s->top];
 s->top=s->top-1;
 return(x);
}
//------------------------
int main()
{
 stack s;
 int num;

 s.top=-1;
     printf("Enter number: ");
     //scanf("%d",&num);
     cin >> num;

     while((num!=0))
     {
       
          push(&s,num%2);
          num=num/2;
     }

    printf("n");
    while(!empty(&s))
       {
       num=pop(&s);
       printf("%d",num);
       }
     return 1;


}