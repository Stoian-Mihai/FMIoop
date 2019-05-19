#include "film.h"
#include <iostream>
using namespace  std;


film::film():curentID(ID()){}

film::film(string nume, string tip, int durata, vector<cinematograf> cinematografe) : curentID(ID())
{
	this->nume = nume;
	this->tip = tip;
	this->durata = durata;
	this->cinematografe = cinematografe;
}

film::~film()
{
	for (auto it : pers)
	{
		if (actor *a = dynamic_cast<actor*>(it))
		{
			delete a;
		}
		else
		if (regizor *r = dynamic_cast<regizor*>(it))
		{
			delete r;
		}
		else
		{
			personalTehnic *p = static_cast<personalTehnic*>(it);
			delete p;
		}
	}
}

void film::read(istream &input)
{
	cout << "nume tip durata numarPersonal\n";
	input >> nume;
	input >> tip;
	input >> durata;
	actor *a;
	regizor *r;
	personalTehnic *p;
	int numarPersonal;
	input >> numarPersonal;
	for(int i=1;i<=numarPersonal;i++)
	{
		cout << "1 - actor, 2 - regizor, 3 - personalTehnic\n";
		int option;
		input >> option;
		try{
			if (option > 3 || option < 1) throw option;
			switch (option)
			{
			case 1:
				a = new actor;
				input >> *a;
				pers.push_back(a);
				break;
			case 2:
				r = new regizor;
				input >> *r;
				pers.push_back(r);
				break;
			case 3:
				p = new personalTehnic;
				input >> *p;
				pers.push_back(p);
				break;
			}
		}catch(int option){
			cout << "optiunea " << option << " este invalida";
		}
	}
	int nrCinematografe;
	input >> nrCinematografe;
	for(int i=1;i<=nrCinematografe;i++)
	{
		cinematograf c;
		input >> c;
		cinematografe.push_back(c);
	}
	
}

void film::print(ostream& output)
{
	output << nume <<"\n";
	output << tip <<"\n";
	output << durata <<"\n";
	for(auto it:pers)
	{
		//cout<< typeid(*it).name();
		if(actor *a = dynamic_cast<actor*>(it))
		{
			a->print(output);
			output << "\n";
		}else
		if(regizor *r = dynamic_cast<regizor*>(it))
		{
			r->print(output);
			output << "\n";
		}else
		{
			personalTehnic *p = static_cast<personalTehnic*>(it);
			p->print(output);
			output << "\n";
		}

	}
	for (auto it : cinematografe)
		output << it;
}

int film::getID()
{
	return this->curentID;
}

vector<personal*> film::getPersonal()
{
	return this->pers;
}

void cinematograf::read(istream& input)
{
	input >> locatie;
	input >> incasari;
}

void cinematograf::print(ostream& output)
{
	output << locatie <<"\n";
	output << incasari <<"\n";
}

personal::personal(string nume, string cnp, string nume_film)
{
	this->nume = nume;
	this->cnp = cnp;
	this->nume_film = nume_film;
}

actor::actor(string nume, string cnp, string nume_film, string rol, int procentIncasari) :personal(nume, cnp, nume_film)
{
	this->rol = rol;
	this->procentIncasari = procentIncasari;
}

actor::actor(actor& A)
{
	this->nume = A.nume;
	this->cnp = A.cnp;
	this->nume_film = A.nume_film;

	this->rol = A.rol;
	this->procentIncasari = A.procentIncasari;
	this->bonus = A.bonus;
}

void actor::operator=(actor& A)
{
	this->nume = A.nume;
	this->cnp = A.cnp;
	this->nume_film = A.nume_film;

	this->rol = A.rol;
	this->procentIncasari = A.procentIncasari;
	this->bonus = A.bonus;
}

void actor::read(istream& input)
{
	cout << "nume cnp nume_film rol procentIncasari\n";
	input >> nume;
	input >> cnp;
	input >> nume_film;

	input >> rol;
	input >> procentIncasari;
	if (rol == "principal") bonus = 10;
}

void actor::print(ostream& output)
{
	output << "nume: "<<nume<<"\n";
	output << "cnp: "<<cnp<<"\n";
	output << "nume_film: "<<nume_film<<"\n";

	output << "rol: "<<rol<<"\n";
	output << "procentIncasari: "<<procentIncasari<<"\n";
	output << "bonus: "<<bonus<<"\n";
}

bool actor::principal()
{
	if (this->rol == "principal") return 1;
	return 0;
}

regizor::regizor(string nume, string cnp, string nume_film, int suma) :personal(nume,cnp,nume_film)
{
	this->suma = suma;
}

regizor::regizor(regizor& R)
{
	this->nume = R.nume;
	this->cnp = R.cnp;
	this->nume_film = R.nume_film;

	this->suma = R.suma;
}

void regizor::operator=(regizor& R)
{
	this->nume = R.nume;
	this->cnp = R.cnp;
	this->nume_film = R.nume_film;

	this->suma = R.suma;
}

void regizor::read(istream& input)
{
	cout << "nume cnp nume_film suma\n";

	input >> nume;
	input >> cnp;
	input >> nume_film;

	input >> suma;
}

void regizor::print(ostream& output)
{
	output << "nume: " << nume << "\n";
	output << "cnp: " << cnp << "\n";
	output << "nume_film: " << nume_film << "\n";

	output << "suma: " << suma << "\n";
}

personalTehnic::personalTehnic(string nume, string cnp, string nume_film, string divizie, int procentIncasari) :personal(nume,cnp,nume_film)
{
	this->divizie = divizie;
	this->procentIncasari = procentIncasari;
}

personalTehnic::personalTehnic(personalTehnic& P)
{
	this->nume = P.nume;
	this->cnp = P.cnp;
	this->nume_film = P.nume_film;

	this->divizie = P.divizie;
	this->procentIncasari = P.procentIncasari;
}

void personalTehnic::operator=(personalTehnic& P)
{
	this->nume = P.nume;
	this->cnp = P.cnp;
	this->nume_film = P.nume_film;

	this->divizie = P.divizie;
	this->procentIncasari = P.procentIncasari;
}

void personalTehnic::read(istream& input)
{
	cout << "nume cnp nume_film divizie procentIncasari\n";
	input >> nume;
	input >> cnp;
	input >> nume_film;

	input >> divizie;
	input >> procentIncasari;
}

void personalTehnic::print(ostream& output)
{
	output << "nume: " << nume << "\n";
	output << "cnp: " << cnp << "\n";
	output << "nume_film: " << nume_film << "\n";

	output << "divizie: " << divizie << "\n";
	output << "procentIncasari: " << procentIncasari << "\n";
}


istream& operator>>(istream& input, film& F)
{
	F.read(input);
	return input;
}

ostream& operator<<(ostream& output, film& F)
{
	F.print(output);
	return output;
}

istream& operator>>(istream& input, cinematograf& C)
{
	C.read(input);
	return input;
}

ostream& operator<<(ostream& output, cinematograf& C)
{
	C.print(output);
	return output;
}

istream& operator>>(istream& input, actor& A)
{
	A.read(input);
	return input;
}

ostream& operator<<(ostream& output, actor& A)
{
	A.print(output);
	return output;
}

istream& operator>>(istream& input, regizor& R)
{
	R.read(input);
	return input;
}

ostream& operator<<(ostream& output, regizor& R)
{
	R.print(output);
	return output;
}

istream& operator>>(istream& input, personalTehnic& P)
{
	P.read(input);
	return input;
}

ostream& operator<<(ostream& output, personalTehnic& P)
{
	P.print(output);
	return output;
}


