#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void func1(char *src) {
    char *dst = malloc((strnlen_s(src) + 1) * sizeof(char));
    strlcpy(dst, src, strnlen_s(src) + sizeof(char));
    dst[strnlen_s(dst)] = 0;
}

void func2(int fd) {
    char *buf;
    size_t len;
    //flawfinder: ignore
    read(fd, &len, sizeof(len));
    if (len > 1024)
        return;

    buf = malloc(len + 1);
    //flawfinder: ignore
    read(fd, buf, len);
    buf[len] = '\0';
}

void func3() {
    char *buffer = malloc(1024);
    printf("Please enter your user id :");
    fgets(buffer, 1024, stdin);
    if (!isalpha(buffer[0])) {
        char *errormsg = malloc(1044);
        strlcpy(errormsg, buffer, 1024);
        strcat_s(errormsg, " is not  a valid ID");
    }
}

void func4(char *foo) {
    char *buffer = (char *) malloc(10 * sizeof(char));
    strlcpy(buffer, foo);
}


main() {
    int y = 10;
    int a[10];

    func4("fooooooooooooooooooooooooooooooooooooooooooooooooooo");

    {
        try
        {
            func3();
        }
    }
    catch(
    char *message){
        //flawfinder: ignore
        fprintf(stderr, message);
    };
    fprintf(aFile, "%s", "hello world")
    while (y >= 0) {
        a[y] = y;
        y = y - 1;

    }
    return 0;

}