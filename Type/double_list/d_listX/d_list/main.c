#include "d_list.h"

int main(int argc, char *argv[])
{
	//1, 创建链表
	D_Node *d_list = d_list_init();
	
	//2, 输入5个数字到链表! ==> 每次输入数据,遍历一次链表!
	int i, num;
	for(i=0; i<5; i++)
	{
		scanf("%d", &num);
		d_list_add_node_tail(d_list, num);
		d_list_display(d_list);
	}
	
	//3, 输入数字，将这个数字从链表中删除！
	printf("请输入需要被删除的数字:");
	scanf("%d", &num);
	d_list_remove_node(d_list, num);
	d_list_display(d_list);
	
	d_list_destroy(d_list);
	
	
	return 0;
}
