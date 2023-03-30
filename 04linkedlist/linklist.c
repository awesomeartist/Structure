#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


// 创建单链表返回头指针
list *CreateList() {
    // 创建一个新的节点
    list *head = (list *)malloc(sizeof(list));
    if (head == NULL)
        return NULL;
    // 初始化节点，头节点数据表示列表长度
    head->data = 0;
    head->next = NULL;
    return head;
}

// 链表插入节点
list *ListInsertNode(list *head, int data, int index) {

    list *current = head;

    // 如果要插入的位置比链表长，则输入非法操作
    if (index > current->data)
        return NULL;

    // 创建一个节点，并初始化
    list *node = (list *)malloc(sizeof(list));
    node->data = data;
    node->next = NULL;

    // 遍历列表，找到要插入的位置
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    // 插入
    node->next = current->next;
    current->next = node;

    // 链表长度 +1
    head->data += 1;

    return head;
}

// 打印列表数据，但不包括头节点数据
void ShowList(list *head) {

    list *current = head->next;
    printf("list: ");
    while (current) {
        printf("%d \t", current->data);
        current = current->next;
    }
    printf("\n");
}

// 删除节点数据
list *ListDeleteNode(list *head, int index) {

    list *current = head;

    // 删除的位置必须是合法的
    if (index > current->data)
        return 0;
    
    // 遍历链表，找到要删除的节点前一个节点的指针
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    // 临时记录将被删除的节点
    list *temp = current->next;
    current->next = current->next->next;

    // 释放掉被删除节点的内存
    free(temp);
    head->data -= 1;
    return head;
}