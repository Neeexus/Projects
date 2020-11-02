#include <iostream>
#include <string>
#include "User.h"

using namespace std;

User::User(){

	this->userName = "";
	this->passWord = "";
	this->message = "";

}


User:: User(string userName, string passWord){

	this->userName = userName;
	this->passWord = passWord;
	message = "";

}

User :: User(string userName, string passWord, string message){ //User �����ε�

	this->userName = userName;
	this->passWord = passWord;
	this->message = message;
}




void User::getMessage(){ //�޼����� ��½����ش�.

	cout << message << endl;
}

string User:: getUsername() const { //������ ���̵� ���Ͻ����ش�.

	return userName;
}

string User :: getPassword() const{	 //������ �н����带 ���Ͻ����ش�.

	return passWord;
}

User & User::operator=(const User & copy){ //������ �����ε��� ���� �����Ų��.

	this->userName = copy.getUsername();
	this->passWord = copy.getPassword();
	this->message = copy.message;

	return *this;


}

ostream & operator<<(ostream & lhs, User & rhs){ //������ �����ε��� ���� ������ ������ ���� ��½�Ų��.

			lhs << "���� ����" << endl
			<< "���̵�: "<< rhs.userName << endl
			<< "�н�����: "<< rhs.passWord << endl << "�޼���: ";
			if(rhs.message == ""){
			cout << "���� �޼����� �����ϴ�..";
			}
			else{
			cout << rhs.message;

			}
			return (cout << endl);
			
}
