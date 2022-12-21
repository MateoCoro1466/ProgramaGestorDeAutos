#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "fecha.h"
#include "cargarCadena.h"
#include "rlutil.h"
#include <string>

class empleado{
    private:
    int id;
    char nombre[40];
    fecha fecha_inicio;
    int telefono;
    char direccion[40];
    char estudio[40];
    int cargo;
    float sueldo;
    bool estado;

public:
    void setID(int i){id=i;}
    void setNombre(const char *N){strcpy(nombre,N);}
    void setFecha_Inicio(fecha f){fecha_inicio=f;}
    void setTelefono(int t){telefono=t;}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setEstudio(const char *d){strcpy(estudio,d);}
    void setSueldo(float s){sueldo=s;}
    void setCargo(int e){cargo=e;}
    void setEstado(bool e){estado=e;}

    int getID(){return id;}
    int getCargo(){return cargo;}
    const char *getNombre(){return nombre;}
    fecha getFecha_inicio(){return fecha_inicio;}
    int getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    const char *getEstudio(){return estudio;}
    float getSueldo(){return sueldo;}
    bool getEstado(){return estado;}

    void cargar();
    void mostrar();

    void altaEmpleado();
    void listarEmpleado();
    bool eliminarEmpleado();
    bool eliminarDefEmpleado();
    void modificarSueldo();
    void modificarCargo();

    void actualizarIDNuevo();
    int buscarID(int x);
    void mostrarEmpleadosBorrados();

    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
};
bool validarTelefonoEmpleado(int t)
{
    int pos=0;
    empleado obj;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getTelefono()==t)
        {
            return false;
        }
        pos++;
    }
    return true;
}

void empleado::cargar(){
    bool z = false;
    int i=0;
    system("cls");
    cout<<"Ingrese el nombre del empleado: "<<endl;
    cargarCadena(nombre,39);
    z = cadenaComparativa(nombre);
    while(z == false) {
        cout << "Nombre vacio o mal cargado"; cout << endl;
        cout << "Por favor, ingrese nuevamente el nombre completo" << endl;
        cargarCadena(nombre, 39);
        z = cadenaComparativa(nombre);
    }
    z = false;
    cout<<"Ingrese la fecha de inicio: "<<endl;
    fecha_inicio.Cargar();
    cout<<"Ingrese el telefono: "<<endl;
    while(i==0)
    {
    cin>>telefono;
    if(validarTelefonoEmpleado(telefono))
    {
        i=1;
    }else{cout<<"INGRESE UN TELEFONO VALIDO"<<endl;}
    }
    i=0;
    cout<<"Ingrese estudio: "<<endl;
    cargarCadena(estudio,39);
    cout<<"Ingrese la direccion: "<<endl;
    cargarCadena(direccion,39);
    cout<<"Ingrese el sueldo: "<<endl;
    while(i==0)
    {

    cin>>sueldo;
    if(sueldo<=0)
    {
        cout<<"INGRESE UN SUELDO VALIDO"<<endl;
    }else{i=1;}
    }
    cout << "Ingrese el cargo: " << endl;
    cout << "(1: empleado, 2: vendedor, 3: gerente)" << endl;
    cin >> cargo;
    if (cargo == 1 || cargo == 2 || cargo == 3) {
        z = true;
     }
    while (z == false) {
        cout << "Ingrese un numero entre 1 y 3" << endl;
        cout << "(1: empleado, 2: vendedor, 3: gerente)" << endl;
        cin >> cargo;
        if (cargo == 1 || cargo == 2 || cargo == 3) {
            z = true;
        }
     }
    estado=true;
    system("pause");
    system("cls");
}


void empleado::mostrar(){

    cout<<"ID:"<<id<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"FECHA DE INICIO: "<<endl;
    fecha_inicio.Mostrar();
    cout<<"TELEFONO: "<<telefono<<endl;
    cout<<"ESTUDIO: "<<estudio<< endl;
    cout<<"DIRECCION: "<<direccion<<endl;
    cout<<"SUELDO: "<<sueldo<<endl;
    cout<<"CARGO: "<<cargo<< endl;
}


void empleado::altaEmpleado(){
    FILE *p;
    p = fopen("personal.dat", "ab");
    empleado obj;
    if (p == NULL) {
        cout << "Error al abrir el archivo de empleado";
    } else {
        obj.cargar();
        fwrite(&obj, sizeof (empleado), 1, p);
        fclose(p);
    }
    fclose(p);
}


void empleado::listarEmpleado(){
    empleado obj;
    int pos = 0;
    system("cls");
    while (obj.leerDeDisco(pos++) == true) {
            if(obj.getEstado()==true){

        obj.mostrar();
        cout << endl;
            }

    }
system("pause");
system("cls");
}


bool empleado::eliminarEmpleado(){

    empleado obj;
    int ID, pos;
    int x = 0;

    while(obj.leerDeDisco(x) == true) {
            if (obj.getEstado() == true) {
                    system("cls");
    cout<<"ID del empleado a eliminar:  ";
    cin>>ID;
    pos=buscarID(ID);
    if(pos==-1){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        system("pause");
        system("cls");

        return false;
    }
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
        system("pause");
        system("cls");

        return false;
    }
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL REGISTRO EXISTE PERO YA ESTA DADO DE BAJA"<<endl;
        system("pause");
        system("cls");

        return false;
    }

    system("pause");
    system("cls");
    obj.setEstado(false);
    return obj.modificarEnDisco(pos);

            }
            x++;
    }

return true;
}


bool empleado::eliminarDefEmpleado(){
    empleado obj;
    int pos=0;
    FILE *p, *pNuevo;

    system("cls");
    cout<<"Los sieguientes empleados seran eliminados de manera definitiva"<<endl;
    mostrarEmpleadosBorrados();
    cout<<"Desea continuar? (S/N): "<<endl;

    ///
     int y=0,x=1;


    rlutil::hidecursor();
    do {    rlutil::hidecursor();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(1,1);

    rlutil::locate(3/*columnas */,5/*filas*/);
    cout<<"------------------------------"<<endl;
    rlutil::locate(3/*columnas */,6/*filas*/);
    cout << "SI"<<endl;
    rlutil::locate(3/*columnas */,7/*filas*/);
    cout << "NO"<<endl;
    rlutil::locate(3/*columnas */,8/*filas*/);
    cout<<"------------------------------"<<endl;

    rlutil::locate(1,6+y);
    cout<<(char)175<<endl;

    switch (rlutil::getkey())
    {
        case 14:
            rlutil::locate(1,6+y);
            cout<<" "<<endl;
            y--;
            if (y<0)
            {
                y=0;
            }

        break;
        case 15:
             rlutil::locate(1,6+y);
            cout<<" "<<endl;
            y++;
            if (y>1)
            {
                y=1;
            }

        break;
       case 1:
            switch (y)
            ///opciones
            {


            case 0:
                system("cls");
    p=fopen("personal.bak","wb");
    if(p==NULL)return false;
    while(obj.leerDeDisco(pos++)){
        fwrite(&obj,sizeof obj,1,p);
    }
    fclose(p);
    pNuevo=fopen("personal.dat","wb");
    if(pNuevo==NULL)return false;

    p=fopen("personal.bak","rb");
    if(p==NULL){fclose (pNuevo); return false;}

    while (fread(&obj,sizeof obj,1,p)==1){
        if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,pNuevo);
        }
    }
    cout<<"Borrado correctamente"<<endl;
    system("pause");
    system("cls");
    fclose(p);
    fclose(pNuevo);
    return true;
            x=0;
            case 1:
                system("cls");
               return false;

                x=0;
                break;

    }

    }

    }while(x !=0 );

system("cls");





return true;}


void empleado::actualizarIDNuevo() {
    FILE *p;
    p = fopen("personal.dat", "rb+");
    empleado obj;
    int pos=0;
    int x = 1;
    while(obj.leerDeDisco(pos) == true){
        if(obj.getEstado() == true) {
            obj.setID(x);
            obj.modificarEnDisco(pos);
            x++;
        }
      pos++;
    }
    fclose(p);
}


int empleado::buscarID(int x){
    empleado obj;
    int pos=0;
    while(obj.leerDeDisco(pos) == true){
        if(obj.getID()==x && obj.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}


void empleado::mostrarEmpleadosBorrados(){
    empleado obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if (obj.getEstado()==false){
            cout<<obj.getID()<<" ";
            cout<<obj.getNombre()<<" ";
        }
    }
}


bool empleado::leerDeDisco(int pos){
    FILE *p;
    p=fopen("personal.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (empleado), 0);
    bool leyo = fread(this, sizeof (empleado), 1, p);
    fclose(p);
    return leyo;
}


bool empleado::grabarEnDisco(){
    FILE *p;
    p=fopen("personal.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (empleado), 1, p);
    fclose(p);
    return escribio;
}


bool empleado::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("personal.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(empleado), 0);
    bool escribio=fwrite(this, sizeof (empleado), 1, p);
    fclose(p);
    return escribio;
}
void empleado::modificarSueldo()
{
    int pos=0,idAcambiar,z=0;
    float nuevo_sueldo;
    empleado obj;
    system("cls");
    cout<<"INGRESE EL ID DEL EMPLADO A CAMBIAR: "<<endl;
    cin>>idAcambiar;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getID()==idAcambiar && obj.getEstado())
        {
            cout<<"INGRESE EL NUEVO SUELDO: "<<endl;
            while(z==0)
            {
            cin>>nuevo_sueldo;
            if(nuevo_sueldo<=0)
            {
                cout<<"INGRESE UN SUELDO VALIDO"<<endl;
            }else{z=1;}
            }
            obj.setSueldo(nuevo_sueldo);
            obj.modificarEnDisco(pos);
            system("cls");
            return;
        }
        pos++;
    }
    cout<<"NO EXISTE ESE EMPLEADO"<<endl;
    system("pause");
    system("cls");

}
void empleado::modificarCargo()
{
    int pos=0,idAcambiar,z=0;
    int nuevo_cargo;
    empleado obj;
    system("cls");
    cout<<"INGRESE EL ID DEL EMPLADO A CAMBIAR: "<<endl;
    cin>>idAcambiar;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getID()==idAcambiar && obj.getEstado())
        {
            cout<<"INGRESE EL NUEVO CARGO: "<<endl;
            while(z==0)
            {

            cin>>nuevo_cargo;
            if(nuevo_cargo<1 || nuevo_cargo>3)
            {
                cout<<"INGRESE UN CARGO ENTRE 1 Y 3"<<endl;
            }else{z=1;}
            }
            obj.setCargo(nuevo_cargo);
            obj.modificarEnDisco(pos);
            system("cls");
            return;
        }
        pos++;
    }
    cout<<"NO EXISTE ESE EMPLEADO"<<endl;
    system("pause");
    system("cls");

}



#endif // EMPLEADO_H_INCLUDED
