#include "inc/Menus.h"
#include "inc/eb_INPUT.h"
#include "inc/LinkedList.h"
#include "inc/Controller.h"
#include "inc/stMovimientos.h"

int me_subMenuGuardar(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int opcion;
	int rtn;
	char direccion[ARRAY_SIZE];
	char auxDireccion[ARRAY_SIZE];
	rtn = 0;

	do
	{
		printf("\n[*] MENU GUARDAR DATOS\n\n");
		printf("[1] CLIENTES\n");
		printf("[2] CUENTAS\n");
		printf("[3] MOVIMIENTOS\n");
		printf("[4] REGRESAR AL MENU PRINCIPAL\n");

		eb_getInt(&opcion, "\n[*] INGRESE UNA OPCION.\n-> ");

		switch(opcion)
		{
		case 1:
			strcpy(direccion, "../DatosClientes/");
			if(eb_getArchivo(auxDireccion, "[*] INGRESE EL NOMBRE DEL ARCHIVO QUE DESEA GUARDAR LOS DATOS DEL LOS CLIENTES:\n-> ", ARRAY_SIZE) == TRUE)
			{
				strcat(direccion, auxDireccion);
				if(controller_guardarDatosClientes(pArrayClientes, direccion) == TRUE)
				{
					puts("[*] LOS DATOS DE CLIENTES SE GUARDARON CORRECTAMENTE");
				}
			}
			strcpy(direccion, " ");
			strcpy(auxDireccion, " ");
			break;
		case 2:
			strcpy(direccion, "../DatosCuentas/");
			if(eb_getArchivo(auxDireccion, "[*] INGRESE EL NOMBRE DEL ARCHIVO QUE DESEA GUARDAR LOS DATOS DEL LOS CUENTAS:\n-> ", ARRAY_SIZE) == TRUE)
			{
				strcat(direccion, auxDireccion);
				if(controller_guardarDatosCuentas(pArrayCuentas, direccion) == TRUE)
				{
					puts("[*] LOS DATOS DE CUENTAS SE GUARDARON CORRECTAMENTE");
				}
			}
			strcpy(direccion, " ");
			strcpy(auxDireccion, " ");
			break;
		case 3:
			strcpy(direccion, "../DatosMovimientos/");
			if(eb_getArchivo(auxDireccion, "[*] INGRESE EL NOMBRE DEL ARCHIVO QUE DESEA GUARDAR LOS DATOS DEL LOS MOVIMIENTOS:\n-> ", ARRAY_SIZE) == TRUE)
			{
				strcat(direccion, auxDireccion);
				if(controller_guardarDatosMovimientos(pArrayMovimientos, direccion) == TRUE)
				{
					puts("[*] LOS DATOS DE MOVIMIENTOS SE GUARDARON CORRECTAMENTE");
				}
			}
			strcpy(direccion, " ");
			strcpy(auxDireccion, " ");
			break;
		case 4:
			opcion = 4;
			break;
		}
	}while(opcion != 4);

	return rtn;
}

void me_subMenuTransacciones(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int opcion;

	do
	{
		printf("\n[*] MENU TRANSACCIONES\n\n");
		printf("[1] DEPOSITO\n");
		printf("[2] RETIRO\n");
		printf("[3] REGRESAR AL MENU PRINCIPAL\n");

		eb_getInt(&opcion, "\n[*] INGRESE UNA OPCION.\n-> ");

		switch(opcion)
		{
		case 1:
			if(controller_deposito(pArrayCuentas, pArrayMovimientos) == TRUE)
			{
				puts("[*] SE COMPLETO LA TRANSACCION EXITOSAMENTE!");
			}else
			{
				puts("[*] SE CANCELO LA TRANSACCION.");
			}
			break;
		case 2:
			if(controller_retiro(pArrayCuentas, pArrayMovimientos) == TRUE)
			{
				puts("[*] SE COMPLETO EL RETIRO EXITOSAMENTE!");
			}else
			{
				puts("[*] SE CANCELO EL RETIRO.");
			}
			break;
		case 3:
			opcion = 3;
			break;
		}
	}while(opcion != 3);


}

int me_subMenuCuentas(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int opcion;
	int rtn;
	rtn = 0;

	do
	{
		printf("\n[*] MENU CUENTAS\n\n");
		printf("[1] REGISTRO\n");
		printf("[2] CONSULTA\n");
		printf("[3] REGRESAR AL MENU PRINCIPAL\n");

		eb_getInt(&opcion, "\n[*] INGRESE UNA OPCION.\n-> ");

		switch(opcion)
		{
		case 1:
			if(controller_registroCuentas(pArrayClientes, pArrayCuentas, pArrayMovimientos) == TRUE)
			{
				puts("[*] LOS DATOS SE REGISTRARON CORRECTAMENTE!");
				rtn++;
			}else
			{
				puts("[*] SE CANCELO EL REGISTRO DE DATOS");
			}
			break;
		case 2:
			if(controller_consultaCuentas(pArrayClientes, pArrayCuentas) != TRUE)
			{
				puts("[*] SE CANCELO LA CONSULTA");
			}
			break;
		case 3:
			opcion = 3;
			break;
		}
	}while(opcion != 3);

	return rtn;
}

int me_subMenuCliente(LinkedList* pArrayClientes)
{
	int opcion;
	int rtn;
	rtn = 0;

	do
	{
		printf("\n[*] MENU CLIENTES\n\n");
		printf("[1] REGISTRO\n");
		printf("[2] CONSULTA\n");
		printf("[3] REGRESAR AL MENU PRINCIPAL\n");

		eb_getInt(&opcion, "\n[*] INGRESE UNA OPCION.\n-> ");

		switch(opcion)
		{
		case 1:
			if(controller_registroClientes(pArrayClientes) == TRUE)
			{
				puts("[*] LOS DATOS SE REGISTRARON CORRECTAMENTE!");
				rtn++;
			}else
			{
				puts("[*] SE CANCELO EL REGISTRO DE DATOS");
			}
			break;
		case 2:
			if(controller_consultaClientes(pArrayClientes) != TRUE)
			{
				puts("[*] SE CANCELO LA CONSULTA");
			}
			break;
		case 3:
			opcion = 3;
			break;
		}
	}while(opcion != 3);

	return rtn;

}//ARREGLAR LAS BANDERAS: USAR EL LL_LEN PARA SABER SI HAY CLIENTES / CUENTAS. (EN EL MENU PRINCIPAL)

void me_MenuPrincipal(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos)
{
	int opcion;
	int flag_rtnClientes;
	int flag_rtnCuentas;
	flag_rtnClientes = 0;
	flag_rtnCuentas = 0;

		do
		{
			printf("\n                                          [SISTEMA BANCARIO]\n\n");
			printf("[*] MENU PRINCIPAL.\n\n");
			printf("[1] CLIENTES.\n");
			printf("[2] CUENTAS.\n");
			printf("[3] DEPOSITOS/RETIROS.\n");
			printf("[4] TRANSFERENCIA.\n");
			printf("[5] ESTADO DE CUENTA.\n");
			printf("[6] GUARDAR DATOS.\n");
			printf("[7] SALIR.\n");

			eb_getInt(&opcion, "\n[*] INGRESE UNA OPCION.\n-> ");

			switch(opcion)
			{
			case 1:
				flag_rtnClientes += me_subMenuCliente(pArrayClientes);
				break;
			case 2:
				if(flag_rtnClientes > 0)
				{
					flag_rtnCuentas += me_subMenuCuentas(pArrayClientes, pArrayCuentas, pArrayMovimientos);
				}else
				{
					puts("[ERROR] DEBES CARGAR A UN CLIENTE");
				}
				break;
			case 3:
				if(flag_rtnCuentas > 0)
				{
					me_subMenuTransacciones(pArrayCuentas, pArrayMovimientos);
				}else
				{
					puts("[ERROR] DEBE HABER CARGADO MINIMO UNA CUENTAS");
				}
				break;
			case 4:
				if(flag_rtnCuentas > 1)
				{
					if(controller_transferencia(pArrayCuentas, pArrayMovimientos) == TRUE)
					{
						puts("[*] TRANSFERENCIA COMPLETADA!");
					}else
					{
						puts("[*] TRANSFERENCIA CANCELADA.");
					}
				}else
				{
					puts("[ERROR] DEBE HABER CARGADO MINIMO DOS CUENTAS");
				}
				break;
			case 5:
				if(flag_rtnCuentas > 0)
				{
					controller_estadoCuenta(pArrayClientes, pArrayCuentas, pArrayMovimientos);
				}else
				{
					puts("[ERROR] DEBE HABER CARGADO MINIMO UNA CUENTAS");
				}
				break;
			case 6:
				if(flag_rtnClientes > 0 || flag_rtnCuentas > 0)
				{
					me_subMenuGuardar(pArrayClientes, pArrayCuentas, pArrayMovimientos);
				}else
				{
					puts("[ERROR] DEBE HABER CARGADO MINIMO UNA CUENTAS O UN CLIENTE");
				}
				break;
			case 7:
				break;
			default:
				break;
			}

			eb_pulseToContinue();

		}while(opcion != 7);
}

