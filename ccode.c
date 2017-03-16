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

int main(int argc, char * const argv[])
{
	//u8 buf[48];
	int fd=open("AUTHORS", O_RDONLY);
	//long fp=0xE0000L;
	//u8 smmajver=0, smminver=0;

	if(sizeof(u8)!=1 || sizeof(u16)!=2 || sizeof(u32)!=4 || '\0'!=0)
	{
		fprintf(stderr,"%s: compiler incompatibility.\n", argv[0]);
		exit(255);
	}
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
	
	hello();	

	return 0;
}
