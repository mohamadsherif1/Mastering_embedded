/*
 * Fifo_buffer.h
 *
 *  Created on: Apr 9, 2023
 *      Author: mohamad
 */




#ifndef FIFO_BUFFER_H_
#define FIFO_BUFFER_H_



// user configurations

//element type
#define element_type uint8_t

// select buffer width
#define width  5



element_type buffer[width];


typedef struct {

	unsigned int count;
	unsigned int length;
	element_type * head;
	element_type * tail;
	element_type * base;

}FIFO_Buf_t;



typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null

}FIFO_status;


FIFO_status FIFO_enqueue(FIFO_Buf_t  * fifo_buf,element_type item);

FIFO_status FIFO_dequeue(FIFO_Buf_t  * fifo_buf,element_type * item);

FIFO_status FIFO_print(FIFO_Buf_t  * fifo_buf);

FIFO_status FIFO_IS_FULL(FIFO_Buf_t  * fifo_buf,element_type * item);






FIFO_status FIFO_init(FIFO_Buf_t * fifo_buf,element_type *buf,unsigned int length);
#endif
