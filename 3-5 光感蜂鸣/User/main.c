#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"


uint8_t KeyNum;

int main(void)
{
	LED_Init();
	Key_init();
	BUZZER_Init();
	LightSensor_Init();
	   
    while (1)
   {
	   if (LightSensor_Get() == 1) //即光线较暗时 
	   {
		   LED1_ON();
		   LED4_OFF();
	   }
	   else
	   {
		   LED4_ON();
		   LED1_OFF();
	   }
   }
}
