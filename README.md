elm327 VAG (Volkswagen/Audi/Porsche) firmware
---------------------------------------------

replacement firmware for the elm327 to interact with VAG cars.


flash elm327/dist/default/production/elm327.production.hex


see https://youtu.be/Pt6VR4PJDXg



commands
-----

commands are a single character. newline is ignored, but may be nessesary for your tty to flush.
The chip gets stuck easily if you send too much stuff, so try to only send commands after receiving state: ready

    v: get VIN
    s: get State Of Charge


output
-----

all output is colon separated. the left hand side is key, the right hand side value.

    state: ready | busy
    value vin: ABC123
    value soc: 73.2 %
    error: vehicle on fire




