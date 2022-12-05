#pragma once
#include <iostream>
#include "Login.h"
#include<vector>
#include<fstream>
#include<cstdlib>
#include <cstring>
#include <string>
using std::stoi;
using namespace std;
class LoginController
{
private:
	vector<Login> vectorLogin;
public:
	LoginController()
	{
		cargar_archivo();
	}
	void add(Login obj)
	{
		vectorLogin.push_back(obj);
	}
	void grabar_archivo(Login login)
	{
		try
		{
			fstream archivoLogin;
			archivoLogin.open("usuarios.csv", ios::app);
			if (archivoLogin.is_open())
			{
				archivoLogin << login.get_usuario() << ";" << login.get_contrasena() << ";" << endl;
				archivoLogin.close();
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO" << endl;
		}
	}
	void cargar_archivo()
	{
		try
		{
			int i;
			size_t posi;
			string linea;
			string temporal[2];
			fstream archivoLogin;
			archivoLogin.open("usuarios.csv", ios::in);
			if (archivoLogin.is_open())
			{
				while (!archivoLogin.eof() && getline(archivoLogin, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						i++;
					}
					Login login(temporal[0], temporal[1]);
					add(login);
				}
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO" << endl;
		}
	}
};

