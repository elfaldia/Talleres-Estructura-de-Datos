Taller 3 - Grafos - Estructura de datos
---------------------------------------
Integrantes:

Diego Martinez.
Gabriel Vergara.
---------------------------------------
comandos de compilacion:

cd "Taller 3"
g++ main.cpp -o salida
./salida
---------------------------------------
Implementacion:

Node.h
Este contiene la informacion de cada 
servidor, como su id, nombre de este mismo
y el tipo (si es un router o un cliente), ademas, contiene 
un vector de tipo Aristas.h, la cual vendria siendo la conexion
entre nodos.

Arista.h
Esta clase es la "conexion" entre nodos, ahora bien, estas conexiones
tienen sus atributos, que vendria siendo el id del servidor destinatario
(al cual se le esta conectando), la velocidad de llegada y los segundos.

Grafo.h
Aca se encuentra la vida del codigo, ya que se tendrea como atributo
un vector de nodos, los cuales al leer el .csv de conexiones, se empezaran
a armar las aristas para cada uno y creando sus ciertas conexiones, por
otro lado, al momento de crear una arista entre un nodo1 y un nodo2, este 
se hara de forma bidireccional.
---------------------------------------
Bellman-Ford
crea una lista desde el origen hasta todos los demás nodos (iniciándolos desde el infinito), también otra lista el cual tiene el seguimiento de los nodos con caminos más cortos (vector padre).

se iteran sobre todos los nodos, y se recorren las aristas del grafo, las cuales se actualizan si se encuentra un camino mas corto, también verificar los ciclos negativos.

finalmente se imprime el recorrido con el calculo correspondiente al tamaño del archivo con la velocidad y distancia de las conexiones.
---------------------------------------