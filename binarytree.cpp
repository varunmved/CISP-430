#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodeTree {
    int key;
    nodeTree *left;
    nodeTree *right;
};

nodeTree * newNode(int value){
    nodeTree *node=new nodeTree;
    node->key=value;
    node->left=NULL;
    node->right=NULL;
    return (node);
}

//search
bool searchNoRecursion(nodeTree *leaf, int key){
    bool found=false;
    
    //use a while loop and not recursion. Leaf is being changed
    //each and every time to point to the left or right, going down
    //the tree.
    while (leaf!=NULL && !found){ 
        if (key==leaf->key){
            found=true;
        }else if (key < leaf->key)
            leaf=leaf->left; //replaces recursion
        else
            leaf=leaf->right;
    }
    return found;
}

//insert
nodeTree * insertNoRecursion(nodeTree *leaf, int key){
    bool foundSpot=false;
    
    while (leaf!=NULL && !foundSpot){
        if (key==leaf->key)
            leaf=NULL;           //no need to insert
        //If it is smaller, then go to the left
        else if (key < leaf->key)
            if (leaf->left !=NULL)
                leaf=leaf->left;
            else 
                foundSpot=true;
        else{
            if (leaf->right!=NULL)
                leaf=leaf->right;
            else 
                foundSpot=true;
        }
    }
    return leaf;
}


//del
void deleteNode (nodeTree *leaf, int delVal)
{

}




int main( ){
    struct nodeTree *root;
    
    FILE *in1, *out;
    in1=fopen("input.txt", "r");
    int data;
    int delVal=1;
    while(true)
    {
        searchNoRecursion(root, data);
        insertNoRecursion(root,data);
        if (searchNoRecursion==false)
        {
            deleteNode (root, delVal);

        }
    }


    //node *left1;
    //node *right1;
    
    root=NULL;
/*
    while(in.good())
    {
        in1>> data;
        
    }
    */

    
}

