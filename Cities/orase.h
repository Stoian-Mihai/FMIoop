#pragma once
#include <iostream>
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
	friend  std::ostream &operator<<(std::ostream &output, Localitate &L);
	friend std::istream &operator>>(std::istream &input, Localitate &L);
	virtual void display(std::ostream &output);
	virtual void read(std::istream &input);
};
class Oras: public Localitate
{
protected:
	int nrBlocuri;
public:
	Oras() :Localitate(){}
	Oras(int cod, char *denumire, long nr_locuitori, int nrBlocuri);
	Oras(const Oras &);
	void operator=(const Oras &);
	friend std::ostream &operator<<(std::ostream &output, Oras &O);
	friend std::istream &operator>>(std::istream &input, Oras &O);
	void display(std::ostream &output);
	void read(std::istream &input);
};
class Capitala: public Oras
{
protected:
	char *numePrefect;
public:
	Capitala() :Oras() { numePrefect = new char[100]; }
	Capitala(int cod, char *denumire, long nr_locuitori, int nrBlocuri, char *numePrefect);
	~Capitala();
	Capitala(const Capitala &);
	void operator=(const Capitala &);
	friend std::ostream &operator<<(std::ostream &output, Capitala &C);
	friend std::istream &operator>>(std::istream &input, Capitala &C);
	void display(std::ostream &output);
	void read(std::istream &input);
};
class Judet
{
	Localitate *p;
	int nrLoc;
public:
	Judet() { p = new Localitate[100]; }
	Judet(int nrLoc, Localitate **v);
	Judet(const Judet &);
	~Judet();
	void operator=(const Judet &);
	friend std::ostream &operator<<(std::ostream &output, Judet &J);
	friend std::istream &operator>>(std::istream &input, Judet &J);
	void display(std::ostream &output);
	void read(std::istream &input);

};

