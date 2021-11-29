#include "inc/stCliente.h"

eCliente* cl_new()
{
	eCliente* pCliente;

	pCliente = (eCliente*) malloc(sizeof(eCliente));

	return pCliente;
}

eCliente* cl_newParametros(char* idClienteStr, char* nombresStr, char* ciudadStr, char* direccionStr, char* edadStr, char* telefonoStr)
{
	eCliente* pCliente;
	pCliente = cl_new();

	if(pCliente != NULL)
	{
		cl_setEverything(pCliente, atoi(idClienteStr), nombresStr, ciudadStr, direccionStr, atoi(edadStr), atoi(telefonoStr));
	}

	return pCliente;
}

int cl_delete(eCliente* this)
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

int cl_setEverything(eCliente* this, int idCliente, char* nombresStr, char* ciudadStr, char* direccionStr, int edad, int telefono)
{
	int rtn;
	rtn = FALSE;

	if(cl_setIdCliente(this, idCliente) &&
	   cl_setNombres(this, nombresStr) &&
	   cl_setCiudad(this, ciudadStr) &&
	   cl_setDireccion(this, direccionStr) &&
	   cl_setEdad(this, edad) &&
	   cl_setTelefono(this, telefono))
	{
		rtn = TRUE;
	}

	return rtn;

}
int cl_getEverything(eCliente* this, int* idCliente, char* nombresStr, char* ciudadStr, char* direccionStr, int* edad, int* telefono)
{
	int rtn;
	rtn = FALSE;

	if(cl_getIdCliente(this, idCliente) &&
	   cl_getNombres(this, nombresStr) &&
	   cl_getCiudad(this, ciudadStr) &&
	   cl_getDireccion(this, direccionStr) &&
	   cl_getEdad(this, edad) &&
	   cl_getTelefono(this, telefono))
	{
		rtn = TRUE;
	}

	return rtn;

}

// --------- //

int cl_setIdCliente(eCliente* this, int id)
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
int cl_getIdCliente(eCliente* this, int* id)
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
int cl_setNombres(eCliente* this, char* nombres)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && nombres != NULL)
	{
		strcpy(this->nombres, nombres);
		rtn = TRUE;
	}

	return rtn;
}
int cl_getNombres(eCliente* this, char* nombres)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && nombres != NULL)
	{
		strcpy(nombres, this->nombres);
		rtn = TRUE;
	}

	return rtn;
}

//
int cl_setCiudad(eCliente* this, char* ciudad)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && ciudad != NULL)
	{
		strcpy(this->ciudad, ciudad);
		rtn = TRUE;
	}

	return rtn;
}
int cl_getCiudad(eCliente* this, char* ciudad)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && ciudad != NULL)
	{
		strcpy(ciudad, this->ciudad);
		rtn = TRUE;
	}

	return rtn;
}

//
int cl_setDireccion(eCliente* this, char* direccion)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && direccion != NULL)
	{
		strcpy(this->direccion, direccion);
		rtn = TRUE;
	}

	return rtn;
}
int cl_getDireccion(eCliente* this, char* direccion)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && direccion != NULL)
	{
		strcpy(direccion, this->direccion);
		rtn = TRUE;
	}

	return rtn;
}

//
int cl_setEdad(eCliente* this, int edad)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		rtn = TRUE;
	}

	return rtn;
}
int cl_getEdad(eCliente* this, int* edad)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*edad = this->edad;
		rtn = TRUE;
	}

	return rtn;
}

//
int cl_setTelefono(eCliente* this, int telefono)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL && telefono > 0)
	{
		this->telefono = telefono;
		rtn = TRUE;
	}

	return rtn;
}
int cl_getTelefono(eCliente* this, int* telefono)
{
	int rtn;
	rtn = FALSE;

	if(this != NULL)
	{
		*telefono = this->telefono;
		rtn = TRUE;
	}

	return rtn;
}

// --------- //

int cl_IDlatest(LinkedList* pArrayListCliente)
{
	eCliente* pCliente;
	int i;
	int id;
	int ultimoID;
	int tCliente;

	ultimoID = 0;
	pCliente = cl_new();
	tCliente = ll_len(pArrayListCliente);

	for(i = 0; i < tCliente; i++)
	{
		pCliente = ll_get(pArrayListCliente, i);
		cl_getIdCliente(pCliente, &id);
		if(ultimoID < id)
		{
			ultimoID = id;
		}
	}

	return ultimoID;

}

int cl_IDincrease(int* id)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return *id += 1;
}

eCliente* cl_searchNombre(LinkedList* pArrayListCliente, char* nombre)
{
	eCliente* pCliente;
	eCliente* rtn;
	char auxNombre[ARRAY_SIZE];
	int tList;
	int i;
	rtn = NULL;
	tList = ll_len(pArrayListCliente);

	if(pArrayListCliente != NULL && nombre != NULL)
	{
		for(i = 0; i < tList; i++)
		{
			pCliente = ll_get(pArrayListCliente, i);
			cl_getNombres(pCliente, auxNombre);
			if(strcmp(auxNombre, nombre) == 0)
			{
				rtn = pCliente;
				break;
			}
		}
	}
	return rtn;
}

int cl_mostrarUnCliente(eCliente* pCliente)
{
	int mc_idCliente;
	int mc_edad;
	int mc_telefono;
	char mc_nombres[ARRAY_SIZE];
	char mc_ciudad[ARRAY_SIZE];
	char mc_direccion[ARRAY_SIZE];
	int rtn;
	rtn = FALSE;

	if(pCliente != NULL)
	{
		cl_getEverything(pCliente, &mc_idCliente, mc_nombres, mc_ciudad, mc_direccion, &mc_edad, &mc_telefono);
		eb_Headboard();
		printf("| %-11d | %-17s | %-17s | %-15s | %-10d | %-12d |\n", mc_idCliente, mc_nombres, mc_ciudad, mc_direccion, mc_edad, mc_telefono);
		rtn = TRUE;
	}

	return rtn;

}

eCliente* cl_searchID(LinkedList* pArrayListCliente, int id)
{
	eCliente* pCliente;
	int auxID;
	int tList;
	eCliente* rtn;
	int i;
	rtn = NULL;
	tList = ll_len(pArrayListCliente);

	if(pArrayListCliente != NULL)
	{
		for(i = 0; i < tList; i++)
		{
			pCliente = ll_get(pArrayListCliente, i);
			cl_getIdCliente(pCliente, &auxID);
			if(auxID == id)
			{
				rtn = pCliente;
				break;
			}
		}
	}
	return rtn;
}
