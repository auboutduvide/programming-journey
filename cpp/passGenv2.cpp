#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

void saveToFile(vector<string>& passwords){
    string fileName;
    cout << "Wpisz nazwe pliku:\n";
    getline(cin, fileName);
    ofstream outputFile(fileName + ".txt");
    for (const string& singlePass : passwords) {
        outputFile << singlePass << "\n";
    }
    outputFile.close();
    for (string &pass : passwords){
        for (char &c : pass){

        c = '\0';
    }
}
    passwords.clear();
    cout << "Zapisano pomyslnie.\n";
    return;
}

void passGen(){
    string pass;
    string tempQuantity;
    string tempSaveChoice;
    vector<string> passwords;
    string tempPassLength;
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int passLength;
    int quantity;
    int saveChoice;

    cout << "Wpisz dlugosc hasla\n";
    getline(cin, tempPassLength);
    passLength = stoi(tempPassLength);
    cout << "Wpisz ilosc hasel do wygenerowania\n";
    getline(cin, tempQuantity);
    quantity = stoi(tempQuantity);
    for (int i = 0; i < quantity; i++){
        pass = "";
        for (int j = 0; j < passLength; j++){
        uint32_t index = arc4random_uniform(chars.length());
        pass += chars[index];
    }
        passwords.push_back(pass);
}
    cout << "Twoje haslo to\n";
    for (const string& pass : passwords){
        cout << pass << " \n";
    }


    cout << "Aby zapisac nazwe do pliku wpisz 1\n";
    getline(cin, tempSaveChoice);
    saveChoice = stoi(tempSaveChoice);
    if (saveChoice == 1){
        saveToFile(passwords);
    } else {
        for (char &c : pass){
            c = '\0';
        }
        pass.clear();
        return;
    }
}

int main(){
    while(true){
        string tempMenuChoice;
        int menuChoice;
        cout << "MENU\n";
        cout << "Co chcesz zrobic?\n";
        cout << "1. Wygeneruj haslo\n2. Wyjdz\n";
        getline(cin, tempMenuChoice);
        menuChoice = stoi(tempMenuChoice);
        if (menuChoice == 1){
            passGen();
        } else if (menuChoice == 2){
            return 0;
        } else {
            cout << "Nieprawidlowa opcja\n";
        }

    }
}
