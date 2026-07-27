#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void greeting(){
    cout << "Witaj w kalkulatorze\n";
}

void scientificCalculator(){
    int operation;
    cout << "Dzialanie:\n1. Potegi\n2. Pierwiastki\n3. Logarytmy\n4. Trygonometria\n";
    cin >> operation;
    if (operation == 1){
        double a;
        double b;
        cout << "Liczba pierwsza:\n";
        cin >> a;
        cout << "Do jakiej potegi:\n";
        cin >> b;
        double result = pow(a, b);
        cout << "Wynik dzialania wynosi " << result << "\n";
    } else if (operation == 2){
        double a;
        cout << "Podaj liczbe:\n";
        cin >> a;
        double result = sqrt(a);
        cout << "Wynik dzialania wynosi " << result << "\n";
    } else if (operation == 3){
        int a;
        cout << "Podaj liczbe:\n";
        cin >> a;
        if (a <= 0){
            cout << "Logarytm istnieje tylko dla liczb dodatnich.\n";
            return;
        }

        double result = log(a);
        cout << "Wynik dzialania wynosi " << result << "\n";
    } else if (operation == 4){
        int t;
        int angle;
        const double PI = 3.141592653589793;
        cout << "1. Sinus\n2. Cosinus\n3. Tangens\n";
        cin >> t;
        cout << "Podaj kat w stopniach: ";
        cin >> angle;

        double radians = angle * PI / 180.0;
        if (t == 1){
            double result = sin(radians);
            cout << "Wynik dzialania wynosi " << result << "\n";
        } else if (t == 2){
            double result = cos(radians);
            cout << "Wynik dzialania wynosi " << result << "\n";
        } else if (t == 3){
            double result = tan(radians);
            cout << "Wynik dzialania wynosi " << result << "\n";
        }
    }
};
void standardCalculator(){
    // todo
};

int main(){
    greeting();
    int choice;

    cout << "Wybierz kalkulator:\n1. Standardowy\n2. Naukowy\n";
    cout << "Twoj wybor:\n";
    cin >> choice;

    bool isScientific = (choice == 2);

    if (isScientific){
        cout << "Uruchomiono kalkulator naukowy";
        scientificCalculator();
    } else {
        cout << "Uruchomiono kalkulator standardowy";
        standardCalculator();
    }
}
