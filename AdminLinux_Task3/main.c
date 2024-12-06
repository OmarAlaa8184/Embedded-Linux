#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc,char *argv[])
{


 int variable = open("/sys/class/leds/input3::capslock/brightness",O_RDWR);

 printf("%d \n %c \n %d ",argc, *argv[1],variable);

 if(argv[1]!=NULL)
 {
	 dprintf(variable,"%s\n",argv[1]);
 }
			
}

