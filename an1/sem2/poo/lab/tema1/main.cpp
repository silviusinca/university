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

    Teatru() {
        denumirePiesa = new char[256];
        strcpy(denumirePiesa, "empty");
        numarActori = 0;
        actori.clear();
        rating = 0;

    }; // constructor default?

    // e complet desctructorul?
    ~Teatru() {
        delete[] denumirePiesa;
        actori.clear();
    }

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

    friend ostream &operator<<(ostream &os, const Teatru &teatru) {
        os << "Denumire Piesa: "<< teatru.denumirePiesa << "\nNumar actori: " << teatru.numarActori << "\nActori: ";
        for (auto actor : teatru.actori) {
            os << get<0>(actor) << ", in varsta de " << get<1>(actor) << " (de) ani; ";
        }
        os << "Rating " << teatru.rating << "/5.";
        return os;
    }

    friend istream &operator>>(istream &is, Teatru &teatru) {
        is >> teatru.denumirePiesa >> teatru.numarActori;
        char *nume;
        int varsta;
        for (int i = 0; i < teatru.numarActori; i++) {
            is >> nume >> varsta;
            teatru.actori.emplace_back(nume, varsta);
        }
        is >> teatru.rating;
        return is;
    }
};

int main() {
    vector<tuple<string, int>> test;
    test.emplace_back("Ion Ion", 25);
    test.emplace_back("Narcis Ion", 34);
    test.emplace_back("Sebastian Ion", 89);
    test.emplace_back("Popa Ion", 15);

    Teatru piesaTest("Piesa test", 4, test, 4.5);

//    cout << piesaTest;
    char* denumire;
    int nrActori;
    float rating_;
    vector<tuple<string, int>> v;


    Teatru teatruTest2;
    cin >> teatruTest2;
    cout << teatruTest2;

    return 0;
}
