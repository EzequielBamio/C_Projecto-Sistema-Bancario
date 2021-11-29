//ACTUALIZADA: 14/06/2021
#include "inc/eb_INPUT.h"

int eb_validarTipoMov(char* tipoMov, int idTipoMov)
{
	int rtn;
	rtn = FALSE;
	if(tipoMov != NULL)
	{
		switch(idTipoMov)
		{
		case 0:
			strcpy(tipoMov, "DEPOSITO");
			break;
		case 1:
			strcpy(tipoMov, "RETIRO");
			break;
		case 2:
			strcpy(tipoMov, "TRANSFERENCIA RECIBIDA");
			break;
		case 3:
			strcpy(tipoMov, "TRANSFERENCIA REALIZADA");
			break;
		case 4:
			strcpy(tipoMov, "SALDO INICIAL");
			break;

		}
	}

	return rtn;
}

int eb_getFecha(char fecha[])
{
	time_t     now;
	struct tm *ts;
	int rtn;
	rtn = FALSE;

	if(fecha != NULL)
	{
	    now = time(0);
	    ts = localtime(&now);
	    strftime(fecha, 80, "%Y-%m-%d %H:%M:%S", ts);
	    rtn = TRUE;
	}

	return rtn;
}

//validacion
int esCaracter(char* pResultado)
{
    int i;
    int rtn;
	int tResultado;
	rtn = 0;
	i = 0;

	if(pResultado != NULL)
	{
		tResultado=strlen(pResultado);

		while (i < tResultado && rtn == 0)
		{
			if (isalpha(pResultado[i]) != 0)
			{
				i++;
			}
			else
			{
				rtn = TRUE;
			}
		}
	}

    return rtn;
}
int esCaracterConEspacio(char* pResultado)
{
	int i;
	int rtn;
	rtn = 1;

	if(strlen(pResultado) > 0)
	{
		for(i = 0; strlen(pResultado) > 0; i++)
		{
			if(isalpha(pResultado[i]) == 0)
			{
				if(isspace(pResultado[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}

	return rtn;
}
int esNumerica(char* pResultado)
{

	int i;
	int rtn;
	rtn = 1;
	if (strlen(pResultado) > 0)
	{
		for(i = 0; i < strlen(pResultado); i++)
		{
			if (isdigit(pResultado[i]) == 0)
			{
				if (i == 0)
				{
					if (pResultado[0] != '-')
					{
						rtn = 0;
						break;
					}
				}else
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}
	return rtn;
}
int esFlotante(char* pResultado)
{
	int rtn;
	int i;
	int contadorSigno;

	contadorSigno = 0;
	rtn = 1; // VERDADERO

	if(strlen(pResultado) > 0){
		for(i = 0; i < strlen(pResultado); i++)
		{

			if(pResultado[i] == '.'|| pResultado[i] == ',')
			{
				contadorSigno++;
			}
			else
			{
				if(isdigit(pResultado[i]) == 0)
				{
					if(i == 0)
					{
						if(pResultado[0] != '-')
						{
							rtn = 0;
							break;
						}
					}else
					{
						rtn = 0;
						break;
					}
				}
			}
		}
		if(contadorSigno > 1)
		{
			rtn = 0;
		}
		}else
		{
			rtn = 0;
		}

	return rtn;
}
int esNumericaPositivo(char* pResultado)
{

	int i;
	int rtn;
	rtn = 1;
	if (strlen(pResultado) > 0)
	{
		for(i = 0; i < strlen(pResultado); i++)
		{
			if (isdigit(pResultado[i]) == 0)
			{
				if (i == 0)
				{
					rtn = 0;
					break;
				}else
				{
					rtn = 0;
					break;
				}
			}
		}
	}else
	{
		rtn = 0;
	}
	return rtn;
}
int esFlotantePositivo(char* pResultado)
{
	int rtn;
	int i;
	int contadorSigno;

	contadorSigno = 0;
	rtn = 1; // VERDADERO

	if(strlen(pResultado) > 0){
		for(i = 0; i < strlen(pResultado); i++)
		{

			if(pResultado[i] == '.'|| pResultado[i] == ',')
			{
				contadorSigno++;
			}
			else
			{
				if(isdigit(pResultado[i]) == 0)
				{
					if(i == 0)
					{
						rtn = 0;
						break;
					}else
					{
						rtn = 0;
						break;
					}
				}
			}
		}
		if(contadorSigno > 1)
		{
			rtn = 0;
		}
		}else
		{
			rtn = 0;
		}

	return rtn;
}
//


int eb_tipoCuenta(char* auxTipoCuenta, int nTipoCuenta)
{
	int rtn;
	rtn = FALSE;
	if(nTipoCuenta == 1)
	{
		strcpy(auxTipoCuenta, "Credito");
		rtn = TRUE;
	}else
	{
		strcpy(auxTipoCuenta, "Debito");
		rtn = TRUE;
	}

	return rtn;
}

void eb_HeadboardCuentas()
{
	puts("\n[CONSULTA]\n");
	printf("_________________________________________________________________________\n");
	printf("|             |                   |                   |                 |\n");
	printf("| ID CUENTA   | CLIENTE           | NIP               | SALDO           |\n");
	printf("|_____________|___________________|___________________|_________________|\n");
	printf("|             |                   |                   |                 |\n");
}

void eb_Headboard()
{
	puts("\n[CONSULTA]\n");
	printf("_____________________________________________________________________________________________________\n");
	printf("|             |                   |                   |                 |            |              |\n");
	printf("| ID CLIENTE  | NOMBRE            | CIUDAD            | DIRECCION       | EDAD       | TELEFONO     |\n");
	printf("|_____________|___________________|___________________|_________________|____________|______________|\n");
	printf("|             |                   |                   |                 |            |              |\n");
}

int eb_contador(char* pBuffer)
{
	int contador;
	int i;
	int rtn;
	contador = 0;
	rtn = FALSE;

	for(i = 0; i < strlen(pBuffer); i++)
	{
		contador++;
	}

	if(contador != 0)
	{
		rtn = contador;
	}

	return rtn;
}

int eb_getClave(int* pResultado, char mensaje[])
{
    char aBuffer[10];
    int rtn;
    int flagEstado_Numerico;
    int rtnContador;
    rtn = FALSE;
    flagEstado_Numerico = FALSE;
    if(pResultado != NULL)
    {
    	do
    	{
    		eb_myGets(aBuffer, 10,mensaje);
    		rtnContador = eb_contador(aBuffer);
    		if(rtnContador != FALSE && rtnContador < 5)
    		{
    			if(esNumerica(aBuffer) != 0)
    			{
					*pResultado = atoi(aBuffer);
					rtn = TRUE;
					flagEstado_Numerico = TRUE;
    			}else{
    				if(eb_getContinuar("[ERROR] LO INGRESADO NO ES UN NUMERO. DESEA VOLVER A INTENTARLO? SI (1) - NO (0):\n-> "))
					{
						flagEstado_Numerico = FALSE;
					}else
					{
						flagEstado_Numerico = NO;
						break;
					}
    			}
    		}else
    		{
    			if(eb_getContinuar("[ERROR] INGRESE UNA CLAVE DE 4 DIGITOS. DESEA VOLVER A INTENTARLO? SI (1) - NO (0):\n-> "))
    			{
    				flagEstado_Numerico = FALSE;
    			}else
    			{
    				flagEstado_Numerico = NO;
    				break;
    			}
    		}
    	}while(flagEstado_Numerico == FALSE);

    }

    return rtn;
}

int eb_getArchivo(char* pString, char* mensaje, int tString)
{
	char cadena[ARRAY_SIZE];
	int rtn;
	int flagEstado_Cadena;
	flagEstado_Cadena = FALSE;
	rtn = FALSE;

	if(pString != NULL)
	{
		do
		{
			eb_myGets(cadena, ARRAY_SIZE, mensaje);

			if(esCaracter(cadena) != 0)
			{
				if(eb_getContinuar("\n[ERROR] SOLO CARACTERES ALFABETICOS. QUIERE VOLVER A INTENTARLO? SI (1) - NO (0):\n-> ") == TRUE)
				{
					flagEstado_Cadena = FALSE;
				}else
				{
					flagEstado_Cadena = NO;
				}
			}else
			{
				flagEstado_Cadena = TRUE;
			}


		} while(flagEstado_Cadena == FALSE);
	}

	if(flagEstado_Cadena == TRUE)
	{
		strcat(cadena, ".csv");
		strcpy(pString, cadena);
		rtn = TRUE;
	}

	return rtn;
}

void eb_pulseToContinue()
{

	printf("[*] Presione una tecla para continuar . . .\n");
    getchar();

}

int eb_subMenu(char mensaje[])
{
	int rtn;
	rtn = -1;

	eb_getNumeroRango(&rtn, mensaje, 0, 2);

	return rtn;
}

int eb_getContinuar(char mensaje[])
{
	int rtn;
	rtn = -1;

	do
	{
		eb_getInt(&rtn, mensaje);
		if(rtn != 1 && rtn != 0)
		{
			printf("[ERROR] OPCION INVALIDA: '%d'\n", rtn);
		}else
		{
			if(rtn == 1)
			{
				rtn = 1;
			}else
			{
				rtn = 0;
			}
		}

	}while(rtn == -1);


	return rtn;
}

int eb_getFloatPositive(float* pResultado, char mensaje[])
{
    char aBuffer[50];
    int rtn;
    int flagEstado_Numerico;
    rtn = FALSE;
    flagEstado_Numerico = FALSE;
    if(pResultado != NULL)
    {
    	do
    	{
        	eb_myGets(aBuffer, sizeof(aBuffer), mensaje);
    		if(esFlotantePositivo(aBuffer) != 0)
    		{
    			*pResultado = atof(aBuffer);
    			rtn = TRUE;
    			flagEstado_Numerico = TRUE;
    		}else
    		{
    			if(eb_getContinuar("[ERROR] LO INGRESADO NO ES UN NUMERO. DESEA VOLVER A INTENTARLO? SI (1) - NO (0):\n-> "))
    			{
    				flagEstado_Numerico = FALSE;
    			}else
    			{
    				flagEstado_Numerico = NO;
    				break;
    			}
    		}
    	}while(flagEstado_Numerico == FALSE);

    }

    return rtn;
}

int eb_getIntPositive(int* pResultado, char mensaje[])
{
    char aBuffer[50];
    int rtn;
    int flagEstado_Numerico;
    rtn = FALSE;
    flagEstado_Numerico = FALSE;
    if(pResultado != NULL)
    {
    	do
    	{
        	eb_myGets(aBuffer, sizeof(aBuffer), mensaje);
    		if(esNumericaPositivo(aBuffer) != 0)
    		{
    			*pResultado = atoi(aBuffer);
    			rtn = TRUE;
    			flagEstado_Numerico = TRUE;
    		}else
    		{
    			if(eb_getContinuar("[ERROR] LO INGRESADO NO ES UN NUMERO. DESEA VOLVER A INTENTARLO? SI (1) - NO (0):\n-> "))
    			{
    				flagEstado_Numerico = FALSE;
    			}else
    			{
    				flagEstado_Numerico = NO;
    				break;
    			}
    		}
    	}while(flagEstado_Numerico == FALSE);

    }

    return rtn;
}

int eb_getSexo(char* pSexo, char mensaje[])
{
	int pAuxSexo;
	int rtn;

	rtn = FALSE;
	if(pSexo != NULL)
	{
		eb_getNumeroRango(&pAuxSexo, mensaje, 0, 1);

		if(pAuxSexo == 1)
		{
			*pSexo = 'M';
			rtn = TRUE;
		}else
		{
			*pSexo = 'F';
			rtn = TRUE;
		}
	}
	return rtn;
}

int concatenarNombreApellido(char* nombreCompleto, char* cadenaApellido, char* cadenaNombre)
{
	int rtn;
    int i;
    rtn = FALSE;

    /** FORMATO "Apellido, Nombre" */
    if(nombreCompleto != NULL && cadenaApellido != NULL && cadenaNombre != NULL)
    {
		strcpy(nombreCompleto, cadenaApellido);
		strcat(nombreCompleto, " ");
		strcat(nombreCompleto, cadenaNombre);

		strlwr(nombreCompleto); //CONVIERTE TODA LA CADENA A MINUSCULA

		nombreCompleto[0]=toupper(nombreCompleto[0]);

		for(i=0; i<strlen(nombreCompleto); i++)
		{
			if (isspace(nombreCompleto[i])) //(nombreCompleto[i]==' ')
			{
				nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);//PASA EN MAYUSCULA EL CARACTER DESPUES DEL ESPACIO
			}
		}

		rtn = TRUE;
    }

    return rtn;
}

int eb_getNombreApellido(char* pString, char* mensajeNombre, char* mensajeApellido, int tString)
{
	char nombre[ARRAY_SIZE];
	char apellido[ARRAY_SIZE];
	int rtn;
	rtn = FALSE;

	if(eb_getString(nombre, mensajeNombre, ARRAY_SIZE) == TRUE)
	{
		if(eb_getString(apellido, mensajeApellido, ARRAY_SIZE) == TRUE)
		{
			if(concatenarNombreApellido(pString, apellido, nombre) == TRUE)
			{
				rtn = TRUE;
			}
		}
	}

	return rtn;
}

int eb_getString(char* pString, char* mensaje, int tString)
{
	char cadena[ARRAY_SIZE];
	int rtn;
	int flagEstado_Cadena;
	flagEstado_Cadena = FALSE;
	rtn = FALSE;

	if(pString != NULL)
	{
		do
		{
			eb_myGets(cadena, ARRAY_SIZE, mensaje);

			if(strlen(cadena) > tString && strlen(cadena) < 1)
			{
				if(eb_getContinuar("\n[ERROR] EN EL LIMITE PERMITIDO DE CARACTERES. QUIERE VOLVER A INTENTARLO? SI (1) - NO (0):\n-> ") == TRUE)
				{
					flagEstado_Cadena = FALSE;
				}else
				{
					flagEstado_Cadena = NO;
				}
			}else
			{
				if(esCaracter(cadena) != 0)
				{
					if(eb_getContinuar("\n[ERROR] SOLO CARACTERES ALFABETICOS. QUIERE VOLVER A INTENTARLO? SI (1) - NO (0):\n-> ") == TRUE)
					{
						flagEstado_Cadena = FALSE;
					}else
					{
						flagEstado_Cadena = NO;
					}
				}else
				{
					flagEstado_Cadena = TRUE;
				}
			}

		} while(flagEstado_Cadena == FALSE);
	}

	if(flagEstado_Cadena == TRUE)
	{
		strlwr(cadena);
		cadena[0]=toupper(cadena[0]);
		strcpy(pString, cadena);
		rtn = TRUE;
	}

	return rtn;
}

int eb_getChar(char* letra, char mensaje[])
{
    char aBuffer[1000];
    int rtn;
    rtn = FALSE;

    if(letra != NULL)
    {
    	do
    	{
    		eb_myGets(aBuffer, ARRAY_SIZE, mensaje);
    		if(strlen(aBuffer) != TRUE)
    		{
    			if(eb_getContinuar("[ERROR] SOLO UNA LETRA. QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> ") != TRUE)
    			{
    				rtn = NO;
    			}
    		}else
    		{
    			aBuffer[0] = toupper(aBuffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
				*letra = aBuffer[0];

				rtn = TRUE;
    		}

    	}while(rtn == FALSE);
    }

    return rtn;
}

int eb_getTelefono(int* pResultado, char mensaje[])
{
    char aBuffer[9];
    int rtn;
    int flagEstado_Numerico;
    int auxTelefono;
    rtn = FALSE;
    flagEstado_Numerico = FALSE;
    if(pResultado != NULL)
    {
    	do
    	{
        	eb_myGets(aBuffer, sizeof(aBuffer), mensaje);
    		if(esNumerica(aBuffer) != 0)
    		{
    			auxTelefono = atoi(aBuffer);
    			if(auxTelefono > 00000000 && auxTelefono < 99999999)
    			{
					*pResultado = auxTelefono;
					rtn = TRUE;
					flagEstado_Numerico = TRUE;
    			}else
    			{
    				if(eb_getContinuar("[ERROR] LO INGRESADO NO ES UN NUMERO DE TELEFONO. DESEA VOLVER A INTENTARLO? SI (1) - NO (0):\n-> "))
					{
						flagEstado_Numerico = FALSE;
					}else
					{
						flagEstado_Numerico = NO;
						break;
					}
    			}
    		}else
    		{
    			if(eb_getContinuar("[ERROR] LO INGRESADO NO ES UN NUMERO. DESEA VOLVER A INTENTARLO? SI (1) - NO (0):\n-> "))
    			{
    				flagEstado_Numerico = FALSE;
    			}else
    			{
    				flagEstado_Numerico = NO;
    				break;
    			}
    		}
    	}while(flagEstado_Numerico == FALSE);

    }

    return rtn;
}

int eb_myGets(char* pResultado, int tResultado, char* mensaje)
{
	char aBuffer[1000];
	int rtn;
	rtn = FALSE;

	if(pResultado != NULL && tResultado > 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(aBuffer);

			if(strlen(aBuffer) > tResultado || strlen(aBuffer) < 1)
			{
				if(eb_getContinuar("[ERROR] EN EL LIMITE DE CARACTERES PERMITIDOS. QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> ") != TRUE)
				{
					rtn = NO;
					break;
				}
			}else
			{
				strncpy(pResultado, aBuffer, tResultado);
				rtn = TRUE;
			}


		} while(rtn == FALSE);



	}

	return rtn;
}

int eb_getInt(int* pResultado, char mensaje[])
{
    char aBuffer[150];
    int rtn;
    rtn = FALSE;

	while(rtn == FALSE)
	{
		eb_myGets(aBuffer, sizeof(aBuffer), mensaje);
		if(esNumerica(aBuffer) == 0)
		{
			if(eb_getContinuar("[ERROR] INGRESE UN NUMERO. QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> ") == NO)
			{
				rtn = NO;
				break;
			}
		}else
		{
			*pResultado = atoi(aBuffer);
			rtn = TRUE;
		}
	}


    return rtn;
}

int eb_getNumeroRango(int* pResultado, char mensaje[], int minimo, int maximo)
{
	int numeroIngresado;
	int rtn;
	rtn = FALSE;

	if(pResultado != NULL)
	{
		do
		{
			if(eb_getInt(&numeroIngresado, mensaje) == TRUE)
			{
				if(numeroIngresado < minimo || numeroIngresado > maximo)
				{
					printf("[ERROR] EL NUMERO %d ESTA FUERA DEL RANGO -> MINIMO: %d MAXIMO: %d.\n", numeroIngresado ,minimo, maximo);
					if(eb_getContinuar("[ERROR] QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> ") == NO)
					{
						rtn = NO;
						break;
					}
				}else
				{
					*pResultado = numeroIngresado;
					rtn = TRUE;
				}
			}else
			{
				rtn = NO;
			}

		}while(rtn == FALSE);

	}

	return rtn;
}

int eb_getFloat(float* pResultado, char mensaje[])
{
	char aBuffer[50];
	int rtn;
	rtn = FALSE;

	if(pResultado != NULL)
	{
		do
		{
			eb_myGets(aBuffer, sizeof(aBuffer), mensaje);

			if(esFlotante(aBuffer) == 0)
			{
				if(eb_getContinuar("[ERROR] LO INGRESADO NO ES UN NUMERO. QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> ") != TRUE)
				{
					rtn = NO;
				}
			}else
			{
				*pResultado = atof(aBuffer);
				rtn = TRUE;
			}

		}while(rtn == FALSE);
	}

	return rtn;
}

int eb_getFlotanteRango(float* pResultado, char* mensaje, float minimo, float maximo)
{
	float numeroIngresado;
	int rtn;
	rtn = FALSE;

	if(pResultado != NULL)
	{
		do
		{
			eb_getFloat(&numeroIngresado, mensaje);

			if(numeroIngresado < minimo && numeroIngresado > maximo)
			{
				printf("ERROR: El numero %.2f esta fuera del rango -> Minimo: %.2f Maximo: %.2f.\n", numeroIngresado ,minimo, maximo);
				if(eb_getContinuar("[ERROR] QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> ") != TRUE)
				{
					rtn = NO;
				}
			}else
			{
				*pResultado = numeroIngresado;
				rtn = TRUE;
			}

		}while(rtn == FALSE);
	}

	return rtn;
}
