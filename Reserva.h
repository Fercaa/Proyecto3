#ifndef RESERVA_H
#define RESERVA_H
#include "Fecha.h"
#include "Material.h"
#include <iostream>
class Reserva
{
    public:
        Reserva();
        Reserva(int dia, int mes, int anio,int idM,int idC);
        Fecha calculaFechaFinReserva(int a);
        void setidMaterial(int idM);
        int getidMaterial();
        void setidCliente(int idC);
        int getidCliente();
        void setfechaReservacion(int dia,int mes,int anio);
        Fecha getfechaReservacion();
    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;
};

#endif // RESERVA_H
