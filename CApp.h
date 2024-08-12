#ifndef CAPP_H
#define CAP_H

#include <SDL2/SDL.h>
#include "./source/Image.h"
#include "./source/Scene.h"
#include "./source/Camera.h"

class CApp
{
public:
	CApp();

	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnLoop();
	void OnRender();
	void OnExit();
		
private:
	Image m_image;
	RT::Scene m_scene;
	bool isRunning;
	SDL_Window *pWindow;
	SDL_Renderer* pRenderer;
	
	void PrintVector(const qbVector<double> &inputVector);

};

#endif // !CAPP_H

