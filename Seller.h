#pragma once
#include <iostream>
using namespace std;
class Seller
{
private:
	int codigo;
	string nom_ape;
	string dni;
public:
	Seller();
	Seller(int, string, string);
	~Seller();
	void set_codigo(int);
	void set_nom_ape(string);
	void set_dni(string);
	int get_codigo();
	string get_nom_ape();
	string get_dni();
};
Seller::Seller()
{

}
Seller::Seller(int codigo, string nom_ape, string dni)
{
	this->codigo = codigo;
	this->nom_ape = nom_ape;
	this->dni = dni;
}
Seller::~Seller()
{

}
void Seller::set_codigo(int codigo)
{
	this->codigo = codigo;
}
void Seller::set_nom_ape(string nom_ape)
{
	this->nom_ape = nom_ape;
}
void Seller::set_dni(string dni)
{
	this->dni = dni;
}
int Seller::get_codigo()
{
	return this->codigo;
}
string Seller::get_nom_ape()
{
	return this->nom_ape;
}
string Seller::get_dni()
{
	return this->dni;
}