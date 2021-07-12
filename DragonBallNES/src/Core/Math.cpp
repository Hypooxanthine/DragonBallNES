#include "Math.h"

float clamp(const float& val, const float& min, const float& max)
{
	if (val > max)
		return max;
	else if (val < min)
		return min;
	else
		return val;
}
