#include<iostream>
#include<string>
#include "contacts.h"

int main() {
	// ��ʼ��ͨѶ¼
	Contact contact;
	contact.count = 0;

	int choice = 0;
	while (true) {
		system("pause");
		system("cls");
		// ��ʾѡ��˵�
		showMenu();

		cin >> choice;	
		switch (choice) {
		case 1:
			addPerson(&contact);
			break;
		case 2:
			showPerson(&contact);
			break;
		case 3:
			deletePerson(&contact);
			break;
		case 4:
			searchPerson(&contact);
			break;
		case 5:
			modifyPerson(&contact);
			break;
		case 6:
			clearContact(&contact);
			break;
		default:
			cout << "�����˳�ϵͳ����ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
		}
	}

	return 0;
}