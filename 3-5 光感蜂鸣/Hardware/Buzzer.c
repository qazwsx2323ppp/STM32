#include "stm32f10x.h"                  // Device header
#include "Buzzer.h"

void BUZZER_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //使用或运算同时选中1 4 引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5); //置为高电平，默认关闭
}

void BUZZER_OFF()
{
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
}

void BUZZER_ON()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
}

void BUZZER_turn()
{
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
	}
	else GPIO_ResetBits(GPIOB, GPIO_Pin_5);
}
