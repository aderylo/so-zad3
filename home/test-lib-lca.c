//
// Created by adam on 12.05.22.
//
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
int main()
{
    pid_t arg1 = 220, arg_2= 229;
    pid_t x = getlcapid(arg1,arg_2);
    if(x == -1){
        printf("Errno %d\n", errno);
    }
    printf("PID : %d\n", x);
    return 0;
}