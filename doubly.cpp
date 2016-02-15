/*Varun Ved
* double linked list excercise
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

struct node *listOne = NULL;
struct node *listTwo=NULL;
int i = 1;
/*
void buildList(FILE *in,int data,struct node *&head, struct node *& tail, int &i);
void headDel(struct node *head,int i);
void tailDel(struct node *tail,int i);
void traverse(FILE *out,struct node *head);

*/
void buildList(FILE *in,int *val,struct node *&head, struct node *& tail, int &i)
{
  cout <<"made it here0";
    head = (node *)malloc(sizeof(node));
    fscanf(in,"%d",val);
    head->data = *val;
    tail=head;
    head->next = NULL;
    cout<<"made it here1";
    while(fscanf(in,"%d",val) != EOF){      
          struct node *current = head;
          while(current->next != NULL){
              current = current->next;
              cout<<"made it here2";
          }
          
          current->next = (node *)malloc(sizeof(node));
          current->next->prev = current;
          current = current->next;
          current->data = *val;
          current->next = NULL;
          i++;      
          cout<<"made it here3";
      }

}

void headDel(struct node *head,int i)
{
   
    struct node *listOne;
    if(i == 1)
    {
        head=NULL;
        head->next=head;
    }
    else
    {
        for(int j=0; j < i; j++)
        {
            head = head -> next;
        }
        
    }
}

void tailDel(struct node *tail,int i)
{
  struct node *listOne;
    if(i == 1)
    {
        tail=NULL;
        tail->next=tail;
    }
    else
    {
        for(int j = 0; j < i; j++)
        {
            tail = tail -> next;
        }
    }
}

void traverse(FILE *out,struct node *head){
    
    struct node *current = head;
    while (current != NULL){
        fprintf(out,"%d\n",current->data);
        current = current->next;
    }
    fprintf(out,"\n\n\n");
}


int main()
{
    int begHeadDel = 0;
    int endTailDel = 0;

    cout << "which item do you want to delete from the beginning? ";
    cin >> begHeadDel;
    if(begHeadDel < 0)
    {
        cerr<< "sorry, that's not valid";
    }

   // cout << endl << "which iteam do you want to delete from the end? ";
    //cin >> endTailDel;


    FILE *in1,  *out1;
    in1 = fopen("input.txt","r");
    out1 = fopen("output.txt","w");
    int* value;

    buildList(in1,value,listOne,listTwo,i);
    cout<<"made it here1";
    headDel(listOne,begHeadDel);
    //tailDel(listOne,endTailDel);
    traverse(out1,listOne);

}