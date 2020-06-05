#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha()
{
    dd=0;
    mm=0;
    aa=0;
}

Fecha::Fecha(int dia,int mes, int anio){
    dd=dia;
    mm=mes;
    aa=anio;
}

void Fecha::setAA(int anio){
    aa=anio;
}

void Fecha::setMM(int mes){
    mm=mes;
}

void Fecha::setDD(int dia){
    dd=dia;
}

void Fecha::setFecha(int d,int m,int a){
    setAA(a);
    setDD(d);
    setMM(m);
}


Fecha Fecha::operator+(int d){
    Fecha temp;
    int dt, mt,ant,tempdia,tempmes;
    dt=dd+d;
    mt=mm;
    ant=aa;
    switch(mt){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(dt<=31){
            temp.aa=ant;
            temp.mm=mt;
            temp.dd=dt;
        }
        else{
            tempdia=dt%31;
            mt++;
            if(mt>12){
                ant++;
                temp.aa=ant;
                temp.mm=1;
                temp.dd=tempdia;
            }
            else{
                temp.mm=mt;
                temp.aa=ant;
                temp.dd=tempdia;
            }

        }
        break;
    case 2:
        if(dt<=28){
            temp.aa=ant;
            temp.mm=mt;
            temp.dd=dt;
        }
        else{
            tempdia=dt%28;
            mt++;
            if(mt>12){
                ant++;
                temp.aa=ant;
                temp.mm=1;
                temp.dd=tempdia;
            }
            else{
                temp.mm=mt;
                temp.aa=ant;
                temp.dd=tempdia;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(dt<=30){
            temp.aa=ant;
            temp.mm=mt;
            temp.dd=dt;
        }
        else{
            tempdia=dt%30;
            mt++;
            if(mt>12){
                ant++;
                temp.aa=ant;
                temp.mm=1;
                temp.dd=tempdia;
            }
            else{
                temp.mm=mt;
                temp.aa=ant;
                temp.dd=tempdia;
            }
        }
    }
    return temp;
}

bool Fecha::operator<(Fecha  b){
    if (aa<b.aa){
        if(mm<b.mm){
            if(dd<b.dd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else{
        return false;
    }
}
bool Fecha::operator>(Fecha  b){
    if (aa>b.aa){
        if(mm>b.mm){
            if(dd>b.dd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else{
        return false;
    }
}

bool Fecha::operator<=(Fecha  b){
    if (aa<=b.aa){
        if(mm<=b.mm){
            if(dd<=b.dd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else{
        return false;
    }
}

bool Fecha::operator>=(Fecha  b){
    if (aa>=b.aa){
        if(mm>=b.mm){
            if(dd>=b.dd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else{
        return false;
    }
}

bool Fecha::operator==(Fecha  b){
    if (aa==b.aa){
        if(mm==b.mm){
            if(dd==b.dd){
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

string Fecha::nombreMes() const{
    switch(mm){
    case 1:
        return "Ene";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Abr";
        break;
    case 5:
        return "May";
        break;

    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Ago";
        break;
    case 9:
        return "Sep";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dec";
        break;
    }
}

