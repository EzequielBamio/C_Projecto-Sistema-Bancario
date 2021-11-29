#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

#ifndef INC_MENUS_H_
#define INC_MENUS_H_

//prototipos
int me_subMenuGuardar(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
void me_subMenuTransacciones(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int me_subMenuCuentas(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int me_subMenuCliente(LinkedList* pArrayClientes);
void me_MenuPrincipal(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
//

#endif /* INC_MENUS_H_ */
