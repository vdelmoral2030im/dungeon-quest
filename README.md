# Dungeon Quest

Un solo proyecto en C que construyes **a lo largo de todo el semestre**. Cada semana le agregas una
pieza nueva; al final tienes un juego completo, escrito por ti, de varios miles de líneas.

> Este repositorio es tuyo. No es una tarea que se entrega y se olvida: lo que escribas en la
> semana 6 lo vas a seguir usando en la semana 16.

---

## Primeros pasos: convierte esta carpeta en TU repositorio

El profesor te dio esta plantilla en un `.zip`. Todavía no es un repositorio: es una carpeta
normal. Lo conviertes tú, **una sola vez**, el primer día.

> La guía completa, paso a paso, es `guia_git_github.md` (te la dio el profesor
> junto con el zip). Aquí va el resumen.

### 1. Descomprime y comprueba que compila

1. Descomprime el zip en un lugar fácil de encontrar, por ejemplo `Documentos\dungeon-quest`.
2. Abre **la carpeta** en VS Code (no los archivos sueltos).
3. Compila y prueba (ver *Compilar y probar*, más abajo). Debe abrir el menú de La Posada y las
   pruebas deben decir `4 de 18`.

**No sigas hasta que compile.** Si algo falla aquí, el problema es el compilador, no git.

### 2. Crea el repositorio en tu computador y publícalo

**Con GitHub Desktop** (recomendado en el laboratorio: no pide permisos de administrador):

1. **File → Add local repository** y elige la carpeta `dungeon-quest`.
2. Te dirá que no es un repositorio. Pulsa **create a repository** y luego **Create repository**.
   Esto hace tu primer *commit* con todos los archivos.
3. Pulsa **Publish repository**. Deja el nombre `dungeon-quest` y **marca "Keep this code
   private"**. Publica.

**Con la terminal:**

```
cd dungeon-quest
git init -b main
git add .
git commit -m "Lab 06: plantilla inicial"
```

Luego, en <https://github.com/new>, crea un repositorio **vacío** llamado `dungeon-quest`,
**privado**, sin README, sin `.gitignore` y sin licencia (ya los tienes). Y conéctalo:

```
git remote add origin https://github.com/TU_USUARIO/dungeon-quest.git
git push -u origin main
```

### 3. Dale acceso al profesor

En GitHub, entra a tu repositorio → **Settings → Collaborators → Add people** y agrega al
profesor. **Sin esto no puede ver tu trabajo y no puede corregirlo.**

---

## La meta

Al terminar el semestre, `make` produce un único programa, `dungeon`, desde cuyo menú:

- creas un **héroe** con un inventario que crece en memoria,
- exploras un dungeon lleno de **enemigos** y peleas contra un jefe,
- organizas la **herrería** y el **orden de marcha** de tu grupo,
- recorres un **mapa** y calculas una tabla de daño con matrices,
- haces crecer un **bosque fractal** que se dibuja como imagen y evoluciona,
- ordenas miles de héroes en un **Salón de la Fama** y mides qué algoritmo gana,
- guardas a tus aventureros en un **Registro del Gremio** con búsqueda instantánea,
- y **guardas la crónica de tu partida comprimida**, con un compresor que escribiste tú.

Esa crónica la va escribiendo el propio juego desde la semana 11 (Lab 10). En la última semana, el
compresor del Lab 13 comprime exactamente lo que tu juego escribió durante el semestre.

---

## La hoja de ruta

Cada laboratorio agrega un **módulo** (un `.h` en `include/` y un `.c` en `src/`) y una **opción
al menú** de `src/main.c`.

| Semana | Lab | Lo que agregas | Lo que aprendes |
|---|---|---|---|
| 6 | 06 | `hechizos`, `cronometro`, `guardian` | compilar, tipos, `switch`, `rand`, git |
| 7–8 | 07 | `inventario`, `bestiario`, `combate` | `struct`, `malloc`/`free`, listas enlazadas |
| 9 | 08 | `herreria`, `formacion` | colas, listas doblemente enlazadas |
| 10 | 09 | `mapa` | matrices, aritmética de punteros |
| 11–12 | 10 | `fractal`, `cronica`, y luego la pila y la mutación | recursión, archivos, pilas |
| 13–14 | 11 | `ordenar`, el Salón de la Fama | ordenamiento, medir algoritmos |
| 15 | 12 | `gremio` | índices, búsqueda binaria, borrado lógico |
| 16 | 13 | `huffman` | árboles, colas de prioridad, bits |

---

## Cómo está organizado

```
dungeon-quest/
├── README.md        este archivo
├── Makefile         para compilar con  make
├── compilar.bat     lo mismo, en Windows sin make
├── probar.bat       las pruebas, en Windows sin make
├── include/         los .h — QUÉ existe            (las vitrinas)
├── src/             los .c — CÓMO funciona          (los talleres)
│   └── main.c       el menú de La Posada: crece cada semana
├── tests/           las pruebas de cada laboratorio
├── datos/           archivos que lee el juego
└── docs/            tus informes, uno por laboratorio
```

**La regla:** un módulo = un `.h` en `include/` + un `.c` en `src/`, con el mismo nombre.
`guardian.h` ↔ `guardian.c`. Nunca se incluye un `.c`: se incluye su `.h`.

---

## Compilar y probar

**Mac, Linux, o la terminal "MSYS2 UCRT64" de Windows:**

```
make            compila el juego
./dungeon       lo ejecuta
make test       corre las pruebas
make limpiar    borra lo compilado
```

**Windows desde PowerShell o cmd** (o con doble clic):

```
.\compilar.bat
.\dungeon.exe
.\probar.bat
```

Las dos formas usan exactamente las mismas banderas:

```
gcc -Wall -Wextra -std=c99 -Iinclude ...
```

### Las pruebas

Cada laboratorio trae un archivo `tests/test_labNN.c`. Lo copias a tu carpeta `tests/` y corres
las pruebas. **Tu meta de la semana es que pasen todas:**

```
  Lab 06: 18 de 18 pruebas pasan

  TODAS LAS PRUEBAS PASAN
```

No modifiques los archivos de `tests/`. Son el criterio de corrección.

---

## Entregar cada semana

Al final de cada sesión, y cada vez que avances en casa:

```
git add .
git commit -m "Lab 06: guardian terminado"
git push
```

Cuando el laboratorio esté listo, **márcalo con una etiqueta** y súbela:

```
git tag lab06
git push origin lab06
```

**La etiqueta es la entrega.** El profesor corrige el estado de tu repositorio en la etiqueta
`labNN`, no lo que haya después. Si la pones antes de terminar, se corrige lo que había.

---

## Reglas del proyecto

1. **Compila sin un solo warning** con `-Wall -Wextra`. Un warning es un error que todavía no
   te ha mordido.
2. **Todas las pruebas pasan** antes de poner la etiqueta.
3. **Un `free` por cada `malloc`** (desde el Lab 07). Un `fclose` por cada `fopen` (desde el 10).
4. **La entrada de teclado se lee con `get_int` o `get_texto`**, nunca con `scanf` a secas.
5. **Comentarios sin acentos** en los `.c` y `.h`: la consola de Windows los muestra mal.
6. **Commits pequeños y con mensaje que diga algo.** `"avance"` no dice nada;
   `"Lab 07: inventario crece con realloc"` sí.
7. **No toques lo que viene dado** (`entrada`, `tests/`). Si algo dado falla, avísale al profesor.

---

## Si algo no funciona

| Síntoma | Causa probable |
|---|---|
| `make: command not found` | estás en PowerShell: usa `compilar.bat`, o abre la terminal UCRT64 |
| `undefined reference to 'mcd'` | el `.h` promete la función pero falta su `.c`, o la escribiste con otro nombre |
| `implicit declaration of function` | falta el `#include` del `.h` |
| `multiple definition of` | incluiste un `.c`, o a un `.h` le falta el include guard |
| las pruebas no compilan | algún módulo tuyo tiene errores: `make` primero, y arregla de arriba hacia abajo |
