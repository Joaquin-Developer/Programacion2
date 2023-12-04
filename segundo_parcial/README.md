### Formas de compilar:  

- En caso que tengamos un solo archivo:  
```bash
g++ NombreArchivo.cpp -o nombre_ejecutable
```

- En caso que tengamos varios archivos:  
Lo que haremos será compilar de forma separada, y luego generar un solo ejecutable
```bash
g++ -c Archivo1.cpp
g++ -c Archivo2.cpp
g++ Archivo1.o Archivo2.o -o nombre_ejecutable
```