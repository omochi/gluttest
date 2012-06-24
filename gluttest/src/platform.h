#pragma once

#include "type.h"

#ifdef _WIN32
#include <Windows.h>
#include <MMSystem.h>

#endif

namespace platform{
	void initialize();
	uint getTimeMsec();
	void finalize();
}


