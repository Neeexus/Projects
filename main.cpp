#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>


#include "User.h"
#include "Root.h"
#include "Exception.h"
#include "Management.h"

using namespace std;
#pragma warning(disable : 4996)


int main() {


	int option;

	vector<User> users; //vector<User> ¼±¾ð
	Management m;

	Root rootUser("root", "root"); // ·çÆ® °èÁ¤ ¾ÆÀÌµð ºñ¹Ð¹øÈ£ ¼±¾ð

	users.push_back(rootUser); // ·çÆ®°èÁ¤ÀÇ ¹è¿­ °ªÀ» µÚ·Îº¸³¿




	do {
		
		cout << endl;
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;// ¸Þ´º UI
		cout << "¦¢                                                                                              ¦¢" << endl;
		cout << "¦¢				    ¿É ¼Ç À»  ¼± ÅÃ ÇØ ÁÖ ¼¼ ¿ä                                ¦¢" << endl;
		cout << "¦¢					   1. °èÁ¤¸¸µé±â                                       ¦¢" << endl;
		cout << "¦¢					   2. ·Î±×ÀÎ                                           ¦¢" << endl;
		cout << "¦¢					   3. Á¾·á                                             ¦¢" << endl;
		cout << "¦¢                                                                                              ¦¢" << endl;
		cout << "¦¢                                                                                              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		
		cout << "[3¹ø È¤Àº ¹®ÀÚ¸¦ ÀÔ·ÂÇÏµÇ¸é Á¾·áµË´Ï´Ù.]" << endl;
		cout << "[¿É¼ÇÀ» ¼±ÅÃÇØ ÁÖ¼¼¿ä]";
		cin >> option;
		string username = "";
		
		
		switch (option) {
			
		case 1: {
			bool exists = 1;
			bool user = 0;



			do {

				user = 1;

				cout << "================================================================================================================" << endl;
				cout << "°èÁ¤ÀÔ·Â: ";

				cin >> username; // °èÁ¤ »ý¼º ¹Þ´Â ¸Þ´º

				try {
					if (m.verify(username, users)) { 
						exists = 0;
					}
				}
				catch (AlreadyExist &expn) { // °èÁ¤ ÀÌ¹Ì Á¸Àç½Ã ¿¹¿ÜÃ³¸®
					expn.ShowExceptionReason();
				}

			} while (exists == 1);

			string password = "";

			cout << "¾ÏÈ£ÀÔ·Â: "; 

			cin >> password; //»ý¼ºµÈ °èÁ¤ÀÇ ¾ÏÈ£ ÀÔ·Â
			
			cout << "================================================================================================================" << endl;
			User newUser(username, password); // °èÁ¤ Á¤º¸ ´ëÀÔ

			users.push_back(newUser);

			cout << endl << endl << "[°èÁ¤ÀÌ »ý¼ºµÇ¾ú½À´Ï´Ù.]" << endl << endl;
			cout << "================================================================================================================" << endl;
			cout << "¾ÆÀÌµð: " << username << endl;
			cout << "ÆÐ½º¿öµå: " << password << endl;
			cout << "================================================================================================================" << endl << endl;


			break;
		}


		case 2: {
			string login_Password;
			string login_Username;
		id: 
			try {

				do { // ·Î±×ÀÎ ¸Þ´º
					cout << endl<<endl<<"================================================================================================================" << endl;
					cout << "¾ÆÀÌµð ÀÔ·Â: ";
					cin >> login_Username;
				} while (m.IDverify(login_Username, users)); 
			}
			catch (WrongAcException &expn) { // ¾ÆÀÌµð°¡ ¸Â´ÂÁö Ã¼Å©¸¦ ÅëÇØ Æ²¸±½Ã ¿¹¿ÜÃ³¸® ¹ß»ý
				expn.ShowExceptionReason();
				goto id; //¿À·ù ¸Þ¼¼Áö Ãâ·ÂÈÄ id·Î goto
			}
		pw:
			try {
				do {


					cout << "ÆÐ½º¿öµå ÀÔ·Â: "; // ÆÐ½º¿öµå ÀÔ·Â¹Þ´Â ¸Þ´º
					cin >> login_Password; 
					cout <<  "================================================================================================================" << endl;

				} while (!m.passwordCheck(login_Password, login_Username, users));
			}
			catch (WrongPsException &expn) { //ÆÐ½º¿öµå°¡ Æ²¸±½Ã ¿¹¿Ü Ã³¸® ¹ß»ý
				expn.ShowExceptionReason();
				goto pw; //¿À·ù ¸Þ¼¼Áö Ãâ·Â ÈÄ pw·Î goto
			}
			User * currentUser = (login_Username == "root") ?
				new Root(login_Username, login_Password, users[m.getUserIndex(login_Username, users)].message) :
				new User(login_Username, login_Password, users[m.getUserIndex(login_Username, users)].message); //»ïÇ× ¿¬»êÀÚ¸¦ ÅëÇØ RootÀÎÁö ¾Æ´ÑÁö¸¦ ÆÇº°
			int opt;

			if (login_Username != "root") { //Root°¡ ¾Æ´Ò½Ã ´ÙÀ½ ¸Þ´º Ãâ·Â

				do {
					cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
					cout << "¦¢                                                                                              ¦¢" << endl;
					cout << "¦¢                                           ¸Þ   ´º                                            ¦¢" << endl;
					cout << "¦¢	                              1. ¸Þ ¼¼ Áö º¸ ³» ±â                                     ¦¢" << endl;
					cout << "¦¢	                              2. ¼ö ½Å ¸Þ ¼¼ Áö                                        ¦¢" << endl;
					cout << "¦¢	                              3. ·Î ±× ÀÎ Çö È²                                        ¦¢" << endl;
					cout << "¦¢	                              4. ·Î ±× ¾Æ ¿ô                                           ¦¢" << endl;
					cout << "¦¢	                              5. Çö Àç °è Á¤ »è Á¦                                     ¦¢" << endl;
					cout << "¦¢                                                                                              ¦¢" << endl;
					cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;

					cin >> opt;

					switch (opt) {


					case 1: {
						string message;
						string messageUser;

						msg:
						try {	//¸Þ¼¼Áö º¸³»´Â ¸Þ´º
							do {
								cout << "¼ö½ÅÀÚ ¾ÆÀÌµð ÀÔ·Â : "; 
								cin >> messageUser;
							} while (m.IDverify(messageUser, users)); 
						}
						catch (WrongAcException &expn) { //¾ÆÀÌµð°¡ Æ²¸± ½Ã ¿¹¿Ü Ã³¸® ¹ß»ý
							expn.ShowExceptionReason();
							goto msg; // ¿¹¿Ü ¸Þ¼¼Áö Ãâ·Â ÈÄ msg·Î goto
						}

						cout << "¸Þ¼¼Áö ÀÔ·Â: ";
						cin.ignore();
						getline(cin, message);

						if (messageUser == currentUser->getUsername()) { // ·Î±×ÀÎ ÈÄ ¸Þ¼¼Áö È®ÀÎ½Ã °°Àº ¾ÆÀÌµð¸é ´ÙÀ½°ú °°Àº ¸Þ¼¼Áö Ãâ·Â
							currentUser->message = message + "\t º¸³½ÀÌ : " + messageUser;
						}
						else {

							m.sendMessage(messageUser, message, users, currentUser); //¸Þ¼¼Áö Àü¼Û
						}
						cout << endl << "¸Þ¼¼Áö Àü¼ÛµÊ." << endl;


						break;
					}
					case 2: {
						if (currentUser->message == "") { //¸Þ¼¼Áö°¡ °ø¹é»óÅÂ¶ó¸é ´ÙÀ½°ú °°Àº ¸Þ¼¼Áö Ãâ·Â
							cout << endl << endl << "¸Þ¼¼Áö°¡ ¾ø½À´Ï´Ù.\n";
						}
						else {
							
							cout << endl << endl << currentUser->message << endl;
						}


						break;
					}
					case 3: {

						m.printAllUsers(users); // À¯ÀúµéÀÇ Á¤º¸ Ãâ·Â
						break;

					}
					case 4: {
						break;
					}
					case 5: {
						users.erase(users.begin() + m.getUserIndex(login_Username, users)); //vector ¿¡¼­ userÀÇ Á¤º¸¸¦ »èÁ¦½ÃÅ´
						break;
					}


					default:
						cout << "¸Þ´º ·Î±×Áß ¼±ÅÃÇÏ¼¼¿ä" << endl; 
						break;

					}



				} while (opt != 4 && opt != 5);
			}
			else if (login_Username == "root") { //¾ÆÀÌµð¿¡ root¸¦ Ä¡°ÔµÉ½Ã ³ª¿À´Â È­¸é

				do {

					cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
					cout << "¦¢                                                                                              ¦¢" << endl;
					cout << "¦¢                                        °ü ¸® ÀÚ °è Á¤ ¿É ¼Ç                                  ¦¢" << endl;
					cout << "¦¢                                                                                              ¦¢" << endl;
					cout << "¦¢	                                  1. ¸Þ ¼¼ Áö º¸ ³» ±â                                 ¦¢" << endl;
					cout << "¦¢	                                  2. ¼ö ½Å ¸Þ ¼¼ Áö                                    ¦¢" << endl;
					cout << "¦¢	                                  3. À¯ Àú ¸ñ ·Ï                                       ¦¢" << endl;
					cout << "¦¢	                                  4. °è Á¤ »è Á¦                                       ¦¢" << endl;
					cout << "¦¢	                                  5. ·Î ±× ¾Æ ¿ô                                       ¦¢" << endl;
					cout << "¦¢                                                                                              ¦¢" << endl;
					cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
					

					cin >> opt;

					switch (opt) {

					case 1: {
						msg1:
						string message;
						string messageUser;
						try {
							do {
								cout << "¼ö½ÅÀÚ ¾ÆÀÌµð ÀÔ·Â: ";
								cin >> messageUser; //¸Þ¼¼Áö º¸³»±â
							} while (m.IDverify(messageUser, users));
						}
						catch (WrongAcException &expn) {
							expn.ShowExceptionReason();
							goto msg1;
						}
						cout << "¸Þ¼¼Áö: ";
						cin.ignore();
						getline(cin, message);

						if (messageUser == currentUser->getUsername()) { 
							currentUser->message = message + "\t º¸³½ÀÌ : " + messageUser;
						}
						else {

							m.sendMessage(messageUser, message, users, currentUser);
						}
						cout << endl << "¸Þ¼¼Áö Àü¼ÛµÊ." << endl;


						break;
					}
					case 2: {
						if (currentUser->message == "") {
							cout << endl << endl << "¹ÞÀº ¸Þ¼¼Áö°¡ ¾ø½À´Ï´Ù.\n";
						}
						else {
							cout << endl << endl << currentUser->message << endl;
						}


						break;
					}


					case 3: {
						m.printAllUsersInfo(users); //À¯ÀúµéÀÇ ¾ÆÀÌµð, ºñ¹Ð¹øÈ£ ¸Þ¼¼Áö ·Î±×¸¦ È®ÀÎÇÒ ¼ö ÀÖ´Ù.
						break;
					}
					case 4: {
						er:
						string userToDelete = "";
						try {


							do {
								cout << "»èÁ¦ÇÒ °èÁ¤: "; //root°èÁ¤¿¡¼­ ¾ÆÀÌµð¸¦ »èÁ¦½ÃÅ³¼öÀÖ´Ù.
								cin.ignore();
								getline(cin, userToDelete);
							} while (m.IDverify(userToDelete, users) || userToDelete == "root");
						}
						catch (WrongAcException &expn) { //¾ÆÀÌµð°¡ Á¸ÀçÇÏÁö ¾ÊÀ» ½Ã ¿¹¿ÜÃ³¸®°¡ ¹ß»ýÇÑ´Ù.
							expn.ShowExceptionReason();
							goto er; //¿¹¿Ü ¸Þ¼¼Áö¸¦ º¸¿©ÁÖ°í er·Î gotoÇÑ´Ù.
						}
							users.erase(users.begin() + m.getUserIndex(userToDelete, users));
							cout << endl << endl << userToDelete << "ÀÇ °èÁ¤ÀÌ »èÁ¦µÇ¾ú½À´Ï´Ù." << endl << endl; //¾ÆÀÌµð¸¦ »èÁ¦½ÃÅ²´Ù.
						
						
					}

					}


				} while (opt != 5);

			}

			delete currentUser; // ¼Ò¸êÀÚ »ç¿ë


			break;
		}

		case 3: {




			exit(0);
			break;
		}
				//			case 4:

		default: {
			
			cout << "¿Ã¹Ù¸¥ °ªÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä." << endl << endl; // ¹®ÀÚ È¤Àº ´Ù¸¥ °ªÀ» ÀÔ·Â ÇÒ ½Ã °­Á¦ Á¾·á ½ÃÅ²´Ù.(¹®ÀÚ °ªÀ» ÀÔ·ÂÇÏ¸é ¹«ÇÑ·çÇÁ¸¦ ÀÌ»óÇÏ°Ô µ¹±â¶§¹®¿¡ ±×³É Á¾·á½ÃÄÑÁá´Ù.
			exit(0);
			break;
		}
		}

	} while (option != 3);







	return 0;
}
