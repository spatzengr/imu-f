#include "includes.h"

uint32_t read_digital_input(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
    return (GPIOx->IDR & GPIO_Pin);
}

void single_gpio_init(GPIO_TypeDef * port, uint16_t pin_src, uint16_t pin, uint8_t af, GPIOMode_TypeDef mode, GPIOOType_TypeDef output, GPIOPuPd_TypeDef pull)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    //map the pin
    if(af)
    {
        GPIO_PinAFConfig(port, pin_src, af);
    }

    //setup the gpio init struct
    GPIO_InitStructure.GPIO_Mode  = mode;
    GPIO_InitStructure.GPIO_OType = output;
    GPIO_InitStructure.GPIO_PuPd  = pull;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin   = pin;

    //init the gpio
    GPIO_Init(port, &GPIO_InitStructure);
}

void board_gpio_init(void)
{
    // SPI pin mappings
    single_gpio_init(BOARD_COMM_MISO_PORT, BOARD_COMM_MISO_PIN_SRC, BOARD_COMM_MISO_PIN, BOARD_COMM_MISO_ALTERNATE, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    single_gpio_init(BOARD_COMM_MOSI_PORT, BOARD_COMM_MOSI_PIN_SRC, BOARD_COMM_MOSI_PIN, BOARD_COMM_MOSI_ALTERNATE, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    single_gpio_init(BOARD_COMM_SCK_PORT,  BOARD_COMM_SCK_PIN_SRC,  BOARD_COMM_SCK_PIN,  BOARD_COMM_SCK_ALTERNATE,  GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    if(BOARD_COMM_CS_MODE == NSS_HARD)
    {
        single_gpio_init(BOARD_COMM_CS_PORT, BOARD_COMM_CS_PIN_SRC, BOARD_COMM_CS_PIN, BOARD_COMM_CS_ALTERNATE, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    }
    else if(BOARD_COMM_CS_MODE == NSS_SOFT)
    {
        single_gpio_init(BOARD_COMM_CS_PORT, BOARD_COMM_CS_PIN_SRC, BOARD_COMM_CS_PIN, BOARD_COMM_CS_ALTERNATE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    }
}