#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
class Producto{
    private:
        int idProducto;
        std::string nombre;
        double precio;
    public:
        Producto();
        Producto(int idProducto, std::string nombre, double precio);
        ~Producto();
        int getIdProducto();
        void setIdProducto(int idProducto);
        std::string getNombre();
        void setNombre(std::string);
        double getPrecio();
        void setPrecio(double precio);
        void mostrarProducto();
};
//constructores, destructor, getters y settes basicos, es una clase sencilla porque la vamos a usar para una clase mas compleja
Producto::Producto(){
    idProducto = 0;
    nombre = "";
    precio = 0.0;
}

Producto::Producto(int idProducto, std::string nombre, double precio){
    this -> idProducto = idProducto;
    this -> nombre = nombre;
    this -> precio = precio;
}

Producto::~Producto(){
}

int Producto::getIdProducto(){
    return idProducto;
}

void Producto::setIdProducto(int idProducto){
    this -> idProducto = idProducto;
}

std::string Producto::getNombre(){
    return nombre;
}

void Producto::setNombre(std::string nombre){
    this -> nombre = nombre;
}

double Producto::getPrecio(){
    return precio;
}

void Producto::setPrecio(double precio){
    this -> precio = precio;
}

void Producto::mostrarProducto(){
    std::cout << "ID: " << idProducto << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Precio: $" << precio << std::endl;
}

#endif
