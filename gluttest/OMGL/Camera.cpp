#include "Camera.h"

namespace omgl{
	mat Camera::getViewing() const{
		//�J���������f���ɐe�q�t������P�[�X���l���Ă��������̂ň�ʌ`
		mat m = glm::inverse(getWorldTransform());
		return m;
	}
}