#include <stdio.h>
#include "dict.h"

int main(void) {

    // 创建一个 key 为字符串类型的字典
    dict *dict = DictCreate(1);

    char str1[] = "name";
    char str2[] = "austin";
    char str3[] = "lookcos";
    char str4[] = "age";
    int age = 18;

    DictPutEntry(dict, &str2, &str2);
    puts(DictGetValue(dict, &str2));

    DictPutEntry(dict, &str1, &str2);
    puts(DictGetValue(dict, &str1));

    DictPutEntry(dict, &str1, &str3);
    puts(DictGetValue(dict, &str1));

    DictPutEntry(dict, &str4, &age);
    printf("age: %d\n", *(int *)DictGetValue(dict, &str4));

    // 字典的释放
    DictEmpty(dict);
    DictRelease(dict);

    
    return 0;
}