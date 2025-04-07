#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	//1.使用RCC开启GPIO时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//2.使用GPIO_init函数初始化GPIO
	GPIO_InitTypeDef GPIO_InitStructure; //定义局部结构体变量
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //工作模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All; //将所有引脚都定义成推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure); //第一个参数值是选择外设，第二个参数是一个结构体地址
    //函数执行完成后，GPIOA的外设的0号引脚被配置为推挽输出，50MHz的速度	
	
	
	//3.使用输入或输出的函数控制GPIO口
	
	
	//使用GPIO写入函数
	//GPIO_ResetBits(GPIOA, GPIO_Pin_0);//给0端口配置了低电平 ，亮了(ovo)
	GPIO_SetBits(GPIOA, GPIO_Pin_0);  //给0端口配置了高电平 ，灭了(O^O)
	//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET); //第三个参数清除了端口，就是配置了低电平
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET); //第三个参数重置了端口，就是配置了高电平
	//Bit_SET == (BitAction)1 , Bit_RESET == (BitAction)0
	  
    while (1)
   {
	   GPIO_Write(GPIOA, ~0x0001);	//0000 0000 0000 0001 取非是因为低电平=、
	   
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0002);	//0000 0000 0000 0010
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0004);	//0000 0000 0000 0100
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0008);	//0000 0000 0000 1000
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0010);	//0000 0000 0001 0000
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0020);	//0000 0000 0010 0000
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0040);	//0000 0000 0100 0000
       Delay_ms(100);
       GPIO_Write(GPIOA, ~0x0080);	//0000 0000 1000 0000
       Delay_ms(100);
   }
}
