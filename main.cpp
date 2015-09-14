#include "CGfxOpenGL.h"

int main(int argc, char* args[]) 
{
	// SDL initialization
	bool running = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
	SDL_WM_SetCaption("OpenGL Test", NULL);
	SDL_Event check;

	// OpenGL initialization
	CGfxOpenGL* glContext = new CGfxOpenGL;
	glContext->SetupProjection(640,480);
	glContext->Initialize();

	while (running)
	{
		while(SDL_PollEvent(&check))
		{
			if (check.type == SDL_QUIT)
				running = false;
			
		}
		glContext->Prepare(0.0f);
		glContext->Render();
		SDL_GL_SwapBuffers();
		SDL_Delay(1);

	}

	
	return 0;
}
