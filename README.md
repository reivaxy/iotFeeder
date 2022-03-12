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


In the works: A second push button to make the motor go backwards by a few steps in case something gets stuck (I had this issue once with big pellets), and a vibrating device to shake down the tiny pellets that sometimes tend to clog and stop falling down the well.
