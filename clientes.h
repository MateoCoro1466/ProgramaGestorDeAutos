#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class clientes {
private:
    int dni;
    char nombre[30];
    char domicilio[40];
    int telefono;
    char email[40];
    bool estado;


public:
    void setDNI(int x) {dni = x;}
    void setNombre(const char *x) {strcpy(nombre, x);}
    void setDomicilio(const char *x) {strcpy(domicilio, x);}
    void setTelefono(int t){telefono=t;}
    void setEmail(const char *x) {strcpy(email, x);}
    void setEstado(bool x) {estado = x;}

    int getDNI() {return dni;}
    char *getNombre() {return nombre;}
    char *getDomicilio() {return domicilio;}
    int getTelefono() {return telefono;}
    char *getEmail() {return email;}
    bool getEstado() {return estado;}

    void cargar();
    void mostrar();

    void altaClientes();
    void listarClientes();
    bool eliminarClientes();
    bool eliminarDefClientes();
    void modificarDNI();
    void modificarTELEFONO();

    int buscarDNI(int x);
    void mostrarClientesBorrados();

    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
};
bool validarDNI(int dni)
{
    clientes obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
    {
        if(obj.getDNI()==dni)
        {
            return false;
        }
        pos++;
    }
    return true;

}
bool validarTelefono(int t)
{
    int pos=0;
    clientes obj;
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
bool validarEMAIL(const char *email)
{
    clientes obj;
    int pos=0;
    while(obj.leerDeDisco(pos))
    {
        if(strcmp(obj.getEmail(),email)==0)
        {
            return false;
        }
        pos++;
    }
    return true;
}

void clientes::cargar() {
    system("cls");
    int z=0;
    bool x = false;
    cout << "Ingrese DNI: " << endl;
    while(z==0)
    {
    cin >> dni;
    if(validarDNI(dni))
    {
        z=1;
    }else{cout<<"DNI YA EXISTENTE, INGRESE UNO VALIDO"<<endl;}
    }
    z=0;
    cout << "Ingrese nombre: " << endl;
    cargarCadena(nombre, 29);
    x = cadenaComparativa(nombre);
    while(x == false) {
        cout << "Nombre vacio o mal cargado"; cout << endl;
        cout << "Por favor, ingrese nuevamente el nombre completo: " << endl;
        cargarCadena(nombre, 29);
        x = cadenaComparativa(nombre);
    }
    x = false;

    cout << "Ingrese domicilio: " << endl;
    cargarCadena(domicilio, 40);
    x = cadenaComparativa(domicilio);
    while( x == false) {
        cout << "Nombre vacio o mal cargado"; cout << endl;
        cout << "Por favor, ingrese nuevamente el domicilio completo: " << endl;
        cargarCadena(domicilio, 39);
        x = cadenaComparativa(domicilio);
    }
    cout<<"Ingrese el telefono: "<<endl;
    cin>>telefono;
    cout<<"Ingrese el e-mail: "<<endl;
    while(z==0)
    {
    cargarCadena(email,39);
    if(validarEMAIL(email))
    {
        z=1;
    }else{cout<<"EMAIL YA EXISTENTE, INGRESE UN EMAIL CORRECTO "<<endl;}
    }
    estado=true;
    system("cls");
}


void clientes::mostrar() {
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Domicilio: "<< domicilio << endl;
    cout<< "TELEFONO: "<<telefono<<endl;
    cout<<"E-MAIL: "<<email<<endl;
}


void clientes::altaClientes() {
    FILE *p;
    p = fopen("clientes.dat", "ab");
    clientes obj;
    if (p == NULL) {
        cout << "Erorr al abrir el archivo de clientes";
    } else {
        obj.cargar();
        fwrite(&obj, sizeof (clientes), 1, p);
        fclose(p);
    }
    fclose(p);
}


void clientes::listarClientes() {
    clientes obj;
    int pos=0;
    system("cls");

    while(obj.leerDeDisco(pos++) == true){

            if(obj.getEstado()==true){

                obj.mostrar();
                cout<<endl;
            }
    }

    system("pause");
    system("cls");

}


bool clientes::eliminarClientes(){

    clientes obj;
    int DNI, pos;
    int x = 0;

    while(obj.leerDeDisco(x) == true) {
            if (obj.getEstado() == true) {
                    system("cls");
    cout<<"DNI del cliente a eliminar:  ";
    cin>>DNI;
    pos=buscarDNI(DNI);
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


bool clientes::eliminarDefClientes(){
    clientes obj;
    int pos=0;
    FILE *p, *pNuevo;
    system("cls");
    cout<<"Los sieguientes clientes seran eliminados de manera definitiva"<<endl;
    mostrarClientesBorrados();
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
    p=fopen("clientes.bak","wb");
    if(p==NULL)return false;
    while(obj.leerDeDisco(pos++)){
        fwrite(&obj,sizeof obj,1,p);
    }
    fclose(p);
    pNuevo=fopen("clientes.dat","wb");
    if(pNuevo==NULL)return false;

    p=fopen("clientes.bak","rb");
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




    ///




return true;}


int clientes::buscarDNI(int x){
    clientes obj;
    int pos=0;
    while(obj.leerDeDisco(pos) == true){
        if(obj.getDNI()==x && obj.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}


void clientes::mostrarClientesBorrados(){
    clientes obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if (obj.getEstado()==false){
            cout<<obj.getNombre()<<" ";
            cout<<obj.getDNI()<<" ";
        }
    }
}


bool clientes::leerDeDisco(int pos){
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (clientes), 0);
    bool leyo = fread(this, sizeof (clientes), 1, p);
    fclose(p);
    return leyo;
}


bool clientes::grabarEnDisco(){
    FILE *p;
    p=fopen("clientes.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (clientes), 1, p);
    fclose(p);
    return escribio;
}


bool clientes::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(clientes), 0);
    bool escribio=fwrite(this, sizeof (clientes), 1, p);
    fclose(p);
    return escribio;
}

void clientes::modificarTELEFONO()
{
    int pos=0,nuevo_telefono=0,DNI=0,z=0;
    clientes obj;
    system("cls");
    cout<<"INGRESE EL DNI DEL CLIENTE QUE DESEA CAMBIAR"<<endl;
    cin>>DNI;
    while(obj.leerDeDisco(pos))
    {   if(obj.getDNI()==DNI && obj.getEstado())
    {
            cout<<"INGRESE EL NUEVO TELEFONO: "<<endl;
            while(z==0)
                {
                cin>>nuevo_telefono;
                if(validarTelefono(nuevo_telefono))
                {
                    z=1;
                }else{cout<<"TELEFONO NO VALIDO, INGRESE UN TELEFONO VALIDO"<<endl;}
                }
            obj.setTelefono(nuevo_telefono);
            obj.modificarEnDisco(pos);
            system("cls");
            return;
    }
        pos++;
    }
    cout<<"NO EXISTE CLIENTE CON ESE DNI"<<endl;
     system("pause");
     system("cls");


}


#endif // CLIENTES_H_INCLUDED
