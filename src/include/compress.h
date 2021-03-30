#ifndef __COMPRESS_H__
#define __COMPRESS_H__ 1
#include <stdint.h>
#include <stdio.h>



typedef struct __DATA_BUFFER{
	uint64_t l;
	uint8_t* dt;
} data_buffer_t;



data_buffer_t* create_data_buffer(FILE* f);



data_buffer_t* compress_data(data_buffer_t* dt);



data_buffer_t* decompress_data(data_buffer_t* dt);



void free_data_buffer(data_buffer_t* dt);



#endif
