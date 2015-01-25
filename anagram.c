/*
Your challenge is to help him find the minimum number of characters that 
need to be changed to make the first string an anagram of the second string. 
He can neither add a character nor delete a character from the first string. 
Only replacement of the original characters with the new ones is allowed.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLENGTH 1000        //Maximum Length of an input string
#define MAXINPUT 100              //Maximum number of input strings



/*FUNCTION PROTOTYPES*/

void copyFile(FILE *in, FILE *out);
int analyzeAnagram(char* myString);
_Bool getLine(FILE *in, char* myString);



int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("\nMust include input file name and export file name\nat the command line.\n");
		return 1;
	}


	//Load Necessary Files.
	char* input_file = argv[1];
	char* output_file = argv[2];
	FILE* in_file;
	FILE* out_file;
	in_file = fopen(input_file, "r");
	out_file = fopen(output_file, "w");	//'w' flag for writing to file.
	
	//Retrieve the first line of the input file to determine the number of test cases.
	char currentLine[MAXLENGTH];
	char numberOfInputs[10];
	getLine(in_file, numberOfInputs);
	printf("\nThere are %s inputs to be analyzed\n", numberOfInputs);
	while(getLine(in_file, currentLine))
	{
		int size = strlen(currentLine);
		int value = analyzeAnagram(currentLine);
		printf("\n(%d\t|\t%d)\t%s\n", size, value, currentLine);
		memset(currentLine, 0, MAXLENGTH);						/* This programming logic
														tells us that a cell with 0 in it is empty */

	}

	

	fclose(in_file);
	fclose(out_file);

	return 0;
}


/*Function used to get a single line from the input file, not including new line character*/
_Bool getLine(FILE *in, char* myString)
{
	int i;
	char c;
	for(i = 0; ((c = getc(in)) != '\n') && (c != EOF); i++)
		myString[i] = c;

	if( c == EOF)
		return false;
	else
		return true;
}

int analyzeAnagram(char* myString)
{	
	if(strlen(myString)%2 == 1)
		return 0;
	else 
		return 1;



}


