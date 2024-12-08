#ifndef CLIENTEVIP_H
#define CLIENTEVIP_H
#include <iostream>
#include "Cliente.h"
//heredamos los atributos de Cliente
class ClienteVIP : public Cliente{
    private:
        std::string tipoClienteVip;
    public:
    //getters y setters nuevos para la nueva clase
        ClienteVIP();
        ClienteVIP(int idCliente, std::string nombre, std::string direccion, int numCompras, std::string tipoClienteVip);
        std::string getTipoClienteVip();
        void setTipoClienteVip(std::string tipoClienteVip);
        void aplicarDescuento(double totalCompra) override;
        void displayInfo() override;
};
//constructor estandar y parametrizado y destructor
ClienteVIP::ClienteVIP() : Cliente(){
    tipoClienteVip = "";
}

ClienteVIP::ClienteVIP(int idCliente, std::string nombre, std::string direccion, int numCompras, std::string tipoClienteVIP) : Cliente(idCliente, nombre, direccion, numCompras){
    this -> tipoClienteVip = tipoClienteVIP;
}
//getters y setters
std::string ClienteVIP::getTipoClienteVip(){
    return tipoClienteVip;
}

void ClienteVIP::setTipoClienteVip(std::string tipoClienteVip){
    this -> tipoClienteVip = tipoClienteVip;
}
//sobreescribimos la funcion de aplicar descuento de la clase base a esta para tomar en cuenta el nivel VIP del usuario
void ClienteVIP::aplicarDescuento(double totalCompra){
    double descuentoAplicar;
    if(getTipoClienteVip() == "Oro"){
        descuentoAplicar = totalCompra * 0.10;
    }
    else if(getTipoClienteVip() == "Platino"){
        descuentoAplicar = totalCompra * 0.15;
    }
    else{
        descuentoAplicar = totalCompra * 0.20;
    }

    std::cout << "El total a pagar sin descuento es de: $" << totalCompra << std::endl;
    std::cout << "El total a pagar con el descuento ya aplicado es: $" << totalCompra-descuentoAplicar << std::endl;
}
//usamos la funcion que ya teniamos ademas del nuevo dato que teniamos
void ClienteVIP::displayInfo(){
    Cliente::displayInfo();
    std::cout << "El nivel VIP del cliente es: " << tipoClienteVip << std::endl;
}


#endif
