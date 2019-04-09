#include "orase.h"
#include <cstring>
#include <iostream>
#include <cstdarg>

Localitate::Localitate()
{
	this->denumire = new char[100];
}

Localitate::Localitate(int cod, char* denumire, long nr_locuitori)
{
	this->denumire = new char[strlen(denumire) + 1];
	strcpy(this->denumire, denumire);
	this->cod = cod;
	this->nr_locuitori = nr_locuitori;
}

Localitate::~Localitate()
{
	delete[] this->denumire;
}

Localitate::Localitate(const Localitate& L)
{
	delete[] this->denumire;
	this->denumire = new char[strlen(L.denumire) + 1];
	strcpy(this->denumire, L.denumire);
	this->cod = L.cod;
	this->nr_locuitori = L.nr_locuitori;
}

void Localitate::operator=(const Localitate& L)
{
	delete[] this->denumire;
	this->denumire = new char[strlen(L.denumire) + 1];
	strcpy(this->denumire, L.denumire);
	this->cod = L.cod;
	this->nr_locuitori = L.nr_locuitori;
}

void Localitate::display()
{
	std::cout << this->cod << " " << this->denumire << " " << this->nr_locuitori << "\n";
}


Oras::Oras(int cod, char* denumire, long nr_locuitori, int nrBlocuri) :Localitate(cod, denumire, nr_locuitori)
{
	this->nrBlocuri = nrBlocuri;
}

Oras::Oras(const Oras& O) :Localitate(O.cod, O.denumire, O.nr_locuitori)
{
	this->nrBlocuri = nrBlocuri;
}

void Oras::operator=(const Oras& O)
{
	this->Localitate::operator=(O);
	this->nrBlocuri = nrBlocuri;
}

void Oras::display()
{
	std::cout << this->nrBlocuri << " ";
	this->Localitate::display();
}


Capitala::Capitala(int cod, char* denumire, long nr_locuitori, int nrBlocuri, char* numePrefect): Oras(cod, denumire, nr_locuitori, nrBlocuri)
{
	this->numePrefect = new char[strlen(numePrefect) + 1];
	strcpy(this->numePrefect, numePrefect);
}

Capitala::~Capitala()
{
	delete[] this->numePrefect;
}

Capitala::Capitala(const Capitala& C): Oras(C.cod,C.denumire,C.nr_locuitori,C.nrBlocuri)
{
	delete[] this->numePrefect;
	strcpy(this->numePrefect, C.numePrefect);
}

void Capitala::operator=(const Capitala& C)
{
	this->Oras::operator=(C);
	strcpy(this->numePrefect, C.numePrefect);
}

void Capitala::display()
{
	std::cout << this->numePrefect << " ";
	this->Oras::display();
}

