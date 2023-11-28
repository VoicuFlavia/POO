#include <iostream>
#include<string>

using namespace std;

class Sejur
{
private:
    const int id;
    char* destinatie;
    float pretBaza;
    int nrExcursiiOptionale;
    float* pretExcursie;
    char* locatie;
    int durata;

public:
    Sejur() : id(1) {
        pretBaza = 0;
        nrExcursiiOptionale = 0;
        pretExcursie = nullptr;
        locatie = nullptr;
        destinatie = nullptr;
        durata = 0;
    }
    //constructor

    Sejur(char* destinatie, float pretBaza, int nrExcursiiOptionale, float* pretExcursie, char* locatie, int durata): id(1) {
        this->destinatie = new char[strlen(destinatie) + 1];
        strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);

        this->pretBaza = pretBaza;

        this->nrExcursiiOptionale = nrExcursiiOptionale;

        this->pretExcursie = new float[sizeof(pretExcursie)];
        for (int i = 0; i < sizeof(pretExcursie); i++) {
            this->pretExcursie[i] = pretExcursie[i];
        }

        this->locatie = new char[strlen(locatie) + 1];
        strcpy_s(this->locatie, strlen(locatie) + 1, locatie);

        this->durata = durata;
    }

    //deconstructor

    ~Sejur() {
        delete this->destinatie;
        delete this->pretExcursie;
        delete this->locatie;
        cout << "Stergere completa!";
    }

    //set

    void setDestinatie(char* destinatie) {
        this->destinatie = new char[strlen(destinatie) + 1];
        strcpy_s(this->destinatie, strlen(destinatie), destinatie);
    }

    void setPretBaza(float pretBaza) {
        this->pretBaza = pretBaza;
    }

    void setNrExcursiiOptionale(int nrExcursiiOptionale) {
        this->nrExcursiiOptionale = nrExcursiiOptionale;
    }

    void setPretExcursie(float* pretExcursie) {
        this->pretExcursie = new float[sizeof(pretExcursie)];
        for (int i = 0; i < sizeof(pretExcursie); i++) {
            this->pretExcursie[i] = pretExcursie[i];
        }
    }

    void setLocatie(char* locatie) {
        this->locatie = new char[strlen(locatie) + 1];
        strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
    }

    void setDurata(int durata) {
        this->durata = durata;
    }

    //get

    char* getDestinatie() {
        char* copie = new char[strlen(this->destinatie) + 1];
        strcpy_s(copie, strlen(this->destinatie) + 1, this->destinatie);
        return copie;
    }

    float getPretBaza() {
        return this->pretBaza;
    }

    int getNrExcursiiOptionale() {
        return this->nrExcursiiOptionale;
    }

    float* getPretExcursie() {
        float* copie = new float[sizeof(this->pretExcursie)];
        for (int i = 0; i < sizeof(pretExcursie); i++) {
            copie[i] = this->pretExcursie[i];
        }
        return copie;
    }

    char* getLocatie() {
        char* copie = new char[strlen(this->locatie) + 1];
        strcpy_s(copie, strlen(this->locatie) + 1, this->locatie);
        return copie;
    }

    int getDurata() {
        return this->durata;
    }

    //constructor de copiere

    Sejur(Sejur& s): id(s.id){
        if (s.destinatie != nullptr) {
            this->destinatie = new char[strlen(s.destinatie) + 1];
            strcpy_s(this->destinatie, strlen(s.destinatie) + 1, s.destinatie);
        }

        this->pretBaza = s.pretBaza;

        this->nrExcursiiOptionale = s.nrExcursiiOptionale;

        if (s.pretExcursie != nullptr) {
            this->pretExcursie = new float[sizeof(s.pretExcursie)];
            for (int i = 0; i < sizeof(s.pretExcursie); i++) {
                this->pretExcursie[i] = s.pretExcursie[i];
            }
        }
        
        if (s.locatie != nullptr) {
            this->locatie = new char[strlen(s.locatie) + 1];
            strcpy_s(this->locatie, strlen(s.locatie) + 1, s.locatie);
        }

        this->durata = s.durata;

    }

    //numarul maxim de excursii optionale

    int getNrMaximExcursii(float bugetMaximSejur) {
        int count = 0;
        float suma = this->pretBaza;
        for (int i = 0; i < this->nrExcursiiOptionale; i++) {
            if (suma + this->pretExcursie[i] <= bugetMaximSejur) {
                suma = suma + this->pretExcursie[i];
                count++;
            }
        }
        return count;
    }

    Sejur& operator=(const Sejur s) {
        if (destinatie != nullptr) {
            delete destinatie;
        }

        if (pretExcursie != nullptr) {
            delete pretExcursie;
        }

        if (locatie != nullptr) {
            delete locatie;
        }

        this->destinatie = new char[strlen(s.destinatie) + 1];
        strcpy_s(this->destinatie, strlen(s.destinatie) + 1, s.destinatie);

        this->pretBaza = s.pretBaza;

        this->nrExcursiiOptionale = s.nrExcursiiOptionale;

        this->pretExcursie = new float[sizeof(s.pretExcursie)];
        for (int i = 0; i < sizeof(s.pretExcursie); i++) {
            this->pretExcursie[i] = s.pretExcursie[i];
        }

        this->locatie = new char[strlen(s.locatie) + 1];
        strcpy_s(this->locatie, strlen(s.locatie) + 1, s.locatie);

        this->durata = s.durata;

        return *this;
    }

    

    friend ostream& operator<<(ostream& out, Sejur s) {
        out << "Destinatie:" << s.destinatie << endl;
        out << "Pretul de baza este:" << s.pretBaza << endl;
        out << "Numarul excursiilor optionale este:" << s.nrExcursiiOptionale << endl;
        out << "Pretul excursiilor optionale este:" << endl;
        for (int i = 0; i < s.nrExcursiiOptionale; i++) {
            out << s.pretExcursie[i] << " lei" << endl;
        }
        out << "Locatia:" << s.locatie << endl;
        out << "Durata sejurului este de :" << s.durata <<"zile"<< endl;

        return out;
    }

        friend istream& operator>>(istream& in, Sejur& s) {
        string buffer;
        cout << "Destinatie:";
        in>>buffer;
        if (s.destinatie != nullptr) {
            delete s.destinatie;
        }
        s.destinatie = new char[buffer.length() + 1];
        strcpy_s(s.destinatie, buffer.length() + 1, buffer.c_str());

        cout << "Pret de baza:";
        in >> s.pretBaza;

        cout << "Numarul de excursii optionale:";
        in >> s.nrExcursiiOptionale;

        if (s.pretExcursie != nullptr) {
            delete s.pretExcursie;
        }
        cout << "Pretul excursiilor optionale:";
        s.pretExcursie = new float[s.nrExcursiiOptionale];
        for (int i = 0; i < s.nrExcursiiOptionale; i++) {
            in >> s.pretExcursie[i];
        }

        cout << "Destinatia sejurului:";
        in >> buffer;
        if (s.locatie != nullptr) {
            delete s.locatie;
        }
        s.locatie = new char[buffer.length() + 1];
        strcpy_s(s.locatie, buffer.length() + 1, buffer.c_str());

        cout << "Durata sejur:";
        in >> s.durata;
        return in;
    }

        Sejur& operator-- () {
            //Sejur copie = *this;
            float pretMinim = this->pretExcursie[0];
            for (int i = 1; i < this->nrExcursiiOptionale; i++) {
                if (this->pretExcursie[i] < pretMinim) {
                    pretMinim = this->pretExcursie[i];
                    for (int j = i + 1; j < this->nrExcursiiOptionale; j++) {
                        this->pretExcursie[i - 1] = this->pretExcursie[j];
                    }
                    this->nrExcursiiOptionale--;
                }
            }
            //copie.setPretExcursie(this->pretExcursie);
            return *this;
        }

        bool operator<=(Sejur s) {

        }
};

int main()
{
    float pret[] = {1234.67 , 5647.90, 3538.67, 32342.23, 3854.56};

    Sejur s1( (char*)"Sibiu", 2350, 5, pret, (char*)"Romania", 10);
    Sejur s2;
    s2 = s1;
    cout << endl;
    float* pretExcursie = new float[s1.getNrExcursiiOptionale()];
    pretExcursie=s1.getPretExcursie();
    for (int i = 0; i < s1.getNrExcursiiOptionale(); i++) {
        cout << pretExcursie[i] << endl;
    }
    delete pretExcursie;
    cout << endl;
    float* pretExcursie2 = new float[s2.getNrExcursiiOptionale()];
    pretExcursie2 = s2.getPretExcursie();
    for (int i = 0; i < s2.getNrExcursiiOptionale(); i++) {
        cout << pretExcursie2[i] << endl;
    }
    delete pretExcursie2;
    cout << endl;
    Sejur s3= s1--;
    cout << s3;
    cout << s1<<endl;
}

