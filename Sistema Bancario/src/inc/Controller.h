#include "LinkedList.h"

#define DEPOSITO 0
#define RETIRO 1
#define TRANFERENCIA_RECIBIDA 2
#define TRANFERENCIA_REALIZADA 3
#define SALDO_INICIAL 4

int controller_registroClientes(LinkedList* pArrayClientes);
int controller_consultaClientes(LinkedList* pArrayClientes);
int controller_registroCuentas(LinkedList* pArrayClientes, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int controller_consultaCuentas(LinkedList* pArrayClientes, LinkedList* pArrayCuentas);
int controller_deposito(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int controller_retiro(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int controller_transferencia(LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int controller_resgistroMovimientos(LinkedList* pArrayMovimientos, int idCuenta, int idCliente, int TipoMov, float monto);
int controller_estadoCuenta(LinkedList* pArrayCliente, LinkedList* pArrayCuentas, LinkedList* pArrayMovimientos);
int controller_guardarDatosClientes(LinkedList* pArrayCliente, char* direccion);
int controller_guardarDatosCuentas(LinkedList* pArrayCuentas, char* direccion);
int controller_guardarDatosMovimientos(LinkedList* pArrayMovimientos, char* direccion);
