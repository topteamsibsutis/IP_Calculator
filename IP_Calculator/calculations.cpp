#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int transform(string object, int* object_int)
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

string network_adress(string ip, string mask)
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

	(string)adr_str;
	return adr_str;
}

string wildcard(string mask)
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

	(string)wildc_str;
	return wildc_str;
}

string first_host(string netw_adr, string mask)
{
	int netw_int[4], first_host = 0, mask_int[4];
	string temp = netw_adr;
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

	(string)first_host_str;
	return first_host_str;
}