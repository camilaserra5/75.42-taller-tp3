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
A continuación se muestran dos diagramas de secuencia (uno para el servidor y uno para el cliente) del camino feliz del programa.

### Servidor
![](http://www.plantuml.com/plantuml/png/ZPD1JmCX48Nl_8gnfzr4stiJJOrNJOp6KzCO2jEMI645TklF5nQowMIxriCUPkUzZ-41An-u2-rHiuEI23jhmzR-C2w2TV3XqR4czfLG3JS1OjsX-pnoPHXflAS6rJvfXIQySCFtwAZOYYyCBD7Xxk4SkeJv8fUmRgmB6rWxQmFibCODOsVAQ2mSMC9M6LabVJqfqSe7D5NDc7380vQ9H_g-Z7g3fyhtvbj88wG9wXIBwixSXKMtcdk9HlvVXr8CgHBj3RrjdS1dvTEEk9JLR35Bf98G26j2zDHCuWJqZ-7wYr1DZiEqjGsS3lqwVGUKXuvh9Uce97Ok13Q4cbkiACPp57ZU0h4GuSXP4idkcfxCgxC2lRSNGgM2SaY54gCjaQVRKryt3o7ci3B5_yUd_ADM7TBuwUYqlXn0OZ29amokGn5T3HCTzpZ4YKOEt_JbcdnDhZNLwFNaa5WkY5meCzzZp15kxk5xM9IwsIh-Ru_w5m00)

### Cliente
![](http://www.plantuml.com/plantuml/png/VOz1JyCm38Nl_XK-jXAm-mve4gUTa428mpIXB75PHEj4YJFu-JIr1Eqsw2NgUzzxjZTPJ98oz73qZh0BGGxX2uoLaF0bKu8u-jxwQ5ZGzfvOtWRZUQ4_JFf2UWxsWmIWTk3j_JownhkL_kBEnzKnPDdZBeOaUu0PLsDQWskqWPciD9M-mGgt8vp82EbuES-gNBDCdqsUYjg_eLIuQUlX_ZJhr6VQHDoMH-wTPCkno0-g3gW_RpoKhWD7PvpQYzioiMigtLvpRHyolIOlTCrDP4-_gwWC-lo_Z9BgNunx8kEMjp-MQiRaMIww58JwROXT6Vfl)

### Procesamiento
Como se puede ver en el servidor, en cada conexión de un cliente, se crea un nuevo **ClientProcessor**. Esta clase, extiende de la clase **Thread** ya que se atenderá un cliente en cada hilo. 
El procesamiento de cada cliente se realiza de la siguiente manera:
![](http://www.plantuml.com/plantuml/png/ZLFDQi904BxlK-mnWhv0eI8KIW-MIcFfUTsTwD9r9ynCR0i-V5qIGsgYvk31cU_dso-x2nP3Kks3sda7ka2K3VuePQmWwGy6KgKXyTQN9ef-2XwYh0WjC2CfPGcCG6-UY7eslvm_w0ZV6QFz0fbg0iQAB2mzooGv-iEGriN_sRmdQe8_W7xKGXKe1rULZiTZ-brFHrNCnYT94dawY-WJ5UoXPJPZrMpxLYT2IIXeCUH2oi4bi-brrO06hDkThbijFB447s6gD-X-ssDqH5h6VtPfY24Nyd7R9XdllGLvJjPB7o6xvzgleJXpnrhdujugwJBJDxqVyXLaXouRldHZq-v4obfeRDoNzNfLCrBJzQPJKsUlEj11Sm8kCNBTL8-UMhXvGncYoyuQavjG6v3X7OoxZ_eaBz233ULldsbX0jzyfqej8Bfg7_u0)

La respuesta según cada protocolo está definida por las siguientes clases:
![](http://www.plantuml.com/plantuml/png/VP1BJiGm38RtEKMMiEW58XRTbGMW2fK3j8sX4KsCOeU7nE5dEWyrpdHccU__VijnJTn7JdvMaxEWtn5vm5-b7hkkVGQUqEg7_whI3V0MUmN254Uuo5eateHN6s_XC-1FE2AnWD7VBdBgPqriZI6EBdpehuWZ4DtTIrKu_a1VUWz24auyBNJR6j3-oVJyaIT7h6FsK0rmqTuJOzQ5iyELufhaXULmXRcWGX53fRevLLoyw8WiBwaQWar-tW40)

## Referencias
* [cpp reference](https://en.cppreference.com/w/)  
* [cplusplus](http://www.cplusplus.com/doc/)  
* [Operador ()](https://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/)
* [stringstream](http://www.cplusplus.com/reference/sstream/stringstream/)
