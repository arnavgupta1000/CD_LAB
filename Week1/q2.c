#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fa,*fb;
	char ca,cb,buf[256];
	fa = fopen("example_input.c","r");
	if(fa==NULL){
		
		printf("cannot open file \n");
		exit(0);
	}
	fb = fopen("example_output.c","w");
	ca=fgetc(fa);
	while(ca!=EOF){
	
		if(ca=='#'){
		
			fgets(buf,strlen("include")+1,fa);
			if(strcmp(buf,"include")==0){
				while(ca!='\n'){
					ca=getc(fa);
				}
			}
			else{
				fseek(fa,-strlen(buf),SEEK_CUR);
			}
			fgets(buf,strlen("define")+1,fa);
			if(strcmp(buf,"define")==0){
				while(ca!='\n'){
					ca=getc(fa);
				}
			}
			else{
				
				fseek(fa,-strlen(buf),SEEK_CUR);
				
			}
			putc(ca,fb);
		}
		else{
		
			putc(ca,fb);
		}
		ca=getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}
