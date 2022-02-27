#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

class Teatru {
private:
    char* denumirePiesa;
    int numarActori;
    vector<tuple<string, int>> actori;
    float rating;

public:
    Teatru(const char* denumirePiesa_, int numarActori_, vector<tuple<string, int>> actori_, float rating_) {
        size_t len = strlen(denumirePiesa_);
        denumirePiesa = new char[len];
        strcpy(denumirePiesa, denumirePiesa_);
        numarActori = numarActori_;
        actori = std::move(actori_);
        rating = rating_;
    }

    // constructor de copiere?
    Teatru(const Teatru &obj) {
        size_t len = strlen(obj.denumirePiesa);
        denumirePiesa = new char[len];
        strcpy(denumirePiesa, obj.denumirePiesa);
        numarActori = obj.numarActori;
        actori = obj.actori;
        rating = obj.rating;
    }

    // constructor default pentru citire
    Teatru() {
        denumirePiesa = new char[256]; // aici e ok daca las asa? alta idee nu mi-a venit.
        strcpy(denumirePiesa, "empty");
        numarActori = 0;
        actori.clear();
        rating = 0;

    };

    // e complet desctructorul?
    ~Teatru() {
        delete[] denumirePiesa;
        actori.clear();
    }

    // gettere si settere:
    char* getDenumirePiesa() const {
        return denumirePiesa;
    }

    void setDenumirePiesa(char* denumirePiesa_) {
        delete[] denumirePiesa;
        size_t len = strlen(denumirePiesa_);
        denumirePiesa = new char[len];
        strcpy(denumirePiesa, denumirePiesa_);
    }

    int getNumarActori() const {
        return numarActori;
    }

    void setNumarActori(int numarActori_) {
        numarActori = numarActori_;
    }

    vector<tuple<string, int>> getActori() const {
        return actori;
    }

    void setActori(vector<tuple<string, int>> actori_) {
        actori = std::move(actori_);
    }

    float getRating() const {
        return rating;
    }

    void setRating(float rating_) {
        rating = rating_;
    }

    // operator overloading
    friend ostream &operator<<(ostream &os, const Teatru &teatru) {
        os << "Denumire Piesa: "<< teatru.denumirePiesa << "\nNumar actori: " << teatru.numarActori << "\nActori: ";
        for (auto actor : teatru.actori) {
            os << get<0>(actor) << ", in varsta de " << get<1>(actor) << " (de) ani; ";
        }
        os << "Rating " << teatru.rating << "/5.\n";
        return os;
    }

    friend istream &operator>>(istream &is, Teatru &teatru) {
        cout << "Denumire piesa: ";
        is.getline(teatru.denumirePiesa, 256);
        cout << "\nNumarul actorilor: ";
        is >> teatru.numarActori;
        is.get();
        int varsta;
        char *nume;
        cout << "\nDetalii despre actori: ";
        for (int i = 0; i < teatru.numarActori; i++) {
            cout << "\nNume: ";
            is.getline(nume, 256);
            cout << "\nVarsta: ";
            is >> varsta;
            is.get();
            std::string str(nume);
            teatru.actori.emplace_back(nume, varsta);
        }
        cout << "\nRating: ";
        is >> teatru.rating;
        is.get();
        return is;
    }

    bool operator>(const Teatru &teatru) const {
        return rating > teatru.rating;
    }

    bool operator<(const Teatru &teatru) const {
        return rating < teatru.rating;
    }

    // compararea de aici se face tot pe baza de rating??
    bool operator!=(const Teatru &teatru) const {
        return !(teatru == *this);
    }
    // si aici la fel??
    bool operator==(const Teatru &teatru) const {
        return strcmp(denumirePiesa, teatru.denumirePiesa) == 0 &&
               numarActori == teatru.numarActori &&
               actori == teatru.actori &&
               rating == teatru.rating;
    }

    // e bine cum am facut overloading aici?
    void operator=(Teatru &teatru) {
        strcpy(teatru.denumirePiesa, denumirePiesa);
        teatru.numarActori = numarActori;
        teatru.actori = actori;
        teatru.rating = rating;
    }
};

int main() {

    Teatru teatru1, teatru2;
    cin >> teatru1;// >> teatru2;
    // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV), cum rezolv ??, asta daca citesc doar un teatru
    // Process finished with exit code 132 (interrupted by signal 4: SIGILL), cum rezolv ??, asta daca citesc 2 teatre;
    cout << teatru1;// << teatru2;


    return 0;
}
