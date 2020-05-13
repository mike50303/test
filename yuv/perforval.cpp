#include "perforval.h"

long long gct()
{
	using namespace std::chrono;
	high_resolution_clock::time_point tp = high_resolution_clock::now();
	milliseconds ms = duration_cast<milliseconds>(tp.time_since_epoch());
	return ms.count();
}
