#pragma once
#include <iostream>
using namespace std;
class Product
{
private:
	int codigo;
	string nombre;
	float precio;
	int cantidad;
public:
	Product();
	Product(int,string,float,int);
	~Product();
	void set_codigo(int);
	void set_nombre(string);
	void set_precio(float);
	void set_cantidad(int);
	int get_codigo();
	string get_nombre();
	float get_precio();
	int get_cantidad();
};
Product::Product()
{

}
Product::Product(int codigo, string nombre,float precio,int cantidad)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->precio = precio;
	this->cantidad = cantidad;
}
Product::~Product()
{

}
void Product::set_codigo(int codigo)
{
	this->codigo = codigo;
}
void Product::set_nombre(string nombre)
{
	this->nombre = nombre;
}
void Product::set_precio(float precio)
{
	this->precio = precio;
}
void Product::set_cantidad(int cantidad)
{
	this->cantidad = cantidad;
}
int Product::get_codigo()
{
	return this->codigo;
}
string Product::get_nombre()
{
	return this->nombre;
}
float Product::get_precio()
{
	return this->precio;
}
int Product::get_cantidad()
{
	return this->cantidad;
}
