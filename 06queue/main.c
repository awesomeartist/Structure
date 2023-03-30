#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {

    char a = 'a';
    char b = 'b';
    char c = 'c';

    queue *queue = QueueCreate();
    printf("%p\n", QueuePullData(queue));

    QueuePushData(queue, &a);
    QueuePushData(queue, &b);
    QueuePushData(queue, &c);

    while (queue->length) {
        printf("%c\n", *(char *)QueuePullData(queue));
    }

    QueuePushData(queue, &c);
    QueuePushData(queue, &c);

    // 释放队列中节点
    QueueEmpty(queue);
    printf("%p\n", QueuePullData(queue));

    // 释放队列
    QueueRelease(queue);

    return 0;
}