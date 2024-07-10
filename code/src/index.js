const i2c = require('i2c-bus');

const MCP9685_ADDR = 0x40;
const STATE_REG = 0x05;

(async () => {
    const i2cState = await i2c.openPromisified(1)
    const rawData = await i2cState.readWord(MCP9685_ADDR, STATE_REG)
    console.log(rawData);
}) ()