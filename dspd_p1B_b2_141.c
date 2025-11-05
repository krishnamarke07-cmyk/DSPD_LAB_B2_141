/*
Write a program to implement a Binary Search algorithm. 
Write a search function which takes a SearchList as its first parameter and a Comparable as its second. 
If either parameter is null, or if the SearchList is empty, you should return NULL.

Implement the following algorithm: 
• Examine the value in the middle of the current array and print it. 
• If the midpoint value is the value that we are looking for, return true. 
• If the value that we are looking for is greater than the midpoint value, 
  adjust the current array to start at the midpoint and print the index.
• If the value that we are looking for is less than the midpoint value, 
  adjust the current array to end at the midpoint and print the index.
• Continue until you find the value, or until the start reaches the end.
*/

// Program code:
// Write a program to perform Binary Search on a sorted array.

#include <stdio.h>

int main()
{
    int i = 0, n, search, found = 0, mid, start, high;
    int arr[100];

    printf("Enter the range of the array: ");
    scanf("%d", &n);

    high = n - 1;
    start = 0;

    printf("Enter %d number of sorted elements of array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element whose location you need to find in the array: ");
    scanf("%d", &search);

    while (start <= high)
    {
        mid = (start + high) / 2;

        printf("Start of the array is %d\n", start + 1);
        printf("End of the array is %d\n", high + 1);
        printf("Mid of the array is %d\n", mid + 1);
        printf("The array is:\n");

        for (i = start; i <= high; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        if (arr[mid] == search)
        {
            printf("The element %d is located at %d\n", search, mid + 1);
            found = 1;
            break;
        }
        else if (search < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (!found)
    {
        printf("The element %d is not present in the array.\n", search);
    }

    return 0;
}
