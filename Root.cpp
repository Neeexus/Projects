#include <iostream>
#include <string>
#include "Root.h"


Root::Root(string username, string password): User(username, password){ //User Ŭ�����κ��� ��ӹ޴´�.

}

Root::Root(string username, string password, string message): User(username, password, message){ //User Ŭ�����κ��� message���� ��ӹ޴´�.

}

Root::~Root(){} //�Ҹ���



