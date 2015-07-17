# Arkanoid Distribuido

Fork del juego con funciones de Red. El punto es tener un juego multijugador en Red con un servidor que controle las funciones del juego y un cliente que haga los updates gráficos y envíe los cambios de cada jugador al servidor, para que lo distribuya.


## El serializador

El ejemplo de uso del serializador está dentro de Game::update(). Es sencillo de usar y solamente require del envío de la estructura para poder convertir a string.

## Librerías utilizadas
Para instalar POCO solamente se tiene que correr ./configure, luego make y luego sudo make isntall.

Esto instala las librerías en /usr/local/lib

Para instalar Boost, primero se corre ./boostrap.sh, luego ./b2 y luego sudo ./b2 install --prefix=/usr/local .

Entonces se instalan las librerías en /usr/local/lib y los headers en /usr/local/import

## Compilación.

Si todos los archivos están en el mismo lugar. Entonces solamente exportamos la variable del bash de las librerías con

export LD_LIBRARY_PATH=/usr/local/lib

Y finalmente compilamos con

g++ -I/usr/local/include -L/usr/local/lib main.cpp udp_client.cpp Serializador.cpp tablero.cpp Game.cpp  -lboost_system -lboost_thread -lboost_timer -lboost_atomic -lboost_chrono -lSDL2 -lPocoFoundation -lPocoJSON -lpthread -std=c++11 -o arkanoid;

##Bugs

Al correr el cliente, se queda corriendo el io_service a pesar de que se cierre la interfaz gráfica. Falta arreglar eso

Falta que el servidor se mueva para controlar las excepciones con la serialización.
