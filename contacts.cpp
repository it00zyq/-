#include "contacts.h"

void showMenu() {
	cout << "****************" << endl;
	cout << "* 1-�����ϵ�� *" << endl;
	cout << "* 2-��ʾ��ϵ�� *" << endl;
	cout << "* 3-ɾ����ϵ�� *" << endl;
	cout << "* 4-������ϵ�� *" << endl;
	cout << "* 5-�޸���ϵ�� *" << endl;
	cout << "* 6-�����ϵ�� *" << endl;
	cout << "* 0-�˳�ͨѶ¼ *" << endl;
	cout << "****************" << endl;
	cout << "��ѡ�� - ";
 }

// ��ȡ��ϵ���±꣬�����ڷ���-1
int findPerson(const Contact *contact, string name) {
	for (int i = 0; i < contact->count; i++) {
		// ������ϵ�ˣ������±�
		if (contact->persons[i].name == name) {
			return i;
		}
	}
	// ��ϵ�˲����ڣ�����-1
	return -1;
}


// �����ϵ��
void addPerson(Contact *contact) {
	// �ж�ͨѶ¼�Ƿ�����
	if (contact->count == MAX_PERSON) {
		cout << "ͨѶ¼������" << endl;
		return;
	}
	int count = contact->count;
	
	string name;
	cout << "������";
	cin >> name;
	contact->persons[count].name = name;

	int sex;
	while (true)
	{
		cout << "�Ա�(0-Ů��1-��)��";
		cin >> sex;
		if (sex == 0 || sex == 1) {
			break;
		} else {
			cout << "������Ϸ�ֵ��" << endl;
		}
	}
	contact->persons[count].sex = sex;

	int age;
	while (true)
	{
		cout << "����(0<age<150)��";
		cin >> age;
		if ( age > 0 && age < 150) {
			break;
		}
		else {
			cout << "������Ϸ�ֵ��" << endl;
		}
	}
	contact->persons[count].age = age;

	string phone;
	cout << "���룺";
	cin >> phone;
	contact->persons[count].phone = phone;

	// �������
	contact->count ++;

	cout << "�ɹ������ϵ�ˣ�" << endl;
}

// ��ʾ��ϵ��
void showPerson(const Contact *contact) {
	if (contact->count == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	} else {
		cout << "����\t �Ա�\t ����\t ��ϵ�绰" << endl;
		for (int i = 0; i < contact->count; i++) {
			cout << contact->persons[i].name << "\t";
			string sexString;
			if (contact->persons[i].sex == 0) {
				sexString = "Ů";
			}else {
				sexString = "��";
			}
			cout << sexString << "\t";
			cout << contact->persons[i].age << "\t";
			cout << contact->persons[i].phone << "\t";
			cout << endl;
		}
	}
}

// ɾ����ϵ��
void deletePerson(Contact *contact) {
	string name;
	cout << "��������ϵ��������";
	cin >> name;
	int res = findPerson(contact, name);
	if (res == -1) {
		cout << "��ϵ�˲����ڣ�" << endl;
	} else {
		contact->count --;
		for (int i = res; i < contact->count; i++) {
			contact->persons[i] = contact->persons[i + 1];
		}
		cout << "ɾ���ɹ���" << endl;
	}
}

// ������ϵ��
void searchPerson(const Contact *contact) {
	string name;
	cout << "��������ϵ��������";
	cin >> name;
	int res = findPerson(contact, name);
	if (res == -1) {
		cout << "��ϵ�˲����ڣ�" << endl;
	} else {
		Person p = contact->persons[res];
		cout << "��ϵ����Ϣ��" << endl;
		cout << "������" << p.name << endl;
		cout << "�Ա�" << (p.sex == 0 ? "Ů" : "��") << endl;
		cout << "���䣺" << p.age << endl;
		cout << "���룺" << p.phone << endl;
	}
}

// �޸���ϵ��
void modifyPerson(Contact *contact) {
	int count = contact->count;
	string name;
	cout << "��������ϵ��������";
	cin >> name;
	int res = findPerson(contact, name);
	if (res == -1) {
		cout << "��ϵ�˲����ڣ�" << endl;
	} else {
		cout << "��������ϵ���µ���Ϣ��" << endl;
		cout << "������";
		cin >> name;
		contact->persons[res].name = name;

		int sex;
		while (true)
		{
			cout << "�Ա�(0-Ů��1-��)��";
			cin >> sex;
			if (sex == 0 || sex == 1) {
				break;
			}
			else {
				cout << "������Ϸ�ֵ��" << endl;
			}
		}
		contact->persons[res].sex = sex;

		int age;
		while (true)
		{
			cout << "����(0<age<150)��";
			cin >> age;
			if (age > 0 && age < 150) {
				break;
			}
			else {
				cout << "������Ϸ�ֵ��" << endl;
			}
		}
		contact->persons[res].age = age;

		string phone;
		cout << "���룺";
		cin >> phone;
		contact->persons[res].phone = phone;
	}
}

// �����ϵ��
void clearContact(Contact *contact) {
	contact->count = 0;
	cout << "ͨѶ¼�����" << endl;
}