#pragma once
#include <iostream>
#include "Product.h"
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
class ProductController
{
private:
	vector<Product> vectorProduct;
public:
	ProductController()
	{
		cargar_archivo();
	}
	void add(Product obj)
	{
		vectorProduct.push_back(obj);
	}
	Product get(int pos)
	{
		return vectorProduct[pos];
	}
	int size()
	{
		return vectorProduct.size();
	}
	int get_correlativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorProduct[size() - 1].get_codigo() + 1;
		}
	}
	Product get_buscar_por_codigo(int codigo)
	{
		Product objError;
		objError.set_nombre("ERROR");
		for (Product x : vectorProduct)
		{
			if (codigo == x.get_codigo())
			{
				return x;
			}
		}
		return objError;
	}
	bool modificar(Product obj, string nombre, float precio, int cantidad)
	{
		for (int i = 0; i < vectorProduct.size(); i++)
		{
			if (obj.get_codigo() == vectorProduct[i].get_codigo())
			{
				vectorProduct[i].set_nombre(nombre);
				vectorProduct[i].set_precio(precio);
				vectorProduct[i].set_cantidad(cantidad);
				return true;
			}
		}
		return false;
	}
	int get_post_array(Product obj)
	{
		for (Product x : vectorProduct)
		{
			if (obj.get_codigo() == x.get_codigo())
			{
				return 1;
			}
		}
		return -1;
	}
	void remove(Product obj)
	{
		vectorProduct.erase(vectorProduct.begin() + get_post_array(obj));
	}
	void grabar_archivo(Product obj)
	{
		try
		{
			fstream archivoProduct;
			archivoProduct.open("productos.csv", ios::app);
			if (archivoProduct.is_open())
			{
				archivoProduct << obj.get_codigo() << ";" << obj.get_nombre() << ";" << obj.get_precio() << ";" << obj.get_cantidad() << ";" << endl;
				archivoProduct.close();
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
			fstream archivoProduct;
			archivoProduct.open("productos.csv", ios::out);
			if (archivoProduct.is_open())
			{
				for (Product x : vectorProduct)
				{
					archivoProduct << x.get_codigo() << ";" << x.get_nombre() << ";" << x.get_precio() << ";" << x.get_cantidad() << ";" << endl;

				}
				archivoProduct.close();
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN PROBLEMA AL GRABAR EN EL ARCHIVO";
		}
	}
	void cargar_archivo()
	{
		try
		{
			int i;
			size_t posi;
			string linea;
			string temporal[4];
			fstream archivoProduct;
			archivoProduct.open("productos.csv", ios::in);
			if (archivoProduct.is_open())
			{
				while (!archivoProduct.eof() && getline(archivoProduct, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					Product objProduct(stoi(temporal[0]), temporal[1], stof(temporal[2]), stoi(temporal[3]));
					add(objProduct);
				}
			}
		}
		catch (exception e)
		{
			cout << "OCURRIO UN ERROR AL GRABAR EN EL ARCHIVO";
		}
	}
};