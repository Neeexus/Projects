#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>


#include "User.h"
#include "Root.h"
#include "Exception.h"
#include "Management.h"
using namespace std;
string Management::encrypt(string a) { // ��ȣȭ�� ���� �żҵ�

	for (unsigned int i = 0; i < a.length(); i++) {
		a[i] = a[i] + 127;
	}
	return a;

}

string Management:: decrypt(string a) { // ��ȣȭ�� ���� �޼ҵ�
	for (unsigned int i = 0; i < a.length(); i++) {
		a[i] = a[i] - 127;
	}

	return a;
}

bool Management::verify(string a, vector<User> &  b) throw(AlreadyExist) {  //vector�� ���� ���̵� �����ϴ��� üũ�ϴ� �޼ҵ�

	for (unsigned int i = 0; i < b.size(); i++) {

		if (a == b[i].getUsername()) {
			AlreadyExist expn(a);
			throw expn;
			return false;
		}


	}

	return true;
}

bool Management::IDverify(string a, vector<User> &  b)throw(WrongAcException) { //vector�� ���� ���̵� �´��� üũ�ϴ� �޼ҵ�

	for (unsigned int i = 0; i < b.size(); i++) {

		if (a == b[i].getUsername()) {

			return false;
		}

	}

	WrongAcException expn(a);
	throw  expn;
	return true;
}

bool Management::verify(string a, vector<User> &  b, int & index) { //vector�� ���� index ���� �������ִ� �޼ҵ�

	for (unsigned int i = 0; i < b.size(); i++) {

		if (a == b[i].getUsername()) {
			index = i;
			return false;
		}
	}


	return true;
}


void Management::printAllUsers(vector<User> & a) { // ���� �α��� ���� �������� ���� ���

	cout << endl << "�α��� ��Ȳ :" << endl;

	for (unsigned int i = 0; i < a.size(); i++) {
		if (a[i].getUsername() != "root") {
			cout << a[i].getUsername() << endl;
		}

	}
}


bool Management::passwordCheck(string password, string username, vector<User> & b)throw(WrongPsException) { // �н����尡 �ùٸ��� üũ�ϴ� �޼ҵ�
	int userIndex = -1;
	for (unsigned int i = 0; i < b.size(); i++) {
		if (username == b[i].getUsername()) {

			userIndex = i;
			break;

		}

	}

	if (userIndex != -1) {
		if (password == b[userIndex].getPassword()) {

			return true;
		}
	}
	WrongPsException expn(password);
	throw expn;
	return false;
}

void Management::sendMessage(string user, string messageTo, vector<User> & b, User * currUser) { // �޼����� ���۽����ִ� �޼ҵ�
	int index;
	if (!verify(user, b, index)) {

		b[index].message = messageTo + "\t ������ : " + currUser->getUsername();
	}
}

int Management::getUserIndex(string user, vector<User> & b) {  //������ �迭 ���� ���Ͻ����ִ� �޼ҵ�
	for (unsigned int i = 0; i < b.size(); i++) {
		if (user == b[i].getUsername()) {
			return i;
		}
	}
	return -1;
}

void Management::printAllUsersInfo(vector <User> & b) { // ������ �������� ���Ǵ� ������ ���� ���� ���
	char pass[50] = "C++pro"; // ���� Ű ��ȣ
	char opt[50];
	char ent;

	for (unsigned int i = 0; i < b.size(); i++) {
		encrypt(b[i].getPassword());

		cout << "���̵�: " << b[i].getUsername() << endl << "�н�����: " << encrypt(b[i].getPassword()) << endl;
		if (b[i].message == "") {
			cout << "�޼��� ����� �����ϴ�.\n\n";
		}
		else {

			cout << encrypt(b[i].message) << endl << endl;
		}
	}
	cout << endl << endl;
	cout << "�޼����� �� �н������ ��ȣȭ �Ǿ��ֽ��ϴ�." << endl;
	cout << "�����Ͻ÷��� ���Ű�� �Է����ּ���." << endl << endl;
	cout << "�����Ͻðڽ��ϱ�?(Y/N)" << endl;
	cin >> ent;
	while (1) {
		if (ent == 'Y' || ent == 'y') {
			cout << "���Ű�� �Է����ּ���." << endl;
			cin >> opt;
			cout << endl;
			if (strcmp(pass, opt) == 0) {
				cout << "�޼����� ����մϴ�." << endl;
				for (unsigned int i = 0; i < b.size(); i++) {
					decrypt(b[i].getPassword());
					cout << "���̵�: " << b[i].getUsername() << endl << "�н�����: " << b[i].getPassword() << endl;
					if (b[i].message == "") {
						cout << "�޼��� ����� �����ϴ�." << endl << endl;
					}
					else {

						cout << b[i].message << endl << endl;

					}
				}
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�." << endl;
				break;
			}

		}
		else {
			break;
		}
	}
}
