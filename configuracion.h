#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
#include "empleado.h"
#include "clientes.h"
#include "ventas.h"
#include "autos.h"
bool copiaSeguridadClientes(){
clientes obj;
int pos=0;
FILE *p;

p=fopen("clientes.bkp","wb");
if(p==NULL)return false;
while(obj.leerDeDisco(pos++)){
    fwrite(&obj,sizeof obj,1,p);
}
fclose(p);
return true;
}


bool copiaSeguridadEmpleado(){
empleado obj;
int pos=0;
FILE *p;

p=fopen("personal.bkp","wb");
if(p==NULL)return false;
while(obj.leerDeDisco(pos++)){
    fwrite(&obj,sizeof obj,1,p);
}
fclose(p);
return true;
}


bool copiaSeguridadAutos(){
autos obj;
int pos=0;
FILE *p;

p=fopen("autos.bkp","wb");
if(p==NULL)return false;
while(obj.leerDeDisco(pos++)){
    fwrite(&obj,sizeof obj,1,p);
}
fclose(p);
return true;
}


bool copiaSeguridadVentas(){
ventas obj;
int pos=0;
FILE *p;

p=fopen("ventas.bkp","wb");
if(p==NULL)return false;
while(obj.leerDeDisco(pos++)){
    fwrite(&obj,sizeof obj,1,p);
}
fclose(p);
return true;
}


bool restaurarClientes(){
clientes obj;
FILE *p, *pNuevo;

pNuevo=fopen("clientes.dat","wb");
if(pNuevo==NULL)return false;

p=fopen("clientes.bkp","rb");
if(p==NULL){fclose (pNuevo); return false;}

while (fread(&obj,sizeof obj,1,p)==1){
    if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,pNuevo);
        }
    }
fclose(p);
fclose(pNuevo);
return true;
}


bool restaurarEmpleado(){
empleado obj;
FILE *p, *pNuevo;

pNuevo=fopen("personal.dat","wb");
if(pNuevo==NULL)return false;

p=fopen("personal.bkp","rb");
if(p==NULL){fclose (pNuevo); return false;}

while (fread(&obj,sizeof obj,1,p)==1){
    if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,pNuevo);
        }
    }
fclose(p);
fclose(pNuevo);
return true;
}


bool restaurarAutos(){
autos obj;
FILE *p, *pNuevo;

pNuevo=fopen("autos.dat","wb");
if(pNuevo==NULL)return false;

p=fopen("autos.bkp","rb");
if(p==NULL){fclose (pNuevo); return false;}

while (fread(&obj,sizeof obj,1,p)==1){
    if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,pNuevo);
        }
    }
fclose(p);
fclose(pNuevo);
return true;
}


bool restaurarVentas(){
ventas obj;
FILE *p, *pNuevo;

pNuevo=fopen("ventas.dat","wb");
if(pNuevo==NULL)return false;

p=fopen("ventas.bkp","rb");
if(p==NULL){fclose (pNuevo); return false;}

while (fread(&obj,sizeof obj,1,p)==1){
    if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,pNuevo);
        }
    }
fclose(p);
fclose(pNuevo);
return true;
}
bool restaurarDatosInicio()
{
    FILE *p,*pNuevo;
    empleado obj;
pNuevo=fopen("personal.dat","wb");
if(pNuevo==NULL)return false;

p=fopen("empleado.ini","rb");
if(p==NULL){fclose (pNuevo); return false;}
while (fread(&obj,sizeof obj,1,p)==1){
    if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,pNuevo);
        }
    }
fclose(p);
fclose(pNuevo);
obj.actualizarIDNuevo();

FILE *p1,*p1Nuevo;
clientes obj1;
p1Nuevo=fopen("clientes.dat","wb");
if(p1Nuevo==NULL)return false;

p1=fopen("clientes.ini","rb");
if(p1==NULL){fclose (p1Nuevo); return false;}
while (fread(&obj1,sizeof obj1,1,p1)==1){
    if(obj1.getEstado()==true){
        fwrite(&obj1,sizeof obj1,1,p1Nuevo);
        }
    }
fclose(p1);
fclose(p1Nuevo);

FILE *p2,*p2Nuevo;
autos obj2;
p2Nuevo=fopen("autos.dat","wb");
if(p2Nuevo==NULL)return false;

p2=fopen("autos.ini","rb");
if(p2==NULL){fclose (p2Nuevo); return false;}
while (fread(&obj2,sizeof obj2,1,p2)==1){
    if(obj2.getEstado()==true){
        fwrite(&obj2,sizeof obj2,1,p2Nuevo);
        }
    }
fclose(p2);
fclose(p2Nuevo);

FILE *p3,*p3Nuevo;
ventas obj3;
p3Nuevo=fopen("ventas.dat","wb");
if(p3Nuevo==NULL)return false;

p3=fopen("ventas.ini","rb");
if(p3==NULL){fclose (p3Nuevo); return false;}
while (fread(&obj3,sizeof obj3,1,p3)==1){
    if(obj3.getEstado()==true){
        fwrite(&obj3,sizeof obj3,1,p3Nuevo);
        }
    }
fclose(p3);
fclose(p3Nuevo);




return true;


}


#endif // CONFIGURACION_H_INCLUDED
