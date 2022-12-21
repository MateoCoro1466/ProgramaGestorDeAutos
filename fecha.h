#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class fecha{

private:
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
    int dia;
    int mes;
    int anio;

public:
    void setDia(int d){dia=d;}
    void setMes(int d){mes=d;}
    void setAnio(int d){anio=d;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void Cargar(){
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    int x;
    bool z = false;
    cout<<"ANIO: ";
    cin>>x;
    ///pq 1922
        if (x >= ((1900+tmPtr->tm_year) - 100) && x <= 1900+tmPtr->tm_year) {
        anio = x;
        z = true;
        }
            else {
                while(z == false) {
                cout << "Ingrese un numero menor o igual a " << 1900+tmPtr->tm_year << endl;
                cin >> x;
                    if (x >= ((1900+tmPtr->tm_year) - 100) && x <= 1900+tmPtr->tm_year) {
                    anio = x;
                    z = true;
                    }
                }
            }
        anio = x;
        z = false;
        cout<<"MES: ";
        cin>>x;
            if (anio == 1900+tmPtr->tm_year) {
                if (x >= 1 && x <= tmPtr->tm_mon+1) {
                    z = true;
                    mes = x;
                }
                else {
                    while(z == false) {
                    cout << "Ingrese un numero entre 1 y " << tmPtr->tm_mon+1 << endl;
                    cin >> x;
                        if (x >= 1 && x <= tmPtr->tm_mon+1) {
                            z = true;
                            mes = x;
                        }
                }
                }
            }  else {
                if (x >= 1 && x <= 12) {
                z = true;
                } else {
                while(z == false) {
                cout << "Ingrese un numero entre 1 y 12" << endl;
                cin >> x;
                    if (x >= 1 && x <= 12) {
                        z = true;
                        mes = x;
                    }
                }
                }
                }
        mes = x;
        z = false;

        cout<<"DIA: ";
        cin>>x;

        if (anio == 1900+tmPtr->tm_year) {
            if (mes == tmPtr->tm_mon+1) {
                if (x >= 1 && x <= tmPtr->tm_mday) {
                    z = true;
                    dia = x;
                } else {
                    while(z == false) {
            cout << "Ingrese un numero entre 1 y " << tmPtr->tm_mday << endl;
            cin >> x;
            if (x >= 1 && x <= tmPtr->tm_mday) {
                dia = x;
                z = true;
            }
        }
                }
            }
        } else {
            if (x >= 1 && x <= 31) {
        dia = x;
        z = true;
    } else {
        while(z == false) {
            cout << "Ingrese un numero entre 1 y 30" << endl;
            cin >> x;
            if (x >= 1 && x <= 30) {
                dia = x;
                z = true;
            }
        }
    }
        }
        dia = x;
    }


    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

};

#endif // FECHA_H_INCLUDED
