#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main() {
    int a[2];
    int b[2];

    pipe(a);
    pipe(b);

    int fk = fork();

    while(1) {
        if (fk) {
            char c[500];
            fgets(c, sizeof(c), stdin);
            write(a[WRITE], c, sizeof(c));
            read(b[READ], c, sizeof(c));

            printf("%s", c);
        }
        else {
            char d[500];
            read(a[READ], d, sizeof(d));
            d[strlen(d) - 1] = '\0'; 
            strcat(d, "random characters");
            write(b[WRITE], d, sizeof(d));
        }
    }

}
