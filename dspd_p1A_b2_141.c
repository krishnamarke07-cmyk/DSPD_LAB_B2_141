//Write a program to accept ‘n’ numbers into an array and then calculate the sum of numbers present in odd positions and even positions respectively
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum_even = 0, sum_odd = 0;
    for(i = 0; i < n; i++) {
        if(i % 2 == 0)
            sum_even += arr[i];
        else
            sum_odd += arr[i];
    }

    printf("Sum of elements at even positions: %d\n", sum_even);
    printf("Sum of elements at odd positions: %d\n", sum_odd);

    return 0;
}
