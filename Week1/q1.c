#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fa, *fb;
	char ca,cb;
	fa = fopen("example_input.c","r");
	if(fa==NULL){
		printf(" Cannot open file \n ");
		exit(0);
	}
	fb = fopen("example_output.c","w");
	ca=getc(fa);
	while(ca != EOF){
		if(ca==' ' || ca=='\t'){
			putc(' ',fb);
		while(ca == ' ' || ca== '\t'){
			ca=getc(fa);
		}
	}
	 putc(ca,fb);
	 ca=getc(fa);
	 }
	 fclose(fa);
	 fclose(fb);
	 return 0;
}
		
