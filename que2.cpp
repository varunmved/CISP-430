#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
/*
Populate a queue with a list of integers (both positive and negative) from a file (input.txt). 
Write an algorithm that deletes all negative integers without changing the order of the remaining elements.  

Duplicates are allowed.
 Do not use a counter to keep track of the number of items in the queue. 
Do not create any other data structures such as stacks, other queues, linked lists or arrays. 
You can only use the enqueue and dequeue functions when modifying the queue. 
Display the results on the screen by using a traverse function. 



*/
struct node {
     int item;
     node *next;          
};

//add
void enqueue(int item, struct node *&front, struct node*&rear){
    struct node *newNode=new node;
   
    newNode->item=item;
    newNode->next=NULL;  
    if (rear){          
rear ->next=newNode;  
      rear =newNode;        
   }else
        front = rear =newNode;   
}

//remove
void dequeue(struct node *& front, struct node *& rear){
    struct node *temp;

    if(front){  
        temp= front;  
        front = front->next;  
        delete temp;
    }
    /*

    */
    
    if (!front)            
       rear =NULL;
}


int main(){
    FILE *in1, *out;
    in1 = fopen("input.txt","r");
    int *data;
    struct node *front1;
    struct node *rear1;
    while(fscanf(in1,"%d",data) != EOF)
    {
        if(data >0) enqueue(*data, front1, rear1);
    }
    

}