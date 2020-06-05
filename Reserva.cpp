#include "Reserva.h"

Reserva::Reserva()
{
    idMaterial=0;
    idCliente=0;
}

Reserva::Reserva(int dia, int mes,int anio,int idM,int idC){
    setidCliente(idC);
    setidMaterial(idM);
    setfechaReservacion(dia,mes,anio);
}

void Reserva::setfechaReservacion(int dia,int mes,int anio){
    fechaReservacion.setFecha(dia,mes,anio);
}

void Reserva::setidCliente(int idC){
    idCliente=idC;
}

void Reserva::setidMaterial(int idM){
    idMaterial=idM;
}

int Reserva::getidCliente(){
    return idCliente;
}

int Reserva::getidMaterial(){
    return idMaterial;
}

Fecha Reserva::getfechaReservacion(){
    return fechaReservacion;
}

Fecha Reserva::calculaFechaFinReserva(int a){
    int dias=a;
    Fecha temp=fechaReservacion+dias;
    return temp;
}
