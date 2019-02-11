#include"callbook.h"


void createList(linkedlist &list)
{
	list.head = NULL;
	list.current = NULL;
	list.count = 0;
}

Node* append(linkedlist &list, char *namep, char *nump)
{
	struct Node * temp;

	// 새로운 노드 새성
	temp = (struct Node *)malloc(sizeof(struct Node));
	strcpy(temp->name, namep);
	strcpy(temp->num, nump);
	temp->next = NULL;
	list.current = temp;
	list.count++;

	// 1) 빈 리스트 일 때, 리스트에 해드로 연결
	if (list.head == NULL)  // or if (list.coumt == 0)
	{
		list.head = list.current;
		// list.head = temp;
	}
	else // 리스트에 노드가 하나 이상 있을 경우
	{
		// 이 경우는 리스트의 마지막을 찾아서 마지막에 연결 시켜줌
		struct Node * pos;
		pos = list.head;

		while (pos->next != NULL)		// 리스트에서 마지막 노드르 찾을 때 까지 이동
		{
			pos = pos->next;
		}
		pos->next = list.current;		// 마지막 노드에 새로운 노드 연결

	}

	return list.current;
}


void printList(linkedlist &list)
{

	int i;
	struct Node * temp;

	temp = list.head;

	for (i = 0; i < list.count; i++)
	{
		cout << i + 1 << '.' << temp->name << " : " << temp->num << endl << endl;
		temp = temp->next;
	}
}

void removeNameNode(linkedlist &list, char *namep) //current 지우기
{
	int i;
	list.current = list.head;
	if (list.head == NULL) //리스트에 노드가 없을 떄
	{
		cout << "리스트에 노드가 없습니다" << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->name, namep) == 0) //찾을 데이터와 같은 데이터를 가지는 노드를 current로 가정 
		{
			if (list.head == list.current)
			{
				if (list.current->next != NULL) //맨처음 노드가 current + 뒤에 노드가 하나이상 일 경우
				{
					list.current->next = list.head;
					delete list.current;
					list.count--;

				}
				else// 맨처음 노드가 current + 뒤에 노드가 없을 떄
				{
					delete list.current;
					list.count--;
					cout << "이젠 더이상 리스트에 노드가 없습니다" << endl;
				}
			}
			else //current가 중간에 있거나 끝에 있을 경우
			{
				struct Node* prior; //current 이전 노드를 가르킬 노드  포인터
				prior = list.head; //맨처음 노드를 prior로 지정
				while (prior->next != list.current) //prior의 다음 노드가  current가 아닐때까지
				{
					prior = prior->next;//prior는 다음 노드를 가르킴
				}//prior->next=current
				prior->next = list.current->next;//prior의 다음 노드는 
				delete list.current;
				list.count--;
			}
		}
		list.current = list.current->next;
	}
}

void removeNumNode(linkedlist &list, char *nump)//current 지우기
{
	int i;
	list.current = list.head;
	if (list.head == NULL) //리스트에 노드가 없을 떄
	{
		cout << "리스트에 노드가 없습니다" << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->num, nump) == 0)//찾을 데이터와 같은 데이터를 가지는 노드를 current로 가정 
		{
			if (list.head == list.current)
			{
				if (list.current->next != NULL) //맨처음 노드가 current + 뒤에 노드가 하나이상 일 경우
				{
					list.current->next = list.head;
					delete list.current;
					list.count--;

				}
				else// 맨처음 노드가 current + 뒤에 노드가 없을 떄
				{
					delete list.current;
					list.count--;
					cout << "이젠 더이상 리스트에 노드가 없습니다" << endl;
				}
			}
			else //current가 중간에 있거나 끝에 있을 경우
			{
				struct Node* prior; //current 이전 노드를 가르킬 노드  포인터
				prior = list.head; //맨처음 노드를 prior로 지정
				while (prior->next != list.current) //prior의 다음 노드가  current가 아닐때까지
				{
					prior = prior->next;//prior는 다음 노드를 가르킴
				}//prior->next=current
				prior->next = list.current->next;//prior의 다음 노드는 
				delete list.current;
				list.count--;
			}
		}
		list.current = list.current->next;
	}
}

void insertNameNode(linkedlist &list, char *namep, char *nump,char *searchp)
{
	int i;
	struct Node* insertNode; //삽입할 노드
	insertNode = new Node; //새 노드 만들기
	strcpy(insertNode->name, namep);
	strcpy(insertNode->num, nump);
	insertNode->next = NULL;

	list.current = list.head; // 첫 노드를 current로 지정

	if (list.head == NULL)
	{
		cout << "리스트에 노드가 없습니다." << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->name, searchp) == 0) //찾을 데이터와 같은 데이터를 가지는 노드를 current로 가정 
		{
			if (list.current->next == NULL) // current 뒤에 노드 x
			{
				list.current->next = insertNode; //insertNode를 current 다음 노드로 지정
				list.count++;
			}
			else //current 뒤에 노드 하나 이상 일 경우
			{
				insertNode->next = list.current->next;
				list.current->next = insertNode;
				list.count++;
			}
		}
		list.current = list.current->next;
	}
}

void insertNumNode(linkedlist &list, char *namep, char *nump, char *searchp)
{
	int i;
	struct Node* insertNode; //삽입할 노드
	insertNode = new Node; //새 노드 만들기
	strcpy(insertNode->name, namep);
	strcpy(insertNode->num, nump);
	insertNode->next = NULL;

	list.current = list.head; // 첫 노드를 current로 지정

	if (list.head == NULL)
	{
		cout << "리스트에 노드가 없습니다." << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->num, searchp) == 0) //찾을 데이터와 같은 데이터를 가지는 노드를 current로 가정 
		{
			if (list.current->next == NULL) // current 뒤에 노드 x
			{
				list.current->next = insertNode; //insertNode를 current 다음 노드로 지정
				list.count++;
			}
			else //current 뒤에 노드 하나 이상 일 경우
			{
				insertNode->next = list.current->next;
				list.current->next = insertNode;
				list.count++;
			}
		}
		list.current = list.current->next;
	}
}