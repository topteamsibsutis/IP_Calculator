#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>


int transform(std::string object, int* object_int)
{
	int i = 0, j = 0, a = 0;
	char part[4][4];
	while (object[i] != '\0') {
		if ((object[i] < 48 || object[i] > 57) && object[i] != '.')
			return 1;

		if (object[i] == '.') {
			i++;
			a = 0;
			j++;
		}

		part[j][a] = object[i];
		a++;
		i++;
	}

	for (i = 0; i < 4; i++) {
		object_int[i] = atoi(part[i]);
		if (object_int[i] < 0 || object_int[i] > 255)
			return 1;
	}
	return 0;
}

std::string network_adress(std::string ip, std::string mask)
{
	int ip_int[4], mask_int[4], netw_adr[4];
	char adr_str[16] = "\0", adr_double_arr[4][4];

	transform(ip, ip_int);
	transform(mask, mask_int);


	for (int i = 0; i < 4; i++) {
		netw_adr[i] = ip_int[i] & mask_int[i];
		sprintf_s(
			adr_double_arr[i],
			4,
			"%d",
			netw_adr[i]);

	}

	int row = 0, col = 0;
	for (int i = 0; i < 16; i++) {
		if (adr_double_arr[row][col] != '\0') {
			adr_str[i] = adr_double_arr[row][col];

			col++;
		}
		else {
			if (row == 3)
				break;
			adr_str[i] = '.';
			row++;
			col = 0;
		}
	}

	(std::string)adr_str;
	return adr_str;
}

std::string wildcard(std::string mask)
{
	int mask_int[4], wildc_int[4];
	char wildc_str[16] = "\0", wildc_double_arr[4][4];

	transform(mask, mask_int);

	for (int i = 0; i < 4; i++) {
		wildc_int[i] = 255 - mask_int[i];
		sprintf_s(wildc_double_arr[i], 4, "%d", wildc_int[i]);
	}

	int row = 0, col = 0;
	for (int i = 0; i < 16; i++) {
		if (wildc_double_arr[row][col] != '\0') {
			wildc_str[i] = wildc_double_arr[row][col];
			col++;
		}
		else {
			if (row == 3)
				break;
			wildc_str[i] = '.';
			row++;
			col = 0;
		}
	}

	(std::string)wildc_str;
	return wildc_str;
}

std::string first_host(std::string netw_adr, std::string mask)
{
	int netw_int[4], first_host = 0, mask_int[4];
	std::string temp = netw_adr;
	char first_host_str[16];
	transform(netw_adr, netw_int);
	transform(mask, mask_int);

	strcpy_s(first_host_str, temp.c_str());
	if (mask_int[3] != 255) {
		for (int i = 0; i < 16; i++) {
			if (first_host_str[i] == '\0') {
				first_host_str[i - 1] = first_host_str[i - 1] + 1;
				break;
			}
		}
	}

	(std::string)first_host_str;
	return first_host_str;
}

std::string last_host(std::string wildcard, std::string netw_adr)
{
	int netw_int[4], wildc_int[4], l_host[4];
	char l_host_str[16] = "\0", l_host_double_arr[4][4];

	transform(netw_adr, netw_int);
	transform(wildcard, wildc_int);

	for (int i = 0; i < 4; i++) {
		if (i != 3 || wildc_int[3] <= 1) {
			l_host[i] = wildc_int[i] | netw_int[i];
		}
		else
			l_host[i] = (wildc_int[i] | netw_int[i]) - 1;
		sprintf_s(l_host_double_arr[i], 4, "%d", l_host[i]);
	}

	int row = 0, col = 0;
	for (int i = 0; i < 16; i++) {
		if (l_host_double_arr[row][col] != '\0') {
			l_host_str[i] = l_host_double_arr[row][col];
			col++;
		}
		else {
			if (row == 3)
				break;
			l_host_str[i] = '.';
			row++;
			col = 0;
		}
	}

	(std::string)l_host_str;
	return l_host_str;
}

std::string broadcast(std::string netw_adr, std::string wildcard)
{
	int netw_int[4], wildc_int[4], brd_int[4];
	char brd_str[16] = "\0", brd_double_arr[4][4];

	transform(netw_adr, netw_int);
	transform(wildcard, wildc_int);

	for (int i = 0; i < 4; i++) {
		brd_int[i] = wildc_int[i] | netw_int[i];
		sprintf_s(brd_double_arr[i], 4, "%d", brd_int[i]);
	}

	int row = 0, col = 0;
	for (int i = 0; i < 16; i++) {
		if (brd_double_arr[row][col] != '\0') {
			brd_str[i] = brd_double_arr[row][col];
			col++;
		}
		else {
			if (row == 3)
				break;
			brd_str[i] = '.';
			row++;
			col = 0;
		}
	}

	(std::string)brd_str;
	return brd_str;
}

std::string quan_ip(std::string broad, std::string netw_adr)
{
	unsigned long long quan = 1;
	char quan_str[11] = "\0";
	int brd_int[4], netw_int[4];
	transform(broad, brd_int);
	transform(netw_adr, netw_int);
	for (int i = 0; i < 4; i++) {
		quan = quan * (brd_int[i] - netw_int[i] + 1);
	}
	sprintf_s(quan_str, 11, "%llu", quan);
	(std::string)quan_str;
	return quan_str;
}

std::string quan_aviable(std::string quan)
{
	char quan_use_str[11];
	long long quan_int, quan_use_int;
	quan_int = atoll(quan.c_str());
	if (quan_int - 2 > 0)
		quan_use_int = quan_int - 2;
	else
		quan_use_int = quan_int;
	sprintf_s(quan_use_str, 11, "%lld", quan_use_int);
	(std::string)quan_use_str;
	return quan_use_str;
}



TEST(Network_adr, Zeros) {
	std::string expected = "0.0.0.0";
	std::string result = network_adress("192.168.0.1", "0.0.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Network_adr, Max) {
	std::string expected = "192.168.0.1";
	std::string result = network_adress("192.168.0.1", "255.255.255.255");

	EXPECT_EQ(expected, result);
}

TEST(Network_adr, Rand) {
	std::string expected = "192.168.0.0";
	std::string result = network_adress("192.168.0.1", "255.255.255.0");

	EXPECT_EQ(expected, result);
}

TEST(Wildcard, Zeros) {
	std::string expected = "255.255.255.255";
	std::string result = wildcard("0.0.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Wildcard, Max) {
	std::string expected = "0.0.0.0";
	std::string result = wildcard("255.255.255.255");

	EXPECT_EQ(expected, result);
}

TEST(Wildcard, Rand) {
	std::string expected = "0.0.127.255";
	std::string result = wildcard("255.255.128.0");

	EXPECT_EQ(expected, result);
}

TEST(First_host, Zeros) {
	std::string expected = "0.0.0.1";
	std::string result = first_host("0.0.0.0", "0.0.0.0");

	EXPECT_EQ(expected, result);
}

TEST(First_host, Max) {
	std::string expected = "192.168.0.1";
	std::string result = first_host("192.168.0.1", "255.255.255.255");

	EXPECT_EQ(expected, result);
}

TEST(First_host, Rand) {
	std::string expected = "192.168.0.1";
	std::string result = first_host("192.168.0.0", "255.255.128.0");

	EXPECT_EQ(expected, result);
}

TEST(Last_host, Zeros) {
	std::string expected = "255.255.255.254";
	std::string result = last_host("255.255.255.255", "0.0.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Last_host, Max) {
	std::string expected = "192.168.0.1";
	std::string result = last_host("0.0.0.0", "192.168.0.1");

	EXPECT_EQ(expected, result);
}

TEST(Last_host, Rand) {
	std::string expected = "192.168.63.254";
	std::string result = last_host("0.0.63.255", "192.168.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Broadcast, Zeros) {
	std::string expected = "255.255.255.255";
	std::string result = broadcast("0.0.0.0", "255.255.255.255");

	EXPECT_EQ(expected, result);
}

TEST(Broadcast, Max) {
	std::string expected = "192.168.0.1";
	std::string result = broadcast("192.168.0.1", "0.0.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Broadcast, Rand) {
	std::string expected = "192.168.0.127";
	std::string result = broadcast("192.168.0.0", "0.0.0.127");

	EXPECT_EQ(expected, result);
}

TEST(Quantity, Zeros) {
	std::string expected = "4294967296";
	std::string result = quan_ip("255.255.255.255", "0.0.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Quantity, Max) {
	std::string expected = "1";
	std::string result = quan_ip("192.168.0.1", "192.168.0.1");

	EXPECT_EQ(expected, result);
}

TEST(Quantity, Rand) {
	std::string expected = "8192";
	std::string result = quan_ip("192.168.31.255", "192.168.0.0");

	EXPECT_EQ(expected, result);
}

TEST(Quantity_used, Zeros) {
	std::string expected = "4294967294";
	std::string result = quan_aviable("4294967296");

	EXPECT_EQ(expected, result);
}

TEST(Quantity_used, Max) {
	std::string expected = "1";
	std::string result = quan_aviable("1");

	EXPECT_EQ(expected, result);
}

TEST(Quantity_used, Rand) {
	std::string expected = "8190";
	std::string result = quan_aviable("8192");

	EXPECT_EQ(expected, result);
}