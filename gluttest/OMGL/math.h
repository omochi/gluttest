#pragma once

#include "common.h"

namespace omgl{
	mat lookAt(vec3 front,vec3 up);
	mat lookAt(vec3 eye,vec3 at,vec3 up);

}