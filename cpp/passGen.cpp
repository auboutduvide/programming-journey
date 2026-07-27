#include <iostream>
#include <string>
#include <vector>   
using namespace std;

class passGen {
private:
        string pass;
        string chars;
        int len;
        int quantity;

public:
    passGen(){
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        len = 8; // default
        quantity = 1; // default
    }

    void userPreferences(){
        string tempNewLen, tempNewQuantity;
        cout << "Dlugosc hasla (jesli domyslne, zostaw puste):\n";
        getline(cin, tempNewLen);
        if (!tempNewLen.empty()) {
            len = stoi(tempNewLen);
        }
        cout << "Ilosc hasel (jesli jedno, zostaw puste):\n";
        getline(cin, tempNewQuantity);
        if (!tempNewQuantity.empty()) {
            quantity = stoi(tempNewQuantity);
    }   
}

    void passCfg(int newLen, int newQuantity){
        if (newLen != 8 ) len = newLen;
        if (newQuantity != 1) quantity = newQuantity;
    }

    vector<string> gen(int newLen, int newQuantity, string chars){
        vector<string> passwords;

        for (int i = 0; i < newQuantity; i++){
        string pass = "";
        for (int j = 0; j < newLen; j++) {
            uint32_t index = arc4random_uniform(chars.length());
            pass += chars[index];
        }
        passwords.push_back(pass);
    }   
    return passwords;
}
        void showPasswords(vector<string> passwords){
            cout << "Wygenerowane hasla:\n";
            for (const string& p : passwords) {
                cout << p << "\n";
            }
        }
};

int main() {
    passGen generator;
    generator.userPreferences(); 
    vector<string> hasla = generator.gen(12, 3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    generator.showPasswords(hasla);
    
    return 0;
}
