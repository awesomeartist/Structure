#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// 创建队列
queue *QueueCreate() {

    // 创建一个队列
    queue *queue = (struct queue*)malloc(sizeof(struct queue));

    // 为方便操作，队列默认创建一个队列节点
    queue_node *node = (struct queue_node*)malloc(sizeof(struct queue_node));
    if (queue == NULL || node == NULL)
        return NULL;
    
    node->data = NULL;
    node->next = NULL;

    // 初始化队列
    queue->head = node;
    queue->rear = node;
    queue->length = 0;

    return queue;
}

// 入队
queue *QueuePushData(queue *queue, void *data) {

    // 创建一个节点
    queue_node *node = (struct queue_node*)malloc(sizeof(struct queue_node));
    if (node == NULL)
        return NULL;
    node->data = data;

    // 队尾插入元素
    queue->rear->next = node;
    queue->rear = queue->rear->next;

    queue->length += 1;
    return queue;
}

// 出队
void *QueuePullData(queue *queue) {
    queue_node *current = queue->head->next;

    // 判断队尾是否有数据
    if (current == NULL)
        return NULL;
    
    void *data = current->data;
    queue->head->next = current->next;

    // 盘对队列中除了头节点外是否只有一个节点，避免尾指针丢失
    if (queue->rear == current) {
        queue->rear = queue->head;
    }
    free(current);
    queue->length -= 1;

    return data;
}
// 释放队列中所有节点，但不释放队本身
void QueueEmpty(queue *queue) {

    int length = queue->length;
    queue_node *current, *next;

    // 注意这里不释放头节点
    current = queue->head->next;
    while (length--) {
        next = current->next;
        free(current);
        current = next;
    }

    queue->head->next = NULL;
    queue->rear->next = NULL;
    queue->length = 0;
}

// 释放队列，包括队列节点
void QueueRelease(queue *queue) {

    QueueEmpty(queue);
    free(queue->head);
    free(queue);
}