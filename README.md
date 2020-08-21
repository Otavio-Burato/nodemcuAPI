# nodemcuAPI

<table>
  <tr>
  <th>Circuit Scheme</th>
  <th>Server Scheme</th>
  </tr>
  <tr>
    <td><img height="500" src="https://github.com/Otavio-Burato/nodemcuAPI/blob/main/scheme.png?raw=true" alt="Circuit scheme"/></td>
    <td><img height="300" src="https://github.com/Otavio-Burato/nodemcuAPI/blob/main/server.png?raw=true" alt="Server scheme"/></td>
  </tr>
</table>

 
[fritzing](https://github.com/fritzing/fritzing-app) -
[nodemcu layout](https://github.com/roman-minyaylov/nodemcu-v3-fritzing)

[Draw.io](app.diagrams.net)

A simple code api and mqtt server for nodemcu.

**this project use libs:**

- [arduino-mqtt](https://github.com/256dpi/arduino-mqtt)<br>
This library bundles the lwmqtt MQTT 3.1.1 client and adds a thin wrapper to get an Arduino like API.

- [MQTT.js](https://github.com/mqttjs/MQTT.js)<br>
MQTT.js is a client library for the MQTT protocol, written in JavaScript for node.js and the browser.

**MQTT Broker:** ([Mosquitto](https://github.com/eclipse/mosquitto))

### How to use

Change SSID and PASSWORD in Arduino code:

``` ino
const char* ssid     = "SSID";
const char* password = "PASSWORD";
```

And your host name:

``` ino
client.begin("$HOST.local", WiFiclient);
```
**Compile code to nodemcu and run javascript/broker server with:**

yarn start

mosquitto
