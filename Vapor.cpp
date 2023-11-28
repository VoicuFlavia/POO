// Vapor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string.h>
using namespace std;

class Vapor {
private:
    static int nrVapoare;
    int capacitate;
    int nrPersoaneImbarcate;
    int* varstePasageri;
    char* plecare; // de unde pleaca vaporul
    char* sosire; //unde soseste vaporul

public:
    Vapor() {
        this->capacitate = 0;
        this->nrPersoaneImbarcate = 0;
        this->varstePasageri = nullptr;
        this->plecare = nullptr;
        this->sosire = nullptr;
    }

    //constructor

    Vapor(int capacitate, int nrPersoane, int* varste, char* plecare, char* sosire) {
        this->capacitate = capacitate;
        if (nrPersoane < capacitate) {
            this->nrPersoaneImbarcate = nrPersoane;
        }
        else {
            this->nrPersoaneImbarcate = 0;
        }

        if (varste != nullptr && nrPersoane < capacitate) {
            this->varstePasageri = new int[this->nrPersoaneImbarcate];
            for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
                this->varstePasageri[i] = varste[i];
            }
        }
        else {
            this->varstePasageri = nullptr;
        }

        this->plecare = new char[strlen(plecare) + 1];
        strcpy_s(this->plecare, strlen(plecare) + 1, plecare);

        this->sosire = new char[strlen(sosire) + 1];
        strcpy_s(this->sosire, strlen(sosire) + 1, sosire);

    }

    //destructor

    ~Vapor() {
        delete[] this->varstePasageri;
        delete[] this->plecare;
        delete[] this->sosire;
    }

    //constructor de copiere

    Vapor(const Vapor& v) {
        this->capacitate = v.capacitate;

        this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
        this->varstePasageri = new int[v.nrPersoaneImbarcate];
            for (int i = 0; i < v.nrPersoaneImbarcate; i++) {
                this->varstePasageri[i] = v.varstePasageri[i];
            }

            this->plecare = new char[strlen(v.plecare) + 1];
            strcpy_s(this->plecare, strlen(v.plecare) + 1, v.plecare);

            this->sosire = new char[strlen(v.sosire) + 1];
            strcpy_s(this->sosire, strlen(v.sosire) + 1, v.sosire);
    }
    //get

    int getCapacitate() {
        return this->capacitate;
    }

    int getNrPersoaneImbarcate() {
        return this->nrPersoaneImbarcate;
    }

    int* getVarstePasageri() {
        int* copie = new int[this->nrPersoaneImbarcate];
        for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
            copie[i] = this->varstePasageri[i];
        }
        return copie;
    }

    char* getPlecare() {
        char* copie = new char[strlen(this->plecare) + 1];
        strcpy_s(copie, strlen(this->plecare) + 1, this->plecare);
        return copie;
    }

    char* getSosire() {
        char* copie = new char[strlen(this->sosire) + 1];
        strcpy_s(copie, strlen(this->sosire) + 1, this->sosire);
        return copie;
    }

    //set

    void setCapacitate(int capacitate) {
        this->capacitate = capacitate;
    }

    void setNrPersoaneImbarcate(int persoane) {
        this->nrPersoaneImbarcate = persoane;
    }

    void setVarstePasageri(int* varste) {
        varstePasageri = new int[this->nrPersoaneImbarcate];
        if (varste != nullptr) {
            for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
                this->varstePasageri[i] = varste[i];
            }
        }
    }

    void setPlecare(char* plecare) {
        if (plecare != nullptr) {
            this->plecare = new char[strlen(plecare) + 1];
            strcpy_s(this->plecare, strlen(plecare) + 1, plecare);
        }
    }

    void setSosire(char* sosire) {
        if (sosire != nullptr) {
            this->sosire = new char[strlen(sosire) + 1];
            strcpy_s(this->sosire, strlen(sosire) + 1, sosire);
        }
    }

    Vapor& operator=(const Vapor& v) {

        /*if (this->plecare != nullptr) {
            delete[] this->plecare;
            this->plecare = nullptr;
        }

        if (this->varstePasageri != nullptr) {
            delete[] this->varstePasageri;
            this->varstePasageri = nullptr;
        }

        if (this->sosire != nullptr) {
            delete[] this->sosire;
            this->sosire = nullptr;
        }*/

        this->capacitate = v.capacitate;

        this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;

            this->varstePasageri = new int[v.nrPersoaneImbarcate];
            for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
                this->varstePasageri[i] = v.varstePasageri[i];
            }


            this->plecare = new char[strlen(v.plecare) + 1];
            strcpy_s(this->plecare, strlen(v.plecare) + 1, v.plecare);

        this->sosire = new char[strlen(v.sosire) + 1];
        strcpy_s(this->sosire, strlen(v.sosire) + 1, v.sosire);
        return *this;
    }

    friend ostream& operator<<(ostream& out, Vapor v) {
        out << "Capacitate: " << v.capacitate << endl;
        out << "Numarul de persoane imbarcate este: " << v.nrPersoaneImbarcate << endl;
        out << "Varstele pasagerilor:" << endl;
        for (int i = 0; i < v.nrPersoaneImbarcate; i++) {
            out << "Pasagerul " << i << " are varsta de " << v.varstePasageri[i] << " ani" << endl;
        }
        out << "Vaporul pleaca din " << v.plecare << endl;
        out << "Vaporul soseste in " << v.sosire << endl;
        int medie = v.calculareVarstaMedie();
        out << "Varsta medie a persoanelor imbarcate este de " << medie << " ani" << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Vapor& v) {
        cout << "Capacitate: " << endl;
        in >> v.capacitate;

        cout << "Numarul persoanelor de pe vapor: " << endl;
        in >> v.nrPersoaneImbarcate;

        cout << "Varsta persoanelor de pe vapor: " << endl;
        int varsta;
        v.varstePasageri = new int[v.nrPersoaneImbarcate];
        for (int i = 0; i < v.nrPersoaneImbarcate; i++) {
            in >> varsta;
            v.varstePasageri[i] = varsta;
        }

        cout << "Locul de plecare al vaporului: " << endl;
        string buffer;
        in >> buffer;
        v.plecare = new char[buffer.length() + 1];
        strcpy_s(v.plecare, buffer.length() + 1, buffer.c_str());

        cout << "Locul de sosire al vaporului: " << endl;
        in >> buffer;
        v.sosire = new char[buffer.length() + 1];
        strcpy_s(v.sosire, buffer.length() + 1, buffer.c_str());
        return in;
    }

    int calculareVarstaMedie() {
        int suma = 0;
        int* copie = new int[this->nrPersoaneImbarcate];
        for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
            copie[i] = this->varstePasageri[i];
            suma = suma + copie[i];
        }
        int medie = suma / this->nrPersoaneImbarcate;
        return medie;
    }

    int operator()() {
        return this->capacitate - this->nrPersoaneImbarcate;
    }

    Vapor& operator++(int) {
        Vapor copie(*this);
        this->nrPersoaneImbarcate++;
        int* copieptr = new int[this->nrPersoaneImbarcate];
        for (int i = 0; i < this->nrPersoaneImbarcate - 1; i++) {
            copieptr[i] = this->varstePasageri[i];
        }
        copieptr[this->nrPersoaneImbarcate - 1] = 0;
        delete[] this->varstePasageri;
        this->varstePasageri = new int[this->nrPersoaneImbarcate];
        for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
            this->varstePasageri[i]= copieptr[i] ;
        }

        return copie;
    }
};

int Vapor::nrVapoare = 1;
int main()
{
    int varste[] = { 20,21,22,23,24 };
    Vapor v1(10, 5, varste, (char*)"Romania", (char*)"Italia");

    Vapor v2 = v1;

    Vapor v3;
    v3 = v1;
    cout << "Pe vapor mai pot fi imbarcate inca " << v1() << " persoane" << endl;
    cout << v3;

    Vapor v4=v1++;
    cout << v4;
}

