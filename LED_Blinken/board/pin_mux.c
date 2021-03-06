/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v7.0
processor: MK22FN512xxx12
package_id: MK22FN512VLL12
mcu_data: ksdk2_0
processor_version: 7.0.1
pin_labels:
- {pin_num: '45', pin_signal: PTA15/SPI0_SCK/UART0_RX/I2S0_RXD0, label: LED_RED_RR, identifier: LED_A;LED_RED_RR}
- {pin_num: '47', pin_signal: ADC1_SE17/PTA17/SPI0_SIN/UART0_RTS_b/I2S0_MCLK, label: LED_RED_RL, identifier: LED_RED_RL}
- {pin_num: '80', pin_signal: ADC1_SE4b/CMP0_IN2/PTC8/FTM3_CH4/I2S0_MCLK/FB_AD7, label: LED_GREEN_FL, identifier: LED_GREEN_FL}
- {pin_num: '81', pin_signal: ADC1_SE5b/CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/FTM2_FLT0, label: LED_RED_FL, identifier: LED_GREEN_FL;LED_RED_FL}
- {pin_num: '82', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5, label: LED_BLUE_FL, identifier: LED_GREEN_FL;LED_BLUE_FL}
- {pin_num: '83', pin_signal: ADC1_SE7b/PTC11/LLWU_P11/I2C1_SDA/FTM3_CH7/FB_RW_b, label: LED_GREEN_FR, identifier: LED_GREEN_FR}
- {pin_num: '95', pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FB_AD4/LPUART0_RX/I2C0_SCL, label: LED_RED_FR, identifier: LED_RED_FR}
- {pin_num: '96', pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FB_AD3/LPUART0_TX/I2C0_SDA, label: LED_BLUE_FR, identifier: LED_BLUE_FR}
- {pin_num: '53', pin_signal: ADC0_SE8/ADC1_SE8/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/FTM1_QD_PHA, label: JS_RIGHT, identifier: JS_RIGHT}
- {pin_num: '54', pin_signal: ADC0_SE9/ADC1_SE9/PTB1/I2C0_SDA/FTM1_CH1/FTM1_QD_PHB, label: JS_DOWN, identifier: JS_DOWN}
- {pin_num: '55', pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3, label: JS_UP, identifier: JS_UP}
- {pin_num: '56', pin_signal: ADC0_SE13/PTB3/I2C0_SDA/UART0_CTS_b/FTM0_FLT0, label: JS_PUSH, identifier: JS_PUSH}
- {pin_num: '57', pin_signal: PTB9/SPI1_PCS1/LPUART0_CTS_b/FB_AD20, label: JS_LEFT, identifier: JS_LEFT}
- {pin_num: '21', pin_signal: ADC1_DM0/ADC0_DM3, label: test, identifier: test}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    LED();
    Joystick();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
LED:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '45', peripheral: GPIOA, signal: 'GPIO, 15', pin_signal: PTA15/SPI0_SCK/UART0_RX/I2S0_RXD0, identifier: LED_RED_RR, direction: OUTPUT}
  - {pin_num: '47', peripheral: GPIOA, signal: 'GPIO, 17', pin_signal: ADC1_SE17/PTA17/SPI0_SIN/UART0_RTS_b/I2S0_MCLK, direction: OUTPUT}
  - {pin_num: '80', peripheral: GPIOC, signal: 'GPIO, 8', pin_signal: ADC1_SE4b/CMP0_IN2/PTC8/FTM3_CH4/I2S0_MCLK/FB_AD7, direction: OUTPUT}
  - {pin_num: '81', peripheral: GPIOC, signal: 'GPIO, 9', pin_signal: ADC1_SE5b/CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/FTM2_FLT0, identifier: LED_RED_FL, direction: OUTPUT}
  - {pin_num: '82', peripheral: GPIOC, signal: 'GPIO, 10', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5, identifier: LED_BLUE_FL, direction: OUTPUT}
  - {pin_num: '83', peripheral: GPIOC, signal: 'GPIO, 11', pin_signal: ADC1_SE7b/PTC11/LLWU_P11/I2C1_SDA/FTM3_CH7/FB_RW_b, direction: OUTPUT}
  - {pin_num: '95', peripheral: GPIOD, signal: 'GPIO, 2', pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FB_AD4/LPUART0_RX/I2C0_SCL, direction: OUTPUT}
  - {pin_num: '96', peripheral: GPIOD, signal: 'GPIO, 3', pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FB_AD3/LPUART0_TX/I2C0_SDA, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : LED
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void LED(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);

    gpio_pin_config_t LED_RED_RR_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA15 (pin 45)  */
    GPIO_PinInit(LED_LED_RED_RR_GPIO, LED_LED_RED_RR_PIN, &LED_RED_RR_config);

    gpio_pin_config_t LED_RED_RL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA17 (pin 47)  */
    GPIO_PinInit(LED_LED_RED_RL_GPIO, LED_LED_RED_RL_PIN, &LED_RED_RL_config);

    gpio_pin_config_t LED_GREEN_FL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC8 (pin 80)  */
    GPIO_PinInit(LED_LED_GREEN_FL_GPIO, LED_LED_GREEN_FL_PIN, &LED_GREEN_FL_config);

    gpio_pin_config_t LED_RED_FL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC9 (pin 81)  */
    GPIO_PinInit(LED_LED_RED_FL_GPIO, LED_LED_RED_FL_PIN, &LED_RED_FL_config);

    gpio_pin_config_t LED_BLUE_FL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC10 (pin 82)  */
    GPIO_PinInit(LED_LED_BLUE_FL_GPIO, LED_LED_BLUE_FL_PIN, &LED_BLUE_FL_config);

    gpio_pin_config_t LED_GREEN_FR_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC11 (pin 83)  */
    GPIO_PinInit(LED_LED_GREEN_FR_GPIO, LED_LED_GREEN_FR_PIN, &LED_GREEN_FR_config);

    gpio_pin_config_t LED_RED_FR_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD2 (pin 95)  */
    GPIO_PinInit(LED_LED_RED_FR_GPIO, LED_LED_RED_FR_PIN, &LED_RED_FR_config);

    gpio_pin_config_t LED_BLUE_FR_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD3 (pin 96)  */
    GPIO_PinInit(LED_LED_BLUE_FR_GPIO, LED_LED_BLUE_FR_PIN, &LED_BLUE_FR_config);

    /* PORTA15 (pin 45) is configured as PTA15 */
    PORT_SetPinMux(LED_LED_RED_RR_PORT, LED_LED_RED_RR_PIN, kPORT_MuxAsGpio);

    /* PORTA17 (pin 47) is configured as PTA17 */
    PORT_SetPinMux(LED_LED_RED_RL_PORT, LED_LED_RED_RL_PIN, kPORT_MuxAsGpio);

    /* PORTC10 (pin 82) is configured as PTC10 */
    PORT_SetPinMux(LED_LED_BLUE_FL_PORT, LED_LED_BLUE_FL_PIN, kPORT_MuxAsGpio);

    /* PORTC11 (pin 83) is configured as PTC11 */
    PORT_SetPinMux(LED_LED_GREEN_FR_PORT, LED_LED_GREEN_FR_PIN, kPORT_MuxAsGpio);

    /* PORTC8 (pin 80) is configured as PTC8 */
    PORT_SetPinMux(LED_LED_GREEN_FL_PORT, LED_LED_GREEN_FL_PIN, kPORT_MuxAsGpio);

    /* PORTC9 (pin 81) is configured as PTC9 */
    PORT_SetPinMux(LED_LED_RED_FL_PORT, LED_LED_RED_FL_PIN, kPORT_MuxAsGpio);

    /* PORTD2 (pin 95) is configured as PTD2 */
    PORT_SetPinMux(LED_LED_RED_FR_PORT, LED_LED_RED_FR_PIN, kPORT_MuxAsGpio);

    /* PORTD3 (pin 96) is configured as PTD3 */
    PORT_SetPinMux(LED_LED_BLUE_FR_PORT, LED_LED_BLUE_FR_PIN, kPORT_MuxAsGpio);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
Joystick:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '53', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: ADC0_SE8/ADC1_SE8/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/FTM1_QD_PHA, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled,
    slew_rate: slow, pull_select: up, pull_enable: enable}
  - {pin_num: '54', peripheral: GPIOB, signal: 'GPIO, 1', pin_signal: ADC0_SE9/ADC1_SE9/PTB1/I2C0_SDA/FTM1_CH1/FTM1_QD_PHB, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled,
    slew_rate: slow, pull_select: up, pull_enable: enable}
  - {pin_num: '55', peripheral: GPIOB, signal: 'GPIO, 2', pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled,
    slew_rate: slow, pull_select: up, pull_enable: enable}
  - {pin_num: '56', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: ADC0_SE13/PTB3/I2C0_SDA/UART0_CTS_b/FTM0_FLT0, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled,
    slew_rate: slow, pull_select: up, pull_enable: enable}
  - {pin_num: '57', peripheral: GPIOB, signal: 'GPIO, 9', pin_signal: PTB9/SPI1_PCS1/LPUART0_CTS_b/FB_AD20, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled,
    slew_rate: slow, pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : Joystick
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void Joystick(void)
{
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);

    gpio_pin_config_t JS_RIGHT_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB0 (pin 53)  */
    GPIO_PinInit(JOYSTICK_JS_RIGHT_GPIO, JOYSTICK_JS_RIGHT_PIN, &JS_RIGHT_config);

    gpio_pin_config_t JS_DOWN_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB1 (pin 54)  */
    GPIO_PinInit(JOYSTICK_JS_DOWN_GPIO, JOYSTICK_JS_DOWN_PIN, &JS_DOWN_config);

    gpio_pin_config_t JS_UP_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB2 (pin 55)  */
    GPIO_PinInit(JOYSTICK_JS_UP_GPIO, JOYSTICK_JS_UP_PIN, &JS_UP_config);

    gpio_pin_config_t JS_PUSH_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB3 (pin 56)  */
    GPIO_PinInit(JOYSTICK_JS_PUSH_GPIO, JOYSTICK_JS_PUSH_PIN, &JS_PUSH_config);

    gpio_pin_config_t JS_LEFT_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB9 (pin 57)  */
    GPIO_PinInit(JOYSTICK_JS_LEFT_GPIO, JOYSTICK_JS_LEFT_PIN, &JS_LEFT_config);

    /* PORTB0 (pin 53) is configured as PTB0 */
    PORT_SetPinMux(JOYSTICK_JS_RIGHT_PORT, JOYSTICK_JS_RIGHT_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB0 (pin 53): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(JOYSTICK_JS_RIGHT_PORT, JOYSTICK_JS_RIGHT_PIN, kPORT_InterruptOrDMADisabled);

    PORTB->PCR[0] = ((PORTB->PCR[0] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB1 (pin 54) is configured as PTB1 */
    PORT_SetPinMux(JOYSTICK_JS_DOWN_PORT, JOYSTICK_JS_DOWN_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB1 (pin 54): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(JOYSTICK_JS_DOWN_PORT, JOYSTICK_JS_DOWN_PIN, kPORT_InterruptOrDMADisabled);

    PORTB->PCR[1] = ((PORTB->PCR[1] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB2 (pin 55) is configured as PTB2 */
    PORT_SetPinMux(JOYSTICK_JS_UP_PORT, JOYSTICK_JS_UP_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB2 (pin 55): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(JOYSTICK_JS_UP_PORT, JOYSTICK_JS_UP_PIN, kPORT_InterruptOrDMADisabled);

    PORTB->PCR[2] = ((PORTB->PCR[2] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB3 (pin 56) is configured as PTB3 */
    PORT_SetPinMux(JOYSTICK_JS_PUSH_PORT, JOYSTICK_JS_PUSH_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB3 (pin 56): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(JOYSTICK_JS_PUSH_PORT, JOYSTICK_JS_PUSH_PIN, kPORT_InterruptOrDMADisabled);

    PORTB->PCR[3] = ((PORTB->PCR[3] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTB9 (pin 57) is configured as PTB9 */
    PORT_SetPinMux(JOYSTICK_JS_LEFT_PORT, JOYSTICK_JS_LEFT_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB9 (pin 57): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(JOYSTICK_JS_LEFT_PORT, JOYSTICK_JS_LEFT_PIN, kPORT_InterruptOrDMADisabled);

    PORTB->PCR[9] = ((PORTB->PCR[9] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
