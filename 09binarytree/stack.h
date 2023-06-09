#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack_node {
    struct stack_node *next;
    void *data;
}stack_node;

typedef struct stack {
    struct stack_node *top;
    // 表示栈的高度
    int length;
}stack;

// 创建栈
stack *StackCreate();

// 入栈
stack *StackPush(stack *stack, void *data);

// 出栈
void *StackPop(stack *stack);

// 清空栈中所有元素，但不清除栈本身
void StackEmpty(stack *stack);

// 清空栈中所有元素并删除栈
void StackRelease(stack *stack);

#endif