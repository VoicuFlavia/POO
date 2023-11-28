#include <iostream>
using namespace std;

class Fisier {
private:
    const int codFisier;
    string numeFisier;
    int nrAccesari;
    string* editori;

public:

    Fisier() : codFisier(0),numeFisier(""), nrAccesari(0) {
        this->editori = nullptr;
    }

    Fisier(int codFisier, string numeFisier, int nrAccesari, const string* editori):codFisier(codFisier),nrAccesari(nrAccesari) {
        if (numeFisier.length() > 5) {
            this->numeFisier = numeFisier;
        }
        else {
            this->numeFisier = "";
        }
        this->editori = new string[this->nrAccesari];
        for (int i = 0; i < this->nrAccesari; i++) {
            this->editori[i] = editori[i];
        }
    }

    Fisier(const Fisier& f) :Fisier(f.codFisier, f.numeFisier, f.nrAccesari, f.editori) {
     
    }

    ~Fisier() {
        delete[] this->editori;
    }

    string* getEditor() {
        if (this->editori != nullptr && this->nrAccesari!=0) {
            string* copie = new string[this->nrAccesari];
            for (int i = 0; i < this->nrAccesari; i++) {
                copie[i] = this->editori[i];
            }
            return copie;
        }
        return nullptr;
    }

    Fisier& operator=(const Fisier& f) {
        if (this == &f) {
            return *this;
        }

        this->numeFisier = f.numeFisier;
        this->nrAccesari = f.nrAccesari;


        delete[] this->editori;
        if (f.nrAccesari != 0 && f.editori != nullptr) {
            this->editori = new string[this->nrAccesari];

            for (int i = 0; i < this->nrAccesari; i++) {
                this->editori[i] = f.editori[i];
            }
        }
        else {
            this->editori = nullptr;
            this->nrAccesari = 0;
        }

        return *this;
    }

    void setEditor(string* editori, int nrAccesari) {
        if (editori != nullptr && nrAccesari != 0) {
            delete[] this->editori;

            this->nrAccesari = nrAccesari;
            this->editori = new string[this->nrAccesari];

            for (int i = 0; i < this->nrAccesari; i++) {
                this->editori[i] = editori[i];
            }
        }
    }

    friend ostream& operator<<(ostream& out, const Fisier f) {
        out << "Cod fisier: " << f.codFisier << endl;
        out << "Nume fisier: " << f.numeFisier << endl;
        out << "Nr accesari: " << f.nrAccesari << endl;
        for (int i = 0; i < f.nrAccesari; i++) {
            out << "Accesarea " << i << " :" << f.editori[i] << endl;
        }

        return out;
    }

    
    friend istream& operator>>(istream& in, Fisier& f) {
        cout << "Nume fisier: " << endl;
        char buffer[256];
        in.getline(buffer, 255);

        f.numeFisier = (string)buffer;

        cout << "Nr accesari: " << endl;
        in >> f.nrAccesari;

        delete[] f.editori;
        f.editori = new string[f.nrAccesari];
        in.getline(buffer, 255);
        for (int i = 0; i < f.nrAccesari; i++) {
            cout << "Accesarea " << i << " :"<<endl;
            in.getline(buffer, 255);
            f.editori[i] = buffer;
        }

        return in;
    }

    bool operator>(const Fisier f) {
        if (this->numeFisier.length() > f.numeFisier.length()) {
            return true;
        }
        return false;
    }

    string& operator[](int index) {
        return this->editori[index];
    }

};
int main() {
    // Example data for the first file
    string editori1[] = { "Editor1", "Editor2", "Editor3" };
    Fisier fisier1(1, "File1.txt", 3, editori1);

    // Example data for the second file
    string editori2[] = { "EditorA", "EditorB" };
    Fisier fisier2(2, "File2.txt", 2, editori2);

    // Outputting file details using the overloaded << operator
    cout << "Details of File 1:\n" << fisier1 << endl;
    cout << "Details of File 2:\n" << fisier2 << endl;

    // Comparing files based on the length of their names using the overloaded > operator
    if (fisier1 > fisier2) {
        cout << "File 1 has a longer name than File 2.\n";
    }
    else {
        cout << "File 2 has a longer name than File 1.\n";
    }

    // Using the [] operator to access an editor of File 1
    cout << "First editor of File 1: " << fisier1[0] << endl;

    // Using the copy constructor to create a new file with the same details as File 1
    Fisier fisier3(fisier1);
    cout << "Details of File 3 (copy of File 1):\n" << fisier3 << endl;

    // Using the assignment operator to copy details from File 2 to File 3
    fisier3 = fisier2;
    cout << "Details of File 3 after assignment from File 2:\n" << fisier3 << endl;

    Fisier f4;
    cin >> f4;

    return 0;
}

