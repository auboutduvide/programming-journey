#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

int main(){
    vector<string> tasks;

    ifstream input("tasks.txt");
    string task;
    while(getline(input, task)){
        tasks.push_back(task);
    }

    input.close();
    while (true){
    int option;
    cout << "1. Dodaj zadania\n2. Pokaz zadania\n3. Usun zadania\n4. Wyjdz\n";
    cin >> option;

    if (option == 1){
        cout << "Ladowanie...\n" << flush;
        this_thread::sleep_for(chrono::seconds(3));
        string newTask = "";
        cout << "Wpisz tresc zadania (ToDo):\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newTask);
        tasks.push_back(newTask);
        cout << "Dodawanie...\n";
        ofstream file("tasks.txt");

        for (string task : tasks){
            file << task << "\n";
        }
        file.close();
        this_thread::sleep_for(chrono::seconds(2));

        cout << "Zadanie zostalo dodane pomyslnie.\n";
    } else if (option == 2){
        int number = 1;

        for (const string& task : tasks){
            cout << number << ". " << task << "\n";
            number++;
        }
    } else if (option == 3){
        int toDelete;
        cout << "Wybierz identyfikator zadania do usuniecia:\n";
        while (true){
            cin >> toDelete;

            if (toDelete < 1 || toDelete > tasks.size()){
                cout << "Nie ma takiego zadania\n";
            }
            else {
                tasks.erase(tasks.begin() + toDelete - 1);
                break;
                ofstream file("tasks.txt");

                for (string task : tasks){
                    file << task << "\n";
                }

                file.close();
            }
        }
    } else if (option == 4){
        ofstream output("tasks.txt");

        for (string task : tasks){

            output << task << "\n";

        }

        output.close();
            cout << "Do zobaczenia!";
            return 0;
        }
}}
