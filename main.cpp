#include <iostream>
#include <fstream>


#include <iomanip>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#include <ctime>
#include "klasy.h"

using namespace std;












void dostepneKola();




int kolo[3]= {1,1,1};
bool zlaLiteraKolo;




int main() {


    int il_pyt=12;
    Odpowiedz o[il_pyt];


    for(int i=0; i<=(il_pyt-1); i++) {
        system("cls");

        zlaLiteraKolo=false;

        dostepneKola();
        o[i].nrPytania=i+1;
        o[i].menu();
        o[i].pytanieZa(i);

        if(o[i].nadpisanoPytnie==false)
            o[i].wczytajPlik();

        if( (zlaLiteraKolo==true) && (o[i].nadpisanoPytnie==true))
            continue;


        o[i].wyswietlPytanie();
        o[i].pobierzOdp();
        o[i].wybor_odp();
        o[i].czyPoprawna(i);


        if(zlaLiteraKolo==true)
            i--;

    }



    getch();

    return 0;
}





































