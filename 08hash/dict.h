/* 基于哈希表的字典。
 * 支持整型或者字符型的键，值用空类型指针，所以可以表示各种数据，
 * 这也意味着节点不是直接保存数据，而是保存指向该值的指针变量。
 */

#ifndef __DICT_H__
#define __DICT_H__

// 字典类型
#define DICT_TYPE_INT 0
#define DICT_TYPE_STR 1

//键值对
typedef struct dict_entry {
    struct dict_entry *next;
    void *key;
    void *value;
} dict_entry;

// 字典
typedef struct dict {
    // 哈希函数
    unsigned int (*hash)(void *key);
    // table 数组用于存放 dict_entry 指针
    dict_entry **table;
    // 指针数组
    int size;
    // 掩码
    int sizemask;
} dict;

// 哈希函数（适用整数）
static unsigned int HashInteger(void *key);
// 哈希函数 TIME33 算法
static unsigned int Hash33(void *key);
// 创建一个 dict
dict *DictCreate(int type);
// 创建一个 dict_entry
dict_entry *DictCreateEntry(void *key, void *value);
// 字典插入一个键值对
dict *DictPutEntry(dict *dict, void *key, void *val);
// dict 获取值
void *DictGetValue(dict *dict, void *key);
// 清除 dict 所有 entry，而不清除 dict 本身
void DictEmpty(dict *dict);
// 释放 dict
void DictRelease(dict *dict);


#endif