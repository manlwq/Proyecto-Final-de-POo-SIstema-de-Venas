#pragma once
#include <iostream>
using namespace std;
class Sale
{
private:
	int codigo;
	int codigo_venta;
	int codigo_cliente;
	int codigo_vendedor;
	string fecha;
	float total;
public:
	Sale();
	Sale(int,int, int, int, string, float);
	~Sale();
	void set_codigo(int);
	void set_codigo_venta(int);
	void set_codigo_cliente(int);
	void set_codigo_vendedor(int);
	void set_fecha(string);
	void set_total(float);
	int get_codigo();
	int get_codigo_venta();
	int get_codigo_cliente();
	int get_codigo_vendedor();
	string get_fecha();
	float get_total();
};
Sale::Sale()
{

}
Sale::Sale(int codigo,int codigo_venta, int codigo_cliente, int codigo_vendedor, string fecha, float total)
{
	this->codigo = codigo;
	this->codigo_venta = codigo_venta;
	this->codigo_cliente = codigo_cliente;
	this->codigo_vendedor = codigo_vendedor;
	this->fecha = fecha;
	this->total = total;
}
Sale::~Sale()
{

}
void Sale::set_codigo(int codigo)
{
	this->codigo = codigo;

}
void Sale::set_codigo_venta(int codigo_venta)
{
	this->codigo_venta = codigo_venta;
}
void Sale::set_codigo_cliente(int codigo_cliente)
{
	this->codigo_cliente = codigo_cliente;
}
void Sale::set_codigo_vendedor(int codigo_vendedor)
{
	this->codigo_vendedor = codigo_vendedor;
}
void Sale::set_fecha(string fecha)
{
	this->fecha = fecha;
}
void Sale::set_total(float total)
{
	this->total = total;
}
int Sale::get_codigo()
{
	return 	this->codigo;

}
int Sale::get_codigo_venta()
{
	return this->codigo_venta;
}
int Sale::get_codigo_cliente()
{
	return this->codigo_cliente;
}
int Sale::get_codigo_vendedor()
{
	return this->codigo_vendedor;
}
string Sale::get_fecha()
{
	return this->fecha;
}
float Sale::get_total()
{
	return this->total;
}
