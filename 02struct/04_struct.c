#include <stdio.h>


int main(void) {

    // typedef 的使用
    struct student {
        char name[32];
        int age;
        int class;
    };

    //使用 typedef 关键字为 struct student 指定一个别名
    typedef struct student s;

    // 或者合并定义为
    typedef struct student {
        char name[32];
        int age;
        int class;
    }s;


    return 0;
}