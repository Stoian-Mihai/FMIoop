#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;
class personal;
class cinematograf;
class film
{
	string nume;
	string tip;
	int durata;
	vector<personal*> pers;
	vector<cinematograf> cinematografe;
	static int ID()
	{
		static int ID = 0;
		return ID++;
	}
	const int curentID;
public:
	film();
	film(string nume, string tip, int durata, vector<cinematograf> cinematografe);
	~film();
	void read(istream &input);
	void print(ostream &output);
	friend istream &operator >>(istream &input, film &F);
	friend ostream &operator <<(ostream &output, film &F);
	int getID();
	vector<personal*> getPersonal();
};
class cinematograf
{
	string locatie;
	int incasari;
	void read(istream &input);
	void print(ostream &output);
	friend istream &operator >>(istream &input, cinematograf &C);
	friend ostream &operator <<(ostream &output, cinematograf &C);
};
class personal
{
protected:
	string nume;
	string cnp;
	string nume_film;
public:
	personal() {};
	personal(string nume,string cnp,string nume_film);
	virtual void read(istream &input) = 0;
	virtual void print(ostream &output) = 0;

};
class actor: public personal
{
	string rol;
	int procentIncasari;
	int bonus = 0;
public:
	actor(){};
	actor(string nume, string cnp, string nume_film, string rol, int procentIncasari);
	actor(actor &A);
	void operator=(actor &A);
	void read(istream &input);
	void print(ostream& output);
	bool principal();
	friend istream &operator>>(istream &input, actor &A);
	friend ostream &operator<<(ostream &ofstream, actor &A);
};
class regizor : public personal
{
	int suma;
public:
	regizor() {};
	regizor(string nume, string cnp, string nume_film, int suma);
	regizor(regizor &R);
	void operator=(regizor &R);
	void read(istream &input);
	void print(ostream& output);
	friend istream &operator>>(istream &input, regizor &R);
	friend ostream &operator<<(ostream &output, regizor &R);
};
class personalTehnic :public personal
{
	string divizie;
	int procentIncasari;
public:
	personalTehnic() {};
	personalTehnic(string nume, string cnp, string nume_film, string divizie, int procentIncasari);
	personalTehnic(personalTehnic &P);
	void operator=(personalTehnic &P);
	void read(istream &input);
	void print(ostream &output);
	friend istream &operator>>(istream &input, personalTehnic &P);
	friend ostream &operator<<(ostream &output, personalTehnic &P);

};
template <class type>
class firmaDistributie
{
	vector <film*> filme;
	int numarPersoane;
	int numarActori;
	int numarFilme;
	static int ID()
	{
		static int ID = 0;
		return ID++;
	}
	const int numarFirme;
public:
	firmaDistributie() :numarFirme(ID())
	{
		numarActori = 0;
		numarPersoane = 0;
	}
	void read(istream &input)
	{
		input >> numarFilme;
		for (int i = 1; i <= numarFilme; i++)
		{
			film *f = new film;
			f->read(input);
			auto vecPersoane = f->getPersonal();
			for (auto it : vecPersoane)
			{
				actor *a;
				if (a = dynamic_cast<actor*>(it))
				{
					numarActori++;
				}
				numarPersoane++;

			}
			filme.push_back(f);
		}
	}
	void print(ostream &output)
	{
		for (auto it : filme)
		{
			it->print(output);
		}
	}
	friend istream &operator>>(istream &input, firmaDistributie &F) { F.read(input); }
	friend ostream &operator<<(ostream &output, firmaDistributie &F) { F.print(output); }
};
template <>
class firmaDistributie<unsigned>
{
	vector <film*> filme;
	int numarPersoane;
	int numarActori;
	int numarFilme;
	int numarActoriP;
	static int ID()
	{
		static int ID = 0;
		return ID++;
	}
	const int numarFirme;
public:
	firmaDistributie() :numarFirme(ID())
	{
		numarActori = 0;
		numarPersoane = 0;
		numarActoriP = 0;
	}
	void read(istream &input)
	{
		input >> numarFilme;
		for (int i = 1; i <= numarFilme; i++)
		{
			film *f = new film;
			f->read(input);
			auto vecPersoane = f->getPersonal();
			for (auto it : vecPersoane)
			{
				actor *a;
				if (a = dynamic_cast<actor*>(it))
				{
					numarActori++;
					if (a->principal()) numarActoriP++;
				}
				numarPersoane++;

			}
			filme.push_back(f);
		}
	}
	void print(ostream &output)
	{
		for (auto it : filme)
		{
			it->print(output);
		}
		cout << "Actori Principali: " << numarActoriP << "\n";
	}
	friend istream &operator>>(istream &input, firmaDistributie &F) { F.read(input); }
	friend ostream &operator<<(ostream &output, firmaDistributie &F) { F.print(output); }
};


