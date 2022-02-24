#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in;
    ofstream out("/Users/Abel/Desktop/Cpp/encryptDecrypt/encryptDecrypt/encryptedFile.txt");
    in.open("/Users/Abel/Desktop/Cpp/encryptDecrypt/encryptDecrypt/decryptedFile.txt");
    
    //to encrypt var in is the decrypted file and to decrypt var in is the encrypted file
    string txt;
    if (!in.is_open()) {
            cout << "File not found\n";
        }
    bool quit = false;
    int key;
    while (!quit) {
    cout << "Enter the encryption or decryption key\n";
    cin >> key;
        if (key > 94 || key < -94) {
            continue;
        }
        else {
            quit = true;
        }
    }
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
