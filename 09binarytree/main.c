#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main(void) {
    // ABD##E##CF##G##
    tree_node *root = TreeCreate();

    printf("\nPreorderTraverse1:");
    PreorderTraverse1(root);

    printf("\nPreorderTraverse2:");
    PreorderTraverse2(root);

    printf("\nInorderTraverse1:");
    InorderTraverse1(root);

    printf("\nInorderTraverse2:");
    InorderTraverse2(root);

    printf("\nPosorderTraverse1:");
    PosorderTraverse1(root);
    
    printf("\nPosorderTraverse2:");
    PosorderTraverse2(root);

    printf("\nLevelOrderTraverse:");
    LevelTraverse(root);
}