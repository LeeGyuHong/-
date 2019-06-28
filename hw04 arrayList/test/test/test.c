#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

// ======================================================================

LIST *create_list(void)
{
	LIST* p =(LIST*) malloc(sizeof(LIST));
	p->length = 0;
	if (p != NULL)
		return p;
	else
		printf("list ���� ����\n");
	return NULL;
}

// ======================================================================

void print_list(LIST * list)
{
	printf("(%d:",list->length);
		
	if (list->length == 0)
		printf(")\n");
	/*else if (list->length == 1)
        printf("%d)\n", list->items[0]);*/
	else if (list->length >= 1)
	{
		printf("%d", list->items[0]);
		for (int i = 1; i < list->length; i++)
		{
			printf(",%d", list->items[i]);
		}
		printf(")\n");
	}
	
}

// ======================================================================

int length_list(LIST * list)
{
	return list->length;
}

// ======================================================================

int add_list(LIST * list, int position, int item)    //position�� �������� �ֵ� ������ �ڷ� �а� �� �ڸ��� �ֱ�
{
	if (list->length >= MAX_LIST_SIZE)
	{
		printf("CURRENT LIST SIZE IS MAX LIST SIZE\n");
		return -1;
	}

	for (int i = list->length-1; i >=position; i--)  //�ڿ������� ä���ߵ�, �տ������� ä���� �ϳ��� index��� �θ� ä��Ե� �״����� index��Ҹ� �Ҿ����.
	{
		list->items[i + 1] = list->items[i];
	}
	list->items[position] = item;
	list->length++;
	return length_list(list);
}

// ======================================================================

int delete_list(LIST * list, int position)//������ġ ���� index��� �� ������ġ���� ���������
{
	if (list->length ==0) //main �Լ� ���������� ����Ʈ�� �ƹ��͵� ������ ������ �Ұ����ϹǷ� ������ȯ
		return -1;
	int deleted = list->items[position];
	for (int i = position; i < list->length-1; i++)
	{
		list->items[i] = list->items[i + 1];
	}
	list->length--;
	return deleted;
}

// ======================================================================
int main(void)
{
	LIST *l1;
	int i, r;

	// delete_list
	printf("===== t13: delete_list =====\n");

	l1 = create_list();
	for (i = 0; i < 5; i++)
		add_list(l1, i, i * 10);
	print_list(l1);

	r = delete_list(l1, 0);
	if (r != 0) {
		printf("ERROR: delete_list, i=0\n");
		return EXIT_FAILURE;
	}
	print_list(l1);

	r = delete_list(l1, 1);
	if (r != 20) {
		printf("ERROR: delete_list, i=1\n");
		return EXIT_FAILURE;
	}
	print_list(l1);

	r = delete_list(l1, 2);
	if (r != 40) {
		printf("ERROR: delete_list, i=2\n");
		return EXIT_FAILURE;
	}
	print_list(l1);

	r = delete_list(l1, 0);
	if (r != 10) {
		printf("ERROR: delete_list, i=0\n");
		return EXIT_FAILURE;
	}
	print_list(l1);

	r = delete_list(l1, 0);
	if (r != 30) {
		printf("ERROR: delete_list, i=0\n");
		return EXIT_FAILURE;
	}
	print_list(l1);

	r = delete_list(l1, 0);
	if (r != ERROR) {
		printf("ERROR: delete_list\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}