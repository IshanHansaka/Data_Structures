#include <stdio.h>

void InsertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void BubbleSort(int arr[], int length)
{
    int temp;
    int swapped;
    for (int i = 0; i < length - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < length -  i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped++;
            }
        }
        if (swapped == 0)
            break;
    }
}

void SelectionSort(int arr[], int length)
{
    int min_index;
    int temp;
    for (int i = 0; i < length - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {9, 1, 7, 6, 4, 8, 5, 3, 2};

    int length = sizeof(arr) / sizeof(int);

    SelectionSort(arr, length);

    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    return 0;
}