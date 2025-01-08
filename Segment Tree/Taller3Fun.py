import csv

class SegmentTree:
    
    # Constructor de la clase SegmentTree
    def __init__(self,data,func):
        #largo de la lista de datos
        self.n = len(data)
        #se crea una lista con el doble de largo para obtener el espaccio suficiente
        self.tree = [0] * (2 * self.n)
        #se guarda la funcion que se va a utilizar
        self.func = func
        #se construye el arbol
        self.construir(data)
    
    def construir(self,data):
        for i in range(self.n):
            self.tree[self.n + i] = data[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.func(self.tree[i * 2], self.tree[i * 2 + 1])

    def consultar(self,left,right):
        #se inicializan las variables left y right para movernos en el arbol sisabe
        left += self.n
        right += self.n
        #se inicializa la variable response
        response = 0
        while left < right:
            if left % 2:
                response = self.func(response, self.tree[left])
                left += 1
            if right % 2:
                right -= 1
                response = self.func(response, self.tree[right])
            left //= 2
            right //= 2
        return response
    
#funciones para leer los datos del csv
def leer_stock(archivo):
    #se inicializan las categorias
    categorias = []
    #se inicializa el stock
    stock = []
    #se abre el archivo en modo lectura
    with open(archivo, 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            #se agrega a categorias el valor de la categorias
            categorias.append(int(row['Categoria']))
            #se agrega a stock el valor que corresponde a stock
            stock.append(int(row['Stock']))
    #devuelve las listas de categoria y stock
    return categorias, stock

def leer_ganancias(archivo):
    #se inicializan las semanas y ganancias
    semanas = []
    ganancias = []
    #se abre el archivo en modo lectura
    with open(archivo, 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            #se agrega a semanas el valor de la semana
            semanas.append(int(row['Semana']))
            #se agrega a ganancias el valor que corresponde a ganancias
            ganancias.append(float(row['Ganancia']))
    #devuelve las listas de semanas y ganancias
    return semanas, ganancias

#construye el arbol con respecto a stock
def construir_segment_tree_stock(stock):
    return SegmentTree(stock, lambda x, y: x + y)

#construye el arbol con respecto a ganancias
def construir_segment_tree_ganancias(ganancias):
    return SegmentTree(ganancias, lambda x, y: x + y)

#se hace la consulta con respecto a stock en el rango de las gategorias
def stock_en_rango(stock_tree, cate_index, cate_inicio, cate_fin):
    idx_inicio = cate_index[cate_inicio]
    idx_fin = cate_index[cate_fin]
    return stock_tree.consultar(idx_inicio, idx_fin + 1)

#se hace la consulta de ganancias con respecto a las semanas que se ingresen
def ganancia_en_rango(ganancia_tree, semanas, semana_inicio, semana_fin):
    idx_inicio = semanas.index(semana_inicio)
    idx_fin = semanas.index(semana_fin)
    return ganancia_tree.consultar(idx_inicio, idx_fin + 1)