#pragma once
#include "../common.h"
#include "../Color.h"
namespace omgl{
	class Vertex{
	public:
		vec3 pos;
		vec3 normal;
		Color color;
		vec2 tex;
		Vertex(){};
		Vertex(vec3 p):pos(p){}
		Vertex &setPos(vec3 p);
		Vertex &setPos(float x,float y,float z);
		Vertex &setNormal(vec3 n);
		Vertex &setNormal(float x,float y,float z);
	};

	typedef std::vector<Vertex> VertexList;

	void VertexListToBufP(std::vector<float> &dst,const VertexList &list);
	void VertexListToBufPN(std::vector<float> &dst,const VertexList &list);
}