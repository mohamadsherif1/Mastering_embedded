
#include "uart.h"

# define UART0DR *((volatile unsigned int * const )((unsigned int *)0x101f1000))

void Uart_send_str(unsigned char * P_String){
	
	while(*P_String != '\0'){
		
		UART0DR =(unsigned int )(* P_String);
		P_String++;
	}
	
}