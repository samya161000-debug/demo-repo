#include <iostream>
#include <bitset>
using namespace std;

// Sender function
void sender(string msg, int binaryData[], int &n, int &parityBit) {
    n = 0;

    cout << "\nSender Address = " << msg << endl;
    cout << "ASCII (binary) = ";

    // Convert each char to binary (8-bit)
    for (int i = 0; i < msg.length(); i++) {
        bitset<8> b(msg[i]);  // ASCII to binary

        for (int j = 7; j >= 0; j--) {
            binaryData[n++] = b[j];
            cout << b[j];
        }
        cout << " ";
    }

    // Calculate parity
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (binaryData[i] == 1) count++;
    }

    parityBit = count % 2;  // even parity

    cout << "\nParity Bit = " << parityBit << endl;
}

// Receiver function
void receiver(int binaryData[], int n, int parityBit) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (binaryData[i] == 1) count++;
    }

    count += parityBit;

    cout << "\nReceiver Checking...\n";

    if (count % 2 == 0) {
        cout << "No Error Detected ✅\n";
    } else {
        cout << "Error Detected ❌\n";
    }
}

int main() {
    string msg;
    int binaryData[1000];
    int n, parityBit;

    cout << "Enter Sender Address (message): ";
    cin >> msg;

    sender(msg, binaryData, n, parityBit);

    // You can simulate error here if needed
    // binaryData[2] = !binaryData[2];

    receiver(binaryData, n, parityBit);

    return 0;
}