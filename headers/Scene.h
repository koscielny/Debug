#ifndef SCENE_H  
#define SCENE_H

#include "KDTree.h"

class Scene {
	public:
		vec3 w;
		vec3 u;
		vec3 v;
		int width;
		int height;
		int maxdepth;
		std::string filename;
		double fovy;
		double fovx;
		vec3 eye;
		glm::vec3 camera_eye;
		glm::vec3 camera_lookat;
		glm::vec3 camera_up;
		double camera_fovy;

		std::vector<Shape*> objects;
		AABB sceneAABB;
		TreeNode* KDTree;
		
		vec3 diffuse;
		vec3 specular;
		double shininess;
		vec3 emission;
		double indexofrefraction;
		double refractivity;
		
		double antialias;
		int shadowrays;
		double lightradius;
		
		std::vector<Light*> lights;
		//std::vector<Shape*> lights;
		bool isLight;
		
		Scene(char*);
		~Scene();
		Ray castEyeRay(double,double);
		vec3 castpoint(double i, double j);
		void setCoordinateFrame(vec3&, vec3&);
		void parseLine(std::string,std::stack<mat4>&,
			std::vector<vec3>&,std::vector<vec3>&,std::vector<vec3>&);
		void parse(char*);
		void updateAABB(vec3&);
};


#endif