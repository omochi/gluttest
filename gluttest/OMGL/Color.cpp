#include "Color.h"

namespace omgl{


	Color getColor(int idx){
		return ColorList[idx%ARRAY_SIZE(omgl::ColorList)];
	}

}