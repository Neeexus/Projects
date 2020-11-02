#include<iostream>
#include<string>
#pragma once
#pragma warning(disable : 4996)
class Exception {
public:
	virtual void ShowExceptionReason()=0; //virtual void를 통해 메모리 공간 효율적 확보

};
class AlreadyExist :public Exception {
	std::string Account;
public :
	AlreadyExist(std::string ac);
	void ShowExceptionReason();
};
class WrongAcException :public Exception {
private:
	std::string Account;
public:
	WrongAcException(std::string ac);
	void ShowExceptionReason();
};
class WrongPsException :public Exception {
private:
	std::string Password;
public:
	WrongPsException(std::string ps);
	void ShowExceptionReason();
};