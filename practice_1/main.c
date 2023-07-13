#include <stdio.h>
#include <stdlib.h>
#include "include/ipdata.h"
#include "include/ipfuncs.h"

int main () {
    initialize_ip_data();
    char api_len[16];
    int mask;
    printf("Введите ip-адрес в формате 162.157.78.93/24\n");
    scanf("%15[^/]/%d", api_len, &mask);
    if(mask < 0 || mask > 32) {
        printf("Вы ввели неправильную маску\n");
        return 1;
    }
    IpAddress ip;
    strcpy(ip.ip_addr, api_len);
    ip.mask = mask;
    get_network_address(ip.ip_addr, ip.mask);
    is_broadcast_ip_address(ip.ip_addr);
    is_private_ip_address(ip.ip_addr);
    is_network_ip_address(ip);
    return 0;
}