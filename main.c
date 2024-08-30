#include <msp430.h> 


/**
 * main.c
 */

unsigned char secuencia[]={12,6,3,9}; //matriz de secuencia de alto consumo, 1100=12, 0011=3 ...

unsigned char i;

void delay ()
{
   volatile unsigned long u32Count;

    for (u32Count=0;u32Count<=100;u32Count++);
}



void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P2DIR=0x0F; //salidas de puerto P2.0 hsta P2.3
	while(1)
	{

	    if (P1IN & (0b00001000)) P2OUT=secuencia[i++%4]; 
        //if (P1IN & (1<<3)==0 ....

        else P2OUT=secuencia[i--%4]; //la secuencia al rev�s

        delay();
	}
}
