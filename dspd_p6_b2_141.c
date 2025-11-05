/*
Implement Binary search tree(BST) with following Menu operations.
1. Search an element in BST(Display NULL if not found, If found Display Found)
2. Insert an element in BST
3. Delete leaf element in BST
4. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void search(struct node* root, int key)
{
    if(root == NULL)
    {
        printf("NULL\n");
        return;
    }
    if(root->data == key)
    {
        printf("Found\n");
        return;
    }
    else if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct node* deleteLeaf(struct node* root, int key)
{
    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if(key > root->data)
        root->right = deleteLeaf(root->right, key);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            printf("Deleted leaf node: %d\n", root->data);
            free(root);
            return NULL;
        }
        else
        {
            printf("%d is not a leaf node, cannot delete.\n", root->data);
        }
    }
    return root;
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    int ch, val;

    while(1)
    {
        printf("\n--- BST Menu ---\n");
        printf("1. Search element\n");
        printf("2. Insert element\n");
        printf("3. Delete leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(root, val);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Inorder after insertion: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf node value to delete: ");
                scanf("%d", &val);
                root = deleteLeaf(root, val);
                printf("Inorder after deletion: ");
                inorder(root);
                printf("\n");
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
