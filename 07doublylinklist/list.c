#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 创建列表
list *ListCreate(void) {
    list *list = (struct list *)malloc(sizeof(struct list));
    if (list == NULL)
        return 0;
    list->head = NULL;
    list->rear = NULL;
    list->length = 0;

    return list;
}

// 清空链表中所有的节点但不删除链表本身
void ListEmpty(list *list) {
    unsigned long length;
    list_node *current, *next;
    current = list->head;
    length = list->length;
    while (length) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->rear = NULL;
}

// 释放整个列表
void ListRelease(list *list) {
    ListEmpty(list);
    free(list);
}

// 创建一个迭代器
list_iter *ListGetIterator(list *list, int direction) {
    list_iter *iter = (list_iter *)malloc(sizeof(list_iter));
    if (iter == NULL)
        return NULL;
    if (direction == LIST_START_HEAD)
        iter->next = list->head;
    else
        iter->next = list->rear;

    iter->direction = direction;

    return iter;
}

// 释放迭代器内存
void ListReleaseIterator(list_iter *iter) {
    free(iter);
}

// 返回链表下一个节点值
void *ListNext(list_iter *iter) {
    list_node *current = iter->next;
    if (current == NULL)
        return NULL;
    
    // 判断迭代器方向，并将迭代器 next 指针指向下一个节点
    if (iter->direction == LIST_START_HEAD)
        iter->next = current->next;
    else
        iter->next = current->prev;

    return current->value;
}

// 添加一个节点在链表头部
list *ListAddNodeHead(list *list, void *value) {

    // 新建一个链表节点
    list_node *node = (list_node *)malloc(sizeof(list_node));
    if (node == NULL)
        return NULL;
    node->value = value;

    // 如果链表为空
    if (list->length == 0) {
        list->head = node;
        list->rear = node;
        node->prev = NULL;
        node->next = NULL;
    }
    else {
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->length += 1;

    return list;
}

// 添加一个节点在链表尾部
list *ListAddNodeRear(list *list, void *value) {
    // 新建一个节点
    list_node *node = (list_node *)malloc(sizeof(list_node));
    if (node == NULL)
        return NULL;
    node->value = value;

    // 如果链表为空
    if (list->length == 0) {
        list->head = node;
        list->rear = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else {
        node->next = NULL;
        node->prev = list->rear;
        list->rear->next = node;
        list->rear = node;
    }
    list->length += 1;

    return list;
}

// 删除一个节点
void ListDeleteNode(list *list, list_node *node) {

    // 判断该节点是否有直接前驱
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;

    // 判断该节点是否有直接后驱
    if (node->next)
        node->next->prev = node->prev;
    else
        list->rear = node->prev;
    
    // 释放该节点
    free(node);
    list->length -= 1;
}

// 获取头部元素
void *ListGetValueHead(list *list) {
    if (list->head == NULL)
        return NULL;
    void *value = list->head->value;
    ListDeleteNode(list, list->head);

    return value;
}

// 获取尾部元素
void *ListGetValueRear(list *list) {
    if (list->rear == NULL)
        return NULL;
    void *value = list->rear->value;
    ListDeleteNode(list, list->rear);

    return value;
}