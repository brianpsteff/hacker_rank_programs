/*
 * This program detects whether or not a linked list contains a cycle.
 */



#include <stdio.h>
#include <linkedList.h>

int HasCycle(struct Node* head);

int main(void)
{
    
    struct Node *head = (struct Node*)0;
    
    for(int i = 0; i<10; i++){
        head = addTail(head, i);
    }

    print(head);
    
    int x = HasCycle(head);
    printf("%i\n", x);
    
    return 0;

}

int HasCycle(struct Node* head)
{
    // Complete this function
    // Do not write the main method
    
    //Account for an empty list
    if(head == (struct Node*)0){
        return 0;
    }
    
    struct Node *tmp = head;
    //Declare an array of pointers
    struct Node* pointers[50];
    int currentIndex = 0;
    int ValuesInArray =1;
    pointers[0] = head;
    
    //Iterate through the list
    for(    ; tmp -> next != (struct Node*)0; tmp = tmp->next)
    {
        for(int i = 1; i<ValuesInArray; i++){
            if(tmp == pointers[i])
                return 1;
        }
        currentIndex++;
        pointers[currentIndex] = tmp;
    }
    
    
    /*If for loop completes then there are no cylces in list*/
    return 0;
    
}