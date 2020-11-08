// ToDoListApp_CutieHack2020.cpp

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class tasks {
private:
	vector<string> theTasks;

public:

	tasks() {
		theTasks.push_back("");
	}

	void addTask(string toAdd) {
		theTasks.push_back(toAdd);
	}

	void printList() {
		for (int i = 0; i < theTasks.size(); i++) {
			cout << i + 1 << ". " << theTasks.at(i) << endl;
		}
	}

	void deleteTask(int num) {
		theTasks.erase(theTasks.begin() + (num - 1));
	}

	bool isEmpty() {
		if (theTasks.size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}

};

int main()
{
	vector<string> usernames;
	vector<string> passwords;

	vector<tasks*> list;


	bool isValidUser = false;
	int userIndex;

	cout << "\nWelcome to the To-Do List app!" << endl;

	string isAccount;
	cout << "Do you have an account?(yes/no)" << endl;
	cin >> isAccount;

	if (isAccount == "no" || "No" || "n") {
		cout << "Let's create you an account!" << endl;

		string nameOfUser;
		bool usernameExists = false;
		cout << "Enter a username you want below:" << endl;
		cin >> nameOfUser;

		if (usernames.size() >= 1) {
			for (int i = 0; i < usernames.size(); i++) {
				if (usernames.at(i) == nameOfUser) {
					usernameExists = true;
				}
			}
			while (usernameExists) {
				cout << "The username you typed already exists" << endl;
				cout << "Please enter another username you want below:" << endl;
				cin >> nameOfUser;
				for (int i = 0; i < usernames.size(); i++) {
					if (usernames.at(i) == nameOfUser) {
						usernameExists = true;
						break;
					}
					else {
						usernameExists = false;
					}
				}
			}
		}

		usernames.push_back(nameOfUser);

		string passwordOfUser;
		cout << "Type a password below(letters only): " << endl;
		cin >> passwordOfUser;
		passwords.push_back(passwordOfUser);

		cout << "\nYour account is created!\n" << endl;
		isValidUser = true;
		userIndex = usernames.size() - 1;
	}

	if (isAccount == "yes" || "Yes" || "y") {
		string enteredUsername;
		cout << "Enter your username below:" << endl;
		cin >> enteredUsername;

		string enteredPassword;
		cout << "Enter your password below:" << endl;
		cin >> enteredPassword;

		for (int i = 0; i < usernames.size(); i++) {
			if (usernames.at(i) == enteredUsername) {
				if (passwords.at(i) == enteredPassword) {
					isValidUser = true;
					userIndex = i;
				}
			}
		}

		/*for (int i = 0; i < usernames.size(); i++) {
			int count;
			if (usernames.at(i) != enteredUsername) {
				count++;
			}
			if (count == usernames.size()) {
				cout << "username doesn't exist." << endl;
			}
		}*/
	}

	while (isValidUser) {
		cout << "\nYou are successfully signed into your account!\n" << endl;

		cout << "You can type the following commands shown below\n" << endl;
		cout << "addtask: To add a task to your to-do list" << endl;
		cout << "viewtasks: To print out your to-do list" << endl;
		cout << "removetask: To remove a task" << endl;
		cout << "logout: To log out of your account" << endl;
		cout << "closeapplication: To exit the program" << endl;
		cout << "seecommands: To see these commands again\n" << endl;

		string commandEntered;
		cout << "Enter a command (all lowercase): " << endl;
		cin >> commandEntered;

		list.at(userIndex) = new tasks();

		while (true) {
			if (commandEntered == "addtask") {
				string enteredTask;
				cout << "Enter the task you want to do: " << endl;
				cin >> enteredTask;
				list.at(userIndex)->addTask(enteredTask);

			}

			else if (commandEntered == "viewtasks") {
				if (list.at(userIndex)->isEmpty()) {
					cout << "Your to-do list is empty" << endl;
					cout << "Begin by using the 'add task' command" << endl;
				}
				else {
					list.at(userIndex)->printList();
				}

			}

			else if (commandEntered == "removetask") {
				int taskToRemove;
				cout << "Enter the # of the task you want to remove: " << endl;
				cin >> taskToRemove;

				list.at(userIndex)->deleteTask(taskToRemove);
			}

			else if (commandEntered == "logout") {

			}

			else if (commandEntered == "closeapplication") {
				exit(0);
			}

			else if (commandEntered == "seecommands") {
				cout << "You can type the following commands below" << endl;
				cout << "addtask: To add a task to your to-do list" << endl;
				cout << "viewtasks: To print out your to-do list" << endl;
				cout << "removetask: To remove a task" << endl;
				cout << "logout: To log out of your account" << endl;
				cout << "closeapplication: To exit the program" << endl;
				cout << "seecommands: To see these commands again\n" << endl;
			}

			else {
				cout << "Invalid command. Enter a valid command and make sure it's in lowercase" << endl;
			}

			cout << "Enter a command: " << endl;
			cin >> commandEntered;
		}

	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
