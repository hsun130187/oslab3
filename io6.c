#include <stdio.h>
#include <sys/time.h>	// For struct timeval, gettimeofday
double wall_time()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return 1. * t.tv_sec + 1.e-6 * t.tv_usec;
}
void readf(){
	FILE *fread=fopen("test.txt","r");
	char ch=fgetc(fread);
	fclose(fread);
}
void writef(){
	FILE *fpWrite=fopen("test.txt","w");
	int i=0;
	for(i=0;i<500;i++){
		char message[]="this is a test!\n";
	    fputs(message,fpWrite);
	}
	fclose(fpWrite);
	
	
}
int main(){
	int i;
	double seconds=-0.1;
	seconds = -wall_time();
	for(i=0;i<500000;i++){
		writef();
	    readf();	
	}
	//seconds += wall_time();
	//printf("total time used FOR IO is %lf ", seconds);
	//seconds = -wall_time();
	for(int i=0;i<3000;i++){
		for(int j=0;j<10000000;j++){
			
		}
	}
	seconds += wall_time();
	printf("total time used FOR CPU INTENSIVE  is %lf ", seconds);
	return 0; 
} 

