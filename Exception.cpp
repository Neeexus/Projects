#include <iostream>
#include<string>
#include "Exception.h"
#pragma warning(disable : 4996)
using namespace std;

void Exception::ShowExceptionReason() { //class Exception ����
	
}


void WrongPsException::ShowExceptionReason() { //ShowExceptionReason ������
	cout << "[�н����尡 �ùٸ��� �ʽ��ϴ�.]" << endl;
}
void WrongAcException::ShowExceptionReason()//ShowExceptionReason ������
{
	cout << "[���̵� : " << Account << "(��)�� ���� ���� �ʴ� ���̵��Դϴ�.]" << endl;
}
void AlreadyExist::ShowExceptionReason()//ShowExceptionReasong ������
{
	cout << "[���̵� : " << Account << "(��)�� �̹� ��� ���� �����Դϴ�.]" << endl;
}
WrongAcException::WrongAcException(std::string ac) :Account(ac){} 
WrongPsException::WrongPsException(std::string ps) :Password(ps){}
AlreadyExist::AlreadyExist(std::string ac):Account(ac){}
//���� ���� ���Խ����ش�.

