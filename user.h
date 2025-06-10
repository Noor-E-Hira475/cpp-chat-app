#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Message.h"

using namespace std;

class User {
private:
    string userName;
    string email;
    string password;
    string salt;
    vector<Message> sentMessages;
    vector<Message> receivedMessages; // To store received messages

public:
    User();
    User(const string& userName, const string& email, const string& password);
    void setUserName(const string& userName);
    string getUserName() const;
    void setEmail(const string& email);
    string getEmail() const;
    void setPassword(const string& password);
    string getPassword() const;
    const vector<Message>& getSentMessages() const;
    const vector<Message>& getReceivedMessages() const;
    vector<Message>& getSentMessagesNonConst(); 
    vector<Message>& getReceivedMessagesNonConst();
    string generateSalt();
    string hashPassword(const string& password, const string& salt) const;
    bool verifyPassword(const string& inputPassword) const;
    void sendMessageToUser(User& receiver, const string& messageContent);
    void receiveMessage(const Message& message);
    void saveToFile(ofstream& outFile) const;
    void loadFromFile(ifstream& inFile);
};

#endif // USER_H
