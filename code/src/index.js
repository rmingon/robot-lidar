import { Motor } from './motor.js';


const sleep = (microsecond) => {
    return new Promise((resolve) => {
        setTimeout(resolve, microsecond)
    })
}
(async () => {
    const motor = new Motor()
    await motor.i2cInit()
    motor.readWord(0x00);
    while(1) {
        sleep(1000)
        motor.setPwm(1, 0, 4095)
        sleep(1000)
        motor.setPwm(1, 4095, 0)
    }
}) ()