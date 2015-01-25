/* PROBLEM DESCRIPTION
 *
 *	James found a love letter his friend Harry has written for his girlfirend. James is a prankster,
 *	so he decides to meddle with the letter. He changes all the words in the letter into palindromes.
 *
 *
 *	2 RULES FOLLOWED:
 *		-	he can reduce the value of a letter, e.g. he can change 'd' to 'c', but he cannot change 'c' to 'd'.
 *		-	In order to forma palindrome, if he has to repeatedly reuce the value of a letter, hfe can do it until the 
 *			letter becomes 'a'. ONce a letter has been changed to 'a', it can no longer be changed.
 *
 *	Each reduction in the value of any letter is counted as a single operation. 
 *
 *	FIND THE MINIIMUM NUMBER OF OPERATIONS REQUIRED TO CONVERT A GIVEN STRING INTO A PALINDROME.


*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	if(argc < 2){
		printf("Incorrect input format.\n");
	} else {
		for(int i  = 0; i < argc; i++)
			printf("\n%s\n", argv[i]);
	}






	return 0;

}
