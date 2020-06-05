#include <iostream>
#include "Fecha.h"
#include "Disco.h"
#include "Software.h"
#include "Libro.h"
#include "Reserva.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

istream &operator>>(istream &in, Fecha &b){
    cout<<"Teclea la fecha. Dia: ";
    in>>b.dd;
    cout<<" Mes: ";
    in>>b.mm;
    cout<<" Anio: ";
    in>>b.aa;
    cout<<endl;
    return in;
}

ostream &operator<<(ostream &out,const Fecha &b){
    out<<b.dd;
    out<<"/";
    out<<b.nombreMes();
    out<<"/";
    out<<b.aa;
    return out;
}

int main()
{
    Material *arrM[30];
    Reserva arrR[60];
    int d,m,a,idM,idC,var=0,var2=0;
    int x1,x2,idtitulo,idnuevo,idmn;
    char letra;
    string y,y2;
    char z,sn;
    int x=0,idSol;
    bool comp,reserv,comp2,comp3,comp4;
    Fecha temp,temp2;
    ifstream ArchR;
    ArchR.open("Reserva.txt");
    ifstream ArchM;
    ArchM.open("Material.txt");

    while(ArchR>>d>>m>>a>>idM>>idC){
        arrR[var].setfechaReservacion(d,m,a);
        arrR[var].setidCliente(idC);
        arrR[var].setidMaterial(idM);
        var++;
    }
    while(ArchM>>x1>>y>>z>>x2>>y2){
        switch(z){
            case 'L':{
            arrM[var2]=new Libro(x2,y2,x1,y);
            break;
            }
            case 'S':{
            arrM[var2]=new Software(x2,y2,x1,y);
            break;
            }
            case 'D':{
            arrM[var2]=new Disco(x2,y2,x1,y);
            break;
            }
        }
        var2++;
    }
    do{
        do{
            cout<<"Consultar lista de materiales (M)"<<endl;
            cout<<"Consultar la lista de reservaciones (R)"<<endl;
            cout<<"Consultar reservaciones de un material dado (C)"<<endl;
            cout<<"Consultar  reservaciones de una fecha dada (F)"<<endl;
            cout<<"Hacer una reservacion (H)"<<endl;
            cout<<"Terminar (T)"<<endl;
            cin>>letra;
            letra=toupper(letra);
        }while(!(letra=='R'||letra=='F'||letra=='M'||letra=='H'||letra=='T'||letra=='C'));
        switch (letra){
        case 'M':
            for(int i=0;i<var2;i++){
//                cout<<(arrM[i]->getidMaterial());
//                cout<<" ";
//                cout<<(arrM[i]->getTitulo());
//                cout<<" ";
                arrM[i]->muestraDatos();
                cout<<endl;
            }
                break;
        case 'R':
            for(int i=0; i<var;i++){
                cout<<"ID Cliente: "<<arrR[i].getidCliente();
                cout<<"  ID Material:";
                cout<<arrR[i].getidMaterial();
                cout<<"  Inicio:";
                cout<<arrR[i].getfechaReservacion();
                cout<<"  Final:";
                for(int u=0; u<var2;u++){
                    if ((arrR[i].getidMaterial())==(arrM[u]->getidMaterial())){
                    cout<<arrR[i].calculaFechaFinReserva(arrM[u]->cantidadDiasPrestamo());
                    }
                }
                cout<<endl;

 //               for(int u=0; u<=var2;u++){
 //                   if ((arrR[i].getidMaterial())==(arrM[u]->getidMaterial())){
 //                       cout<<arrM[u]->getTitulo();
 //                       cout<<"  ";
 //                   }
 //               }
            }
            break;
        case 'C':
            do{
                comp=false;
                cout<<"Escriba el ID del Material:"<<endl;
                cin>>idSol;
                for(int id=0; id<var2;id++){
                    if (idSol==(arrM[id]->getidMaterial())){
                        comp=true;
                        idtitulo=id;
                    }
                }
            }while(comp==false);
            cout<<arrM[idtitulo]->getTitulo()<<endl;
            reserv=false;
            for(int it=0;it<var;it++){
                if((arrR[it].getidMaterial())==idSol){
                   cout<<"Inicio: "<<arrR[it].getfechaReservacion();
                   cout<<"  Final: "<<arrR[it].calculaFechaFinReserva(arrM[idtitulo]->cantidadDiasPrestamo());
                   reserv=true;
                }
            }
            if (reserv==false){
                cout<<"No hay reservaciones para este material"<<endl;
            }
            break;
        case 'F':
            cin>>temp;
            comp2= false;
            for(int e=0;e<var;e++){
                for(int o=0;o<var2;o++){
                    if(arrR[e].getidMaterial()==arrM[o]->getidMaterial()){
                        if ((temp<=arrR[e].calculaFechaFinReserva(arrM[o]->cantidadDiasPrestamo()))&&(temp>=arrR[e].getfechaReservacion())){
                            cout<<"ID Cliente: "<<arrR[e].getidCliente()<<"  "<<arrM[o]->getTitulo()<<endl;
                            comp2=true;
                        }
                    }
                }
            }
            if(comp2==false){
                cout<<"No se encontro material reservado"<<endl;
            }
            cout<<endl;
            break;
        case 'H':
            var++;
            cout<<"ID Cliente: ";
            cin>>idnuevo;
            arrR[var-1].setidCliente(idnuevo);
            do{
                comp3=false;
                cout<<endl<<"ID Material: ";
                cin>>idmn;
                for(int it2=0;it2<var2;it2++){
                    if(idmn==(arrM[it2]->getidMaterial())){
                        comp3=true;
                    }
                }
            }while(comp3==false);
            do{
                comp4=false;
                cin>>temp2;
                for(int it3=0;it3<var;it3++){
                    if(idmn==arrR[it3].getidMaterial()){
                        for(int i4=0;i4<var2;i4++){
                            if(idmn==arrM[i4]->getidMaterial()){
                                if((temp2<=arrR[it3].calculaFechaFinReserva(arrM[i4]->cantidadDiasPrestamo()))&&(temp2>=arrR[it3].getfechaReservacion())){
                                    cout<<"Lo sentimos, el material esta reservado en esta fecha. Intente de nuevo."<<endl;
                                    comp4=true;
                                }
                            }
                        }
                    }
                }
                if(comp4==false){
                    arrR[var-1].setfechaReservacion(temp2.getDD(),temp2.getMM(),temp2.getAA());
                    arrR[var-1].setidMaterial(idmn);
                }
            }while(comp4==true);
            break;
        case 'T':
            x=1;
            break;
        }
        cout<<endl;
        if (x==0){
            cout<<"Desea realizar otra accion?(Y/N)"<<endl;
            cin>>sn;
            sn=toupper(sn);
            if(sn=='N'){
                x=1;
            }
        }
    }while(x==0);
    return 0;
}
