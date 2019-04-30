#include <iostream>
#include <iomanip>
#include <windows.h>

#include "klasy.h"
using namespace std;







extern int kolo[3];




void dostepneKola() {
    cout << "=================" << endl;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 176);
    if(kolo[0]==1) {
        cout << setw(30) << left << "[1] Publicznosc";
    } else {
        SetConsoleTextAttribute(hConsole, 8);
        cout << setw(30) << left << "[1] Publicznosc wykorzystane";
        SetConsoleTextAttribute(hConsole, 176);
    }


    if(kolo[1]==1) {
        cout << setw(30) << left << "[2] 50/50";
    } else {
        SetConsoleTextAttribute(hConsole, 8);
        cout << setw(30) << left << "[2] 50/50 wykorzystane";
        SetConsoleTextAttribute(hConsole, 176);
    }


    if(kolo[2]==1) {
        cout << setw(30) << left << "[3] Telefon do przyjaciela";
    } else {
        SetConsoleTextAttribute(hConsole, 8);
        cout << setw(30) << left << "[3] Telefon do przyjaciela wykorzystane";
        SetConsoleTextAttribute(hConsole, 176);
    }
    SetConsoleTextAttribute(hConsole, 7);

}




void Wyswietlanie::menu() {
    cout << "\n=================" << endl;
    int i = 12;
    for (int i = 12; i >= 1; i--) {
        char znak = ' ' ;
        char znak_gw = ' ' ;

        if (nrPytania==i)
            znak = char(254) ;

        if (nrPytania==i)
            znak_gw = char(254) ;

        if(i==2 || i==7 || i==12) {
            cout << setw(3) << right << i << " " << znak << " " << setw(10) << right << kwota[i-1] << " " << znak_gw << " " << kwota_gw[i] << endl;
        } else {
            cout << setw(3) << right << i << " " << znak << " " << setw(10) << right << kwota[i-1] << " " << znak_gw << " " << endl;
        }
    }
    cout << "=================" << endl;
}
void Wyswietlanie::pytanieZa(int nrPytania) {
    cout << "Kwota Gwarantowana to: " << kwota_gw[nrPytania];
    cout << "\tPytanie za: " << kwota[nrPytania] << endl;
    cout << "=================" << endl;
}
void Wyswietlanie::wyswietlPytanie() {
    cout << "Pytanie nr: " << nrPytania << "\n\t\t" << tresc << "\n"<< endl;
    cout << setw(10) << right << "a: " << setw(50) << left << a << setw(3) << right << "b: " << setw(50) << left << b << endl;
    cout << setw(10) << right << "c: " << setw(50) << left << c << setw(3) << right << "d: " << setw(50) << left << d << endl;
};

