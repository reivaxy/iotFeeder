# iotFeeder
Fish feeder using ESP8266, a stepper motor and an oled screen.

This is a module of the Iotinator framework (https://github.com/reivaxy/iotinator), which can also work autonomously (no master to connect to).

It's using cheap and widely available components (each under $4), and a 3D printed case.

The ESP8266 allows some WiFi access for setting the feeding times and quantities, as well as OTA firmware upgrade, the tiny Oled screen displays what's going on, and one push button helps calibrating the quantities as well as manually treat your little fishes when they deserve it.

The stepper motor allows controling with precision the amount of food dispensed.

Here is the overall aspect of the 3D printed case:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/3DPrintedCase.jpg?raw=true" width="512px"/>

Here is a working prototype:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/prototype.jpg?raw=true" width="512px"/>

The 3D design is using an Archimedes' screw:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/3DDesign.png?raw=true" width="512px"/>

In the works: A small vibrating device to shake down the tiny pellets that sometimes tend to clog and stop falling down the well especially when tank is near empty.


## COMPONENTS NEEDED

I've used this stepper driver board:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/driver.jpg?raw=true" width="100px"/>

https://www.ebay.com/itm/263017459366

To use them with the [PCB available here](hardware/PCB), you will need to unsolder the headers and solder them on the other side of the drier PCB, which is not ideal. 

This driver board was obviously not intended to be mounted on proto board but if you push hard enough, it fits :)

I might end up designing another PCB with an SMD MPF10S equivalent and the few discreete components needed to get rid of the driver board.

I've used this stepper:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/stepper.jpg?raw=true" width="100px"/>

https://www.ebay.com/itm/262537288016


Other components easy to find anywhere:

1 x ESP12

1 x LM1117 regulator (the stepper is 6V, the ESP 3.3V)

1 x Oled 0.96inch white pixels (the blue and yellow option does not age as well, and be careful with the power pins, some are reversed)

2 x push buttons (can be mounted on the PCB or wired)

3 x 22k resistors (SMD 0608 i fyou use the PCB)

1 x 6V power unit. The module needs about 500mA at peak when stepper starts, 100mA when idle 

2 x 6800ZZ bearings

About 160g of PLA filament.
