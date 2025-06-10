#ifndef USERLIST_H
#define USERLIST_H

#include <string>
#include "User.h"

class UserList {
private:
    struct Node {
        User* user;
        Node* next;
        Node() : user(nullptr), next(nullptr) {}
    };

    Node* head;

public:
    UserList();
    ~UserList();
    void insertUserAtHead(const User& newUser);
    void displayUsers() const;
    User* findUserByName(const string& userName) const;
    void addNewUser();
    void saveUsersToFile(const string& filename) const;
    void loadUsersFromFile(const string& filename);
    void loadMessagesFromFile(const string& filename);
    void printChatHistory(const string& userName) const;
};

#endif // USERLIST_H
