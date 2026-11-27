# Dungeon Quest

Informe de el progreso del proyecto. Cada sección cuenta qué implementé, cómo lo resolví y si compiló y funcionó.

Repositorio: https://github.com/vdelmoral2030im/dungeon-quest

---

## Lab 06 — La Forja

### Hechizos (hechizos.c)

Traduje a C los cuatro algoritmos que hice en Python en el Lab 01:

- mcd: el algoritmo de Euclides. En Python se hace con a, b = b, a % b, pero en C eso no existe, así que usé una variable temporal (temp) para guardar el b viejo antes de cambiarlo. Si no, el a terminaba usando el b nuevo y daba mal.

- fibonacci: versión iterativa con long long, porque F(92) ya tiene 19 dígitos y no cabe en un int.

- simple_loop y double_loop: los dos lazos que cuentan vueltas. El primero es lineal y el segundo cuadrático.


### Cronómetro (cronometro.c)

Escribí cronometro_tabla, que mide simple_loop con n = 1 000 000, 10 000 000 y 100 000 000, y double_loop con n = 1 000, 3 000 y 10 000, e imprime una tabla. Para medir uso la función medir que venía dada, a la que le paso el nombre de la función como puntero a función.

Mis tiempos en C:

| Función     |        n         |  Segundos    |                 
| ----------- | ---------------- | ------------ |
| simple_loop | 	1 000 000      | 	  0.003     |
| simple_loop | 	10 000 000     |    0.024     |
| simple_loop | 	100 000 000    | 	  0.239     |
| double_loop |    1 000         |   0.002      |
| double_loop | 	3 000          |	  0.024     |
| double_loop | 	10 000         | 	  0.237     |


### El guardián (guardian.c)

Informe y pruebas

- El desbordamiento: fibonacci(93) imprime un número negativo (-6246583658587674878) porque el resultado real no cabe en un long long y "da la vuelta". Lo expliqué en docs/informe_lab06.md.

- Rompí el compilador a propósito con cinco errores distintos y anoté los mensajes en el informe.

- Resultado de las pruebas: Lab 06: 18 de 18 pruebas pasan.

---

## Lab 07 — La mochila

### inventario.c

Aquí empecé a manejar memoria dinámica. En Python una lista crece sola con append; en C hay que pedir memoria con malloc/realloc y devolverla con free.

Lo que implementé:

- inventario_agregar: agrega un item al final. La mochila empieza vacía (puntero en NULL, cantidad 0, capacidad 0). La primera vez pido espacio para 2 items con malloc, y cuando se llena duplico la capacidad con realloc. Uso una variable nueva para el resultado de realloc, así, si no hay memoria, no pierdo la mochila que ya tenía.

- Recibo Item **inv (puntero a puntero) porque realloc puede mover la mochila a otra dirección y la función tiene que poder cambiar el puntero de quien la llama.

- Cada item guarda su propia copia del nombre (con una función auxiliar copiar_texto que usa malloc + strcpy), no un puntero al texto original.

- inventario_peso: suma los pesos de todos los items.

- inventario_imprimir: muestra un item por línea con su tipo (usando un switch), su nombre y su peso, y al final el peso total. Si la mochila está vacía, avisa.

- inventario_liberar: primero libera cada nombre y después el arreglo. Un free por cada malloc.

En main.c agregué la opción 4 del menú ("El inventario del heroe"), que crea una mochila con tres objetos, la imprime y la libera. Compila bien, no existen fugas de memoria.


---
## Lab 08 — Bestiario y combate

### Bestiario: lista enlazada (bestiario.c)

Los enemigos ya no van en un arreglo sino en nodos sueltos, donde cada uno apunta al siguiente. Implementé:

- bestiario_agregar: agrega al final. Si la lista está vacía, el nuevo nodo pasa a ser la cabeza; si no, recorro hasta el último nodo y lo enlazo ahí.

- bestiario_insertar: inserta en la posición pos. Si pos es 0 o negativa (o la lista está vacía), va al principio; si pos es mayor que el largo, va al final. Para el caso del medio me paro en el nodo anterior y cambio dos punteros, sin mover a los demás.

- bestiario_purgar: borra a todos los enemigos con vida ≤ 0. Lo hice en dos pasos: primero borro los muertos que estén al principio (porque eso cambia la cabeza), y después recorro el resto y salto los nodos muertos. Libero siempre el nombre y luego el nodo.

- bestiario_liberar: recorre la lista guardando el siguiente antes de liberar cada nodo.

- bestiario_imprimir, copiar_texto y nuevo_enemigo venían dadas.

**Igual que con la mochila, uso NodoEnemigo cabeza porque agregar al inicio o purgar al primero cambia la cabeza.**


### Combate (combate.c)

combate_pelear hace pelear al héroe contra un enemigo por turnos. El héroe golpea primero; si el enemigo queda con vida ≤ 0 gana el héroe, y si no, el enemigo contraataca. Devuelve 1 si gana el héroe y 0 si pierde. Cubrí los casos borde: punteros NULL, héroe o enemigo que ya estén muertos, y el caso en que ninguno puede hacer daño (los dos ataques ≤ 0), donde el héroe se retira para no caer en un bucle infinito. Las vidas se modifican directamente porque paso punteros.

#### Opción 5 del menú: "Explorar el dungeon"

En main.c armé el bestiario (Goblin, Orco, Dragón, y el Esqueleto insertado en la posición 1), lo imprimo, hago pelear al héroe contra cada enemigo en orden, y al final purgo a los derrotados y libero todo. 

---

---

## Lab 09 — La Herrería y la Formación

### La herrería: cola FIFO (herreria.c)

Implementé una cola con punteros `head` y `tail` para operaciones en $O(1)$:

- `herreria_encolar`: crea un `Pedido` con `malloc`, copia el nombre con `strncpy` asegurando `'\0'` al final y lo agrega por `tail` (o asigna `head` y `tail` si estaba vacía).
- `herreria_atender`: saca por `head`, copia el pedido a `destino`, avanza `head` y, si queda `NULL`, pone `tail = NULL` antes de hacer `free` y decrementar `cantidad`.
- `herreria_liberar`: recorre desde `head` guardando `sig` antes de cada `free` y reinicia la estructura con `herreria_iniciar`.

**¿Qué pasa si `atender` no actualiza `tail` cuando sale el último pedido?**  
Si `atender` no pone `tail = NULL` al vaciar la cola, `tail` queda apuntando a memoria ya liberada. Al encolar un nuevo pedido después, `tail->sig` escribe sobre un nodo liberado y `head` no se actualiza con el nuevo elemento.

### La formación: lista doblemente enlazada (formacion.c)

Completé las operaciones de la lista doble manteniendo siempre los enlaces `ant` y `sig` emparejados:

- `formacion_insertar_final`: espejo de `insertar_inicio`, agregando detrás de `ultimo` (`m->ant = f->ultimo` y `f->ultimo->sig = m`) o inicializando ambos extremos si estaba vacía.
- `formacion_contiene`: recorre de `primero` a `ultimo` comparando nombres con `strcmp`.
- `formacion_eliminar`: busca el nodo y reenlaza sus vecinos cubriendo los cuatro casos (medio, primero, último y único) antes de liberar y restar `cantidad`.
- `formacion_imprimir_reversa_rec` (bono): imprime la fila al revés usando recursión por `sig` sin recurrir a `ant`.

#### Opciones 6 y 7 del menú (`main.c`)

Agregué la opción `6) La herreria` y la opción `7) La formacion` en `main.c` con sus respectivas funciones auxiliares y `pausa()`.

---

---

## Lab 10 — El Cartógrafo

Aquí hice lo contrario del Lab 09: en vez de nodos sueltos unidos por punteros, una matriz, donde todo está pegado en memoria. El mapa del dungeon es un `char mapa[8][12]` y la tabla de daño sale de multiplicar dos matrices de `int`.

### El mapa (mapa.c)

- `mapa_celda`: devuelve el símbolo de la casilla `(fila, col)` usando solo punteros, sin corchetes: `*(*(mapa + fila) + col)`. Primero compruebo si la casilla está fuera del mapa (`fila < 0`, `fila >= MAPA_FILAS`, `col < 0` o `col >= MAPA_COLS`) y en ese caso devuelvo `'\0'` sin leer la memoria. Uso `>=` y no `>` porque los índices van de 0 a `MAPA_FILAS - 1`.
- `mapa_contar`: dos `for` anidados (filas y columnas) que llaman a `mapa_celda` y suman 1 cada vez que la casilla es igual al símbolo buscado. En el nivel 1 hay 3 enemigos (`E`) y 2 tesoros (`T`).
- `mapa_cargar`, `mapa_imprimir`, `mapa_imprimir_memoria` y `matriz_imprimir` venían dadas.

### La tabla de daño (mapa.c)

`matriz_multiplicar(A, fa, ca, B, fb, cb, C)` calcula `C = A x B`, donde `A` son héroes × atributos y `B` atributos × enemigos, así que `C[i][j]` es el daño del héroe `i` al enemigo `j`.

- **Precondición primero:** si `ca != fb`, o si alguna dimensión queda fuera de `1..MAT_MAX`, hago `return 0` antes de los `for`. Así se cancela de verdad: `C` queda intacta. Imprimir un error y seguir calculando no habría sido cancelar.
- **Tres `for` anidados:** `i` recorre los héroes, `j` los enemigos y `k` los atributos. Pongo `C[i][j] = 0;` justo antes del `for` de `k`, porque `C` puede venir con basura, y después acumulo `C[i][j] += A[i][k] * B[k][j];`.
- Al final `return 1;`, para que la función devuelva un valor en todos los caminos.

Lo comprobé a mano con el ejemplo de la guía: `[[3,1],[2,4]] x [[2,0],[5,3]] = [[11,3],[24,12]]`.

#### Opción 8 del menú: "El mapa del cartografo"

En `main.c` agregué `#include "mapa.h"`, el prototipo de `ver_mapa`, la línea `8) El mapa del cartografo` en `mostrar_menu` y el `case 8` con su `pausa()`. `ver_mapa()` carga y dibuja el mapa, cuenta enemigos y tesoros con `mapa_contar`, muestra las direcciones de memoria con `mapa_imprimir_memoria` y multiplica dos matrices 3×3 (héroes × atributos por atributos × enemigos) para mostrar la tabla de daño con `matriz_imprimir`.

Resultado de las pruebas: Lab 10: 22 de 22 pruebas pasan, y compila sin warnings.

### Pregunta: ¿cuántos bytes hay entre `mapa[0][11]` y `mapa[1][0]`, y por qué?

Hay **1 byte**. Aunque pensamos en el mapa como una cuadrícula de 8 filas, en memoria son 96 casillas seguidas, una fila detrás de otra (*row-major*), y `mapa[i][j]` está en la casilla `i * 12 + j`. `mapa[0][11]` es la casilla 11, el último elemento de la fila 0, y `mapa[1][0]` es la casilla 12, la primera de la fila 1. Son vecinas, y como un `char` ocupa 1 byte, la diferencia es 1 byte. La tabla de direcciones de la opción 8 lo muestra: `mapa[0][11]` termina en `...bb` y `mapa[1][0]` empieza en `...bc`.

