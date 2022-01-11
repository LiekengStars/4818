#include "d_list.h"

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
	//1) 准备新节点
	D_Node *newnode = (D_Node *)malloc(sizeof(D_Node));
	if(NULL == newnode)
	{
		perror("malloc newnode failed");
		return NULL;
	}

	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;		
	//2) 找到链表的尾节点 p
	D_Node *p = head;
	for(; p->next != NULL; p=p->next);		//循环结束，p指针指向链表最后一个节点!
	
	//3) 将新节点插入到尾节点后面
	p->next = newnode;
	newnode->prev = p;
	
	return true;
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
bool d_list_remove_node(D_Node *head, int data)
{
	//1) 遍历链表,找到需要被删除的节点p!
	D_Node *p = head->next;
	for(; p!=NULL; p=p->next)
	{
		if(p->data == data)	//找到节点p
		{
			//2) 将节点p从链表中删除
			if(p->next == NULL)		//p是链表中最后一个节点!
			{
				p->prev->next = p->next;	
			}
			else					//p不是最后一个节点
			{
				p->prev->next = p->next;		//p前一个节点中后继指针指向p的下一个节点
				p->next->prev = p->prev;		//p后一个节点中前继指针指向p的前一个节点
			}
			free(p);	//释放节点p
			printf("删除节点成功!\n");
			return true;
		}
	}
	printf("没有找到需要被删除的节点!\n");
	return false;

}

//6, 双向链表销毁
void d_list_destroy(D_Node *head)
{
	int i = 0;
	D_Node *p = head;
	D_Node *q = p->next;
	for(; q!=NULL; q=q->next)
	{
		free(p);
		i++;
		p = q;
	}
	free(p);
	printf("一共释放%d个数据节点!\n", i);
}

















