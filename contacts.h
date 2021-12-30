#include<iostream>
#include<string>
#define MAX_PERSON 1000
using namespace std;

struct Person {
	string name;
	int sex;
	int age;
	string phone;
};

struct Contact {
	Person persons[MAX_PERSON];
	int count;
};

// 显示通讯录菜单
void showMenu();

// 添加联系人
void addPerson(Contact *contact);

// 显示联系人
void showPerson(const Contact *contact);

// 删除联系人
void deletePerson(Contact *contact);

// 查找联系人
void searchPerson(const Contact *contact);

// 修改联系人
void modifyPerson(Contact *contact);

// 清空联系人
void clearContact(Contact *contact);







