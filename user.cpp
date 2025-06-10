#include "User.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

User::User() : userName(""), email(""), password(""), salt("") {}

User::User(const string& userName, const string& email, const string& password)
    : userName(userName), email(email) {
    setPassword(password);
}

void User::setUserName(const string& userName) { this->userName = userName; }
string User::getUserName() const { return userName; }

void User::setEmail(const string& email) { this->email = email; }
string User::getEmail() const { return email; }

void User::setPassword(const string& password) {
    string salt = generateSalt();
    this->salt = salt;
    this->password = hashPassword(password, salt);
}

string User::getPassword() const { return password; }

 const vector<Message>&User::getSentMessages() const{
    return sentMessages;
 }

 const vector<Message>& User::getReceivedMessages() const {
    return receivedMessages;
}

vector<Message>& User::getSentMessagesNonConst() {
    return sentMessages;
}

vector<Message>& User::getReceivedMessagesNonConst() {
    return receivedMessages;
}
string User::generateSalt() {
    string salt;
    const char charset[] = "abcdefghijklmnopqrstuvwxyz1234567890#%*^@";
    const int saltLength = 8;
    for (int i = 0; i < saltLength; i++) {
        salt += charset[rand() % (sizeof(charset) - 1)];
    }
    return salt;
}

string User::hashPassword(const string& password, const string& salt) const {
    size_t result = hash<string>{}(password + salt);
    return to_string(result);
}

bool User::verifyPassword(const string& inputPassword) const {
    return hashPassword(inputPassword, salt) == password;
}

void User::sendMessageToUser(User& receiver, const string& messageContent) {
    if (messageContent.empty()) {
        cout << "Message content cannot be empty." << endl;
        return;
    }
    Message newMessage(this->userName, receiver.getUserName(), messageContent);
    receiver.receiveMessage(newMessage); // Send message to receiver
    sentMessages.push_back(newMessage); // Add to sender's sent msgs
    newMessage.saveMessagesToFile(); // save to chat history file
    cout << "Message sent successfully." << endl;
}

void User::receiveMessage(const Message& message) {
    receivedMessages.push_back(message);
}

void User::saveToFile(ofstream& outFile) const {
    outFile << userName << endl;
    outFile << email << endl;
    outFile << password << endl;
    outFile << salt << endl;
}

void User::loadFromFile(ifstream& inFile) {
    getline(inFile, userName);
    getline(inFile, email);
    getline(inFile, password);
    getline(inFile, salt);
}

