
<!--

author:   Fabian Bart, Bastian Zötzel
email:    zeitmessung@informatic-freak.de

version:  1.0.0
language: de
narrator: Deutsch Female

import:  https://raw.githubusercontent.com/liascript-templates/plantUML/master/README.md
         https://github.com/LiaTemplates/AVR8js/main/README.md
         https://github.com/LiaTemplates/Pyodide

icon: https://upload.wikimedia.org/wikipedia/commons/d/de/Logo_TU_Bergakademie_Freiberg.svg

-->

[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://github.com/Voetzl/Zeitmessung/blob/main/README.md)

# Zeitmessung

![es blinkt](docs/es-blinkt.gif)

**So funktioniert's:**

Dieses Projekt zur Zeitmessung besteht aus drei [PlatformIO](https://platformio.org/)-Projekten für den [Arduino Uno](https://store.arduino.cc/products/arduino-uno-rev3).

>Wir freuen uns auf Commits, Issues, Teil-Implementationen, Ideen, ...

## Bestandteile

<!-- style="display: block; margin-left: auto; margin-right: auto; max-width: 1000px;" -->
```ascii
+-----------------------+              +---------------+                   +-------------+
|                       |              |               |                   |             |
| Benutzerschnittstelle | -- Modus --> | Steuereinheit | -- Interrupts --> | Messeinheit |
|                       |              |               |                   |             |
+-----------------------+              +---------------+                   +-------------+
```

                          {{0-3}}
********************************************************************************

**Messeinheit:**

- misst vergangene Zeit zwischen zwei ausgelösten externen Interrupts

********************************************************************************

                          {{1-3}}
********************************************************************************

**Benutzerschnittstelle:**

- 2 Taster werden zur Kodierung von drei verschiedenen Ausgangssignal-Modi verwendet
	- `01` Modus 1
	- `10` Modus 2
	- `11` Modus 3

- sendet gewählten Modus an Steuereinheit

********************************************************************************

                          {{2-3}}
********************************************************************************

**Steuereinheit:**

- verabeitet den Modus und führt zugehörige Aktionen aus

********************************************************************************

## Änderungen & Pläne

### Geplante Änderungen

                          {{0-3}}
********************************************************************************

**Messeinheit:**

- bessere Darstellung der Messergebnisse

********************************************************************************

                          {{1-3}}
********************************************************************************

**Benutzerschnittstelle:**

- Verarbeitung der Taster-Eingaben und weitergabe an die Steuereinheit

********************************************************************************

                          {{2-3}}
********************************************************************************

**Steuereinheit:**

- Verarbeitung des Signal-Modus und Ausführung der zugehörigen `double` bzw. `float` oder diversen anderen Berechnungen

********************************************************************************

### Zukünftige Pläne

                          {{0-3}}
********************************************************************************

**Messeinheit:**

- Keine Änderung geplant. Möglicherweise Ausgabeverbesserung: Weitergabe über dritten PIN, ob gerade float/double-Berechungszeit oder Näherungszeit gemessen wird

********************************************************************************

                          {{1-3}}
********************************************************************************

**Benutzerschnittstelle:**

- Joystick und Ultraschallsensor jeweils über `ADC` angeschlossen, Datenübertragung an Steuereinheit

>*Zusätzliche Features*
>
>Taster bleiben erhalten, voraussichtlich "Beide gedrückt" als Umschalten zwischen "Joystick-Daten" und "Trigger double/float-Berechnung"

********************************************************************************

                          {{2-3}}
********************************************************************************

**Steuereinheit:**

- Joystick-Daten sollen die mehrfarbige LED steuern, Ultraschallsensordaten sollen bei Betreten eines bestimmten Bereichs `INT0` triggern, bei Verlassen `INT1`

>*Zusätzliche Features*
>
>Berechnungen float/double bleiben erhalten. (Fragwürdig ob sich der Aufwand lohnt, die Daten hier zu übertragen oder ob das doch am selben Arduino geschehen soll. Generelles Problem ist hier aber sowieso die LED-Ansteuerung über PWM-Signale.)

********************************************************************************
