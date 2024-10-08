#include <stdio.h>

void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    int leftArray[n1], rightArray[n2];

    for (i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];

    i = 0;
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {13, 15, 25, 7, 9, 10, 1,6, 2,5,8};
    int array_size = sizeof(array) / sizeof(array[0]);

    printf("Given array is \n");
    printArray(array, array_size);

    mergeSort(array, 0, array_size - 1);

    printf("\nSorted array is \n");
    printArray(array, array_size);

    return 0;
}
