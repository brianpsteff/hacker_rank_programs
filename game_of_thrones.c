/*This program is used to test whether a string read from STDIN has a palindrome permutation.
	If the string has a length of even int then each letter must have an even number of occurences.
	In the other situation, there can be one letter with an odd number of occurences.
	*/

/*SUGGESTED SOLUTION APPROACH BY HACKER RANK MODERATOR*/
/*Use a simpler logic,

try to maintain a hash of all the characters and increase its count as and when you see it. 
Then based on the size of the string, you can check whether the anagram forms a 
palindrome or not. 

PERSONAL APPROACH													*
  *	Build a binary search tree structure w/ characters in string read from STDIN	*
  *	Do not implement a sorting algorithm. 							*

QUESTIONS
	- I should probably learn more about hashes and hash tables/
	- Is there a C library that I can download to make hashing easier?
	- Is there a way to read a single character at a time from STDIN? "%c" perhaps
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


typedef struct tree_Node{
	char letter;
	int count;
	struct tree_Node* left_child;			/*pointer to structure of same type*/
	struct tree_Node* right_child;			/*NOTE: astericks comes after name of stuct
								    rather than after the word "struct"*/
} letter;


/*FUNCTION PROTOTYPES****************************************************/
int node_compare(char c1, letter* node);
bool palindrome_permutable(char* string);
void print_node(letter* my_letter);
void print_tree(letter* head);
/*************************************************************************/



int main(void)
{
	letter a = {'a', 2, NULL, NULL};
	struct tree_Node b; 
	print_node(&a);
	char current;
	while(!(current=='\n' || current==EOF))
	{
		printf("%c\n ", current);
		scanf("%c", &current);
		
	}





	return 0;
}

void print_node(letter* my_letter)
{
	char value = my_letter -> letter;
	int occurences = my_letter -> count;
	printf("The letter %c occures %d in the input string\n", value, occurences);
}

void print_tree(letter* head)
{

}



/* palindrome_permutable:	returns true if string can be rearanged to form a palindrome*/
bool palindrome_permutable(char* string)
{
	return false;
}



/* node_compare: 	determines whether a character is less than, greater than or equall
				to the character member of structure pointer in the argment. can return 
				{-1, 0, 1}
*/
int node_compare(char c1, letter* node)
{
	int direction;
	char c2 = node->letter;
	if((c2 - c1) == 0)
		direction = 0;
	else if ((c2-c1) >0)
		direction = -1;
	else
		direction = 1;
	return direction;
}



