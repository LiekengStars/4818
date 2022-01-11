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
D_Node *d_list_init()
{
	//1) 申请堆空间
	D_Node *head = (D_Node *)malloc(sizeof(D_Node));
	if(NULL == head)
	{
		perror("malloc head failed");
		return NULL;
	}
	
	//2) 链表头赋值
	head->prev = NULL;
	head->next = NULL;
	
	//3) 返回链表头
	return head;
}

//3, 链表节点插入（头插法）
bool d_list_add_node_head(D_Node *head, int data)
{
	//1) 申请新节点空间
	D_Node *newnode = (D_Node *)malloc(sizeof(D_Node));
	if(NULL == newnode)
	{
		perror("malloc newnode failed");
		return NULL;
	}

	//2) 新节点赋值
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;	

	//3) 头插法插入新节点
	if(head->next == NULL)		//如果链表是空的
	{
		head->next = newnode;
		newnode->prev = head;
	}
	else
	{
		newnode->next = head->next;			//记录node1的地址
		head->next = newnode;				//处理后继指针,完成之后node1 -> newnode->next
		
		newnode->next->prev = newnode;
		newnode->prev = head;	
	}
	return true;
}

//3, 链表节点插入（尾插法）
bool d_list_add_node_tail(D_Node *head, int data)
{
	
	
}


//4, 链表遍历
void d_list_display(D_Node *head)
{
	D_Node *p = head->next;
	for(; p!=NULL; p=p->next)	//从第一个数据节点到最后!
	{
		printf("%d ->", p->data);
	}
	printf("NULL\n");
}



//5, 链表节点删除
//6, 链表销毁


int main(int argc, char *argv[])
{
	//1, 创建链表
	D_Node *d_list = d_list_init();
	
	//2, 输入5个数字到链表! ==> 每次输入数据,遍历一次链表!
	int i, num;
	for(i=0; i<5; i++)
	{
		scanf("%d", &num);
		d_list_add_node_head(d_list, num);
		d_list_display(d_list);
	}
	
	
	
	
	return 0;
}















