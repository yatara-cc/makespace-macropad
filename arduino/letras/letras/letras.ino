/*
  # Letras firmware para ATMEGA32U4.

  Manda las letras “a”, “b”, “c” o “d” al ordenador según las teclas
  pulsadas.

  Pin de escribir -> cathode-diode-anode -> Pin de leer
                            --|<|--

  ## Licencia

  Para información en castellano, vease:
  https://www.gnu.org/licenses/licenses.es.html

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "Keyboard.h"



const uint8_t pin_e [] = {5, 4};
const uint8_t pin_l [] = {2, 3};
const uint8_t n_e = sizeof(pin_e) / sizeof(pin_e[0]);
const uint8_t n_l = sizeof(pin_l) / sizeof(pin_l[0]);
const uint8_t n_mx = n_e * n_l;

uint8_t matrix [n_mx] = {0};
uint8_t pulsado [n_mx] = {0};

char mapa [n_mx] = {
  'a',
  'b',
  'c',
  'd'
};



void init_pines(void) {
  // Initializar todos los pines:
  // Poner los pines de leer alto y
  // los pines de escribir bajo.
  
  for (uint8_t l = 0; l < n_l; l++) {
    pinMode(pin_l[l], INPUT_PULLUP);
  }
  for (uint8_t e = 0; e < n_e; e++) {
    pinMode(pin_e[e], OUTPUT);
    digitalWrite(pin_e[e], HIGH);
  }
}



void leer_matrix() {
  // Leer el estado de los interruptores
  // y llenar la matrix con los resultados.

  for (uint8_t e = 0; e < n_e; e++) {
    digitalWrite(pin_e[e], LOW);
    for (uint8_t l = 0; l < n_l; l++) {
      uint8_t m = n_e * l + e;
      matrix[m] = !digitalRead(pin_l[l]);
    }
    digitalWrite(pin_e[e], HIGH);
  }
}



void enviar_codigos() {
  // Enviar carácteres al ordenador según el estado
  // de la mátrix y las letras correspondientes
  // en la mapa.

  for (uint8_t l = 0; l < n_l; l++) {
    for (uint8_t e = 0; e < n_e; e++) {
      uint8_t m = n_e * l + e;
      
      if (matrix[m] && !pulsado[m]) {
        Keyboard.press(mapa[m]);
        pulsado[m] = 1;
      }
      if (!matrix[m] && pulsado[m]) {
        Keyboard.release(mapa[m]);
        pulsado[m] = 0;
      }
    }
  }
}



void setup(void) {
  // Initializar.
  // Este función ejecuta una vez al empezar.
  
  delay(500);
  Serial.begin(115200);
  
  Keyboard.begin();
  init_pines();
}



void loop(void) {
  // Este función ejecuta infinitamente en bucle.
  leer_matrix();
  enviar_codigos();
  delay(20);  // Pausar 20 millisegundos.
}


