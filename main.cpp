# include<iostream>
# include<cstdlib>
#include<cstring>
#include <cstdio>
#include <ctime>

using namespace std;
#include "fecha.h"
#include "empleado.h"
#include "clientes.h"
#include "ventas.h"
#include "autos.h"
#include "configuracion.h"
#include "menu.h"
#include "Reportes.h"



int main()
{
    int y=0,x=1;
    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(35/*columnas */,9/*filas*/);
    cout<<"MENU PRINCIPAL"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "MENU EMPLEADOS"<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "MENU CLIENTES"<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "AUTOS"<<endl;
    rlutil::locate(30/*columnas */,16/*filas*/);
    cout<< "VENTAS"<<endl;
    rlutil::locate(30/*columnas */,17/*filas*/);
     cout<< "CONFIGURACION"<<endl;
     rlutil::locate(30/*columnas */,18/*filas*/);
     cout<< "REPORTES"<<endl;
    rlutil::locate(30/*columnas */,19/*filas*/);
    cout << "SALIR"<<endl;
    rlutil::locate(28,13+y);

    cout<<(char)175<<endl;

    switch (rlutil::getkey())
    {
        case 14:
            rlutil::locate(28,13+y);
            cout<<" "<<endl;
            y--;
            if (y<0)
            {
                y=0;
            }

        break;
        case 15:
             rlutil::locate(28,13+y);
            cout<<" "<<endl;
            y++;
            if (y>6)
            {
                y=6;
            }

        break;
       case 1:
            switch (y)
            ///opciones
            {

            case 0:
                menuEmpleados();
                system("cls");
                break;

            case 1:
                menuClientes();
                system("cls");
                break;

            case 2:
                menuAutos();
                system("cls");
                break;

            case 3:
                menuVentas();
                system("cls");
                break;
            case 4:
                menuConf();
                system("cls");
                break;
            case 5:
                menuReportes();
                system("cls");

                break;
            case 6:
                system("cls");
                return 0;
                x=0;

                break;

    }

    }

    }while(x !=0 );

system("cls");

}

