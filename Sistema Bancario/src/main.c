/*
 ============================================================================
 SISTEMA BANCARIO.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inc/LinkedList.h"
#include "inc/Menus.h"


int main(void) {
	setbuf(stdout, NULL);

	LinkedList* pListaClientes = ll_newLinkedList();
	LinkedList* pListaCuentas = ll_newLinkedList();
	LinkedList* pListaMovimientos = ll_newLinkedList();
	me_MenuPrincipal(pListaClientes, pListaCuentas, pListaMovimientos);


	return EXIT_SUCCESS;
}
