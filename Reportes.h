#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void empeladoMAyorSueldo()
{
    empleado obj;
    int pos=0,sueldomax=0,id;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getEstado())
        {
            if(obj.getSueldo()>sueldomax)
            {
                sueldomax=obj.getSueldo();
                id=obj.getID();
            }
        }
    }
    pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getID()==id)
        {
            obj.mostrar();
        }
    }
}


void AutoMasCaro()
{
    autos obj;
    int pos=0,precioMax=0,codigoAuto;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getEstado())
        {
            if(obj.getPrecio()>precioMax)
            {
                precioMax=obj.getPrecio();
                codigoAuto=obj.getCodigoAuto();
            }
        }
    }
    pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getCodigoAuto()==codigoAuto)
        {
            obj.mostrar();
        }
    }


}



void empleadoMinimoSueldo(){
empleado obj;
float sueldomin;
int pos=0,id;
int x=0;

    while(obj.leerDeDisco(pos++))
    {

        if(obj.getEstado())
        {
            if(x==0){sueldomin=obj.getSueldo();}

            if(obj.getSueldo()<sueldomin)
            {
                sueldomin=obj.getSueldo();
                id=obj.getID();
            }
        }
        x++;
    }
    pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getID()==id)
        {
            obj.mostrar();
        }
    }
}


void AutoUltimos5Anios()
{
    autos obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getEstado())
        {
            if(obj.getAnio()>2017)
            {
            obj.mostrar();
            }
        }
    }
}

void autoMasBarato() {
    autos obj;
    int pos=0,precioMin=0,codigoAuto;
    bool z = false;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getEstado() == true) {
            if (z == false) {
                precioMin = obj.getPrecio();
                codigoAuto = obj.getCodigoAuto();
                z = true;
            } else {
                if(obj.getPrecio() < precioMin) {
                precioMin = obj.getPrecio();
                codigoAuto = obj.getCodigoAuto();
                }
            }


        }
    }
    pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getCodigoAuto()==codigoAuto)
        {
            obj.mostrar();
        }
    }
}

void empleadoIngresadoEn2021() {
    empleado obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getEstado() == true)
        {
            if(obj.getFecha_inicio().getAnio() == 2021)
            {
                obj.mostrar();
                cout << endl;
            }
        }
    }
}

#endif // REPORTES_H_INCLUDED
