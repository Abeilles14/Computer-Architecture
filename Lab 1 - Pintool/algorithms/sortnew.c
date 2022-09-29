#include "sortnew.h" 

void sortnew(unsigned long long int *arr, long long int size) {
    heapSort(arr, size);
	return;
}

 void heapify(unsigned long long int *arr, long long int size, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && arr[left] > arr[largest])
      largest = left;
  
    if (right < size && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swapnew(&arr[i], &arr[largest]);
      heapify(arr, size, largest);
    }

	return;
  }
  
  // main function to do heap sort
  void heapSort(unsigned long long int *arr, long long int size) {
    // Build max heap
    for (int i = (size/2)-1; i >= 0; i--)
      heapify(arr, size, i);
  
    // Heap sort
    for (int i = size-1; i >= 0; i--) {
      swapnew(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }

	return;
  }

void swapnew(unsigned long long int *first, unsigned long long int *second)
{
	unsigned long long int tempreg = *first;
	*first = *second;
	*second = tempreg;
	return;
}
