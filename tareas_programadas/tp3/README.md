# Tarea programada 3

Esta tarea consiste en un código que almacena datos de ciudades desde un csv, los pone en grafos y realiza operaciones en el.

## Manual de usuario

Todos los comandos que se van a mencionar deben ser ingresados en una terminal dentro de la carpeta tp3

Para compilar se puede usar el comando make, y para correrlo despues de compilado se puede utilizar el comando make run

Para crear la documentación se puede usar make doc, y para abrirla make opendoc

Para eliminar todos los archivos creados por el makefile, se puede usar make clean

Cuando se corre el programa, este pide el nombre del archivo a correr, en este caso, como los archivos están dentro de una carpeta, se le debe proporcionar de la siguiente manera: "input_files/" + nombre del archivo, los tres archivos son input_small.csv, input_medium.csv e input_large.csv, luego de eso el programa le dirá cuantas ciudades se registraron, y mostrará el menú con las opciones a elegir