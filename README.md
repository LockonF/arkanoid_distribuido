# Arkanoid Distribuido

Fork del juego con funciones de Red. El punto es tener un juego multijugador en Red con un servidor que controle las funciones del juego y un cliente que haga los updates gráficos y envíe los cambios de cada jugador al servidor, para que lo distribuya.

## Librerías utilizadas
El proyecto requiere de las siguientes librerías

POCO Libraries. Se utilizó la serialización en JSON de la librería.
http://pocoproject.org/

Boost. Se utilizó la librería ASIO, que ayuda con las funciones de red. Se tomaron como base los ejemplos de servidor de chat y se adaptaron para el servidor de juego.
http://www.boost.org/

Las librerías se tienen que compilar y correr. Para utilizar POCO se configura, da make e install, tal cual se describe en el siguiente link:
http://pocoproject.org/download/index.html

Para utilizar Boost, en Ubuntu existen paquetes precompilados
http://packages.ubuntu.com/vivid/libboost-all-dev
http://stackoverflow.com/questions/12578499/how-to-install-boost-on-ubuntu

Posteriormente se tienen que linkear las librerías. Ejemplo de Boost
-L /usr/lib/ -lboost_system -lboost_thread -lpthread

Las convenciones de nombre de Boost son las siguientes:

http://www.boost.org/doc/libs/1_39_0/more/getting_started/unix-variants.html#library-naming

Para POCO:
-L/usr/local/lib/Poco -lPocoFoundation -lPocoUtil -lPocoJSON


http://stackoverflow.com/questions/2490804/how-to-link-poco-librarylibraries-to-our-program-in-unix-environment
