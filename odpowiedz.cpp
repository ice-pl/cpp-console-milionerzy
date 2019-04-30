#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <ctime>


#include "klasy.h"


using namespace std;


extern int kolo[3];
extern bool zlaLiteraKolo;





void Odpowiedz::pobierzOdp() {
    cout << "\nTwoja odpowiedz to: ";
    mojaOdpowiedz = getch();
    cout << mojaOdpowiedz << endl;
    mojaOdpowiedz = tolower(mojaOdpowiedz);
}
void Odpowiedz::wybor_odp() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch(mojaOdpowiedz) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
        break;

    case '1':
        if(kolo[0]==0) {
            zlaLiteraKolo=true;

            cout << "\nNie masz kola: ";
            SetConsoleTextAttribute(hConsole, 12);
            cout << setw(20) << right << "[1] Publicznosc" << endl;
            SetConsoleTextAttribute(hConsole, 7);
        } else {
            zlaLiteraKolo=true;
            kolo[0]=0;
            koloPublicznosc();
        }

        cout << "Nacisnij ENTER";
        getch();
        break;

    case '2':
        if(kolo[1]==0) {
            zlaLiteraKolo=true;
            cout << "\nNie masz kola: ";
            SetConsoleTextAttribute(hConsole, 12);
            cout << setw(20) << right << "[2] 50/50" << endl;
            SetConsoleTextAttribute(hConsole, 7);

            cout << "Nacisnij ENTER";
            getch();
        } else {
            zlaLiteraKolo=true;
            nadpisanoPytnie=true;
            kolo[1]=0;
            koloPolNaPol();
        }
        break;

    case '3':
        if(kolo[2]==0) {
            zlaLiteraKolo=true;
            cout << "\nNie masz kola: ";
            SetConsoleTextAttribute(hConsole, 12);
            cout <<  setw(20) << right << "[3] Telefon do przyjaciela" << endl;
            SetConsoleTextAttribute(hConsole, 7);

        } else {
            zlaLiteraKolo=true;
            kolo[2]=0;
            koloTelefon();
        }
        cout << "Nacisnij ENTER";
        getch();
        break;

    case 'r':
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Wybrales rezygnacje z gry " << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\nWygrana: ";
        SetConsoleTextAttribute(hConsole, 11);
        if(nrPytania<2) {
            cout << 0 << endl;
        } else {
            cout << kwota[nrPytania-2] << endl;
        }
        SetConsoleTextAttribute(hConsole, 7);
        exit(0);

        cout << "Nacisnij ENTER";
        getch();
        break;

    default:
        zlaLiteraKolo=true;

        cout << "Poprawny wybor odpowiedzi to: ";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "a b c d" << endl;
        SetConsoleTextAttribute(hConsole, 7);

        cout << "Jesli chcesz wybrac kolo to: ";
        SetConsoleTextAttribute(hConsole, 176);
        cout << "1 2 3" << endl;
        SetConsoleTextAttribute(hConsole, 7);

        cout << "Jesli rezygnujesz z gry to: ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "r" << endl;
        SetConsoleTextAttribute(hConsole, 7);

        cout << "Nacisnij ENTER";
        getch();
        break;
    }

}






void Odpowiedz::czyPoprawna(int nrPytania) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(( mojaOdpowiedz == 'a') || (mojaOdpowiedz == 'b') || (mojaOdpowiedz == 'c') || (mojaOdpowiedz == 'd') ) {
        if(string(1,mojaOdpowiedz) == poprawna) {
            SetConsoleTextAttribute(hConsole, 160);

            cout << "\nTo jest poprawna odpowiedz" <<  endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\nWygrana: ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << kwota[nrPytania] << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Nacisnij ENTER";
            getch();
        } else {
            SetConsoleTextAttribute(hConsole, 79);
            cout << "\nTo NIE jest poprawna odpowiedz" << endl;
            SetConsoleTextAttribute(hConsole, 160);
            cout << "Poprawna odpowiedzia byla:" ;
            SetConsoleTextAttribute(hConsole, 10);
            cout << " " << poprawna << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\nKwota gwarantowana to: ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << kwota_gw[nrPytania] << endl;
            SetConsoleTextAttribute(hConsole, 7);
            exit(0);
        }
    }
}




void Odpowiedz::koloPublicznosc() {
    srand( time( NULL ) );
    int suma=0;
    if(nadpisanoPytnie==false) {
        int glosow[5];
        glosow[0]=0;
        for (int i=1; i<5; i++) {
            glosow[i]=( rand() % (101-suma) );
            suma=suma+glosow[i];
        }
        cout << setw(20) << right << glosow[1] << " %";
        cout << setw(20) << right << glosow[2] << " %";
        cout << setw(20) << right << glosow[3] << " %";
        cout << setw(20) << right << glosow[4] << " %" << endl;
        cout << setw(22) << "A  " << setw(22) << "B  " << setw(22) << "C  " << setw(22) << "D  " << endl;
    } else {
        int glosow[3];
        glosow[0]=0;

        for (int i=1; i<3; i++) {
            glosow[i]=( rand() % (101-suma) );
            suma=suma+glosow[i];
        }
        cout << setw(30) << right << glosow[1] << " %";
        cout << setw(30) << right << glosow[2] << " %"<< endl;
        cout << setw(38) << "Dla pierwszej  " << setw(30) << "Dla drugiej  " << endl;
    }
}
void Odpowiedz::koloPolNaPol() {

    int poprawna_nr;
    if(poprawna=="a")
        poprawna_nr=1;
    if(poprawna=="b")
        poprawna_nr=2;
    if(poprawna=="c")
        poprawna_nr=3;
    if(poprawna=="d")
        poprawna_nr=4;

    srand( time( NULL ) );

    int  Tablica[4];
    for (int i=0; i<4; i++)
        Tablica[i] = (i+1);

    int j, temp;
    do {
        for (int i=0; i<4; i++) {
            j = rand()%4;
            temp = Tablica[i];
            Tablica[i] = Tablica[j];
            Tablica[j] = temp;
        }
    } while((Tablica[0] == poprawna_nr) || (Tablica[1] == poprawna_nr)) ;

    for (int i=0; i<2; i++) {
        switch(Tablica[i]) {
        case 1:
            a=" ";
            break;
        case 2:
            b=" ";
            break;
        case 3:
            c=" ";
            break;
        case 4:
            d=" ";
            break;
        }
    }
}

void Odpowiedz::koloTelefon() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "\n\tCzesc tu " <<  " " ;
    SetConsoleTextAttribute(hConsole, 13);
    cout << "SLAWOMIR " <<  endl ;
    SetConsoleTextAttribute(hConsole, 7);
    Sleep(500);
    cout << "\tMoim zdaniem bedzie to odpowiedz " ;
    Sleep(1000);

    srand( time( NULL ) );
    int przyjaciel = (rand()% 4)+1;

    SetConsoleTextAttribute(hConsole, 14);
    if(przyjaciel==1)
        cout << "A" << endl;
    if(przyjaciel==2)
        cout << "B" << endl;
    if(przyjaciel==3)
        cout << "C" << endl;
    if(przyjaciel==4)
        cout << "D" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

