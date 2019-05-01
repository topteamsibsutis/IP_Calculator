#pragma once
#include <iostream>
#include <string>

std::string network_adress(std::string ip, std::string mask);
std::string wildcard(std::string mask);
std::string first_host(std::string netw_adr, std::string mask);
std::string last_host(std::string wildcard, std::string netw_adr);
std::string broadcast(std::string netw_adr, std::string wildcard);
std::string quan_ip(std::string broad, std::string netw_adr);
std::string quan_aviable(std::string quan);
