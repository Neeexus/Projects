#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>


#include "User.h"
#include "Root.h"
#include "Exception.h"

class Management {
public:
	string encrypt(string a);  // 암호화를 위한 매소드
	string decrypt(string a); // 복호화를 위한 메소드

	bool verify(string a, vector<User> &  b) throw(AlreadyExist); //vector를 통해 아이디가 존재하는지 체크하는 메소드
	bool IDverify(string a, vector<User> &  b)throw(WrongAcException);  //vector를 통해 아이디가 맞는지 체크하는 메소드
	bool verify(string a, vector<User> &  b, int & index); //vector를 통해 index 값을 설정해주는 메소드
	void printAllUsers(vector<User> & a);  // 현재 로그인 중인 유저들의 정보 출력
	bool passwordCheck(string password, string username, vector<User> & b)throw(WrongPsException); // 패스워드가 올바른지 체크하는 메소드
	void sendMessage(string user, string messageTo, vector<User> & b, User * currUser);// 메세지를 전송시켜주는 메소드
	int getUserIndex(string user, vector<User> & b); //유저의 배열 값을 리턴시켜주는 메소드
	void printAllUsersInfo(vector <User> & b);// 관리자 계정에서 사용되는 유저의 관한 정보 출력
};