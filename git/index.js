// obter o código da biblioteca
const five = require("johnny-five");
const mqtt = require('mqtt');
const dadosMqtt = {
  host: 'm10.cloudmqtt.com',
  port: '13038',
  username: 'rodolfo',
  password: 'rodolfo',
};
// criar uma instância que representa nossa placa
const board = new five.Board({
  port: "COM4" // substitua pela porta a qual seu Arduino estiver conectado
});

var client = mqtt.connect(dadosMqtt);
var on = 180;

client.on('connect', function () {
  client.subscribe('LED')
  console.log("conectado");
  //vincular código a ser rodado quando a comunicação com a placa começar
  board.on("ready", function () {
    console.log("placa ok");
    // vincular uma variável do tipo Led que controla o pino 13
    const led = new five.Led(10);
    const led2 = new five.Led(11);
    const botao = new five.Button(7);
    const botao2 = new five.Button(4);
    const servo = new five.Servo(9);
    const relay = new five.Relay(12);

    botao.on("down", function () {
      led.stop();
      led2.stop();
      led.toggle();
      led2.toggle();

    });
    botao.on("hold", function () {
      led.pulse(500);
      led2.pulse(500);
    });
    botao2.on("down", function () {
      if (on == 90) {
        servo.to(180);
        led.on();
        led2.on();
        relay.close();
        on = 180;
      } else {
        servo.to(90);
        led.off();
        led2.off();
        relay.open();
        on = 90
      }
    });

    client.on('message', function (topic, message) {
      console.log(message.toString())
      switch (message.toString()) {
        case "on":
          led.on();
          led2.on();
          break;
        case "off":
          led.off();
          led2.off();
          break;
        case "abrir":
          servo.to(180);
          led.on();
          led2.on();
          relay.close();
          break;
        case "fechar":
          servo.to(90);
          led.off();
          led2.off();
          relay.open();
          break;
      }
    });
  });
});