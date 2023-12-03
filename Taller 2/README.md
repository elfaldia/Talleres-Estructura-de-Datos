README TALLER -> Diego Martinez
--------------------------------
.- CODIGO DE COMPILACION
>crear nuevo terminal
cd "Taller 2"
g++ main.cpp -o salida
./salida
--------------------------------

COMPARACION DE TIEMPO ENTRE MINIMAX Y MINIMAX CON PODA ALPHA BETA

MINIMAX = (84 - 141) microsegundos
MINIMAXPAB = (20 - 30) microsegundos

como se puede apreciar, al aplicar poda alpha beta el tiempo de ejecucion baja
por lo que se puede concluir que llega a ser mas optimo su uso.

--------------------------------

FUNCIONAMIENTO DEL CSV

El guardado del juego se realiza de la siguiente forma.
.- Primero espera que terminen de lanzar cada jugadores.
.- Se preguntara "Do you wanna save the game and leave?".
.- Si es seleccionado se sobreescribira en el archivo loadGame.csv.
.- Tener en cuenta que solo guarda una sola partida, siendo esta la ultima que se guardo.

El cargado del juego se realiza de la siguiente forma.
.- El cargado de partida saldra en el menu principal como la opcion 4.
.- Habra un verificador, si el txt se encuentra vacio, nos dara un mensaje y nos mandara a un juego desde cero.
.- Podras ajustar las dificultad de la partida guardada, variando entre normal y hard.
.- Las partidas cargadas vendran como predeterminada con el algoritmo minimax sin porda alpha beta.

--------------------------------