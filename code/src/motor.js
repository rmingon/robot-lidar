import i2c from 'i2c-bus'



const MCP9685_ADDR = 0x70;

const PCA9685_MODE1 = 0x00      /**< Mode Register 1 */
const PCA9685_MODE2 = 0x01      /**< Mode Register 2 */
const PCA9685_SUBADR1 = 0x02    /**< I2C-bus subaddress 1 */
const PCA9685_SUBADR2 = 0x03    /**< I2C-bus subaddress 2 */
const PCA9685_SUBADR3 = 0x04    /**< I2C-bus subaddress 3 */
const PCA9685_ALLCALLADR = 0x05 /**< LED All Call I2C-bus address */
const PCA9685_LED0_ON_L = 0x06  /**< LED0 on tick, low byte*/
const PCA9685_LED0_ON_H = 0x07  /**< LED0 on tick, high byte*/
const PCA9685_LED0_OFF_L = 0x08 /**< LED0 off tick, low byte */
const PCA9685_LED0_OFF_H = 0x09 /**< LED0 off tick, high byte */
// etc all 16:  LED15_OFF_H 0x45
const PCA9685_ALLLED_ON_L = 0xFA  /**< load all the LEDn_ON registers, low */
const PCA9685_ALLLED_ON_H = 0xFB  /**< load all the LEDn_ON registers, high */
const PCA9685_ALLLED_OFF_L = 0xFC /**< load all the LEDn_OFF registers, low */
const PCA9685_ALLLED_OFF_H = 0xFD /**< load all the LEDn_OFF registers,high */
const PCA9685_PRESCALE = 0xFE     /**< Prescaler for PWM output frequency */
const PCA9685_TESTMODE = 0xFF     /**< defines the test mode to be entered */

// MODE1 bits
const MODE1_ALLCAL = 0x01  /**< respond to LED All Call I2C-bus address */
const MODE1_SUB3 = 0x02    /**< respond to I2C-bus subaddress 3 */
const MODE1_SUB2 = 0x04    /**< respond to I2C-bus subaddress 2 */
const MODE1_SUB1 = 0x08    /**< respond to I2C-bus subaddress 1 */
const MODE1_SLEEP = 0x10   /**< Low power mode. Oscillator off */
const MODE1_AI = 0x20      /**< Auto-Increment enabled */
const MODE1_EXTCLK = 0x40  /**< Use EXTCLK pin clock */
const MODE1_RESTART = 0x80 /**< Restart enabled */
// MODE2 bits
const MODE2_OUTNE_0 = 0x01 /**< Active LOW output enable input */
const MODE2_OUTNE_1 = 0x02 /**< Active LOW output enable input - high impedience */
const MODE2_OUTDRV = 0x04 /**< totem pole structure vs open-drain */
const MODE2_OCH = 0x08    /**< Outputs change on ACK vs STOP */
const MODE2_INVRT = 0x10  /**< Output logic state inverted */

const PCA9685_PRESCALE_MIN = 3   /**< minimum prescale value */
const PCA9685_PRESCALE_MAX = 255 /**< maximum prescale value */



export class Motor {
    i2c = null

    constructor() {
        this.__i2cInit()
    }

    async __i2cInit() {
        this.i2c = await i2c.openPromisified(1)
    }

    async readWord(addr) {
        return this.i2c.readByte(MCP9685_ADDR, addr)
    }

    async setPwm(num, on, off) {
        const buffer = [];
        buffer[0] = PCA9685_LED0_ON_L + 4 * num;
        buffer[1] = on;
        buffer[2] = on >> 8;
        buffer[3] = off;
        buffer[4] = off >> 8;
        console.log(buffer)
    }

}