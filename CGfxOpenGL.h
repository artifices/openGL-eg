#ifndef CGFX_OPENGL
#define CGFX_OPENGL

#include "SDL.h" 
#include "SDL_opengl.h"
#include "math.h"

#pragma warning(disable:4305) // disable implicit float double casting

class CGfxOpenGL 
{
private:
	int windowWidth;
	int windowHeight;
	float angle;

public:
	CGfxOpenGL();
	virtual ~ CGfxOpenGL();

	bool Initialize();
	bool Shutdown();
	
	void SetupProjection(int width, int height);
	void Prepare(float dt);
	void Render();

	void CreateNewCube(float xOrigin, float yOrigin, float zOrigin);
	
};

#endif