#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include "UserList.h"
#include "User.h"
#include "Message.h"

using namespace std;

void showMenu() {
    cout << "Chat Application Menu:" << endl;
    cout << "1. Add New User" << endl;
    cout << "2. Send Message" << endl;
    cout << "3. View Chat History" << endl;
    cout << "4. Show All Users" << endl;
    cout << "5. Exit" << endl;
    cout << "Please enter your choice: ";
}

void addNewUser(UserList &userList) {
    userList.addNewUser();
}

void sendMessage(UserList &userList) {
    string senderName, receiverName, messageContent;

    cout << "Enter sender's username: ";
    cin >> senderName;
    cout << "Enter receiver's username: ";
    cin >> receiverName;
    cout << "Enter the message: ";
    cin.ignore(); 
    getline(cin, messageContent);

    User* sender = userList.findUserByName(senderName);
    User* receiver = userList.findUserByName(receiverName);

    if (sender && receiver) {
        Message newMessage(senderName, receiverName, messageContent);
        sender->sendMessageToUser(*receiver, messageContent);
    } else {
        cout << "User(s) not found!" << endl;
    }
}

void viewChatHistory(UserList &userList) {
    string userName;
    cout << "Enter the username to view chat history: ";
    cin >> userName;
    userList.printChatHistory(userName);
}

void showAllUsers(UserList &userList) {
    userList.displayUsers();
}

int main() {
    srand(time(0)); 
    UserList userList;
    userList.loadUsersFromFile("User.txt");
    userList.loadMessagesFromFile("ChatHistory.txt");

    int choice = 0;
    
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addNewUser(userList);
                userList.saveUsersToFile("User.txt"); 
                break;
            case 2:
                sendMessage(userList);
                break;
            case 3:
                viewChatHistory(userList);
                break;
            case 4:
                showAllUsers(userList);
                break;
            case 5:
                cout << "Exiting Chat Application." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
