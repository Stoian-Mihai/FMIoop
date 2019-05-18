#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class personal;
class film
{
	string nume;
	string tip;
	int durata;
	vector<personal> pers;
public:
	film();
	film(string nume, string tip, int durata, vector<personal> pers);
	void read(istream &input);
	void print(ostream &output);
	friend istream &operator >>(istream &input, film &F);
	friend ostream &operator <<(ostream &output, film &F);
};
class cinematograf
{
	
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
	void read(istream &input);
	void print(ostream& output);
	friend istream &operator>>(istream &input, actor &A);
	friend ostream &operator<<(ostream &ofstream, actor &A);
};
class regizor : public personal
{
	int suma;
public:
	regizor() {};
	regizor(string nume, string cnp, string nume_film, int suma);
	void read(istream &input);
	void print(ostream& output);
	friend istream &operator>>(istream &input, regizor &R);
	friend ostream &operator<<(ostream &output, regizor &R);
};
class personalTehnic
{
	string divizie;
	int procentIncasari;
};
class firmaDistributie
{
	
};