#include"callbook.h"

int main(void)
{
	struct linkedlist list;
	char  menu_name[20];
	char menu_num[20];
	char menu_search[20];
	createList(list);
	int n;

	cout << "SLL ��ȭ��ȣ��" << endl;
	cout << "�̸�(name)+��ȣ(num)" << endl<<endl;

	while (1)
	{
		cout << "������������������������������" << endl;
		cout << "0.����Ʈ ���(printlist)" << endl;
		cout << "1.����Ʈ�� ������ �ֱ�(append)" << endl;
		cout << "2.�Է��� �̸��� ���� ��� �����(removeNameNode)" << endl;
		cout << "3.�Է��� ��ȣ�� ���� ��� �����(removeNumNode)" << endl;
		cout << "4.�Է��� �̸��� �ڿ� ��� ����(insertNameNode)" << endl;
		cout << "5.�Է��� ��ȣ�� �ڿ� ��� ����(insertNumNode)" << endl;
		cout << "������������������������������" << endl;
		cout << "�޴��� ������ : ";
		cin >> n;

		if (n == 0)
		{
			cout << "����Ʈ ���" << endl;
			printList(list);
		}

		else if (n == 1)
		{
			cout << "��ȭ��ȣ �Է�: ";
			cin >> menu_num;
			cout << "�̸� �Է�: ";
			cin >> menu_name;
			append(list, menu_name, menu_num);
			cout << endl;
		}

		else if (n == 2)
		{
			cout << "���� �̸� �Է�: ";
			cin >> menu_name;
			removeNameNode(list, menu_name);
			cout << endl;
		}

		else if (n == 3)
		{
			cout << "���� ��ȣ �Է�: ";
			cin >> menu_num;
			removeNumNode(list, menu_num);
			cout << endl;
		}

		else if (n == 4)
		{
			cout << "���� �̸��ڿ� ��带 �����մϴ�" << endl;
			cout << "ã�� �̸� �Է�: ";
			cin >> menu_search;
			cout << "�߰��� �̸�: ";
			cin >> menu_name;
			cout << "�߰��� ��ȣ: ";
			cin >> menu_num;
			insertNameNode(list, menu_name, menu_num, menu_search);
			cout << endl;
		}
		else if (n == 5)
		{
			cout << "���� ��ȣ �ڿ� ��带 �����մϴ�" << endl;
			cout << "ã�� ��ȣ �Է�: ";
			cin >> menu_search;
			cout << "�߰��� �̸�: ";
			cin >> menu_name;
			cout << "�߰��� ��ȣ: ";
			cin >> menu_num;
			insertNumNode(list, menu_name, menu_num, menu_search);
			cout << endl;
		}
		else
		{
			cout << endl << "�ٽ� �Է����ּ���" << endl;
		}
	}
	return 0;
}