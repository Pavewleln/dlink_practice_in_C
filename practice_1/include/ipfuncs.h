#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include "ipdata.h"

#ifndef IPFUNCS_H
#define IPFUNCS_H

void get_network_address(char* ip_addr, int mask);
void is_private_ip_address(char *ip_addr);
void is_broadcast_ip_address(char *ip_addr);
void is_network_ip_address(IpAddress ip);
int is_in_network(IpAddress ip, IpAddress network);

#endif