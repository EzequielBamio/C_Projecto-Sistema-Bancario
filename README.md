# Project-Sistema-Bancario

_Simulador de Sistema Bancario, hecho para la practica de Estructuras, Punteros, Archivos, LinkedList en C._

## MENU 🚀

<a href="https://imgbb.com/"><img src="https://i.ibb.co/yhKM1RC/menu-principal.png" alt="menu-principal" border="0"></a>

<a href="https://imgbb.com/"><img src="https://i.ibb.co/0GfX7S1/menu-clientes.png" alt="menu-clientes" border="0"></a>
<a href="https://imgbb.com/"><img src="https://i.ibb.co/GQNRXvh/menu-cuentas.png" alt="menu-cuentas" border="0"></a>

#### FUNCIONALIDAD DEL MENU 📋
<p>
  <h5 align="left"><b>**Registro** Cada dato que se agregue deberá ser confirmado y guardado en el lista.</b></h5>
  <h5 align="left"><b>**Consulta** Consultará información de Clientes por nombre, y la información de Cuentas por Id</b></h3>
  <h5 align="left"><b>**Regresar al menu principal** Muestra el menú principal.</b></h5>

</p>

### ESTRUCTURAS 🔧

```c
#define ARRAY_SIZE 100
```

```c
typedef struct
{
  int idCliente;
  char nombres[ARRAY_SIZE];
  char ciudad[ARRAY_SIZE];
  char direccion[ARRAY_SIZE];
  int edad;
  int telefono;

}eCliente;
```

```c
typedef struct
{
  int idCuenta;
  int idCliente;
  int nip;
  float saldo;
}eCuentas;
```

```c
typedef struct
{
  int idCuenta;
  int idCliente;
  int idTipoMov;
  float monto;
  char fecha[ARRAY_SIZE];
}eMovimientos;
```
## Construido con 🛠️

  ![C](https://img.shields.io/badge/-C-333333?style=flat&logo=C%2B%2B&logoColor=00599C)
  ![Eclipse](https://img.shields.io/badge/-Eclipse-333333?style=flat&logo=eclipse-ide&logoColor=2C2255)
  
  * **Uso de**:
      Funciones,
      Arreglos,
      Estructuras,
      Archivos,
      LinkedList.
## ACTUALIZACIONES 📄

23/07/2021 - Proyecto cargado.

## Autor ✒️

* [EzequielBamio](https://github.com/EzequielBamio) - *Desarrollador*
 
 <p align="center">
<br>
<a href="https://drive.google.com/file/d/1bb-wbcOZ2OE20MRyFDtz6ReMP7zoDjWG/view?usp=sharing"><img src="https://img.shields.io/badge/PROBAR_EL_PROYECTO_(.EXE)-88AE4B.svg?&style=for-the-badge&logo=Google-Drive&logoColor=white" alt="PROBAR EL PROYECTO (.EXE)"/></a>&nbsp;
</p>

---


