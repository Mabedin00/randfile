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
}
