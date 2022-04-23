#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int
main(void)
{
   int fileSizes[] = {64, 128, 1024, (4 * 1024), (8 * 1024), (64 * 1024), (128 * 1024)};
   
   for (int i = 0; i < (int)(sizeof(fileSizes)/sizeof(fileSizes[0])); i++) {

       char fileName[PATH_MAX];
       snprintf(fileName, sizeof(fileName), "%d.txt", fileSizes[i]);

       int fd = open(fileName, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
       if (fd == 0) {
	  printf("open(): %s\n", strerror(errno));
	  exit(1);             
       }

       for (int j = 0; j < fileSizes[i]; j += 64) {
           dprintf(fd, "|_=%07d=_ABCDEFGHIJKLMNOPQRSTUVWXYZ_-_0123456789_=%07d=_|\n", j, j+64);
       }

       close(fd);
   }

   return 0;
}
