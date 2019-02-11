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

	// ���ο� ��� ����
	temp = (struct Node *)malloc(sizeof(struct Node));
	strcpy(temp->name, namep);
	strcpy(temp->num, nump);
	temp->next = NULL;
	list.current = temp;
	list.count++;

	// 1) �� ����Ʈ �� ��, ����Ʈ�� �ص�� ����
	if (list.head == NULL)  // or if (list.coumt == 0)
	{
		list.head = list.current;
		// list.head = temp;
	}
	else // ����Ʈ�� ��尡 �ϳ� �̻� ���� ���
	{
		// �� ���� ����Ʈ�� �������� ã�Ƽ� �������� ���� ������
		struct Node * pos;
		pos = list.head;

		while (pos->next != NULL)		// ����Ʈ���� ������ ��帣 ã�� �� ���� �̵�
		{
			pos = pos->next;
		}
		pos->next = list.current;		// ������ ��忡 ���ο� ��� ����

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

void removeNameNode(linkedlist &list, char *namep) //current �����
{
	int i;
	list.current = list.head;
	if (list.head == NULL) //����Ʈ�� ��尡 ���� ��
	{
		cout << "����Ʈ�� ��尡 �����ϴ�" << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->name, namep) == 0) //ã�� �����Ϳ� ���� �����͸� ������ ��带 current�� ���� 
		{
			if (list.head == list.current)
			{
				if (list.current->next != NULL) //��ó�� ��尡 current + �ڿ� ��尡 �ϳ��̻� �� ���
				{
					list.current->next = list.head;
					delete list.current;
					list.count--;

				}
				else// ��ó�� ��尡 current + �ڿ� ��尡 ���� ��
				{
					delete list.current;
					list.count--;
					cout << "���� ���̻� ����Ʈ�� ��尡 �����ϴ�" << endl;
				}
			}
			else //current�� �߰��� �ְų� ���� ���� ���
			{
				struct Node* prior; //current ���� ��带 ����ų ���  ������
				prior = list.head; //��ó�� ��带 prior�� ����
				while (prior->next != list.current) //prior�� ���� ��尡  current�� �ƴҶ�����
				{
					prior = prior->next;//prior�� ���� ��带 ����Ŵ
				}//prior->next=current
				prior->next = list.current->next;//prior�� ���� ���� 
				delete list.current;
				list.count--;
			}
		}
		list.current = list.current->next;
	}
}

void removeNumNode(linkedlist &list, char *nump)//current �����
{
	int i;
	list.current = list.head;
	if (list.head == NULL) //����Ʈ�� ��尡 ���� ��
	{
		cout << "����Ʈ�� ��尡 �����ϴ�" << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->num, nump) == 0)//ã�� �����Ϳ� ���� �����͸� ������ ��带 current�� ���� 
		{
			if (list.head == list.current)
			{
				if (list.current->next != NULL) //��ó�� ��尡 current + �ڿ� ��尡 �ϳ��̻� �� ���
				{
					list.current->next = list.head;
					delete list.current;
					list.count--;

				}
				else// ��ó�� ��尡 current + �ڿ� ��尡 ���� ��
				{
					delete list.current;
					list.count--;
					cout << "���� ���̻� ����Ʈ�� ��尡 �����ϴ�" << endl;
				}
			}
			else //current�� �߰��� �ְų� ���� ���� ���
			{
				struct Node* prior; //current ���� ��带 ����ų ���  ������
				prior = list.head; //��ó�� ��带 prior�� ����
				while (prior->next != list.current) //prior�� ���� ��尡  current�� �ƴҶ�����
				{
					prior = prior->next;//prior�� ���� ��带 ����Ŵ
				}//prior->next=current
				prior->next = list.current->next;//prior�� ���� ���� 
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
	struct Node* insertNode; //������ ���
	insertNode = new Node; //�� ��� �����
	strcpy(insertNode->name, namep);
	strcpy(insertNode->num, nump);
	insertNode->next = NULL;

	list.current = list.head; // ù ��带 current�� ����

	if (list.head == NULL)
	{
		cout << "����Ʈ�� ��尡 �����ϴ�." << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->name, searchp) == 0) //ã�� �����Ϳ� ���� �����͸� ������ ��带 current�� ���� 
		{
			if (list.current->next == NULL) // current �ڿ� ��� x
			{
				list.current->next = insertNode; //insertNode�� current ���� ���� ����
				list.count++;
			}
			else //current �ڿ� ��� �ϳ� �̻� �� ���
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
	struct Node* insertNode; //������ ���
	insertNode = new Node; //�� ��� �����
	strcpy(insertNode->name, namep);
	strcpy(insertNode->num, nump);
	insertNode->next = NULL;

	list.current = list.head; // ù ��带 current�� ����

	if (list.head == NULL)
	{
		cout << "����Ʈ�� ��尡 �����ϴ�." << endl;
	}

	for (i = 0; i < list.count; i++)
	{
		if (strcmp(list.current->num, searchp) == 0) //ã�� �����Ϳ� ���� �����͸� ������ ��带 current�� ���� 
		{
			if (list.current->next == NULL) // current �ڿ� ��� x
			{
				list.current->next = insertNode; //insertNode�� current ���� ���� ����
				list.count++;
			}
			else //current �ڿ� ��� �ϳ� �̻� �� ���
			{
				insertNode->next = list.current->next;
				list.current->next = insertNode;
				list.count++;
			}
		}
		list.current = list.current->next;
	}
}