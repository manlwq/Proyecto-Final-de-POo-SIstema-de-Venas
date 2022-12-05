#pragma once
#include <iostream>
#include "Detail.h"
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
class DetailController
{
private:
	vector<Detail> vectorDetail;
public:
	DetailController()
	{
		cargar_archivo();

	}
	void add(Detail obj)
	{
		vectorDetail.push_back(obj);
	}
	Detail get(int pos)
	{
		return vectorDetail[pos];
	}
	int size()
	{
		return vectorDetail.size();
	}
	int get_correlativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorDetail[size() - 1].get_codigo() + 1;
		}
	}
	void listar(Detail obj)
	{
		cout << "Codigo del producto:" << obj.get_codigo_producto() << endl;
		cout << "Cantidad del producto:" << obj.get_cantidad_venta() << endl;
		cout << "Subtotal:" << obj.get_sub_total() << endl;
	}
	void grabar_archivo(Detail obj)
	{
		try
		{
			fstream archivoDetail;
			archivoDetail.open("detalles.csv", ios::app);
			if (archivoDetail.is_open())
			{
				archivoDetail << obj.get_codigo() << ";" << obj.get_codigo_venta() << ";" << obj.get_nombre_venta() << ";" << obj.get_codigo_producto() << ";" << obj.get_cantidad_venta() << ";" << obj.get_precio_venta() << ";" << endl;
				archivoDetail.close();
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO";
		}
	}
	void grabar_modificar_eliminar_archivo()
	{
		try
		{
			fstream archivoDetail;
			archivoDetail.open("detalles.csv", ios::out);
			if (archivoDetail.is_open())
			{
				for (Detail x : vectorDetail)
				{
					archivoDetail << x.get_codigo() << ";" << x.get_codigo_venta() << ";" << x.get_nombre_venta() << ";" << x.get_codigo_producto() << ";" << x.get_cantidad_venta() << ";" << x.get_precio_venta() << ";" << endl;

				}
				archivoDetail.close();
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO!!!";
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
			fstream archivoDetail;
			archivoDetail.open("detalles.csv", ios::in);
			if (archivoDetail.is_open())
			{
				while (!archivoDetail.eof() && getline(archivoDetail, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					Detail objDetail(stoi(temporal[0]), stoi(temporal[1]), temporal[2], stoi(temporal[3]), stoi(temporal[4]), stof(temporal[5]));
					add(objDetail);
				}
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO";
		}
	}
};