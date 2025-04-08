//用于封装LED驱动
#include "stm32f10x.h"                  // Device header

//定义LED初始化函数
void LED_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_4; //使用或运算同时选中1 4 引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_4); //置为高电平，默认关闭
}

void LED1_OFF()
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED1_ON()
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED1_turn()
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED4_OFF()
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void LED4_ON()
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void LED4_turn()
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
	}
	else GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}
