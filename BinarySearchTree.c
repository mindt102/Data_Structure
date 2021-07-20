#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int FindMin(struct BstNode *root)
{

    // Recursive Approach
    /*
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMin(root->left);
    }
    */

    // Iterative Approach
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    // struct BstNode* current = root;
    // We can use root directly because root is just a local variable
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
};

struct BstNode *Insert(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(struct BstNode *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
        return true;
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

void PrintTree(struct BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        PrintTree(root->left);
        PrintTree(root->right);
    }
}

int main()
{
    struct BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    PrintTree(root);
    printf("\n");

    int number;
    printf("Enter a number to search: ");
    scanf("%d", &number);
    if (Search(root, number))
        printf("Found\n");
    else
        printf("Not found\n");

    printf("Minimum value of the tree: %d\n", FindMin(root));

    return 0;
}