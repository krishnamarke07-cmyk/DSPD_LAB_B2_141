/*
This C program creates a linked list to store integer elements. 
It prompts the user to enter elements and add them to the list until the user enters 0. 
It then traverses the list and prints each element and "=>" until reaching the null pointer. 
Finally, it displays the number of nodes in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int num, count = 0;

    printf("Enter elements (enter 0 to stop):\n");
    while(1)
    {
        scanf("%d", &num);
        if(num == 0)
            break;

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        count++;
    }

    printf("\nLinked List Elements:\n");
    temp = head;
    while(temp != NULL)
    {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nTotal number of nodes: %d\n", count);

    return 0;
}
