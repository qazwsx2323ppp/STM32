#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"


uint8_t KeyNum;

int main(void)
{
	LED_Init();
	Key_init();
	BUZZER_Init();
	   
    while (1)
   {
	   
	   KeyNum = Key_GetNum();
       if (KeyNum == 1)
       {
           LED1_turn();
       }
       if (KeyNum == 2)
       {
           LED4_turn();
       }
	   
	  BUZZER_ON();
	  Delay_ms(500);
	  BUZZER_OFF();
	  Delay_ms(500);
	  BUZZER_turn();
	  Delay_ms(500);
	  BUZZER_turn();
	  Delay_ms(500);
	  
   }
}
