#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void create_file(
        string ip,
        string netmask,
        string wildcard,
        string broadcast,
        string address,
        string first_host,
        string last_host,
        string quan_ip_all,
        string quan_ip_aviable)
{
    setlocale(LC_ALL, "Russian");
    ofstream Data_write("Data.txt");
    Data_write << "IP-address: " << ip << endl;
    Data_write << "Net mask: " << netmask << endl;
    Data_write << "Wildcard: " << wildcard << endl;
    Data_write << "Broadcast: " << broadcast << endl;
    Data_write << "Network address: " << address << endl;
    Data_write << "Firs host: " << first_host << endl;
    Data_write << "Last host: " << last_host << endl;
    Data_write << "Quanity of IP-addresses: " << quan_ip_all << endl;
    Data_write << "Quanity of aviable IP-addresses: " << quan_ip_aviable;
    Data_write.close();
}