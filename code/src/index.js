const i2c = require('i2c-bus');
const { Motor } = require('./motor');

(async () => {
    const motor = new Motor()
    motor.readWord(0x00);
    motor.setPwm(1, 0, 1000)
}) ()