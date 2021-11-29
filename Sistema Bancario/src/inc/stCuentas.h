#include <stdlib.h>
#include <stdio.h>
#include "eb_INPUT.h"
#include "stCliente.h"
#include "LinkedList.h"

#ifndef STCUENTAS_H_
#define STCUENTAS_H_

//inicio struct
typedef struct
{
	int idCuenta;
	int idCliente;
	int nip;
	float saldo;

}eCuentas;
//fin struct

//-------------------------//

//inicio prototipos
eCuentas* cu_new();
eCuentas* cu_newParametros( char* idCuentaStr, char* idCuentasStr, char* nipStr,char* saldoStr);
int cu_delete(eCuentas* this);
int cu_setEverything(eCuentas* this, int idCuentaStr, int idClienteStr, int nipStr, float saldoStr);
int cu_getEverything(eCuentas* this, int* idCuentas, int* idCliente, int* nip, float* saldo);

// --------- //

int cu_setIdCuenta(eCuentas* this, int id);
int cu_getIdCuenta(eCuentas* this, int* id);
int cu_setIdCliente(eCuentas* this, int id);
int cu_getIdCliente(eCuentas* this, int* id);
int cu_setNIP(eCuentas* this, int nip);
int cu_getNIP(eCuentas* this, int* nip);
int cu_setSaldo(eCuentas* this, float saldo);
int cu_getSaldo(eCuentas* this, float* saldo);

// --------- //
int cu_IDlatest(LinkedList* pArrayListCuentas);
int cu_IDincrease(int* id);
int cu_mostrarUnCuentas(eCuentas* pCuentas, eCliente* pCliente);
eCuentas* cu_searchID(LinkedList* pArrayListCuenta, int id);
eCuentas* cu_solicitarCuenta(LinkedList* pArrayCuentas, char* mensaje);
int cu_soliciarNIP(eCuentas* pCuentas);
float cu_solicitarRetiro(eCuentas* pCuentas, char* mensaje, char* mensajeError);
int cu_sumar(eCuentas* pCuentas, float cantidadSumar);
int cu_restar(eCuentas* pCuentas, float cantidadRestar);
eCuentas* cu_searchIdCliente(LinkedList* pArrayCuentas, int idCliente);

//fin prototipos

#endif /* STCUENTAS_H_ */
