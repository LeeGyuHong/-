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
		printf("list 생성 오류\n");
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

int add_list(LIST * list, int position, int item)    //position에 무슨값이 있든 무조건 뒤로 밀고 그 자리에 넣기
{
	if (list->length >= MAX_LIST_SIZE)
	{
		printf("CURRENT LIST SIZE IS MAX LIST SIZE\n");
		return -1;
	}

	for (int i = list->length-1; i >=position; i--)  //뒤에서부터 채워야됨, 앞에서부터 채울경우 하나의 index요소 로만 채우게됨 그다음의 index요소를 잃어버림.
	{
		list->items[i + 1] = list->items[i];
	}
	list->items[position] = item;
	list->length++;
	return length_list(list);
}

// ======================================================================

int delete_list(LIST * list, int position)//삭제위치 뒤의 index요소 로 삭제위치부터 덮어버리기
{
	if (list->length ==0) //main 함수 마지막에서 리스트에 아무것도 없을시 삭제가 불가능하므로 에러반환
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