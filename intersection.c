#include<stdio.h>
#include"linkedList.h"


int main(void)
{
    
    struct Node *head_A = (struct Node*)0;
    
    for(int i = 0; i< 10; i++){
        head_A = addTail(head_A, i);
    }
    
    print(head_A);
    
    return 0;
    
}