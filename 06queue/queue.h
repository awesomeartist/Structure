#ifndef __QUEUE_H__
#define __QUEUE_H__

// 队节点
typedef struct queue_node {
    struct queue_node *next;
    void *data;
}queue_node;

// 队本身
typedef struct queue {
    struct queue_node *head;
    struct queue_node *rear;
    int length;
}queue;

// 创建队列
queue *QueueCreate();

// 入队
queue *QueuePushData(queue *queue, void *data);

// 出队
void *QueuePullData(queue *queue);

// 释放队列中所有节点，但不释放队列本身
void QueueEmpty(queue *queue);

// 释放队列中所有节点，并释放队列本身
void QueueRelease(queue *queue);

#endif