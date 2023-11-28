#include <iostream>
using namespace std;

class Prajitura {
private:
    char* denumire;
    int nrCalorii;
    int nrIngrediente;
    float* gramajIngrediente;
    bool esteVegana;
    static string Firma;

public:

    Prajitura() : nrCalorii(0), nrIngrediente(0), esteVegana(false) {
        this->denumire = nullptr;
        gramajIngrediente = nullptr;
    }

    Prajitura(char* denumire, int nrCalorii, int nrIngrediente, float* gramaj, bool esteVegana) : nrCalorii(nrCalorii), nrIngrediente(nrIngrediente), esteVegana(esteVegana) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

        this->gramajIngrediente = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->gramajIngrediente[i] = gramaj[i];
        }
    }

    ~Prajitura() {
        delete[] this->denumire;
        delete[] this->gramajIngrediente;
    }

    Prajitura(const Prajitura& p) {
        this->nrCalorii = p.nrCalorii;

        this->nrIngrediente = p.nrIngrediente;

        this->esteVegana = p.esteVegana;

        this->denumire = new char[strlen(p.denumire) + 1];
        strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);

        this->gramajIngrediente = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->gramajIngrediente[i] = p.gramajIngrediente[i];
        }
    }

    Prajitura& operator=(const Prajitura& p) {
        this->nrCalorii = p.nrCalorii;

        this->nrIngrediente = p.nrIngrediente;

        this->esteVegana = p.esteVegana;

        this->denumire = new char[strlen(p.denumire) + 1];
        strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);

        this->gramajIngrediente = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->gramajIngrediente[i] = p.gramajIngrediente[i];
        }
        return *this;
    }

    Prajitura& operator*=(int multiplicator) {
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->gramajIngrediente[i] *= multiplicator;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, Prajitura p) {
        out << "Denumire: " << p.denumire << endl;
        out << "Numar calorii: " << p.nrCalorii << endl;
        out << "Numar ingrediente: " << p.nrIngrediente << endl;
        for (int i = 0; i < p.nrIngrediente; i++) {
            out << "Ingredient " << i << " are: " << p.gramajIngrediente[i] << " grame" << endl;
        }
        out << "Prajitura este vegana? " << p.esteVegana << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Prajitura& p) {
        cout << "Denumire: " << endl;
        string buffer;
        in >> buffer;
        delete[] p.denumire;
        p.denumire = new char[buffer.length() + 1];
        strcpy_s(p.denumire, buffer.length() + 1, buffer.c_str());

        cout << "Numar calorii: " << endl;
        in >> p.nrCalorii;

        cout << "Numar ingrediente: " << endl;
        in >> p.nrIngrediente;
        p.gramajIngrediente = new float[p.nrIngrediente];
        for (int i = 0; i < p.nrIngrediente; i++) {
            cout << "Ingredientul " << i << " are: ";
            in >> p.gramajIngrediente[i];
            cout << "grame" << endl;
        }

        cout << "Prajitura este vegana? ";
        string raspuns;
        in >> raspuns;
        if (raspuns == "da") p.esteVegana = true;
        else p.esteVegana = false;

        return in;
    }

    friend Prajitura& operator+(float gramaj, Prajitura& p) {
        p.nrIngrediente++;
        float* copie = new float[p.nrIngrediente];
        for (int i = 0; i < p.nrIngrediente - 1; i++) {
            copie[i] = p.gramajIngrediente[i];
        }
        copie[p.nrIngrediente - 1] = gramaj;
        delete[] p.gramajIngrediente;
        p.gramajIngrediente = new float[p.nrIngrediente];
        p.gramajIngrediente = copie;
        return p;
    }
};
int main()
{
    float ingrediente[] = { 12.43,21.34,232.43,258,33.2 };
    Prajitura p1 = { (char*)"Amandina",300,5,ingrediente,true };
    cout << p1;
    p1 *= 10;
    cout << p1 << endl << endl;
    Prajitura p2= p1;
    cout << p2 << endl << endl;;
    Prajitura p3;
    p3 = 10 + p2;
    cout << p3;

}