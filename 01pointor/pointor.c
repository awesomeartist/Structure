#include <stdio.h>

int main() {
    
    // 声明一个整型变量 age，值是 17
    int age = 17;
    // 声明一个整型指针，指向变量 age 的地址，& 符号可以理解为 <取地址符号>
    int *p = &age;

    printf("the value of age: %d\n", age);
    printf("the value of *p: %d\n", *p);
    printf("the address of age: %d\n", &age);
    printf("the address that p points to: %d\n", p);
    printf("the address of p: %d\n", &p);


    return 0;
}