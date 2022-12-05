#pragma once
#include <iostream>
#include "Customer.h"
#include<vector>
#include<fstream>
#include<cstdlib>
#include <cstring>
#include <string>
using std::stoi;
using namespace std;
class CustomerController
{
private:
	vector<Customer> vectorCustomer;
public:
	CustomerController()
	{
		cargar_archivo();
	}
	void add(Customer obj)
	{
		vectorCustomer.push_back(obj);
	}
	Customer get(int pos)
	{
		return vectorCustomer[pos];
	}
	int size()
	{
		return vectorCustomer.size();
	}
	int get_correlativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorCustomer[size() - 1].get_codigo() + 1;
		}
	}
	Customer get_buscar_por_codigo(int codigo)
	{
		Customer objError;
		objError.set_nom_ape("ERROR");
		for (Customer x : vectorCustomer)
		{
			if (codigo == x.get_codigo())
			{
				return x;
			}
		}
		return objError;
	}
	bool modificar(Customer obj, string nom_ape, string dni)
	{
		for (int i = 0; i < vectorCustomer.size(); i++)
		{
			if (obj.get_codigo() == vectorCustomer[i].get_codigo())
			{
				vectorCustomer[i].set_nom_ape(nom_ape);
				vectorCustomer[i].set_dni(dni);
				return true;
			}
		}
		return false;
	}
	int get_post_array(Customer obj)
	{
		for (Customer x : vectorCustomer)
		{
			if (obj.get_codigo() == x.get_codigo())
			{
				return 1;
			}
		}
		return -1;
	}
	void remove(Customer obj)
	{
		vectorCustomer.erase(vectorCustomer.begin() + get_post_array(obj));
	}
	void grabar_archivo(Customer obj)
	{
		try
		{
			fstream archivoCustomer;
			archivoCustomer.open("clientes.csv", ios::app);
			if (archivoCustomer.is_open())
			{
				archivoCustomer << obj.get_codigo() << ";" << obj.get_nom_ape() << ";" << obj.get_dni() << ";" << endl;
				archivoCustomer.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	void grabar_modificar_eliminar_archivo()
	{
		try
		{
			fstream archivoCustomer;
			archivoCustomer.open("clientes.csv", ios::out);
			if (archivoCustomer.is_open())
			{
				for (Customer x : vectorCustomer)
				{
					archivoCustomer << x.get_codigo() << ";" << x.get_nom_ape() << ";" << x.get_dni() << ";" << endl;
				}
				archivoCustomer.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	void cargar_archivo()
	{
		try
		{
			int i;
			size_t posi;
			string linea;
			string temporal[3];
			fstream archivoCustomer;
			archivoCustomer.open("clientes.csv", ios::in);
			if (archivoCustomer.is_open())
			{
				while (!archivoCustomer.eof() && getline(archivoCustomer, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					Customer objCustomer(stoi(temporal[0]), temporal[1], temporal[2]);
					add(objCustomer);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};