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
- {pin_num: '45', pin_signal: PTA15/SPI0_SCK/UART0_RX/I2S0_RXD0, label: RED_R_R, identifier: RED_R_R}
- {pin_num: '53', pin_signal: ADC0_SE8/ADC1_SE8/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/FTM1_QD_PHA, label: RIGHT, identifier: RIGHT}
- {pin_num: '54', pin_signal: ADC0_SE9/ADC1_SE9/PTB1/I2C0_SDA/FTM1_CH1/FTM1_QD_PHB, label: DOWN, identifier: RIGHT;DOWN}
- {pin_num: '56', pin_signal: ADC0_SE13/PTB3/I2C0_SDA/UART0_CTS_b/FTM0_FLT0, label: PUSH, identifier: PUSH}
- {pin_num: '57', pin_signal: PTB9/SPI1_PCS1/LPUART0_CTS_b/FB_AD20, label: LEFT, identifier: LEFT}
- {pin_num: '55', pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3, label: UP, identifier: UP}
- {pin_num: '58', pin_signal: ADC1_SE14/PTB10/SPI1_PCS0/LPUART0_RX/FB_AD19/FTM0_FLT1, label: UART_TX, identifier: UART_TX}
- {pin_num: '59', pin_signal: ADC1_SE15/PTB11/SPI1_SCK/LPUART0_TX/FB_AD18/FTM0_FLT2, label: UART_RX, identifier: UART_RX}
- {pin_num: '62', pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN, label: MODE, identifier: MODE}
- {pin_num: '63', pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b, label: CONNECTED, identifier: CONNECTED}
- {pin_num: '47', pin_signal: ADC1_SE17/PTA17/SPI0_SIN/UART0_RTS_b/I2S0_MCLK, label: RED_R_L, identifier: RED_R_L}
- {pin_num: '66', pin_signal: PTB20/FB_AD31/CMP0_OUT, label: RED_R_L_BREAK, identifier: RED_R_L_BREAK}
- {pin_num: '80', pin_signal: ADC1_SE4b/CMP0_IN2/PTC8/FTM3_CH4/I2S0_MCLK/FB_AD7, label: GREEN_F_L, identifier: GREEN_F_L}
- {pin_num: '81', pin_signal: ADC1_SE5b/CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/FTM2_FLT0, label: RED_F_L, identifier: RED_F_L}
- {pin_num: '82', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5, label: BLUE_F_L, identifier: BLUE_F_L}
- {pin_num: '83', pin_signal: ADC1_SE7b/PTC11/LLWU_P11/I2C1_SDA/FTM3_CH7/FB_RW_b, label: GREEN_F_R, identifier: GREEN_F_R}
- {pin_num: '95', pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FB_AD4/LPUART0_RX/I2C0_SCL, label: RED_F_R, identifier: RED_F_R}
- {pin_num: '96', pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FB_AD3/LPUART0_TX/I2C0_SDA, label: BLUE_F_R, identifier: BLUE_F_R}
- {pin_num: '46', pin_signal: PTA16/SPI0_SOUT/UART0_CTS_b/I2S0_RX_FS, label: RED_R_R_BREAK, identifier: RED_R_R_BREAK}
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
    BOARD_LED();
    BOARD_JOYSTICK();
    BOARD_BL();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_LED:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '45', peripheral: GPIOA, signal: 'GPIO, 15', pin_signal: PTA15/SPI0_SCK/UART0_RX/I2S0_RXD0, direction: OUTPUT, gpio_init_state: 'true', slew_rate: fast,
    open_drain: disable}
  - {pin_num: '46', peripheral: GPIOA, signal: 'GPIO, 16', pin_signal: PTA16/SPI0_SOUT/UART0_CTS_b/I2S0_RX_FS, direction: OUTPUT, gpio_init_state: 'true', slew_rate: fast,
    open_drain: disable}
  - {pin_num: '47', peripheral: GPIOA, signal: 'GPIO, 17', pin_signal: ADC1_SE17/PTA17/SPI0_SIN/UART0_RTS_b/I2S0_MCLK, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
  - {pin_num: '66', peripheral: GPIOB, signal: 'GPIO, 20', pin_signal: PTB20/FB_AD31/CMP0_OUT, direction: OUTPUT, gpio_init_state: 'true', slew_rate: fast, open_drain: disable}
  - {pin_num: '80', peripheral: GPIOC, signal: 'GPIO, 8', pin_signal: ADC1_SE4b/CMP0_IN2/PTC8/FTM3_CH4/I2S0_MCLK/FB_AD7, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
  - {pin_num: '81', peripheral: GPIOC, signal: 'GPIO, 9', pin_signal: ADC1_SE5b/CMP0_IN3/PTC9/FTM3_CH5/I2S0_RX_BCLK/FB_AD6/FTM2_FLT0, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
  - {pin_num: '82', peripheral: GPIOC, signal: 'GPIO, 10', pin_signal: ADC1_SE6b/PTC10/I2C1_SCL/FTM3_CH6/I2S0_RX_FS/FB_AD5, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
  - {pin_num: '83', peripheral: GPIOC, signal: 'GPIO, 11', pin_signal: ADC1_SE7b/PTC11/LLWU_P11/I2C1_SDA/FTM3_CH7/FB_RW_b, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
  - {pin_num: '95', peripheral: GPIOD, signal: 'GPIO, 2', pin_signal: PTD2/LLWU_P13/SPI0_SOUT/UART2_RX/FTM3_CH2/FB_AD4/LPUART0_RX/I2C0_SCL, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
  - {pin_num: '96', peripheral: GPIOD, signal: 'GPIO, 3', pin_signal: PTD3/SPI0_SIN/UART2_TX/FTM3_CH3/FB_AD3/LPUART0_TX/I2C0_SDA, direction: OUTPUT, gpio_init_state: 'true',
    slew_rate: fast, open_drain: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_LED
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_LED(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);

    gpio_pin_config_t RED_R_R_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTA15 (pin 45)  */
    GPIO_PinInit(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN, &RED_R_R_config);

    gpio_pin_config_t RED_R_R_BREAK_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTA16 (pin 46)  */
    GPIO_PinInit(BOARD_LED_RED_R_R_BREAK_GPIO, BOARD_LED_RED_R_R_BREAK_PIN, &RED_R_R_BREAK_config);

    gpio_pin_config_t RED_R_L_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTA17 (pin 47)  */
    GPIO_PinInit(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN, &RED_R_L_config);

    gpio_pin_config_t RED_R_L_BREAK_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB20 (pin 66)  */
    GPIO_PinInit(BOARD_LED_RED_R_L_BREAK_GPIO, BOARD_LED_RED_R_L_BREAK_PIN, &RED_R_L_BREAK_config);

    gpio_pin_config_t GREEN_F_L_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTC8 (pin 80)  */
    GPIO_PinInit(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN, &GREEN_F_L_config);

    gpio_pin_config_t RED_F_L_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTC9 (pin 81)  */
    GPIO_PinInit(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN, &RED_F_L_config);

    gpio_pin_config_t BLUE_F_L_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTC10 (pin 82)  */
    GPIO_PinInit(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN, &BLUE_F_L_config);

    gpio_pin_config_t GREEN_F_R_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTC11 (pin 83)  */
    GPIO_PinInit(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN, &GREEN_F_R_config);

    gpio_pin_config_t RED_F_R_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD2 (pin 95)  */
    GPIO_PinInit(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN, &RED_F_R_config);

    gpio_pin_config_t BLUE_F_R_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD3 (pin 96)  */
    GPIO_PinInit(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN, &BLUE_F_R_config);

    /* PORTA15 (pin 45) is configured as PTA15 */
    PORT_SetPinMux(BOARD_LED_RED_R_R_PORT, BOARD_LED_RED_R_R_PIN, kPORT_MuxAsGpio);

    PORTA->PCR[15] = ((PORTA->PCR[15] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_FastSlewRate)

                      /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                      | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTA16 (pin 46) is configured as PTA16 */
    PORT_SetPinMux(BOARD_LED_RED_R_R_BREAK_PORT, BOARD_LED_RED_R_R_BREAK_PIN, kPORT_MuxAsGpio);

    PORTA->PCR[16] = ((PORTA->PCR[16] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_FastSlewRate)

                      /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                      | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTA17 (pin 47) is configured as PTA17 */
    PORT_SetPinMux(BOARD_LED_RED_R_L_PORT, BOARD_LED_RED_R_L_PIN, kPORT_MuxAsGpio);

    PORTA->PCR[17] = ((PORTA->PCR[17] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_FastSlewRate)

                      /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                      | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTB20 (pin 66) is configured as PTB20 */
    PORT_SetPinMux(BOARD_LED_RED_R_L_BREAK_PORT, BOARD_LED_RED_R_L_BREAK_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[20] = ((PORTB->PCR[20] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_FastSlewRate)

                      /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                      | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTC10 (pin 82) is configured as PTC10 */
    PORT_SetPinMux(BOARD_LED_BLUE_F_L_PORT, BOARD_LED_BLUE_F_L_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[10] = ((PORTC->PCR[10] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_FastSlewRate)

                      /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                      | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTC11 (pin 83) is configured as PTC11 */
    PORT_SetPinMux(BOARD_LED_GREEN_F_R_PORT, BOARD_LED_GREEN_F_R_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[11] = ((PORTC->PCR[11] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                      /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                       * configured as a digital output. */
                      | PORT_PCR_SRE(kPORT_FastSlewRate)

                      /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                      | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTC8 (pin 80) is configured as PTC8 */
    PORT_SetPinMux(BOARD_LED_GREEN_F_L_PORT, BOARD_LED_GREEN_F_L_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[8] = ((PORTC->PCR[8] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                     /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_FastSlewRate)

                     /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                     | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTC9 (pin 81) is configured as PTC9 */
    PORT_SetPinMux(BOARD_LED_RED_F_L_PORT, BOARD_LED_RED_F_L_PIN, kPORT_MuxAsGpio);

    PORTC->PCR[9] = ((PORTC->PCR[9] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                     /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_FastSlewRate)

                     /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                     | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTD2 (pin 95) is configured as PTD2 */
    PORT_SetPinMux(BOARD_LED_RED_F_R_PORT, BOARD_LED_RED_F_R_PIN, kPORT_MuxAsGpio);

    PORTD->PCR[2] = ((PORTD->PCR[2] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                     /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_FastSlewRate)

                     /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                     | PORT_PCR_ODE(kPORT_OpenDrainDisable));

    /* PORTD3 (pin 96) is configured as PTD3 */
    PORT_SetPinMux(BOARD_LED_BLUE_F_R_PORT, BOARD_LED_BLUE_F_R_PIN, kPORT_MuxAsGpio);

    PORTD->PCR[3] = ((PORTD->PCR[3] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_SRE_MASK | PORT_PCR_ODE_MASK | PORT_PCR_ISF_MASK)))

                     /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_FastSlewRate)

                     /* Open Drain Enable: Open drain output is disabled on the corresponding pin. */
                     | PORT_PCR_ODE(kPORT_OpenDrainDisable));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_JOYSTICK:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '53', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: ADC0_SE8/ADC1_SE8/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/FTM1_QD_PHA, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_select: up, pull_enable: enable}
  - {pin_num: '54', peripheral: GPIOB, signal: 'GPIO, 1', pin_signal: ADC0_SE9/ADC1_SE9/PTB1/I2C0_SDA/FTM1_CH1/FTM1_QD_PHB, identifier: DOWN, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_select: up, pull_enable: enable}
  - {pin_num: '55', peripheral: GPIOB, signal: 'GPIO, 2', pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_select: up, pull_enable: enable}
  - {pin_num: '56', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: ADC0_SE13/PTB3/I2C0_SDA/UART0_CTS_b/FTM0_FLT0, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_select: up, pull_enable: enable}
  - {pin_num: '57', peripheral: GPIOB, signal: 'GPIO, 9', pin_signal: PTB9/SPI1_PCS1/LPUART0_CTS_b/FB_AD20, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_JOYSTICK
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_JOYSTICK(void)
{
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);

    gpio_pin_config_t RIGHT_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB0 (pin 53)  */
    GPIO_PinInit(BOARD_JOYSTICK_RIGHT_GPIO, BOARD_JOYSTICK_RIGHT_PIN, &RIGHT_config);

    gpio_pin_config_t DOWN_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB1 (pin 54)  */
    GPIO_PinInit(BOARD_JOYSTICK_DOWN_GPIO, BOARD_JOYSTICK_DOWN_PIN, &DOWN_config);

    gpio_pin_config_t UP_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB2 (pin 55)  */
    GPIO_PinInit(BOARD_JOYSTICK_UP_GPIO, BOARD_JOYSTICK_UP_PIN, &UP_config);

    gpio_pin_config_t PUSH_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB3 (pin 56)  */
    GPIO_PinInit(BOARD_JOYSTICK_PUSH_GPIO, BOARD_JOYSTICK_PUSH_PIN, &PUSH_config);

    gpio_pin_config_t LEFT_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB9 (pin 57)  */
    GPIO_PinInit(BOARD_JOYSTICK_LEFT_GPIO, BOARD_JOYSTICK_LEFT_PIN, &LEFT_config);

    /* PORTB0 (pin 53) is configured as PTB0 */
    PORT_SetPinMux(BOARD_JOYSTICK_RIGHT_PORT, BOARD_JOYSTICK_RIGHT_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB0 (pin 53): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_JOYSTICK_RIGHT_PORT, BOARD_JOYSTICK_RIGHT_PIN, kPORT_InterruptFallingEdge);

    PORTB->PCR[0] = ((PORTB->PCR[0] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp));

    /* PORTB1 (pin 54) is configured as PTB1 */
    PORT_SetPinMux(BOARD_JOYSTICK_DOWN_PORT, BOARD_JOYSTICK_DOWN_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB1 (pin 54): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_JOYSTICK_DOWN_PORT, BOARD_JOYSTICK_DOWN_PIN, kPORT_InterruptFallingEdge);

    PORTB->PCR[1] = ((PORTB->PCR[1] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp));

    /* PORTB2 (pin 55) is configured as PTB2 */
    PORT_SetPinMux(BOARD_JOYSTICK_UP_PORT, BOARD_JOYSTICK_UP_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB2 (pin 55): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_JOYSTICK_UP_PORT, BOARD_JOYSTICK_UP_PIN, kPORT_InterruptFallingEdge);

    PORTB->PCR[2] = ((PORTB->PCR[2] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp));

    /* PORTB3 (pin 56) is configured as PTB3 */
    PORT_SetPinMux(BOARD_JOYSTICK_PUSH_PORT, BOARD_JOYSTICK_PUSH_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB3 (pin 56): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_JOYSTICK_PUSH_PORT, BOARD_JOYSTICK_PUSH_PIN, kPORT_InterruptFallingEdge);

    PORTB->PCR[3] = ((PORTB->PCR[3] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp));

    /* PORTB9 (pin 57) is configured as PTB9 */
    PORT_SetPinMux(BOARD_JOYSTICK_LEFT_PORT, BOARD_JOYSTICK_LEFT_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTB9 (pin 57): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_JOYSTICK_LEFT_PORT, BOARD_JOYSTICK_LEFT_PIN, kPORT_InterruptFallingEdge);

    PORTB->PCR[9] = ((PORTB->PCR[9] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_BL:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '58', peripheral: GPIOB, signal: 'GPIO, 10', pin_signal: ADC1_SE14/PTB10/SPI1_PCS0/LPUART0_RX/FB_AD19/FTM0_FLT1}
  - {pin_num: '59', peripheral: GPIOB, signal: 'GPIO, 11', pin_signal: ADC1_SE15/PTB11/SPI1_SCK/LPUART0_TX/FB_AD18/FTM0_FLT2}
  - {pin_num: '62', peripheral: GPIOB, signal: 'GPIO, 16', pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN}
  - {pin_num: '63', peripheral: GPIOB, signal: 'GPIO, 17', pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_BL
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_BL(void)
{
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);

    /* PORTB10 (pin 58) is configured as PTB10 */
    PORT_SetPinMux(BOARD_BL_UART_TX_PORT, BOARD_BL_UART_TX_PIN, kPORT_MuxAsGpio);

    /* PORTB11 (pin 59) is configured as PTB11 */
    PORT_SetPinMux(BOARD_BL_UART_RX_PORT, BOARD_BL_UART_RX_PIN, kPORT_MuxAsGpio);

    /* PORTB16 (pin 62) is configured as PTB16 */
    PORT_SetPinMux(BOARD_BL_MODE_PORT, BOARD_BL_MODE_PIN, kPORT_MuxAsGpio);

    /* PORTB17 (pin 63) is configured as PTB17 */
    PORT_SetPinMux(BOARD_BL_CONNECTED_PORT, BOARD_BL_CONNECTED_PIN, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
