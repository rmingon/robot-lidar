import { Motor } from './motor.js';

(async () => {
    const motor = new Motor()
    motor.readWord(0x00);
    motor.setPwm(1, 0, 1000)
}) ()