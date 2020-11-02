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
string Management::encrypt(string a) { // 암호화를 위한 매소드

	for (unsigned int i = 0; i < a.length(); i++) {
		a[i] = a[i] + 127;
	}
	return a;

}

string Management:: decrypt(string a) { // 복호화를 위한 메소드
	for (unsigned int i = 0; i < a.length(); i++) {
		a[i] = a[i] - 127;
	}

	return a;
}

bool Management::verify(string a, vector<User> &  b) throw(AlreadyExist) {  //vector를 통해 아이디가 존재하는지 체크하는 메소드

	for (unsigned int i = 0; i < b.size(); i++) {

		if (a == b[i].getUsername()) {
			AlreadyExist expn(a);
			throw expn;
			return false;
		}


	}

	return true;
}

bool Management::IDverify(string a, vector<User> &  b)throw(WrongAcException) { //vector를 통해 아이디가 맞는지 체크하는 메소드

	for (unsigned int i = 0; i < b.size(); i++) {

		if (a == b[i].getUsername()) {

			return false;
		}

	}

	WrongAcException expn(a);
	throw  expn;
	return true;
}

bool Management::verify(string a, vector<User> &  b, int & index) { //vector를 통해 index 값을 설정해주는 메소드

	for (unsigned int i = 0; i < b.size(); i++) {

		if (a == b[i].getUsername()) {
			index = i;
			return false;
		}
	}


	return true;
}


void Management::printAllUsers(vector<User> & a) { // 현재 로그인 중인 유저들의 정보 출력

	cout << endl << "로그인 현황 :" << endl;

	for (unsigned int i = 0; i < a.size(); i++) {
		if (a[i].getUsername() != "root") {
			cout << a[i].getUsername() << endl;
		}

	}
}


bool Management::passwordCheck(string password, string username, vector<User> & b)throw(WrongPsException) { // 패스워드가 올바른지 체크하는 메소드
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

void Management::sendMessage(string user, string messageTo, vector<User> & b, User * currUser) { // 메세지를 전송시켜주는 메소드
	int index;
	if (!verify(user, b, index)) {

		b[index].message = messageTo + "\t 보낸이 : " + currUser->getUsername();
	}
}

int Management::getUserIndex(string user, vector<User> & b) {  //유저의 배열 값을 리턴시켜주는 메소드
	for (unsigned int i = 0; i < b.size(); i++) {
		if (user == b[i].getUsername()) {
			return i;
		}
	}
	return -1;
}

void Management::printAllUsersInfo(vector <User> & b) { // 관리자 계정에서 사용되는 유저의 관한 정보 출력
	char pass[50] = "C++pro"; // 열람 키 암호
	char opt[50];
	char ent;

	for (unsigned int i = 0; i < b.size(); i++) {
		encrypt(b[i].getPassword());

		cout << "아이디: " << b[i].getUsername() << endl << "패스워드: " << encrypt(b[i].getPassword()) << endl;
		if (b[i].message == "") {
			cout << "메세지 기록이 없습니다.\n\n";
		}
		else {

			cout << encrypt(b[i].message) << endl << endl;
		}
	}
	cout << endl << endl;
	cout << "메세지는 및 패스워드는 암호화 되어있습니다." << endl;
	cout << "열람하시려면 비밀키를 입력해주세요." << endl << endl;
	cout << "열람하시겠습니까?(Y/N)" << endl;
	cin >> ent;
	while (1) {
		if (ent == 'Y' || ent == 'y') {
			cout << "비밀키를 입력해주세요." << endl;
			cin >> opt;
			cout << endl;
			if (strcmp(pass, opt) == 0) {
				cout << "메세지를 출력합니다." << endl;
				for (unsigned int i = 0; i < b.size(); i++) {
					decrypt(b[i].getPassword());
					cout << "아이디: " << b[i].getUsername() << endl << "패스워드: " << b[i].getPassword() << endl;
					if (b[i].message == "") {
						cout << "메세지 기록이 없습니다." << endl << endl;
					}
					else {

						cout << b[i].message << endl << endl;

					}
				}
				break;
			}
			else {
				cout << "틀렸습니다." << endl;
				break;
			}

		}
		else {
			break;
		}
	}
}
