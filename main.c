# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "random.h"

int main() {
    int SIZE_OF_ARR = 10;
    int initial_arr[SIZE_OF_ARR], final_arr[SIZE_OF_ARR];
    int fd, b, i;
    printf("Generating random numbers:\n");
    for (i = 0; i < SIZE_OF_ARR; i++) {
        initial_arr[i] = random_generator();
        printf("\t random %d: %d\n", i, initial_arr[i]);
    }

    printf("Writing numbers to file...\n" );
    fd = open("random", O_CREAT|O_EXCL|O_WRONLY, 0755);
    if( fd < 0 ) {
       printf("errno: %d error: %s\n", errno, strerror(errno));
       return 0;
    }
    b = write(fd, initial_arr, SIZE_OF_ARR * sizeof(int));
    if (b == -1) {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }

    printf("Reading numbers from file...\n" );
    close(fd);
    fd = open("rand", O_RDONLY);
    b = read(fd, final_arr, SIZE_OF_ARR * sizeof(int));
    b = close(fd);
    if (b == -1) {
      printf("Error %d: %s\n", errno, strerror(errno));
      return 0;
    }
    printf("Verification that written values were the same:\n");
    for (i = 0; i < SIZE_OF_ARR; i++) {
        printf("\t el %d: %d\n", i, final_arr[i]);
    }


}
