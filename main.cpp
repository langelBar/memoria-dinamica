#include <iostream>
#include <queue>
#include <windows.h>
#include <fstream>
#include <estructuras.cpp>
#include <basicas.cpp>
#include <string>

using namespace std;

int contSuc=1;
int contVenta=1;
int contAuto=1;
int clienteCont=1;
int contAlquiler = 1;


void inicializarListaClientes(listaClientes *lc){
    lc->cab=new nodoClientes();
    lc->nmrClientes=0;
}

void inicializarVenta(venta *v){
    v->infoA=new automovil();
    v->infoC=new cliente();
}
void inicializarAlquiler(alquiler *alq) {
    alq->codigo = "";
    alq->infoAuto = NULL;
    alq->infoCliente = NULL;
}

void inicializarCunya(cunya *nuevo){
    nuevo->Nombre="AUTOMOVILISTICA CUNYA";
    nuevo->lS=new grafoSucursal();
}

void inicializar_listaAutos(listaAutos *lA){
    lA->cab=NULL;
    lA->nAutos=0;
}
void inicializar_automovil(automovil *a){
    a->precio=0;
}
void inicializar_colaClientes(colaCliente *cC){
    cC->adelante=new nodoClientes();
    cC->nCliente=0;
    cC->atras=new nodoClientes();
}
void inicializar_cliente(cliente *c){
    c->edad=0;
    c->licencia=true;
}

void inicializarListaVenta(listaVenta *lv){
    lv->nmrVenta=0;
    lv->cab=new nodoVenta();
}

void inicializarListaAlquiler(listaAlquiler *la){
    la->nmrAlquiler=0;
    la->cab=NULL;
}

void inicilizarSucursal(nodoSucursal *sc){
    sc->cC=new colaCliente();
    sc->lA=new listaAutos();
    sc->lV=new listaVenta();
    sc->lAlq=new listaAlquiler();
    sc->lc=new listaClientes();
    sc->adyacente=NULL;
    sc->sgte=NULL;
    inicializarListaClientes(sc->lc);
    inicializar_colaClientes(sc->cC);
    inicializar_listaAutos(sc->lA);
    inicializarListaVenta(sc->lV);
    sc->codigo=generarCodigo("SUC",contSuc);
}

void inicializarGrafoSucursal(grafoSucursal *gS){
    gS->aristaC=NULL;
    gS->cab=NULL;
    gS->nmrSuck=0;
}

void inicializaArista( aristaSuc *nuevo){
    nuevo->destino = NULL;
    nuevo->sgte = NULL;
}

void leerCliente(cliente *c,string dato){
    gotoxy(40, 7);cout << "Llene los datos del nuevo cliente a continuacion:" << endl;
    gotoxy(40, 8);c->codigo=generarCodigo(dato+"CLI",clienteCont);
    gotoxy(40, 9);c->nombre=leerTexto("Ingrese el nombre del cliente: ",40,9);
    gotoxy(40, 10);c->apellido=leerTexto("Ingrese el apellido del cliente: ",40,10);
    gotoxy(40, 11);c->DNI=leerTexto("Ingrese el DNI del cliente: ",40,11);
    gotoxy(40, 12);c->edad=leerEntero("Ingrese su edad: ");
    gotoxy(40, 13);c->licencia=leerEstado("Ingrese SI//NO si actualmente tiene licencia: ");

}

cliente *elejirCliente(colaCliente *lS){
    int numero=1;
    int valor=0;
    gotoxy(5,3 ); cout << "LISTA DE CLIENTES";

    nodoClientes *aux = lS->atras;
    gotoxy(5,4 + numero); cout << numero << "." <<lS->adelante->infoCliente->codigo<<"  "<<lS->adelante->infoCliente->DNI<<" "<<lS->adelante->infoCliente->nombre;
    numero++;
    if(lS->atras!=NULL){
        while( aux != NULL ){
            gotoxy(5,4 + numero); cout << numero << "." <<aux->infoCliente->codigo<<"  "<<aux->infoCliente->DNI<<" "<<aux->infoCliente->nombre;
            numero++;
            aux = aux->sgte;
        }
    }
    do{
        gotoxy(5, 4+ numero); cout << "Elija opcion:";
        cin >> valor;
    }while(!( valor>0 && valor < numero+1  ));
    if(valor==1){
        return lS->adelante->infoCliente;
    }
    if(valor!=1){
        valor--;
    }
    aux = lS->atras;
    for ( int y=0; y < valor-1; y++ ){
        aux = aux->sgte;
    }
    return aux->infoCliente;
}

automovil *elejirAuto(listaAutos *lS){
    int numero=1;
    int valor=0;
    gotoxy(5,3 ); cout << "LISTA DE AUTOMOVILES";
    nodoAutos *aux = lS->cab;
    while( aux ){
        gotoxy(5,4 + numero); cout << numero << "." <<aux->infoAuto->codigo<<"  "<<aux->infoAuto->precio;
        numero++;
        aux = aux->sgte;
    }
    do{
        gotoxy(5, 4+ numero); cout << "Elija opcion:";
        cin >> valor;
    }while(!( valor > 0 && valor < lS->nAutos + 1  ));
    aux = lS->cab;
    for ( int y = 0; y < valor -1; y++ ){
        aux = aux->sgte;
    }
    return aux->infoAuto;
}


nodoSucursal *elejirSucursal(grafoSucursal *lS){
    int numero=1;
    int valor=0;
    gotoxy(5,3 ); cout << "LISTA DE SUCURSALES";
    gotoxy(5,4 ); cout << "--------------------";
    nodoSucursal *aux = lS->cab;
    while( aux !=NULL ){
        gotoxy(5,4 + numero); cout << numero << "." <<aux->codigo<<"  "<<aux->direccion;
        numero++;
        aux = aux->sgte;
    }
    do{
        gotoxy(5, 4+ numero); cout << "Elija opcion:";
        cin >> valor;
    }while(!( valor > 0 && valor < lS->nmrSuck + 1  ));
    aux = lS->cab;
    for ( int y = 0; y < valor -1; y++ ){
        aux = aux->sgte;
    }
    return aux;
}

void registroGlobalCliente(listaClientes *lc,cliente *c){
    system("cls");
    nodoClientes *nuevo = new nodoClientes();
    nuevo->infoCliente = c;
    nuevo->sgte = NULL;

    if (lc->nmrClientes==0) {
        lc->cab = nuevo;
    } else {
        nodoClientes *aux = lc->cab;
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
    lc->nmrClientes++;
}

void RegistrarCliente(grafoSucursal *lS,listaClientes *lc) {
    system("cls");
    if(lS->nmrSuck==0){
        gotoxy(40, 20);cout <<"PRIMERO INGRESE PRIMERO SUCURSALES";
        system("pause>>null");
        return;
    }
    nodoSucursal *nS=elejirSucursal(lS);
    system("cls");
    colaCliente *cC=nS->cC;
    cliente *c = new cliente();
    inicializar_cliente(c);
    leerCliente(c,nS->codigo);
    registroGlobalCliente(nS->lc,c);
    if (c->edad < 21) {
            gotoxy(40, 20);cout << "Lo sentimos, solo se permiten clientes mayores de 21 anios." << endl;
            delete c; // Liberar la memoria del cliente
            system("pause");
            return;
        }
    nodoClientes *nuevoCliente = new nodoClientes();
    nodoClientes *temp = cC->atras;
    nuevoCliente->infoCliente = c;
    nuevoCliente->sgte = NULL;

    if (cC->nCliente == 0) {
        cC->adelante = nuevoCliente;
        cC->atras=NULL;
    } else {
        if(cC->nCliente==1){
            cC->atras=nuevoCliente;
        }else {
            while (temp->sgte!=NULL) {
                temp=temp->sgte;
            }
            temp->sgte=nuevoCliente;
        }
    }
    clienteCont++;
    cC->nCliente++;
    registroGlobalCliente(lc,c);
    gotoxy(40, 20);cout << "Cliente registrado exitosamente." << endl;
    system("pause");
}
void leerAuto(automovil *a){

    a->codigo=generarCodigo("AUT",contAuto);
    gotoxy(40, 7);cout << "Llene los datos del nuevo automovil a continuacion:" << endl;
    gotoxy(40, 8);a->modelo=leerTexto("Ingrese el modelo del automovil: ",40,8);
    gotoxy(40, 9);a->precio=leerDouble("Ingrese el precio del automovil: ");
    gotoxy(40, 10);a->marca=leerTexto("Ingrese la marca del automovil: ",40,10);
    gotoxy(40, 11);a->cantAutos=leerEntero("Ingrese la cantidad de automoviles disponibles: ");
}

void mostrarColaClientes(grafoSucursal *lS) {
    system("cls");
    nodoSucursal *nS=elejirSucursal(lS);
    system("cls");
    colaCliente *cC=nS->cC;
    nodoClientes *aux = cC->atras;
    cliente *temp=new cliente();
    if (cC->nCliente == 0) {
        gotoxy(40, 3);cout << "No hay personas en la cola de clientes." << endl;
    } else {
        gotoxy(40, 3);cout << "Cola de Clientes:" << endl;
        int i = 1;
        temp=cC->adelante->infoCliente;
        gotoxy(40, 5);cout << i << ".(NOMBRE: " << temp->nombre << "),(APELLIDO: " << temp->apellido << "),(CODIGO: " << temp->codigo << ")" << endl;
        i++;
        if(cC->nCliente==1){
            system("pause");
            return;
        }
        while (aux != NULL) {
            gotoxy(40, 4+i);cout << i << ".(NOMBRE: " << aux->infoCliente->nombre << "),(APELLIDO: " << aux->infoCliente->apellido << "),(CODIGO: " << aux->infoCliente->codigo << ")" << endl;
            aux = aux->sgte;
            i++;
        }
    }
    system("pause");
}



void buscarCliente(grafoSucursal *ls){
    nodoClientes *aux=new nodoClientes();
    cliente *temp=new cliente();
    nodoSucursal *nuevo= new nodoSucursal();
    nuevo=ls->cab;
    string busqueda;
    system("cls");
    int opc=0;
    while (nuevo !=NULL) {
        if(nuevo->lc->nmrClientes==0){
            system("cls");
            gotoxy(40, 15);cout<<"NO HAY CLIENTES REGISTRADOS"<<endl;
            system("pause");
            return;
        }
        nuevo=nuevo->sgte;
    }
    nuevo=ls->cab;
    do{
        opc=menuBuscarPor();
        switch (opc) {
        case 1:
            gotoxy(40, 15);busqueda=leerTexto("INGRESE DNI PARA BUSCAR :",40,10);
            while (nuevo !=NULL) {
                colaCliente *cC=nuevo->cC;
                aux=cC->atras;
                if(cC->adelante->infoCliente->DNI==busqueda){
                    system("cls");
                    temp=cC->adelante->infoCliente;
                    gotoxy(40, 10);cout<< "(NOMBRE: " << temp->nombre << "),(APELLIDO: " << temp->apellido << "),(CODIGO: " << temp->codigo << ")" << endl;
                    system("pause");
                    return;
                }
                while (aux != NULL) {
                    system("cls");
                    if(aux->infoCliente->DNI==busqueda){
                        temp=aux->infoCliente;
                        system("cls");
                        gotoxy(40, 10);cout<< "(NOMBRE: " << temp->nombre << "),(APELLIDO: " << temp->apellido << "),(CODIGO: " << temp->codigo << ")" << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO CLIENTE";
            system("pause");
            return;
            break;
        case 2:
            gotoxy(40, 15);busqueda=leerTexto("INGRESE NOMBRE PARA BUSCAR :",40,10);
            while (nuevo !=NULL) {
                colaCliente *cC=nuevo->cC;
                aux=cC->atras;
                if(cC->adelante->infoCliente->nombre==busqueda){
                    system("cls");
                    temp=cC->adelante->infoCliente;
                    gotoxy(40, 10);cout<< "(NOMBRE: " << temp->nombre << "),(APELLIDO: " << temp->apellido << "),(CODIGO: " << temp->codigo << ")" << endl;
                    system("pause");
                    return;
                }
                while (aux != NULL) {
                    system("cls");
                    if(aux->infoCliente->nombre==busqueda){
                        temp=aux->infoCliente;
                        system("cls");
                        gotoxy(40, 10);cout<< "(NOMBRE: " << temp->nombre << "),(APELLIDO: " << temp->apellido << "),(CODIGO: " << temp->codigo << ")" << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO CLIENTE";
            system("pause");
            break;
        default:
            break;
        }
    }while(opc !=0);
}


void registarSucursalesDato(grafoSucursal *lS,nodoSucursal *a){
    system("cls");
    lS->nmrSuck++;
    nodoSucursal *nuevo = new nodoSucursal();
    nuevo = a;
    nuevo->sgte = NULL;

    if (lS->cab == NULL) {
        lS->cab = nuevo;
    } else {
        nodoSucursal *aux = lS->cab;
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
    contSuc++;
}

void registrarSucursales(grafoSucursal *lS){
    system("cls");
    nodoSucursal *a = new nodoSucursal();
    inicilizarSucursal(a);
    a->codigo=generarCodigo("SUC",contSuc);
    gotoxy(40, 14);a->direccion=leerTexto("INGRESE DIRECCION :",40,14);
    registarSucursalesDato(lS,a);
    gotoxy(40, 15);cout << "Sucursal registrada exitosamente." << endl;
    system("pause");
}

void mostrarSucursales(grafoSucursal *lS){
    system("cls");
    nodoSucursal *aux=new nodoSucursal();
    aux=lS->cab;
    system("cls");
    int x=1;
    gotoxy(40, 8);cout<< "LISTA DE SUCURSALES";
    while (aux != NULL) {
            gotoxy(40, 9+x);cout<< "(CODIGO: " << aux->codigo << "),(DIRECCION: " << aux->direccion<< ")" << endl;
            x++;
        aux = aux->sgte;
    }
    system("pause");
}

void buscarSucursales(grafoSucursal *lS){
    nodoSucursal *temp=new nodoSucursal();
    string busqueda;
    system("cls");
    gotoxy(40, 15);busqueda=leerTexto("INGRESE CODIGO PARA BUSCAR :",40,10);
    nodoSucursal *nuevo= new nodoSucursal();
    nuevo=lS->cab;
    if(lS->nmrSuck==0){
        system("cls");
        gotoxy(40, 15);cout<<"NO HAY SUCURSALES REGISTRADOS"<<endl;
        system("pause");
        return;
    }
    nuevo=lS->cab;
    while (nuevo !=NULL) {
        system("cls");
        temp=nuevo;
        if(temp->codigo==busqueda){
            gotoxy(40, 10);cout<< "(CODIGO: " << temp->codigo << " ),( DIRECCION: " << temp->direccion << ") "<<endl;
            system("pause");
            return;
        }
        nuevo=nuevo->sgte;
    }
    system("cls");
    gotoxy(40, 10);cout<<"NO SE ENCONTRO SUCURSALES";
    system("pause");
}

//esta funcion añade sucursales para iniciar
void aniadirSucursales(grafoSucursal *lS){
    nodoSucursal *nuevo1=new nodoSucursal();
    nodoSucursal *nuevo2=new nodoSucursal();
    nodoSucursal *nuevo3=new nodoSucursal();
    inicilizarSucursal(nuevo1);
    inicilizarSucursal(nuevo2);
    inicilizarSucursal(nuevo3);
    nuevo1->codigo=generarCodigo("SUC",51);
    nuevo2->codigo=generarCodigo("SUC",25);
    nuevo3->codigo=generarCodigo("SUC",64);
    nuevo1->direccion=generarCodigo("mariscal nieto ",502);
    nuevo2->direccion=generarCodigo("los sauces ",203);
    nuevo3->direccion=generarCodigo("buenos aires ",640);
    registarSucursalesDato(lS,nuevo1);
    registarSucursalesDato(lS,nuevo2);
    registarSucursalesDato(lS,nuevo3);

}

void RegistrarAuto(grafoSucursal *lS) {
    system("cls");
    nodoSucursal * nuevo=elejirSucursal(lS);
    listaAutos *lA=nuevo->lA;
    system("cls");
    int x;
    x=lA->nAutos;
    automovil *a = new automovil();
    a->precio = 0;
    leerAuto(a);
    lA->nAutos++;
    nodoAutos *nuevoAuto = new nodoAutos();
    nuevoAuto->infoAuto = a;
    nuevoAuto->sgte = NULL;

    if (lA->cab == NULL) {
        lA->cab = nuevoAuto;
    } else {
        nodoAutos *aux = lA->cab;
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevoAuto;
    }
    contAuto++;
    gotoxy(40, 14+x);cout << "Automovil registrado exitosamente." << endl;
    system("pause");
}

void mostrarAutosDisponibles(grafoSucursal *lS) {
    system("cls");
    nodoSucursal *nuevo=elejirSucursal(lS);
    listaAutos *lA=nuevo->lA;
    system("cls");
    gotoxy(40, 2); cout << "Lista de Automoviles Disponibles:" << endl;
    nodoAutos *aux = lA->cab;
    int i = 1;
    while (aux != NULL) {
        automovil *autoInfo = aux->infoAuto;
        gotoxy(40, 7+i);cout << i << ". Codigo: " << autoInfo->codigo<< ". Marca: " << autoInfo->marca << ", Modelo: " << autoInfo->modelo
             << ", Precio: $" << autoInfo->precio << ", Cantidad: " << autoInfo->cantAutos << endl;
        aux = aux->sgte;
        i++;
    }
    system("pause");
}

void buscarAuto(grafoSucursal *ls){
    string busqueda;
    nodoAutos *aux= new nodoAutos();
    automovil *temp= new automovil();
    nodoSucursal *nuevo= new nodoSucursal();
    nuevo=ls->cab;
    int opc=0;
    while (nuevo !=NULL) {
        if(nuevo->lA->nAutos==0){
            system("cls");
            gotoxy(40, 15);cout<<"NO HAY AUTOS REGISTRADOS"<<endl;
            system("pause");
            return;
        }
        nuevo=nuevo->sgte;
    }
    nuevo=ls->cab;
    do{
        opc=menuAutBuscarPor();
        switch (opc) {
        case 1:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE CODIGO PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lA->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->infoAuto->codigo==busqueda){
                        temp=aux->infoAuto;
                        gotoxy(40, 10);cout<< "(codigo: " << temp->codigo << "),(marca: " << temp->marca << "),(modelo : " << temp->modelo << ")"<< "),(precio: " << temp->precio << ")"<< "),(stock: " << temp->cantAutos << ")" << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO AUTO";
            system("pause");
            break;
        case 2:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE MODELO PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lA->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->infoAuto->codigo==busqueda){
                        temp=aux->infoAuto;
                        gotoxy(40, 10);cout<< "(codigo: " << temp->codigo << "),(marca: " << temp->marca << "),(modelo : " << temp->modelo << ")"<< "),(precio: " << temp->precio << ")"<< "),(stock: " << temp->cantAutos << ")" << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO AUTO";
            system("pause");
            break;
        case 3:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE MARCA PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lA->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->infoAuto->marca==busqueda){
                        temp=aux->infoAuto;
                        gotoxy(40, 10);cout<< "(codigo: " << temp->codigo << "),(marca: " << temp->marca << "),(modelo : " << temp->modelo << ")"<< "),(precio: " << temp->precio << ")"<< "),(stock: " << temp->cantAutos << ")" << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO AUTO";
            system("pause");
            break;
        default:
            break;
        }
    }while(opc !=0);
}

void desencolar(colaCliente *cC,string busqueda){
    nodoClientes *aux=new nodoClientes();
    cliente *temp=new cliente();
    aux=cC->atras;
    system("cls");
    if(cC->nCliente==0){
        system("cls");
        gotoxy(40, 15);cout<<"NO HAY CLIENTES REGISTRADOS"<<endl;
        system("pause");
        return;
    }
    while (aux !=NULL) {
        if(cC->adelante->infoCliente->codigo==busqueda){
            system("cls");
            temp=cC->adelante->infoCliente;
            gotoxy(30, 10);cout<<"CLIENTE SELECCIONADO"<< endl;
            system("pause");
            return;
        }
        while (aux != NULL) {
            system("cls");
            if(aux->infoCliente->codigo==busqueda){
                temp=aux->infoCliente;
                system("cls");
                gotoxy(40, 10);cout<<"CLIENTE SELECCIONADO"<< endl;
                system("pause");
                return;
            }
            aux = aux->sgte;
        }
    }
    system("cls");
    gotoxy(40, 10);cout<<"NO SE ENCONTRO CLIENTE";
    system("pause");
    return;
}

void registrarVenta(grafoSucursal *lS){
    system("cls");
    if(lS->nmrSuck==0){
        gotoxy(40, 20);cout <<"PRIMERO INGRESE PRIMERO SUCURSALES";
        system("pause>>null");
        return;
    }
    nodoSucursal *nS=elejirSucursal(lS);
    if(nS->cC->nCliente==0){
        gotoxy(40, 20);cout <<"PRIMERO INGRESE PRIMERO CLIENTES";
        system("pause>>null");
        return;
    }
    if(nS->lA->nAutos==0){
        gotoxy(40, 20);cout <<"PRIMERO INGRESE PRIMERO AUTOS";
        system("pause>>null");
        return;
    }
    venta * v=new venta();
    inicializarVenta(v);
    listaVenta *lv=nS->lV;
    system("cls");
    cliente *nuevoCliente=new cliente();
    nuevoCliente = elejirCliente(nS->cC);
    //desencolar(nS->cC,nuevoCliente->codigo);
    system("cls");
    automovil *nuevoAuto=new automovil();
    automovil *cambiaStock;
    do{
        cambiaStock=elejirAuto(nS->lA);
    }while(cambiaStock->cantAutos==0);
    cambiaStock->cantAutos--;
    nuevoAuto=cambiaStock;
    v->codigo=generarCodigo("VENT",contVenta);
    v->infoA=nuevoAuto;
    v->infoC=nuevoCliente;
    nodoVenta *aux = lv->cab;
    nodoVenta *nuevoVenta = new nodoVenta();
    nuevoVenta->info = v;
    nuevoVenta->sgte = NULL;

    if (lv->nmrVenta==0) {
        lv->cab = nuevoVenta;
    } else {
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevoVenta;
    }
    lv->nmrVenta++;
    contVenta++;
    gotoxy(40, 20);cout << "VENTA REGISTRADA EXISTOSAMENTE." << endl;
    system("pause");


}

void mostrarVentas(grafoSucursal * lS){
    system("cls");
    nodoSucursal *nuevo=elejirSucursal(lS);
    listaVenta *lv=nuevo->lV;
    system("cls");
    gotoxy(40, 2); cout << "VENTAS REALIZADAS:" << endl;
    nodoVenta *aux = lv->cab;
    int i = 1;
    if(nuevo->lV->nmrVenta==0){
        gotoxy(40, 15);cout<<"NO HAY VENTAS REGISTRADAS"<<endl;
        system("pause");
        return;
    }
    while (aux != NULL) {
        venta *infov = aux->info;
        gotoxy(35, 7+i);cout << i << ". CODIGO: " << infov->codigo
             << ", CLIENTE  NOMBRE: "<< infov->infoC->nombre
             << ", AUTO MARCA:" << infov->infoA->modelo
             << ", PRECIO: "<< infov->infoA->precio << endl;
        aux = aux->sgte;
        i++;
    }
    system("pause");
}
void registrarAlquiler(grafoSucursal *lS) {
    system("cls");
    if (lS->nmrSuck == 0) {
        gotoxy(40, 20); cout << "PRIMERO INGRESE SUCURSALES";
        system("pause>>null");
        return;
    }

    nodoSucursal *nS = elejirSucursal(lS);
    if (nS->lc->nmrClientes == 0) {
        gotoxy(40, 20); cout << "PRIMERO INGRESE CLIENTES";
        system("pause>>null");
        return;
    }

    if (nS->lA->nAutos == 0) {
        gotoxy(40, 20); cout << "PRIMERO INGRESE AUTOS";
        system("pause>>null");
        return;
    }

    // Crear una nueva instancia de alquiler
    alquiler *alq = new alquiler();
    inicializarAlquiler(alq);

    listaAlquiler *lAlq = nS->lAlq;
    system("cls");

    cliente *nuevoCliente = new cliente();
    nuevoCliente = elejirCliente(nS->cC);

    //desencolar(nS->cC, nuevoCliente->codigo);
    system("cls");

    automovil *nuevoAuto = new automovil();
    automovil *autoSeleccionado;
    do {
        autoSeleccionado = elejirAuto(nS->lA);
    } while (autoSeleccionado->cantAutos == 0);
    nuevoAuto = autoSeleccionado;

    alq->codigo = generarCodigo("ALQ", contAlquiler);
    alq->infoAuto = nuevoAuto;
    alq->infoCliente = nuevoCliente;

    nodoAlquiler *aux = lAlq->cab;
    nodoAlquiler *nuevoAlquiler = new nodoAlquiler();
    nuevoAlquiler->info = alq;
    nuevoAlquiler->sgte = NULL;

    if (lAlq->nmrAlquiler == 0) {
        lAlq->cab = nuevoAlquiler;
    } else {
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevoAlquiler;
    }

    lAlq->nmrAlquiler++;
    contAlquiler++;
    gotoxy(40, 20); cout << "ALQUILER REGISTRADO EXITOSAMENTE." << endl;
    system("pause");
}

void mostrarAlquileres(grafoSucursal *lS) {
    system("cls");
    nodoSucursal *nuevo = elejirSucursal(lS);
    listaAlquiler *lAlq = nuevo->lAlq;
    system("cls");
    gotoxy(40, 2); cout << "ALQUILERES REALIZADOS:" << endl;
    nodoAlquiler *aux = lAlq->cab;
    int i = 1;

    if (nuevo->lAlq->nmrAlquiler == 0) {
        gotoxy(40, 15); cout << "NO HAY ALQUILERES REGISTRADOS" << endl;
        system("pause");
        return;
    }

    while (aux != NULL) {
        alquiler *infoAlq = aux->info;
        gotoxy(35, 7 + i); cout << i << ". CODIGO: " << infoAlq->codigo
             << ", CLIENTE NOMBRE: " << infoAlq->infoCliente->nombre
             << ", AUTO MARCA: " << infoAlq->infoAuto->marca
             << ", PRECIO: " << infoAlq->infoAuto->precio << endl;
        aux = aux->sgte;
        i++;
    }
    system("pause");
}
void insertarArista(nodoSucursal *aux, nodoSucursal *temp, aristaSuc *nuevo){
    system("cls");
    aristaSuc *temporal = new aristaSuc();
    if ( aux->adyacente == NULL ){
        aux->adyacente = nuevo;
        nuevo->destino = temp;
    }
    else{
        temporal = aux->adyacente;
        while( temporal->sgte != NULL ){
            temporal = temporal->sgte;
        }
        nuevo->destino = temp;
        temporal->sgte = nuevo;
    }
    gotoxy(40, 5); cout << "Registro correcto"<<endl;
    system("pause");
}

void registrarConexion( grafoSucursal *gS ){
    aristaSuc *nuevo = new aristaSuc();
    string sucOrigen,sucDestino;
    bool val=false;
    nodoSucursal *aux = gS->cab , *temp = gS->cab;
    inicializaArista( nuevo );
    system("cls");
    if ( gS->nmrSuck == 0 ){
        gotoxy(40,5 ); cout << "No hay SUCURSALES";
        return;
    }
    gotoxy(30,5 ); cout<<"INGRESE CODIGOS";
    gotoxy(30,5 ); sucOrigen  = leerTexto("Ingrese Sucursal Origen: ",30,5);
    gotoxy(30,6 ); sucDestino = leerTexto("Ingrese Sucursal Destino: ",30,6);
    while( temp != NULL ){
        if (temp->codigo == sucDestino ){
            val=true;
            break;
        }
        temp = temp->sgte;
    }
    if ( val==true ){
        while( aux != NULL ){
            if ( aux->codigo == sucOrigen ){
                insertarArista( aux, temp, nuevo );
                return;
            }
            aux = aux->sgte;
        }
    }else {
        system("cls");
        gotoxy(30,6 );cout << "INGRESE CODIGO CORRECTOS";
        system("pause");
    }
    system("pause");
}

void mostrarConexiones( grafoSucursal *gS ){
    nodoSucursal *aux = new nodoSucursal();
    aristaSuc *temp = new aristaSuc();
    int x = 1;
    int y = 0;
    aux = gS->cab;
    system("cls");
    gotoxy(20, 3 ); cout << "SUCURSALES ORIGEN";
    gotoxy(50, 3 ); cout << "CONEXIONES";
    while( aux != NULL ){
        y = 0;
        if ( aux->adyacente != NULL ){
            gotoxy(20, 3 + x ); cout << aux->codigo;
            temp = aux->adyacente;
            while( temp != NULL ){
                gotoxy(50 + y, 3 + x  ); cout << temp->destino->codigo;
                temp = temp->sgte;
                y += 20;
            }
        }
        aux = aux->sgte;
        x++;
    }
    system("pause>>null");
}

void buscarVentas(grafoSucursal *ls){
    string busqueda;
    nodoVenta *aux= new nodoVenta();
    nodoSucursal *nuevo= new nodoSucursal();
    nuevo=ls->cab;
    int opc=0;
    while (nuevo !=NULL) {
        if(nuevo->lV->nmrVenta==0){
            system("cls");
            gotoxy(40, 15);cout<<"NO HAY VENTAS REGISTRADAS"<<endl;
            system("pause");
            return;
        }
        nuevo=nuevo->sgte;
    }
    nuevo=ls->cab;
    venta *temp= new venta();
    do{
        opc=menuVenBuscarPor();
        switch (opc) {
        case 1:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE CODIGO PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lV->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->info->codigo==busqueda){
                        temp=aux->info;
                        gotoxy(35, 7);cout << " CODIGO: " << aux->info->codigo
                             << ", CLIENTE  NOMBRE: "<< aux->info->infoC->nombre
                             << ", AUTO MARCA:" << aux->info->infoA->modelo
                             << ", PRECIO: "<< aux->info->infoA->precio << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO VENTA CON LOS DATOS DADOS";
            system("pause");
            break;
        case 2:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE CODIGO CLIENTE PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lV->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->info->infoC->codigo==busqueda){
                        temp=aux->info;
                        gotoxy(35, 7);cout << " CODIGO: " << aux->info->codigo
                             << ", CLIENTE  NOMBRE: "<< aux->info->infoC->nombre
                             << ", AUTO MARCA:" << aux->info->infoA->modelo
                             << ", PRECIO: "<< aux->info->infoA->precio << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO VENTA CON LOS DATOS DADOS";
            system("pause");
            break;
        case 3:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE CODIGO AUTO PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lV->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->info->infoA->codigo==busqueda){
                        temp=aux->info;
                        gotoxy(35, 7);cout << " CODIGO: " << aux->info->codigo
                             << ", CLIENTE  NOMBRE: "<< aux->info->infoC->nombre
                             << ", AUTO MARCA:" << aux->info->infoA->modelo
                             << ", PRECIO: "<< aux->info->infoA->precio << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO VENTA CON LOS DATOS DADOS";
            system("pause");
            break;
        case 4:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE NOMBRE PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lV->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->info->infoC->nombre==busqueda){
                        temp=aux->info;
                        gotoxy(35, 7);cout << " CODIGO: " << aux->info->codigo
                             << ", CLIENTE  NOMBRE: "<< aux->info->infoC->nombre
                             << ", AUTO MARCA:" << aux->info->infoA->modelo
                             << ", PRECIO: "<< aux->info->infoA->precio << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO VENTA CON LOS DATOS DADOS";
            system("pause");
            break;
        case 5:
            system("cls");
            gotoxy(40, 15);busqueda=leerTexto("INGRESE MARCA PARA BUSCAR :",40,10);
            system("cls");
            while (nuevo !=NULL) {
                aux=nuevo->lV->cab;
                gotoxy(40,9);cout<<"SUCURSAL : "<<nuevo->codigo<<" DIRECCION: "<<nuevo->direccion<<endl;
                while (aux != NULL) {

                    if(aux->info->infoA->marca==busqueda){
                        temp=aux->info;
                        gotoxy(35, 7);cout << " CODIGO: " << aux->info->codigo
                             << ", CLIENTE  NOMBRE: "<< aux->info->infoC->nombre
                             << ", AUTO MARCA:" << aux->info->infoA->modelo
                             << ", PRECIO: "<< aux->info->infoA->precio << endl;
                        system("pause>>null");
                        return;
                    }
                    aux = aux->sgte;
                }
                nuevo=nuevo->sgte;
            }
            system("cls");
            gotoxy(40, 10);cout<<"NO SE ENCONTRO VENTA CON LOS DATOS DADOS";
            system("pause");
            break;
        default:
            break;
        }
    }while(opc !=0);
}

void registarAlfCliente(listaClientes *lc, cliente *c,int a){
    system("cls");
    nodoClientes *nuevo = new nodoClientes();
    nuevo->infoCliente = c;
    nuevo->sgte = NULL;

    nodoClientes *aux = lc->cab;
    for (int var = 0; var < a; ++var) {

        aux = aux->sgte;
    }
    nodoClientes *aux2 = lc->cab;
    cliente *temp=new cliente();
    temp=aux->infoCliente;
    for (int var = 0; var < a; ++var) {
        if(aux2->infoCliente->nombre==temp->nombre){
            aux->infoCliente=temp;
            aux = aux->sgte;
        }
    }
    nuevo->sgte=aux->sgte;
    aux=nuevo;
}

void mostrarDatos(nodoClientes *lista) {
    nodoClientes *actual = lista;
    system("cls");
    std::cout << "---- DATOS DE CLIENTES ----" << std::endl;
    while (actual != NULL) {
        cliente *datos = actual->infoCliente;
        std::cout << "Nombre: " << datos->nombre;
        std::cout << " Apellido: " << datos->apellido;
        std::cout << " DNI: " << datos->DNI <<endl;

        actual = actual->sgte;
    }
}

void intercambiarNodos(nodoClientes *a, nodoClientes *b) {
    cliente *temp = a->infoCliente;
    a->infoCliente = b->infoCliente;
    b->infoCliente = temp;
}

void mostrarAlfabeticamente(grafoSucursal *lS){
    system("cls");
    nodoSucursal *nS=elejirSucursal(lS);
    nodoClientes *aver=new nodoClientes();
    aver=nS->lc->cab;
    nodoClientes *actual = aver;
    while (actual != NULL) {
        nodoClientes *minimo = actual;
        nodoClientes *siguiente = actual->sgte;

        while (siguiente != NULL) {
            // Comparar por el campo 'nombre'
            if (siguiente->infoCliente->nombre < minimo->infoCliente->nombre) {
                minimo = siguiente;
            }

            siguiente = siguiente->sgte;
        }

        // Intercambiar los nodos actual y el mínimo encontrado
        intercambiarNodos(actual, minimo);

        actual = actual->sgte;
    }
    mostrarDatos(aver);
    system("pause");
}

void guardarDatosEnArchivo(listaAutos *lista ,string nom ) {
    string nombreArchivoEntrada = "datosautos_" + nom + ".txt";
    const char *nombreArchivo = nombreArchivoEntrada.c_str();
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    nodoAutos *temp = lista->cab;
    while (temp != NULL) {
        archivo << temp->infoAuto->codigo << " "
                << temp->infoAuto->modelo << " "
                << temp->infoAuto->precio << " "
                << temp->infoAuto->cantAutos << " "
                << temp->infoAuto->marca << endl;

        temp = temp->sgte;
    }

    archivo.close();
}

void cargarDatosDesdeArchivo(listaAutos *lista,string nom) {
    string nombreArchivoEntrada = "datosautos_" + nom + ".txt";
    const char *nombreArchivo = nombreArchivoEntrada.c_str();
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        automovil *nuevoAuto = new automovil;

        if (iss >> nuevoAuto->codigo >> nuevoAuto->modelo >> nuevoAuto->precio >> nuevoAuto->cantAutos >> nuevoAuto->marca) {
            nodoAutos *nuevoNodo = new nodoAutos;
            nuevoNodo->infoAuto = nuevoAuto;
            nuevoNodo->sgte = NULL;

            if (lista->cab == NULL) {
                lista->cab = nuevoNodo;
            } else {
                nodoAutos *temp = lista->cab;
                while (temp->sgte != NULL) {
                    temp = temp->sgte;
                }
                temp->sgte = nuevoNodo;
            }

            lista->nAutos++;
        } else {
            cerr << "Error al leer la línea del archivo: " << linea << endl;
                delete nuevoAuto;
        }
    }

    archivo.close();
}

void guardarEn(grafoSucursal *lS){
    nodoSucursal *nf=new nodoSucursal();
    nf=lS->cab;
    while (nf != NULL) {
        guardarDatosEnArchivo(nf->lA,nf->codigo);
        nf=nf->sgte;
    }
}

void cargarAutos(grafoSucursal *lS){
    nodoSucursal *nf=lS->cab;
    while (nf != NULL) {
        cargarDatosDesdeArchivo(nf->lA,nf->codigo);
        nf=nf->sgte;
    }
}

int main() {
    cunya *nuevo= new cunya();
    inicializarCunya(nuevo);
    aniadirSucursales(nuevo->lS);
    cargarAutos(nuevo->lS);

    listaClientes *listaGlobalClientes= new listaClientes();
    int opc=0,opcCli=0,opcSuc=0,opcAut=0,opcVent=0, opcAlq=0;
    do{
        opc=menu();
        switch (opc) {
        case 1:
            //MENU SUCURSALES
            do{
                opcSuc=menuSuc();
                switch (opcSuc) {
                case 1:
                    registrarSucursales(nuevo->lS);
                    break;
                case 2:
                    mostrarSucursales(nuevo->lS);
                    break;
                case 3:
                    buscarSucursales(nuevo->lS);
                    break;
                case 4:
                    registrarConexion(nuevo->lS);
                    break;
                case 5:
                    mostrarConexiones(nuevo->lS);
                    break;
                default:
                    break;
                }
            }while(opcSuc !=0);
            break;
        case 2:
            //MENU CLIENTES
            do{
                opcCli=menuCli();
                switch (opcCli) {
                case 1:
                    RegistrarCliente(nuevo->lS,listaGlobalClientes);
                    break;
                case 2:
                    mostrarColaClientes(nuevo->lS);
                    break;
                case 3:
                    buscarCliente(nuevo->lS);
                    break;
                case 4:
                    mostrarAlfabeticamente(nuevo->lS);
                    break;
                default:
                    break;
                }
            }while(opcCli !=0);
            break;
        case 3:
            //MENU AUTOMOVIL
            do{
                opcAut=menuAut();
                switch (opcAut) {
                case 1:
                    RegistrarAuto(nuevo->lS);
                    break;
                case 2:
                    mostrarAutosDisponibles(nuevo->lS);
                    break;
                case 3:
                    buscarAuto(nuevo->lS);
                    break;
                case 0:
                    guardarEn(nuevo->lS);
                    break;
                default:
                    break;
                }
            }while(opcAut !=0);
            break;
        case 4:
            //MENU VENTA
            do{
                opcVent=menuVent();
                switch (opcVent) {
                case 1:
                    registrarVenta(nuevo->lS);
                    break;
                case 2:
                    mostrarVentas(nuevo->lS);
                    break;
                case 3:
                    buscarVentas(nuevo->lS);
                    break;
                default:
                    break;
                }
            }while (opcVent !=0);
            break;
        case 5:
            //MENU ALQUILER
            do{
                opcAlq=menuAlq();
                switch (opcAlq) {
                case 1:
                    registrarAlquiler(nuevo->lS);
                    break;
                case 2:
                    mostrarAlquileres(nuevo->lS);
                    break;

                default:
                    break;
                }
            }while (opcVent !=0);
            break;
        case 0:
            gotoxy(45,18);cout << "Saliendo del programa. Hasta luego"<< endl;
            system("pause");
            break;
        default:
            gotoxy(45,18);cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opc != 0);
    return 0;
}
