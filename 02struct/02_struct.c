#include <stdio.h>
#include <string.h>

int main(void) {

#if 0
    // struct 的属性声明与变量声明可以合并
    struct student {
        char name[32];
        int age;
        int class;
    }stu;

    strcpy(stu.name, "austin");
    stu.age = 19;
    stu.class = 3;

    printf("name : %s\nage : %d\nclass : %d\n", stu.name, stu.age, stu.class);
#elif 0
    // 初试化也可以写在一起
    struct student {
        char name[32];
        int age;
        int class;
    }stu = {"austin", 19, 3},
    stu2 = {"tim", 18, 2};

    printf("name : %s\nage : %d\nclass : %d\n", stu.name, stu.age, stu.class);
    printf("name : %s\nage : %d\nclass : %d\n", stu2.name, stu2.age, stu2.class);

#elif 1
    // 可以省略结构体的标记，适用于只需要一个 struct student 变量
    struct {
        char name[32];
        int age;
        int class;
    }stu;

    strcpy(stu.name, "austin");
    stu.age = 19;
    stu.class = 3;

    printf("name: %s\nage: %d\nclass: %d\n", stu.name, stu.age, stu.class);
#endif
    

    return 0;
}