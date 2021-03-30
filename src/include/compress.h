#ifndef __COMPRESS_H__
#define __COMPRESS_H__ 1
#include <stdint.h>
#include <stdio.h>



typedef struct __DATA_BUFFER{
	uint64_t l;
	uint8_t* dt;
} data_buffer_t;



typedef void (*compressor_data_cb_func)(uint8_t c);



data_buffer_t* create_data_buffer(FILE* f);



data_buffer_t* compress_data(data_buffer_t* dt);



void compress_data_cb(data_buffer_t* dt,compressor_data_cb_func cb);



data_buffer_t* decompress_data(data_buffer_t* dt);



void decompress_data_cb(data_buffer_t* dt,compressor_data_cb_func cb);



void free_data_buffer(data_buffer_t* dt);



#endif
