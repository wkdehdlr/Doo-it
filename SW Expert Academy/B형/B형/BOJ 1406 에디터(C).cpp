#pragma warning(disable : 4996)
#include <cstdio>
#include<malloc.h>
#define MAX_NODE 600000

typedef struct listNode
{
	char data;
	struct listNode* prev;
	struct listNode* next;
} ListNode;
/*
typedef struct
{
	int use;
	ListNode node;
} ListNodeHeap;

ListNodeHeap heap[MAX_NODE];

void initHeap(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		heap[i].use = 0;
	}
}



ListNode* getListNode(void)
{
int i;
for (i = 0; i < MAX_NODE; i++)
{
if (!heap[i].use)
{
heap[i].use = 1;
initListNode(&heap[i].node);
return &heap[i].node;
}
}
return NULL;
}
void destroyListNode(ListNode* node)
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
}
*/
void initListNode(ListNode* node)
{
	node->data = '\0';
	node->prev = node;
	node->next = node;
}


ListNode* appendListNode(ListNode* list, char data)
{
	ListNode *node;// = getListNode();
	node = (ListNode*)malloc(sizeof(listNode*) * 2 + 2);	//동적할당코드추가
	initListNode(node);//node 초기화 내가 직접 호출
	node->data = data;
	if (list == NULL)
	{
		return node;
	}
	else
	{
		ListNode* last = list->prev;
		last->next = node;
		list->prev = node;
		node->prev = last;
		node->next = list;
		return list;
	}
}
ListNode* insertListNode(ListNode* node, char data)
{
	ListNode* new_node;// = getListNode();
	new_node = (ListNode*)malloc(sizeof(listNode*) * 2 + 2);
	initListNode(new_node);

	new_node->data = data;

	new_node->prev = node->prev;
	new_node->next = node;
	node->prev->next = new_node;
	node->prev = new_node;
	return node;
}

ListNode* removeListNode(ListNode* list, ListNode* node)
{
	if (list == list->next)
	{
		//free(node);
		//destroyListNode(node);
		return NULL;
	}
	else
	{
		ListNode* prev = node->prev;
		ListNode* next = node->next;
		prev->next = next;
		next->prev = prev;
		//free(node);
		//destroyListNode(node);
		return (list == node) ? next : list;
	}
}
char str[100001];
int N;
int main()
{
	ListNode* list = NULL;
	ListNode* node;
	ListNode* head, *tail;
	scanf("%s", str);

	head = list = appendListNode(list, '\0');//head를 추가함
	for (int i = 0; str[i] != '\0'; ++i)
		list = appendListNode(list, str[i]);
	list = appendListNode(list, '\0');//마지막에 널문자 하나 추가해서 tail을 알림
	node = tail = list->prev;//커서를 맨마지막으로 옮긴다.

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		switch (str[0])
		{
		case 'L': if (node->prev != head)node = node->prev; break;
		case 'D': if (node != tail)node = node->next; break;
		case 'B': if (node->prev != head) {
			list = removeListNode(list, node->prev);
		} break;
		case 'P': scanf("%s", str); node = insertListNode(node, str[0]); break;
		}
	}

	node = head->next;
	while (node != tail)
	{
		printf("%c", node->data);
		node = node->next;
	}
	printf("\n");
}