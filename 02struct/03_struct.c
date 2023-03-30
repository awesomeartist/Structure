#include <stdio.h>
#include <string.h>


int main(void) {

    // struct 的使用
    struct student {
        char name[32];
        int age;
        int class;
    }stu;

    strcpy(stu.name, "austin");
    stu.age = 19;
    stu.class = 3;

    struct student *stu_ptr = &stu;

    // 使用 . 访问结构体变量成员
    printf("age: %d\n", stu.age);
    
    // 使用 -> 访问结构体变量成员
    printf(": %s\n", *stu_ptr);
    printf("age: %d\n", stu_ptr->age);


    return 0;
}