
#include "stdio.h"
#include "stdint.h"

#include "fifo.h"



FIFO_status FIFO_init(FIFO_Buf_t * fifo_buf,element_type *buf,unsigned int length){

if(buf == NULL)
	return FIFO_null;



fifo_buf->base = buf;
fifo_buf->head = buf;
fifo_buf->tail = buf;

fifo_buf->count =0;
fifo_buf->length =length;

return FIFO_no_error;

}

FIFO_status FIFO_enqueue(FIFO_Buf_t  * fifo_buf,element_type item){


	if(!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail )
			return FIFO_null;

	if(FIFO_IS_FULL(fifo_buf) == FIFO_full )
		return FIFO_full;

	*(fifo_buf->head) =item;
	fifo_buf->count++;

	// circular condition

	if (fifo_buf->head ==(fifo_buf->base + fifo_buf->length *sizeof(element_type))){

		fifo_buf->head= fifo_buf->base;
	}else
		fifo_buf->head++;

	return FIFO_no_error;


}

FIFO_status FIFO_dequeue(FIFO_Buf_t  * fifo_buf,element_type * item){



	if(!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail )
			return FIFO_null;

	if(fifo_buf->count == 0)
	return FIFO_empty;

	*item = *(fifo_buf->tail);
	fifo_buf-> count--;
	if (fifo_buf->tail ==(fifo_buf->base + fifo_buf->length *sizeof(element_type))){

		fifo_buf->tail= fifo_buf->base;
	}else
		fifo_buf->tail++;

	return FIFO_no_error;

}

FIFO_status FIFO_print(FIFO_Buf_t  * fifo_buf){

	element_type *temp;
	int i;

	if(fifo_buf->count == 0){

		printf("Fifo is empty \n");


	}else{

		temp = fifo_buf->tail;
		printf(" fifo is printing \n");
		for(i= 0; i< fifo_buf->count;i++){

			printf("%x \n",*temp);
		}

	}

	return FIFO_no_error;


}

FIFO_status FIFO_IS_FULL(FIFO_Buf_t  * fifo_buf,element_type * item){
	if(!fifo_buf->head || !fifo_buf->base || !fifo_buf->tail )
				return FIFO_null;

	if(fifo_buf-> count ==fifo_buf->length ){
		return FIFO_full;
	}

	return FIFO_no_error;
}


