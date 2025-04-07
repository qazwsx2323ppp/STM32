#include "stm32f10x.h"                  // Device header

int main (void)
{
	//直接操作寄存器
	//RCC->APB2ENR = 0x00000010;
	//GPIOC->CRH = 0x00300000;
	//GPIOC->ODR = 0x00000000;
	
	//使用库函数
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_Pin_13); //高电平 
//	GPIO_ResetBits(GPIOC, GPIO_Pin_13); //低电平
	while (1)
	{
	
	}
}  //最后一行要空出来，不然会报错7
