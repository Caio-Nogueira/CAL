/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if (n == 0) return 1;
	return n*factorialRecurs(n-1);

}

int factorialDinam(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++){
	    result *= i;
	}
	return result;
}

/*
 * Complexidade Temporal
 * Ambos os algoritmos têm complexidade linear.
 *
 * Complexidade espacial
 * O algoritmo iterativo (dinâmico) possui complexidade espacial linear, enquanto que a complexidade espacial
 * do algoritmo recursivo será exponencial
 * */