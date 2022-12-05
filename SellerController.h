#pragma once
#include <iostream>
#include "Seller.h"
#include<vector>
#include<fstream>
#include<cstdlib>
#include <cstring>
#include <string>
using std::stoi;
using namespace std;
class SellerController
{
private:
	vector<Seller> vectorSeller;
public:
	SellerController()
	{
		cargar_archivo();
	}
	void add(Seller obj)
	{
		vectorSeller.push_back(obj);
	}
	Seller get(int pos)
	{
		return vectorSeller[pos];
	}
	int size()
	{
		return vectorSeller.size();
	}
	int get_correlativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorSeller[size() - 1].get_codigo() + 1;
		}
	}
	Seller get_buscar_por_codigo(int codigo)
	{
		Seller objError;
		objError.set_nom_ape("ERROR");
		for (Seller x : vectorSeller)
		{
			if (codigo == x.get_codigo())
			{
				return x;
			}
		}
		return objError;
	}
	bool modificar(Seller obj, string nom_ape, string dni)
	{
		for (int i = 0; i < vectorSeller.size(); i++)
		{
			if (obj.get_codigo() == vectorSeller[i].get_codigo())
			{
				vectorSeller[i].set_nom_ape(nom_ape);
				vectorSeller[i].set_dni(dni);
				return true;
			}
		}
		return false;
	}
	int get_post_array(Seller obj)
	{
		for (Seller x : vectorSeller)
		{
			if (obj.get_codigo() == x.get_codigo())
			{
				return 1;
			}
		}
		return -1;
	}
	void remove(Seller obj)
	{
		vectorSeller.erase(vectorSeller.begin() + get_post_array(obj));
	}
	void grabar_archivo(Seller obj)
	{
		try
		{
			fstream archivoSeller;
			archivoSeller.open("vendedores.csv", ios::app);
			if (archivoSeller.is_open())
			{
				archivoSeller << obj.get_codigo() << ";" << obj.get_nom_ape() << ";" << obj.get_dni() << ";" << endl;
				archivoSeller.close();
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
			fstream archivoSeller;
			archivoSeller.open("vendedores.csv", ios::out);
			if (archivoSeller.is_open())
			{
				for (Seller x : vectorSeller)
				{
					archivoSeller << x.get_codigo() << ";" << x.get_nom_ape() << ";" << x.get_dni() << ";" << endl;

				}
				archivoSeller.close();
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO";
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
			fstream archivoSeller;
			archivoSeller.open("vendedores.csv", ios::in);
			if (archivoSeller.is_open())
			{
				while (!archivoSeller.eof() && getline(archivoSeller, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					Seller objSeller(stoi(temporal[0]), temporal[1], temporal[2]);
					add(objSeller);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};
