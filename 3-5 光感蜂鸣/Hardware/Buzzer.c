#include "stm32f10x.h"                  // Device header

void BUZZER_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //使用或运算同时选中1 4 引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_SetBits(GPIOA, GPIO_Pin_12); //置为高电平，默认关闭
}

void BUZZER_OFF()
{
	GPIO_SetBits(GPIOA, GPIO_Pin_12);
}

void BUZZER_ON()
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_12);
}
