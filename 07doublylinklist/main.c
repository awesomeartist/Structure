#include <stdio.h>
#include "list.h"


int main(void) {

    char a = 'a';
    char b = 'b';
    char c = 'c';

    // 创建列表
    list *list = ListCreate();

    // 测试空表是否报错
    printf("-----test void list\n");
    printf("%p\n", ListGetValueHead(list));
    printf("%p\n", ListGetValueRear(list));

    // 表头添加数据
    ListAddNodeHead(list, &a);
    ListAddNodeHead(list, &b);

    // 表尾添加数据
    ListAddNodeRear(list, &c);
    ListAddNodeRear(list, &a);

    // 分别从列表头部和尾部出队
    printf("---the length of list: %d\n", list->length);
    printf("---pop value from head---\n");

    while (list->length > 2) {
        printf("%c\n", *(char *)ListGetValueHead(list));
    }
    printf("---pop value from rear---\n");
    while (list->length) {
        printf("%c\n", *(char *)ListGetValueRear(list));
    }

    // 添加数据
    ListAddNodeHead(list, &a);
    ListAddNodeHead(list, &b);
    ListAddNodeHead(list, &c);

    // 创建一个正向迭代器
    list_iter *iter = ListGetIterator(list, LIST_START_HEAD);

    // 测试迭代器
    printf("---test iter---\n");
    printf("%c\n", *(char *)ListNext(iter));
    printf("%c\n", *(char *)ListNext(iter));

    // 释放迭代器
    ListReleaseIterator(iter);

    // 清除链表节点
    ListEmpty(list);

    printf("---test void list---\n");
    printf("%p\n", ListGetValueHead(list));
    printf("%p\n", ListGetValueRear(list));

    // 释放链表
    ListRelease(list);


    return 0;
}