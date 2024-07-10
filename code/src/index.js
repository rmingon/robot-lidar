import { Motor } from './motor.js';

(async () => {
    const motor = new Motor()
    await motor.i2cInit()
    motor.readWord(0x00);
    motor.setPwm(1, 4096, 0)
}) ()