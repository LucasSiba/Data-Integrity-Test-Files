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
   int fd;

   int fileSizes[] = {64, 128, 1024, (4 * 1024), (64 * 1024)};
   
   for (int i = 0; i < (int)(sizeof(fileSizes)/sizeof(fileSizes[0])); i++) {

       char fileName[PATH_MAX];
       snprintf(fileName, sizeof(fileName), "%d-%d.txt", fileSizes[i], i);

       fd = open(fileName, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
       if (fd == 0) {
	  printf("open(): %s\n", strerror(errno));
	  exit(1);             
       }

       dprintf(fd, "foo");

       close(fd);
   }

   return 0;
}
