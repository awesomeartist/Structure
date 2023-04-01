#ifndef __LIST_H__
#define __LIST_H__

// 定义迭代器迭代方向
#define LIST_START_HEAD 0
#define LIST_START_REAR 1

// 链表节点
typedef struct list_node {
    struct list_node *prev;
    struct list_node *next;
    void *value;  
} list_node;

// 链表
typedef struct list {
    unsigned long length;
    list_node *head;
    list_node *rear;
} list;

// 迭代器结构
typedef struct list_iter {
    list_node *next;
    int direction;
} list_iter;


// 创建链表
list *ListCreate(void);
// 创建一个迭代器 
list_iter *ListGetIterator(list *list, int direction);
// 返回链表下一个节点值
void * ListNext(list_iter *iter);
// 释放迭代器内存
void ListReleaseIterator(list_iter *iter);
// 添加一个节点在链表头部
list *ListAddNodeHead(list *list, void *value);
// 添加一个节点在链表尾部 
list *ListAddNodeRear(list *list, void *value);
// 删除一个节点
void ListDeleteNode(list *list, list_node *node);
// 获取头部元素
void *ListGetValueHead(list *list);
// 获取尾部元素
void *ListGetValueRear(list *list);
// 清空链表中所有的节点但是不删除链表本身
void ListEmpty(list *list);
// 释放整个链表
void ListRelease(list *list);

#endif