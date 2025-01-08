from Taller3Fun import leer_stock, leer_ganancias, construir_segment_tree_stock, construir_segment_tree_ganancias, stock_en_rango, ganancia_en_rango

def menu():
    categorias, stock = leer_stock('stock_productos.csv')
    semanas, ganancias = leer_ganancias('ganancias.csv')

    stock_tree = construir_segment_tree_stock(stock)
    ganancia_tree = construir_segment_tree_ganancias(ganancias)

    indice = {cate: i for i, cate in enumerate(categorias)}

    while True:
        print("\nBienvenido al sistema de Consultas de Almacenes Salem:")
        print("Que desea hacer? :)")
        print("1. Stock entre categorias")
        print("2. Ganancias entre semanas")
        print("3. Salir")
        opcion = input("Seleccione una opcion: ")

        if opcion == '1':
            try:
                print("Ingrese desde la categoria 1 hasta la 200 como maximo, gracias")
                cate_inicio = int(input("Ingrese la categoria de inicio: "))
                cate_fin = int(input("Ingrese la categora de fin: "))
                if cate_inicio <= 0 or cate_fin <= 0:
                    print("Los números deben ser mayores a 0. Intente de nuevo.")
                elif cate_inicio > 200 or cate_fin > 200:
                    print("Solo hay 200 filas. Intente de nuevo.")
                else:
                    print(f"Stock desde la categoria {cate_inicio} hasta la categoria {cate_fin}: {stock_en_rango(stock_tree, indice, cate_inicio, cate_fin)}")
            except ValueError:
                print("Ingrese valores validos porfavor :)")
        elif opcion == '2':
            try:
                print("Ingrese desde semana 1 hasta 200 como maximo, gracias")
                semana_inicio = int(input("Ingrese la semana de inicio: "))
                semana_fin = int(input("Ingrese la semana de fin: "))
                if semana_inicio <= 0 or semana_fin <= 0:
                    print("Error en el numero pa, intente de nuevo")
                elif semana_inicio > 200 or semana_fin > 200:
                    print("Intente de nuevo :)")
                else:
                    print(f"Ganancia desde la semana {semana_inicio} hasta la semana {semana_fin}: {ganancia_en_rango(ganancia_tree, semanas, semana_inicio, semana_fin)}")
            except ValueError:
                print("Ingrese valores validos porfavor :)")
        elif opcion == '3':
            print('Gracias por su preferencia :)')
            break
        else:
            print("Opcion invalida")

if __name__ == "__main__":
    menu()