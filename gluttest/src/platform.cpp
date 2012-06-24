#include "platform.h"

#ifdef _WIN32
#endif

namespace platform{
	
	void initialize(){
		timeBeginPeriod(1);
	}

	uint getTimeMsec(){
		return timeGetTime();
	}
	
	void finalize(){
		timeEndPeriod(1);
	}
	
}

