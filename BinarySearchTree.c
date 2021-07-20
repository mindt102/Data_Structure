#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "BinarySearchTree.h"

int main()
{
    struct BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    printf("Preorder: ");
    PreOrder(root);
    printf("\n");

    printf("Levelorder: ");
    LevelOrder(root);
    printf("\n");

    // Search a number
    /*
    int number;
    printf("Enter a number to search: ");
    scanf("%d", &number);
    if (Search(root, number))
        printf("Found\n");
    else
        printf("Not found\n");
    */

    // Find Min value and Height of the tree
    /*
    printf("Minimum value of the tree: %d\n", FindMin(root));
    printf("Height of the tree: %d\n", FindHeight(root));
    */

    return 0;
}