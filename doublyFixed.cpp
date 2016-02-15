#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};
/*
void deleteBeg(int delBeg, struct node*&head,  struct node *&tail);
void adjust(struct node *current, struct node *&head, struct node *&tail);
void insertEnd(int item, struct node*&head, struct node *&tail);
void deleteEnd(int delBeg, struct node*&head,  struct node *&tail);
void traverse(FILE *out,struct node *head, struct node *tail);

 */

//newNode will be at the tail end, so tail will have to be set
void insertEnd(int item, struct node*&head, struct node *&tail)
{
	node * newNode;
	//create node
	newNode = new node;
	newNode-> data = item;
	newNode -> next = NULL;

	if(!head)
	{
		newNode->prev=NULL;
		head = newNode;
	}
	else
	{
	//something in list
		newNode->prev=tail;
		tail->next=newNode;
	}
	tail=newNode; ////make it a new node
}

void adjust(struct node *current, struct node *&head, struct node *&tail)
{
	if(current ->prev != NULL)	//if it is not in the head
		current->prev->next = current->next; //point he next before this node to one after
	else head=current->next; //make the next one head

	if(current ->next != NULL)	//if it is not in the tail
		current->next->prev = current->prev; //make the next one point to the previous one
	else tail=current->prev; //change the tail of the node that needs to be displayed

	delete current;
}


void deleteBeg(int delBeg, struct node*&head,  struct node *&tail)
{
	struct node*current=head;

	while(--delBeg >0) //if 0 then we have landed on teh delete node
	{
			current=current->next; // go to node that needs to be deleted
			if(current==NULL) //if delbeg is invalid and we go outisdie we get out
			break;

	}
	if(current!=NULL) //if delbeg is 0 coming into the function or invalid //is it set to some value
		adjust(current,head,tail); //current has node that needs to be deleted

			

}

void deleteEnd(int delBeg, struct node*&head,  struct node *&tail)
{
	struct node*current=tail;

	while(--delBeg >0) //if 0 then we have landed on teh delete node
	{
			current=current->prev; // go to node that needs to be deleted
			if(current==NULL) //if delbeg is invalid and we go outisdie we get out
			break;

	}
	if(current!=NULL) //if delbeg is 0 coming into the function or invalid //is it set to some value
		adjust(current,head,tail); //current has node that needs to be deleted

}

void traverse(FILE *out,struct node *head, struct node *tail){
    
    struct node *current = head;
    while (current != NULL){
        fprintf(out,"%d\n",current->data);
        current = current->next;
    }
    struct node *current1 = tail;
    while (current1 != NULL){
        fprintf(out,"%d\n",current1->data);
        current1 = current1->prev;
    }

    fprintf(out,"\n\n\n");
}

int main()
{
	struct node *head, *tail, *current =NULL;
	int begHeadDel = 0;
    int endTailDel = 0;

	FILE  *out1;
    //in1 = fopen("input.txt","r");
    out1 = fopen("output.txt","w");
    ifstream in_stream;
    in_stream.open("input.txt");
    int data;

	//file read
	while(in_stream.good())
	{
		
		insertEnd(data,head,tail); //insert at the end
	}
	in_stream.close();
	//asking user
	cout << "which item do you want to delete from the beginning? ";
    cin >> begHeadDel;
    if(begHeadDel < 0)
    {
        cerr<< "sorry, that's not valid";
    }

    cout << endl << "which iteam do you want to delete from the end? ";
    cin >> endTailDel;

    deleteBeg(begHeadDel,head,tail);
    deleteEnd(endTailDel,head,tail);
    traverse(out1,head,tail); 
    return 0;
}