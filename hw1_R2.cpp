#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream in;
//ostream out;

struct scoreN
{
	int score;
	scoreN* next;
};

struct node
{
	string data;
	struct node *next;
	struct node* prev;
	struct scoreN* singleLL;
};

void buildList(FILE *in,string data,struct node *&head,struct node *&tail,int &i){  
     
    head = (node *)malloc(sizeof(node));
    fscanf(in,"%s",data);
    strcpy(head->data,data);
    tail=head;
    head->next = NULL;
    
        while(fscanf(in,"%s",data) != EOF){      
            struct node *current = head; //make a pointer to a new struct and =head
            while(current->next != NULL){//while there's still another current
                current = current->next;//link the list
            }
            
            current->next = (node *)malloc(sizeof(node));//allocate space for each node
            current->next->prev = current;
         	current = current->next;
          	current->data = data;
          	current->next = NULL;
          	i++;    
        }

     
}



void traverse()
{

}

void deleteStudent(string name, struct node*& head, struct node*& tail)
{
	struct node* temp = head;
	while(temp->data != name)
	{
		temp->next =temp;
		
	}

}

void ascend()
{

}

void descend()
{

}
 
int main()
{
	

	return 0;
}