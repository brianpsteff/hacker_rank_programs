#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10

void insertionSort(int myNumbers[], int size);

int main(void){
	
	srand(time(NULL));
	int nums[ARRAY_SIZE];

	for(int i = 0; i<ARRAY_SIZE; i++){
		int r = rand()%20;
		nums[i] = r;
	}

	insertionSort(nums, 11);
	for(int i = 0; i<10; i++){
		printf("%i, ", nums[i])
	}
	
}

void insertionSort(int myNumbers[], int size)
{
	for(int i = 1; i< size -1; i++){					//size -1 because the array is one cell larger than the actual amount of numbers.
		int element = myNumbers[i];
		int index = i;
		while(index > 0 && myNumbers[index-1]>element){
			myNumbers[index] = myNumbers[index-1];
			index = index -1;
			myNumbers[index] = element;
		}
	}
}