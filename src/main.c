#include <compress.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>



int main(int argc,const char** argv){
	FILE* f;
#ifdef _MSC_VER
	if (fopen_s(&f,argv[1],"rb")){// lgtm [cpp/path-injection]
#else
	if (!(f=fopen(argv[1],"rb"))){// lgtm [cpp/path-injection]
#endif
		printf("Unable to Open File!\n");
	}
	data_buffer_t* dt=create_data_buffer(f);
	fclose(f);
	data_buffer_t* c_dt=compress_data_bf(dt);
	printf("%"PRIu64" -> %"PRIu64" (%+.2f%%)\n",dt->l,c_dt->l,((float)c_dt->l-dt->l)/dt->l*100);
	data_buffer_t* d_dt=decompress_data_bf(c_dt);
	printf("%"PRIu64" -> %"PRIu64" (%+.2f%%)\n",c_dt->l,d_dt->l,((float)d_dt->l-c_dt->l)/c_dt->l*100);
	if (dt->l!=d_dt->l){
		printf("Length Mismatch!\n");
	}
	else{
		for (uint64_t i=0;i<dt->l;i++){
			if (*(dt->dt+i)!=*(d_dt->dt+i)){
				printf("Character Mismatch: +%"PRIu64"\n",i);
				break;
			}
		}
	}
	free_data_buffer(dt);
	free_data_buffer(c_dt);
	free_data_buffer(d_dt);
	return 0;
}
