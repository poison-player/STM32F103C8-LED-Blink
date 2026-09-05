#include "stm32f1xx_hal.h"
#define LED_PORT GPIOB
#define LED_PIN GPIO_PIN_0
void pb0_led_init(void);
int main (void)
{
HAL_Init();
pb0_led_init();
while(1)
{HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
HAL_Delay(1000);
HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
HAL_Delay(1000);
}
}
void pb0_led_init(void)
{GPIO_InitTypeDef GPIO_InitStruct ={0};
__HAL_RCC_GPIOB_CLK_ENABLE();
GPIO_InitStruct.Pin =LED_PIN;
GPIO_InitStruct.Mode =GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull =GPIO_NOPULL;
GPIO_InitStruct.Speed =GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init (LED_PORT, &GPIO_InitStruct);
}


