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

	vector<User> users; //vector<User> ����
	Management m;

	Root rootUser("root", "root"); // ��Ʈ ���� ���̵� ��й�ȣ ����

	users.push_back(rootUser); // ��Ʈ������ �迭 ���� �ڷκ���




	do {
		
		cout << endl;
		cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;// �޴� UI
		cout << "��                                                                                              ��" << endl;
		cout << "��				    �� �� ��  �� �� �� �� �� ��                                ��" << endl;
		cout << "��					   1. ���������                                       ��" << endl;
		cout << "��					   2. �α���                                           ��" << endl;
		cout << "��					   3. ����                                             ��" << endl;
		cout << "��                                                                                              ��" << endl;
		cout << "��                                                                                              ��" << endl;
		cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
		
		cout << "[3�� Ȥ�� ���ڸ� �Է��ϵǸ� ����˴ϴ�.]" << endl;
		cout << "[�ɼ��� ������ �ּ���]";
		cin >> option;
		string username = "";
		
		
		switch (option) {
			
		case 1: {
			bool exists = 1;
			bool user = 0;



			do {

				user = 1;

				cout << "================================================================================================================" << endl;
				cout << "�����Է�: ";

				cin >> username; // ���� ���� �޴� �޴�

				try {
					if (m.verify(username, users)) { 
						exists = 0;
					}
				}
				catch (AlreadyExist &expn) { // ���� �̹� ����� ����ó��
					expn.ShowExceptionReason();
				}

			} while (exists == 1);

			string password = "";

			cout << "��ȣ�Է�: "; 

			cin >> password; //������ ������ ��ȣ �Է�
			
			cout << "================================================================================================================" << endl;
			User newUser(username, password); // ���� ���� ����

			users.push_back(newUser);

			cout << endl << endl << "[������ �����Ǿ����ϴ�.]" << endl << endl;
			cout << "================================================================================================================" << endl;
			cout << "���̵�: " << username << endl;
			cout << "�н�����: " << password << endl;
			cout << "================================================================================================================" << endl << endl;


			break;
		}


		case 2: {
			string login_Password;
			string login_Username;
		id: 
			try {

				do { // �α��� �޴�
					cout << endl<<endl<<"================================================================================================================" << endl;
					cout << "���̵� �Է�: ";
					cin >> login_Username;
				} while (m.IDverify(login_Username, users)); 
			}
			catch (WrongAcException &expn) { // ���̵� �´��� üũ�� ���� Ʋ���� ����ó�� �߻�
				expn.ShowExceptionReason();
				goto id; //���� �޼��� ����� id�� goto
			}
		pw:
			try {
				do {


					cout << "�н����� �Է�: "; // �н����� �Է¹޴� �޴�
					cin >> login_Password; 
					cout <<  "================================================================================================================" << endl;

				} while (!m.passwordCheck(login_Password, login_Username, users));
			}
			catch (WrongPsException &expn) { //�н����尡 Ʋ���� ���� ó�� �߻�
				expn.ShowExceptionReason();
				goto pw; //���� �޼��� ��� �� pw�� goto
			}
			User * currentUser = (login_Username == "root") ?
				new Root(login_Username, login_Password, users[m.getUserIndex(login_Username, users)].message) :
				new User(login_Username, login_Password, users[m.getUserIndex(login_Username, users)].message); //���� �����ڸ� ���� Root���� �ƴ����� �Ǻ�
			int opt;

			if (login_Username != "root") { //Root�� �ƴҽ� ���� �޴� ���

				do {
					cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
					cout << "��                                                                                              ��" << endl;
					cout << "��                                           ��   ��                                            ��" << endl;
					cout << "��	                              1. �� �� �� �� �� ��                                     ��" << endl;
					cout << "��	                              2. �� �� �� �� ��                                        ��" << endl;
					cout << "��	                              3. �� �� �� �� Ȳ                                        ��" << endl;
					cout << "��	                              4. �� �� �� ��                                           ��" << endl;
					cout << "��	                              5. �� �� �� �� �� ��                                     ��" << endl;
					cout << "��                                                                                              ��" << endl;
					cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;

					cin >> opt;

					switch (opt) {


					case 1: {
						string message;
						string messageUser;

						msg:
						try {	//�޼��� ������ �޴�
							do {
								cout << "������ ���̵� �Է� : "; 
								cin >> messageUser;
							} while (m.IDverify(messageUser, users)); 
						}
						catch (WrongAcException &expn) { //���̵� Ʋ�� �� ���� ó�� �߻�
							expn.ShowExceptionReason();
							goto msg; // ���� �޼��� ��� �� msg�� goto
						}

						cout << "�޼��� �Է�: ";
						cin.ignore();
						getline(cin, message);

						if (messageUser == currentUser->getUsername()) { // �α��� �� �޼��� Ȯ�ν� ���� ���̵�� ������ ���� �޼��� ���
							currentUser->message = message + "\t ������ : " + messageUser;
						}
						else {

							m.sendMessage(messageUser, message, users, currentUser); //�޼��� ����
						}
						cout << endl << "�޼��� ���۵�." << endl;


						break;
					}
					case 2: {
						if (currentUser->message == "") { //�޼����� ������¶�� ������ ���� �޼��� ���
							cout << endl << endl << "�޼����� �����ϴ�.\n";
						}
						else {
							
							cout << endl << endl << currentUser->message << endl;
						}


						break;
					}
					case 3: {

						m.printAllUsers(users); // �������� ���� ���
						break;

					}
					case 4: {
						break;
					}
					case 5: {
						users.erase(users.begin() + m.getUserIndex(login_Username, users)); //vector ���� user�� ������ ������Ŵ
						break;
					}


					default:
						cout << "�޴� �α��� �����ϼ���" << endl; 
						break;

					}



				} while (opt != 4 && opt != 5);
			}
			else if (login_Username == "root") { //���̵� root�� ġ�Եɽ� ������ ȭ��

				do {

					cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
					cout << "��                                                                                              ��" << endl;
					cout << "��                                        �� �� �� �� �� �� ��                                  ��" << endl;
					cout << "��                                                                                              ��" << endl;
					cout << "��	                                  1. �� �� �� �� �� ��                                 ��" << endl;
					cout << "��	                                  2. �� �� �� �� ��                                    ��" << endl;
					cout << "��	                                  3. �� �� �� ��                                       ��" << endl;
					cout << "��	                                  4. �� �� �� ��                                       ��" << endl;
					cout << "��	                                  5. �� �� �� ��                                       ��" << endl;
					cout << "��                                                                                              ��" << endl;
					cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
					

					cin >> opt;

					switch (opt) {

					case 1: {
						msg1:
						string message;
						string messageUser;
						try {
							do {
								cout << "������ ���̵� �Է�: ";
								cin >> messageUser; //�޼��� ������
							} while (m.IDverify(messageUser, users));
						}
						catch (WrongAcException &expn) {
							expn.ShowExceptionReason();
							goto msg1;
						}
						cout << "�޼���: ";
						cin.ignore();
						getline(cin, message);

						if (messageUser == currentUser->getUsername()) { 
							currentUser->message = message + "\t ������ : " + messageUser;
						}
						else {

							m.sendMessage(messageUser, message, users, currentUser);
						}
						cout << endl << "�޼��� ���۵�." << endl;


						break;
					}
					case 2: {
						if (currentUser->message == "") {
							cout << endl << endl << "���� �޼����� �����ϴ�.\n";
						}
						else {
							cout << endl << endl << currentUser->message << endl;
						}


						break;
					}


					case 3: {
						m.printAllUsersInfo(users); //�������� ���̵�, ��й�ȣ �޼��� �α׸� Ȯ���� �� �ִ�.
						break;
					}
					case 4: {
						er:
						string userToDelete = "";
						try {


							do {
								cout << "������ ����: "; //root�������� ���̵� ������ų���ִ�.
								cin.ignore();
								getline(cin, userToDelete);
							} while (m.IDverify(userToDelete, users) || userToDelete == "root");
						}
						catch (WrongAcException &expn) { //���̵� �������� ���� �� ����ó���� �߻��Ѵ�.
							expn.ShowExceptionReason();
							goto er; //���� �޼����� �����ְ� er�� goto�Ѵ�.
						}
							users.erase(users.begin() + m.getUserIndex(userToDelete, users));
							cout << endl << endl << userToDelete << "�� ������ �����Ǿ����ϴ�." << endl << endl; //���̵� ������Ų��.
						
						
					}

					}


				} while (opt != 5);

			}

			delete currentUser; // �Ҹ��� ���


			break;
		}

		case 3: {




			exit(0);
			break;
		}
				//			case 4:

		default: {
			
			cout << "�ùٸ� ���� �Է����ּ���." << endl << endl; // ���� Ȥ�� �ٸ� ���� �Է� �� �� ���� ���� ��Ų��.(���� ���� �Է��ϸ� ���ѷ����� �̻��ϰ� ���⶧���� �׳� ����������.
			exit(0);
			break;
		}
		}

	} while (option != 3);







	return 0;
}
