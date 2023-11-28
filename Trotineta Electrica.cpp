#include <iostream>
using namespace std;

class TrotinetaElectrica {
private:
    string model;
    float nivelBaterie;
    const float consumPerKm;
    float* kmPerSesiuneInchiriere;
    int nrSesiuniInchiriere;
    static int NIVEL_MAXIM_BATERIE;

public:

    TrotinetaElectrica() : model(""), nivelBaterie(0), consumPerKm(0), nrSesiuniInchiriere(0) {
        this->kmPerSesiuneInchiriere = nullptr;
    }

    TrotinetaElectrica(string model, float nivelBaterie, float consum, float* kmPerSesiune, int nrSesiuni) : model(model), nivelBaterie(nivelBaterie), consumPerKm(consum), nrSesiuniInchiriere(nrSesiuni){
        this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
        for (int i = 0; i < this->nrSesiuniInchiriere; i++) {
            this->kmPerSesiuneInchiriere[i] = kmPerSesiune[i];
        }
    }

    TrotinetaElectrica(const TrotinetaElectrica& t) :model(t.model), nivelBaterie(t.nivelBaterie), consumPerKm(t.consumPerKm), nrSesiuniInchiriere(t.nrSesiuniInchiriere) {
        this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
        for (int i = 0; i < this->nrSesiuniInchiriere; i++) {
            this->kmPerSesiuneInchiriere[i] = t.kmPerSesiuneInchiriere[i];
        }
    }

    TrotinetaElectrica& operator=(const TrotinetaElectrica& t) {
        this->model = t.model;
        this->nivelBaterie = t.nivelBaterie;
        this->nrSesiuniInchiriere = t.nrSesiuniInchiriere;
        this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
        for (int i = 0; i < this->nrSesiuniInchiriere; i++) {
            this->kmPerSesiuneInchiriere[i] = t.kmPerSesiuneInchiriere[i];
        }
        return *this;
    }

    ~TrotinetaElectrica() {
        delete[] this->kmPerSesiuneInchiriere;
    }

    TrotinetaElectrica& utilizeazaTrotineta(float kmParcursi) {
        this->nrSesiuniInchiriere++;
        float* copie = new float[this->nrSesiuniInchiriere];
        for (int i = 0; i < this->nrSesiuniInchiriere - 1; i++) {
            copie[i] = this->kmPerSesiuneInchiriere[i];
        }
        copie[this->nrSesiuniInchiriere - 1] = kmParcursi;
        this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
        this->kmPerSesiuneInchiriere = copie;
        return *this;
    }

    friend ostream& operator<<(ostream& out, TrotinetaElectrica t) {
        out << "Model: " << t.model << endl;
        out << "Nivel baterie: " << t.nivelBaterie << endl;
        out << "Consum per kilometru: " << t.consumPerKm << endl;
        for (int i = 0; i < t.nrSesiuniInchiriere; i++) {
            out << "Sesiunea nr " << i << " a avut " << t.kmPerSesiuneInchiriere[i] << " km" << endl;
        }
        return out;
    }

    string getModel() {
        return this->model;
    }

    int getNrISesiuniInchirieri() {
        return this->nrSesiuniInchiriere;
    }

    float getNivelBaterie() {
        return this->nivelBaterie;
    }

    void incarcaTrotineta(int minute, float rataDeIncarcareMinut) {
        float incarcare = minute * rataDeIncarcareMinut;
        try {
            
            if (incarcare > 0) {
                this->nivelBaterie += incarcare;
            }
            else {
                throw(incarcare);
            }
        }
        catch (float incarcare) {
            cout << "Nu a putut fi incarcata";
        } 
    }

    float kmDeParcurs() {
        return this->nivelBaterie / this->consumPerKm;
    }

    TrotinetaElectrica& operator+(float kmParcursi) {
        this->nrSesiuniInchiriere++;
        float* copie = new float[this->nrSesiuniInchiriere];
        for (int i = 0; i < this->nrSesiuniInchiriere - 1; i++) {
            copie[i] = this->kmPerSesiuneInchiriere[i];
        }
        copie[this->nrSesiuniInchiriere - 1] = kmParcursi;
        delete[] this->kmPerSesiuneInchiriere;
        this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
        this->kmPerSesiuneInchiriere = copie;
        return *this;
    }

    float operator()(int i, int j) {
        float suma = 0;
        if (i>0 && j>0) {
                for (int v = i; v <= j; v++) {
                    suma += this->kmPerSesiuneInchiriere[v];
                }
        }
        return suma;
    }

};

int TrotinetaElectrica::NIVEL_MAXIM_BATERIE = 100;

int main()
{
    float km[] = {1,2,3,4,5};
    TrotinetaElectrica t1 = { "Bolt",12.2,12,km,5 };
    cout << t1;
    cout << endl;
    t1.utilizeazaTrotineta(15);
    cout << t1 << endl;
    cout << t1.kmDeParcurs() << endl;
    t1.incarcaTrotineta(60, 1);
    cout << t1;
    cout << t1 + 10;
    cout << endl;
    float km1 = t1(2, 4);
    cout << km1;
}
