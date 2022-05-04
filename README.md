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

So funktioniert's: Die drei Unterordner in "code" beschreiben jeweils ein Platformio-Projekt für einen Arduino. Zu dritt bilden diese eine Zeitmessung. 
Hier ein Auszug aus einem Forum über das Zusammenspiel:

Aktuelle Version auf Git (18:00 MEZ):

-- Messeinheit gesteuert durch Interrupts: Misst Zeit zwischen Interrupt 0 und Interrupt 1.
-- Benutzeroberfläche: 2 Taster so geschaltet, dass drei verschiedene Ausgangssignale erzeugt werden können (einer, beide), wobei die einer-gedrückt-Stellung jeweils an die Steuereinheit weitergegeben wird
-- Steuereinheit: Unfunktionabel

 

In der Pipeline (hoffentlich bis heute Abend, Updates hier im Forum):

-- Benutzerschnittstelle: 2 Taster binär geschaltet für 4 Signale, die an Steuereinheit weitergegeben werden können

-- Steuereinheit: Je nach Signaleingang double- float- oder diverse andere Berechnung (Erweiterungspotential), bei Start und Ende jeweils Ausgabe für Messeinheit

-- Messeinheit: Keine Änderung geplant, möglicherweise noch bessere Zeitdauerausgabe.

 

Zukunft (In Bezug auf Übungsaufgabe, kein Zeitrahmen, Änderung vorbehalten):

-- Benutzerschnittstelle: Joystick und Ultraschallsensor jeweils über ADC angeschlossen, Datenweitergabe an Steuereinheit. 

                   //Zusätzliches Feature, Taster bleiben erhalten, voraussichtlich "Beide gedrückt" als Umschalten zwischen "Joystick-Daten" und "Trigger double/float-Berechnung"

-- Steuereinheit: Joystick-Daten sollen die mehrfarbige LED steuern, Ultraschallsensordaten sollen bei Betreten eines bestimmten Bereichs "RUPT_0" triggern, bei Verlassen "RUPT_1"

                  //Zusätzliches Feature, Berechnungen float/double bleiben erhalten. (Fragwürdig ob sich der Aufwand lohnt, die Daten hier zu übertragen oder ob das doch am selben Arduino geschehen soll. Generelles Problem ist hier aber sowieso die LED-Ansteuerung über PWM-Signale.)

-- Messeinheit: Keine Änderung geplant. Möglicherweise Ausgabeverbesserung: Weitergabe über dritten PIN, ob gerade float/double-Berechungszeit oder Näherungszeit gemessen wird

 

Wir freuen uns auf Commits, Issues, Teil-Implementationen, Ideen,...

---

## Aufgaben

- [ ] Fertig machen (readme)
