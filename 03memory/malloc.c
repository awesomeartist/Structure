#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name[32];
    int age;
    int class;
};

int main(void) {

    // size_t 的使用
    size_t size = sizeof(int);
    printf("the size of int is: %d\n", size);

    // malloc 的使用
    int *p = (int*)malloc(sizeof(int));
    *p = 100;

    //为结构体申请内存
    struct student stu;
    
    struct student *stu_ptr = (struct student *)malloc(sizeof(struct student));
    char *name = (char *)malloc(sizeof(char) * 32);

    strcpy(name, "austin");
    // stu_ptr->name = name;
    strcpy(stu_ptr->name, name);
    stu_ptr->age = 19;
    stu_ptr->class = 3;
    
    printf("name: %s\n age: %d\n class: %d\n", stu_ptr->name, stu_ptr->age, stu_ptr->age);
    
    free(stu_ptr);
    free(name);


    return 0;
}