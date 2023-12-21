#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;

void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}

string generarCodigo(string dat,int num){
     string val;
     stringstream ss;
     ss << num;
     val=dat + ss.str();
     return val;
}

unsigned short menuCli(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "MENU DE OPCIONES" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. REGISTRAR CLIENTE" << endl;
         gotoxy(45, 10);cout << "2. MOSTRAR CLIENTES" << endl;
         gotoxy(45, 11);cout << "3. BUSCAR CLIENTE" << endl;
         gotoxy(45, 12);cout << "4. MOSTRAR ALFABETICAMENTE" << endl;
         gotoxy(45, 13);cout << "0. VOLVER" << endl;
         gotoxy(45, 21);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 5 ));
     return opc;
}

unsigned short menuSuc(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "MENU DE OPCIONES" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. REGISTRAR SUCURSALES" << endl;
         gotoxy(45, 10);cout << "2. LISTAR SUCURSALES" << endl;
         gotoxy(45, 11);cout << "3. BUSCAR SUCURSALES" << endl;
         gotoxy(45, 12);cout << "4. AÑADIR CONEXION" << endl;
         gotoxy(45, 13);cout << "5. MOSTRAR CONEXIONES" << endl;
         gotoxy(45, 14);cout << "0. VOLVER" << endl;
         gotoxy(45, 15);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 6 ));
     return opc;
}

unsigned short menuAut(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "MENU DE OPCIONES" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. REGISTRAR AUTOMOVIL" << endl;
         gotoxy(45, 10);cout << "2. MOSTRAR AUTOMOVIL" << endl;
         gotoxy(45, 11);cout << "3. BUSCAR AUTOMOVIL" << endl;
         gotoxy(45, 12);cout << "0. VOLVER" << endl;
         gotoxy(45, 13);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 4 ));
     return opc;
}

unsigned short menuVenBuscarPor(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "SELCCIONE" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. CODIGO" << endl;
         gotoxy(45, 10);cout << "2. CODIGO CLIENTE" << endl;
         gotoxy(45, 11);cout << "3. CODIGO AUTOMOVIL" << endl;
         gotoxy(45, 12);cout << "4. NOMBRE" << endl;
         gotoxy(45, 13);cout << "5. MARCA" << endl;
         gotoxy(45, 14);cout << "0. VOLVER" << endl;
         gotoxy(45, 15);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 6));
     return opc;
}

unsigned short menuAutBuscarPor(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "SELCCIONE" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. CODIGO" << endl;
         gotoxy(45, 10);cout << "2. MODELO" << endl;
         gotoxy(45, 11);cout << "3. MARCA" << endl;
         gotoxy(45, 12);cout << "0. VOLVER" << endl;
         gotoxy(45, 13);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 4));
     return opc;
}

unsigned short menuBuscarPor(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "SELCCIONE" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. DNI" << endl;
         gotoxy(45, 10);cout << "2. NOMBRE" << endl;
         gotoxy(45, 11);cout << "0. VOLVER" << endl;
         gotoxy(45, 12);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 3));
     return opc;
}

unsigned short menuVent(){
     unsigned short opc;
     do {
         system("cls");
         gotoxy(45, 7); cout << "MENU DE OPCIONES" << endl;
         gotoxy(45, 8); cout << "================" << endl;
         gotoxy(45, 9); cout << "1. ATENDER CLIENTE" << endl;
         gotoxy(45, 10);cout << "2. MOSTRAR VENTAS" << endl;
         gotoxy(45, 11);cout << "3. BUSCAR VENTAS" << endl;
         gotoxy(45, 12);cout << "0. VOLVER" << endl;
         gotoxy(45, 13);cout << "Elija una opcion: ";
         cin >> opc;
     }while(!( opc >= 0 && opc < 4));
     return opc;
}
int menuAlq() {
    int opcion;
    system("cls");
    gotoxy(45, 7);cout << "MENU DE ALQUILERES" << endl;
    gotoxy(45, 8);cout << "1. REGISTRAR ALQUILER" << endl;
    gotoxy(45, 9);cout << "2. MOSTRAR ALQUILERES" << endl;
    gotoxy(45, 10);cout << "0. VOLVER" << endl;
    gotoxy(45, 11);cout << "Ingrese su opcion: ";
    cin >> opcion;
    return opcion;
}
unsigned short menu(){
    unsigned short opc;
    do {
        system("cls");
        gotoxy(45, 7); cout << "MENU DE OPCIONES" << endl;
        gotoxy(45, 8); cout << "================" << endl;
        gotoxy(45, 9); cout << "1. SUCURSALES" << endl;
        gotoxy(45, 10);cout << "2. CLIENTES" << endl;
        gotoxy(45, 11);cout << "3. AUTOMOVILES" << endl;
        gotoxy(45, 12);cout << "4. VENTA" << endl;
        gotoxy(45, 13);cout << "5. ALQUILER" << endl;
        gotoxy(45, 14);cout << "0. Salir" << endl;
        gotoxy(45, 15);cout << "Elija una opcion: ";
        cin >> opc;
    }while(!( opc >= 0 && opc < 6 ));
    return opc;
}


string leerTexto(string mensaje,int x,int y){
    string valor;
    do{
        gotoxy(x,y);cout << mensaje;
        fflush( stdin );
        getline(cin, valor);
    }while(!(valor.length()>0));
    return valor;
}

unsigned short leerEnteroCorto( string mensaje ){
    unsigned short valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor < 100));
    return valor;
}
int leerEntero(string msm){
    int dato;
    do{
        cout<<msm;
        cin>>dato;
    }while(dato<0);

    return dato;
}

double leerDouble(string msm) {
    double dato;
    do {
        cout << msm;
        cin >> dato;
    } while (dato < 0);

    return dato;
}
bool leerEstado(string mensaje){
    string valor;
    do{
        cout << mensaje;
        cin >> valor;
    }while(!( valor == "SI" || valor == "NO" ));
    if ( valor == "SI")
        return true;
    else
        return false;
}
