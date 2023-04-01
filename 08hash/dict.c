#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

// 哈希函数（适用整数）
static unsigned int HashInteger(void *key) {
    return ((*(int *)key) *2654435769) >> 28;
}

// 哈希函数 TIME32 算法
static unsigned int Hash33(void *key) {
    unsigned int hash = 0;
    while (*(char *)key != 0) {
        //左移5位相当于*32，再+hash则相当于*33;
        hash = (hash << 5) + hash + *(char *)key++;
    }
    return hash;
}

// 创建一个 dict
dict *DictCreate(int type) {
    dict *dict = (struct dict *)malloc(sizeof(struct dict));
    if (dict == NULL)
        return NULL;
    if (type == DICT_TYPE_INT)
        dict->hash = &HashInteger;
    else
        dict->hash = &Hash33;
    
    dict->size = 1;
    dict->sizemask = dict->size - 1;
    // 哈希表存放二级指针
    dict->table = (dict_entry **)malloc(sizeof(dict_entry *) * (dict->size));

    if (dict->table == NULL)
        return NULL;
    // 哈希表指针表内存初始化
    memset(dict->table, 0, sizeof(dict_entry *) * (dict->size));

    return dict;
}
// 创建一个dict_entry
dict_entry *DictCreateEntry(void *key, void *value) {
    dict_entry *entry = (dict_entry *)malloc(sizeof(dict_entry));
    if (entry == NULL)
        return NULL;
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}
// 字典插入一个键值对
dict *DictPutEntry(dict *dict, void *key, void *value) {
    // 哈希函数通过键值获得哈希地址
    unsigned int hash = dict->hash(key);
    // 
    int index = hash & dict->sizemask;

    dict_entry *entry;
    entry = DictCreateEntry(key, value);
    // 新键指向指向原哈希地址
    entry->next = dict->table[index];
    // 新键的地址存入哈希表
    dict->table[index] = entry;

    return dict;
}

/* 字典插入一个键值对 (另外一种思路)*/
/*
dict *dict_put_entry(dict *dict, void *key, void *val)
{
    unsigned int hash = dict->hash(key);
    int pos = hash & dict->sizemask;
    dict_entry *entry, *current;
    if(dict->table[pos]==0){
        printf("新增\n");
        entry = dict_create_entry(key, val);
        dict->table[pos] = entry;
    } else {
        current = dict->table[pos];
        
        /* 首先判断第一个节点是否符合更新的情况 */
        /* if(dict->hash(current->key) == dict->hash(key)) {
            printf("更新\n");
            current->val = val;
            return dict;
        } */

        /* 如果不符合，往下找，直到找到hash值相等的key的节点，则更新，
         * 或者直到next==NULL，此时新增在链表尾部。 */
       /*  while(current->next != NULL) {    
            printf("往下找\n");
            if(dict->hash(current->next->key) == dict->hash(key)) {
                printf("更新\n");
                current->next->val = val;
                return dict;
            };
            current = current->next;
        } */

        /* printf("尾部插入\n");
        entry = dict_create_entry(key, val);
        current->next = entry;
    }
    return dict;
} */

// dict 获取值
void *DictGetValue(dict *dict, void *key) {
    unsigned int hash = dict->hash(key);
    int index = hash & dict->sizemask;
    if (dict->table[index] == 0)
        return NULL;
    dict_entry *current = dict->table[index];
    while (dict->hash(current->key) != dict->hash(key)) {
        if (current->next != NULL)
            current = current->next;
        else
            return NULL;
    }
    return current->value;
}

// 清除 dict 所有 entry, 而不清除 dict 本身
void DictEmpty(dict *dict) {
    for (int i = 0; i < dict->size; i++) {
        if (dict->table[i] != 0) {
            dict_entry * current, *next;
            current = dict->table[i];
            while (current) {
                next = current->next;
                free(current);
                current = next;
            }
            dict->table[i] = 0;
        }
    }
}

// 释放 dict
void DictRelease(dict *dict) {
    DictEmpty(dict);
    free(dict->table);
    free(dict);
}