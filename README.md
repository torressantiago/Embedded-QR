# Configuración y Despliegue de Código QR en LilyGo T-Display-S3
---

## 1. Requisitos

### Hardware

* Placa LilyGo T-Display-S3.
* Cable USB-C con soporte para transferencia de datos (un cable exclusivo de carga no funcionará).
* Ordenador con sistema operativo Windows, macOS o Linux.

### Software

* [Arduino IDE](https://www.arduino.cc/en/software) instalado en el equipo.

---

## 2. Conexión del Dispositivo

1. Conectar el cable USB-C al puerto de la placa LilyGo.
2. Conectar el otro extremo del cable a un puerto USB del ordenador.
3. Confirmar que la pantalla se ilumina, lo cual indica que la placa está recibiendo alimentación.

---

## 3. Configuración del Entorno de Desarrollo (Arduino IDE)

### A. Instalación de soporte para ESP32

1. Abrir Arduino IDE.
2. Dirigirse a **Archivo** > **Preferencias** (en macOS: **Arduino** > **Settings**).
3. Localizar el campo **"Gestor de URLs Adicionales de Tarjetas"**.
4. Añadir la siguiente URL y hacer clic en **OK**:
`[https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)`
5. Navegar a **Herramientas** > **Placa** > **Gestor de tarjetas...**
6. En el buscador de la barra lateral, introducir `esp32`.
7. Localizar "esp32 by Espressif Systems" e instalar.

### B. Selección de la placa

1. Navegar a **Herramientas** > **Placa** > **esp32**.
2. Seleccionar el modelo **LilyGo T-Display-S3** en la lista.

### C. Instalación de librerías

1. Navegar a **Programa** > **Incluir Librería** > **Administrar Bibliotecas...**
2. Buscar `TFT_eSPI` (autor: Bodmer) e instalar.
3. Buscar `qrcode` (autor: Richard Moore) e instalar.

### D. Configuración de la librería TFT_eSPI

Este paso es estrictamente necesario para que la librería se comunique correctamente con la pantalla del dispositivo.

1. Acceder al directorio local de las librerías de Arduino en el sistema (generalmente ubicado en `Documentos/Arduino/libraries/TFT_eSPI`).
2. Abrir el archivo `User_Setup_Select.h` con un editor de texto.
3. Localizar la línea `#include <User_Setup.h>` y comentarla añadiendo dos barras al inicio:
`//#include <User_Setup.h>`
4. Localizar la línea `//#include <User_Setups/Setup206_LilyGo_T_Display_S3.h>` y descomentarla eliminando las dos barras iniciales:
`#include <User_Setups/Setup206_LilyGo_T_Display_S3.h>`
5. Guardar y cerrar el archivo.

---

## 4. Carga de Código

1. En Arduino IDE, eliminar el código de ejemplo predeterminado.
2. Pegar el código fuente del proyecto en el área de texto.
3. Seleccionar el puerto de comunicación correspondiente a la placa navegando a **Herramientas** > **Puerto**.
4. Ejecutar la carga del código haciendo clic en el botón **Subir** (ícono de flecha hacia la derecha situado en la esquina superior izquierda).
5. Esperar a que la consola inferior confirme el proceso con el mensaje "Subida completada".
6. El código QR aparecerá automáticamente en la pantalla de la placa.

---

## 5. Solución de Problemas

* **Error de compilación o pantalla en blanco tras la subida:**
Verificar la correcta modificación del archivo `User_Setup_Select.h` detallada en el paso 3D. Es indispensable guardar los cambios en dicho archivo antes de compilar.
* **Puerto no detectado por el sistema:**
Reemplazar el cable USB-C actual. Asegurarse de utilizar un cable con líneas de datos habilitadas.</User_Setups/Setup206_LilyGo_T_Display_S3.h></User_Setups/Setup206_LilyGo_T_Display_S3.h></User_Setup.h></User_Setup.h>