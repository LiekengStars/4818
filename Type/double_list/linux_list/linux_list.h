#ifndef _LINUX_LIST_H_
#define _LINUX_LIST_H_

#include "kernel_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct plane{
    int data;
    struct list_head ptr;                   //内核链表指针
}PLA,*Plane;

Plane list_init();
bool list_add_head(Plane head,int data);    //头插法
void list_display(Plane head) ;             //遍历链表
bool del_list(Plane head,int data);
void destory_list(Plane head);              //销毁链表
void add_abs_del(Plane head,int data);      //加入正数，删除负数




#endif