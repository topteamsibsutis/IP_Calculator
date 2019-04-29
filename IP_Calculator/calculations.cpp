#include <iostream>
#include <stdlib.h>

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
