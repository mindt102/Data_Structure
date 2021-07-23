#include <stdio.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

bool IsBstUtil(struct Node *root, int minValue, int maxValue)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < maxValue && root->data > minValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
        return false;
}

bool isBinarySearchTree()
{
    return true;
};

int main()
{
    return 0;
}
