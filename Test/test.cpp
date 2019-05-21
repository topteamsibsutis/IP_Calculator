#include "pch.h"

int error = 0;

void check_ip_input(std::string ip_input_string)
{
	int k = 0;

	while (ip_input_string[k] != '\0')
	{
		k++;
	}

	if (ip_input_string[k - 1] == '.')
	{
		error = 1;
	}
}

TEST(Check_ip_input, Check_ip_input) {
	check_ip_input("192.168.0.");
	EXPECT_EQ(1, error);
}