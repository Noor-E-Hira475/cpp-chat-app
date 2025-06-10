#include "Message.h"
#include <chrono>
#include <ctime>

// Function to get current timestamp
string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    string timeString = ctime(&currentTime);
    timeString.pop_back(); // Remove the trailing newline
    return timeString;
    
}

Message::Message(const string& sender, const string& receiver, const string& content, const string& timestamp)
    : sender(sender), receiver(receiver), content(content), timeStamp(timestamp) {}


void Message::displayMessage() const {
    cout << "Sender: " << sender << endl;
    cout << "Receiver: " << receiver << endl;
    cout << "Message: " << content << endl;
    cout << "Time Sent: " << timeStamp << endl;
}

void Message::saveMessagesToFile() const {
    ofstream outFile("ChatHistory.txt", ios::app); // open in append mode
    if (outFile.is_open()) {
        outFile << "Sender: " << sender << endl;
        outFile << "Receiver: " << receiver << endl;
        outFile << "Message: " << content << endl;
        outFile << "Time Sent: " << timeStamp << endl;
        outFile << "-----------------------------" << endl;
        outFile.close();
    } else {
        cout << "Failed to open chat history file!" << endl;
    }
}

void Message::setTimestamp(const string& timestamp) {
    this->timeStamp = timestamp; 
}