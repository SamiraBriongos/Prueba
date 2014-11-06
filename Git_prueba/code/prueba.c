#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/aes.h>

unsigned int timestamp(void) {
	unsigned int bottom;
	unsigned int top;
	asm volatile(".byte 15;.byte 49" : "=a"(bottom),"=d"(top));
	return bottom;
	}

		unsigned char key[16];
		AES_KEY expanded;
		unsigned char zero[16];
		unsigned char scrambledzero[16];
	
	void handle(char out[40],char in[],int len) {
	unsigned char workarea[len * 3];
	int i;

     for (i = 0;i < 40;++i) out[i] = 0;
       	*(unsigned int *) (out + 32) = timestamp();

	if (len < 16) return;

     for (i = 0;i < 16;++i) out[i] = in[i];
   
     for (i = 16;i < len;++i) workarea[i] = in[i];
     
	AES_encrypt(in,workarea,&expanded);
	
/*a real server would now check AES-based authenticator,*/
/* process legitimate packets, and generate usefuloutput*/

     for(i=0;i < 16;++i) out[16+i] = scrambledzero[i]; 
	*(unsigned int *)(out+36)= timestamp();
}
	
	int main(){
		int i;
		int val;
		
		for (i = 0;i < 10;++i){
			val = timestamp();
			printf("%d",val);
			printf(".\n");
			printf("%u",val);
			printf(".\n");
			printf("%f",val);
			printf(".\n");
			printf("%e",val);
			printf(".\n");
			printf(".\n");
		}
		
		int s;
		char* in;
		int r;
		char out[40];
		
		if (read(0,key,sizeof key) < sizeof key) return 111;

   AES_set_encrypt_key(key,128,&expanded);
   AES_encrypt(zero,scrambledzero,&expanded);
	
	in = "abcdefghijklmnop";
	r=128;
	
	handle(out,in,r);		
		return 5;
	}
