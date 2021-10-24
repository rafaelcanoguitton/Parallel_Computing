# Informe Lista Enlazada

## Introducción

Para este informe se hizo una comparación de tiempos de Lista Enlazada con Pthreads en 3 casos:

- Mutex por nodo

- Mutex por lista

- Read-Write mutex

## Experimento

La comparación se hace a través de 100000 operaciones por threads, con el80% operación Member, 10% Insert y 10%Delete.

| Implementación            | 1        | 2        | 4      | 8      |
| ------------------------- | -------- | -------- | ------ | ------ |
| Read-Write Locks          | 3.347126 | 2.5136   | 2.5595 | 2.8484 |
| One Mutex for Entire List | 0.440076 | 1.563613 | 3.4515 | 7.5937 |
| One Mutex per Node        | 7.4777   | 1.9569   | 1.1751 | 7.9573 |

## Conclusión

Llegamos a que evidentemente, teóricamente y prácticamente la implementación con Read-Write siempre va a ser mejor que las demás. Sin embargo se puede observar la variación de tiempos que existe en cuanto a la implementación de la lista con un mutex para la lista entera y la lista con mutex por nodo, en las cuales existe el comportamiento más caótico e impredecible.
