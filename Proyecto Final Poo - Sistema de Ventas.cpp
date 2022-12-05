#include <iostream>
#include <iostream>
#include "LoginController.h"
#include "CustomerController.h"
#include "ProductController.h"
#include "SellerController.h"
#include "SaleController.h"
#include "DetailController.h"
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
LoginController* logController = new LoginController();
CustomerController* customController = new CustomerController();
ProductController* prodController = new ProductController();
SellerController* sellController = new SellerController();
SaleController* saleController = new SaleController();
DetailController* detailController = new DetailController();
void login();
void menu();
void customer();
void product();
void seller();
void sale();

void nuevo_customer();
void listar_customer();
void buscar_customer();
void modificar_customer();
void eliminar_customer();

void nuevo_product();
void listar_product();
void buscar_product();
void modificar_product();
void eliminar_product();

void nuevo_seller();
void listar_seller();
void buscar_seller();
void modificar_seller();
void eliminar_seller();

int main()
{
	login();
}
void login()
{
	vector<string> usuarios;
	vector<string> claves;
	usuarios.push_back("pedro");
	claves.push_back("pedro2004");

	string usuario;
	string contrasena;

	int intento = 0;
	bool ingreso = false;
	char caracter;
	do
	{
		system("cls");
		cout << "\t\t\tINICIO DE SESION" << endl;
		cout <<"\t\t\t"<<"   " << "----------" << endl;
		cout << "\n\tUsuario:\t";
		getline(cin, usuario);
		cout << "\tContrasena:\t";
		caracter = _getch();
		contrasena = "";
		while (caracter != 13)
		{
			if (caracter != 8)
			{
				contrasena.push_back(caracter);
				cout << "*";
			}
			else
			{
				if (contrasena.length() > 0)
				{
					cout << "\b \b";
					contrasena = contrasena.substr(0, contrasena.length() - 1);
				}
			}
			caracter = _getch();
		}
		for (int i = 0; i < usuarios.size(); i++)
		{
			if (usuarios[i] == usuario && claves[i] == contrasena)
			{
				ingreso = true;
				break;
			}
		}
		if (!ingreso)
		{
			cout << "\n\t\t\t----------" << endl;
			cout << "\tEL USUARIO O CONTRASENA SON INCORRECTOS" << endl;
			cout << "\t\t\t***INTENTOS***" << endl;
			cout <<"\t\t\t" << intento + 1 << "de 3 intentos" << endl;
			cin.get();
			intento++;
		}


	} while (intento < 3 && ingreso == false);
	if (ingreso == true)
	{
		Login login(usuario, contrasena);
		logController->add(login);
		logController->grabar_archivo(login);
		cout << "\n\t\t\t----------" << endl;
		cout << "\n\t\t"<<"  "<<"Ingreso satisfactorio" << endl;
		system("pause");
		system("cls");
		menu();
	}
	else
	{
		cout << "\tHa pasado el limite de intentos (MAXIMO 3 INTENTOS)";
		exit(0);
	}
}
void menu()
{
	int opt;
	do
	{
		cout << "***MENU DE OPCIONES***\n";
		cout << "Vendedor[1]***********\n";
		cout << "Cliente[2]************\n";
		cout << "Producto[3]***********\n";
		cout << "Venta[4]**************\n";
		cout << "Salir[5]**************\n";
		cout << "Ingresar una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls");
			seller();
			system("pause");
			system("cls");
			break;
		case 2:system("cls");
			customer();
			system("pause");
			system("cls");
			break;
		case 3:system("cls");
			product();
			system("pause");
			system("cls");
			break;
		case 4:system("cls");
			sale();
			system("pause");
			system("cls");
			break;
		case 5:system("cls");
			cout << "GRACIAS POR USAR NUESTRO PROGRAMA\n";
			system("pause");
			system("cls");
			break;
		default:system("cls");
			cout << "Ingrese una opcion entre [1-3]";
			system("pause");
			system("cls");
		}
	} while (opt != 3);

}
void customer()
{
	int opt;
	do
	{
		cout << "***********MENU DE OPCIONES***********\n";
		cout << "Nuevo Cliente[1]**********************\n";
		cout << "Listar Cliente[2]*********************\n";
		cout << "Buscar Cliente[3]*********************\n";
		cout << "Modificar cliente[4]******************\n";
		cout << "Eliminar Cliente[5]*******************\n";
		cout << "Regresar al menu principal[6]*********\n";
		cout << "Salir[7]******************************\n";
		cout << "Ingresar una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls");
			nuevo_customer();
			system("pause");
			system("cls");
			break;
		case 2:system("cls");
			listar_customer();
			system("pause");
			system("cls");
			break;
		case 3:system("cls");
			buscar_customer();
			system("pause");
			system("cls");
			break;
		case 4:system("cls");
			modificar_customer();
			system("pause");
			system("cls");
			break;
		case 5:system("cls");
			eliminar_customer();
			system("pause");
			system("cls");
			break;
		case 6:system("cls");
			system("pause");
			system("cls");
			menu();
			break;
		case 7:system("cls");
			cout << "GRACIAS POR USAR NUESTRO PROGRAMA\n";
			exit(0);
			break;
		default:system("cls");
			cout << "Ingrese una opcion entre [1-7]";
			system("pause");
			system("cls");
		}
	} while (opt != 7);
}
void nuevo_customer()
{
	string flag;
	int codigo;
	string nom_ape;
	string dni;
	do
	{
		codigo = customController->get_correlativo();
		cout << "*****Cliente(" << codigo << ")*****\n";
		cin.ignore();
		cout << "Nombres y apellidos:";
		getline(cin, nom_ape);
		cout << "DNI:";
		cin >> dni;
		cout << "Continuar(S/s):";
		cin >> flag;
		Customer objCustom(codigo, nom_ape, dni);
		customController->add(objCustom);
		customController->grabar_archivo(objCustom);
		system("cls");
	} while (flag == "S" || flag == "s");
}
void listar_customer()
{
	for (int i = 0; i < customController->size(); i++)
	{
		cout << customController->get(i).get_codigo() << "\t" << customController->get(i).get_nom_ape() << "\t" << customController->get(i).get_dni() << endl;
	}
}
void buscar_customer()
{
	int codigo;
	cout << "Ingrese el codigo del cliente:";
	cin >> codigo;
	Customer customojb = customController->get_buscar_por_codigo(codigo);
	if (customojb.get_nom_ape() != "Error")
	{
		cout << "*****Cliente encontrado*****\n";
		cout << "Codigo:" << customojb.get_codigo() << "\n";
		cout << "Nombres y apellidos:" << customojb.get_nom_ape() << "\n";
		cout << "DNI:" << customojb.get_dni() << "\n";
	}
	else
	{
		cout << "No se encontro el cliente!\n";
	}

}
void modificar_customer()
{
	int codigo;
	cout << "Ingrese el codigo del cliente a modificar:";
	cin >> codigo;
	Customer customojb = customController->get_buscar_por_codigo(codigo);
	if (customojb.get_nom_ape() != "Error")
	{
		cout << "*****Cliente encontrado*****\n";
		cout << "Codigo:" << customojb.get_codigo() << "\n";
		cout << "Nombres y apellidos:" << customojb.get_nom_ape() << "\n";
		cout << "DNI:" << customojb.get_dni() << "\n";
		cin.ignore();

		string nom_ape_new;
		string dni_new;
		cout << "Modificando datos del cliente\n";
		cout << "Nuevo Nombre:";
		getline(cin, nom_ape_new);
		cout << "Nuevo DNI:";
		cin >> dni_new;
		bool estado = customController->modificar(customojb, nom_ape_new, dni_new);
		if (estado = true)
		{
			cout << "CLIENTE MODIFICADO SATISFACTORIAMENTE!!!\n";
			customController->grabar_modificar_eliminar_archivo();

		}
		else
		{
			cout << "NO SE ENCONTRO EL CLIENTE A MODIFICAR!\n";

		}


	}
	else
	{
		cout << "No se encontro el cliente!\n";
	}
}
void eliminar_customer()
{
	int codigo;
	cout << "Ingrese codigo a buscar:";
	cin >> codigo;
	Customer objEliminar = customController->get_buscar_por_codigo(codigo);
	if (objEliminar.get_nom_ape() != "ERROR")
	{
		customController->remove(objEliminar);
		cout << "CLIENTE ELIMINADO SATISFACTORIAMENTE!!!";
		customController->grabar_modificar_eliminar_archivo();
	}
	else 
	{
		cout << "No se encontro el cliente!\n";
	}

}
void product()
{
	int opt;
	do
	{
		cout << "************MENU DE OPCIONES************\n";
		cout << "Nuevo Producto[1]***********************\n";
		cout << "Listar Producto[2]**********************\n";
		cout << "Buscar Producto[3]**********************\n";
		cout << "Modificar Producto[4]*******************\n";
		cout << "Eliminar Producto[5]********************\n";
		cout << "Regresar al menu principal[6]***********\n";
		cout << "Salir[7]********************************\n";
		cout << "Ingresar una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls");
			nuevo_product();
			system("pause");
			system("cls");
			break;
		case 2:system("cls");
			listar_product();
			system("pause");
			system("cls");
			break;
		case 3:system("cls");
			buscar_product();
			system("pause");
			system("cls");
			break;
		case 4:system("cls");
			modificar_product();
			system("pause");
			system("cls");
			break;
		case 5:system("cls");
			eliminar_product();
			system("pause");
			system("cls");
			break;
		case 6:system("cls");
			system("pause");
			system("cls");
			menu();
			break;
		case 7:system("cls");
			cout << "GRACIAS POR USAR NUESTRO PROGRAMA\n";
			exit(0);
			break;
		default:system("cls");
			cout << "Ingrese una opcion entre [1-7]";
			system("pause");
			system("cls");
		}
	} while (opt != 7);
}
void nuevo_product()
{
	string flag;
	int codigo;
	string nombre;
	float precio;
	int cantidad;
	do
	{
		codigo = prodController->get_correlativo();
		cout << "*****Producto(" << codigo << ")*****\n";
		cin.ignore();
		cout << "Nombre del producto:";
		getline(cin, nombre);
		cout << "Precio del producto:";
		cin >> precio;
		cout << "Cantidad del producto:";
		cin >> cantidad;
		cout << "Continuar(S/s):";
		cin >> flag;
		Product objProd(codigo, nombre, precio, cantidad);
		prodController->add(objProd);
		prodController->grabar_archivo(objProd);
		system("cls");
	} while (flag == "S" || flag == "s");
}
void listar_product()
{
	for (int i = 0; i < prodController->size(); i++)
	{
		cout << prodController->get(i).get_codigo() << "\t" << prodController->get(i).get_nombre() << "\t" << prodController->get(i).get_precio() << "\t" << prodController->get(i).get_cantidad() << endl;

	}

}
void buscar_product()
{
	int codigo;
	cout << "Ingrese el codigo del producto:";
	cin >> codigo;
	Product prodojb = prodController->get_buscar_por_codigo(codigo);
	if (prodojb.get_nombre() != "ERROR")
	{
		cout << "*****PRODUCTO ENCONTRADO*****\n";
		cout << "Codigo:" << prodojb.get_codigo() << "\n";
		cout << "Nombre:" << prodojb.get_nombre() << "\n";
		cout << "Precio:" << prodojb.get_precio() << "\n";
		cout << "Cantidad" << prodojb.get_cantidad() << "\n";
	}
	else
	{
		cout << "NO SE HA ENCONTRADO UN PRODUCTO";
	}
}
void modificar_product()
{
	int codigo;
	cout << "Ingrese el codigo del producto:";
	cin >> codigo;
	Product prodojb = prodController->get_buscar_por_codigo(codigo);
	if (prodojb.get_nombre() != "ERROR")
	{
		cout << "*****PRODUCTO ENCONTRADO*****\n";
		cout << "Codigo:" << prodojb.get_codigo() << "\n";
		cout << "Nombre:" << prodojb.get_nombre() << "\n";
		cout << "Precio:" << prodojb.get_precio() << "\n";
		cout << "Cantidad" << prodojb.get_cantidad() << "\n";
		cin.ignore();
		string nombre_new;
		float precio_new;
		int cantidad_new;
		cout << "MODIFICANDO DATOS DEL PRODUCTO\n";
		cout << "Nuevo Nombre del producto:";
		getline(cin, nombre_new);
		cout << "Nuevo precio:";
		cin >> precio_new;
		cout << "Nueva cantidad:";
		cin >> cantidad_new;
		bool estado = prodController->modificar(prodojb, nombre_new, precio_new, cantidad_new);
		if (estado = true)
		{
			cout << "PRODUTO MODIFICADO EXITOSAMENTE!!!\n";
			prodController->grabar_modificar_eliminar_archivo();

		}
		else
		{
			cout << "NO SE ENCONTRA EL PRODUCTO A MOFIDICAR!!!\n";
		}

	}
	else
	{
		cout << "NO SE HA ENCONTRADO UN PRODUCTO";
	}
}
void eliminar_product()
{
	int codigo;
	cout << "Ingrese codigo a buscar:";
	cin >> codigo;
	Product objEliminar = prodController->get_buscar_por_codigo(codigo);
	if (objEliminar.get_nombre() != "ERROR")
	{
		prodController->remove(objEliminar);
		cout << "PRODUCTO ELIMINADO EXITOSAMENTE!!!";
		prodController->grabar_modificar_eliminar_archivo();
	}
	else
	{
		cout << "No se encontra el producto!!!\n";
	}

}
void seller()
{
	int opt;
	do
	{
		cout << "***********MENU DE OPCIONES***********\n";
		cout << "Nuevo Vendedor[1]**********************\n";
		cout << "Listar Vendedor[2]*********************\n";
		cout << "Buscar Vendedor[3]*********************\n";
		cout << "Modificar Vendedor[4]******************\n";
		cout << "Eliminar Vendedor[5]*******************\n";
		cout << "Regresar al menu principal[6]*********\n";
		cout << "Salir[7]******************************\n";
		cout << "Ingresar una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls");
			nuevo_seller();
			system("pause");
			system("cls");
			break;
		case 2:system("cls");
			listar_seller();
			system("pause");
			system("cls");
			break;
		case 3:system("cls");
			buscar_seller();
			system("pause");
			system("cls");
			break;
		case 4:system("cls");
			modificar_seller();
			system("pause");
			system("cls");
			break;
		case 5:system("cls");
			eliminar_seller();
			system("pause");
			system("cls");
			break;
		case 6:system("cls");
			system("pause");
			system("cls");
			menu();
			break;
		case 7:system("cls");
			cout << "GRACIAS POR USAR NUESTRO PROGRAMA\n";
			exit(0);
			break;
		default:system("cls");
			cout << "Ingrese una opcion entre [1-7]";
			system("pause");
			system("cls");
		}
	} while (opt != 7);

}
void nuevo_seller()
{
	string flag;
	int codigo;
	string nom_ape;
	string dni;
	do
	{
		codigo = sellController->get_correlativo();
		cout << "*****Vendedor(" << codigo << ")*****\n";
		cin.ignore();
		cout << "Nombres y apellidos:";
		getline(cin, nom_ape);
		cout << "DNI:";
		cin >> dni;
		cout << "Continuar(S/s):";
		cin >> flag;
		Seller objSell(codigo, nom_ape, dni);
		sellController->add(objSell);
		sellController->grabar_archivo(objSell);
		system("cls");
	} while (flag == "S" || flag == "s");

}
void listar_seller()
{
	for (int i = 0; i < sellController->size(); i++)
	{
		cout << sellController->get(i).get_codigo() << "\t" << sellController->get(i).get_nom_ape() << "\t" << sellController->get(i).get_dni() << endl;
	}
}
void buscar_seller()
{
	int codigo;
	cout << "Ingrese el codigo del vendedor:";
	cin >> codigo;
	Seller sellojb = sellController->get_buscar_por_codigo(codigo);
	if (sellojb.get_nom_ape() != "Error")
	{
		cout << "*****Vendedor encontrado*****\n";
		cout << "Codigo:" << sellojb.get_codigo() << "\n";
		cout << "Nombres y apellidos:" << sellojb.get_nom_ape() << "\n";
		cout << "DNI:" << sellojb.get_dni() << "\n";
	}
	else
	{
		cout << "No se encontro el Vendedor!\n";
	}

}
void modificar_seller()
{
	int codigo;
	cout << "Ingrese el codigo del vendedor:";
	cin >> codigo;
	Seller sellojb = sellController->get_buscar_por_codigo(codigo);
	if (sellojb.get_nom_ape() != "Error")
	{
		cout << "*****Vendedor encontrado*****\n";
		cout << "Codigo:" << sellojb.get_codigo() << "\n";
		cout << "Nombres y apellidos:" << sellojb.get_nom_ape() << "\n";
		cout << "DNI:" << sellojb.get_dni() << "\n";
		cin.ignore();

		string nom_ape_new;
		string dni_new;
		cout << "Modificando datos del vendedor\n";
		cout << "Nuevo Nombre:";
		getline(cin, nom_ape_new);
		cout << "Nuevo DNI:";
		cin >> dni_new;
		bool estado = sellController->modificar(sellojb, nom_ape_new, dni_new);
		if (estado = true)
		{
			cout << "VENDEDOR MODIFICADO SATISFACTORIAMENTE!!!\n";
			sellController->grabar_modificar_eliminar_archivo();

		}
		else
		{
			cout << "NO SE ENCONTRO EL VENDEDOR A MODIFICAR!\n";

		}
	}
	else
	{
		cout << "No se encontro el Vendedor!\n";
	}
}
void eliminar_seller()
{
	int codigo;
	cout << "Ingrese codigo a buscar:";
	cin >> codigo;
	Seller objEliminar = sellController->get_buscar_por_codigo(codigo);
	if (objEliminar.get_nom_ape() != "ERROR")
	{
		sellController->remove(objEliminar);
		cout << "VENDEDOR ELIMINADO SATISFACTORIAMENTE!!!";
		sellController->grabar_modificar_eliminar_archivo();
	}
	else
	{
		cout << "No se encontro el vendedor!\n";
	}
}
void sale()
{
	int codes;
	int cantidad;
	string rpt;
	string rpta;

	int code;
	int codigo;
	int cod;
	string fecha;
	float total = 0;
	int estado = 0;
	int c;

	cout << "VENTA" << endl;
	c = saleController->get_correlativo();
	fecha = "04/12/20222";
	cout << "Fecha:" << fecha << endl;
	cout << "Codigo de Venta[" << "0" << c + 1 << "]" << endl;
	cout << "Ingresar codigo del cliente:";
	cin >> code;
	Customer objCustom = customController->get_buscar_por_codigo(code);
	cout << "CLIENTE:" << objCustom.get_dni() << " " << objCustom.get_nom_ape()<<endl;
	cout << "****************" << endl;
	cout << "Ingresar codigo del vendedor:";
	cin >> codigo;
	Seller objSeller = sellController->get_buscar_por_codigo(codigo);
	cout << "VENDEDOR:" << objSeller.get_nom_ape() << " " << objSeller.get_dni() << endl;
	cout << "\n";
	cout << "\t PRODUCTOS EN VENTA" << endl;
	do
	{
		for (int i = 0; i < prodController->size(); i++)
		{
			cout << "Codigo" << "000" << prodController->get(i).get_codigo() << "\n";
			cout << "Nombre" << prodController->get(i).get_nombre() << "\n";
			cout << "Precio:" << prodController->get(i).get_precio() << "\n";
			cout << "***************" << endl;
		}
		cout << "\n";
		cout << "Ingrese el codigo del producto:";
		cin >> codes;
		system("cls");
		Product objProduct = prodController->get_buscar_por_codigo(codes);
		if (objProduct.get_nombre() == "ERROR")
		{
			cout << "No se encontro el producto!!!" << endl;
		}
		else
		{
			cout << "PRODUCTO ENCONTRADO!!!" << endl;
			cout << "Codigo" << "000" << objProduct.get_codigo() << "\n";
			cout << "Nombre" << objProduct.get_nombre() << "\n";
			cout << "Precio:" << objProduct.get_precio() << "\n";
			cout << "***************" << endl;
			
		}
		cout << "CANTIDAD";
		cin >> cantidad;
		cout << "ESTA SEGURO DE AGREGAR LOS SIGUIENTES PRODUCTOS?(S/s)" << endl;
		cin >> rpt;
		Detail objDetail;

		if (rpt == "S" || rpt == "s")
		{
			c = saleController->get_correlativo();
			objDetail.set_codigo_venta(c + 1);
			objDetail.set_nombre_venta(objProduct.get_nombre());
			objDetail.set_codigo_producto(codes);
			objDetail.set_cantidad_venta(cantidad);
			objDetail.set_precio_venta(objProduct.get_precio());
			detailController->add(objDetail);
			total += objDetail.get_sub_total();
			detailController->listar(objDetail);
		}
		else
		{
			system("pause");

		}
		cout << "DESEA AGREGAR OTRO PRODUCTO?(S/S):";
		cin >> rpta;
		detailController->grabar_archivo(objDetail);
	} while (rpta == "S" || rpta == "s");
	Sale objSale;
	objSale.set_codigo_venta(c + 1);
	objSale.set_codigo_cliente(code);
	objSale.set_codigo_vendedor(codigo);
	objSale.set_fecha(fecha);
	objSale.set_total(total);
	saleController->add(objSale);
	saleController->grabar_archivo(objSale);
	system("cls");
	cout << "El precio a pagar es:" << objSale.get_total() << endl;

}