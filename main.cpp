#include "CarritoCompras.h"
#include "ClienteVIP.h"
#include <iostream>
#include <string>

using namespace std;
//funciones prototipo de funciones que van a ser usadas para ahorrar lineas de codigo
int comprobarDatosNumericos(int limiteInf, int limiteSup);
void espaciador();
void mostrarCatalogo(Producto listaProductos[]);

int main(){
    //variables que vamos a usar dentro del codigo
    string nombreCliente, direccionCliente, tipoVipCliente;
    int tipoVipClienteNumerico;
    char confirmacionClienteVip;
    bool boolVip;
    int listaIdsProductos[10];
    //pedimos los datos al usuario
    cout << "Ingresa tu nombre: ";
    getline(cin, nombreCliente);
    cout << "Ingresa tu direccion: ";
    getline(cin, direccionCliente);
    do{
        cout << "Eres cliente VIP?(y/n)";
        cin >> confirmacionClienteVip;
    }while(confirmacionClienteVip != 'y' && confirmacionClienteVip != 'n');
    //isvip se vuelve verdadero si el cliente es vip
    boolVip = (tolower(confirmacionClienteVip) == 'y');
    //pedimos el nivel de vip del usuario en forma de numero para que no lo tenga que escribir
    if (confirmacionClienteVip == 'y') {
        cout << "Que tipo de VIP eres? " << endl;
        cout << "1: Oro" << endl << "2: Platino" << endl << "3: Diamante" << endl;
        tipoVipClienteNumerico = comprobarDatosNumericos(1, 3);
        if (tipoVipClienteNumerico == 1) {
            tipoVipCliente = "Oro"; 
        } 
        else if (tipoVipClienteNumerico == 2) {
            tipoVipCliente = "Platino";
        } 
        else {
            tipoVipCliente = "Diamante";
        }
    }
    //construimos ambos clientes, aunque el usuario solo sea 1
    Cliente clienteNormal(839, nombreCliente, direccionCliente, 0);
    ClienteVIP clienteVip(345, nombreCliente, direccionCliente, 0, tipoVipCliente);
    //solo hacemos un carrito para el cliente porque este es independiente de si el cliente es vip o no
    CarritoCompras carrito;
    //definimos los productos que va a tener nuestra tienda
    Producto producto1(354, "Gansito", 18.00);
    Producto producto2(576, "Pinguino", 19.00);
    Producto producto3(789, "Coca cola", 23000.00);
    Producto producto4(657, "Arroz", 25.00);
    Producto producto5(155, "Pollo", 55.00);
    Producto producto6(167, "Hamburguesa", 42.00);
    Producto producto7(179, "Pechuga", 14.00);
    Producto producto8(153, "Milanesa", 70.00);
    Producto producto9(458, "Pandaexpress", 105.00);
    Producto producto10(963, "Donitasbimbo", 32.00);
    Producto producto11(369, "Pepsi", 3.00);
    Producto producto12(145, "Fanta", 56.00);
    Producto producto13(745, "Sidral", 400.00);
    Producto producto14(985, "Computadora", 200.00);
    Producto producto15(652, "Audifonos", 899.00);
    Producto producto16(957, "Mouse", 470.00);
    Producto producto17(375, "Teclado", 2.00);
    Producto producto18(657, "Perro", 32.00);
    Producto producto19(234, "Gato", 7000.00);
    Producto producto20(137, "Coca cola de vainilla", 12.00);
    //agregamos los productos a una lista de 20 lugares
    Producto listaProductos[20] = {producto1, producto2, producto3, producto4, producto5, producto6, producto7, producto8, 
                                   producto9, producto10, producto11, producto12, producto13, producto14, producto15, producto16, 
                                   producto17, producto18, producto19, producto20};
    //dependiendo de si el cliente es vip, usamos un objeo cliente o otro, para esto sirve isvip
    cout << "Bienvenido " << (boolVip ? clienteVip.getNombre() : clienteNormal.getNombre()) << endl;
    //definimos mas variables que vamos a usar
    int opcion, idProductoEliminar, numeroProductoAgregar; 
    char confirmacionSalir;
    bool correrTienda = true;
    //usamos do while para que la tienda siempre corra por lo menos una vez
    do{
        //pedimos la opcion al usuario
        cout << "1: Mostrar Informacion Cliente " << endl;
        cout << "2: Mostrar numero de productos " << endl;
        cout << "3: Eliminar Producto" << endl;
        cout << "4: Mostrar carrito" << endl;
        cout << "5: Agregar producto al carrito" << endl;
        cout << "6: Pagar el carrito " << endl;
        cout << "0: Salir" << endl;
        //siempre comprobamos los datos antes de usarlos dentro de las funciones
        opcion = comprobarDatosNumericos(0,6);
        //switch case para hacer algo dependiendo del valor de opcion
        switch(opcion){
            case 1:
            //mostramos la informacion del cliente dependiendo del cliente correspondiente
                (boolVip ? clienteVip.displayInfo() : clienteNormal.displayInfo());
                espaciador();
                break;
                //mostramos la cantidad de productos dentro del carrito usando la funcion de carritocompras
            case 2:
                cout << "El numero de elementos en tu carrito es: " << carrito.getNumProductos() << endl;
                espaciador();
                break;
            case 3:
            //mostramos el carrito, luego pedimos el dato al usuario y se lo damos a la funcion de eliminar producto
                carrito.mostrarCarrito();
                cout << "Ingresa el id del producto que deseas eliminar: ";
                cin >> idProductoEliminar;
                carrito.eliminarProducto(idProductoEliminar);
                espaciador();
                break;
            case 4:
            //mostramos el carrito
                carrito.mostrarCarrito();
                espaciador();
                break;
            case 5:
            //mostramos los productos
                mostrarCatalogo(listaProductos);
                //reiniciamos siempre la variable
                numeroProductoAgregar = 1;
                do{
                    //comprobamos el dato, no puede ser mayor a 20 porque solo hay 20 productos
                    cout << "Ingresa el numero del producto que deseas agregar al carrito: " << endl;
                    numeroProductoAgregar = comprobarDatosNumericos(0,20);
                    cout << "Ingresa 0 cuando desees terminar. " << endl;
                    //el usuario nos esta dando un numero arriba del indice que le corresponde a cada producto
                    for(int i = 1; i <= 20; i++){
                        //en el momento en el que i sea igual al numero que el usuario indico
                        if(numeroProductoAgregar == i){
                            //agregamos el producto de un indice abajo del valor de i al carrito
                        carrito.agregarProducto(listaProductos[i-1]);
                        }
                        /* por ejemplo, si el usuario pide que agreguemos el producto 1, agregamos al carrito el producto que esta en el indice 0, es decir, 1 abajo
                        del numero que indico el usuario*/
                    }
                    //cuando el usuario ingrese 0, se rome el ciclo
                }while(numeroProductoAgregar != 0);
                espaciador();
                break;
            case 6:
            //iteramos la cantidad de productos que tenga el carrito, para no iterar de mas
                for(int i = 0; i < carrito.getNumProductos(); i++){
                    //agregamos a la lista el id del producto al que le corresponde el indice i en la lista de productos de CarritoCompras
                    listaIdsProductos[i] = carrito.getProducto(i);
                }
                //realizamos la compra y aplicamos el descuento, tambien dependiendo del tipo de cliente que sea
                (boolVip ? clienteVip.realizarCompra(listaIdsProductos, carrito.getNumProductos()) : clienteNormal.realizarCompra(listaIdsProductos, carrito.getNumProductos()));
                (boolVip ? clienteVip.aplicarDescuento(carrito.calcularTotalCompra()) : clienteNormal.aplicarDescuento(carrito.calcularTotalCompra()));
                cout << "El carrito fue pagado, los productos se agregaron al historial de compras. " << endl;
                cout << "Muestra la informacion de cliente si quieres ver tu historial. " << endl;
                espaciador();
                break;
            case 0:
            //confirmamos que el usaurio quiera salir de la tienda
                cout << "Estas seguro que quieres salir (y/n): " ;
                cin >> confirmacionSalir;
                if(tolower(confirmacionSalir) == 'y'){
                    //cambiamos el valor de correr tienda a false, asi que la siguiente vez que el while se evalue, se rompe el ciclo y salimos de la tienda
                    correrTienda = false;
                }
                espaciador();
                break;
            default:
            cout << "Opcion invalida" << endl;  
        };
        //mientras que correr tienda sea true, la tienda se va a seguir corriendo
    }while(correrTienda);
    return 0;
}



int comprobarDatosNumericos(int limiteInf, int limiteSup){
    //funcion que usamos para siempre comprobar los datos numericos, le gamos los limites inferiores y superiores para comprobar que esten 
    //entre estos
    int opcionUsuario;
    do{
        cout << "Ingresa un numero: ";
        cin >> opcionUsuario;
        if(opcionUsuario < limiteInf || opcionUsuario > limiteSup){
            cout << "Ingresa una opcion correcta." << endl;
        }
    }while(opcionUsuario < limiteInf || opcionUsuario > limiteSup);
    //regresamos el dato ya comprobado
    return opcionUsuario;
}

void espaciador(){
    cout << "-------------------------------------------------------------" << endl;
}
//mostramos cada producto dentro de la lista con su numero, su nombre y precio
void mostrarCatalogo(Producto listaProductos[]){
    for(int i = 0; i < 20; i++){
        //para que sea mas comprensible, mostramos los numeros de 1 a 20 en vez de de 0 a 19
        cout << "Producto " << i+1 << ": " << endl;
        cout << "Nombre: " << listaProductos[i].getNombre() << endl;
        cout << "Precio: $" << listaProductos[i].getPrecio() << endl;
        cout << "---------------------------------------" << endl;

    }
}
