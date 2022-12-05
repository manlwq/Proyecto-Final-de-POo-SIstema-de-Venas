#pragma once
#include <iostream>
using namespace std;
class Customer
{
private:
	int codigo;
	string nom_ape;
	string dni;
public:
	Customer();
	Customer(int, string, string);
	~Customer();
	void set_codigo(int);
	void set_nom_ape(string);
	void set_dni(string);
	int get_codigo();
	string get_nom_ape();
	string get_dni();
};
Customer::Customer()
{

}
Customer::Customer(int codigo, string nom_ape, string dni)
{
	this->codigo = codigo;
	this->nom_ape = nom_ape;
	this->dni = dni;
}
Customer::~Customer()
{

}
void Customer::set_codigo(int codigo)
{
	this->codigo = codigo;
}
void Customer::set_nom_ape(string nom_ape)
{
	this->nom_ape = nom_ape;
}
void Customer::set_dni(string dni)
{
	this->dni = dni;
}
int Customer::get_codigo()
{
	return this->codigo;
}
string Customer::get_nom_ape()
{
	return this->nom_ape;
}
string Customer::get_dni()
{
	return this->dni;
}
