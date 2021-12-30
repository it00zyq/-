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

// ��ʾͨѶ¼�˵�
void showMenu();

// �����ϵ��
void addPerson(Contact *contact);

// ��ʾ��ϵ��
void showPerson(const Contact *contact);

// ɾ����ϵ��
void deletePerson(Contact *contact);

// ������ϵ��
void searchPerson(const Contact *contact);

// �޸���ϵ��
void modifyPerson(Contact *contact);

// �����ϵ��
void clearContact(Contact *contact);







