#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H
#include "Producto.h"
#include <iostream>
class CarritoCompras{
    private:
    //variable constante y global dentro de la clase
        static const int MAXIMO_PRODUCTOS;
        //los productos dentro del carrito se representan con un arreglo de productos
        Producto productos[7];
        int numProductos;
    public:
        CarritoCompras();
        ~CarritoCompras();
        int getNumProductos();
        void agregarProducto(Producto productoAgregar);
        double calcularTotalCompra();
        void mostrarCarrito();
        void eliminarProducto(int idProducto);
        int getProducto(int indiceProducto);
};
//definimos nuestra variable constante para que sea accesible dentro de todas las instancias de la clase
const int CarritoCompras::MAXIMO_PRODUCTOS = 5;

CarritoCompras::CarritoCompras(){
    numProductos = 0;
}

CarritoCompras::~CarritoCompras(){
}

void CarritoCompras::agregarProducto(Producto productoAgregar){
    //comprobamos que el carrito no este lleno
    if(numProductos >= MAXIMO_PRODUCTOS){
        std::cout << "El carrito esta lleno, no puedes agregar mas productos" << std::endl;
    }
    //si no lo esta, agregamos el producto al indice que toca y aumentamos el contador de productos
    else{
        productos[numProductos] = productoAgregar;
        numProductos += 1;
        std::cout << "Producto agregado " << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
}

double CarritoCompras::calcularTotalCompra(){
    //sumamos todos los precios de todos los productos dentro del carrito
    double suma = 0;
    //iteramos la cantidad de veces que nos de cantidad de productos para no iterar de mas 
    for(int i = 0; i < numProductos; i++){
        suma += productos[i].getPrecio();
    }
    return suma;
}
int CarritoCompras::getNumProductos(){
    //funcion que nos regresa el numero de productos dentro del carrito
    return numProductos;
}

void CarritoCompras::mostrarCarrito(){
    //mostramos cada producto y todos sus atributos
    for(int i = 0; i < numProductos; i++){
        std::cout << "Producto " << i+1 << ": " << std::endl;
        std::cout << "ID: " << productos[i].getIdProducto() << std::endl;
        std::cout << "Nombre: " << productos[i].getNombre() << std::endl;
        std::cout << "Precio: $" << productos[i].getPrecio() << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
    //al final usamos la funcion anterior para mostrar el total de la compra tambien
    std::cout << "Total de la compra: $" << calcularTotalCompra() << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}


void CarritoCompras::eliminarProducto(int idProducto){
    int indice = -1;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].getIdProducto() == idProducto) {
            //guardamos el indice en el que esta el producto eliminado
            indice = i;
        }
    }
    //entramos a la condicion si el producto existe
    if (indice != -1){
        //iteramos desde el indice en el que estaba el producto hasta la cantidad de productos -1 porque le vamos a quitar un espacio a la lista
        for (int i = indice; i < numProductos - 1; i++){
            //recorremos cada producto al lugar anterior
            productos[i] = productos[i + 1];
        }
        //disminuimos la cantidad de producto para llevar bien la cuenta
        numProductos--;
        //mostramos un mensaje cuando eliminamos el producto
        std::cout << "El producto con id" << idProducto << " fue eliminado " << std::endl;
    }
    //si no existe mostramos el mensaje y terminamos la funcion
    else{
        std::cout << "El producto con ID " << idProducto << " no esta en el carrito." << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
}

int CarritoCompras::getProducto(int indiceProducto){
    //regresamos el id del producto que esta en el indice que recibe la funcion, eso lo usamos para la funcion de realizar compra de la clase
    return productos[indiceProducto].getIdProducto();

}
#endif
