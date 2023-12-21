#include <iostream>
#include <windows.h>


using namespace std;


struct automovil{
    string codigo;
    string modelo;
    double precio;
    int cantAutos;
    string marca;
};

struct nodoAutos{
    automovil *infoAuto;
    nodoAutos *sgte;
};

struct listaAutos{
    nodoAutos *cab;
    unsigned short nAutos;
};

struct cliente{
    string codigo;
    string DNI;
    string nombre;
    string apellido;
    int edad;
    bool licencia;
};

struct nodoClientes{
    cliente *infoCliente;
    nodoClientes *sgte;
};

struct listaClientes{
    nodoClientes *cab;
    int nmrClientes;
};

struct colaCliente{
    nodoClientes *atras;
    nodoClientes *adelante;
    int nCliente;
};

struct venta{
    automovil *infoA;
    cliente *infoC;
    string codigo;

};

struct nodoVenta{
    venta *info;
    nodoVenta *sgte;

};

struct listaVenta{
    nodoVenta *cab;
    int nmrVenta;
};
struct alquiler {
    automovil *infoAuto;
    cliente *infoCliente;
    string codigo;
    // Otros datos necesarios para un alquiler de autos
};

struct nodoAlquiler {
    alquiler *info;
    nodoAlquiler *sgte;
};

struct listaAlquiler {
    nodoAlquiler *cab;
    int nmrAlquiler;
};
struct nodoSucursal{
    string codigo;
    colaCliente *cC;
    listaClientes *lc;
    listaAutos *lA;
    listaVenta *lV;
    listaAlquiler *lAlq;
    string direccion;
    struct nodoSucursal *sgte;
    struct aristaSuc *adyacente;
};

struct aristaSuc{
    nodoSucursal *destino;
    aristaSuc *sgte;
};

struct grafoSucursal{
    aristaSuc *aristaC;
    nodoSucursal *cab;
    int nmrSuck;
};

struct cunya {
    string Nombre;
    grafoSucursal *lS;
};
