#include "Vertex.h"

namespace omgl{
	Vertex &Vertex::setPos(vec3 p){
		pos = p;
		return *this;
	}
	Vertex &Vertex::setPos(float x,float y,float z){
		setPos(vec3(x,y,z));
		return *this;
	}
	void VertexListToBufP(std::vector<float> &dst,const VertexList &list){
		dst.clear();
		dst.reserve(list.size()*3);
		for(VertexList::const_iterator i = list.begin();i!=list.end();i++){
			dst.push_back((*i).pos.x);
			dst.push_back((*i).pos.y);
			dst.push_back((*i).pos.z);
		}
	}
	void VertexListtoBufPN(std::vector<float> &dst,const VertexList &list){
		dst.clear();
		dst.reserve(list.size()*6);
		for(VertexList::const_iterator i = list.begin();i!=list.end();i++){
			dst.push_back((*i).pos.x);
			dst.push_back((*i).pos.y);
			dst.push_back((*i).pos.z);
			dst.push_back((*i).normal.x);
			dst.push_back((*i).normal.y);
			dst.push_back((*i).normal.z);
		}
	}
}