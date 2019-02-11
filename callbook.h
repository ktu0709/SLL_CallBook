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
	struct Node *temp; //임시 노드
	int count; // 리스트의 노드 개수
};


Node* append(linkedlist &list, char *namep, char *nump); //맨뒤에 노드 추가
void createList(linkedlist &list); // 리스트를 관리를 위한 데이터 관리 구조체 생성
void printList(linkedlist &list); //리스트 출력
void removeNameNode(linkedlist &list, char *namep); //똑같은 이름 데이터를 가지는 노드를 제거 
void removeNumNode(linkedlist &list, char *nump); //똑같은 전화번호 데이터 ""
void insertNameNode(linkedlist &list, char *namep,char *nump,char *searchp); //똑같은 이름 뒤에 노드 삽입
void insertNumNode(linkedlist &list, char *namep, char *nump, char *searchp); //똑같은 번호뒤에 노드 삽입
#endif 

