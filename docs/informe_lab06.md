# Informe — Lab 06 · La Forja

**Nombre:**
**Repositorio:**

---

## 1. El cronómetro: C contra Python

Pega la tabla que imprime la opción 2 del menú y completa la última columna con tus tiempos de
Python del Lab 01 (los que tengas; si no mediste algún `n`, déjalo en blanco).

| función | n | segundos en C | segundos en Python |
|---|---|---|---|
| `simple_loop` | 1 000 000 | | |
| `simple_loop` | 10 000 000 | | |
| `simple_loop` | 100 000 000 | | |
| `double_loop` | 1 000 | | |
| `double_loop` | 3 000 | | |
| `double_loop` | 10 000 | | |

  funcion                   n     segundos
  simple_loop         1000000     0.003000
  simple_loop        10000000     0.024000
  simple_loop       100000000     0.239000
  double_loop            1000     0.002000
  double_loop            3000     0.024000
  double_loop           10000     0.237000

**¿Cuántas veces más rápido es C?**
Dividí el tiempo de Python entre el tiempo de C en cada fila y C salió mucho más rápido en todas. Lo que más me sorprendió es que C hace en una fracción de segundo lo que a Python le toma bastante más.

**¿Cambió la forma de la curva, o solo la constante? ¿Por qué?** 
Solo cambió la constante. La forma de la curva es la misma en los dos lenguajes. En simple_loop, cuando multiplico n por 10 el tiempo también se multiplica por más o menos 10 (de 0.004 a 0.04). En double_loop, cuando n se multiplica por 10 (de 1 000 a 10 000) el tiempo se multiplica por unas 100 (de 0.0004 a 0.039). Eso pasa porque hay un ciclo dentro de otro, y el trabajo es n por n. Esto no depende del lenguaje, depende de cómo está armado el algoritmo. C solo hace cada vuelta más rápido, pero da las mismas vueltas que Python. 
---

## 2. El desbordamiento

¿Qué imprime `fibonacci(93)`? Explica con tus palabras por qué sale ese número.
(Pista: busca cuál es el valor más grande que cabe en un `long long`).

imprime -6246583658587674878, un número negativo, aunque Fibonacci solo suma números positivos y no debería dar negativo nunca. Pasa porque en C cada número se guarda en un espacio de tamaño fijo. Un long long es como una caja con un límite, y lo más grande que cabe es 9 223 372 036 854 775 807. fibonacci(92) todavía cabe (7 540 113 804 746 346 429), pero el resultado real de fibonacci(93) es 12 200 160 415 121 876 738, que es más grande que el límite y no cabe en la caja. Cuando el número se pasa, C no avisa ni da error. Simplemente el número "da la vuelta". Al dar la vuelta, el resultado cae en los negativos y por eso sale ese número raro. Comprobé que es así: si a -6 246 583 658 587 674 878 le sumo 18 446 744 073 709 551 616 (que es 2 elevado a 64) me da 12 200 160 415 121 876 738, el valor correcto.
---

## 3. Rompe el compilador

Provoca cada error a propósito, copia el mensaje **exacto** del compilador y explícalo.
Después déjalo arreglado: el repositorio tiene que compilar.

| Lo que hiciste | Mensaje del compilador | Qué significa |
|---|---|---|
| quitar un `;` | | |
| usar una variable sin declararla | | |
| `int x = "hola";` | | |
| una función `int` sin `return` | | |
| llamar a `mcd` sin el `#include "hechizos.h"` | | |

| quitar un `;` | `error: expected ',' or ';' before 'printf'` | Me faltaba el `;` al final de `int x = 5`. El compilador no lo nota en esa línea, sino cuando llega a la siguiente (`printf`) y ve que algo quedó sin cerrar. Por eso el error aparece una línea después de donde está el problema. |
| usar una variable sin declararla | `error: 'x' undeclared (first use in this function)` | Usé `x` sin haberle dicho antes al compilador qué era. Hay que declararla primero, por ejemplo `int x;`. |
| `int x = "hola";` | `warning: initialization of 'int' from 'char *' makes integer from pointer without a cast [-Wint-conversion]` | Estoy tratando de guardar un texto ("hola") en una variable que solo guarda números enteros. Un texto y un número son cosas distintas. |
| una función `int` sin `return` | `warning: control reaches end of non-void function [-Wreturn-type]` | La función dice que va a devolver un entero, pero llegó al final sin devolver nada. Falta el `return`. |
| llamar a `mcd` sin el `#include "hechizos.h"` | `warning: implicit declaration of function 'mcd' [-Wimplicit-function-declaration]` | El compilador no sabe qué es `mcd` porque no le dije dónde está definida. El `#include "hechizos.h"` es lo que se la presenta. |

---

## 4. El repositorio

- Enlace a tu repositorio:
https://github.com/vdelmoral2030im/dungeon-quest.git

- ¿Cuántos commits hiciste? Pega la salida de `git log --oneline`:


