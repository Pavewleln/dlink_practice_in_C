#include "include/ipdata.h"

IpAddress network1;
IpAddress network2;
IpAddress network3;
IpAddress network4;

void initialize_ip_data() {
    strcpy(network1.ip_addr, "192.168.10.0");
    network1.mask = 24;

    strcpy(network2.ip_addr, "192.168.160.0");
    network2.mask = 19;

    strcpy(network3.ip_addr, "141.127.0.0");
    network3.mask = 16;

    strcpy(network4.ip_addr, "195.0.172.0");
    network4.mask = 22;
}