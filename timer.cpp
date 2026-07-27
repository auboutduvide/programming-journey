#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main(){
    int minutes;
    
    cout << "Podaj czas w minutach: ";
    cin >> minutes; 
    
    int seconds = minutes * 60; 
    
    for (int i = seconds; i > 0; i--){
        int m = i / 60;
        int s = i % 60;

        cout << "\rPozostalo " << m << " minut i " << s << " sekund" << flush;

        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\nCzas minal!" << endl;
    return 0;
}
