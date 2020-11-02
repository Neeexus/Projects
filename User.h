#include <iostream>
#include <string>

#ifndef USER_H
#define USER_H

using namespace std;

class User{
	private: 
		string userName ;
		string passWord ;
		
	public:
		User();

		User(std::string, std::string);

		User(std::string, std::string, std::string);


		string message ;

		void getMessage();

		string getUsername() const;

		string getPassword() const;

		User & operator=(const User &);

		friend ostream & operator<<(ostream &, User &);


};

#endif
