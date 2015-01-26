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
#define MAX_STRING_LENGTH 1002

typedef struct {
	char c_value;
	bool found;
} letter;						

/*FUNCTION PROTOTYPES*/
int read_string(letter* my_alphabet[], char* my_string);
void print_structure(letter* my_letter);
int evaluate_letter(letter* my_letter, int count);

int main(void)
{
	
	letter alphabet[LETTERS_IN_ALPHABET];
	/* initialize the alphabet as an organized structure */
	for(int i = 0, c = 'a'; i < LETTERS_IN_ALPHABET; i++, c++)
	{
		alphabet[i].c_value = c;
		alphabet[i].found = false;
	}
	
	for(int i = 0; i< 26; i++)
	{
		print_structure(&alphabet[i]);
	}

	int letter_count = 0, i = 0;
	char current_char;
	char my_string[MAX_STRING_LENGTH];	

	/*load the string from StdIN*/
	while((scanf("%c", &current_char) > 0))
	{
		if(current_char != ' ')
		{
			if(isupper(current_char))
				current_char = tolower(current_char);
			my_string[i] = current_char;
			i++;
		}
		
	}

	int string_length = i+1;

	printf("String loaded from STDIN:\n\n%s\nlength:\t%d\n", my_string, string_length);
	
	for(int j = 0; i<string_length; j++){
		int index = my_string[j] - 'a';
		letter_count = evaluate_letter(&alphabet[index], letter_count);
		print_structure(&alphabet[index]);
		printf("The current count is: %d\n", letter_count);	/*Should be incrementing*/
	}

	
	switch(letter_count){
		case 26:
			printf("panagram\n");
			break;
		default:
			printf("not panagram\n");
			break;
	}
	

	return 0;
}

/*evaluate_letter:	If necessary changes the boolean value of the lettr structure passed into the
			function argunebt abd returns an updated count.
			*/
int evaluate_letter(letter* my_letter, int count)
{
	if(my_letter->found == false)
	{
		my_letter->found = true;
		count++;
	}
	return count;
}


void print_structure(letter* my_letter)
{
	char my_char = my_letter -> c_value;
	char* boolean_val = "false";
	if(my_letter -> found == true)
		boolean_val = "true";

	printf("%c\t::\t%s\n", my_char, boolean_val);
}

