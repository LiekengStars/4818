#ifndef __D_LIST_H__
#define __D_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//1, 设计链表节点
typedef struct d_node{
	int data;
	struct d_node *prev;
	struct d_node *next;
}D_Node;

//2, 链表初始化 --> 链表头初始化!
D_Node *d_list_init();
//3, 链表节点插入（头插法）
bool d_list_add_node_head(D_Node *head, int data);
//3, 链表节点插入（尾插法）
bool d_list_add_node_tail(D_Node *head, int data);
//4, 链表遍历
void d_list_display(D_Node *head);
//5, 链表节点删除
bool d_list_remove_node(D_Node *head, int data);
//6, 双向链表销毁
void d_list_destroy(D_Node *head);


#endif
