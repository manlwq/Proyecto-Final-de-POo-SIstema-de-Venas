#pragma once
#include <iostream>
#include "Sale.h"
#include<vector>
#include<fstream>
#include<cstdlib>
#include <cstring>
#include <string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include <cstring>
#include <string>
#include<Windows.h>
#include <conio.h>
using std::stoi;
using std::stof;
using namespace std;
class SaleController
{
private:
	vector<Sale> vectorSale;
public:
	SaleController()
	{
		cargar_archivo();
	}
	void add(Sale obj)
	{
		vectorSale.push_back(obj);
	}
	Sale get(int pos)
	{
		return vectorSale[pos];
	}
	int size()
	{
		return vectorSale.size();
	}
	int get_correlativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorSale[size() - 1].get_codigo() + 1;
		}
	}
	void grabar_archivo(Sale obj)
	{
		try
		{
			fstream archivoSale;
			archivoSale.open("venta.csv", ios::app);
			if (archivoSale.is_open())
			{
				archivoSale << obj.get_codigo() << ";" << obj.get_codigo_venta() << ";" << obj.get_codigo_cliente() << ";" << obj.get_codigo_vendedor() << ";" << obj.get_fecha() << ";" << obj.get_total() << ";" << endl;
				archivoSale.close();
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
			string temporal[6];
			fstream archivoSale;
			archivoSale.open("venta", ios::in);
			if (archivoSale.is_open())
			{
				while (!archivoSale.eof() && getline(archivoSale, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					Sale objSale(stoi(temporal[0]), stoi(temporal[1]), stoi(temporal[2]), stoi(temporal[3]), temporal[4], stof(temporal[5]));
					add(objSale);
				}
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO";
		}
	}
	
};
