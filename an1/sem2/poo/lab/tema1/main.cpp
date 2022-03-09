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

    ~Actor() {
        nume.clear();
    }

    string getNume() const {
        return nume;
    }

    void setNume(string nume_) {
        nume.clear();
        nume = std::move(nume_);
    }

    int getVarsta() const {
        return varsta;
    }

    void setVarsta(int varsta_) {
        varsta = varsta_;
    }

    friend istream &operator>>(istream &is, Actor &actor) {
        cout << "Numele actorului: ";
        char nume_[256];
        is.getline(nume_, 256);
        string aux(nume_);
        actor.setNume(aux);
        cout << "Varsta actorului: ";
        int varsta_;
        is >> varsta_;
        actor.setVarsta(varsta_);
        is.get();
        return is;
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
        denumirePiesa = new char[6];
        strcpy(denumirePiesa, "empty");
        numarActori = 0;
        actori.clear();
        rating = 0;
    };

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
        os << "==========================\n";
        os << "Denumire Piesa: "<< teatru.denumirePiesa << "\nNumar actori: " << teatru.numarActori << "\nActori: ";
        for (const auto& actor : teatru.actori) {
            os << actor.getNume() << ", in varsta de " << actor.getVarsta() << " (de) ani; ";
        }
        os << "Rating " << teatru.rating << "/5.\n";
        os << "==========================\n";
        return os;
    }

    friend istream &operator>>(istream &is, Teatru &teatru) {
        cout << "Denumire piesa: ";
        is.getline(teatru.denumirePiesa, 256);
        cout << "Numarul actorilor: ";
        is >> teatru.numarActori;
        is.get();
        cout << "Detalii despre actori:\n";
        Actor actor;
        for (int i = 0; i < teatru.numarActori; i++) {
            is >> actor;
            teatru.actori.push_back(actor);
        }
        cout << "Rating: ";
        is >> teatru.rating;
        is.get();
        cout << "\n";
        return is;
    }

    bool operator>(const Teatru &teatru) const {
        return rating > teatru.rating;
    }

    bool operator<(const Teatru &teatru) const {
        return rating < teatru.rating;
    }

    bool operator!=(const Teatru &teatru) const {
        return !(teatru == *this);
    }

    bool operator==(const Teatru &teatru) const {
        if (numarActori == teatru.numarActori) {
            for (int i = 0; i < numarActori; i++)
                if ((actori[i].getVarsta() != teatru.actori[i].getVarsta()) || (actori[i].getNume() != actori[i].getNume()))
                    return false;
            if (strcmp(denumirePiesa, teatru.denumirePiesa) != 0)
                return false;
            if (rating != teatru.rating)
                return false;
        } else return false;
        return true;
    }

    Teatru& operator=(const Teatru &teatru) {
        delete[] denumirePiesa;
        size_t len = strlen(teatru.denumirePiesa);
        denumirePiesa = new char[len];
        strcpy(denumirePiesa, teatru.denumirePiesa);
        numarActori = teatru.numarActori;
        actori = teatru.actori;
        rating = teatru.rating;
        return *this;
    }
};

class Menu {
private:
    bool deschis = true;
    int numarPiese;
    int optiune;
    int index;
    float rating_;
    Actor actor;

    vector<Teatru> piese;

    static void help() {
        cout << "---------------------------------------------------" << endl;
        cout << "-> Apasa '0' pentru a inchide meniul;" << endl;
        cout << "-> Apasa '1' pentru a afisa meniul de help din nou;" << endl;
        cout << "-> Apasa '2' pentru a afisa toate piesele;" << endl;
        cout << "-> Apasa '3' pentru a afisa o piesa la alegere;" << endl;
        cout << "-> Apasa '4' pentru a adauga un actor;" << endl;
        cout << "-> Apasa '5' pentru a schimba rating-ul unei piese;" << endl;
        cout << "---------------------------------------------------" << endl;
    }

    void inchide() {
        deschis = false;
    }

    void afisare() {
        for (const auto& piesa : piese) {
            cout << piesa;
        }
    }

    void afisare(int index_) {
        cout << piese[index_];
    }

    void adaugaActor(int index_, const Actor& actor_) {
        vector<Actor> aux = piese[index_].getActori();
        aux.push_back(actor_);
        piese[index_].setActori(aux);
    }

    void schimbaRating(int index_, float rating) {
        piese[index_].setRating(rating);
    }

public:
    void run(){
        cout << "Introdu numarul de piese: ";
        cin >> numarPiese;
        cin.get();
        for (int i = 1; i <= numarPiese; i++) {
            Teatru aux;
            cin >> aux;
            piese.push_back(aux);
        }

        help();
        while (deschis) {
            cout << "Ce operatie doresti sa utilizezi?\n";
            cin >> optiune;
            switch (optiune) {
                case 0:
                    cout << "Meniul s-a inchis.";
                    inchide();
                    break;
                case 1:
                    help();
                    break;
                case 2:
                    afisare();
                    break;
                case 3:
                    cout << "Ce piesa doresti sa afisezi? (numaratoarea incepe de la 0)\n";
                    cin >> index;
                    if (index >= numarPiese) {
                        cout << "nu exista!";
                        break;
                    }
                    afisare(index);
                    break;
                case 4:
                    cout << "Pentru ce piesa vrei sa mai adaugi un actor? (numaratoarea incepe de la 0)\n";
                    cin >> index;
                    if (index >= numarPiese) {
                        cout << "nu exista!";
                        break;
                    }
                    cin.get();
                    cin >> actor;
                    adaugaActor(index, actor);
                    break;
                case 5:
                    cout << "Pentru ce piesa vrei sa schimbi rating-ul? (numaratoarea incepe de la 0)\n";
                    cin >> index;
                    if (index >= numarPiese) {
                        cout << "nu exista!";
                        break;
                    }
                    cout << "Introdu rating-ul nou: ";
                    cin >> rating_;
                    schimbaRating(index, rating_);
                    break;
                default:
                    break;
            }
        }
    }
};

int main() {

    Menu menu;
    menu.run();

    return 0;
}
