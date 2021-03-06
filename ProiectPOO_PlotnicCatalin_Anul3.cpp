#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <vector>
#include <list>
#include <map>
using namespace std;



class Pacienti //clasa pacientii unui spital
{
private:
	char* NumePrenumePacient;
	int varsta;
	string Adresa;
	string boala;
	const int id_Pacient;
	static int nrPacienti;
	bool StareaPacientului; // 0 = insanatosire , 1 = agravare
	static string listaPacienti[50];


public:
	Pacienti() : id_Pacient(++nrPacienti) {
		NumePrenumePacient = new char[strlen("Anonim") + 1];
		strcpy(NumePrenumePacient, "Anonim");
		this->varsta = 0;
		this->Adresa = "Necunoscuta";
		this->boala = "Necunoscuta";
		this->StareaPacientului = NULL;
	}
	Pacienti(const char* NumePrenumePacient, int varsta, string Adresa, string boala, bool StareaPacientului) :id_Pacient(++nrPacienti) {
		this->NumePrenumePacient = new char[strlen(NumePrenumePacient) + 1];
		strcpy(this->NumePrenumePacient, NumePrenumePacient);
		this->varsta = varsta;
		this->Adresa = Adresa;
		this->boala = boala;
		this->StareaPacientului = StareaPacientului;
		this->listaPacienti[id_Pacient - 1] = this->NumePrenumePacient;
	}
	Pacienti(const Pacienti& p) : id_Pacient(p.id_Pacient) {
		this->NumePrenumePacient = new char[strlen(p.NumePrenumePacient) + 1];
		strcpy(this->NumePrenumePacient, p.NumePrenumePacient);
		this->varsta = p.varsta;
		this->Adresa = p.Adresa;
		this->boala = p.boala;
		this->StareaPacientului = p.StareaPacientului;
	}
	~Pacienti()
	{
		delete[] this->NumePrenumePacient;
	}
	//Setteri si getteri
	void setNumePrenumePacient(const char* NumePacient) {
		if (strlen(NumePacient) < 3)
			throw "Data invalida";
		else
		{
			if (this->NumePrenumePacient != NULL)
				delete[] this->NumePrenumePacient;
			this->NumePrenumePacient = new char[strlen(NumePacient) + 1];
			strcpy(this->NumePrenumePacient, NumePacient);
		}
	}
	const char* getNumePrenumePacient() {
		return this->NumePrenumePacient;
	}

	int setVarsta(int varsta) {
		if (varsta > 110 or varsta < 0)
			throw "Data invalida";
		else
			this->varsta = varsta;
	}
	int getVarsta() {
		return this->varsta;
	}
	void setAdresa(string Adresa)
	{
		if (Adresa.size() <= 1) throw "Adresa Pacientului este prea scurt!";
		else
			this->Adresa = Adresa;
	}
	string getAdresa() {
		return this->Adresa;
	}
	void setBoala(string boala)
	{
		if (boala.size() <= 1) throw "Boala Pacientului este prea scurt!";
		else
			this->boala = boala;
	}
	string getBoala() {
		return this->boala;
	}
	int getid_Pacient() {
		return this->id_Pacient;
	}
	int getnrPacienti() {
		return this->nrPacienti;
	}
	void setStareaPacientului(bool StareaPacientului)
	{
		if (StareaPacientului == 1)
			this->StareaPacientului = 1;
		if (StareaPacientului == 0)
			this->StareaPacientului = 0;
		if (StareaPacientului != 1 and StareaPacientului != 0)
			throw "Data invalida";
	}

	bool getStareaPacientului() {
		return this->StareaPacientului;
	}

	Pacienti& operator=(const Pacienti& p) {
		if (this->NumePrenumePacient != NULL) delete[] this->NumePrenumePacient;
		this->NumePrenumePacient = new char[strlen(p.NumePrenumePacient) + 1];
		strcpy(this->NumePrenumePacient, p.NumePrenumePacient);
		this->varsta = p.varsta;
		this->Adresa = p.Adresa;
		this->boala = p.boala;
		this->StareaPacientului = p.StareaPacientului;
		return *this;
	}

	friend ostream& operator<<(ostream& out, Pacienti& p) {
		out << "Id-ul Pacientului: " << p.id_Pacient << endl;
		out << "Nume Prenume Pacient: " << p.NumePrenumePacient << endl;
		out << "Varsta Pacient: " << p.varsta << endl;
		out << "Adresa Pacient: " << p.Adresa << endl;
		out << "Boala: " << p.boala << endl;
		out << "Starea Pacientului: " << p.StareaPacientului << endl;
		return out;
	}
	friend ofstream& operator<<(ofstream& out, Pacienti& p) {
		out << "Id-ul Pacientului: " << p.id_Pacient << endl;
		out << "Nume, Prenume: " << p.NumePrenumePacient << endl;
		out << "Varsta: " << p.varsta << endl;
		out << "Adresa: " << p.Adresa << endl;
		out << "Boala: " << p.boala << endl;
		out << "Starea Pacientului: " << p.StareaPacientului << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Pacienti& p) {
		char caracter[50];
		cout << "Nume, Prenume Pacient: ";
		in >> caracter;
		if (p.NumePrenumePacient != NULL)
			delete[] p.NumePrenumePacient;
		p.NumePrenumePacient = new char[strlen(caracter) + 1];
		strcpy(p.NumePrenumePacient, caracter);

		cout << "Varsta Pacient: ";
		in >> p.varsta;

		cout << "Adresa Pacient:";
		in >> p.Adresa;

		cout << "Boala:";
		in >> p.boala;

		cout << "Starea Pacientului:";
		in >> p.StareaPacientului;

		return in;
	}
	friend ifstream& operator>>(ifstream& in, Pacienti& p) {

		char caracter[50];

		in.getline(caracter, 50);
		if (p.NumePrenumePacient != NULL)
			delete[] p.NumePrenumePacient;
		p.NumePrenumePacient = new char[strlen(caracter) + 1];
		strcpy(p.NumePrenumePacient, caracter);

		in >> p.varsta;
		getline(in, p.Adresa);
		getline(in, p.boala);
		in >> p.StareaPacientului;

		return in;
	}

	bool operator!()
	{
		if (this->varsta > 0)
			return false;
		else
			return true;
	}
	void operator+(int plusVarsta) {
		this->varsta += plusVarsta;
	}

	void operator*(int x) {
		this->varsta *= x;
	}
	Pacienti& operator++() {
		this->varsta++;
		return *this;
	}
	Pacienti& operator++(int n) {
		this->varsta++;
		return *this;
	}
	Pacienti& operator--() {
		this->varsta--;
		return *this;
	}
	Pacienti& operator--(int n) {
		this->varsta--;
		return *this;
	}

};
class Angajati {
private:
	char* data_nastere;
	char* NumePrenumeAngajat;
	char* postDeLucru;
	int experienta;
	int* oreLucratePeZi = NULL;
	int nrZileLucrate;
	string* ZiuaLucrata = NULL;
	static int nrAngajati;
	const int id_Angajat;
	static string listaAngajati[50];
public:
	Angajati() :id_Angajat(++nrAngajati) {
		this->data_nastere = new char[strlen("Necunoscuta") + 1];
		strcpy(this->data_nastere, "Necunoscuta");
		this->NumePrenumeAngajat = new char[strlen("Necunoscut") + 1];
		strcpy(NumePrenumeAngajat, "Necunoscut");
		this->postDeLucru = new char[strlen("Necunoscut") + 1];
		strcpy(postDeLucru, "Necunoscut");
		this->experienta = 0;
		this->oreLucratePeZi = NULL;
		this->nrZileLucrate = 0;
		this->ZiuaLucrata = NULL;
	}
	Angajati(const char* data_nastere, const char* NumePrenumeAngajat, const char* postDeLucru, int experienta, int nrZileLucrate) : id_Angajat(++nrAngajati) {
		this->data_nastere = new char[strlen(data_nastere) + 1];
		strcpy(this->data_nastere, data_nastere);
		this->NumePrenumeAngajat = new char[strlen(NumePrenumeAngajat) + 1];
		strcpy(this->NumePrenumeAngajat, NumePrenumeAngajat);
		this->postDeLucru = new char[strlen(postDeLucru) + 1];
		strcpy(this->postDeLucru, postDeLucru);
		this->experienta = experienta;
		this->nrZileLucrate = 0;
		this->ZiuaLucrata = NULL;
		this->oreLucratePeZi = NULL;
		this->listaAngajati[id_Angajat - 1] = this->NumePrenumeAngajat;
	}
	Angajati(const char* data_nastere, const char* NumePrenumeAngajat, const char* postDeLucru, int experienta, int nrZileLucrate, int* oreLucratePeZi, string* ZiuaLucrata) :id_Angajat(++nrAngajati)
	{
		this->data_nastere = new char[strlen(data_nastere) + 1];
		strcpy(this->data_nastere, data_nastere);
		this->NumePrenumeAngajat = new char[strlen(NumePrenumeAngajat) + 1];
		strcpy(this->NumePrenumeAngajat, NumePrenumeAngajat);
		this->postDeLucru = new char[strlen(postDeLucru) + 1];
		strcpy(this->postDeLucru, postDeLucru);
		this->experienta = experienta;
		this->nrZileLucrate = nrZileLucrate;
		if (nrZileLucrate > 0)
		{
			this->oreLucratePeZi = new int[nrZileLucrate];
			this->ZiuaLucrata = new string[nrZileLucrate];

			for (int i = 0; i < this->nrZileLucrate; i++)
			{
				this->ZiuaLucrata[i] = ZiuaLucrata[i];
				this->oreLucratePeZi[i] = oreLucratePeZi[i];
			}
		}
	}
	Angajati(const Angajati& a) :id_Angajat(a.id_Angajat) {
		this->data_nastere = new char[strlen(a.data_nastere) + 1];
		strcpy(this->data_nastere, a.data_nastere);
		this->NumePrenumeAngajat = new char[strlen(a.NumePrenumeAngajat) + 1];
		strcpy(this->NumePrenumeAngajat, a.NumePrenumeAngajat);
		this->postDeLucru = new char[strlen(a.postDeLucru) + 1];
		strcpy(this->postDeLucru, a.postDeLucru);
		this->experienta = a.experienta;
		this->nrZileLucrate = a.nrZileLucrate;
		this->oreLucratePeZi = new int[this->nrZileLucrate];
		this->ZiuaLucrata = new string[this->nrZileLucrate];
		for (int i = 0; i < this->nrZileLucrate; i++)
		{
			this->oreLucratePeZi[i] = a.oreLucratePeZi[i];
			this->ZiuaLucrata[i] = a.ZiuaLucrata[i];
		}
	}
	~Angajati() {
		if (this->oreLucratePeZi != NULL and this->ZiuaLucrata != NULL)
		{
			delete[] this->oreLucratePeZi;
			delete[] this->ZiuaLucrata;
			nrAngajati--;
		}
	}
	//Setteri si getteri
	void setNumePrenumeAngajat(const char* NumePrenumeAngajat) {
		if (strlen(NumePrenumeAngajat) < 1)
			throw "Data invalida";
		else
		{
			if (this->NumePrenumeAngajat != NULL)
				delete[] this->NumePrenumeAngajat;
			this->NumePrenumeAngajat = new char[strlen(NumePrenumeAngajat) + 1];
			strcpy(this->NumePrenumeAngajat, NumePrenumeAngajat);
		}
	}
	const char* getNumePrenumeANgajat() {
		return this->NumePrenumeAngajat;
	}
	void setpostDeLucru(const char* postDeLucru) {
		if (strlen(postDeLucru) < 1)
			throw "Data invalida";
		else
		{
			if (this->postDeLucru != NULL)
				delete[] this->postDeLucru;
			this->postDeLucru = new char[strlen(postDeLucru) + 1];
			strcpy(this->postDeLucru, postDeLucru);
		}
	}
	const char* getpostDeLucru() {
		return this->postDeLucru;
	}


	void setexperienta(int experienta) {
		if (experienta > 40 or experienta < 0)
			throw "Data invalida";
		else
			this->experienta = experienta;
	}
	int getExperienta() {
		return this->experienta;
	}
	int getid_Angajat() {
		return this->id_Angajat;
	}
	int getnrAngajati() {
		return this->nrAngajati;
	}
	Angajati& operator=(const Angajati& a) {
		if (this->data_nastere != NULL) delete[] this->data_nastere;
		this->data_nastere = new char[strlen(a.data_nastere) + 1];
		strcpy(this->data_nastere, a.data_nastere);
		if (this->NumePrenumeAngajat != NULL) delete[] this->NumePrenumeAngajat;
		this->NumePrenumeAngajat = new char[strlen(a.NumePrenumeAngajat) + 1];
		strcpy(this->NumePrenumeAngajat, a.NumePrenumeAngajat);
		if (this->postDeLucru != NULL) delete[] this->postDeLucru;
		this->postDeLucru = new char[strlen(a.postDeLucru) + 1];
		strcpy(this->postDeLucru, a.postDeLucru);
		if (this->oreLucratePeZi != NULL) delete[] this->oreLucratePeZi;
		this->experienta = a.experienta;
		this->nrZileLucrate = a.nrZileLucrate;
		this->oreLucratePeZi = new int[this->nrZileLucrate];
		this->ZiuaLucrata = new string[this->nrZileLucrate];
		for (int i = 0; i < this->nrZileLucrate; i++)
		{
			this->ZiuaLucrata[i] = a.ZiuaLucrata[i];
			this->oreLucratePeZi[i] = a.oreLucratePeZi[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Angajati& a) {
		out << "ID Angajat: " << a.id_Angajat << endl;
		out << "Nume,Prenume: " << a.NumePrenumeAngajat << endl;
		out << "Postul de lucru: " << a.postDeLucru << endl;
		out << "Data nastere: " << a.data_nastere << endl;
		out << "Experienta: " << a.experienta << endl;
		out << "Numar zile lucrate: " << a.nrZileLucrate << endl;
		if (a.nrZileLucrate > 0)
		{
			for (int i = 0; i < a.nrZileLucrate; i++)
				out << "Data: " << a.ZiuaLucrata[i] << "   a lucrat: " << a.oreLucratePeZi[i] << endl;
		}
		return out;
	}
	friend ofstream& operator<<(ofstream& out, Angajati& a) {
		out << "ID Angajat: " << a.id_Angajat << endl;
		out << "Nume,Prenume: " << a.NumePrenumeAngajat << endl;
		out << "Postul de lucru: " << a.postDeLucru << endl;
		out << "Data nastere: " << a.data_nastere << endl;
		out << "Experienta: " << a.experienta << endl;
		out << "Numar zile lucrate: " << a.nrZileLucrate << endl;
		if (a.nrZileLucrate > 0)
		{
			for (int i = 0; i < a.nrZileLucrate; i++)
				out << "Data: " << a.ZiuaLucrata[i] << "   a lucrat: " << a.oreLucratePeZi[i] << endl;
		}
		return out;
	}

	friend istream& operator>>(istream& in, Angajati& a) {
		char caracter[50];
		cout << "Nume,Prenume: ";
		in >> caracter;
		if (a.NumePrenumeAngajat != NULL)
			delete[] a.NumePrenumeAngajat;
		a.NumePrenumeAngajat = new char[strlen(caracter) + 1];
		strcpy(a.NumePrenumeAngajat, caracter);

		cout << "Postul de Lucru: ";
		in >> caracter;
		if (a.postDeLucru != NULL)
			delete[] a.postDeLucru;
		a.postDeLucru = new char[strlen(caracter) + 1];
		strcpy(a.postDeLucru, caracter);

		cout << "Data nastere: ";
		in >> caracter;
		if (a.data_nastere != NULL)
			delete[] a.data_nastere;
		a.data_nastere = new char[strlen(caracter) + 1];
		strcpy(a.data_nastere, caracter);

		cout << "Experienta: ";
		in >> a.experienta;
		cout << "Numar zile lucrate: ";
		in >> a.nrZileLucrate;
		if (a.nrZileLucrate > 0)
		{
			if (a.ZiuaLucrata != NULL)
				delete[] a.ZiuaLucrata;
			if (a.oreLucratePeZi != NULL)
				delete[] a.oreLucratePeZi;
			a.ZiuaLucrata = new string[a.nrZileLucrate];
			a.oreLucratePeZi = new int[a.nrZileLucrate];
			for (int i = 0; i < a.nrZileLucrate; i++)
			{
				cout << "Ziua " << i + 1 << endl << "Data: ";
				in >> a.ZiuaLucrata[i];
				cout << "Ore lucrate: ";
				in >> a.oreLucratePeZi[i];
			}

		}
		return in;
	}
	friend ifstream& operator>>(ifstream& in, Angajati& a) {

		char caracter[50];

		in.getline(caracter, 50);
		if (a.NumePrenumeAngajat != NULL)
			delete[] a.NumePrenumeAngajat;
		a.NumePrenumeAngajat = new char[strlen(caracter) + 1];
		strcpy(a.NumePrenumeAngajat, caracter);


		in.getline(caracter, 50);
		if (a.postDeLucru != NULL)
			delete[] a.postDeLucru;
		a.postDeLucru = new char[strlen(caracter) + 1];
		strcpy(a.postDeLucru, caracter);


		in.getline(caracter, 50);
		if (a.data_nastere != NULL)
			delete[] a.data_nastere;
		a.data_nastere = new char[strlen(caracter) + 1];
		strcpy(a.data_nastere, caracter);
		in >> a.experienta;
		in >> a.nrZileLucrate;
		if (a.nrZileLucrate > 0)
		{
			if (a.ZiuaLucrata != NULL)
				delete[] a.ZiuaLucrata;
			if (a.oreLucratePeZi != NULL)
				delete[] a.oreLucratePeZi;
			a.ZiuaLucrata = new string[a.nrZileLucrate];
			a.oreLucratePeZi = new int[a.nrZileLucrate];
			for (int i = 0; i < a.nrZileLucrate; i++)
			{
				in >> a.ZiuaLucrata[i];
				in >> a.oreLucratePeZi[i];
			}

		}
		return in;
	}

	bool operator!()
	{
		if (this->experienta > 0)
			return false;
		else
			return true;
	}

	bool operator<=(Angajati a)
	{
		if (this->nrZileLucrate <= a.nrZileLucrate)
			return true;
		else return false;

	}

	void operator+(int plusexperienta) {
		this->experienta += plusexperienta;

	}
	void operator*(int x) {

		this->experienta *= x;
	}

	Angajati& operator++() {
		this->experienta++;
		return *this;
	}

	Angajati& operator++(int n) {
		this->experienta++;
		return *this;
	}

	Angajati& operator--() {
		this->experienta--;
		return *this;
	}

	Angajati& operator--(int n) {
		this->experienta--;
		return *this;
	}
	int& operator[](int i) {
		if (i >= 0 and i < this->nrZileLucrate)
			return this->oreLucratePeZi[i];
		else
			throw "Data invalida";
	}

	int zileConcediuRamase() {
		return 50 - this->nrZileLucrate;
	}


};
class Sectia {
private:
	char* denumire;
	char* NumePrenumeSefSectie;
	int etajul;
	int nrPacientiPeSectie;
	int nrAngajatiPeSectie;
	const int id_Sectie;
	static int nrSectie;
public:
	Sectia() :id_Sectie(++nrSectie) {
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(denumire, "Anonim");
		this->NumePrenumeSefSectie = new char[strlen("Necunoscut") + 1];
		strcpy(NumePrenumeSefSectie, "Necunoscut");
		this->etajul = 0;
		this->nrPacientiPeSectie = 0;
		this->nrAngajatiPeSectie = 0;
	}
	Sectia(const char* denumire, const char* NumePrenumeSefSectie, int etajul, int nrPacientiPeSectie, int nrAngajatiPeSectie) :id_Sectie(++nrSectie) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->NumePrenumeSefSectie = new char[strlen(NumePrenumeSefSectie) + 1];
		strcpy(this->NumePrenumeSefSectie, NumePrenumeSefSectie);
		this->etajul = etajul;
		this->nrPacientiPeSectie = nrPacientiPeSectie;
		this->nrAngajatiPeSectie = nrAngajatiPeSectie;
	}
	Sectia(const Sectia& s) :id_Sectie(s.id_Sectie) {
		this->denumire = new char[strlen(s.denumire) + 1];
		strcpy(this->denumire, s.denumire);
		this->NumePrenumeSefSectie = new char[strlen(s.NumePrenumeSefSectie) + 1];
		strcpy(this->NumePrenumeSefSectie, s.NumePrenumeSefSectie);
		this->etajul = s.etajul;
		this->nrPacientiPeSectie = s.nrPacientiPeSectie;
		this->nrAngajatiPeSectie = s.nrAngajatiPeSectie;
	}
	~Sectia() {
		delete[] this->denumire;
	}
	//Setteri si getteri
	void setDenumire(const char* denumire) {
		if (strlen(denumire) < 3)

			throw "Data invalida";
		else
		{
			if (this->denumire != NULL)
				delete[]this->denumire;
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);

		}

	}
	const char* getDenumire() {
		return this->denumire;
	}
	void setNumePrenumeSefSectie(const char* NumePrenumeSefSectie) {
		if (strlen(NumePrenumeSefSectie) < 3)

			throw "Data invalida";
		else
		{
			if (this->NumePrenumeSefSectie != NULL)
				delete[]this->NumePrenumeSefSectie;
			this->NumePrenumeSefSectie = new char[strlen(NumePrenumeSefSectie) + 1];
			strcpy(this->NumePrenumeSefSectie, NumePrenumeSefSectie);

		}

	}
	const char* getNumePrenumeSefSectie() {
		return this->NumePrenumeSefSectie;
	}
	void setEtajul(int etajul) {
		if (etajul > 10 or etajul < 0)
			throw "Data invalida";
		else
			this->etajul = etajul;
	}
	int getEtajul() {
		return this->etajul;
	}
	void setnrPacientiPeSectie(int nrPacientiPeSectie) {
		if (nrPacientiPeSectie > 100 or nrPacientiPeSectie < 0)
			throw "Data invalida";
		else
			this->nrPacientiPeSectie = nrPacientiPeSectie;
	}
	int getnrPacientiPeSectie() {
		return this->nrPacientiPeSectie;
	}
	void setnrAngajatiPeSectie(int nrAngajatiPeSectie) {
		if (nrAngajatiPeSectie > 20 or nrAngajatiPeSectie < 0)
			throw "Data invalida";
		else
			this->nrAngajatiPeSectie = nrAngajatiPeSectie;
	}
	int getnrAngajatiPeSectie() {
		return this->nrAngajatiPeSectie;
	}
	int getid_Sectie() {
		return this->id_Sectie;
	}
	int getnrSectie() {
		return this->nrSectie;
	}
	Sectia& operator=(const Sectia& s) {
		if (this->denumire != NULL) delete[] this->denumire;
		this->denumire = new char[strlen(s.denumire) + 1];
		strcpy(this->denumire, s.denumire);
		if (this->NumePrenumeSefSectie != NULL) delete[] this->NumePrenumeSefSectie;
		this->NumePrenumeSefSectie = new char[strlen(s.NumePrenumeSefSectie) + 1];
		strcpy(this->NumePrenumeSefSectie, s.NumePrenumeSefSectie);
		this->etajul = s.etajul;
		this->nrPacientiPeSectie = s.nrPacientiPeSectie;
		this->nrAngajatiPeSectie = s.nrAngajatiPeSectie;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Sectia& s) {
		out << "Id-ul Sectiei: " << s.id_Sectie << endl;
		out << "Denumirea sectiei:" << s.denumire << endl;
		out << "Nume Prenume Sef Sectie: " << s.NumePrenumeSefSectie << endl;
		out << "Etajul Sectiei: " << s.etajul << endl;
		out << "Nr de pacienti pe sectie: " << s.nrPacientiPeSectie << endl;
		out << "Nr de angajati pe sectie: " << s.nrAngajatiPeSectie << endl;
		return out;
	}
	friend ofstream& operator<<(ofstream& out, Sectia& s) {
		out << "Id-ul Sectiei: " << s.id_Sectie << endl;
		out << "Denumirea sectiei:" << s.denumire << endl;
		out << "Nume Prenume Sef Sectie: " << s.NumePrenumeSefSectie << endl;
		out << "Etajul Sectiei: " << s.etajul << endl;
		out << "Nr de pacienti pe sectie: " << s.nrPacientiPeSectie << endl;
		out << "Nr de angajati pe sectie: " << s.nrAngajatiPeSectie << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Sectia& s) {
		char caracter[50];
		cout << "Denumire: ";
		in >> caracter;
		if (s.denumire != NULL)
			delete[] s.denumire;
		s.denumire = new char[strlen(caracter) + 1];
		strcpy(s.denumire, caracter);

		cout << "Nume Prenume Sefului de Sectie: ";
		in >> caracter;
		if (s.NumePrenumeSefSectie != NULL)
			delete[] s.NumePrenumeSefSectie;
		s.NumePrenumeSefSectie = new char[strlen(caracter) + 1];
		strcpy(s.NumePrenumeSefSectie, caracter);

		cout << "Etajul Sectiei: ";
		in >> s.etajul;

		cout << "Nr de pacienti pe sectie:";
		in >> s.nrPacientiPeSectie;

		cout << "Nr de angajati pe sectie:";
		in >> s.nrAngajatiPeSectie;

		return in;
	}
	friend ifstream& operator>>(ifstream& in, Sectia& s) {

		char caracter[50];

		in.getline(caracter, 50);
		if (s.denumire != NULL)
			delete[] s.denumire;
		s.denumire = new char[strlen(caracter) + 1];
		strcpy(s.denumire, caracter);

		in.getline(caracter, 50);
		if (s.NumePrenumeSefSectie != NULL)
			delete[] s.NumePrenumeSefSectie;
		s.NumePrenumeSefSectie = new char[strlen(caracter) + 1];
		strcpy(s.NumePrenumeSefSectie, caracter);

		in >> s.etajul;
		in >> s.nrPacientiPeSectie;
		in >> s.nrAngajatiPeSectie;
		return in;
	}
	bool operator!()
	{
		if (this->etajul > 0)
			return false;
		else
			return true;
	}

	bool operator<=(Sectia s)
	{
		if (this->etajul <= s.etajul)
			return true;
		else return false;

	}

	void operator+(int plusetajul) {
		this->etajul += plusetajul;

	}
	void operator*(int x) {

		this->etajul *= x;
	}

	Sectia& operator++() {
		this->etajul++;
		return *this;
	}

	Sectia& operator++(int n) {
		this->etajul++;
		return *this;
	}

	Sectia& operator--() {
		this->etajul--;
		return *this;
	}

	Sectia& operator--(int n) {
		this->etajul--;
		return *this;
	}

	int LocuriRamase() {
		return 110 - this->nrPacientiPeSectie;
	}

};

string Pacienti::listaPacienti[50] = { "Necunoscut" };
string Angajati::listaAngajati[50] = { "Necunoscut" };
int Sectia::nrSectie = 0;
int Angajati::nrAngajati = 0;
int Pacienti::nrPacienti = 0;

int main() {
	cout << "PRIMA FAZA A PROIECTULUI!" << endl << endl;
	cout << "TESTAREA CLASEI PACIENTI" << endl << endl;
	Pacienti p1;
	cout << "Testare constructor implicit si supraincarcarea operatorului <<" << endl << p1 << endl << endl;
	Pacienti p2("Tudorescu Vasile", 39, "Bucuresti, Independentei 266", "Leucemie", 1);
	cout << p2 << endl << endl << endl;
	Pacienti p3("Vasilescu Mihai", 25, "Bucuresti, Univesitatii 14", "Pneumonie", 0);
	cout << "Testare supraincarcare operator>>" << endl;
	cout << endl << endl << p3 << endl << endl;
	Pacienti p4(p2);
	cout << "Testare constructor de copiere" << endl << "Comanda: Pacienti p4(p2)" << endl << endl << p4 << endl << endl << endl;
	cout << "Testare operator = " << endl << "Comanda p4=p3; cout<<p4" << endl << endl;
	p4 = p3;
	cout << p4 << endl << endl << endl;
	Pacienti p9;
	cout << "Testare supraincarcare >>" << endl;
	cout << p9 << endl << endl;
	cout << endl << endl << "Testare supraincarcare negatie !p1 (se testeaza varsta)" << endl;
	if (!p1 == 1)
		cout << "true" << endl << endl << endl << endl;
	else
		cout << "false" << endl << endl << endl << endl;
	cout << "Testare supraincarcare + si get varsta" << endl << "Comanda: cout<<p1.getVarsta();s1+5;cout<<s1.getVarsta()" << endl << endl;
	cout << "Varsta initiala: " << p1.getVarsta() << endl;
	p1 + 5;
	cout << "Varsta dupa p1 +5: " << p1.getVarsta() << endl << endl << endl << endl;
	cout << "Testare supraincarcare *" << endl << "Comanda: p1*2" << endl << endl;
	cout << "Valoare initiala: " << p1.getVarsta() << endl;
	p1 * 2;
	cout << "Valoare dupa comanda: " << p1.getVarsta() << endl << endl << endl << endl;
	cout << "Testare ++p1,p1++,--p1,p1--" << endl << endl;
	cout << "Valoare initiala: " << p1.getVarsta() << endl;
	cout << "Valoare dupa p1++ : "; p1++; cout << p1.getVarsta() << endl;
	cout << "Valoare dupa ++p1 :"; ++p1; cout << p1.getVarsta() << endl;
	cout << "Valoare dupa p1-- :"; p1--; cout << p1.getVarsta() << endl;
	cout << "Valoare dupa --p1 :"; --p1; cout << p1.getVarsta() << endl << endl;
	cout << "Testare setteri si getteri" << endl << "Comanda: setNumePrenumePacient,setVarsta,getNumePrenumePacient, getVarsta:" << endl;
	p1.setNumePrenumePacient("Angelescu Victor"); p1.setVarsta(29);
	cout << "Nume, Prenume: " << p1.getNumePrenumePacient() << endl << "Varsta: " << p1.getVarsta() << endl << endl;



	cout << "TESTAREA CLASEI ANGAJATI" << endl << endl;
	Angajati a1;
	cout << "Testare constructor implicit si supraincarcarea operatorului <<" << endl << a1 << endl << endl;
	Angajati a2("1980/10/08", "Plesca Alexandru", "medic de familie", 25, 250);
	cout << a2 << endl << endl << endl;
	Angajati a3;
	cout << "Testare supraincarcare operator>>" << endl;
	cout << endl << endl << a3 << endl << endl;
	Angajati a4(a2);
	cout << "Testare constructor de copiere si afisarea lui" << endl << a4 << endl;
	cout << "Testare setNumePrenumeAngajat,setexperienta,setpostDeLucru in a4 si afisare cu getNumePrenumeAngajat,getexperienta,get" << endl;
	a4.setNumePrenumeAngajat("Baciu Larisa");
	a4.setexperienta(27);
	a4.setpostDeLucru("Laborant");
	cout << "Angajatul:" << a4.getNumePrenumeANgajat() << endl << "Experienta: " << a4.getExperienta() << endl << "Ocupa postul de: " << a4.getpostDeLucru() << endl << endl << endl;
	cout << "Testare getId_Angajat" << endl;
	cout << "Id angajat: " << a4.getid_Angajat() << endl << endl;
	cout << "Testare !a4 (cout<<!a4)" << endl;
	cout << !a4 << endl;

	cout << "Testare supraincarcare + si get experienta" << endl << "Comanda: cout<<a1.getExperienta();a1+2;cout<<a1.getExperienta()" << endl << endl;
	cout << "Experienta initiala: " << a1.getExperienta() << endl;
	a1 + 2;
	cout << "Experienta dupa a1 + 2: " << a1.getExperienta() << endl << endl << endl << endl;
	cout << "Testare supraincarcare *" << endl << "Comanda: a1*3" << endl << endl;
	cout << "Valoare initiala: " << a1.getExperienta() << endl;
	a1 * 3;
	cout << "Valoare dupa comanda: " << a1.getExperienta() << endl << endl << endl << endl;
	cout << "Testare ++a1,a1++,--a1,a1--" << endl << endl;
	cout << "Valoare initiala: " << a1.getExperienta() << endl;
	cout << "Valoare dupa a1++ : "; a1++; cout << a1.getExperienta() << endl;
	cout << "Valoare dupa ++a1 :"; ++a1; cout << a1.getExperienta() << endl;
	cout << "Valoare dupa a1-- :"; a1--; cout << a1.getExperienta() << endl;
	cout << "Valoare dupa --a1 :"; --a1; cout << a1.getExperienta() << endl << endl;

	cout << "Testare setteri si getteri" << endl << "Comanda: setNumePrenumeAngajat,setpostDeLucru,setExperienta,getNumePrenumeAngajat,getpostDeLucru,setExperienta." << endl;
	a1.setNumePrenumeAngajat("Bandea Ion"); a1.setpostDeLucru("Medic Sef"); a1.setexperienta(29);
	cout << "Nume,Prenume: " << a1.getNumePrenumeANgajat() << endl << "postDeLucru: " << a1.getpostDeLucru() << endl << "Experienta: " << a1.getExperienta() << endl << endl;
	cout << "Functia: calculeaza zilele de concediu ramase in functie de nr de zile lucrate" << endl;
	cout << "Zile concediu: " << a1.zileConcediuRamase() << endl << endl << endl;


	cout << "TESTAREA CLASEI SECTIA" << endl << endl;
	Sectia s1;
	cout << "Testare constructor implicit si supraincarcarea operatorului <<" << endl << s1 << endl << endl;
	Sectia s2("Terapie", "Hungea Andrei", 3, 47, 10);
	cout << endl << s2 << endl << endl << endl;
	Sectia s3;
	cout << "Testare supraincarcare operator>>" << endl;
	cout << endl << endl << s3 << endl << endl;
	Sectia s4(s2);
	cout << "Testare constructor de copiere si afisarea lui" << endl << s4 << endl;
	cout << "Testare setDenumire,setEtajul,setnrPacientiPeSectie,setnrAngajatiPeSectie in s4 si afisare cu getDenumire,getEtajul,getnrPacientiPeSectie,getnrAngajatiPeSectie." << endl;
	s4.setDenumire("Neurologie");
	s4.setEtajul(3);
	s4.setnrPacientiPeSectie(68);
	s4.setnrAngajatiPeSectie(12);
	cout << "Sectia:" << s4.getDenumire() << endl << "Etajul: " << s4.getEtajul() << endl << "Nr de pacienti: " << s4.getnrPacientiPeSectie() << endl<<"Nr de angajati:"<<s4.getnrAngajatiPeSectie() << endl << endl;
	cout << "Testare getId_Sectie" << endl;
	cout << "Id sectie: " << s4.getid_Sectie() << endl << endl;
	cout << "Testare !s4 (cout<<!s4)" << endl;
	cout << !s4 << endl;

	cout << "Testare supraincarcare + si get etajul" << endl << "Comanda: cout<<s1.getEtajul();s1+3;cout<<s1.getEtajul()" << endl << endl;
	cout << "Experienta initiala: " << s1.getEtajul() << endl;
	s1 + 3;
	cout << "Experienta dupa s1 + 3: " << s1.getEtajul() << endl << endl << endl << endl;
	cout << "Testare supraincarcare *" << endl << "Comanda: s1*2" << endl << endl;
	cout << "Valoare initiala: " << s1.getEtajul() << endl;
	s1 * 2;
	cout << "Valoare dupa comanda: " << s1.getEtajul() << endl << endl << endl << endl;
	cout << "Testare ++s1,s1++,--s1,s1--" << endl << endl;
	cout << "Valoare initiala: " << s1.getEtajul() << endl;
	cout << "Valoare dupa s1++ : "; s1++; cout << s1.getEtajul() << endl;
	cout << "Valoare dupa ++s1 :"; ++s1; cout << s1.getEtajul() << endl;
	cout << "Valoare dupa s1-- :"; s1--; cout << s1.getEtajul() << endl;
	cout << "Valoare dupa --s1 :"; --s1; cout << s1.getEtajul() << endl << endl;

	cout << "Testare setteri si getteri" << endl << "Comanda: setDenumire,setNumePrenumeSefSectie,setEtajul,setNrPacientiPeSectie,setNrAngajatiPeSectie,getDenumire,getNumePrenumeSefSectie,getEtajul,getNrPacientiPeSectie,getNrAngajatiPeSectie." << endl;
	s1.setDenumire("Oncologie"); s1.setNumePrenumeSefSectie("Ofteev Maxim"); s1.setEtajul(4); s1.setnrPacientiPeSectie(70); s1.setnrAngajatiPeSectie(14);
	cout << "Denumire: " << s1.getDenumire() << endl << "NumePrenumeSefSectie: " << s1.getNumePrenumeSefSectie() << endl << "Etajul: " << s1.getEtajul() << endl << "Nr de pacienti: " << s1.getnrPacientiPeSectie() << endl << "Nr de angajati: " << s1.getnrAngajatiPeSectie() << endl << endl;
	cout << "Functia: calculeaza locurile ramase in functie de nr de pacienti" << endl;
	cout << "Locuri ramase: " << s1.LocuriRamase() << endl << endl << endl;


}