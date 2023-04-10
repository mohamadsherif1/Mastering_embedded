/*
 * lifo_buffer.c
 *
 *  Created on: Apr 9, 2023
 *      Author: moham
 */




#include "stdint.h"

#include "lifo_buffer.h"

LIFO_status LIFO_Add_item (LIFO_Buf_t * lifo_buf,unsigned int item){

	if(!lifo_buf->head || !lifo_buf->base )
		return LIFO_null;

	if(lifo_buf->count ==lifo_buf->length ){

		return LIFO_full;
	}

	*(lifo_buf->head)= item;
	lifo_buf->head++;
	lifo_buf->count ++;
	return LIFO_no_error;

}


LIFO_status LIFO_Get_item (LIFO_Buf_t * lifo_buf,unsigned int *item){

	if(!lifo_buf->head || !lifo_buf->base )
			return LIFO_null;

	if(lifo_buf->count == 0)
		return LIFO_empty;

	lifo_buf->head --;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;

}

LIFO_status LIFO_init(LIFO_Buf_t * lifo_buf,unsigned int *buf,unsigned int length){

	if(!buf){
		return LIFO_null;
	}


	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->count =0;
	lifo_buf->length =length;

	return LIFO_no_error;

}
