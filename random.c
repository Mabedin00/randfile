# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

int random_generator() {
    int buff[1];
    int b;
    int fd = open("/dev/random", O_RDONLY);
    if (fd < 0) {
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 0;
    }
    if (read(fd, buff, sizeof(int)) == -1){
        printf("errno: %d error: %s\n", errno, strerror(errno));
        return 0;
    }
    return * buff;
}
