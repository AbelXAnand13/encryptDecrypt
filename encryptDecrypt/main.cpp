#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in;
    ofstream out;
    
    //to encrypt var in is the decrypted file and to decrypt var in is the encrypted file
    string txt;
    
    in.open("/Users/Abel/Desktop/Cpp/encryptDecrypt/encryptDecrypt/edtxt.txt");
    out.open("/Users/Abel/Desktop/Cpp/encryptDecrypt/encryptDecrypt/encryptedFile.txt");
    if (!in.is_open()) {
            cout << "File not found\n";
        }
    
    bool quit = false;
    int key;
    //key
    while (!quit) {
        cout << "Enter the key (you can do negatives or positives, just remember to toggle negative sign)\n";
        cin >> key;
        if (key > 94) {
            key = 94;
        }
        else if (key < -94) {
            key = -94;
        }
        else {
            quit = true;
        }
    }
    
    
    while (getline(in, txt)) {
        for (int i = 0; i < txt.length(); i++) {
            unsigned char ch = txt[i] + key;
            out << ch;
        }
        out << endl;
    }
    in.close();
    out.close();
    in.open("/Users/Abel/Desktop/Cpp/encryptDecrypt/encryptDecrypt/encryptedFile.txt");
    out.open("/Users/Abel/Desktop/Cpp/encryptDecrypt/encryptDecrypt/decryptedFile.txt");
    
    while (getline(in, txt)) {
        for (int i = 0; i < txt.length(); i++) {
            unsigned char ch = txt[i] - key;
            out << ch;
        }
        out << endl;
    }
    in.close();
    out.close();
    }
