﻿#include "GLTriangles.h"
namespace omgl{
	const Color &GLTriangles::getColor() const{
		return m_Color;
	}
	void GLTriangles::setColor(const Color &c){
		m_Color = c;
	}
	Vertex &GLTriangles::addVertex(){
		m_Vertices.push_back(Vertex());
		return m_Vertices.back();
	}
	Vertex &GLTriangles::addVertex(const Vertex &v){
		m_Vertices.push_back(v);
		return m_Vertices.back();
	}

	Vertex &GLTriangles::addVertex(const vec3 &p){
		return addVertex(Vertex(p));
	}
	Vertex &GLTriangles::addVertex(float x,float y,float z){
		return addVertex(vec3(x,y,z));
	}

	void GLTriangles::addIndex(int i){
		m_Indices.push_back(i);
	}
	void GLTriangles::addIndex(int i0,int i1,int i2){
		m_Indices.push_back(i0);
		m_Indices.push_back(i1);
		m_Indices.push_back(i2);
	}

	int GLTriangles::getIndexByElementIndex(int i) const{
		return m_Indices[i];
	}
	const Vertex &GLTriangles::getVertexByElementIndex(int i) const{
		return m_Vertices[getIndexByElementIndex(i)];
	}
}