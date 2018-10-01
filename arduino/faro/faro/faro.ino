/*
  # Faro firmware para ATMEGA32U4.

  Lanza destellos por los LEDs integrados para confirmar que funcione
  la placa y el proceso de enviar el firmware.

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



// Definir macros para los LEDs del ATMEGA32U4.
#define TXLED0			PORTD |= (1<<5)
#define TXLED1			PORTD &= ~(1<<5)
#define RXLED0			PORTB |= (1<<0)
#define RXLED1			PORTB &= ~(1<<0)
#define TXLEDX                  DDRD &= ~(1<<DDD5);
#define RXLEDX                  DDRB &= ~(1<<DDB0);
    


void setup(void) {
  // Initializar.
  // Este función ejecuta una vez al empezar.
  // tiene que existir aunque no haga nada.
}



void loop(void) {
  // Este función ejecuta infinitamente en bucle.

  TXLED1;
  delay(500);
  TXLED0;
  delay(500);
}


