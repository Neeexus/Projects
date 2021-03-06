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

	vector<User> users; //vector<User> 摹樹
	Management m;

	Root rootUser("root", "root"); // 瑞お 啗薑 嬴檜蛤 綠塵廓�� 摹樹

	users.push_back(rootUser); // 瑞お啗薑曖 寡翮 高擊 菴煎爾鹵




	do {
		
		cout << endl;
		cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;// 詭景 UI
		cout << "弛                                                                                              弛" << endl;
		cout << "弛				    褫 暮 擊  摹 鷗 п 輿 撮 蹂                                弛" << endl;
		cout << "弛					   1. 啗薑虜菟晦                                       弛" << endl;
		cout << "弛					   2. 煎斜檣                                           弛" << endl;
		cout << "弛					   3. 謙猿                                             弛" << endl;
		cout << "弛                                                                                              弛" << endl;
		cout << "弛                                                                                              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
		
		cout << "[3廓 �分� 僥濠蒂 殮溘ж腎賊 謙猿腌棲棻.]" << endl;
		cout << "[褫暮擊 摹鷗п 輿撮蹂]";
		cin >> option;
		string username = "";
		
		
		switch (option) {
			
		case 1: {
			bool exists = 1;
			bool user = 0;



			do {

				user = 1;

				cout << "================================================================================================================" << endl;
				cout << "啗薑殮溘: ";

				cin >> username; // 啗薑 儅撩 嫡朝 詭景

				try {
					if (m.verify(username, users)) { 
						exists = 0;
					}
				}
				catch (AlreadyExist &expn) { // 啗薑 檜嘐 襄營衛 蕨諼籀葬
					expn.ShowExceptionReason();
				}

			} while (exists == 1);

			string password = "";

			cout << "懍��殮溘: "; 

			cin >> password; //儅撩脹 啗薑曖 懍�� 殮溘
			
			cout << "================================================================================================================" << endl;
			User newUser(username, password); // 啗薑 薑爾 渠殮

			users.push_back(newUser);

			cout << endl << endl << "[啗薑檜 儅撩腎歷蝗棲棻.]" << endl << endl;
			cout << "================================================================================================================" << endl;
			cout << "嬴檜蛤: " << username << endl;
			cout << "ぬ蝶錶萄: " << password << endl;
			cout << "================================================================================================================" << endl << endl;


			break;
		}


		case 2: {
			string login_Password;
			string login_Username;
		id: 
			try {

				do { // 煎斜檣 詭景
					cout << endl<<endl<<"================================================================================================================" << endl;
					cout << "嬴檜蛤 殮溘: ";
					cin >> login_Username;
				} while (m.IDverify(login_Username, users)); 
			}
			catch (WrongAcException &expn) { // 嬴檜蛤陛 蜃朝雖 羹觼蒂 鱔п ぎ萵衛 蕨諼籀葬 嫦儅
				expn.ShowExceptionReason();
				goto id; //螃盟 詭撮雖 轎溘�� id煎 goto
			}
		pw:
			try {
				do {


					cout << "ぬ蝶錶萄 殮溘: "; // ぬ蝶錶萄 殮溘嫡朝 詭景
					cin >> login_Password; 
					cout <<  "================================================================================================================" << endl;

				} while (!m.passwordCheck(login_Password, login_Username, users));
			}
			catch (WrongPsException &expn) { //ぬ蝶錶萄陛 ぎ萵衛 蕨諼 籀葬 嫦儅
				expn.ShowExceptionReason();
				goto pw; //螃盟 詭撮雖 轎溘 �� pw煎 goto
			}
			User * currentUser = (login_Username == "root") ?
				new Root(login_Username, login_Password, users[m.getUserIndex(login_Username, users)].message) :
				new User(login_Username, login_Password, users[m.getUserIndex(login_Username, users)].message); //鳴о 翱骯濠蒂 鱔п Root檣雖 嬴棋雖蒂 っ滌
			int opt;

			if (login_Username != "root") { //Root陛 嬴棍衛 棻擠 詭景 轎溘

				do {
					cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
					cout << "弛                                                                                              弛" << endl;
					cout << "弛                                           詭   景                                            弛" << endl;
					cout << "弛	                              1. 詭 撮 雖 爾 頂 晦                                     弛" << endl;
					cout << "弛	                              2. 熱 褐 詭 撮 雖                                        弛" << endl;
					cout << "弛	                              3. 煎 斜 檣 ⑷ ��                                        弛" << endl;
					cout << "弛	                              4. 煎 斜 嬴 醒                                           弛" << endl;
					cout << "弛	                              5. ⑷ 營 啗 薑 餉 薯                                     弛" << endl;
					cout << "弛                                                                                              弛" << endl;
					cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;

					cin >> opt;

					switch (opt) {


					case 1: {
						string message;
						string messageUser;

						msg:
						try {	//詭撮雖 爾頂朝 詭景
							do {
								cout << "熱褐濠 嬴檜蛤 殮溘 : "; 
								cin >> messageUser;
							} while (m.IDverify(messageUser, users)); 
						}
						catch (WrongAcException &expn) { //嬴檜蛤陛 ぎ萵 衛 蕨諼 籀葬 嫦儅
							expn.ShowExceptionReason();
							goto msg; // 蕨諼 詭撮雖 轎溘 �� msg煎 goto
						}

						cout << "詭撮雖 殮溘: ";
						cin.ignore();
						getline(cin, message);

						if (messageUser == currentUser->getUsername()) { // 煎斜檣 �� 詭撮雖 �挫彖� 偽擎 嬴檜蛤賊 棻擠婁 偽擎 詭撮雖 轎溘
							currentUser->message = message + "\t 爾魚檜 : " + messageUser;
						}
						else {

							m.sendMessage(messageUser, message, users, currentUser); //詭撮雖 瞪歎
						}
						cout << endl << "詭撮雖 瞪歎脾." << endl;


						break;
					}
					case 2: {
						if (currentUser->message == "") { //詭撮雖陛 奢寥鼻鷓塭賊 棻擠婁 偽擎 詭撮雖 轎溘
							cout << endl << endl << "詭撮雖陛 橈蝗棲棻.\n";
						}
						else {
							
							cout << endl << endl << currentUser->message << endl;
						}


						break;
					}
					case 3: {

						m.printAllUsers(users); // 嶸盪菟曖 薑爾 轎溘
						break;

					}
					case 4: {
						break;
					}
					case 5: {
						users.erase(users.begin() + m.getUserIndex(login_Username, users)); //vector 縑憮 user曖 薑爾蒂 餉薯衛霽
						break;
					}


					default:
						cout << "詭景 煎斜醞 摹鷗ж撮蹂" << endl; 
						break;

					}



				} while (opt != 4 && opt != 5);
			}
			else if (login_Username == "root") { //嬴檜蛤縑 root蒂 纂啪腆衛 釭螃朝 �飛�

				do {

					cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
					cout << "弛                                                                                              弛" << endl;
					cout << "弛                                        婦 葬 濠 啗 薑 褫 暮                                  弛" << endl;
					cout << "弛                                                                                              弛" << endl;
					cout << "弛	                                  1. 詭 撮 雖 爾 頂 晦                                 弛" << endl;
					cout << "弛	                                  2. 熱 褐 詭 撮 雖                                    弛" << endl;
					cout << "弛	                                  3. 嶸 盪 跡 煙                                       弛" << endl;
					cout << "弛	                                  4. 啗 薑 餉 薯                                       弛" << endl;
					cout << "弛	                                  5. 煎 斜 嬴 醒                                       弛" << endl;
					cout << "弛                                                                                              弛" << endl;
					cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
					

					cin >> opt;

					switch (opt) {

					case 1: {
						msg1:
						string message;
						string messageUser;
						try {
							do {
								cout << "熱褐濠 嬴檜蛤 殮溘: ";
								cin >> messageUser; //詭撮雖 爾頂晦
							} while (m.IDverify(messageUser, users));
						}
						catch (WrongAcException &expn) {
							expn.ShowExceptionReason();
							goto msg1;
						}
						cout << "詭撮雖: ";
						cin.ignore();
						getline(cin, message);

						if (messageUser == currentUser->getUsername()) { 
							currentUser->message = message + "\t 爾魚檜 : " + messageUser;
						}
						else {

							m.sendMessage(messageUser, message, users, currentUser);
						}
						cout << endl << "詭撮雖 瞪歎脾." << endl;


						break;
					}
					case 2: {
						if (currentUser->message == "") {
							cout << endl << endl << "嫡擎 詭撮雖陛 橈蝗棲棻.\n";
						}
						else {
							cout << endl << endl << currentUser->message << endl;
						}


						break;
					}


					case 3: {
						m.printAllUsersInfo(users); //嶸盪菟曖 嬴檜蛤, 綠塵廓�� 詭撮雖 煎斜蒂 �挫恉� 熱 氈棻.
						break;
					}
					case 4: {
						er:
						string userToDelete = "";
						try {


							do {
								cout << "餉薯й 啗薑: "; //root啗薑縑憮 嬴檜蛤蒂 餉薯衛鑒熱氈棻.
								cin.ignore();
								getline(cin, userToDelete);
							} while (m.IDverify(userToDelete, users) || userToDelete == "root");
						}
						catch (WrongAcException &expn) { //嬴檜蛤陛 襄營ж雖 彊擊 衛 蕨諼籀葬陛 嫦儅и棻.
							expn.ShowExceptionReason();
							goto er; //蕨諼 詭撮雖蒂 爾罹輿堅 er煎 gotoи棻.
						}
							users.erase(users.begin() + m.getUserIndex(userToDelete, users));
							cout << endl << endl << userToDelete << "曖 啗薑檜 餉薯腎歷蝗棲棻." << endl << endl; //嬴檜蛤蒂 餉薯衛鑑棻.
						
						
					}

					}


				} while (opt != 5);

			}

			delete currentUser; // 模資濠 餌辨


			break;
		}

		case 3: {




			exit(0);
			break;
		}
				//			case 4:

		default: {
			
			cout << "螢夥艇 高擊 殮溘п輿撮蹂." << endl << endl; // 僥濠 �分� 棻艇 高擊 殮溘 й 衛 鬼薯 謙猿 衛鑑棻.(僥濠 高擊 殮溘ж賊 鼠и瑞Щ蒂 檜鼻ж啪 給晦陽僥縑 斜傖 謙猿衛麵鍍棻.
			exit(0);
			break;
		}
		}

	} while (option != 3);







	return 0;
}
