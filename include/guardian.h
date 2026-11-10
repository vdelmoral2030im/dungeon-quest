/* ===========================================================================
 * guardian.h  -  La puerta del dungeon: adivina la clave.            [Lab 06]
 * ---------------------------------------------------------------------------
 * El guardian piensa un numero del 1 al 100. Tienes pocos intentos.
 *
 * Fijate en que el modulo tiene DOS funciones:
 *   - guardian_comparar: solo LOGICA. No lee ni imprime nada.
 *   - guardian_jugar:    la PARTIDA. Lee del teclado e imprime.
 *
 * Separarlas es lo que permite PROBAR la logica automaticamente
 * (tests/test_lab06.c no puede escribir por ti en el teclado, pero si
 * puede llamar a guardian_comparar). Vas a ver este patron todo el semestre.
 * ========================================================================= */

#ifndef GUARDIAN_H
#define GUARDIAN_H

/* Compara un intento con la clave secreta. Devuelve:
 *    1  si la clave es MAS ALTA que el intento
 *   -1  si la clave es MAS BAJA que el intento
 *    0  si acertaste */
int guardian_comparar(int secreto, int intento);

/* Juega una partida: elige una clave con rand() % 100 + 1 y da `intentos`
 * oportunidades, respondiendo "mas alto" / "mas bajo".
 * Devuelve 1 si el jugador acerto, 0 si se le acabaron los intentos
 * (en ese caso revela la clave). */
int guardian_jugar(int intentos);

#endif /* GUARDIAN_H */
