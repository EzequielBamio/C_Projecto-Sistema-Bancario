#include "eb_INPUT.h"


#ifndef STMOVIMIENTOS_H_
#define STMOVIMIENTOS_H_

//inicio struct
typedef struct
{
	int idCuenta;
	int idCliente;
	int idTipoMov;
	float monto;
	char fecha[ARRAY_SIZE];

}eMovimiento;
//fin struct

//-------------------------//

//inicio prototipos
eMovimiento* mv_new();
eMovimiento* mv_newParametros(char* idCuentaStr, char* idClienteStr, char* idTipoMovStr, char* montoStr, char* fecha);
int mv_delete(eMovimiento* this);
int mv_setEverything(eMovimiento* this, int idCuentaStr, int idClienteStr, int idTipoMovStr, float montoStr, char* fecha);
int mv_getEverything(eMovimiento* this, int* idCuenta, int* idCliente, int* idTipoMov, float* monto, char* fecha);

// --------- //
int mv_setIdCliente(eMovimiento* this, int id);
int mv_getIdCliente(eMovimiento* this, int* id);
int mv_setIdCuenta(eMovimiento* this, int id);
int mv_getIdCuenta(eMovimiento* this, int* id);
int mv_setIdTipoMov(eMovimiento* this, int id);
int mv_getIdTipoMov(eMovimiento* this, int* id);
int mv_setMonto(eMovimiento* this, float monto);
int mv_getMonto(eMovimiento* this, float* monto);
int mv_setFecha(eMovimiento* this, char* fecha);
int mv_getFecha(eMovimiento* this, char* fecha);

// --------- //

int mv_mostrarMovimientos(LinkedList* this, int id);
int mv_mostrarUnMovimiento(eMovimiento* this);















//fin prototipos

#endif /* STMOVIMIENTOS_H_ */
