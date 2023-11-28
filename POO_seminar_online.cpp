
/*clasa spital cu urm atribute :
-cif(cod de indentificare fiscala - se atribuie valoare la crearea atributului, iar mai apoi nu se mai schimba- de tip sir de caractere
-nume(sir de caractere)
-adresa(sir de caractere)
-medici (valori string , alocat dinamic)
-nrSpitale(va retine nr de spitale-obiecte de tip spital, instantiate vreodate-static,intreg)

Se vor implementa:
-constructor fara parametri 
-constructor cu toti parametrii necesari instantierii unui obiect complet
-constructor de copiere
-destructor

-supraincarcare operator = 
-supraincarcare operatori de citire si scriere din / in consola(>> si<<)
-supraincarcare op [] - returneaza medicul de pe o pozitie data  - atat in mod scriere cat si in mod citire
-supraincarcare !
-cast explicit int - returneaza numarul de spitale instantiate

-metode de get si set

- cel putin unul dintre atributele de tip sir de caractere trebuie sa fie de tip char*

-toate atributele sa fie private
*/
#include <iostream>
using namespace std;

class Spital {
private:
    const string cif;
    char* nume;
    string adresa;
    string* medici;
    int nrMedici;
    static int nrSpitale;

public:
    Spital() :cif("") {
        this->nume = nullptr;
        this->adresa = "";
        this->medici = nullptr;
        this->nrMedici = 0;
        Spital::nrSpitale++;
    }

    Spital(string cif, const char* nume, string adresa, const string* medici, int nrMedici):cif(cif),adresa(adresa),nrMedici(nrMedici) {
        if (nume != nullptr) {
            this->nume = new char[strlen(nume) + 1];
            strcpy_s(this->nume, strlen(nume) + 1, nume);
        }
        else
            this->nume = nullptr;

        this->medici = new string[nrMedici];
        for (int i = 0; i < this->nrMedici; i++) {
            this->medici[i] = medici[i];
        }

        Spital::nrSpitale++;
    }
    //!!!!
    Spital(const Spital& s):Spital(s.cif,s.nume,s.adresa,s.medici,s.nrMedici) 
        {}

    Spital& operator=(const Spital& s) {
        if (this == &s) {
            return *this;
        }
        delete[] this->nume;
        this->nume = new char[strlen(s.nume) + 1];
        strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);

        this->adresa = s.adresa;

        this->nrMedici = s.nrMedici;

        delete[] this->medici;

        this->medici = new string[this->nrMedici];
        for (int i = 0; i < this->nrMedici; i++) {
            this->medici[i] = s.medici[i];
        }


        return *this;
    }

    void setNume(char* nume) {
        if (this->nume != nullptr) {
            delete[] this->nume;
        }

        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    }

    void setAdresa(string adresa) {
        this->adresa = adresa;
    }

    void setMedici(const string* medici, int nrMedici) {
        if (this->medici != nullptr) {
            delete[] this->medici;
        }

        if (medici != nullptr && nrMedici != 0) {

            this->medici = new string[nrMedici];
            for (int i = 0; i < nrMedici; i++) {
                this->medici[i] = medici[i];
            }

        }
        else {
            this->medici = nullptr;
            this->nrMedici = 0;
        }
    }

    char* getName() {
        char* copie = new char[strlen(this->nume) + 1];
        strcpy_s(copie, strlen(this->nume) + 1, this->nume);
        return copie;
    }

    string* getMedici() {
        string* copie = new string[this->nrMedici];
        for (int i = 0; i < this->nrMedici; i++) {
            copie[i] = this->medici[i];
        }
        return copie;
    }

    explicit operator int() {
        return Spital::nrSpitale;
    }

    friend ostream& operator<<(ostream& out, const Spital s) {
        out << "Cif: " << s.cif << endl;
        out << "Nume: " << s.nume << endl;
        out << "Adresa: " << s.adresa << endl;
        for (int i = 0; i < s.nrMedici; i++) {
            out << "Medicul " << i << " :" << s.medici[i] << endl;
        }
        out << "Numarul de medici: " << s.nrMedici << endl;
        out << "Numarul de spitale: " << s.nrSpitale << endl;

        return out;
    }

    friend istream& operator>>(istream& in, Spital& s) {
        cout << "Nume: ";
        char* tmp = new char[250];
        in.getline(tmp,250);

        s.nume = new char[strlen(tmp)+1];
        strcpy_s(s.nume, strlen(tmp) + 1, tmp);


        cout << "Adresa: ";
        in.getline(tmp, 250);
        s.setAdresa(tmp);

        cout << "Numar medici: ";
        in >> s.nrMedici;
        s.medici = new string[s.nrMedici];
        for (int i = 0; i < s.nrMedici; i++) {
            cout << "Medicul " << i<<" :";
            in >> s.medici[i];
        }
        return in;

    }



    ~Spital() {
        delete[] this->nume;
        delete[] this->medici;
        Spital::nrSpitale--; // daca cerinta ar fi ca nr spitale sa tina contorul nr spitalelor active
    }

};
int Spital::nrSpitale = 0;
int main()
{
    string* medic = new string[3];
    medic[0] = "Medic 1";
    medic[1] = "Medic 2";
    medic[2] = "Medic 3";

    Spital s1, s2("123","Floreasca", "Bucuresti", medic, 3);
    s1 = s2;
    s1.setNume((char*)"Spital");
    cout << s2;

    Spital s3;
   // cin >> s3;
    //cout << s3;
    
    cout <<endl<< (int)s1;

}

