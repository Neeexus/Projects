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
	string encrypt(string a);  // ��ȣȭ�� ���� �żҵ�
	string decrypt(string a); // ��ȣȭ�� ���� �޼ҵ�

	bool verify(string a, vector<User> &  b) throw(AlreadyExist); //vector�� ���� ���̵� �����ϴ��� üũ�ϴ� �޼ҵ�
	bool IDverify(string a, vector<User> &  b)throw(WrongAcException);  //vector�� ���� ���̵� �´��� üũ�ϴ� �޼ҵ�
	bool verify(string a, vector<User> &  b, int & index); //vector�� ���� index ���� �������ִ� �޼ҵ�
	void printAllUsers(vector<User> & a);  // ���� �α��� ���� �������� ���� ���
	bool passwordCheck(string password, string username, vector<User> & b)throw(WrongPsException); // �н����尡 �ùٸ��� üũ�ϴ� �޼ҵ�
	void sendMessage(string user, string messageTo, vector<User> & b, User * currUser);// �޼����� ���۽����ִ� �޼ҵ�
	int getUserIndex(string user, vector<User> & b); //������ �迭 ���� ���Ͻ����ִ� �޼ҵ�
	void printAllUsersInfo(vector <User> & b);// ������ �������� ���Ǵ� ������ ���� ���� ���
};