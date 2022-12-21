#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "fecha.h"
#include "cargarCadena.h"

class autos{

private:
    int codigoAuto;///NO DEBE REPETIRSE
    int vendido;
    char marca[20];
    char modelo[20];
    int anio; ///AÑO DEL AUTO
    fecha fechaVenta;
    float precio;
    bool estado;

public:
    void setCodigoAuto(int x){codigoAuto=x;}
    void setVendido(int x) {vendido = x;}
    void setMarca(const char *x){strcpy(marca,x);}
    void setModelo(const char *x){strcpy(modelo,x);}
    void setAnio(int x){anio=x;}
    void setFechaVenta(fecha f){fechaVenta=f;}
    void setPrecio(float x){precio=x;}
    void setEstado(bool x){estado=x;}

    int getCodigoAuto(){return codigoAuto;}
    int getVendido() {return vendido;}
    char *getMarca(){return marca;}
    char *getModelo(){return modelo;}
    int getAnio(){return anio;}
    fecha getFechaVenta(){return fechaVenta;}
    float getPrecio(){return precio;}
    bool getEstado(){return estado;}

    void cargar();
    void mostrar();

    void altaAutos();
    void listarAutos();
    bool eliminarAutos();
    bool eliminarDefAutos();
    void modificarPrecio();
    void modificarCodigo();

    bool evaluarIdVendedor(int x);
    int buscarCodigo(int x);
    void mostrarAutosBorrados();
    bool autoVendido(int m);

    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
};

bool verificarCodigoAuto(int cA)
{
    autos obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getCodigoAuto()==cA)
        {
            return false;
        }
        pos++;
    }
    return true;
}
bool validarAnio(int anio)
{
    if (anio>2022)
    {
        return false;
    }else{return true;}
}
void autos::cargar(){
    vendido = 1;
    int b=0;
    cout<<"Ingrese codigo de auto: "<<endl;
    while(b==0)
    {
    cin>>codigoAuto;
    if(verificarCodigoAuto(codigoAuto))
    {   b=1;

    }else{cout<<"CODIGO DE AUTO INCORRECTO, INGRESE OTRO CODIGO"<<endl;}
    }
    b=0;
    cout<<"Ingrese marca del auto: "<<endl;
    cin>>marca;
    cout<<"Ingrese modelo del auto: "<<endl;
    cin>>modelo;
    cout<<"Ingrese anio en que se creo el auto: "<<endl;
    while(b==0)
    {
    cin >> anio;
    if(validarAnio(anio))
    {
        b=1;
    }else{cout<<"ANIO INCORRECTO INGRESE UN ANIO MENOR O IGUAL AL ACTUAL"<<endl;}
    }
    b=0;
    cout<<"Ingrese fecha de ingreso: "<<endl;
    fechaVenta.Cargar();
    cout<<"Ingrese precio del auto: "<<endl;
    while(b==0)
    {
    cin>>precio;
    if(precio<=0)
    {
        cout<<"INGRESE UN PRECIO VALIDO"<<endl;
    }else{b=1;}
    }
    estado=true;
}


void autos::mostrar(){
    cout<<"Codigo de auto: "<<codigoAuto<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Modelo: "<<modelo<<endl;
    cout<<"Anio del auto: "<<anio << endl;
    cout<<"Fecha de venta: "<<endl;
    fechaVenta.Mostrar();
    cout<<"Precio: "<<precio<<endl;
    cout << "Estado: ";
    if (vendido == 1) {
        cout << "disponible";
    } else {
        cout << "vendido";
        }
    cout << endl;


}


void autos::altaAutos(){
    autos obj;
    FILE *p;
    p = fopen("autos.dat", "ab");
    if (p == NULL) {
        cout << "Erorr al abrir el archivo de autos";
    } else {
        obj.cargar();
        fwrite(&obj, sizeof (autos), 1, p);
        fclose(p);
    }
    fclose(p);
    system("cls");
}


void autos::listarAutos(){
    autos obj;
    int pos=0;
    system("cls");
    while(obj.leerDeDisco(pos++)){
        if(obj.getEstado()==true){
            obj.mostrar();
            cout<<endl;
        }
    }
    system("pause");
    system("cls");
}


bool autos::eliminarAutos(){

    autos obj;
    int m;
    int  pos;
    int x = 0;

    while(obj.leerDeDisco(x) == true) {
        if (obj.getEstado() == true) {
            system("cls");
            cout<<"codigo del auto a eliminar:  ";
            cin>>m;
            pos=buscarCodigo(m);
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


return true;}


bool autos::eliminarDefAutos(){
    autos obj;
    int pos=0;
    FILE *p, *pNuevo;
    system("cls");
    cout<<"Los sieguientes autos seran eliminados de manera definitiva"<<endl;
    mostrarAutosBorrados();
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
               p=fopen("autos.bak","wb");
    if(p==NULL)return false;
    while(obj.leerDeDisco(pos++)){
        fwrite(&obj,sizeof obj,1,p);
    }
    fclose(p);
    pNuevo=fopen("autos.dat","wb");
    if(pNuevo==NULL)return false;

    p=fopen("autos.bak","rb");
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




    ///

return true;}


bool autos::evaluarIdVendedor(int x) {
    int pos = 0;
    int z = 0;
    empleado objEmpleado;
    while(objEmpleado.leerDeDisco(pos) == true){
            if (objEmpleado.getID() == x) {
                z = 1;
            }
            pos++;
        }
        if (z == 1) {
            return true;
        } else {
            return false;
        }
}


int autos::buscarCodigo(int x){
    autos obj;
    int pos=0;
    while(obj.leerDeDisco(pos) == true){
        if(obj.getCodigoAuto()==x && obj.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}


void autos::mostrarAutosBorrados(){
    autos obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if (obj.getEstado()==false){
            cout<<"CODIGO AUTO: "<<obj.getCodigoAuto()<<" ";
        }
    }
}


bool autos::autoVendido(int m){

    autos obj;
    int  pos;
    int x = 0;

    while(obj.leerDeDisco(x) == true) {
            if (obj.getEstado() == true) {
    pos=buscarCodigo(m);
    if(pos==-1){
        cout<<"EL NUMERO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return false;
    }
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL REGISTRO EXISTE PERO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    obj.setVendido(0);
    return obj.modificarEnDisco(pos);
            }
            x++;
    }

return true;}


bool autos::leerDeDisco(int pos){
    FILE *p;
    p=fopen("autos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (autos), 0);
    bool leyo = fread(this, sizeof (autos), 1, p);
    fclose(p);
    return leyo;
}

bool autos::grabarEnDisco(){
    FILE *p;
    p=fopen("autos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (autos), 1, p);
    fclose(p);
    return escribio;
}

bool autos::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("autos.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(autos), 0);
    bool escribio=fwrite(this, sizeof (autos), 1, p);
    fclose(p);
    return escribio;
}

void autos::modificarPrecio()
{
    int pos=0,nuevo_precio=0,codigo;
    autos obj;
    system("cls");
    cout<<"INGRESE EL CODIGO DEL AUTO QUE DESEA CAMBIAR"<<endl;
    cin>>codigo;
    while(obj.leerDeDisco(pos))
    {   if(obj.getCodigoAuto()==codigo && obj.getEstado())
    {
            cout<<"INGRESE EL NUEVO PRECIO: "<<endl;
            cin>>nuevo_precio;
            obj.setPrecio(nuevo_precio);
            obj.modificarEnDisco(pos);
            system("cls");
            return;
    }
        pos++;
    }
    cout<<"NO EXISTE AUTO CON ESE CODIGO"<<endl;
     system("pause");
     system("cls");


}


#endif // AUTOS_H_INCLUDED
