#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <vector>
#include <fstream>
using namespace std;

// todo: menu w petle

void saveToFile(){

}

void generateNumbers(int minNumber, int maxNumber, int quantity){
    cout << "Trwa generowanie liczb.\n";
    this_thread::sleep_for(chrono::seconds(1));
    vector<int> numbers;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(minNumber, maxNumber);
    
    for (int i = 0; i < quantity; i++){
        int temporaryNumber = dist(gen);        
        numbers.push_back(temporaryNumber);
    }
    
    cout << "Wygenerowane liczby to:\n";
    for (const int& temporaryNumber : numbers){
        cout << temporaryNumber << " ";
    }
    string input;
    int save;
    cout << "Aby zapisac liczby do pliku, wpisz 1\n";
    getline(cin, input);
    save = stoi(input);
    if (save != 1){
        return;
    } else {
        string fileName = "";
        cout << "Jaka nazwa pliku:\n";
        getline(cin, fileName);
        ofstream outputFile(fileName + ".txt");
        cout << "Plik zostal zapisany.\n";
        for (int temporaryNumber : numbers){
            outputFile << temporaryNumber << "\n";
        }
        outputFile.close();
    }

}

int main(){
    string input;
    int quantity = 0;

    cout << "Generator losowych liczb.\n";
    cout << "Ile liczb chcesz wygenerowac?:\n";

    getline(cin, input);
    try {
        quantity = stoi(input);
        cout << "Wybrana wartosc to " << quantity << "\n";
    }
    catch (const invalid_argument& e){
        cout << "Nie wpisales liczby.";
        return 1;
    }
    catch (const out_of_range& e){
        cout << "Liczba jest za dluga.";
        return 1;
    }
    
    string min;
    string max;
    int minNumber;
    int maxNumber;

    cout << "Jaki minimalny zakres liczb?:\n";
    getline(cin, min);
    try {
        minNumber = stoi(min);
        cout << "Wybrana wartosc to " << minNumber << "\n";
    }
    catch (const invalid_argument& e){
        cout << "Nie wpisales liczby.";
        return 1;
    }
    if (minNumber < 0){
        throw invalid_argument("Liczba nie moze byc mniejsza niz zero.");
        return 1;
    } 

    cout << "Jaki maksymalny zakres liczb?:\n";
    getline(cin, max);
    try {
        maxNumber = stoi(max);
        cout << "Wybrana wartosc to " << maxNumber << "\n";
    }
    catch (const invalid_argument& e){
        cout << "Nie wpisales liczby.";
        return 1;
    }
    if (maxNumber < minNumber){
        cout << "Gorny zakres musi byc wiekszy niz dolny.";
        return 1;
    }
    generateNumbers(minNumber, maxNumber, quantity);
}
