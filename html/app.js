var http = require('http').createServer(servidor);
var fs = require('fs');
var five = require('johnny-five');
var arduino = new five.Board();
var led0;
var servo;


arduino.on('ready', function(){
  console.log("Arduino Pronto");

  led0 = new five.Led(13);
  servo = new five.Servo(9);
});

function servidor(req, res){
  var url = req.url;
  if(url == '/'){
    res.writeHead(200);
    res.end(fs.readFileSync('view/index.html'));
  }else if(url == '/led0'){
    res.writeHead(302, {'Location': '/'});
    res.end();
    led0.toggle();
    }else if(url == '/s180'){
    res.writeHead(302, {'Location': '/'});
    res.end();
    servo.to(180);
    }else if(url == '/s90'){
    res.writeHead(302, {'Location': '/'});
    res.end();
    servo.to(90);    
  }else{
    res.writeHead(200);
    res.end("<h1>Erro 404</h1>");
  }
};

http.listen(3000, function(){
  console.log("Servidor On-line");
});