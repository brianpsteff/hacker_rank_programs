#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_LENGTH 20
/*We need a datastructure that allows for easy removal and addition*/
/*let us put the letters into a linked list of characters.*/

typedef struct {
    char type;
    int occurrence;
    struct Gem *next;
} Gem;

//Prototyes

void changeCount(struct Gem* head, char string[]);
struct Gem* edit(struct Gem *head);
struct Gem* addTail(struct Gem *head, char type);
void removeGem(struct Gem *head, int position);


int main(void)
{
    int wordCount;
    scanf("%d", &wordCount);
    
    //Create a linked list of gems from the first word of StdIn.
    //First string cannot exceed 20 characters.
    char string[20];
    scanf("%s\n", string);
    struct Gem *head = (struct Gem*)0;
    
    for(int i = 0; string[i]!=NULL; i++){
        head = addTail(head, string[i]);
    }
    
    for(int j = 1; j<wordCount; j++){           
        char string[20];
        fscanf(gems.txt,"%s\n", string);
        printf("%s\n", string);
        /*changeCount(head, string);
        head = edit(head);*/
    }
    
    
    //Now returning the size of the linked list gives the number of Gems present
    int size = 0;
    for( ; head->next!=(struct Gem*)0; size++)
        head = head->next;
    
    printf("%d\n",size);
    
    
    return 1;
}

/*
 *Method that changes the counts associated with each gem in the linked list
 */

void changeCount(struct Gem* head, char string[])
{
    struct Gem* tmp = head;
    
    while(tmp != (struct Gem*)0){
        char myChar = tmp -> type;
        int count = 0;
        for(int i = 0; string[i] != NULL; i++)
        {
            if(string[i] == myChar){
                count++;
            }
        }
        tmp->occurrence = count;
    }   
}

/*Method iterates through a list to check the count values.
 *if count is equal to 0 then it removes the value.
 *returns a pointer to the head of the newly edited list.
 */
struct Gem* edit(struct Gem *head)
{
    struct Gem* newHead = head;
    struct Gem* iterator = head;
    int index;
    for(index = 0 ; iterator->next=(struct Gem*)0; iterator = iterator->next, index++){
        int count;
        count = iterator->occurrence;
        if(count == 0){
            removeGem(iterator,index);
        }
    }
    return newHead;
}

/*Method from personally authored Linked List Library that adds a node to the end of a linked list.*/

struct Gem* addTail(struct Gem *head, char type)
{
    struct Gem *tmp = head;
    struct Gem *newHead = head;
    struct Gem *newGem = (struct Gem *) malloc(sizeof(struct Gem));
    if (newGem == NULL) {
        printf("malloc failed\n");  /*Allocate space in memory to avoid SegFault*/
        exit(-1);
    }
    
    newGem->type = type;
    newGem->next = (struct Node*)0;
    
    /*Account for empty list*/
    if(tmp == (struct Node*)0){
        newHead = newGem;
    } else {
        /*Increment tmp until end of list is reached*/
        while(tmp->next){
            tmp = tmp->next;
        }
    
        tmp->next = newGem;
    }
    
    return newHead;
}

/*
 *  This method removes a Gem from any spot in the linked List
 */
void removeGem(struct Gem *head, int position)
{
    
    struct Gem *tmp = head;
    
    if(position == 0){
        *head = *head->next;
    } else {
        int count;
        for(count = 1; count<position; count++)
        {
            tmp = tmp->next;
        }
        
        tmp->next = tmp->next->next;
    }
}