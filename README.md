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

## Historial de commits
- 3d67e02 Lab 08
- e647a0c Lab 07
- 456f062 Lab 06 completado
