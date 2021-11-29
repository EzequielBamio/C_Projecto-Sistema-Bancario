#include <stdio.h>
#include <stdlib.h>
#include "inc/stCliente.h"
#include "inc/stCuentas.h"
#include "inc/stMovimientos.h"
#include "inc/Controller.h"
#include "inc/eb_INPUT.h"
#include "inc/Menus.h"
#include "inc/LinkedList.h"

int controller_registroClientes(LinkedList* pArrayCliente)
{
	int rtn;
	int rgt_id;
	int rgt_edad;
	int rgt_telefono;
	char rgt_nombres[ARRAY_SIZE];
	char rgt_ciudad[ARRAY_SIZE];
	char rgt_direccion[ARRAY_SIZE];
	eCliente* pCliente;
	pCliente = cl_new();

	rtn = FALSE;
	if(pArrayCliente != NULL)
	{
		if(eb_getNombreApellido(rgt_nombres, "[*] INGRESE EL NOMBRE:\n-> ", "[*] INGRESE EL APELLIDO:\n-> ",ARRAY_SIZE) == TRUE)
		{
			if(eb_getString(rgt_ciudad, "[*] INGRESE LA CIUDAD:\n-> ", ARRAY_SIZE) == TRUE)
			{
				if(eb_getString(rgt_direccion, "[*] INGRESE LA DIRECCION:\n-> ", ARRAY_SIZE) == TRUE)
				{
					if(eb_getIntPositive(&rgt_edad, "[*] INGRESE LA EDAD:\n-> ") == TRUE)
					{
						if(eb_getIntPositive(&rgt_telefono, "[*] INGRESE EL TELEFONO:\n-> ") == TRUE)
						{
							if(eb_getContinuar("[*] QUIERE CONFIRMAR LOS DATOS REGISTRADOS? [1] SI - [0] NO:\n-> ") == TRUE)
							{
								rgt_id = cl_IDlatest(pArrayCliente);
								cl_IDincrease(&rgt_id);
								if(cl_setEverything(pCliente, rgt_id, rgt_nombres, rgt_ciudad, rgt_direccion, rgt_edad, rgt_telefono) == TRUE)
								{
									ll_add(pArrayCliente, pCliente);
									rtn = TRUE;
								}
							}
						}
					}
				}
			}
		}
	}


	return rtn;
}

int controller_consultaClientes(LinkedList* pArrayCliente)
{
	int rtn;
	int tList;
	char nombreIngresado[ARRAY_SIZE];
	eCliente* pAuxCliente;

	rtn = FALSE;
	tList = ll_len(pArrayCliente);
	if(tList == 0)
	{
		puts("[*] NO HAY CLIENTES CARGADOS");
	}else
	{
		if(pArrayCliente != NULL)
		{
			do
			{
				eb_getNombreApellido(nombreIngresado, "[*] INGRESE EL NOMBRE:\n-> ", "[*] INGRESE EL APELLIDO:\n-> ", ARRAY_SIZE);
				pAuxCliente = cl_searchNombre(pArrayCliente, nombreIngresado);
				if(pAuxCliente != NULL)
				{
					rtn = cl_mostrarUnCliente(pAuxCliente);
				}else
				{
					if(eb_getContinuar("[ERROR] ES NOMBRE NO EXISTE. DESEA VOLVER A INTENTARLO? [1] SI - [0] NO:\n-> ") == 0)
					{
						rtn = NO;
					}
				}
			}while(rtn == FALSE);
		}
	}


	return rtn;
}

int controller_registroCuentas(LinkedList* pArrayCliente, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int rtn;
	int rgt_idCuentas;
	int rgt_idCliente;
	int rgt_nip;
	float rgt_saldo;
	eCuentas* pCuentas;
	pCuentas = cu_new();

	rtn = FALSE;
	if(pArrayCliente != NULL && pArrayCuentas != NULL)
	{
		do{
			if(eb_getIntPositive(&rgt_idCliente, "[*] INGRESE LA ID DEL CLIENTE:\n-> ") == TRUE)
			{
				if(cl_searchID(pArrayCliente, rgt_idCliente) != NULL)
				{
					if(eb_getClave(&rgt_nip, "[*] LA CLAVE DE 4 DIGITOS:\n-> " ) == TRUE)
					{
						if(eb_getFloatPositive(&rgt_saldo, "[*] INGRESE EL SALDO:\n-> ") == TRUE)
						{
							rgt_idCuentas = cu_IDlatest(pArrayCuentas);
							cu_IDincrease(&rgt_idCuentas);
							if(cu_setEverything(pCuentas, rgt_idCuentas, rgt_idCliente, rgt_nip, rgt_saldo) == TRUE)
							{
								ll_add(pArrayCuentas, pCuentas);
								controller_resgistroMovimientos(pArrayMovimientos, pCuentas->idCuenta, pCuentas->idCliente, SALDO_INICIAL, rgt_saldo);
								rtn = TRUE;
							}

						}
					}
				}else
				{
					if(eb_getContinuar("[ERROR] ESA ID NO EXISTE. DESEA VOLVER A INTENTARLO? [1] SI - [0] NO:\n-> ") == 0)
					{
						rtn = NO;
					}

				}
			}
		}while(rtn == FALSE);
	}

	return rtn;
}

int controller_consultaCuentas(LinkedList* pArrayCliente, LinkedList* pArrayCuentas)
{
	int rtn;
	int tList;
	int idCliente;
	eCuentas* pAuxCuentas;
	eCliente* pAuxCliente;

	rtn = FALSE;
	tList = ll_len(pArrayCliente);
	if(tList == 0)
	{
		puts("[*] NO HAY CUENTAS CARGADAS");
	}else
	{
		if(pArrayCliente != NULL && pArrayCuentas != NULL)
		{
			do{
				pAuxCuentas = cu_solicitarCuenta(pArrayCuentas, "[*] INGRESE LA ID DE LA CUENTA:\n-> ");
				if(pAuxCuentas != NULL)
				{
					cu_getIdCliente(pAuxCuentas, &idCliente);
					pAuxCliente = cl_searchID(pArrayCliente, idCliente);
					if(pAuxCliente != NULL)
					{
						rtn = cu_mostrarUnCuentas(pAuxCuentas, pAuxCliente);
					}else
					{
						if(eb_getContinuar("[ERROR] ESA ID NO EXISTE. DESEA VOLVER A INTENTARLO? [1] SI - [0] NO:\n-> ") == 0)
						{
							rtn = NO;
						}
					}
				}
			}while(rtn == FALSE);
		}
	}


	return rtn;
}

int controller_deposito(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int rtn;
	float de_cantidadDepositar;
	float de_cantidadActual;
	eCuentas* pAuxCuentas;
	rtn = FALSE;

	if(pArrayCuentas != NULL)
	{
		pAuxCuentas = cu_solicitarCuenta(pArrayCuentas, "[*] INGRESE LA ID DE LA CUENTA:\n-> ");
		if(pAuxCuentas != NULL)
		{
			if(eb_getFloatPositive(&de_cantidadDepositar, "[*] INGRESE LA CANTIDAD A DEPOSITAR:\n-> ") == TRUE)
			{
				if(eb_getContinuar("[*] DESEA CONFIRMAR EL DEPOSITO? [1] SI - [0] NO:\n-> ") == TRUE)
				{
					if(cu_getSaldo(pAuxCuentas, &de_cantidadActual) == TRUE)
					{
						controller_resgistroMovimientos(pArrayMovimientos, pAuxCuentas->idCuenta, pAuxCuentas->idCliente, DEPOSITO, de_cantidadDepositar);
						de_cantidadDepositar = de_cantidadActual + de_cantidadDepositar;
						cu_setSaldo(pAuxCuentas, de_cantidadDepositar);

						rtn = TRUE;
					}
				}
			}

		}
	}


	return rtn;
}

int controller_retiro(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int rtn;
	float re_cantidadRetiro;
	eCuentas* pAuxCuentas;
	rtn = FALSE;

	if(pArrayCuentas != NULL)
	{
		pAuxCuentas = cu_solicitarCuenta(pArrayCuentas, "[*] INGRESE LA ID DE LA CUENTA:\n-> ");
		if(pAuxCuentas != NULL)
		{
			if(cu_soliciarNIP(pAuxCuentas) == TRUE)
			{
				re_cantidadRetiro = cu_solicitarRetiro(pAuxCuentas, "[*] INGRESE LA CANTIDAD A RETIRAR:\n-> ", "[ERROR] LA CANTIDAD QUE DESEA RETIRAR EXCEDE AL SALDO DISPONIBLE, DESEA VOLVER A INGRESAR LA CANTIDAD A RETIRAR? [1] SI - [0] NO:\n-> ");
				if(re_cantidadRetiro > 0)
				{
					if(eb_getContinuar("[*] DESEA CONFIRMAR EL RETIRO? [1] SI - [0] NO:\n-> ") == TRUE)
					{
						if(cu_restar(pAuxCuentas, re_cantidadRetiro) == TRUE)
						{
							controller_resgistroMovimientos(pArrayMovimientos, pAuxCuentas->idCuenta, pAuxCuentas->idCliente, RETIRO, re_cantidadRetiro);
							rtn = TRUE;
						}
					}
				}
			}
		}
	}

	return rtn;
}

int controller_transferencia(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int rtn;
	eCuentas* pCuentaOrigen;
	eCuentas* pCuentaDestino;
	float tr_cantidadTransferir;
	rtn = FALSE;

	if(pArrayCuentas != NULL)
	{
		pCuentaOrigen = cu_solicitarCuenta(pArrayCuentas, "[*] INGRESE LA ID DE LA CUENTA ORIGEN:\n-> ");
		pCuentaDestino = cu_solicitarCuenta(pArrayCuentas, "[*] INGRESE LA ID DE LA CUENTA DESTINO:\n-> ");
		tr_cantidadTransferir = cu_solicitarRetiro(pCuentaOrigen, "[*] INGRESE LA CANTIDAD A TRANSFERIR:\n-> ", "[ERROR] LA CANTIDAD QUE DESEA TRANSFERIR EXCEDE AL SALDO DISPONIBLE, DESEA VOLVER A INGRESAR LA CANTIDAD A TRANSFERIR? [1] SI - [0] NO:\n-> ");
		if(tr_cantidadTransferir > 0)
		{
			if(eb_getContinuar("[*] DESEA CONFIRMAR LA TRANSFERENCIA? [1] SI - [0] NO:\n-> ") == TRUE)
			{
				if(cu_restar(pCuentaOrigen, tr_cantidadTransferir) == TRUE)
				{
					if(cu_sumar(pCuentaDestino, tr_cantidadTransferir) == TRUE)
					{
						controller_resgistroMovimientos(pArrayMovimientos, pCuentaOrigen->idCuenta, pCuentaOrigen->idCliente, TRANFERENCIA_REALIZADA, tr_cantidadTransferir);
						controller_resgistroMovimientos(pArrayMovimientos, pCuentaDestino->idCuenta, pCuentaDestino->idCliente, TRANFERENCIA_RECIBIDA, tr_cantidadTransferir);
						rtn = TRUE;
					}
				}
			}
		}
	}
	return rtn;
}

int controller_resgistroMovimientos(LinkedList* pArrayMovimientos, int idCuenta, int idCliente, int TipoMov, float monto)
{
	eMovimiento* pMovimiento;
	int rtn;
	char fecha[ARRAY_SIZE];
	pMovimiento = mv_new();
	rtn = FALSE;
	if(pArrayMovimientos != NULL && pMovimiento != NULL)
	{
		eb_getFecha(fecha);
		if(mv_setEverything(pMovimiento, idCuenta, idCliente, TipoMov, monto, fecha) == TRUE)
		{
			ll_add(pArrayMovimientos, pMovimiento);
		}
	}


	return rtn;
}

int controller_estadoCuenta(LinkedList* pArrayCliente, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int rtn;
	int ec_idCliente;
	char ec_nombres[ARRAY_SIZE];
	char ec_ciudad[ARRAY_SIZE];
	int ec_idCuenta;
	float ec_saldo;
	eCuentas* pAuxCuenta;
	eCliente* pAuxCliente;
	rtn = FALSE;
	if(pArrayMovimientos != NULL)
	{
		do{
			if(eb_getIntPositive(&ec_idCliente, "[*] INGRESE LA ID DEL CLIENTE:\n-> ") == TRUE)
			{
				pAuxCliente = cl_searchID(pArrayCliente, ec_idCliente);
				if(pAuxCliente != NULL)
				{
					cl_getNombres(pAuxCliente, ec_nombres);
					cl_getCiudad(pAuxCliente, ec_ciudad);
					pAuxCuenta = cu_searchIdCliente(pArrayCuentas, ec_idCliente);
					if(pAuxCuenta != NULL)
					{
						cu_getIdCuenta(pAuxCuenta, &ec_idCuenta);
						cu_getSaldo(pAuxCuenta, &ec_saldo);
						printf("\n[ESTADO DE CUENTA]\n");
						printf("\n\n[*] ID CLIENTE:     %d\n[*] NOMBRE CLIENTE: %s   \n[*] CIUDAD:         %s \n[*] ID CUENTA:      %d\n[*] SALDO ACTUAL:   $%.3f\n\n", ec_idCliente, ec_nombres, ec_ciudad, ec_idCuenta, ec_saldo);
						mv_mostrarMovimientos(pArrayMovimientos, ec_idCliente);
						rtn = TRUE;
					}
				}else
				{
					if(eb_getContinuar("[ERROR] ESA ID NO EXISTE. DESEA VOLVER A INTENTARLO? [1] SI - [0] NO:\n-> ") == 0)
					{
						rtn = NO;
					}

				}
			}
		}while(rtn == FALSE);
	}

	return rtn;
}

int controller_guardarDatosClientes(LinkedList* pArrayCliente, char* direccion)
{
	int rtn;
	int tList;
	int i;
	int gc_idCliente;
	char gc_nombres[ARRAY_SIZE];
	char gc_ciudad[ARRAY_SIZE];
	char gc_direccion[ARRAY_SIZE];
	int gc_edad;
	int gc_telefono;
	FILE* pArchivo;
	eCliente* pCliente;
	rtn = FALSE;
	pArchivo = fopen(direccion, "w");

	if(pArrayCliente != NULL)
	{
		tList = ll_len(pArrayCliente);
		fprintf(pArchivo,"IDCLIENTE,NOMBRE,CIUDAD,DIRECCION,EDAD,TELEFONO\n");
		for(i = 0; i <tList; i++)
		{
			pCliente = ll_get(pArrayCliente, i);
			if(pCliente != NULL)
			{
				if(cl_getEverything(pCliente, &gc_idCliente, gc_nombres, gc_ciudad, gc_direccion, &gc_edad, &gc_telefono) == TRUE)
				{
					fprintf(pArchivo,"%d,%s,%s,%s,%d,%d\n", gc_idCliente, gc_nombres, gc_ciudad, gc_direccion, gc_edad, gc_telefono);
				}
			}
		}
		rtn = TRUE;
	}

	fclose(pArchivo);

	return rtn;
}

int controller_guardarDatosCuentas(LinkedList* pArrayCuentas, char* direccion)
{
	int rtn;
	int i;
	int tList;
	int gc_idCuenta;
	int gc_idCliente;
	int gc_nip;
	float gc_saldo;
	FILE* pArchivo;
	eCuentas* pCuenta;
	rtn = FALSE;
	pArchivo = fopen(direccion, "w");

	if(pArrayCuentas != NULL)
	{
		tList = ll_len(pArrayCuentas);
		fprintf(pArchivo, "IDCUENTA, IDCLIENTE, NIP, SALDO\n");
		for(i = 0; i < tList; i++)
		{
			pCuenta = ll_get(pArrayCuentas, i);
			if(pCuenta != NULL)
			{
				if(cu_getEverything(pCuenta, &gc_idCuenta, &gc_idCliente, &gc_nip, &gc_saldo) == TRUE)
				{
					fprintf(pArchivo, "%d,%d,%d,%.3f\n", gc_idCuenta, gc_idCliente, gc_nip, gc_saldo);
				}
			}
		}
		rtn = TRUE;
	}
	fclose(pArchivo);
	return rtn;
}

int controller_guardarDatosMovimientos(LinkedList* pArrayMovimiento, char* direccion)
{
	int rtn;
	int i;
	int tList;
	int gm_idCuenta;
	int gm_idCliente;
	int gm_idTipoMov;
	float gm_monto;
	char gm_fecha[ARRAY_SIZE];
	FILE* pArchivo;
	eMovimiento* pMovimiento;
	rtn = FALSE;
	pArchivo = fopen(direccion, "w");

	if(pArrayMovimiento != NULL)
	{
		tList = ll_len(pArrayMovimiento);
		fprintf(pArchivo, "IDCUENTA, IDCLIENTE, IDTIPOMOV, MONTO, FECHA\n");
		for(i = 0; i < tList; i++)
		{
			pMovimiento = ll_get(pArrayMovimiento, i);
			if(pMovimiento != NULL)
			{
				if(mv_getEverything(pMovimiento, &gm_idCuenta, &gm_idCliente, &gm_idTipoMov, &gm_monto, gm_fecha) == TRUE)
				{
					fprintf(pArchivo, "%d,%d,%d,%.3f,%s\n", gm_idCuenta, gm_idCliente, gm_idTipoMov, gm_monto, gm_fecha);
				}
			}
		}
		rtn = TRUE;
	}
	fclose(pArchivo);
	return rtn;
}
