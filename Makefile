# ===========================================================================
# Makefile  -  Dungeon Quest
# ---------------------------------------------------------------------------
# Funciona en Mac, Linux y en la terminal "MSYS2 UCRT64" de Windows.
# Si estas en PowerShell o en cmd, usa compilar.bat y probar.bat.
#
#   make           compila el juego  ->  ./dungeon
#   make test      compila y corre todas las pruebas de tests/
#   make correr    compila y abre el juego
#   make limpiar   borra lo compilado
# ===========================================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -Iinclude
LDLIBS  = -lm

PROGRAMA = dungeon

# Todos los modulos menos main.c (las pruebas traen su propio main)
MODULOS  = $(filter-out src/main.c,$(wildcard src/*.c))
CABECERAS = $(wildcard include/*.h)

# Una prueba por cada tests/test_*.c
PRUEBAS  = $(patsubst tests/%.c,bin/%,$(wildcard tests/test_*.c))

all: $(PROGRAMA)

$(PROGRAMA): src/main.c $(MODULOS) $(CABECERAS)
	$(CC) $(CFLAGS) -o $(PROGRAMA) src/main.c $(MODULOS) $(LDLIBS)

bin/test_%: tests/test_%.c tests/prueba.h $(MODULOS) $(CABECERAS)
	@mkdir -p bin
	$(CC) $(CFLAGS) -Itests -o $@ $< $(MODULOS) $(LDLIBS)

test: $(PRUEBAS)
	@fallas=0; \
	for t in $(PRUEBAS); do ./$$t || fallas=$$((fallas+1)); done; \
	if [ $$fallas -eq 0 ]; then echo "  TODAS LAS PRUEBAS PASAN"; \
	else echo "  Archivos de prueba con fallas: $$fallas"; exit 1; fi

correr: $(PROGRAMA)
	./$(PROGRAMA)

limpiar:
	rm -rf $(PROGRAMA) $(PROGRAMA).exe bin

.PHONY: all test correr limpiar
