#include "main.h"

static void delay(int loop)
{
    unsigned int i, j;

    for (i = 0; i < loop; i++) {
        for (j = 0; j < 10000; j++){
        }
    }
}

int main(void)
{
	u8 key;
    u8 led = LED1;
	Key_Init();
	LED_Init();
	while(1)
	{
	    LEDTog(led);
        led++;
        if (led > LED4) {
            led = LED1;
        }

        delay_ms(500);
        
        #if 0
        key=KEY_Scan();
		if(key==1)LEDTog(LED1);
		else if(key==2)LEDTog(LED2);
		else if(key==3)LEDTog(LED1);
		else if(key==4)LEDTog(LED2);
        #endif
	}
}


