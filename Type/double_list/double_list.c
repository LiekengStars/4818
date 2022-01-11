#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DateType int 

typedef struct head_list
{
    DateType date;
    struct head_list *prev;
    struct head_list *next;
}Head_List;


Head_List *head_init()
{
    Head_List *head =(Head_List *)malloc(sizeof(Head_List));
    if(head == NULL)
    {
        perror("malloc failed");
        return NULL;
    }
    head->next = head;
    head->prev = head;
    return head;
}

void _add_list(Head_List *new,Head_List *next,Head_List *prev)
{
    next->prev = new;
    new->next = next;
    prev->next = new;
    new->prev = prev;
}
bool add_node_h(Head_List *head, DateType date)
{
	//1) 申请新节点空间
	Head_List *new_list = (Head_List *)malloc(sizeof(Head_List));
	if(NULL == new_list)
	{
		perror("malloc failed");
		return NULL;
	}
	new_list->date = date;
	new_list->prev = NULL;
	new_list->next = NULL;
    
    _add_list(new_list,head->next,head);
	return true;
}


bool add_node_p(Head_List *head,DateType date) //尾插法
{
    Head_List *new_list = (Head_List *)malloc(sizeof(Head_List));
    if(new_list == NULL)
    {
        perror("malloc failed");
        return NULL;
    }
    new_list->date = date;
    new_list->next = NULL;
    new_list->prev = NULL;

    _add_list(new_list,head,head->prev);
    return true;
}

void Show_list(Head_List *head)
{
    Head_List *p = head->next;
    if(p == head)
    {
        printf("没有数据\n");
        return ;
    }
    while(p!= head)
    {
        printf("%d->",p->date);
        p = p->next; //自增
    }
}

bool Remove_list(Head_List *head,DateType date)
{
    Head_List *p = head->next;
    for(;p != head;p = p->next)
    {
        if(p->date == date)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            printf("删除成功\n");
            //Show_list(head);
            return true;
        }
    }
    printf("未找到目标\n");
    return false;
}

void Add_smell_T_Big(Head_List *head,DateType date)
{
    Head_List *new_list = (Head_List *)malloc(sizeof(Head_List));
    if(new_list == NULL)
    {
        perror("malloc failed\n");
        return ;
    }
    new_list->date = date;
    Head_List *q = head->next;
    for(;q->next!= NULL;q=q->next)
    {
        if(q->next->date >= date)
        {
            new_list->prev = q;
            q->next->prev = new_list;
            new_list->next = q->next;
            q->next = new_list;
            return ;
        }
    }
    q->next = new_list;
    new_list->prev = q;
    return ;
}

void Destory_list(Head_List *head)
{
    Head_List *p = head;
    Head_List *q = head->next;
    for(;q!=NULL;q=q->next)
    {
        free(p);
        p = q;
    }
}



int main(int argc,char *argv)
{
    Head_List *list1 = head_init();
    int i,num;
    for(i=0;i<8;i++)
    {
        scanf("%d",&num);
        add_node_p(list1,num);
        Show_list(list1);
}
    return 0;
}