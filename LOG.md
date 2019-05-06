OBD2
---

see https://www.youtube.com/watch?v=n-XoLvICheI



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


next attached the diagnostics to the real car and sniffed it using a splitter cable

day 2
-------


gateway did not react to 200, instead it reacted to 7E0 messages with 7E8
that appears to be "unified diagnostic services" protocol, specifically ISO-14229


    7E0   [8]  02 10 03 55 55 55 55 55

might mean:  2 additional bytes, odb2 mode 10 and pid 03,

the response was:

    7E8 [8] 06 50 03 00 1E 01 E0 55

which makes me believe its actually "Diagnostic Session Control",
because there's something about request $10 response $50


there's a python implementation of the protocol that i need to look through
https://github.com/pylessard/python-udsoncan


day 3
-------

pylessard knows UDS rather well, so i emailed him directly and he was extremly helpful.
we're sure its UDS.  the relevant message is

    765   [8]  03 22 1D D0 55 55 55 55

- 03 : Byte from the IsoTp Layer. Tells that the data of the frame fully contained in a single Can message and there is 3 bytes of data
- 22 : Service ID - ReadDataByIdentifier.  Basically the command number saying you want to read a value from the ECU
- 1DD0 : The ID of the value to read. I would believe that the SOC is identified by this value.
- 55 55 55 55 : Meaningless padding


response is:

    7CF   [8]  04 62 1D D0 B6 AA AA AA

- 04 : Same as above, with 4 bytes of data instead
- 62 : Response to service ID 0x22 (0x22 + 0x40). Response are always +0x40.
- 1DD0 : The ID of the value to read.
- B6 : The relevant value
- AA AA AA : Meaningless padding.


he also said we might need to init a UDS session this way:

    765   [8]  02 10 03 55 55 55 55 55
    7CF   [8]  06 50 03 00 32 01 F4 AA


"Tester change the session ID 3  (ExtendedDiagnosticSession).
ECU confirms the change and provide some session data : 003201F4. This data is manufacturer specific. The same data is given everytime the session changes, being ExtendedDiagnosticSession or DefaultSession"


day 4
-------

ELM327 cannot send these messages. Would have been nice, since its dirt cheap and CE certified (allegedly).
i tried to reverse engineer the elm327, since it's just a pic mcu, but i couldnt figure out how the bluetooth module works.
After reflashing the PIC, it no longer advertises, which makes me believe it needs an init sequence before it becomes a uart bridge.

day 5
-------

ignoring the interfacing problem for now, going into the dcan with my rpi.
To make the rpi work as a can end-device (instead of between the gateway and the VAG tool), i put a 120Ohm back across the H/L lines.

Pier-Yves was spot on with the value. It decreases as i drain the HV Battery
(with the AC because that eats more power than driving).

The session thing is not needed to get this specific value i want, but might be needed for others.
The protocol is a fairly simple request response thing, on a very quiet can line. I'm confident this can be done with a cheap mcu, like the pic18f in the elm327.
I just need to figure out the bluetooth chip.


day 6
------
ELM327 is a pic18f25k80, so it flashable with something else. All the code is in this repo.





