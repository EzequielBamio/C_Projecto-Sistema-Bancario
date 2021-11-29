#include "eb_INPUT.h"

#ifndef STCLIENTE_H_
#define STCLIENTE_H_

//inicio struct
typedef struct
{
	int idCliente;
	char nombres[ARRAY_SIZE];
	char ciudad[ARRAY_SIZE];
	char direccion[ARRAY_SIZE];
	int edad;
	int telefono;

}eCliente;
//fin struct

//-------------------------//

//inicio prototipos
eCliente* cl_new();

eCliente* cl_newParametros(char* idClienteStr, char* nombresStr, char* ciudadStr, char* direccionStr, char* edadStr, char* telefonoStr);

int cl_delete(eCliente* this);

int cl_setEverything(eCliente* this, int idCliente, char* nombresStr, char* ciudadStr, char* direccionStr, int edad, int telefono);
int cl_getEverything(eCliente* this, int* idCliente, char* nombresStr, char* ciudadStr, char* direccionStr, int* edad, int* telefono);

// --------- //
int cl_setIdCliente(eCliente* this, int id);
int cl_getIdCliente(eCliente* this, int* id);

int cl_setNombres(eCliente* this, char* nombres);
int cl_getNombres(eCliente* this, char* nombres);

int cl_setCiudad(eCliente* this, char* ciudad);
int cl_getCiudad(eCliente* this, char* ciudad);

int cl_setDireccion(eCliente* this, char* direccion);
int cl_getDireccion(eCliente* this, char* direccion);

int cl_setEdad(eCliente* this, int edad);
int cl_getEdad(eCliente* this, int* edad);

int cl_setTelefono(eCliente* this, int telefono);
int cl_getTelefono(eCliente* this, int* telefono);

// --------- //

int cl_IDlatest(LinkedList* pArrayListCliente);
int cl_IDincrease(int* id);
eCliente* cl_searchNombre(LinkedList* pArrayListCliente, char* nombre);
int cl_mostrarUnCliente(eCliente* pCliente);
eCliente* cl_searchID(LinkedList* pArrayListCliente, int id);

//fin prototipos


#endif /* STCLIENTE_H_ */
