/* A Panagram is a string that has at least one instance of every letter in the english alphabet*/

/* NOTE:	I will not need to bother with a binary search function, because I can easily 
		use ASCII Aritmetic to directly asccess the appropriate location in the 
		alphabet struct array
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <regex.h>

#define MAX_STRING_LENGTH 10e3

struct letter {
	char c_value;
	bool found;
} alphabet[26];						/*initialize an array of struct letters*/


int main(void)
{
	
	/* initialize the alphabet as an organized structure */
	for(int i = 0, c = 'a'; i < 26; i++, c++)
	{
		alphabet[i].c_value = c;
		alphabet[i].found = false;
	}

	int letter_count = 0;
	char current_char;
	char my_string[MAX_STRING_LENGTH];	
	/*load the string from StdIN, one character at a time*/\
	for(int i = 0; !(current_char == '\n' || current_char == EOF); i++)
	{
		scanf("%c", &current_char);
		while(current_char == ' ')		/*Skip SPaces*/
			scanf("%c", &current_char);
		


	}

	switch(letter_count){
		case 26:
			printf("panagram\n");
		default:
			printf("not panagram\n");
	}

	return 0;
}


