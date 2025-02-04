# MobileRobotik_WS202425

## 1. Einleitung

In diesem Repository befinden sich die Dateien für die Mobile Robotik Vorlesung im Wintersemester 2024/25.

## 2. Funktion

### 2.1. Move Forward

- Ultraschalldistanzsensoren zur Kontrolle, ob wir mittig stehen

### 2.2. Turn

- Ultraschalldistanzsensoren zur Erkennung des Drehwinkels
  1. Drehung des Sensors um 90°
  2. Drehung des Roboters
  3. Drehung des Sensors zurück bis Werte wieder gleich sind
  4. Ab 2. wiederholen bis Winkel des Sensors 0° beträgt
- Zusätzlich Kontrolle, ob wir bei der Drehung abdriften?

## 3. Verbesserungsmöglichkeiten

- vorausschauend Sackgassen erkennen

## 4. Gedanken
- eine Klasse für Movement
- eine Klasse für Sensoren auslesen
