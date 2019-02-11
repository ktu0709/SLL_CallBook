#ifndef CALLBOOK_H
#define CALLBOOK_H

#include<iostream>
#include<cstring>
#include<assert.h>
using namespace std;

struct Node{
	char name[20];
	char num[20];
	struct Node *next;
	
};

struct linkedlist{
	struct Node *head; 
	struct Node *current; 
	struct Node *temp; //�ӽ� ���
	int count; // ����Ʈ�� ��� ����
};


Node* append(linkedlist &list, char *namep, char *nump); //�ǵڿ� ��� �߰�
void createList(linkedlist &list); // ����Ʈ�� ������ ���� ������ ���� ����ü ����
void printList(linkedlist &list); //����Ʈ ���
void removeNameNode(linkedlist &list, char *namep); //�Ȱ��� �̸� �����͸� ������ ��带 ���� 
void removeNumNode(linkedlist &list, char *nump); //�Ȱ��� ��ȭ��ȣ ������ ""
void insertNameNode(linkedlist &list, char *namep,char *nump,char *searchp); //�Ȱ��� �̸� �ڿ� ��� ����
void insertNumNode(linkedlist &list, char *namep, char *nump, char *searchp); //�Ȱ��� ��ȣ�ڿ� ��� ����
#endif 

