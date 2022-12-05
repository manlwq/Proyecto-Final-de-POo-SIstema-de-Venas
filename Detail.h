#pragma once
#include <iostream>
using namespace std;
class Detail
{
private:
	int codigo;
	int codigo_venta;
	string nombre_venta;
	int codigo_producto;
	int cantidad_venta;
	float precio_venta;
public:
	Detail();
	Detail(int,int, string, int, int, float);
	~Detail();
	void set_codigo(int);
	void set_codigo_venta(int);
	void set_nombre_venta(string);
	void set_codigo_producto(int);
	void set_cantidad_venta(int);
	void set_precio_venta(float);
	int get_codigo();
	int get_codigo_venta();
	string get_nombre_venta();
	int get_codigo_producto();
	int get_cantidad_venta();
	float get_precio_venta();
	float get_sub_total();
};
Detail::Detail()
{

}
Detail::Detail(int codigo, int codigo_venta, string nombre_venta, int codigo_producto, int cantidad_venta, float precio_venta)
{
	this->codigo = codigo;
	this->codigo_venta = codigo_venta;
	this->nombre_venta = nombre_venta;
	this->codigo_producto = codigo_producto;
	this->cantidad_venta = cantidad_venta;
	this->precio_venta = precio_venta;
}
Detail::~Detail()
{

}
void Detail::set_codigo(int codigo)
{
	this->codigo = codigo;

}
void Detail::set_codigo_venta(int codigo_venta)
{
	this->codigo_venta = codigo_venta;

}
void Detail::set_nombre_venta(string nombre_venta)
{
	this->nombre_venta = nombre_venta;

}
void Detail::set_codigo_producto(int codigo_producto)
{
	this->codigo_producto = codigo_producto;

}
void Detail::set_cantidad_venta(int cantidad_venta)
{
	this->cantidad_venta = cantidad_venta;

}
void Detail::set_precio_venta(float precio_venta)
{
	this->precio_venta = precio_venta;
}
int Detail::get_codigo()
{
	return this->codigo;
}
int Detail::get_codigo_venta()
{
	return this->codigo_venta;
}
string Detail::get_nombre_venta()
{
	return this->nombre_venta;
}
int Detail::get_codigo_producto()
{
	return this->codigo_producto;
}
int Detail::get_cantidad_venta()
{
	return this->cantidad_venta;
}
float Detail::get_precio_venta()
{
	return this->precio_venta;
}
float Detail::get_sub_total()
{
	return this->get_precio_venta() * this->get_cantidad_venta();
}



