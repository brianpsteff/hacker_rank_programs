/* A Panagram is a string that has at least one instance of every letter in the english alphabet*/

/* NOTE:	I will not need to bother with a binary search function, because I can easily 
		use ASCII Aritmetic to directly asccess the appropriate location in the 
		alphabet struct array
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LETTERS_IN_ALPHABET 26
#define MAX_STRING_LENGTH 1000

typedef struct {
	char c_value;
	bool found;
} letter;						

/*FUNCTION PROTOTYPES*/
int read_string(letter* my_alphabet[], char* my_string);

int main(void)
{
	
	letter alphabet[LETTERS_IN_ALPHABET];
	/* initialize the alphabet as an organized structure */
	for(int i = 0, c = 'a'; i < LETTERS_IN_ALPHABET; i++, c++)
	{
		alphabet[i].c_value = c;
		alphabet[i].found = false;
	}

	int letter_count;
	char current_char;
	char my_string[MAX_STRING_LENGTH];	
	/*load the string from StdIN, one character at a time*/\
	for(int i = 0; !(current_char == '\n' || current_char == EOF); i++)
	{
		scanf("%c", &current_char);
		while(current_char == ' ')		/*Skip Spaces*/
			scanf("%c", &current_char);
		if(current_char == '\n' || current_char == EOF)
			break;
		else if(!islower(current_char))
			current_char = tolower(current_char);

		my_string[i] = current_char;
	}

	printf("String loaded from STDIN:\n\n%s\n", my_string);
	printf("\n%d\n", strlen(my_string));
	letter_count = read_string(alphabet, my_string);

	switch(letter_count){
		case 26:
			printf("panagram\n");
		default:
			printf("not panagram\n");
	}

	return 0;
}

/*read_string:	takes a pointer to an array of letter structures, and a pointer to a char
		array as arguments. tests each letter in string against structures in array.
		Returns a count of structs who's member 'found' == true.
		If returned int is equal to 26 then the string is indeed a panagram.
*/	
int read_string(letter* my_alphabet[], char* my_string)
{	
	int count;
	char current_char;
	for(int i = 0; my_string[i] != '\0'; i++)
	{
		current_char = my_string[i];
		if(my_alphabet[current_char - 'a'] -> found == false)
		{
			count++;
			my_alphabet[current_char - 'a'] -> found = true;
		}
	}
	return count;
}

/* Funciton specific Function prototype*/
void print_structure(letter* my_letter);

void print_structure_array(letter* my_alphabet[])
{

}

void print_structure(letter* my_letter)
{
	char my_char = my_letter -> c_value;
	char* boolean_val = "false";
	if(my_letter -> found == true)
		boolean_val = "true";

	printf()
}

