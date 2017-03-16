/*
 *	Hello.c file
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
#include "version.h"

void hello(void)
{
	printf("Welcome to version: %s\n",VERSION);
}
