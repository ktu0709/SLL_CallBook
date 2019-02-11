#include"callbook.h"

int main(void)
{
	struct linkedlist list;
	char  menu_name[20];
	char menu_num[20];
	char menu_search[20];
	createList(list);
	int n;

	cout << "SLL 전화번호부" << endl;
	cout << "이름(name)+번호(num)" << endl<<endl;

	while (1)
	{
		cout << "───────────────" << endl;
		cout << "0.리스트 출력(printlist)" << endl;
		cout << "1.리스트에 데이터 넣기(append)" << endl;
		cout << "2.입력한 이름와 같은 노드 지우기(removeNameNode)" << endl;
		cout << "3.입력한 번호와 같은 노드 지우기(removeNumNode)" << endl;
		cout << "4.입력한 이름와 뒤에 노드 생성(insertNameNode)" << endl;
		cout << "5.입력한 번호와 뒤에 노드 생성(insertNumNode)" << endl;
		cout << "───────────────" << endl;
		cout << "메뉴를 고르세요 : ";
		cin >> n;

		if (n == 0)
		{
			cout << "리스트 출력" << endl;
			printList(list);
		}

		else if (n == 1)
		{
			cout << "전화번호 입력: ";
			cin >> menu_num;
			cout << "이름 입력: ";
			cin >> menu_name;
			append(list, menu_name, menu_num);
			cout << endl;
		}

		else if (n == 2)
		{
			cout << "지울 이름 입력: ";
			cin >> menu_name;
			removeNameNode(list, menu_name);
			cout << endl;
		}

		else if (n == 3)
		{
			cout << "지울 번호 입력: ";
			cin >> menu_num;
			removeNumNode(list, menu_num);
			cout << endl;
		}

		else if (n == 4)
		{
			cout << "같은 이름뒤에 노드를 생성합니다" << endl;
			cout << "찾을 이름 입력: ";
			cin >> menu_search;
			cout << "추가할 이름: ";
			cin >> menu_name;
			cout << "추가할 번호: ";
			cin >> menu_num;
			insertNameNode(list, menu_name, menu_num, menu_search);
			cout << endl;
		}
		else if (n == 5)
		{
			cout << "같은 번호 뒤에 노드를 생성합니다" << endl;
			cout << "찾을 번호 입력: ";
			cin >> menu_search;
			cout << "추가할 이름: ";
			cin >> menu_name;
			cout << "추가할 번호: ";
			cin >> menu_num;
			insertNumNode(list, menu_name, menu_num, menu_search);
			cout << endl;
		}
		else
		{
			cout << endl << "다시 입력해주세요" << endl;
		}
	}
	return 0;
}