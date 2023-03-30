#include <stdio.h>
#include <string.h>
// 构造结构体
struct student {
    char name[32];
    int age;
    int class;
};



int main(void) {

    // 一次性初始化结构体
    // struct student stu = {"austin", 19, 3};

    // 先声明再初始化结构体
    struct student stu;
    strcpy(stu.name, "austin");
    stu.age = 19;
    stu.class = 3;

    printf("name: %s\nage: %d\nclass: %d\n", stu.name, stu.age, stu.class);




    return 0;
}