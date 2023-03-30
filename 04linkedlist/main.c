
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main(void) {

    int length;
    list *link_list = CreateList();
    for (int i = 0; i < 5; i++) {
        ListInsertNode(link_list, i, i);
        ShowList(link_list);
    }
    ListDeleteNode(link_list, 2);
    printf("delete the data on position 2 \n");
    ShowList(link_list);

    return 0;
}