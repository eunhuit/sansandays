/*
 * GccApplication1.c
 *
 * Created: 2024-05-28 오전 9:03:56
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0x0F;
	unsigned char FND[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	while (1)
	{
		PORTB=0xFF;
		for (int i = 0; i < 10; i++)
		{
			PORTB=0xFF;
			if((PINB & 0x10)!=0){
				PORTB=0xFE;
			}
					
			else if((PINB & 0x20)!=0){
				PORTB=0xFD;
			}
					
			else if((PINB & 0x40)!=0){
				PORTB=0xFB;
			}
					
			else if((PINB & 0x80)!=0){
				PORTB=0xF7;
			}
			
			PORTA = FND[i];
			_delay_ms(1000);
		}
	}
}
