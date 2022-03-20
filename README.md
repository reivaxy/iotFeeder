# iotFeeder
Fish feeder using ESP8266, a stepper motor and an oled screen.

This will be a module of the Iotinator framework (https://github.com/reivaxy/iotinator), which can already work autonomously (no master module is needed).

It's using cheap and widely available components (each under $4), a 3D printed case, and an optional PCB.

The ESP8266 allows some WiFi access for setting the feeding times and quantities, as well as OTA firmware upgrade, the tiny Oled screen displays what's going on, and one push button helps calibrating the quantities as well as manually treat your little fishes when they deserve it.

The stepper motor allows controling with precision the amount of food dispensed.

Here is the overall aspect of the 3D printed case:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/3DPrintedCase.jpg?raw=true" width="512px"/>

Here is a working prototype:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/prototype.jpg?raw=true" width="512px"/>

The 3D design is using an Archimedes' screw:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/3DDesign.jpg?raw=true" width="512px"/>

Here is a short demo with the prototype showing the configuration page, then the Oled screen, then the dispensing of one programmed serving.

https://youtu.be/9wqxyTTBjuU

## COMPONENTS NEEDED

I've used this stepper driver board but I guess others should work:

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/driver.jpg?raw=true" width="200px"/>

https://www.ebay.com/itm/263017459366

To use them with the [PCB available here](hardware/PCB), you will need to unsolder the headers and solder them on the other side of the driver PCB, which is not ideal. 

This driver board was obviously not intended to be mounted on proto board but if you push hard enough, it fits :)

I might end up designing another PCB with an SMD MPF10S equivalent and the few discreete components needed to get rid of the driver board.

I've used this stepper, so the case is designed to accomodate it, but since it's mounted on an [independant plate](https://github.com/reivaxy/iotFeeder/blob/master/hardware/3DFiles/stepperPlate.stl), adaptation to another stepper could be easy if within the overall dimensions.

<img src="https://github.com/reivaxy/iotFeeder/blob/master/resources/stepper.jpg?raw=true" width="200px"/>

https://www.ebay.com/itm/262537288016


Other components easy to find anywhere:

1 x ESP12 but it also works on a D1_mini or node MCU.

1 x LM1117 regulator (the stepper is 6V, the ESP 3.3V)

1 x Oled 0.96inch white pixels (the split blue & yellow screen does not age as well, and be careful with the power pins, some are reversed)

2 x push buttons (can be mounted on the [PCB](hardware/PCB) or wired)

3 x 22k resistors (SMD 0806 if you use the [PCB](hardware/PCB))

1 x 6V power unit. The module needs about 500mA at peak when stepper starts, 100mA when idle 

1 x power jack socket

2 x 6800ZZ bearings

2 hex bolts m3x16 to mount the stepper on the stepper plate

8 Philips self tapping flat head screws m2x12 : 
- 4 to attach the stepper plate to the case
- 4 to attach the back panel to the case

 
About 160g of PLA filament.
