#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "fecha.h"
#include "autos.h"
#include "clientes.h"


class ventas{
private:
    int numVenta;
    int codigoAuto;
    int idVendedor;
    int dniCliente;
    bool estado;

public:
    void setNumVenta(int x) {numVenta = x;}
    void setCodigoAuto(int x) {codigoAuto = x;}
    void setIdVendedor(int x) {idVendedor = x;}
    void setDniCliente(int x) {dniCliente = x;}
    void setEstado(bool e){estado=e;}

    int getNumVenta() {return numVenta;}
    int getCodigoAuto() {return codigoAuto;}
    int getIdVendedor() {return idVendedor;}
    int getDniCliente() {return dniCliente;}
    bool getEstado(){return estado;}

    void cargar();
    void mostrar();

    void altaVentas();
    void listarVentas();

    bool evaluarCodigoAuto(int x);
    bool evaluarIdVendedor(int x);
    bool evaluarDNICLiente(int x);
    void modificarCodigoAuto();
    void modificarNumeroVenta();

    bool leerDeDisco(int pos);
    bool leerDeDiscoDos(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
};
bool validarNumVenta(int nV)
{
    ventas obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getNumVenta()==nV)
        {
            return false;
        }
        pos++;
    }
    return true;

}

void ventas::cargar(){
    bool z = false;
    int i=0;
    cout<<"Ingrese el numero de venta: "<<endl;
    while (i==0)
    {
    cin>>numVenta;
    if(validarNumVenta(numVenta))
    {
        i=1;
    }else{cout<<"INGRESE UN NUMERO DE VENTA VALIDO"<<endl;}
    }
    cout<<"Ingrese el codigo del auto: "<<endl;
    cin>>codigoAuto;
    z = evaluarCodigoAuto(codigoAuto);
    while (z != true) {
        cout << "Codigo de auto inexistente o auto ya vendido" << endl;
        cout<<"Ingrese el codigo del auto: "<<endl;
        cin>>codigoAuto;
        z = evaluarCodigoAuto(codigoAuto);
    }
    z = false;
    cout<<"Ingrese ID del vendedor: "<<endl;
    cin>>idVendedor;
    z = evaluarIdVendedor(idVendedor);
    while (z == false) {
        cout << "Id inexistente" << endl;
        cout<<"Ingrese ID del vendedor: "<<endl;
        cin>>idVendedor;
        z = evaluarIdVendedor(idVendedor);
    }
    z = false;
    cout<<"Ingrese dni cliente: "<<endl;
    cin>>dniCliente;
    z = evaluarDNICLiente(dniCliente);
    while (z == false) {
        cout << "DNI inexistente" << endl;
        cout<<"Ingrese DNI del cliente: "<<endl;
        cin>>dniCliente;
        z = evaluarDNICLiente(dniCliente);
    }
    estado=true;
}


void ventas::mostrar(){
    cout<<"NUMERO VENTA: "<<numVenta<<endl;
    cout<<"CODIGO DEL AUTO: "<<codigoAuto<<endl;
    cout<<"ID DEL VENDEDOR: "<<idVendedor<<endl;
    cout<<"DNI CLIENTE: "<<dniCliente<<endl;


}


 void ventas::altaVentas(){
    FILE *p;

    p = fopen("ventas.dat", "ab");

    ventas obj;
    if (p == NULL ) {
        cout << "Erorr al abrir el archivo de ventas";
    } else {
        system("cls");
        obj.cargar();
        fwrite(&obj, sizeof (ventas), 1, p);
        fclose(p);

    }
    fclose(p);
    ;
    system("cls");
}


void ventas::listarVentas(){
    ventas obj;
    int pos=0;
    system("cls");
    while(obj.leerDeDisco(pos)){
        obj.mostrar();
        cout<<endl;
        pos++;
    }
    system("pause");
    system("cls");
}


 bool ventas::evaluarCodigoAuto(int x) {
    int pos = 0;
    int z = 0;
    autos objAuto;
    while(objAuto.leerDeDisco(pos++) == true){
        if (objAuto.getCodigoAuto() == x && objAuto.getVendido() == 1) {
            z = 1;
            objAuto.autoVendido(x);
        }
    }
    if (z == 1) {
        return true;
    } else {
        return false;
    }
}


bool ventas::evaluarIdVendedor(int x) {
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


bool ventas::evaluarDNICLiente(int x) {
    int pos = 0;
    int z = 0;
    clientes objCliente;
    while(objCliente.leerDeDisco(pos) == true){
        if (objCliente.getDNI() == x) {
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


bool ventas::leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (ventas), 0);
    bool leyo = fread(this, sizeof (ventas), 1, p);
    fclose(p);
    return leyo;
}


bool ventas::leerDeDiscoDos(int pos){
    FILE *x;
    x=fopen("ventas.bkp","rb");
    if(x==NULL) return false;
    fseek(x, pos * sizeof (ventas), 0);
    bool leyo = fread(this, sizeof (ventas), 1, x);
    fclose(x);
    return leyo;
}


bool ventas::grabarEnDisco(){
    FILE *p;
    p=fopen("ventas.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (ventas), 1, p);
    fclose(p);
    return escribio;
}


bool ventas::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(ventas), 0);
    bool escribio=fwrite(this, sizeof (ventas), 1, p);
    fclose(p);
    return escribio;
}
bool validarCodigo(int cA)
{
    autos obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getCodigoAuto()==cA)
        {
            return true;
        }

    }
    return false;
}


    void ventas::modificarCodigoAuto()
{
    int pos=0,nuevo_codigo=0,codigo,z=0;
    ventas obj;
    system("cls");
    cout<<"INGRESE EL CODIGO DE LA VENTA QUE DESEA MODIFICAR"<<endl;
    cin>>codigo;
    while(obj.leerDeDisco(pos))
    {   if(obj.getNumVenta()==codigo&& obj.getEstado())
    {   cout<<"INGRESE EL NUEVO CODIGO DEL AUTO : "<<endl;
        while(z==0)
            {

            cin>>nuevo_codigo;
            if(validarCodigo(nuevo_codigo))
            {
                z=1;
            }else{cout<<"INGRESE UN CODIGO DE AUTO VALIDO"<<endl;}
            }
            obj.setCodigoAuto(nuevo_codigo);
            obj.modificarEnDisco(pos);
            system("cls");
            return;
    }
        pos++;
    }
    cout<<"NO EXISTE VENTA CON ESE CODIGO"<<endl;
     system("pause");
     system("cls");


}

#endif // VENTAS_H_INCLUDED
