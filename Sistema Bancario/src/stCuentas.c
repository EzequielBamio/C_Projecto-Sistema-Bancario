#include "inc/stCuentas.h"

eCuentas* cu_new()
{
	eCuentas* pCuentas;

	pCuentas = (eCuentas*) malloc(sizeof(eCuentas));

	return pCuentas;
}

eCuentas* cu_newParametros( char* idCuentaStr, char* idCuentasStr, char* nipStr,char* saldoStr)
{
	eCuentas* pCuentas;
	pCuentas = cu_new();

	if(pCuentas != NULL)
	{
		cu_setEverything(pCuentas, atoi(idCuentaStr), atoi(idCuentasStr), atoi(nipStr), atof(saldoStr));
	}

	return pCuentas;
}

int cu_delete(eCuentas* this)
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

int cu_setEverything(eCuentas* this, int idCuenta, int idCliente, int nip, float saldo)
{
	int rtn;
	rtn = FALSE;

	if(cu_setIdCuenta(this,idCuenta) &&
	   cu_setIdCliente(this, idCliente) &&
	   cu_setNIP(this,nip) &&
	   cu_setSaldo(this, saldo))
	{
		rtn = TRUE;
	}

	return rtn;

}
int cu_getEverything(eCuentas* this, int* idCuentas, int* idCliente, int* nip, float* saldo)
{
	int rtn;
	rtn = FALSE;

	if(cu_getIdCuenta(this, idCuentas) &&
	   cu_getIdCliente(this, idCliente) &&
	   cu_getNIP(this, nip) &&
 	   cu_getSaldo(this, saldo))
	{
		rtn = TRUE;
	}

	return rtn;

}
// --------- //

int cu_setIdCuenta(eCuentas* this, int id)
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
int cu_getIdCuenta(eCuentas* this, int* id)
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

int cu_setIdCliente(eCuentas* this, int id)
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
int cu_getIdCliente(eCuentas* this, int* id)
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

int cu_setNIP(eCuentas* this, int nip)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && nip > -1)
	{
		this->nip = nip;
		rtn = TRUE;
	}

	return rtn;
}
int cu_getNIP(eCuentas* this, int* nip)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*nip = this->nip;
		rtn = TRUE;
	}

	return rtn;
}

//

int cu_setSaldo(eCuentas* this, float saldo)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && saldo > -1)
	{
		this->saldo = saldo;
		rtn = TRUE;
	}

	return rtn;
}
int cu_getSaldo(eCuentas* this, float* saldo)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*saldo = this->saldo;
		rtn = TRUE;
	}

	return rtn;
}

//


// --------- //

int cu_IDlatest(LinkedList* pArrayListCuentas)
{
	eCuentas* pCuentas;
	int i;
	int id;
	int ultimoID;
	int tCuentas;

	ultimoID = 0;
	pCuentas = cu_new();
	tCuentas = ll_len(pArrayListCuentas);

	for(i = 0; i < tCuentas; i++)
	{
		pCuentas = ll_get(pArrayListCuentas, i);
		cu_getIdCuenta(pCuentas, &id);
		if(ultimoID < id)
		{
			ultimoID = id;
		}
	}

	return ultimoID;

}

int cu_IDincrease(int* id)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return *id += 1;
}

eCuentas* cu_searchID(LinkedList* pArrayListCuenta, int id)
{
	eCuentas* pCuenta;
	int auxID;
	int tList;
	int i;
	eCuentas* rtn;
	rtn = NULL;

	if(pArrayListCuenta != NULL)
	{
		tList = ll_len(pArrayListCuenta);

		for(i = 0; i < tList; i++)
		{
			pCuenta = ll_get(pArrayListCuenta, i);
			cu_getIdCuenta(pCuenta, &auxID);
			if(auxID == id)
			{
				rtn = pCuenta;
				break;
			}
		}
	}
	return rtn;
}


int cu_mostrarUnCuentas(eCuentas* pCuentas, eCliente* pCliente)
{
	int mc_idCuentas;
	int mc_idCliente;
	int mc_nip;
	float mc_saldo;
	char mc_nombreCliente[ARRAY_SIZE];
	int rtn;

	cu_getEverything(pCuentas, &mc_idCuentas, &mc_idCliente, &mc_nip, &mc_saldo);
	cl_getNombres(pCliente, mc_nombreCliente);
	eb_HeadboardCuentas();
	printf("| %-11d | %-17s | %-17d | $%-14.3f |\n", mc_idCuentas, mc_nombreCliente, mc_nip, mc_saldo);
	rtn = TRUE;

	return rtn;

}

eCuentas* cu_solicitarCuenta(LinkedList* pArrayCuentas, char* mensaje)
{
	eCuentas* rtn;
	int idIngresado;
	eCuentas* pAuxCuentas;
	rtn = NULL;
	if(pArrayCuentas != NULL)
	{
		eb_getIntPositive(&idIngresado, mensaje);
		pAuxCuentas = cu_searchID(pArrayCuentas, idIngresado);
		if(pAuxCuentas != NULL)
		{
			rtn = pAuxCuentas;
		}
	}

	return rtn;
}

int cu_soliciarNIP(eCuentas* pCuentas)
{
	int rtn;
	int actualNIP;
	int auxNIP;
	rtn = FALSE;

	if(pCuentas != NULL)
	{
		if(eb_getClave(&auxNIP, "[*] INGRESE LA CLAVE DE 4 DIGITOS:\n-> ") == TRUE)
		{
			if(cu_getNIP(pCuentas, &actualNIP) == TRUE)
			{
				if(auxNIP == actualNIP)
				{
					rtn = TRUE;
				}
			}
		}
	}

	return rtn;
}

float cu_solicitarRetiro(eCuentas* pCuentas, char* mensaje, char* mensajeError)
{
	int rtn;
	float re_cantidadRetiro;
	float re_cantidadActual;
	rtn = FALSE;

	if(pCuentas != NULL)
	{
		do
		{
			if(eb_getFloatPositive(&re_cantidadRetiro, mensaje) == TRUE)
			{
				if(cu_getSaldo(pCuentas, &re_cantidadActual) == TRUE)
				{
					if(re_cantidadRetiro < re_cantidadActual)
					{
						rtn = re_cantidadRetiro;
					}else
					{
						if(eb_getContinuar(mensajeError) != TRUE)
						{
							rtn = NO;
						}
					}
				}
			}
		}while(rtn == FALSE);
	}


	return rtn;
}

int cu_restar(eCuentas* pCuentas, float cantidadRestar)
{
	int rtn;
	float re_cantidadActual;
	rtn = FALSE;
	if(pCuentas != NULL && cantidadRestar > 0)
	{
		if(cu_getSaldo(pCuentas, &re_cantidadActual) == TRUE)

		cantidadRestar = re_cantidadActual - cantidadRestar;
		cu_setSaldo(pCuentas, cantidadRestar);
		rtn = TRUE;
	}

	return rtn;
}

int cu_sumar(eCuentas* pCuentas, float cantidadSumar)
{
	int rtn;
	float re_cantidadActual;
	rtn = FALSE;
	if(pCuentas != NULL && cantidadSumar > 0)
	{
		if(cu_getSaldo(pCuentas, &re_cantidadActual) == TRUE)

		cantidadSumar = re_cantidadActual + cantidadSumar;
		cu_setSaldo(pCuentas, cantidadSumar);
		rtn = TRUE;
	}

	return rtn;
}

eCuentas* cu_searchIdCliente(LinkedList* pArrayCuentas, int idCliente)
{
	eCuentas* rtn;
	int i;
	int tList;
	int auxIdCliente;
	eCuentas* pCuenta;
	tList = ll_len(pArrayCuentas);
	rtn = NULL;
	if(pArrayCuentas != NULL)
	{
		for(i = 0; i < tList; i++)
		{
			pCuenta = ll_get(pArrayCuentas, i);
			cu_getIdCliente(pCuenta, &auxIdCliente);
			if(auxIdCliente == idCliente)
			{
				rtn = pCuenta;
			}
		}
	}

	return rtn;
}
