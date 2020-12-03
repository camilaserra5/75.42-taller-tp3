# Correcciones

El tp está muy bien, pero hay una race condition al hacer limpieza de los clientes conectados. Recordar que por más que el objeto sea uno solo (el clientManager), el mismo se está accediendo desde 2 hilos distintos (el thread que está corriendo run, y el thread que llama a stop). Minimizar la cantidad de recursos accedidos concurrentemente: lo único necesario para terminar el `run()` era cortar el aceptador, la parte de liberar recursos la podía hacer el run() al finalizar su ciclo. 

Nota final: 7
