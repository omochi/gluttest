#include "Camera.h"

namespace omgl{
	mat Camera::getViewing() const{
		//カメラがモデルに親子付けするケースを考えておきたいので一般形
		mat m = glm::inverse(getWorldTransform());
		return m;
	}

}