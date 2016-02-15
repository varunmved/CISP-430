#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node{
    char data[10];
    node *next;
    node *prev;
    struct scores;
};

struct scoresN{
	int score;
	node *next;
};

struct node* buildList(FILE *in,char *data,struct node *&head,struct node *&tail, struct scoresN *&head,int &i){  
     
    head = (node *)malloc(sizeof(node));
    fscanf(in,"%s",data);
    strcpy(head->data,data);
    tail=head;
    head->next = NULL;
    
        while(fscanf(in,"%s",data) != "end"){      
            struct node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            
            current->next = (node *)malloc(sizeof(node));
            current->next->prev = current;
         	current = current->next;
          	current->data = data;
          	current->next = NULL;
          	i++;    
        }
     
}

struct node* split(struct node *head,int i){
    
    struct node *listTwo;
    for(int e = 1; e < i/2; e++){
        head = head->next;
    }
    listTwo = head->next;
    head->next = NULL;
     
    return listTwo;
}

struct node* merge(struct node *head1,struct node *&head2){
    
    struct node *current = head1;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = head2;
    head2 = NULL;
}

void traverse(FILE *out,struct node *head, struct node *tail){
    
    struct node *current = head;
    while (current != NULL){
        fprintf(out,"%s\n",current->data);
        current = current->next;
    }
    struct node *current1 = tail;
    while (current1 != NULL){
        fprintf(out,"%s\n",current1->data);
        current1 = current1->prev;
    }

    fprintf(out,"\n\n\n");
}


