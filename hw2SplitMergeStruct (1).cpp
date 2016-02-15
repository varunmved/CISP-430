#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node{
    char data[15];
    node *next;
};

struct node *listOne = NULL;
struct node *listTwo;
struct node *listThree = NULL;
struct node *listFour = NULL;
int i = 1;



struct node* buildList(FILE *in,char *data,struct node *&head,int &i,char test);
struct node* split(struct node *head,int i);
struct node* merge(struct node *head1,struct node *&head2);
void traverse(FILE *out,struct node *head);



int main(){
    FILE *in1, *in2, *out1, *out2;
    in1 = fopen("inputSplit.txt","r");
    in2 = fopen("inputMerge.txt","r");
    out1 = fopen("outputSplit.txt","w");
    out2 = fopen("outputMerge.txt","w");
    char data[15];
    
    
    buildList(in1,data,listOne,i,'y');
    buildList(in2,data,listThree,i,'n');
    buildList(in2,data,listFour,i,'n');
    
    listTwo = split(listOne,i);
    merge(listThree,listFour);
    
    traverse(out1,listOne);
    traverse(out1,listTwo);
    traverse(out2,listThree);

  
    fclose(in1);
    fclose(in2);
    fclose(out1);
    fclose(out2);
    
    free(listOne);
    free(listTwo);
    free(listThree);
    free(listFour);
}



struct node* buildList(FILE *in,char *data,struct node *&head,int &i,char test){  
     
    head = (node *)malloc(sizeof(node));
    fscanf(in,"%s",data);
    strcpy(head->data,data);
    head->next = NULL;
    
    if(test == 'y'){
        while(fscanf(in,"%s",data) != EOF){      
            struct node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            
            current->next = (node *)malloc(sizeof(node));
            current = current->next;
            strcpy(current->data, data);
            current->next = NULL;
            i++;      
        }
    }
    else{      
        for(int i=1; i<5;i++){
            struct node *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = (node *)malloc(sizeof(node));
            current = current->next;
            fscanf(in,"%s",data);
            strcpy(current->data, data);
            current->next = NULL;
        }
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

void traverse(FILE *out,struct node *head){
    
    struct node *current = head;
    while (current != NULL){
        fprintf(out,"%s\n",current->data);
        current = current->next;
    }
    fprintf(out,"\n\n\n");
}
