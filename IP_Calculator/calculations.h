#pragma once
#include <iostream>
#include <string>

std::string network_adress(std::string ip, std::string mask);
std::string wildcard(std::string mask);
std::string first_host(std::string netw_adr, std::string mask);

