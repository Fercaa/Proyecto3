#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;
class Fecha
{
    public:
        Fecha();
        Fecha(int dia,int mes,int anio);
        void setDD(int dia);
        int getDD()const{return dd;}
        void setMM(int mes);
        int getMM()const{return mm;}
        void setAA(int anio);
        int getAA()const{return aa;}
        void setFecha(int d,int m,int a);
        Fecha operator+(int d);
        bool operator>=(Fecha b);
        bool operator<=(Fecha b);
        bool operator<(Fecha b);
        bool operator>(Fecha b);
        bool operator==(Fecha b);
        friend ostream &operator<<(ostream &out, const Fecha &a);
        friend istream &operator>>(istream &in, Fecha &b);
        string nombreMes()const;

    private:
        int dd;
        int mm;
        int aa;
};



#endif // FECHA_H
