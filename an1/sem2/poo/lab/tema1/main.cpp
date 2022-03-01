#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

class Actor {
private:
    string nume;
    int varsta;

public:
    Actor(string nume_, int varsta_) {
        nume = std::move(nume_);
        varsta = varsta_;
    }

    Actor() {
        nume = "";
        varsta = -1;
    }

    string getNume() const {
        return nume;
    }

    void setNume(string nume_) {
        nume = std::move(nume_);
    }

    int getVarsta() const {
        return varsta;
    }

    void setVarsta(int varsta_) {
        varsta = varsta_;
    }
};

class Teatru {
private:
    char* denumirePiesa;
    int numarActori;
    vector<Actor> actori;
    float rating;

public:
    Teatru(const char* denumirePiesa_, int numarActori_, vector<Actor> actori_, float rating_) {
        size_t len = strlen(denumirePiesa_);
        denumirePiesa = new char[len];
        strcpy(denumirePiesa, denumirePiesa_);
        numarActori = numarActori_;
        actori = std::move(actori_);
        rating = rating_;
    }

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

    vector<Actor> getActori() const {
        return actori;
    }

    void setActori(vector<Actor> actori_) {
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
        for (const auto& actor : teatru.actori) {
            os << actor.getNume() << ", in varsta de " << actor.getVarsta() << " (de) ani; ";
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
        char nume[256];
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
               //               std::equal(actori.begin(), actori.end(), teatru.actori.begin()) && ??
               rating == teatru.rating;
    }

    Teatru& operator=(const Teatru &teatru) {
        strcpy(denumirePiesa, teatru.denumirePiesa);
        numarActori = teatru.numarActori;
        actori = teatru.actori;
        rating = teatru.rating;
        return *this;
    }
};

int main() {

    Teatru teatru1, teatru2;
    cin >> teatru1 >> teatru2;
    cout << teatru1 << teatru2;

    return 0;
}
