#include <iostream>
using namespace std;

struct Producto {
	char nombre[50];
	int stock;
};

// verificar si los nombres son iguales
bool compararNombre(char cadena1[], char cadena2[]) {
	int i = 0;
	while (cadena1[i] != '\0' && cadena2[i] != '\0') {
		if (cadena1[i] != cadena2[i]) {
			return false;
		}
		i++;
	}
	return (cadena1[i] == '\0' && cadena2[i] == '\0');
}

// utilizando selection sort, ordenamos de menor a mayor
void ordenarPorStock(Producto productos[], int totalProductos) {
	for (int i = 0; i < totalProductos - 1; i++) {
		int indiceMenor = i;
		for (int j = i + 1; j < totalProductos; j++) {
			if (productos[j].stock < productos[indiceMenor].stock) {
				indiceMenor = j;
			}
		}
		if (indiceMenor != i) {
			Producto temp = productos[i];
			productos[i] = productos[indiceMenor];
			productos[indiceMenor] = temp;
		}
	}
	cout << endl;
	cout << "PRODUCTOS ORDENADOS POR STOCK" << endl;
	cout << endl;
	cout << "Presione Enter para continuar ";
}

// mostrar los productos con stock menor a 10
void mostrarProductosBajoStock(Producto productos[], int totalProductos) {
	int n;
	cout << "Ingrese la cantidad de productos que desea ver: ";
	cin >> n;

	cout << "PRODUCTOS CON STOCK MENOR A 10 UNIDADES" << endl;
	cout << endl;

	int contador = 0;
	for (int i = 0; i < totalProductos && contador < n; i++) {
		if (productos[i].stock < 10) {
			cout << "Producto: " << productos[i].nombre
			     << ", Stock: " << productos[i].stock << endl;
			contador++;
		}
	}

	if (contador == 0) {
		cout << "No hay productos con stock menor a 10 unidades."
		     << endl;
	}

	cout << "Presione Enter para continuar ";
}

// agregar un producto
void agregarProducto(Producto productos[], int &totalProductos) {
	if (totalProductos < 100) {
		cout << "Ingrese el nombre del producto: ";
		cin >> productos[totalProductos].nombre;
		cout << "Ingrese la cantidad en stock: ";
		cin >> productos[totalProductos].stock;
		totalProductos++;
		cout << endl;
		cout << "Producto agregado." << endl;
		cout << "Presione Enter para continuar ";
	} else {
		cout << "No se puede agregar más productos. Capacidad maxima "
			"alcanzada."
		     << endl;
		cout << "Presione Enter para continuar ";
	}
}

// eliminar un producto por su nombre
void eliminarProducto(Producto productos[], int &totalProductos) {
	char nombre[50];
	cout << "Ingrese el nombre del producto a eliminar: ";
	cin >> nombre;

	for (int i = 0; i < totalProductos; i++) {
		if (compararNombre(productos[i].nombre, nombre)) {
			for (int j = i; j < totalProductos - 1; j++) {
				productos[j] = productos[j + 1];
			}
			totalProductos--;
			cout << "Producto eliminado." << endl;
			return;
		}
	}
	cout << endl;
	cout << "Producto no encontrado." << endl;
	cout << "Presione Enter para continuar ";
}

// modificar un producto en base al nonmbre
void modificarProducto(Producto productos[], int totalProductos) {
	char nombre[50];
	cout << "Ingrese el nombre del producto a modificar: ";
	cin >> nombre;

	for (int i = 0; i < totalProductos; i++) {
		if (compararNombre(productos[i].nombre, nombre)) {
			cout << "Ingrese el nuevo stock para "
			     << productos[i].nombre << ": ";
			cin >> productos[i].stock;
			cout << "Stock actualizado." << endl;
			return;
		}
	}
	cout << endl;
	cout << "Producto no encontrado." << endl;
	cout << "Presione Enter para continuar ";
}

// para esperar la tecla enter del usuario
void esperarEnter() {
	cin.ignore();
	cin.get();
	system("cls");
}

// imprime todos los productos actuales
void mostrarProductos(Producto productos[], int totalProductos) {
	cout << "LISTA DE PRODUCTOS: " << endl;
	cout << endl;
	for (int i = 0; i < totalProductos; i++) {
		cout << "Producto: " << productos[i].nombre
		     << ", Stock: " << productos[i].stock << endl;
	}
	cout << endl;
	cout << "Presione Enter para continuar ";
	esperarEnter();
}

// Menú principal
void mostrarMenu() {
	cout << "------ MENU ------" << endl;
	cout << "1. Ordenar productos por stock" << endl;
	cout << "2. Mostrar productos con stock menor a 10" << endl;
	cout << "3. Agregar producto" << endl;
	cout << "4. Eliminar producto" << endl;
	cout << "5. Modificar producto" << endl;
	cout << "6. Mostrar todos los productos" << endl;
	cout << "7. Salir" << endl;
	cout << "------------------" << endl;
	cout << "Seleccione una opcion: ";
}

int main() {
	Producto productos[100] = {{"Pizzas", 15},
				   {"Computadoras", 8},
				   {"Telefonos", 25},
				   {"Consolas", 5},
				   {"Videojuegos", 35}};
	int totalProductos = 5;
	int opcion;

	do {
		mostrarMenu();
		cin >> opcion;

		switch (opcion) {
			case 1:
				ordenarPorStock(productos, totalProductos);
				esperarEnter();
				break;
			case 2:
				ordenarPorStock(productos, totalProductos);
				mostrarProductosBajoStock(productos,
							  totalProductos);
				esperarEnter();
				break;
			case 3:
				agregarProducto(productos, totalProductos);
				esperarEnter();
				break;
			case 4:
				eliminarProducto(productos, totalProductos);
				esperarEnter();
				break;
			case 5:
				modificarProducto(productos, totalProductos);
				esperarEnter();
				break;
			case 6:
				mostrarProductos(productos, totalProductos);
				break;
			case 7:
				cout << "Saliendo." << endl;
				break;
			default:
				cout << "Opcion no valida. Por favor, "
					"seleccione una opcion valida."
				     << endl;
				cin.clear();
				cout << "Presione ENTER para continuar "
				     << endl;
				esperarEnter();
		}

		cout << endl;
	} while (opcion != 7);

	return 0;
}