#pragma once

class Localitate
{
protected:
	char *denumire;
	int cod;
	long nr_locuitori;
public:
	Localitate();
	Localitate(int cod, char *denumire, long nr_locuitori);
	~Localitate();
	Localitate(const Localitate &);
	void operator=(const Localitate &);
	virtual void display();
};
class Oras: public Localitate
{
protected:
	int nrBlocuri;
public:
	Oras(int cod, char *denumire, long nr_locuitori, int nrBlocuri);
	Oras(const Oras &);
	void operator=(const Oras &);
	void display();
};
class Capitala: public Oras
{
protected:
	char *numePrefect;
public:
	Capitala(int cod, char *denumire, long nr_locuitori, int nrBlocuri, char *numePrefect);
	~Capitala();
	Capitala(const Capitala &);
	void operator=(const Capitala &);
	void display();
};
class Judet
{
	Localitate *p;
	int nrLoc;
public:
	Judet(int nrLoc, ...);
	void display();

};

