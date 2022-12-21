#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "rlutil.h"
#include "Reportes.h"
int menuClientes() {
     int y=0,x=1;
     clientes obj;
    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(35/*columnas */,9/*filas*/);
    cout<<"MENU CLIENTES"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "ALTA DE CLIENTE"<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "LISTADO DE CLIENTES"<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "BAJA DE CLIENTES"<<endl;
    rlutil::locate(30/*columnas */,16/*filas*/);
    cout<< "ELIMINAR CLIENTES BORRADOS"<<endl;
     rlutil::locate(30/*columnas */,17/*filas*/);
    cout<< "MODIFICAR TELEFONO DEL CLIENTE"<<endl;
    rlutil::locate(30/*columnas */,18/*filas*/);
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
            if (y>5)
            {
                y=5;
            }

        break;
       case 1:
            switch (y)
            ///opciones
            {

            case 0:
               obj.altaClientes();

            break;

            case 1:
                system("cls");
                obj.listarClientes();


                break;

            case 2:
                 obj.eliminarClientes();
                break;

            case 3:
                obj.eliminarDefClientes();
                break;
            case 4:
           obj.modificarTELEFONO();

                break;
            case 5:
                return -1;

                break;

    }

    }

    }while(x !=0 );

system("cls");
return true;
}


int menuAutos() {


    int y=0,x=1;
     autos obj;
    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(35/*columnas */,9/*filas*/);
    cout<<"MENU AUTOS"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "ALTA DE AUTOS"<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "LISTADO DE AUTOS"<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "BAJA DE AUTOS"<<endl;
    rlutil::locate(30/*columnas */,16/*filas*/);
    cout<< "ELIMINAR AUTOS BORRADOS"<<endl;
    rlutil::locate(30/*columnas */,17/*filas*/);
    cout<< "MODIFICAR PRECIO AUTO"<<endl;

    rlutil::locate(30/*columnas */,18/*filas*/);
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
            if (y>5)
            {
                y=5;
            }

        break;
       case 1:
            switch (y)
            ///opciones
            {

            case 0:
               system("cls");
               obj.altaAutos();
               system("cls");

            break;

            case 1:

                obj.listarAutos();
                system("cls");
                break;

            case 2:
                 obj.eliminarAutos();
                break;

            case 3:
                obj.eliminarDefAutos();
                break;
            case 4:
                obj.modificarPrecio();
                break;
            case 5:
                return -1;

                break;



    }

    }

    }while(x !=0 );

system("cls");
return true;
}


int menuEmpleados() {
    int y=0,x=1;
     empleado obj;
    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(35/*columnas */,9/*filas*/);
    cout<<"MENU EMPLEADOS"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "ALTA DE EMPLEADO"<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "LISTADO DE EMPLEADOS"<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "BAJA DE EMPLEADO"<<endl;
    rlutil::locate(30/*columnas */,16/*filas*/);
    cout<< "ELIMINAR EMPLEADOS BORRADOS"<<endl;
    rlutil::locate(30/*columnas */,17/*filas*/);
    cout<< "MODIFICAR SUELDO DE UN EMPLEADO"<<endl;
    rlutil::locate(30/*columnas */,18/*filas*/);
    cout<< "MODIFICAR CARGO DE UN EMPLEADO"<<endl;
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
               obj.altaEmpleado();
               obj.actualizarIDNuevo();
                break;

            case 1:
                obj.listarEmpleado();
                system("cls");
                break;

            case 2:
                 obj.eliminarEmpleado();
                obj.actualizarIDNuevo();
                break;

            case 3:
                obj.eliminarDefEmpleado();
                break;
            case 4:
                obj.modificarSueldo();

            break;
            case 5:
                obj.modificarCargo();
                break;


            case 6:
                return -1;
                x=0;
                break;

    }

    }

    }while(x !=0 );

system("cls");
return true;
}


int menuVentas() {

ventas obj;
 int y=0,x=1;

    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(30/*columnas */,9/*filas*/);
    cout<<"MENU VENTAS"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "ALTA DE VENTAS"<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "LISTAR VENTAS"<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "MODIFICAR CODIGO DE UN AUTO"<<endl;

    rlutil::locate(30/*columnas */,16/*filas*/);
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
            if (y>3)
            {
                y=3;
            }

        break;
       case 1:
            switch (y)
            ///opciones
            {

            case 0:
                obj.altaVentas();
                break;

            case 1:
                obj.listarVentas();
                system("cls");
                break;
            case 2:
                obj.modificarCodigoAuto();

                break;
            case 3:
               return -1;

                break;





    }

    }

    }while(x !=0 );

system("cls");
return true;
}


int menuConf() {


 int y=0,x=1;

    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(35/*columnas */,9/*filas*/);
    cout<<"MENU CONFIGURACION"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "COPIA DE SEGRIDAD DEL ARICHIVO CLIENTES "<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "COPIA DE SEGRIDAD DEL ARICHIVO EMPLEADOS "<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "COPIA DE SEGRIDAD DEL ARICHIVO AUTOS "<<endl;
    rlutil::locate(30/*columnas */,16/*filas*/);
    cout<< "COPIA DE SEGRIDAD DEL ARICHIVO VENTAS "<<endl;
    rlutil::locate(30/*columnas */,17/*filas*/);
    cout<< "RESTAURAR EL ARCHIVO DE CLIENTES"<<endl;
    rlutil::locate(30/*columnas */,18/*filas*/);
    cout<< "RESTAURAR EL ARCHIVO DE EMPLEADOS "<<endl;
    rlutil::locate(30/*columnas */,19/*filas*/);
    cout<< "RESTAURAR EL ARCHIVO DE AUTOS "<<endl;
    rlutil::locate(30/*columnas */,20/*filas*/);
    cout<< "RESTAURAR EL ARCHIVO DE VENTAS"<<endl;
    rlutil::locate(30/*columnas */,21/*filas*/);
    cout<< "RESTAURAR DATOS DE INICIO"<<endl;
    rlutil::locate(30/*columnas */,22/*filas*/);
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
            if (y>9)
            {
                y=9;
            }

        break;
       case 1:
            switch (y)
            ///opciones
            {

            case 0:
                system("cls");
            if(copiaSeguridadClientes())
            {
                cout<<"COPIA DE SEGURIDAD CREADA CORRECTAMENTE"<<endl;
            }else{cout<<"ERROR EN LA CREACION DE LA COPIA DE SEGURIDAD "<<endl;}
            system("pause");
            system("cls");
                break;

            case 1:
                system("cls");
            if(copiaSeguridadEmpleado())
            {
                cout<<"COPIA DE SEGURIDAD CREADA CORRECTAMENTE"<<endl;
            }else{cout<<"ERROR EN LA CREACION DE LA COPIA DE SEGURIDAD "<<endl;}
            system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                if(copiaSeguridadAutos())
            {
                cout<<"COPIA DE SEGURIDAD CREADA CORRECTAMENTE"<<endl;
            }else{cout<<"ERROR EN LA CREACION DE LA COPIA DE SEGURIDAD "<<endl;}
            system("pause");
            system("cls");

                break;
            case 3:
                system("cls");
               if(copiaSeguridadVentas())
            {
                cout<<"COPIA DE SEGURIDAD CREADA CORRECTAMENTE"<<endl;
            }else{cout<<"ERROR EN LA CREACION DE LA COPIA DE SEGURIDAD "<<endl;}
            system("pause");
            system("cls");
            break;
            case 4:
                 system("cls");
               if(restaurarClientes())
            {
                cout<<"RESTAURACION COMPLETADA"<<endl;
            }else{cout<<"ERROR EN LA RESTAURACION "<<endl;}
            system("pause");
            system("cls");
                break;
            case 5:
                system("cls");
               if(restaurarEmpleado())
            {
                cout<<"RESTAURACION COMPLETADA"<<endl;
            }else{cout<<"ERROR EN LA RESTAURACION "<<endl;}
            system("pause");
            system("cls");
                break;
            case 6:
                 system("cls");
               if(restaurarAutos())
            {
                cout<<"RESTAURACION COMPLETADA"<<endl;
            }else{cout<<"ERROR EN LA RESTAURACION "<<endl;}
            system("pause");
            system("cls");
                break;
            case 7:
                 system("cls");
               if(restaurarVentas())
            {
                cout<<"RESTAURACION COMPLETADA"<<endl;
            }else{cout<<"ERROR EN LA RESTAURACION "<<endl;}
            system("pause");
            system("cls");
                break;
            case 8:
                 system("cls");
               if(restaurarDatosInicio())
            {
                cout<<"RESTAURACION COMPLETADA"<<endl;
            }else{cout<<"ERROR EN LA RESTAURACION "<<endl;}
            system("pause");
            system("cls");

                break;

            case 9:
               return -1;
                break;



    }

    }

    }while(x !=0 );

system("cls");
return true;
}
int menuReportes() {


 int y=0,x=1;

    rlutil::cls();
    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);
    rlutil::locate(35/*columnas */,9/*filas*/);
    cout<<"MENU REPORTES"<<endl;
    rlutil::locate(30/*columnas */,10/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,11/*filas*/);
    cout << "INGRESE UNA OPCION"<<endl;
    rlutil::locate(30/*columnas */,12/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(30/*columnas */,13/*filas*/);
    cout<< "EMPELADO CON MAYOR SUELDO "<<endl;
    rlutil::locate(30/*columnas */,14/*filas*/);
    cout<< "AUTO MAS CARO "<<endl;
    rlutil::locate(30/*columnas */,15/*filas*/);
    cout<< "EMPLEADO CON MENOR SUELDO"<<endl;
    rlutil::locate(30/*columnas */,16/*filas*/);
    cout<< "AUTOS MODELO 2018-2022"<<endl;
    rlutil::locate(30/*columnas */,17/*filas*/);
    cout<< "AUTO MAS BARATO"<<endl;
    rlutil::locate(30/*columnas */,18/*filas*/);
    cout<< "EMPLEADO INGRESADO EN 2021 "<<endl;
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
                system("cls");
                empeladoMAyorSueldo();
                system("pause");
                system("cls");
                break;

            case 1:
                system("cls");
                AutoMasCaro();
                system("pause");
                system("cls");

                break;
            case 2:
                system("cls");
                empleadoMinimoSueldo();
                system("pause");
                system("cls");

                break;
            case 3:
                system("cls");
                AutoUltimos5Anios();
                system("pause");
                system("cls");

            break;
            case 4:
                 system("cls");
                autoMasBarato();
                system("pause");
                system("cls");

                break;
            case 5:
                system("cls");
                empleadoIngresadoEn2021();
                system("pause");
                system("cls");

                break;

            case 6:
               return -1;
                break;



    }

    }

    }while(x !=0 );

system("cls");
return true;
}
#endif // MENU_H_INCLUDED
