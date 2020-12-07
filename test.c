#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  int fd = open("/dev/rand", O_RDONLY);
  if (fd == -1) {
    printf("Failed to open character device file!\n");
    return -1;
  }
  int value = 0;
  short short_val = 0;
  read(fd, &value, sizeof(value));
  printf("Random 4-byte integer from character device : %d\n", value);
  read(fd, &short_val, sizeof(short_val));
  printf("Random 2-byte integer from character device : %d\n", short_val);
  close(fd);
  return 0;
}
