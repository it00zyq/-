#include "contacts.h"

void showMenu() {
	cout << "****************" << endl;
	cout << "* 1-添加联系人 *" << endl;
	cout << "* 2-显示联系人 *" << endl;
	cout << "* 3-删除联系人 *" << endl;
	cout << "* 4-查找联系人 *" << endl;
	cout << "* 5-修改联系人 *" << endl;
	cout << "* 6-清空联系人 *" << endl;
	cout << "* 0-退出通讯录 *" << endl;
	cout << "****************" << endl;
	cout << "请选择 - ";
 }

// 获取联系人下标，不存在返回-1
int findPerson(const Contact *contact, string name) {
	for (int i = 0; i < contact->count; i++) {
		// 存在联系人，返回下标
		if (contact->persons[i].name == name) {
			return i;
		}
	}
	// 联系人不存在，返回-1
	return -1;
}


// 添加联系人
void addPerson(Contact *contact) {
	// 判断通讯录是否已满
	if (contact->count == MAX_PERSON) {
		cout << "通讯录已满！" << endl;
		return;
	}
	int count = contact->count;
	
	string name;
	cout << "姓名：";
	cin >> name;
	contact->persons[count].name = name;

	int sex;
	while (true)
	{
		cout << "性别(0-女，1-男)：";
		cin >> sex;
		if (sex == 0 || sex == 1) {
			break;
		} else {
			cout << "请输入合法值！" << endl;
		}
	}
	contact->persons[count].sex = sex;

	int age;
	while (true)
	{
		cout << "年龄(0<age<150)：";
		cin >> age;
		if ( age > 0 && age < 150) {
			break;
		}
		else {
			cout << "请输入合法值！" << endl;
		}
	}
	contact->persons[count].age = age;

	string phone;
	cout << "号码：";
	cin >> phone;
	contact->persons[count].phone = phone;

	// 添加人数
	contact->count ++;

	cout << "成功添加联系人！" << endl;
}

// 显示联系人
void showPerson(const Contact *contact) {
	if (contact->count == 0) {
		cout << "通讯录为空！" << endl;
	} else {
		cout << "姓名\t 性别\t 年龄\t 联系电话" << endl;
		for (int i = 0; i < contact->count; i++) {
			cout << contact->persons[i].name << "\t";
			string sexString;
			if (contact->persons[i].sex == 0) {
				sexString = "女";
			}else {
				sexString = "男";
			}
			cout << sexString << "\t";
			cout << contact->persons[i].age << "\t";
			cout << contact->persons[i].phone << "\t";
			cout << endl;
		}
	}
}

// 删除联系人
void deletePerson(Contact *contact) {
	string name;
	cout << "请输入联系人姓名：";
	cin >> name;
	int res = findPerson(contact, name);
	if (res == -1) {
		cout << "联系人不存在！" << endl;
	} else {
		contact->count --;
		for (int i = res; i < contact->count; i++) {
			contact->persons[i] = contact->persons[i + 1];
		}
		cout << "删除成功！" << endl;
	}
}

// 查找联系人
void searchPerson(const Contact *contact) {
	string name;
	cout << "请输入联系人姓名：";
	cin >> name;
	int res = findPerson(contact, name);
	if (res == -1) {
		cout << "联系人不存在！" << endl;
	} else {
		Person p = contact->persons[res];
		cout << "联系人信息：" << endl;
		cout << "姓名：" << p.name << endl;
		cout << "性别：" << (p.sex == 0 ? "女" : "男") << endl;
		cout << "年龄：" << p.age << endl;
		cout << "号码：" << p.phone << endl;
	}
}

// 修改联系人
void modifyPerson(Contact *contact) {
	int count = contact->count;
	string name;
	cout << "请输入联系人姓名：";
	cin >> name;
	int res = findPerson(contact, name);
	if (res == -1) {
		cout << "联系人不存在！" << endl;
	} else {
		cout << "请输入联系人新的信息：" << endl;
		cout << "姓名：";
		cin >> name;
		contact->persons[res].name = name;

		int sex;
		while (true)
		{
			cout << "性别(0-女，1-男)：";
			cin >> sex;
			if (sex == 0 || sex == 1) {
				break;
			}
			else {
				cout << "请输入合法值！" << endl;
			}
		}
		contact->persons[res].sex = sex;

		int age;
		while (true)
		{
			cout << "年龄(0<age<150)：";
			cin >> age;
			if (age > 0 && age < 150) {
				break;
			}
			else {
				cout << "请输入合法值！" << endl;
			}
		}
		contact->persons[res].age = age;

		string phone;
		cout << "号码：";
		cin >> phone;
		contact->persons[res].phone = phone;
	}
}

// 清空联系人
void clearContact(Contact *contact) {
	contact->count = 0;
	cout << "通讯录已清空" << endl;
}