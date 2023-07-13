#include "include/ipfuncs.h"

// Вывод сетевого адреса
void get_network_address(char *ip_addr, int mask)
{
    int octets[4];
    sscanf(ip_addr, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    int maskBit = 32 - mask;
    for (int i = 3; i >= 0; i--)
    {
        if (maskBit >= 8)
        {
            octets[i] = 0;
            maskBit -= 8;
        }
        else if (maskBit > 0)
        {
            octets[i] &= ~(255 >> maskBit);
            maskBit = 0;
        }
    }
    printf("IP-адрес сети: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);
};

// Проверка на частный адрес
void is_private_ip_address(char *ip_addr)
{
    struct in_addr addr;
    inet_aton(ip_addr, &addr);
    uint32_t ip = ntohl(addr.s_addr);

    if ((ip >= 0x0A000000 && ip <= 0x0AFFFFFF) || // 10.0.0.0/8
        (ip >= 0xAC100000 && ip <= 0xAC1FFFFF) || // 172.16.0.0/12
        (ip >= 0xC0A80000 && ip <= 0xC0A8FFFF))
    { // 192.168.0.0/16
        printf("%s является частным адресом\n", ip_addr);
    }
    else
    {
        printf("%s не является частным адресом\n", ip_addr);
    }
}

// Проверка на широковещательный адрес
void is_broadcast_ip_address(char *ip_addr)
{
    struct in_addr addr;
    inet_aton(ip_addr, &addr);
    uint32_t ip = ntohl(addr.s_addr);

    if (ip == 0xFFFFFFFF || (ip & 0xFF) == 0xFF)
    {
        printf("%s является широковещательным адресом\n", ip_addr);
    }
    else
    {
        printf("%s не является широковещательным адресом\n", ip_addr);
    }
}

// Проверка на совпадение с ip-адресами типа "network"
void is_network_ip_address(IpAddress ip)
{
    if (is_in_network(ip, network1) == 1)
    {
        printf("Ip-адрес %s соответствует сетевому адресу network1, то есть %s \n", ip.ip_addr, network1.ip_addr);
        return;
    }
    if (is_in_network(ip, network2) == 1)
    {
        printf("Ip-адрес %s соответствует сетевому адресу network2, то есть %s \n", ip.ip_addr, network2.ip_addr);
        return;
    }
    if (is_in_network(ip, network3) == 1)
    {
        printf("Ip-адрес %s соответствует сетевому адресу network3, то есть %s \n", ip.ip_addr, network3.ip_addr);
        return;
    }
    if (is_in_network(ip, network4) == 1)
    {
        printf("Ip-адрес %s соответствует сетевому адресу network4, то есть %s \n", ip.ip_addr, network4.ip_addr);
        return;
    }

    printf("Ip-адрес %s не соответствует ни одной из сетей\n", ip.ip_addr);
}

int is_in_network(IpAddress ip, IpAddress network)
{
    // Проверяем, совпадают ли первые mask бит IP-адреса и сетевого адреса
    for (int i = 0; i < network.mask / 8; i++)
    {
        if (ip.ip_addr[i] != network.ip_addr[i])
        {
            return 0; // IP-адрес не принадлежит сети
        }
    }

    // Проверяем, совпадает ли последний байт IP-адреса сетевому адресу
    int lastOctetMask = 255 << (8 - (network.mask % 8));
    if ((ip.ip_addr[network.mask / 8] & lastOctetMask) != (network.ip_addr[network.mask / 8] & lastOctetMask))
    {
        return 0; // IP-адрес не принадлежит сети
    }

    return 1;
}