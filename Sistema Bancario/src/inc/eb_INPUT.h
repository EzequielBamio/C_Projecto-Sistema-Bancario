#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include <time.h>

#ifndef EB_INPUT_H_
#define EB_INPUT_H_

#define ARRAY_SIZE 100
#define TRUE 1
#define FALSE -1
#define NO 0
#define SI 1
#define SALIR 2

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

int eb_validarTipoMov(char* tipoMov, int idTipoMov);
int eb_getFecha(char fecha[]);
int eb_tipoCuenta(char* auxTipoCuenta, int nTipoCuenta);
int eb_contador(char* buffer);
void eb_HeadboardCuentas();
void eb_Headboard();
int eb_getArchivo(char* pString, char* mensaje, int tString);
int eb_getClave(int* pResultado, char mensaje[]);
int eb_getTelefono(int* pResultado, char mensaje[]);
int eb_subMenu(char mensaje[]);
int eb_getFloatPositive(float* pResultado, char mensaje[]);
int eb_getIntPositive(int* pResultado, char mensaje[]);
int eb_getContinuar(char mensaje[]);
int eb_getNombreApellido(char* pString, char* mensajeNombre, char* mensajeApellido, int tString);
int eb_getString(char* pString, char* mensaje, int tString);
void eb_pulseToContinue();

int esFlotantePositivo(char* pResultado);
int esNumericaPositivo(char* pResultado);
/******/

int get_Tipo(char pTipo[], char mensaje[]);
int eb_getSexo(char* pSexo, char mensaje[]);
int concatenarNombreApellido(char nombreCompleto[], char cadenaApellido[], char cadenaNombre[]);
int eb_getChar(char* , char []);
int eb_myGets(char [], int , char []);
int eb_getInt(int*, char []);
int eb_getNumeroRango(int*, char [], int , int );
int eb_getFloat(float*, char []);
int eb_getFlotanteRango(float*, char [], float , float );

int esNumerica(char []);
int esFlotante(char []);
int esCaracterConEspacio(char []);
int esCaracter(char pResultado[]);
#endif /* EB_INPUT_H_ */
