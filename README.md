# Wordle - Trabajo Práctico
## Franco Mondino, Lucas Ruberto
## Descripción del proyecto

Este consiste en la implementación de una versión del juego **Wordle**, donde el objetivo es adivinar una palabra de 5 letras en un máximo de 6 intentos. Además, del desarrollo de un jugador virtual que ofrece sugerencia de palabras basándose en su frecuencia en el idioma.

### Estructura del juego

1. **Letras correctas en la posición correcta** se muestran en <font color="green">**verde**</font>.
2. **Letras correctas en posición incorrecta** se muestran en <font color="yellow">**amarillo**</font>.
3. **Letras incorrectas** se muestran en <font color="gray">**gris**</font>.


El proyecto se divide en dos módulos principales:

1. **Módulo Jugable**: Implementa el entorno para que un jugador humano juegue adivinando palabras.
2. **Módulo Jugador Virtual**: Un jugador automático que elige palabras de una base de datos.

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
    ./wordle <palabra_secreta>
    ```

## Observaciones sobre la implementación

- El jugador virtual selecciona las palabras de una base de datos, eligiendo la palabra con mayor frecuencia según el archivo proporcionado.
- Si no es posible adivinar la palabra en 6 intentos, el juego muestra un mensaje de derrota.
- Si el jugador virtual se queda sin opciones, se termina la partida.

## Base de datos

La base de datos utilizada contiene palabras de 5 letras y su frecuencia de uso en el idioma castellano. Un ejemplo:

* ***Letra, 3***
* ***Casas, 5***
* ***Perro, 5***


El criterio de desempate entre palabras de la misma frecuencia es alfabético.

## Estructuras de datos

Se utilizó un **MaxHeap** para mantener las palabras de mayor frecuencia en la parte superior, optimizando el proceso de selección de la siguiente palabra a adivinar.

