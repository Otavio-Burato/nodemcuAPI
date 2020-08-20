var mqtt = require('mqtt'), url = require('url');
const express = require('express')
const app = express()

var mqtt_url = url.parse('mqtt://localhost:1883');
var url = "mqtt://" + mqtt_url.host;

var options = {
    port: mqtt_url.port,
    clientId: 'mqttjs_' + Math.random().toString(16).substr(2, 8),
};

var client = mqtt.connect(url, options);
let value = 0;

value = client.on('connect', function() {
    let data;
    data = client.subscribe('message', function() {
        let data;
        data = client.on('message', function(topic, message, packet) {
            value = JSON.parse(message);
        });
    });
});

app.get('/', (req, res) => {
    console.log(value);
    res.send("value: "+value);
})

app.listen(3000);

