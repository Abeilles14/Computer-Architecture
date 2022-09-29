#include "sortoriginal.h"

void sortorig(unsigned long long int *arr, long long int size){
	bubbleSort(arr,size);
	return;
}	



// +++++++++++++++++++ Add your additional function definitions below ++++++++++++++++++++++++//
void bubbleSort(unsigned long long int *arr, long long int size){
	// Edit only after this line -- Bubble Sort
	unsigned long long int counter1, counter2;
	for (counter1 = 0; counter1 < size-1; counter1++){
		// Last i elements are already in place
		for (counter2 = 0; counter2 < (size-counter1-1); counter2++)
		if (arr[counter2] > arr[counter2+1]){
			swap(&arr[counter2], &arr[counter2+1]);
		}
	}
	// Edit only before this line
	return;
}

void swap(unsigned long long int *first, unsigned long long int *second)
{
	unsigned long long int tempreg = *first;
	*first = *second;
	*second = tempreg;
	return;
}


