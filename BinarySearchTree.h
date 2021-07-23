#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct Node
{
    struct BstNode *BstNodePtr;
    struct Node *next;
};

// struct BstNode* Front(front) {

// }

bool IsEmpty(struct Node *front, struct Node *rear)
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(struct BstNode *x, struct Node **frontPtr, struct Node **rearPtr)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->BstNodePtr = x;
    temp->next = NULL;
    if (IsEmpty(*frontPtr, *rearPtr))
    {
        *frontPtr = *rearPtr = temp;
        return;
    }
    else
    {
        (*rearPtr)->next = temp;
        *rearPtr = temp;
    }
}

void Dequeue(struct Node **frontPtr, struct Node **rearPtr)
{
    struct Node *temp = *frontPtr;
    if (IsEmpty(*frontPtr, *rearPtr))
    {
        printf("Queue is empty, nothing to dequeue. \n");
        return;
    }
    else if (*frontPtr == *rearPtr)
    {
        *frontPtr = *rearPtr = NULL;
    }
    else
    {
        *frontPtr = (*frontPtr)->next;
    }
    free(temp);
}

void PrintQueue(struct Node *front, struct Node *rear)
{
    if (!IsEmpty(front, rear))
    {
        struct Node *temp = front;
        printf("Queue is: ");
        while (temp != NULL)
        {
            printf("%d ", temp->BstNodePtr->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

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

int FindHeight(struct BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

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

void PreOrder(struct BstNode *root)
{
    /*
    Tree Traversal:
    Bread First => Level Order
    Depth First:
            <root> <left> <right> => Preorder
            <left> <root> <right> => Inorder
            <left> <right> <root> => Postorder
    */
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void LevelOrder(struct BstNode *root)
{

    struct Node *front = NULL;
    struct Node *rear = NULL;

    Enqueue(root, &front, &rear);
    while (!IsEmpty(front, rear))
    {
        struct BstNode *current = front->BstNodePtr;
        printf("%d ", current->data);
        if (current->left != NULL)
        {
            Enqueue(current->left, &front, &rear);
        }
        if (current->right != NULL)
        {
            Enqueue(current->right, &front, &rear);
        }
        Dequeue(&front, &rear);
    }
}

struct BstNode *Delete(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        // Case 2: One child
        else if (root->left == NULL)
        {
            struct BstNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct BstNode *temp = root;
            root = root->left;
            free(temp);
        }

        else
        {
            struct BstNode *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }

        return root;
    }
}