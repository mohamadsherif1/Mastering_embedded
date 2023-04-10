#include "uart.h"


unsigned char string_buff[100] = "hello world";

void main (void_){
Uart_send_str(string_buff);	
}