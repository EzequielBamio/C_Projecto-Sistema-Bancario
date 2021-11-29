#include "inc/stMovimientos.h"

eMovimiento* mv_new()
{
	eMovimiento* pMovimiento;

	pMovimiento = (eMovimiento*) malloc(sizeof(eMovimiento));

	return pMovimiento;
}

eMovimiento* mv_newParametros(char* idCuentaStr, char* idClienteStr, char* idTipoMovStr, char* montoStr, char* fecha)
{
	eMovimiento* pMovimiento;
	pMovimiento = mv_new();

	if(pMovimiento != NULL)
	{
		mv_setEverything(pMovimiento, atoi(idCuentaStr), atoi(idClienteStr), atoi(idTipoMovStr), atof(montoStr), fecha);
	}

	return pMovimiento;
}

int mv_delete(eMovimiento* this)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		free(this);
		rtn = TRUE;
	}

	return rtn;
}

int mv_setEverything(eMovimiento* this, int idCuentaStr, int idClienteStr, int idTipoMovStr, float montoStr, char* fecha)
{
	int rtn;
	rtn = FALSE;

	if(mv_setIdCuenta(this, idCuentaStr) &&
	   mv_setIdCliente(this, idClienteStr) &&
	   mv_setIdTipoMov(this, idTipoMovStr) &&
	   mv_setMonto(this, montoStr) &&
	   mv_setFecha(this, fecha))
	{
		rtn = TRUE;
	}

	return rtn;

}
int mv_getEverything(eMovimiento* this, int* idCuenta, int* idCliente, int* idTipoMov, float* monto, char* fecha)
{
	int rtn;
	rtn = FALSE;

	if(mv_getIdCuenta(this, idCuenta) &&
	   mv_getIdCliente(this, idCliente) &&
	   mv_getIdTipoMov(this, idTipoMov) &&
	   mv_getMonto(this, monto) &&
	   mv_getFecha(this, fecha))
	{
		rtn = TRUE;
	}

	return rtn;

}
// --------- //

int mv_setIdCliente(eMovimiento* this, int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idCliente = id;
		rtn = TRUE;
	}

	return rtn;
}
int mv_getIdCliente(eMovimiento* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*id = this->idCliente;
		rtn = TRUE;
	}

	return rtn;
}

//

int mv_setIdCuenta(eMovimiento* this, int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id > 0)
	{
		this->idCuenta = id;
		rtn = TRUE;
	}

	return rtn;
}
int mv_getIdCuenta(eMovimiento* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*id = this->idCuenta;
		rtn = TRUE;
	}

	return rtn;
}

//
int mv_setIdTipoMov(eMovimiento* this, int id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		this->idTipoMov = id;
		rtn = TRUE;
	}

	return rtn;
}
int mv_getIdTipoMov(eMovimiento* this, int* id)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && id != NULL)
	{
		*id = this->idTipoMov;
		rtn = TRUE;
	}

	return rtn;
}

//
int mv_setMonto(eMovimiento* this, float monto)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && monto > -1)
	{
		this->monto = monto;
		rtn = TRUE;
	}

	return rtn;
}
int mv_getMonto(eMovimiento* this, float* monto)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*monto = this->monto;
		rtn = TRUE;
	}

	return rtn;
}

//
int mv_setFecha(eMovimiento* this, char* fecha)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && fecha != NULL)
	{
		strcpy(this->fecha, fecha);
		rtn = TRUE;
	}

	return rtn;
}
int mv_getFecha(eMovimiento* this, char* fecha)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && fecha != NULL)
	{
		strcpy(fecha, this->fecha);
		rtn = TRUE;
	}

	return rtn;
}

// --------- //

int mv_mostrarMovimientos(LinkedList* this, int id)
{
	int rtn;
	int i;
	int tList;
	int idAux;
	eMovimiento* pMovimiento;
	tList = ll_len(this);
	rtn = FALSE;
	if(this != NULL)
	{
		for(i = 0; i < tList; i++)
		{
			pMovimiento = ll_get(this, i);
			mv_getIdCliente(pMovimiento, &idAux);
			if(id == idAux)
			{
				mv_mostrarUnMovimiento(pMovimiento);
			}
		}
		rtn = TRUE;
	}

	return rtn;
}

int mv_mostrarUnMovimiento(eMovimiento* this)
{
	int rtn;
	int mo_idCliente;
	int mo_idCuenta;
	int mo_idTipoMov;
	float mo_monto;
	char mo_tipoMov[ARRAY_SIZE];
	char mo_fecha[ARRAY_SIZE];
	rtn = FALSE;

	if(this != NULL)
	{
		mv_getEverything(this, &mo_idCuenta, &mo_idCliente, &mo_idTipoMov, &mo_monto, mo_fecha);
		eb_validarTipoMov(mo_tipoMov, mo_idTipoMov);
		printf("FECHA MOV            TIPO MOV               SALDO\n");
		printf("%-20s %-22s $%-10.3f\n\n", mo_fecha, mo_tipoMov, mo_monto);
		rtn = TRUE;
	}

	return rtn;
}


