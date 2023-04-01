#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

// 创建一个节点
tree_node *TreeCreateNode(char key) {
    tree_node *node = (struct tree_node *)malloc(sizeof(struct tree_node));
    if (node == NULL)
        return NULL;

        node->key = key;
        node->left = NULL;
        node->right = NULL;

        return node;
}

// 创建一个二叉树
tree_node *TreeCreate() {
    char str;
    tree_node *current;
    scanf("%c", &str);
    if ('#' == str)
        current = NULL;
    else {
        current = TreeCreateNode(str);
        current->left = TreeCreate();
        current->right= TreeCreate();
    }

    return current;
}

// 前序遍历1
void PreorderTraverse1(tree_node *node) {
    if (node != NULL) {
        printf("%c\t", node->key);
        PreorderTraverse1(node->left);
        PreorderTraverse1(node->right);
    }
}


// 前序遍历2
void PreorderTraverse2(tree_node *node) {
    stack *stack = StackCreate();
    tree_node *current = node;

    while (current != NULL || stack->length) {
        if (current != NULL) {
            printf("%c\t", current->key);
            StackPush(stack, current);
            current = current->left;
        }
        else {
            current = StackPop(stack);
            current = current->right;
        }
    }
    StackRelease(stack);
}

// 中序编列1
void InorderTraverse1(tree_node *node) {
    if (node != NULL) {
        InorderTraverse1(node->left);
        printf("%c\t", node->key);
        InorderTraverse1(node->right);
    }
}

// 中序遍历2
void InorderTraverse2(tree_node *node) {
    stack *stack = StackCreate();
    tree_node *current = node;

    while (current != NULL || stack->length) {
        if (current != NULL) {
            StackPush(stack, current);
            current = current->left;
        }
        else {
            current = StackPop(stack);
            printf("%c\t", current->key);
            current = current->right;
        }
    }
    StackRelease(stack);
}

// 后序遍历1
void PosorderTraverse1(tree_node *node) {
    if (node != NULL) {
        PosorderTraverse1(node->left);
        PosorderTraverse1(node->right);
        printf("%c\t", node->key);
    }
}

// 后序遍历2
void PosorderTraverse2(tree_node *node) {
    stack *s = StackCreate();
    stack *stack = StackCreate();

    tree_node *current = node;

    while (current != NULL || stack->length) {
        if (current != NULL) {
            StackPush(s, &(current->key));
            StackPush(stack, current);
            current = current->right;
        }
        else {
            current = StackPop(stack);
            current = current->left;
        }
    }
    while (s->length) {
        printf("%c\t", *(char *)StackPop(s));
    }
    StackRelease(s);
    StackRelease(stack);
}

// 层次遍历
void LevelTraverse(tree_node *root) {
    // 创建一个队列
    queue *queue = QueueCreate();

    if (root != NULL)
        QueuePushData(queue, root);
    while (queue->length) {
        tree_node *current = QueuePullData(queue);
        printf("%c\t", current->key);
        if (current->left)
            QueuePushData(queue, current->left);
        if (current->right)
            QueuePushData(queue, current->right);
    }

    // 队列用完后释放
    QueueRelease(queue);
}