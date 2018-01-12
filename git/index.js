// obter o código da biblioteca
const five = require("johnny-five");
var on = false;

// criar uma instância que representa nossa placa
const board = new five.Board({
  port: "COM4" // substitua pela porta a qual seu Arduino estiver conectado
});

// vincular código a ser rodado quando a comunicação com a placa começar
board.on("ready", function() {

  // vincular uma variável do tipo Led que controla o pino 13
  const led = new five.Led(10);
  const led2 = new five.Led(11);
  const botao = new five.Button(7);

  botao.on ("down", function() {
    led.stop();
    led2.stop();  
    led.toggle();
    led2.toggle();
    });
  botao.on ("hold", function() {
    led.pulse(500);
    led2.pulse(500);
 });

  
  // piscar o led a cada 500ms
  //led.blink(500);
  //led2.blink(500);

  //this.repl.inject({
   // led: led
  //});

  //led.toggle();
});