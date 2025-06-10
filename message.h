#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Function declaration for current timestamp
string getCurrentTimestamp();

class Message {
private:
    string sender;
    string receiver;
    string content;
    string timeStamp;

public:
    Message(const string& sender, const string& receiver, const string& content, const string& timestamp = getCurrentTimestamp());
    // display message
    void displayMessage() const;
    // save message
    void saveMessagesToFile() const;
    // Setter for timestamp
    void setTimestamp(const string& timestamp);
};

#endif // MESSAGE_H
