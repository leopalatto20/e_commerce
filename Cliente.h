#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include "CarritoCompras.h"
//definimos la clase con atributos privados y metodos publicos
class Cliente{
    private:
        int idCliente;
        std::string nombre;
        std::string direccion;
        int historialCompras[10];
        int numCompras;
    public:
        Cliente();
        Cliente(int idCliente, std::string nombre, std::string direccion, int numCompras);
        ~Cliente();
        void setIdCliente(int idCliente);
        int getIdCliente();
        void setNombre(std::string nombre);
        std::string getNombre();
        void setDireccion(std::string direccion);
        std::string getDireccion();
        void setNumCompras(int numCompras);
        int getNumCompras();
        void realizarCompra(int idProducto[10], int cantidadProductos);
        virtual void aplicarDescuento(double totalCompra);
        virtual void displayInfo();


};
//constructor estandar y parametrizado
Cliente::Cliente(){
    idCliente = 0;
    nombre = "";
    direccion = "";
    numCompras = 0;
}

Cliente::Cliente(int idCliente, std::string nombre, std::string direccion, int numCompras){
    this -> idCliente = idCliente;
    this -> nombre = nombre;
    this -> direccion = direccion;
    this -> numCompras = numCompras;
    
}
//destructor
Cliente::~Cliente(){
}
//setters y getters
void Cliente::setIdCliente(int idCliente){
    this -> idCliente = idCliente;
}

int Cliente::getIdCliente(){
    return idCliente;
}

void Cliente::setNombre(std::string nombre){
    this -> nombre = nombre;
}

std::string Cliente::getNombre(){
    return nombre;
}

void Cliente::setDireccion(std::string){
    this -> direccion = direccion;
}

std::string Cliente::getDireccion(){
    return direccion;
}

void Cliente::setNumCompras(int){
    this -> numCompras = numCompras;
}

int Cliente::getNumCompras(){
    return numCompras;
}

void Cliente::realizarCompra(int idProducto[10], int cantidadProductos){
    for(int i = 0; i < cantidadProductos; i++){
        //aqui pasamos el contenido del arreglo que nos dio el usuario al de nuestro historial de compras
        historialCompras[i] = idProducto[i];
        //aumentamos en 1 el numero de compras
        numCompras += 1;
    }
}
 
void Cliente::aplicarDescuento(double totalCompra){
    double descuentoAplicar;
    //multiplicamos el total de la compra por 0.05 para sacar el 5% de ese total
    descuentoAplicar = totalCompra* 0.05;
    
    if(getNumCompras() >= 5){
        std::cout << "El total de la compra sin descuento es: $" << totalCompra << std::endl;
        std::cout << "El total a pagar con el descuento aplicado es: $" << totalCompra-descuentoAplicar << std::endl;
    }
    else{
        std::cout << "Ningun descuento aplicado." << std::endl;
        std::cout << "El total de la compra sin descuento es: $" << totalCompra << std::endl;
    }
    //le restamos el descuento que calculamos al total
    
}

void Cliente::displayInfo(){
    std::cout << "El nombre del cliente es: " << nombre << std::endl;
    std::cout << "La direccion del cliente es: " << direccion <<std::endl;
    std::cout << "El ID del cliente es: " << idCliente <<std::endl;
    std::cout << "El numero de compras del cliente es: " << numCompras << std::endl;
    //iteramos a traves de nuestra lista de historial de compras para mostrar el id de cada producto que compro el usuario
    for(int i = 0; i < numCompras; i++){
        std::cout << "El cliente compro el producto: " << historialCompras[i] << std::endl;
    }
}

#endif
