/* Class definition for a shape */
#ifndef SHAPE_H
#define SHAPE_H

#include "Transform.h"
#include "Ray.h"


#define _USE_MATH_DEFINES
#include <math.h>

#include <algorithm>

class AABB {
public:
	AABB(){};
	AABB(vec3&,vec3&);
	vec3 aabbmax;
	vec3 aabbmin;
	double intersect(Ray&);
	vec3 center;
};

class Intersection;
class TreeNode;

class Shape {
	public:
		virtual double intersect(Ray&)=0;
		virtual vec3 getNormal(const vec3&)=0;
		virtual vec3 getNormal(const Intersection&) = 0;//比getNormal(const vec3&)能防止法向弄反
		virtual double getSubtendedAngle(const vec3&)=0;
		virtual vec3 shade(const Intersection&, TreeNode*, bool) = 0;
	//	virtual vec3 getTexture(vec3&){};
		
		AABB aabb;
		//bool hasTexture;
		
		/* material properties */
		vec3 diffuse;
		vec3 specular;
		double shininess;
		vec3 emission;
		double indexofrefraction;
		double refractivity;
		bool assertnorm;//如为NormTriangle则true；如仅为Triangle，norm不一定在正确的那一方向

};

class Sphere : public Shape {
	public:
		Sphere(mat4);
		double intersect(Ray&);
		vec3 getNormal(const vec3&);
		vec3 getNormal(const Intersection&);
		double getSubtendedAngle(const vec3&);
		vec3 shade(const Intersection&, TreeNode*, bool);
		mat4 mv;
		mat4 inv;	
};

class Triangle : public Shape {
	public:
		Triangle(){};
		Triangle(vec3,vec3,vec3);
		double intersect(Ray&);
		virtual vec3 getNormal(const vec3&);
		vec3 getNormal(const Intersection&);////比getNormal(const vec3&)能防止法向弄反

		double getSubtendedAngle(const vec3&);
		vec3 shade(const Intersection&, TreeNode*, bool);
	//	vec3 getTexture(vec3&);
	
		vec3 p0;
		vec3 p1;
		vec3 p2;
		vec3 n0;
};

class NormTriangle : public Triangle {
public:
	NormTriangle(vec3,vec3,vec3,vec3,vec3,vec3);
	vec3 getNormal(const vec3&);
	vec3 getNormal(const Intersection&);

	vec3 n1;
	vec3 n2;
};

#endif 