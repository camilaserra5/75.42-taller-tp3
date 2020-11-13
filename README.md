# [75.42] Taller de programación I
## Trabajo práctico 3: Taller pages

**Camila Serra**  
**97422**  
**camilaserra5@gmail.com**  
**https://github.com/camilaserra5/75.42-taller-tp3**

_________________
## Introducción
Para este trabajo se desarrollará una aplicación servidor que atenderá petitorios HTTP, mediante los cuales podrá acceder y dar alta a recursos del mismo. El objetivo es el diseño y construcción de un sistema que atiende varios clientes de forma simultanéa. Se desarrollará en el lenguaje de programación C++11.

En el presente informe se detalla la solución propuesta y las diferentes pruebas realizadas para garantizar el correcto funcionamiento.

* [Objetivos](#objetivos)
* [Diseño](#diseño)
* [Pruebas](#pruebas)
* [Referencias](#referencias)

## Objetivos
El objetivo del presente trabajo es realizar una aplicación servidor que atenderá petitorios HTTP, mediante los cuales podrá acceder y dar alta a recursos del mismo.
El servidor será ejecutado de la siguiente manera:
```bash
./server <puerto/servicio> <root_file>
```
El parámetro **root_file** representa la ruta a un archivo que corresponde al recurso "/".

El cliente será ejecutado de la siguiente manera:
```bash
./client <ip/hostname> <puerto/servicio>
```

Petitorios HTTP
```
Método (GET o POST)
Ruta del recurso
Body (opcional)
```

El servidor deberá atender conexiones de clientes, hasta recibir por entrada estándar una **q**. Por salida estándar, deberá imprimir la primer línea de los petitorios que lleguen.

El cliente recibirá por entrada estándar el petitorio a enviar, y deberá imprimir por salida estándar la respuesta del servidor.

El formato del petitorio recibido será de la siguiente manera:
```
<metodo> <recurso> <protocolo>
<clave>:<valor>
<clave>:<valor>
.
.
.
<clave>:<valor>

body (opcional)
```

Respuestas del servidor en cada caso:

* **GET /**
    ```
    HTTP/1.1 200 OK
    Content-Type: text/html
    
    
    < contenido del root content >
    ``` 

* **GET /<recurso>**

    Si el recurso existe (se hizo un post)
    ```
    HTTP/1.1 200 OK
    Content-Type: text/html
    
    
    < contenido del recurso >
    ``` 
    Si no existe
    ```
    HTTP/1.1 404 NOT FOUND
    
    
    ```

* **POST /**
    ```
    HTTP/1.1 403 FORBIDDEN
    
    
    ``` 

* **POST /<recurso>**
    ```
    HTTP/1.1 200 OK
    
    < body recibido >
    ``` 

* **Otros**
    ```
    HTTP/1.1 405 METHOD NOT ALLOWED
    
    <método> es un comando desconocido
    ``` 

## Diseño


## Pruebas


## Referencias
* [cpp reference](https://en.cppreference.com/w/)  
* [cplusplus](http://www.cplusplus.com/doc/)  
* [Operador ()](https://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/)
* [stringstream](http://www.cplusplus.com/reference/sstream/stringstream/)