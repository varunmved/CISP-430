#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct myQueue
{
	char item;
	myQueue *next;
	
}mq;

//add
void enque(char item, mq *&front, mq *&rear)
{
	mq *newQ = new mq;

	newQ->item=item;
	newQ->next =NULL;
	if(rear)
	{
	  rear->next=newQ;
	  rear=newQ;
	}
	else front=rear=newQ;
}

//remove
char dequeue(mq *&front, mq *& rear)
{
	mq *temp;
	if(front)
	{
	  temp = front;
	  front = front->next;
	  delete temp;
	}
	if(!front)
	{
		rear=NULL;
	}
	return item;
}
void process(mq *&front, mq *&rear)
{
	char data;
	data=dequeue(front,rear);
	if(data!=')'); /*in the last program
	he used this except data > 0, so i'm assuming
	i have to adapt it for the postfix order*/
	enque(data,front,rear);
}

const char * toHex(string postfix)
{


}

int main()
{
	FILE *in1, *out;
	in1=fopen("input.txt", "r");
	char data;
	mq *front1;
	mq *rear1;
	mq *end;
	front=rear=NULL;

	while(in.good())
	{
		in>> data;
		enque(data,front,rear);
	}

	//traverse(front);

	end=rear;
	if(front)
	{
		while(front!=end)
			process(front,rear);
		process(front,rear);
	}
	//xtraverse(front);
	cin >> data;
}

void algorithimlol()
{
	
}