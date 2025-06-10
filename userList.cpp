#include "UserList.h"
#include <fstream>
#include <iostream>

UserList::UserList() : head(nullptr) {}

UserList::~UserList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current->user; // Free user object
        delete current;       // Free node object
        current = nextNode;
    }
}

void UserList::insertUserAtHead(const User& newUser) {
    Node* newNode = new Node;
    newNode->user = new User(newUser); // deep copy
    newNode->next = head;
    head = newNode;
}


void UserList::displayUsers() const {
    Node* current = head;
    while (current != nullptr) {
        cout << "UserName: " << current->user->getUserName() << endl;
        cout << "Email: " << current->user->getEmail() << endl << endl;
        current = current->next;
    }
}


User* UserList::findUserByName(const string& userName) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->user->getUserName() == userName) {
            return current->user;
        }
        current = current->next;
    }
    return nullptr;
}


void UserList::addNewUser() {
    string userName, email, password;
    cout << "Enter new username: ";
    cin >> userName;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    User newUser(userName, email, password);
    insertUserAtHead(newUser); // Insert user at the head
    cout << "User added successfully." << endl;
}

void UserList::saveUsersToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Failed to open file for saving users!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        current->user->saveToFile(outFile);
        current = current->next;
    }
    outFile.close();
}

void UserList::loadUsersFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Failed to open file for loading users!" << endl;
        return;
    }

    while (!inFile.eof()) {
        User tempUser;
        tempUser.loadFromFile(inFile);

        // Avoid inserting empty user (in case of trailing newline)
        if (!tempUser.getUserName().empty()) {
            insertUserAtHead(tempUser);
        }
    }

    inFile.close();
}

void UserList::loadMessagesFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Failed to open chat history file for loading!" << endl;
        return;
    }

    string line, sender, receiver, content, timestamp;
    const string messagePrefix = "Message: ";
    while (getline(inFile, line)) {
        if (line.find("Sender: ") == 0) {
            sender = line.substr(8);
            getline(inFile, line);
            if (line.find("Receiver: ") == 0) {
                receiver = line.substr(10);
            } else {
                continue; 
            }
            getline(inFile, line);
            if (line.find(messagePrefix) == 0 && line.length() > messagePrefix.length()) {
                content = line.substr(messagePrefix.length());
            } else {
                content = "";
            }
            getline(inFile, line);
            if (line.find("Time Sent: ") == 0) {
                timestamp = line.substr(11);
            } else {
                continue; 
            }
            getline(inFile, line); 

            // Create message with timestamp
            Message message(sender, receiver, content, timestamp);

            User* senderUser = findUserByName(sender);
            User* receiverUser = findUserByName(receiver);

            if (senderUser && receiverUser) {
                senderUser->getSentMessagesNonConst().push_back(message);
                receiverUser->getReceivedMessagesNonConst().push_back(message);
            }
        }
    }

    inFile.close();
}

void UserList::printChatHistory(const string& userName) const {
    User* user = findUserByName(userName);
    if (user != nullptr) {
        // Display sent messages
        cout << "Chat history for " << userName << " (Sent Messages):\n";
        const auto& sentMessages = user->getSentMessages();
        if (sentMessages.empty()) {
            cout << "No sent messages.\n";
        } else {
            for (const auto& msg : sentMessages) {
                msg.displayMessage();
                cout << endl;
            }
        }

        // Display received messages
        cout << "Chat history for " << userName << " (Received Messages):\n";
        const auto& receivedMessages = user->getReceivedMessages();
        if (receivedMessages.empty()) {
            cout << "No received messages.\n";
        } else {
            for (const auto& msg : receivedMessages) {
                msg.displayMessage();
                cout << endl;
            }
        }
    } else {
        cout << "User not found!" << endl;
    }
}