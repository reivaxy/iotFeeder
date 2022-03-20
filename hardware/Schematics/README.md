Here is the schema. I designed it using the https://easyeda.com/ schema editor which is online, free, and brilliant.

It also allows to design the PCB and order it in a few clicks.

<img src="https://github.com/reivaxy/iotFeeder/raw/master/hardware/Schematics/Schematic_Feeder.png" width="500px">

On PCB v1 I forgot to add capacitors around the LM1117 :( PCB v2 will have them.

In theory, SCL/SDA pins should have pullup resistors, but I never used any when driving one of these OLED screens, and all worked fine, at least as long as you do not use this bus to control several devices.