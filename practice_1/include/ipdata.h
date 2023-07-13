#include <string.h>

#ifndef IPDATA_H
#define IPDATA_H

typedef struct MyIpAddress{
    char ip_addr[16];
    int mask;
} IpAddress;

extern IpAddress network1;
extern IpAddress network2;
extern IpAddress network3;
extern IpAddress network4;

#endif