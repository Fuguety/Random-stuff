#include <iostream>
#include <string>
#include <SDL2/SDL.h>
using namespace std;



int main(int argc, char* argv[])
{


	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);

	
	// window parameters
	int width = 640;
	int height = 480;

	// defines window
	window = SDL_CreateWindow("Title here", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	// defines render
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    	SDL_RenderClear(render);

	bool running = true;
	SDL_Event ev;

// Loop for executing the window
    while(running)
	{
		// Events, where everything happens
		while(SDL_PollEvent(&ev) != 0)
		{
			if(ev.type == SDL_QUIT)
				running = false;
		}
    }



    // End/Destroy everything
	SDL_DestroyWindow(window);
	SDL_Quit();


}
