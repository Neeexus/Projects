#include <iostream>
#include <string>
#include "Root.h"


Root::Root(string username, string password): User(username, password){ //User 클래스로부터 상속받는다.

}

Root::Root(string username, string password, string message): User(username, password, message){ //User 클래스로부터 message까지 상속받는다.

}

Root::~Root(){} //소멸자



