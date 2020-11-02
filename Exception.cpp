#include <iostream>
#include<string>
#include "Exception.h"
#pragma warning(disable : 4996)
using namespace std;

void Exception::ShowExceptionReason() { //class Exception 정의
	
}


void WrongPsException::ShowExceptionReason() { //ShowExceptionReason 재정의
	cout << "[패스워드가 올바르지 않습니다.]" << endl;
}
void WrongAcException::ShowExceptionReason()//ShowExceptionReason 재정의
{
	cout << "[아이디 : " << Account << "(가)는 존재 하지 않는 아이디입니다.]" << endl;
}
void AlreadyExist::ShowExceptionReason()//ShowExceptionReasong 재정의
{
	cout << "[아이디 : " << Account << "(가)는 이미 사용 중인 계정입니다.]" << endl;
}
WrongAcException::WrongAcException(std::string ac) :Account(ac){} 
WrongPsException::WrongPsException(std::string ps) :Password(ps){}
AlreadyExist::AlreadyExist(std::string ac):Account(ac){}
//각각 값을 대입시켜준다.

