#include <iostream>
#include <string>


using namespace std;






class WyborPliku {
  private:
    string nazwa_pliku;
  public:
    string tresc, a, b, c, d, poprawna;
    int nrPytania;

    WyborPliku(string nnn="trudnosc_Wsadowy.txt");
    ~WyborPliku() {
    };

    void pokazNazwePliku();
    void wczytajPlik();
};





class Wyswietlanie :public WyborPliku {

  public:
    using WyborPliku::WyborPliku;
    ~Wyswietlanie() {
    };

    int kwota[12]= {500,1000,2000,5000,10000,20000,40000,75000,125000,250000,500000,1000000};
    int kwota_gw[13]= {0,0,1000,1000,1000,1000,1000,40000,40000,40000,40000,40000,1000000};

    void menu();
    void pytanieZa(int nrPytania);
    void wyswietlPytanie();


};








class Odpowiedz :public Wyswietlanie {
  public:
    char mojaOdpowiedz;
    bool nadpisanoPytnie=false;


    using Wyswietlanie::Wyswietlanie;
    ~Odpowiedz() {
    };


    void pobierzOdp();
    void wybor_odp();

    void czyPoprawna(int nrPytania);



    void koloPublicznosc();
    void koloPolNaPol();
    void koloTelefon();


};



