var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {

  var accelerometer = new five.Accelerometer({
    controller: "MMA8452"
  });

   accelerometer.on("change", function() {
     console.log("accelerometer");
     console.log("  x            : ", this.x);
     console.log("  y            : ", this.y);
     console.log("  z            : ", this.z);
     console.log("  pitch        : ", this.pitch);
     console.log("  roll         : ", this.roll);
     console.log("  acceleration : ", this.acceleration);
     console.log("  inclination  : ", this.inclination);
     console.log("  orientation  : ", this.orientation);
     console.log("--------------------------------------");
   });

  //["tap", "tap:single", "tap:double"].forEach(function(event) {
    //accelerometer.on(event, function() {
      //console.log(event);
    //});
  //});
});