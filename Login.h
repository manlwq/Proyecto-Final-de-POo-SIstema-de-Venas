#pragma once
#include <iostream>
using namespace std;
class Login
{
private:
	string usuario;
	string contrasena;
public:
	Login();
	Login(string, string);
	~Login();
	void set_usuario(string);
	void set_contrasena(string);
	string get_usuario();
	string get_contrasena();
};
Login::Login()
{

}
Login::Login(string usuario, string contrasena)
{
	this->usuario = usuario;
	this->contrasena = contrasena;
}
Login::~Login()
{

}
void Login::set_usuario(string usuario)
{
	this->usuario = usuario;

}
void Login::set_contrasena(string contrasena)
{
	this->contrasena = contrasena;
}
string Login::get_usuario()
{
	return this->usuario;
}
string Login::get_contrasena()
{
	return this->contrasena;
}