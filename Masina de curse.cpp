#include <iostream>
using namespace std;


class MasinaDeCurse {
private:
    const string serieMasina;
    string numeEchipa;
    char* numeSponsor;
    int nrTururiGrandPrix;
    float lungimeTur;
    int nrTururiEfectuate;
    float* timpPeTurEfectuat;
    static float timpMinimPeTur;

public:

    MasinaDeCurse() :serieMasina("0"), numeEchipa(""), nrTururiEfectuate(0), lungimeTur(0), nrTururiGrandPrix(10) {
        this->numeSponsor = nullptr;
        this->timpPeTurEfectuat = nullptr;
    }

    MasinaDeCurse(string numeEchipa, float lungimeTur, float* timpPeTurEfectuat, int nrTururiEfectuate) :serieMasina("123A"), numeEchipa(numeEchipa), lungimeTur(lungimeTur), nrTururiEfectuate(nrTururiEfectuate) {
        this->numeSponsor = nullptr;
        this->nrTururiGrandPrix = 10;

        delete[] this->timpPeTurEfectuat;
        this->timpPeTurEfectuat = new float[this->nrTururiEfectuate];
        for (int i = 0; i < this->nrTururiEfectuate; i++) {
            this->timpPeTurEfectuat[i] = timpPeTurEfectuat[i];
        }
    }

    ~MasinaDeCurse() {
        delete[] this->timpPeTurEfectuat;
        delete[] this->numeSponsor;
    }

    MasinaDeCurse(const MasinaDeCurse& m) : serieMasina(m.serieMasina), numeEchipa(m.numeEchipa), lungimeTur(m.lungimeTur), nrTururiEfectuate(m.nrTururiEfectuate) {
        this->numeSponsor = nullptr;
        this->nrTururiGrandPrix = 0;
        if (this->nrTururiEfectuate != 0) {
            this->timpPeTurEfectuat = new float[this->nrTururiEfectuate];
            for (int i = 0; i < this->nrTururiEfectuate; i++) {
                this->timpPeTurEfectuat[i] = m.timpPeTurEfectuat[i];
            }
        }
        
    }

    MasinaDeCurse& operator=(const MasinaDeCurse& m) {
        this->numeEchipa = m.numeEchipa;
        this->numeSponsor = nullptr;
        this->lungimeTur = m.lungimeTur;
        this->nrTururiEfectuate = m.nrTururiEfectuate;
        this->nrTururiGrandPrix = 0;

        this->timpPeTurEfectuat = new float[this->nrTururiEfectuate];
        for (int i = 0; i < this->nrTururiEfectuate; i++) {
            this->timpPeTurEfectuat[i] = m.timpPeTurEfectuat[i];
        }
        return *this;
    }

    friend istream& operator>>(istream& in, MasinaDeCurse& m) {
        cout << "Nume echipa: " << endl;
        in >> m.numeEchipa;

        cout << "Nume sponsor: " << endl;
        string buffer;
        in >> buffer;

        m.numeSponsor = new char[buffer.length() + 1];
        strcpy_s(m.numeSponsor, buffer.length() + 1, buffer.c_str());

        cout << "Numar tururi Grand Prix: " << endl;
        in >> m.nrTururiGrandPrix;

        cout << "Lungime tur: " << endl;
        in >> m.lungimeTur;

        cout << "Numar tururi efectuate: " << endl;
        in >> m.nrTururiEfectuate;

        m.timpPeTurEfectuat = new float[m.nrTururiEfectuate];

        for (int i = 0; i < m.nrTururiEfectuate; i++) {
            cout << "Timpul de pe tura " << i << " :";
            in >> m.timpPeTurEfectuat[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const MasinaDeCurse m) {
        out << "Serie: " << m.serieMasina<<endl;
        out << "Nume echipa: " << m.numeEchipa << endl;
        //out << "Nume sponsor: " << m.numeSponsor << endl;
        out << "Numar Tururi Grand Prix: " << m.nrTururiGrandPrix << endl;
        out << "Lungime tur: " << m.lungimeTur << endl;
        out << "Numarul tururilor efectuate: " << m.nrTururiEfectuate << endl;
        for (int i = 0; i < m.nrTururiEfectuate; i++) {
            out << "Turul " << i << " a fost parcurs in " << m.timpPeTurEfectuat[i] << endl;
        }
       // out << m.timpMinimPeTur;
        return out;
    }

    MasinaDeCurse& operator+=(float lungimeTur) {
        if (this->nrTururiEfectuate < this->nrTururiGrandPrix) {
            this->nrTururiEfectuate++;
            float* copie = new float[this->nrTururiEfectuate];
            for (int i = 0; i < this->nrTururiEfectuate - 1; i++) {
                copie[i] = this->timpPeTurEfectuat[i];
            }
            copie[this->nrTururiEfectuate - 1] = lungimeTur;
            this->timpPeTurEfectuat = new float[this->nrTururiEfectuate];
            this->timpPeTurEfectuat = copie;
        }
        return *this;
    }

    bool operator<(const MasinaDeCurse m) {
        int m1 = 0;
        int m2 = 0;
        for (int i = 0; i < this->nrTururiEfectuate; i++) {
            if (this->timpPeTurEfectuat[i] > m.timpPeTurEfectuat[i]) m1++;
            else m2++;
        }
        if (m1 > m2) return false;
        return true;
    }


};

float MasinaDeCurse::timpMinimPeTur = 1;
int main()
{
    float timp[] = { 12.0,13.0,14.0,15,16 };
    MasinaDeCurse m1 = { "Echipa",120,timp,5 };
    cout << m1;

    cout << endl << endl;
    m1 += 10;
    cout << m1;

    MasinaDeCurse m2;
    cin >> m2;

    cout << m2;

    bool raspuns = m1 < m2;
    cout << raspuns;
}

