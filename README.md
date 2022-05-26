# Practica-8: BUSES DE COMUNICACIÓN IV

En aquesta pràctica realitzarem un bucle de comunicacions de manera que les dades enviades des del terminal rdx0 es redirigeixin a 
la uart 2 txd2 i les dades enviades a aquest uart 2 les reenvii de nou a la sortida del terminal rdx0 per tal que puguem veure el que 
hem escrit des de teclat a través de la nostra pantalla.

Aquesta pràctica, a diferència de totes les altres, nosaltres som els encarregats de realitzar el codi, adjuntat prèviament a la part 
del main. És un exercici senzill, és per això que no hem tingut masses problemes a realitzar el codi però al ser un exercici senzill 
no se'ns ha fet complicat ja que hem adquirit coneixements al llarg de totes les pràctiques passades.

# Material

Pràctica en la qual només ens fa falta la ESP32.

# Funcionament

El funcionament és senzill. Definim els 2 ports, RXD2 al pin 16 i TXD2 al pin 17.

```c++
#include <Arduino.h>
#define RXD2 16
#define TXD2 17
```

Entrem al loop i veiem el primer while, aquest, si detecta que el primer Serial està lliure, el que fa és print al caràcter 
enviat pel 2n Serial 

```c++
void loop() {
while (Serial.available()) 
    {
      Serial2.print(char(Serial.read()));
    }
```


i el segon while fa exactament el mateix però començant des del 2n Serial, és a dir, llegeix si el Serial2 està lliure
i si ho està envia el contingut (el caràcter) cap al Serial1, és per això que nosaltres podem veure per pantalla el que escrivim 
des del nostre propi teclat.

```c++
while (Serial2.available()) 
    {
      Serial.print(char(Serial2.read()));
    } 
}
```

En resum, el que fa aquest codi és enviar el caràcter que nosaltres hem escrit des del pin 16 al 17, aquest ho llegeix i l'envia un altre cop
del 17 al 16, fet que fa que puguem veure el que escrivim per la pantalla.

El funcionament es pot veure al vídeo adjuntat al repositori.
