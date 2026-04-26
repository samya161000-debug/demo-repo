#include <iostream>
using namespace std;

string toBinary(unsigned char ch) {
    string bin = "";

    for (int i = 7; i >= 0; i--) {
        if ((ch >> i) & 1)
            bin += '1';
        else
            bin += '0';
    }

    return bin;
}


void sender(string msg, string &binaryData, int &parityBit) {
    binaryData = "";

    cout << "\nSender Address = " << msg << endl;
    cout << "ASCII (binary) = ";

    for (int i = 0; i < msg.length(); i++) {
        string bin = toBinary((unsigned char)msg[i]);

        cout << bin << " ";
        binaryData += bin;   
    }

    int count = 0;
    for (int i = 0; i < binaryData.length(); i++) {
        if (binaryData[i] == '1') count++;
    }

    parityBit = count % 2;

    cout << "\nParity Bit = " << parityBit << endl;
}

void receiver(string binaryData, int parityBit) {
    int count = 0;

    for (int i = 0; i < binaryData.length(); i++) {
        if (binaryData[i] == '1') count++;
    }

    count += parityBit;

    cout << "\nReceiver Checking\n";

    if (count % 2 == 0)
        cout << "No Error Detected \n";
    else
        cout << "Error Detected \n";
}

int main() {
    string msg, binaryData;
    int parityBit;

    cout << "Enter Sender Address (message): ";
    cin >> msg;

    sender(msg, binaryData, parityBit);



    receiver(binaryData, parityBit);

    return 0;
}