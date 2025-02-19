# MobileRobotik_WS202425

## 1. Einleitung

In diesem Repository befinden sich die Dateien für die Mobile Robotik Vorlesung im Wintersemester 2024/25.

Team Move X:

- Lukas Konietzka - 2122553

- Frank Bänecke - 2068855

- Niklas Just - 2123394

## 2. Funktion

Der Roboter orientiert sich anhand der drei Ultraschallsensoren, welche die Abstände zu den Wänden rechts, links und vorne messen. Es wurde ein Algorithmus nach der Rechten-Hand-Regel implementiert. Dies bedeutet, dass der Roboter an einer Kreuzung mit mehreren Möglichkeiten immer nach rechts abbiegt.

## 3. Inbetriebnahme

### 3.1 Montage des Roboters

- Der Roboter ist nach [dieser](/doc/Aufbauanleitung.pdf) Anleitung zusammengebaut.

- Die drei Ultraschallsensoren sind auf [diesem](#6-einzelteilzeichnung-sensorhalterung) Bauteil angebracht.

- Der vordere Sensor ist so montiert, dass seine Halterung nach innen abknickt. Dadurch wird verhindert, dass der Sensor weit über die Baseplate hinausragt.

- Nicht verwendet wurden die beiden Infrarot Geschwindigkeits- / Drehzahlsensoren F249.

- Nicht verwendet wurde außerdem das Sensor Shield V5.0.

### 3.2 Hochladen der Software auf den Roboter

- Repository klonen

```bash
  git clone https://github.com/frankbits/MobileRobotik_WS202425.git
```

- [PlatformIO](https://platformio.org) Erweiterung in VS Code installieren

- Projekt auch in PlatformIO öffnen:

  ![image](/doc/readmefiles/Platformio%20Screenshot.png)

- Roboter über USB an Rechner anschließen

- Upload Taste drücken, oder Tastenkürzel Strg + Alt + U verwenden

- Roboter am Batteriefach einschalten

## 4. Limitationen

Die Probleme auf die wir während des Projektes gestoßen sind:

- Unterschiedliche starke Gleichstrommotoren erschweren das Geradeausfahren. Werden die Motoren mit dem gleichen PWM Signal angesteuert, fährt der Roboter eine Kurve. Diese ist nicht immer gleich groß.

- Dieses Problem wollten wir mit einer Regelung durch die Infrarot Drehzahlsensoren lösen. Diese konnten wir nicht so an den Roboter anbringen, dass sie zuverlässige Messergebnisse liefern. Dadurch war das Verhalten des Roboters nicht deterministisch und eine Parametrierung der Regelstrecke nicht möglich.

## 5. Verbesserungsmöglichkeiten

- Geradeausfahren mithilfe von Servomotoren sicherstellen
- 90° Kurven durch Servomotoren
- bessere Gangmittelung mithilfe der Ultraschallsensoren
- vorausschauend Sackgassen erkennen mithilfe Kartenzeichnung

# Anhang

## 1. Dömanenmodell

![image](/doc/Domain.drawio.png)

## 2. Statemachine

![image](/doc/Statemachine-State%20Machine%20for%20Right-Hand%20Rule.drawio.png)

## 3. Regelkreise

- Forward:

![image](/doc/Statemachine-Regelkreise%20Move%20Forward.drawio.png)

- Right-Hand-Rule:

![image](/doc/Statemachine-Regelkreise%20Turn%20Right%20_%20Turn%20Left.drawio.png)

## 4. Aktivitätsdiagramme

![image](/doc/Statemachine-Aktivitätsdiagramme.drawio.png)

## 5. Pinbelegungsplan

[PDF](/doc/Anschlussplan_ATmega.pdf)

## 6. Einzelteilzeichnung Sensorhalterung

[PDF](/doc/Halterung_SR04.pdf)
