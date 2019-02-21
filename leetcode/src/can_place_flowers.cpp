#include "can_place_flowers.h"


using namespace std;

bool hasNeighbor(std::vector<int>& flowerbed, int pos) {
	if (pos > 0 && flowerbed[pos - 1] == 1)
		return true;
	if (pos < flowerbed.size() - 1 && flowerbed[pos + 1] == 1)
		return true;
	return false;
}


bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
{
	if (n == 0)
		return true;
	for (int i = 0; i < flowerbed.size(); ++i) {
		if (flowerbed[i] == 1)
			continue;

		if (!hasNeighbor(flowerbed, i)) {
			n--;
			flowerbed[i] = 1;
		}

		if (n == 0)
			break;
	}
	return n <= 0;
}
