#include<iostream>
#include<string>
#include "contacts.h"

int main() {
	// 初始化通讯录
	Contact contact;
	contact.count = 0;

	int choice = 0;
	while (true) {
		system("pause");
		system("cls");
		// 显示选择菜单
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
			cout << "您已退出系统，欢迎下次使用!" << endl;
			system("pause");
			return 0;
		}
	}

	return 0;
}