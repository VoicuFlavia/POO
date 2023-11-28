#include<string.h>
#include <iostream>

using namespace std;

class CartelaTransport {
private:
    const string serieCartela;
    string numePosesor;
    char* producatorCartela;
    int nrZileUtilizate;
    float sumaPortofel;
    int nrCalatorii;
    float* valoriCalatorii;
    static float valoareMinCalatorie;

public:
    //constructor fara parametri
    CartelaTransport(): serieCartela("12345") 
    {
        numePosesor = "anonim";
        producatorCartela = nullptr;
        nrZileUtilizate = 0;
        sumaPortofel = 0;
        nrCalatorii = 0;
        valoriCalatorii = nullptr;
    }

    //constructor

    CartelaTransport(string numePosesor, float sumaPortofel,int nrCalatorii, float* valoriCalatorii, char* producator, int nrZile) :serieCartela("12345") {
        this->numePosesor = numePosesor;

        this->sumaPortofel = sumaPortofel;

        this->nrCalatorii = nrCalatorii;
        this->valoriCalatorii = new float[this->nrCalatorii];
        for (int i = 0; i < this->nrCalatorii; i++) {
            this->valoriCalatorii[i] = valoriCalatorii[i];
        }

        this->producatorCartela = new char[strlen(producator) + 1];
        strcpy_s(this->producatorCartela, strlen(producator) + 1, producator);

        this->nrZileUtilizate = nrZile;
    }

    //destructor

    ~CartelaTransport() {
        delete[] producatorCartela;
        delete[] valoriCalatorii;
    }

    //constructor de copiere

    CartelaTransport(const CartelaTransport& c) {
        this->numePosesor = c.numePosesor;

        if (c.producatorCartela != nullptr) {
            this->producatorCartela = new char[strlen(c.producatorCartela) + 1];
            strcpy_s(this->producatorCartela, strlen(c.producatorCartela) + 1, c.producatorCartela);
        }

        this->nrZileUtilizate = c.nrZileUtilizate;

        this->sumaPortofel = c.sumaPortofel;

        this->nrCalatorii = c.nrCalatorii;

        this->valoriCalatorii = new float[this->nrCalatorii];
        for (int i = 0; i < this->nrCalatorii; i++) {
            this->valoriCalatorii[i] = c.valoriCalatorii[i];
        }
    }

    //get
    string getNumePosesor() {
        return this->numePosesor;
    }

    float* getValoriCalatorii() {
        float* copie = new float[this->nrCalatorii];
        for (int i = 0; i < this->nrCalatorii; i++) {
            copie[i] = this->valoriCalatorii[i];
        }
        return copie;
    }


    char* getProducatorCartela() {
        char* copie = new char[strlen(this->producatorCartela) + 1];
        strcpy_s(copie, strlen(this->producatorCartela) + 1, this->producatorCartela);
        return copie;
    }

    //set

    void setProducatorCartela(char* producator) {
        this->producatorCartela = new char[strlen(producator) + 1];
        strcpy_s(this->producatorCartela, strlen(producator) + 1, producator);
    }

    void setValoriCalatorii(float* valori) {
        delete[] this->producatorCartela;
        this->valoriCalatorii = new float[sizeof(this->nrCalatorii)];
        for (int i = 0; i < this->nrCalatorii; i++) {
            this->valoriCalatorii[i] = valori[i];
        }
    }


    float medieSumaPeZi() {
        float suma = 0;
        for (int i = 0; i < this->nrCalatorii; i++) {
            suma += this->valoriCalatorii[i];
        }
        return suma / this->nrZileUtilizate;
    }

    CartelaTransport& operator=(const CartelaTransport& c) {
        this->numePosesor = c.numePosesor;

        if (c.producatorCartela != nullptr) {
            this->producatorCartela = new char[strlen(c.producatorCartela) + 1];
            strcpy_s(this->producatorCartela, strlen(c.producatorCartela) + 1, c.producatorCartela);
        }

        this->nrZileUtilizate = c.nrZileUtilizate;

        this->sumaPortofel = c.sumaPortofel;

        this->nrCalatorii = c.nrCalatorii;

        this->valoriCalatorii = new float[this->nrCalatorii];
        for (int i = 0; i < this->nrCalatorii; i++) {
            this->valoriCalatorii[i] = c.valoriCalatorii[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, CartelaTransport c) {
       // out << "Seria cartelei: " << c.serieCartela << endl;
        if (c.producatorCartela != nullptr) {
            out << "Numele Posesorului: " << c.numePosesor << endl;
        }
        
        out << "Numarul de zile utilizate: " << c.nrZileUtilizate << endl;

        out << "Suma de pe portofelul electronic: " << c.sumaPortofel << endl;

        out << "Numarul de calatorii efectuate: " << c.nrCalatorii << endl;

        out << "Valorile calatoriilor: " << endl;
        for (int i = 0; i < c.nrCalatorii; i++) {
            out << "Calatoria " << i << " are valoarea " << c.valoriCalatorii[i] << " lei" << endl;
        }

        out << "Valoarea medie pe zi a calatoriilor este de " << c.medieSumaPeZi() << " lei" << endl;

        return out;
    }

    friend istream& operator>>(istream& in, CartelaTransport& c) {
        cout << "Introduceti numele posesorului: " << endl;
        string buffer;
        in >> c.numePosesor;

        cout << "Introduceti numele producatorului: " << endl;
        in >> buffer;
        c.producatorCartela = new char[buffer.length() + 1];
        strcpy_s(c.producatorCartela, buffer.length() + 1, buffer.c_str());

        cout << "Introduceti numarul de zile utilizate: " << endl;
        in >> c.nrZileUtilizate;

        cout << "Introduceti suma de pe portofelul electronic: " << endl;
        in >> c.sumaPortofel;

        cout << "Introduceti numarul de calatorii efectuate: " << endl;
        in >> c.nrCalatorii;

        cout << "Introduceti valoarea fiecare calatorii: " << endl;
        c.valoriCalatorii = new float[c.nrCalatorii];
        for (int i = 0; i < c.nrCalatorii; i++) {
            cout << endl;
            cout << "Calatoria " << i << " a costat :";
            in >> c.valoriCalatorii[i];
            cout << " lei";
        }
        return in;
    }

    void operator+=(float bani) {
        float suma = 0;
        for (int i = 0; i < this->nrCalatorii; i++) {
            suma += this->valoriCalatorii[i];
        }

        if (suma + bani <= this->sumaPortofel) {
            this->sumaPortofel = this->sumaPortofel + bani;
            this->nrCalatorii++;

            float* copie = new float[this->nrCalatorii];
            for (int i = 0; i < this->nrCalatorii-1; i++)
                copie[i] = this->valoriCalatorii[i];

            copie[this->nrCalatorii-1] = bani;
            this->valoriCalatorii = new float[this->nrCalatorii];
            for (int i = 0; i < this->nrCalatorii; i++) {
                this->valoriCalatorii[i] = copie[i];
            }
            delete [] copie;
        }
    }

    bool operator>(CartelaTransport c) {
        if (this->sumaPortofel > c.sumaPortofel) {
            return true;
        }
        return false;
    }



};
//int CartelaTransport::valoareMinCalatorie=3;
int main()
{
    float calatorii[] = {1.02,3.67,1.90,2.45,3.78};
    CartelaTransport c1 = { "Iulian",17.30,5,calatorii,(char*)"Metrorex",5};
    //cout<<c1;

    /*CartelaTransport c2;
    c2 = c1;

    cout << endl;
    cout << c2;
    cout << endl;
    c1 += 20;
    cout << c1;
    CartelaTransport c3 = { "Mihnea",16,5,calatorii,(char*)"STB",5 };
    bool raspuns = c1 > c3;
    cout << raspuns;*/
    cout << endl;
    CartelaTransport c4;
    cin >> c4;
    c4 += 2;
    cout << c4;
    bool raspuns1 = c4 > c1;
    cout << raspuns1;

}


