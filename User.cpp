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

User :: User(string userName, string passWord, string message){ //User 오버로딩

	this->userName = userName;
	this->passWord = passWord;
	this->message = message;
}




void User::getMessage(){ //메세지를 출력시켜준다.

	cout << message << endl;
}

string User:: getUsername() const { //유저의 아이디를 리턴시켜준다.

	return userName;
}

string User :: getPassword() const{	 //유저의 패스워드를 리턴시켜준다.

	return passWord;
}

User & User::operator=(const User & copy){ //연산자 오버로딩을 통해 복사시킨다.

	this->userName = copy.getUsername();
	this->passWord = copy.getPassword();
	this->message = copy.message;

	return *this;


}

ostream & operator<<(ostream & lhs, User & rhs){ //연산자 오버로딩을 통해 재정의 다음과 같이 출력시킨다.

			lhs << "유저 정보" << endl
			<< "아이디: "<< rhs.userName << endl
			<< "패스워드: "<< rhs.passWord << endl << "메세지: ";
			if(rhs.message == ""){
			cout << "받은 메세지가 없습니다..";
			}
			else{
			cout << rhs.message;

			}
			return (cout << endl);
			
}
