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

std::ostream& operator<<(std::ostream& output, Localitate &L)
{
	L.display(output);
	return output;
}

std::istream& operator>>(std::istream& input, Localitate& L)
{
	L.read(input);
	return input;
}

std::ostream& operator<<(std::ostream& output, Oras& O)
{
	O.display(output);
	return output;
}

std::istream& operator>>(std::istream& input, Oras& O)
{
	O.read(input);
	return input;
}

std::ostream& operator<<(std::ostream& output, Capitala &C)
{
	C.display(output);
	return output;
}

std::istream& operator>>(std::istream& input, Capitala& C)
{
	C.read(input);
	return input;
}

std::ostream& operator<<(std::ostream& output, Judet& J)
{
	J.display(output);
	return output;
}

std::istream& operator>>(std::istream& input, Judet& J)
{
	J.read(input);
	return input;
}

void Localitate::display(std::ostream &output)
{
	output << this->cod << " " << this->denumire << " " << this->nr_locuitori << "\n";
}

void Localitate::read(std::istream& input)
{
	input >> this->cod >> this->denumire >> this->nr_locuitori;
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

void Oras::display(std::ostream &output)
{
	output << this->nrBlocuri << " ";
	this->Localitate::display(output);
}

void Oras::read(std::istream& input)
{
	input >> nrBlocuri;
	this->Localitate::read(input);
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

void Capitala::display(std::ostream &output)
{
	output << this->numePrefect << " ";
	this->Oras::display(output);
}

void Capitala::read(std::istream& input)
{
	input >> this->numePrefect;
	this->Oras::read(input);
}

Judet::Judet(int nrLoc, Localitate** v)
{
	this->nrLoc = nrLoc;
	this->p = new Localitate[nrLoc + 1];
	for(int i=0;i<nrLoc;i++)
	{
		this->p[i] = *v[i];
	}
}

Judet::Judet(const Judet& J)
{
	delete[] this->p;
	this->nrLoc = J.nrLoc;
	this->p = new Localitate[J.nrLoc + 1];
	for(int i=0;i<J.nrLoc;i++)
	{
		this->p[i] = J.p[i];
	}
}


Judet::~Judet()
{

	delete[] p;
}

void Judet::operator=(const Judet& J)
{
	this->nrLoc = J.nrLoc;
	delete[] this->p;
	this->p = new Localitate[this->nrLoc + 1];
	for (int i = 0; i < J.nrLoc; i++)
	{
		this->p[i] = J.p[i];
	}
}

void Judet::display(std::ostream& output)
{
	for(int i=0;i<nrLoc;i++)
	{
		output << p[i];
	}
}
void Judet::read(std::istream& input)
{
	int n, option, k = 0;
	Localitate **v;
	v = new Localitate*[100];
	input >> n;
	//std::cout << " 1 - Localitate\n 2 - Oras\n 3 - Capitala\n";
	//std::cout << " Localitate - cod denumire nr loc\n Oras - nr blocuri cod denumire nr loc\n Capitala - nume prefect nr blocuri cod denumire nr loc\n";
	for (int i = 1; i <= n; i++)
	{
		input >> option;
		switch (option)
		{
		case 1:
		{
			Localitate *L = new Localitate;
			input >> *L;
			v[k++] = L;
			break;
		}
		case 2:
		{
			Oras *O = new Oras;
			input >> *O;
			v[k++] = O;
			break;
		}
		case 3:
		{
			Capitala *C = new Capitala;
			input >> *C;
			v[k++] = C;
			break;
		}
		}
	}
	//Judet J(n, v);
	this->nrLoc = n;
	for (int i = 0; i < nrLoc; i++)
	{
		this->p[i] = *v[i];
	}
}

