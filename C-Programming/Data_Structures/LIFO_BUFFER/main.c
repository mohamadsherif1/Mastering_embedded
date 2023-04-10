/*
 * main.c
 *
 *  Created on: Apr 9, 2023
 *      Author: mohamad
 */


#include "lifo_buffer.h"

#include "stdio.h"
unsigned int buffer[5];
int main(){

	int i  = 0;

	LIFO_Buf_t UART_lifo;

	LIFO_init(&UART_lifo,buffer,5);

for(i = 0; i< 5; i++){

	if(LIFO_Add_item(&UART_lifo,i)== LIFO_no_error){
	printf("tmam %d ", i)	;
	}
	}

}
