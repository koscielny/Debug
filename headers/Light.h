/* Class definition for lights */
#ifndef LIGHT_H
#define LIGHT_H
#include "KDTree.h"

class Light {
public:
	//Light();
	virtual ~Light(){};
	virtual vec3 shade(const Intersection&, TreeNode* tree, bool single_ray) = 0;
	vec3 color;
};

class AreaLight : public Light 
{
public:
	AreaLight(Shape* s) : shapelight(s){};//�ɴ಻��color���� ��Shape���emission������ʵ��shade()
	~AreaLight(){};//shapelightָ�뽻��Vector<Shapes*> shapes �ͷ�

	vec3 shade(const Intersection&, TreeNode* tree, bool single_ray);
	Shape* shapelight;
};

class DirectionalLight : public Light {
public:
	~DirectionalLight(){};
	DirectionalLight(const vec3& color,const vec3& dir);
	vec3 shade(const Intersection& hit, TreeNode* tree, bool single_ray);
	bool isVisible(const vec3& point,  TreeNode* tree);
	vec3 direction;
};

class PointLight : public Light {
public:
	~PointLight(){};
	PointLight(const vec3& color,const vec3& p, double,double,double);
	vec3 shade(const Intersection& hit, TreeNode* tree, bool single_ray);
	bool isVisible(const vec3& point,  TreeNode* tree);
	vec3 point;
	double constant;
	double linear;
	double quadratic;
	double lightradius=0;
	int shadowrays=1;//
};

#endif