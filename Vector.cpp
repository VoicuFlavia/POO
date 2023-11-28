#include <iostream>
using namespace std;

class Vector {
private:
    const int id_unic;
    char* denumire;
    float* elemente;
    int nrElemente;
    string owner;
    static string supportGuy;

public:
    Vector(): id_unic(0){
        denumire = nullptr;
        elemente = nullptr;
        nrElemente = 0;
        owner = "";
    }

    Vector(int id_unic, char* denumire, float* elemente, int nrElemente, string owner) : id_unic(id_unic), nrElemente(nrElemente), owner(owner) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

        this->elemente = new float[this->nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            this->elemente[i] = elemente[i];
        }
    }

    Vector(float* elemente, int nrElemente, string owner) : id_unic(0), nrElemente(nrElemente), owner(owner) {
        this->elemente = new float[this->nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            this->elemente[i] = elemente[i];
        }
        this->denumire = nullptr;
    }

    Vector(const Vector& v): id_unic(v.id_unic), nrElemente(v.nrElemente), owner(v.owner) {
        this->denumire = new char[strlen(v.denumire) + 1];
        strcpy_s(this->denumire, strlen(v.denumire) + 1, v.denumire);

        this->elemente = new float[v.nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            this->elemente[i] = v.elemente[i];
        }
    }

    ~Vector(){
        delete[] this->denumire;
        delete[] this->elemente;
    }

    Vector& operator=(Vector& v){
        this->nrElemente = v.nrElemente;

        delete[] this->denumire;
        this->denumire = new char[strlen(v.denumire) + 1];
        strcpy_s(this->denumire, strlen(v.denumire) + 1, v.denumire);

        delete[] this->elemente;
        this->elemente = new float[v.nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            this->elemente[i] = v.elemente[i];
        }

        this->owner = v.owner;
        return *this;
    }

    //get

    char* getDenumire() {
        char* copie = new char[strlen(this->denumire) + 1];
        strcpy_s(copie, strlen(this->denumire) + 1, this->denumire);
        return copie;
    }

    float* getElemente() {
        float* copie = new float[this->nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            copie[i] = this->elemente[i];
        }
        return copie;
    }

    //set

    void setDenumire(char* denumire) {
        delete[] this->denumire;
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
    }

    void setElemente(float* elemente) {
        delete[] this->elemente;
        this->elemente = new float[this->nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            this->elemente[i] = elemente[i];
        }
    }

    friend ostream& operator<<(ostream& out, Vector v) {
        out << "Id-ul unic: " << v.id_unic<<endl;
        out << "Denumire: " << v.denumire<<endl;
        for (int i = 0; i < v.nrElemente; i++) {
            out << "Elementul " << i << " :" << v.elemente[i] << endl;
        }
        out << "Numarul de elemente: " << v.nrElemente << endl;
        out << "Owner: " << v.owner << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Vector& v) {
        cout << "Denumire:" << endl;
        char* buffer;
        in >> buffer;
        v.denumire = new char[strlen(buffer) + 1];
        cout << "Numarul de elemente:" << endl;
        in >> v.nrElemente;
        for (int i = 0; i < v.nrElemente; i++) {
            cout<< "Introduceti elementul " << i << " :";
            in >> v.elemente[i];
        }
        cout << "Owner: " << endl;
        in >> v.owner;
        return in;
    }

    Vector& operator[](float valoare) {
        for (int i = 0; i < this->nrElemente; i++) {
            this->elemente[i] += valoare;
        }
        return *this;
    }


    Vector& operator+=(float element) {
        this->nrElemente++;
        float* copie = new float[this->nrElemente];
        for (int i = 0; i < this->nrElemente - 1; i++) {
            copie[i] = this->elemente[i];
        }
        copie[this->nrElemente - 1] = element;
        this->elemente = copie;
        return *this;
    }

    Vector& operator--() {
        this->nrElemente--;
        float* copie = new float[this->nrElemente];
        for (int i = 0; i < this->nrElemente; i++) {
            copie[i] = this->elemente[i];
        }
        this->elemente = copie;
        return *this;
    }
};

string Vector::supportGuy = "Andrei";



int main()
{
    float elemente[] = { 1,2,3,4,5 };
    Vector v1(10, (char*)"Vector", elemente, 5, "ION");
    Vector v2;
    v2 = v1[1];
    v2 += (19);
    cout << v2 << endl;
    Vector v3 = --v2;
    cout << v3;
}

