OBD2
---
can is on pin 6 and 14
see section "Finding CAN Connections" in  http://opengarages.org/handbook/ebook/

on a VW, the only thing reachable from the obd can bus is the can gateway.
you cannot talk to any other system directly, and the bus is silent unless you send a request.

This is a volksagen specific odb diagnostics tool attempting to start a session with the gateway.


```
root@raspberrypi:~# candump can0
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  200   [7]  01 C0 00 10 00 03 01
  can0  000   [1]  A8
  can0  7E0   [8]  02 10 03 55 55 55 55 55
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  200   [3]  01 C0 A0
  can0  7A0   [1]  A8
  can0  7E0   [8]  02 09 00 55 55 55 55 55
  can0  7DF   [8]  02 09 00 55 55 55 55 55
```


apparantly 200 is the gateway. They use some sort of session protocol on top of canbus that
requests a pair of canbus ids from the gateway that is used for the rest of the communication.

https://forum.macchina.cc/t/how-to-read-vw-can-bus/655/8


to get this dump i'm using an mcp2515 and a raspberry pi.
The shield i bought had a fixed 120Ohm resistor across the can lines,
so i desoldered it and replaced it with a resistor in the cable assembly.
CAN needs a 120Ohm on start and end of the bus, but a sniffer will probably be in the middle instead.


next step
---------

attach the diagnostics to the real car and sniff it using a splitter cable
