/*
Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
a. Push an Element on to Stack 
b. Pop an Element from Stack 
c. Demonstrate how Stack can be used to check Palindrome 
d. Demonstrate Overflow and Underflow situations on Stack 
e. Display the status of Stack 
f. Exit 
Support the program with appropriate functions for each of the above operations.
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int num) {
    if(top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = num;
        printf("%d pushed to stack.\n", num);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void checkPalindrome() {
    char str[50];
    char rev[50];
    int i, j, len;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    len = strlen(str);

    top = -1; // reset stack
    for(i = 0; i < len; i++) {
        push(str[i]);
    }

    for(i = 0; i < len; i++) {
        rev[i] = stack[top--];
    }
    rev[len] = '\0';

    if(strcmp(str, rev) == 0)
        printf("%s is a Palindrome.\n", str);
    else
        printf("%s is not a Palindrome.\n", str);
}

int main() {
    int ch, num;

    while(1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &num);
                push(num);
                break;

            case 2:
                pop();
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
