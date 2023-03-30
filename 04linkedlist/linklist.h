#include <stdio.h>
#include <stdlib.h>


// 定义列表节点结构体
typedef struct node {
    int data;
    struct node *next;
}list;

// 创建单链表返回头指针
list *CreateList();

// 链表插入节点
list *ListInsertNode(list *head, int data, int index);

// 打印列表数据，但不包括头节点数据
void ShowList(list *head);

// 删除节点数据
list *ListDeleteNode(list *head, int index);