#include <compress.h>
#include <stdint.h>
#include <stdio.h>



int main(int argc,const char** argv){
	FILE* f=NULL;
	fopen_s(&f,"rsrc/test.txt","rb");
	data_buffer_t* dt=create_data_buffer(f);
	fclose(f);
	data_buffer_t* c_dt=compress_data(dt);
	printf("%llu -> %llu (%+.2f%%)\n",dt->l,c_dt->l,((float)c_dt->l-dt->l)/dt->l*100);
	data_buffer_t* d_dt=decompress_data(c_dt);
	printf("%llu -> %llu (%+.2f%%)\n",c_dt->l,d_dt->l,((float)d_dt->l-c_dt->l)/c_dt->l*100);
	if (dt->l!=d_dt->l){
		printf("Length Mismatch!\n");
	}
	else{
		for (uint64_t i=0;i<dt->l;i++){
			if (*(dt->dt+i)!=*(d_dt->dt+i)){
				printf("Character Mismatch: +%llu\n",i);
				break;
			}
		}
	}
	free_data_buffer(dt);
	free_data_buffer(c_dt);
	free_data_buffer(d_dt);
	return 0;
}
