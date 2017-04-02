/*
 * Ccode rev 1.0
 *
 *	(C) 2017-2020 HuyLe <anhhuy@live.com>
 *
 *      15-March-2017 <anhhuy@live.com>
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "version.h"
#include "hello.h"
#define DEFAULT_MEM_DEV "/dev/mem"
static struct opt{
	const char *point;
	unsigned int flags;
}st;
int main(int argc, char * const argv[])
{
	int fd=open("AUTHORS", O_RDONLY);

	if(sizeof(u8)!=1 || sizeof(u16)!=2 || sizeof(u32)!=4 || '\0'!=0)
	{
		fprintf(stderr,"%s: Compiler incompatibility.\n", argv[0]);
		exit(255);
	}
	printf("###########################\n");
	printf("MAIN CCODE VERSION: %s\n", VERSION);

	if(fd==-1)
	{
		perror("ERROR");
		exit(1);
	}

	if(close(fd)==-1)
	{
		perror("CLOSE");
		exit(1);
	}
	
	/* Set default value */
	st.point=DEFAULT_MEM_DEV;
	st.flags=0;

	/* Checking the goto function */
	if (st.flags == 0){
		printf(">>>%s\n",st.point);
		goto exit_now;
	}else{
		printf(">>>%d\n",st.flags);
	}
exit_now:	hello();	

	printf("###########################\n");
	return 0;
}
