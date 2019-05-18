#include "film.h"
#include <iostream>
using namespace  std;


film::film(){}

film::film(string nume, string tip, int durata, vector<personal> pers)
{
	this->nume = nume;
	this->tip = tip;
	this->durata = durata;
	//this->pers = pers;
}

void film::read(istream &input)
{
	input >> nume;
	input >> tip;
	input >> durata;
	//input >> pers;

}

void film::print(ostream& output)
{
	output << nume <<"\n";
	output << tip <<"\n";
	output << durata <<"\n";
	//output << pers;
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

void actor::read(istream& input)
{
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

regizor::regizor(string nume, string cnp, string nume_film, int suma) :personal(nume,cnp,nume_film)
{
	this->suma = suma;
}

void regizor::read(istream& input)
{
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