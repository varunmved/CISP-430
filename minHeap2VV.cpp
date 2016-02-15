#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>


using namespace std;

//minheap
int heap[10],heapSize;

void Init()
{
        heapSize = 0;
        heap[0] = -INT_MAX;
}


/*Insert an element into the heap */
void Insert(int element)
{
        heapSize++;
        heap[heapSize] = element; /*Insert in the last place*/
        /*Adjust its position*/
        int now = heapSize;
        while(heap[now/2] > element) 
        {
                heap[now] = heap[now/2];
                now /= 2;
        }
        heap[now] = element;
}

int DeleteMin()
{
                int minElement,lastElement,child,now;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        /* now refers to the index at which we are now */
        for(now = 1; now*2 <= heapSize ;now = child)
        {
            if(lastElement==1)
                cout <<child <<endl;
              
                child = now*2;
                
                if(child != heapSize && heap[child+1] < heap[child] ) 
                {
                        child++;
                }
                              if(lastElement > heap[child])
                {
                        heap[now] = heap[child];
                }
                else /* It fits there */
                {
                        break;
                }
        }
        heap[now] = lastElement;
        return minElement;

}

int main()
{
        int number_of_elements=10;
        int iter, element;
        Init();
        ifstream inFile;
        inFile.open("input.txt"); 
        if (!inFile) {
            cout << "Unable to open text file";
        }

        while (inFile >> element) {
       
                Insert(element);

        }
        for(iter = 0;iter < 5;iter++)
        {
                printf("%d ",DeleteMin());
        }
        printf("\n");
        return 0;
}