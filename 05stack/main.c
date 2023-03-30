
#include <stdio.h>
#include "stack.h"

int main(void) {

    char a = 'a';
    char b = 'b';
    char c = 'c';

    // 创建一个栈
    stack *stack = StackCreate();
    printf("%p\n", StackPop(stack));

    // 压栈
    StackPush(stack, &a);
    StackPush(stack, &b);
    StackPush(stack, &c);

    // 出栈
    while (stack->length > 0) {
        printf("%c \n", *(char *)StackPop(stack));
    }

    // 压栈
    StackPush(stack, &a);
    StackEmpty(stack);
    printf("%p\n", StackPop(stack));

    // 释放栈
    StackRelease(stack);

    return 0;
}