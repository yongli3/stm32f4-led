#include "led.h"

void LED_Init(void)
{
  	GPIO_InitTypeDef  GPIO_InitStructure;

#if 1
	  // PA9 & PA10 uart1 TX/RX
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);
#endif
    // pc14 pc15
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOC, &GPIO_InitStructure);

    LEDOn(LED1);
    LEDOn(LED2);
    LEDOn(LED3);
    LEDOn(LED4);

    LEDOff(LED1);
    LEDOff(LED2);
    LEDOff(LED3);
    LEDOff(LED4);    
}

void LEDOn(Led_Def Led)//LEDÁÁ
{
  	LED_PORT[Led]->BSRRL=LED_PIN[Led];
}

void LEDOff(Led_Def Led)//LEDÃð
{
  	LED_PORT[Led]->BSRRH=LED_PIN[Led];  
}

void LEDTog(Led_Def Led)//LED×´Ì¬·­×ª
{
  	LED_PORT[Led]->ODR^=LED_PIN[Led];
}



