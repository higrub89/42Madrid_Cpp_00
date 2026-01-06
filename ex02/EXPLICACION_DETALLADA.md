# 📚 Explicación Detallada del Ejercicio ex02 - Clase Account

## 📋 Índice
1. [Descripción General del Proyecto](#descripción-general-del-proyecto)
2. [Arquitectura del Programa](#arquitectura-del-programa)
3. [Variables Miembro](#variables-miembro)
4. [Funciones Implementadas](#funciones-implementadas)
5. [Flujo de Ejecución](#flujo-de-ejecución)
6. [Conceptos Clave de C++](#conceptos-clave-de-c)
7. [Compilación y Pruebas](#compilación-y-pruebas)

---

## 🎯 Descripción General del Proyecto

### Objetivo
Implementar la clase `Account` que simula un sistema bancario simple con múltiples cuentas. El ejercicio es de **ingeniería inversa**: se proporciona el header (`.hpp`), un programa de prueba (`tests.cpp`) y un archivo de log con la salida esperada (`19920104_091532.log`).

### Archivos del Proyecto
```
ex02/
├── Account.hpp              # Header de la clase (proporcionado, NO modificar)
├── Account.cpp              # Implementación (TU CÓDIGO)
├── tests.cpp               # Programa de prueba (proporcionado, NO modificar)
└── 19920104_091532.log     # Salida de referencia
```

### Desafío
Crear `Account.cpp` de manera que al ejecutar `tests.cpp`, la salida coincida exactamente con el formato del archivo `.log` (excepto el timestamp que será diferente).

---

## 🏗️ Arquitectura del Programa

### Diagrama de Clases
```
┌─────────────────────────────────────────┐
│           Clase Account                 │
├─────────────────────────────────────────┤
│ Variables Estáticas (compartidas):      │
│  - _nbAccounts                          │
│  - _totalAmount                         │
│  - _totalNbDeposits                     │
│  - _totalNbWithdrawals                  │
├─────────────────────────────────────────┤
│ Variables de Instancia (por cuenta):    │
│  - _accountIndex                        │
│  - _amount                              │
│  - _nbDeposits                          │
│  - _nbWithdrawals                       │
├─────────────────────────────────────────┤
│ Métodos Públicos:                       │
│  + Account(int initial_deposit)         │
│  + ~Account()                           │
│  + makeDeposit(int)                     │
│  + makeWithdrawal(int) : bool           │
│  + displayStatus() const                │
│  + checkAmount() const : int            │
│  + displayAccountsInfos() [static]      │
│  + getNbAccounts() [static] : int       │
│  + getTotalAmount() [static] : int      │
│  + getNbDeposits() [static] : int       │
│  + getNbWithdrawals() [static] : int    │
├─────────────────────────────────────────┤
│ Métodos Privados:                       │
│  - _displayTimestamp() [static]         │
└─────────────────────────────────────────┘
```

---

## 📊 Variables Miembro

### Variables Estáticas (Compartidas por todas las instancias)

Estas variables pertenecen a la **clase**, no a objetos individuales. Se comparten entre todas las cuentas.

```cpp
static int _nbAccounts;           // Número total de cuentas activas
static int _totalAmount;          // Suma total de dinero en todas las cuentas
static int _totalNbDeposits;      // Total de depósitos realizados (global)
static int _totalNbWithdrawals;   // Total de retiros realizados (global)
```

**Inicialización (líneas 5-8):**
```cpp
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
```

> ⚠️ **Importante:** Las variables estáticas deben inicializarse **fuera de la clase**, en el archivo `.cpp`.

### Variables de Instancia (Únicas por cada cuenta)

Cada objeto `Account` tiene sus propias copias de estas variables:

```cpp
int _accountIndex;      // Índice único de la cuenta (0, 1, 2, ...)
int _amount;            // Saldo actual de esta cuenta
int _nbDeposits;        // Número de depósitos en esta cuenta
int _nbWithdrawals;     // Número de retiros en esta cuenta
```

---

## 🔧 Funciones Implementadas

### 1. **Getters Estáticos** (líneas 11-29)

Permiten acceder a las variables estáticas privadas desde fuera de la clase.

```cpp
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}
```

**Uso:**
```cpp
int total = Account::getNbAccounts();  // Se llama sin crear un objeto
```

---

### 2. **Constructor** (líneas 31-37)

Se ejecuta automáticamente al crear una nueva cuenta.

```cpp
Account::Account(int initial_deposit) 
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
    _accountIndex = _nbAccounts;     // Asigna índice único
    _nbAccounts++;                   // Incrementa contador global
    _totalAmount += initial_deposit; // Suma al total global
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}
```

**Lista de inicialización:**
```cpp
: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
```
Inicializa las variables miembro **antes** de ejecutar el cuerpo del constructor.

**Salida esperada:**
```
[20260106_214838] index:0;amount:42;created
```

**Flujo:**
1. Se crea una cuenta con un depósito inicial
2. Se le asigna un índice único (basado en el número actual de cuentas)
3. Se incrementa el contador global de cuentas
4. Se suma el depósito inicial al total global
5. Se muestra el mensaje de creación

---

### 3. **Destructor** (líneas 47-52)

Se ejecuta automáticamente cuando un objeto se destruye (al salir de scope).

```cpp
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
    _nbAccounts--;           // Decrementa contador global
    _totalAmount -= _amount; // Resta del total global
}
```

**Salida esperada:**
```
[20260106_214838] index:0;amount:47;closed
```

**Flujo:**
1. Muestra mensaje de cierre con el saldo final
2. Decrementa el contador de cuentas activas
3. Resta el saldo de esta cuenta del total global

---

### 4. **_displayTimestamp()** (líneas 39-44)

Función privada que muestra el timestamp en formato `[YYYYMMDD_HHMMSS]`.

```cpp
void Account::_displayTimestamp(void) {
    std::time_t t = std::time(NULL);           // Obtiene tiempo actual
    char buf[20];                               // Buffer para el string
    std::strftime(buf, sizeof(buf), 
                  "[%Y%m%d_%H%M%S] ", 
                  std::localtime(&t));          // Formatea el tiempo
    std::cout << buf;                           // Imprime el timestamp
}
```

**Formato de salida:**
```
[20260106_214838] 
```

**Componentes:**
- `%Y` → Año (4 dígitos): 2026
- `%m` → Mes (01-12): 01
- `%d` → Día (01-31): 06
- `%H` → Hora (00-23): 21
- `%M` → Minutos (00-59): 48
- `%S` → Segundos (00-59): 38

---

### 5. **displayAccountsInfos()** (líneas 55-62)

Función estática que muestra información global de todas las cuentas.

```cpp
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}
```

**Salida esperada:**
```
[20260106_214838] accounts:8;total:20049;deposits:0;withdrawals:0
```

**Uso en tests.cpp:**
```cpp
Account::displayAccountsInfos();  // Llamada estática
```

---

### 6. **displayStatus()** (líneas 65-72)

Muestra el estado de una cuenta específica.

```cpp
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}
```

**Salida esperada:**
```
[20260106_214838] index:0;amount:42;deposits:0;withdrawals:0
```

**Nota:** Es una función `const` porque no modifica el estado del objeto.

---

### 7. **makeDeposit()** (líneas 75-89)

Realiza un depósito en la cuenta.

```cpp
void Account::makeDeposit(int deposit) {
    int p_amount = _amount;          // Guarda el monto previo
    _amount += deposit;              // Actualiza saldo
    _nbDeposits++;                   // Incrementa contador de depósitos
    _totalAmount += deposit;         // Actualiza total global
    _totalNbDeposits++;              // Incrementa contador global
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits 
              << std::endl;
}
```

**Salida esperada:**
```
[20260106_214838] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
```

**Flujo:**
1. Guarda el monto anterior (`p_amount`)
2. Suma el depósito al saldo actual
3. Incrementa contadores (de la cuenta y globales)
4. Muestra el mensaje con valores antes y después

---

### 8. **makeWithdrawal()** (líneas 92-114)

Intenta realizar un retiro. Retorna `true` si es exitoso, `false` si no hay fondos.

```cpp
bool Account::makeWithdrawal(int withdrawal) {
    int p_amount = _amount;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount;
    
    // Verifica si hay fondos suficientes
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    // Si hay fondos, procesa el retiro
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    std::cout << ";withdrawal:" << withdrawal 
              << ";amount:" << _amount 
              << ";nb_withdrawals:" << _nbWithdrawals 
              << std::endl;
    
    return true;
}
```

**Salida si hay fondos:**
```
[20260106_214838] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
```

**Salida si NO hay fondos:**
```
[20260106_214838] index:0;p_amount:47;withdrawal:refused
```

**Flujo:**
1. Guarda el monto anterior
2. Muestra timestamp e índice
3. **Verifica** si hay fondos suficientes
4. Si NO hay fondos: muestra "refused" y retorna `false`
5. Si SÍ hay fondos: procesa el retiro, actualiza contadores y retorna `true`

---

### 9. **checkAmount()** (líneas 117-119)

Getter simple que retorna el saldo actual.

```cpp
int Account::checkAmount(void) const {
    return _amount;
}
```

**Uso:**
```cpp
int balance = account.checkAmount();
```

---

## 🔄 Flujo de Ejecución

### Programa tests.cpp

El programa de prueba sigue este flujo:

```cpp
int main(void) {
    // 1. Crea 8 cuentas con diferentes montos iniciales
    int amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
    accounts_t accounts(amounts, amounts + amounts_size);
    
    // 2. Muestra información global y estado de cada cuenta
    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));
    
    // 3. Realiza depósitos en todas las cuentas
    int d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
    for (...) {
        account.makeDeposit(deposit);
    }
    
    // 4. Muestra información actualizada
    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));
    
    // 5. Intenta realizar retiros
    int w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
    for (...) {
        account.makeWithdrawal(withdrawal);
    }
    
    // 6. Muestra información final
    Account::displayAccountsInfos();
    std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));
    
    // 7. Al salir del scope, se destruyen todas las cuentas
    return 0;
}
```

### Salida Completa del Programa

```
# Creación de 8 cuentas
[timestamp] index:0;amount:42;created
[timestamp] index:1;amount:54;created
...
[timestamp] index:7;amount:16576;created

# Estado inicial
[timestamp] accounts:8;total:20049;deposits:0;withdrawals:0
[timestamp] index:0;amount:42;deposits:0;withdrawals:0
...

# Depósitos
[timestamp] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
...

# Estado después de depósitos
[timestamp] accounts:8;total:21524;deposits:8;withdrawals:0
...

# Retiros (algunos rechazados)
[timestamp] index:0;p_amount:47;withdrawal:refused
[timestamp] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
...

# Estado final
[timestamp] accounts:8;total:12442;deposits:8;withdrawals:6
...

# Destrucción de cuentas
[timestamp] index:0;amount:47;closed
...
[timestamp] index:7;amount:8942;closed
```

---

## 💡 Conceptos Clave de C++

### 1. **Variables Estáticas**

```cpp
static int _nbAccounts;  // Declaración en .hpp
int Account::_nbAccounts = 0;  // Definición en .cpp
```

- **Compartidas** por todas las instancias de la clase
- Existen durante toda la ejecución del programa
- Se acceden con `Account::_nbAccounts` (dentro de la clase)
- Deben inicializarse **fuera** de la clase

### 2. **Funciones Estáticas**

```cpp
static void displayAccountsInfos(void);  // Declaración
```

- No necesitan un objeto para ser llamadas
- Solo pueden acceder a variables estáticas
- Se llaman con `Account::displayAccountsInfos()`

### 3. **Lista de Inicialización del Constructor**

```cpp
Account::Account(int initial_deposit) 
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    // Cuerpo del constructor
}
```

- Inicializa variables miembro **antes** del cuerpo del constructor
- Más eficiente que asignar dentro del cuerpo
- **Obligatorio** para referencias y constantes

### 4. **Funciones const**

```cpp
void displayStatus(void) const;
int checkAmount(void) const;
```

- Prometen **no modificar** el estado del objeto
- Pueden ser llamadas en objetos `const`
- El compilador genera error si intentan modificar variables miembro

### 5. **Constructor y Destructor**

```cpp
Account(int initial_deposit);  // Constructor
~Account(void);                // Destructor
```

- **Constructor:** Se ejecuta al crear un objeto
- **Destructor:** Se ejecuta al destruir un objeto (automáticamente)
- El destructor se llama en orden inverso a la creación

### 6. **std::time y std::strftime**

```cpp
std::time_t t = std::time(NULL);              // Obtiene tiempo actual
std::tm* now = std::localtime(&t);            // Convierte a estructura tm
std::strftime(buf, size, format, now);        // Formatea como string
```

- `std::time_t`: Tipo para almacenar tiempo (segundos desde 1970)
- `std::tm`: Estructura con año, mes, día, hora, etc.
- `std::strftime`: Formatea tiempo como string con especificadores

---

## 🔨 Compilación y Pruebas

### Compilar el Programa

```bash
c++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o account_test
```

**Flags:**
- `-Wall -Wextra -Werror`: Activa todos los warnings y los trata como errores
- `-std=c++98`: Usa el estándar C++98 (requerido por 42)
- `-o account_test`: Nombre del ejecutable

### Ejecutar el Programa

```bash
./account_test
```

### Comparar con el Log de Referencia

```bash
# Guardar tu salida
./account_test > my_output.log

# Comparar (ignorando timestamp)
./account_test | sed 's/\[.*\] /[TIMESTAMP] /' > my_output.log
sed 's/\[.*\] /[TIMESTAMP] /' 19920104_091532.log > reference.log
diff my_output.log reference.log
```

Si `diff` no muestra diferencias, ¡tu implementación es correcta! ✅

### Verificar con Valgrind (Memory Leaks)

```bash
valgrind --leak-check=full ./account_test
```

Debe mostrar:
```
All heap blocks were freed -- no leaks are possible
```

---

## 📝 Resumen de Implementación

### Checklist Completo

- ✅ Variables estáticas inicializadas
- ✅ 4 Getters estáticos (`getNbAccounts`, `getTotalAmount`, etc.)
- ✅ Constructor (crea cuenta, asigna índice, muestra mensaje)
- ✅ Destructor (muestra cierre, actualiza contadores)
- ✅ `_displayTimestamp()` (formato `[YYYYMMDD_HHMMSS]`)
- ✅ `displayAccountsInfos()` (información global)
- ✅ `displayStatus()` (estado de una cuenta)
- ✅ `makeDeposit()` (realiza depósito, actualiza contadores)
- ✅ `makeWithdrawal()` (retiro con validación de fondos)
- ✅ `checkAmount()` (retorna saldo actual)

### Puntos Clave

1. **Variables estáticas** llevan el registro global de todas las cuentas
2. **Cada cuenta** tiene su propio índice, saldo y contadores
3. **Formato exacto** del log es crítico (espacios, `;`, `:`)
4. **Timestamp** será diferente, pero el resto debe coincidir
5. **Orden de actualización:** guardar valor previo → actualizar → mostrar

---

## 🎓 Conceptos Aprendidos

Este ejercicio enseña:

1. ✅ **Variables y funciones estáticas** en C++
2. ✅ **Constructores y destructores**
3. ✅ **Lista de inicialización**
4. ✅ **Funciones const**
5. ✅ **Manejo de tiempo** (`<ctime>`)
6. ✅ **Formato de salida** con `std::cout`
7. ✅ **Ingeniería inversa** (reconstruir código desde especificación)
8. ✅ **Gestión de estado** (variables de instancia vs. estáticas)

---

## 🚀 Conclusión

Este ejercicio simula un sistema bancario simple donde:
- Múltiples cuentas comparten información global (total de dinero, número de cuentas)
- Cada cuenta mantiene su propio estado (saldo, depósitos, retiros)
- Todas las operaciones se registran con timestamp
- El programa valida operaciones (retiros con fondos insuficientes)

La implementación completa en `Account.cpp` tiene **119 líneas** y cumple exactamente con la especificación del archivo de log de referencia.

---

**Autor:** Implementación para el ejercicio ex02 del módulo CPP_00 de 42  
**Fecha:** Enero 2026  
**Compilador:** c++ (compatible con C++98)
