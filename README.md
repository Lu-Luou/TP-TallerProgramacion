# Wordle - Trabajo Práctico

### Franco Mondino, Lucas Ruberto

![Logo Wordle](/DB/images.png)

## Descripción del proyecto
---
Este proyecto consiste en la implementación de una versión del juego **Wordle**, donde el objetivo es adivinar una palabra de 5 letras en un máximo de 6 intentos. Además, se implementa un "jugador virtual" que elige palabras basándose en su frecuencia en el idioma castellano.

### Estructura del juego

1. **Letras correctas en la posición correcta** se muestran en **verde**.
2. **Letras correctas en posición incorrecta** se muestran en **amarillo**.
3. **Letras incorrectas** se muestran en **gris**.

El proyecto se divide en dos módulos principales:

1. **Módulos Jugable**: Implementa el entorno para que un jugador humano juegue adivinando palabras.
2. **Módulos Jugador Virtual**: Un jugador automático que sugiere palabras según una base de datos.

## Archivos del proyecto

- `main.c`: Controla la ejecución principal del juego.
- `wordle.c` y `wordle.h`: Contienen la lógica del juego y la interacción con el jugador humano.
- `machine.c` y `machine.h`: Implementan la lógica del jugador virtual.
- `maxHeap.c` y `maxHeap.h`: Estructura de datos utilizada para optimizar la selección de palabras más frecuentes.
- `Makefile`: Script para compilar el proyecto.

## Compilación y ejecución

1. Para compilar el proyecto, usa el siguiente comando:
    ```bash
    make
    ```

2. Para ejecutar el juego:
    ```bash
    ./ourWordle <palabra_secreta>
    ```

3. Para limpiar los archivos compilados:
    ```bash
    make clean
    ```

## Estructuras de datos

### *ED "wordle"*
Se utilizó un **arreglo de "Letter"** donde cada letra almacena su respectivo caracter con el que forma una palabra, una bandera por si es una letra amarilla y otra bandera por si es ser verde.
Con esto nos ayuda a referenciar la correctitud de la palabra a adivinar, si la letra no es de ningún color se la toma como gris.


### *ED "machine"*
Se utilizó un **MaxHeap** para cargar una base de datos con las palabras y su frecuencia, optimizando el proceso de selección de la siguiente palabra a adivinar.
Para ir guardando las posibles palabras que pueda llegar a recomendar el jugador virtual, se van extrayendo las que sean validas y luego se las almacenan en otro heap auxiliar, el cual es referenciado al heap principal para que pueda volver a ser filtrado.


## Base de datos

La base de datos utilizada contiene palabras de 5 letras y su frecuencia de uso en el idioma castellano. Un ejemplo:

* ***Letra,3***
* ***Casas,5***
* ***Perro,5***


El criterio de desempate entre palabras de la misma frecuencia es alfabético, toma la primera palabra que encuentra de las 2 con mismo índice.
La base de datos esta ordenada alfabéticamente, al cargarse las palabras con el mismo índice, van a estar con el mismo orden.

## Observaciones sobre la implementación

- El jugador virtual selecciona las palabras de una base de datos, prefiriendo una palabra con mayor frecuencia según el archivo proporcionado.
- Se decidio implementar una estructura minimalista para atribuirle un color (verde, amarillo o ninguno) a cada letra de cada palabra ingresada en el wordle.
- Si no es posible adivinar la palabra en 6 intentos, el juego muestra un mensaje de derrota, en caso contrario se muestra un mensaje de victoria.
- Si el jugador virtual se queda sin posibles sugerencias, muestra un aviso al respecto.

---
---