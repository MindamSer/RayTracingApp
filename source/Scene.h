#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "Image.h"
#include "Camera.h"
#include "ObjSphere.h"
#include "PointLight.h"

namespace RT
{
	class Scene
	{
	public:
		Scene();
		
		bool Render(Image &outputImage);
		
	private:
		RT::Camera m_camera;
		
		std::vector<std::shared_ptr<RT::ObjectBase>> m_objectList;
		
		std::vector<std::shared_ptr<RT::LightBase>> m_lightList;
	
	};
}

#endif
