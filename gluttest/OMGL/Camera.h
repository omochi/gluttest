#pragma once

#include "SceneNode.h"

namespace omgl{
	class Camera : public SceneNode{
	private:
	public:
		Camera():SceneNode(){
			m_Width = 0;
			m_Height = 0;
			m_Near=0.1f;
			m_Far = 1000.f;
		}
		//フレームサイズ
		//ビューポートと合わせると良い
		int m_Width;
		int m_Height;

		//カメラ設定
		float m_Near;
		float m_Far;
		virtual mat getProjection() const = 0;
		mat getViewing() const;

	};
}