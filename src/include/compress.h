#ifndef __COMPRESS_H__
#define __COMPRESS_H__ 1
#include <stdint.h>
#include <stdio.h>



#define COMPRESSOR_END_OF_DATA 256



typedef struct __DATA_BUFFER{
	uint64_t l;
	uint8_t* dt;
} data_buffer_t;



typedef uint16_t (*compressor_data_read_func)(void* ctx);
typedef void (*compressor_data_reset_read_func)(void* ctx);
typedef void (*compressor_data_write_func)(void* ctx,uint8_t c);



data_buffer_t* create_data_buffer(FILE* f);



void compress_data(void* rf_ctx,compressor_data_read_func rf,compressor_data_reset_read_func rrf,void* wf_ctx,compressor_data_write_func wf);



data_buffer_t* compress_data_bf(data_buffer_t* dt);



void decompress_data(void* rf_ctx,compressor_data_read_func rf,void* wf_ctx,compressor_data_write_func wf);



data_buffer_t* decompress_data_bf(data_buffer_t* dt);



void free_data_buffer(data_buffer_t* dt);



#endif
