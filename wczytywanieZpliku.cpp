#include <iostream>
#include <fstream>
#include "klasy.h"




using namespace std;





WyborPliku::WyborPliku(string nnn) {
    this->nazwa_pliku=nnn;
}
void WyborPliku::pokazNazwePliku() {
    cout << nazwa_pliku << endl;
};
void WyborPliku::wczytajPlik() {
    fstream plik;
    plik.open(nazwa_pliku.c_str(),ios::in);

    int nr_linii=(nrPytania-1)*6+1;
    int aktualny_nr=1;
    string linia;

    while(getline(plik,linia)) {
        if(aktualny_nr==nr_linii)
            tresc=linia;
        if(aktualny_nr==nr_linii+1)
            a=linia;
        if(aktualny_nr==nr_linii+2)
            b=linia;
        if(aktualny_nr==nr_linii+3)
            c=linia;
        if(aktualny_nr==nr_linii+4)
            d=linia;
        if(aktualny_nr==nr_linii+5)
            poprawna=linia;
        aktualny_nr++;
    }
    plik.close();
};
