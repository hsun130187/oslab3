#include<stdio.h>
#include<pthread.h>
#include<sys/time.h>
void * myfunc(void * arg){
	int i,j;
	for(i=0;i<30000;i++){
		for(j=0;j<100000;j++){

		}
	}
    return NULL;
}
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
	for(i=0;i<100;i++){
		char message[]="this is a test!\n";
	    fputs(message,fpWrite);
	}
	fclose(fpWrite);


}
int main(){
	pthread_t pthid;
	double seconds=-0.1;
	int count;
        //seconds = -wall_time();
	pthread_create(&pthid, NULL, myfunc, NULL);
	 seconds = -wall_time();
	for(count=0;count<10000;count++){
		writef();
	    readf();	
	}
        void * ptr=NULL;
	pthread_join(pthid,&ptr);
	seconds+=wall_time();
	printf("threads total time used is %lf\n", seconds);
 	return 0;

}

