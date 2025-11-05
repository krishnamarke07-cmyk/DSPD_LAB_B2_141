/*
3. Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations.
*/

#include <stdio.h>
#define MAX 50

char queue[MAX];
int front = -1, rear = -1;

void insert(char ch)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = ch;
        printf("Inserted element: %c\n", ch);
    }
}

void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Deleted element: %c\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for(i = front; i <= rear; i++)
        {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    char c;

    while(1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &c);
                insert(c);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
