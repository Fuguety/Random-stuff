#include <iostream>
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


	// Render the rectangle with the color yellow
	SDL_Rect rect;
	rect = {10, 10, 50, 50};
    SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
	SDL_RenderFillRect(render, &rect);

	
	// Updates the window for rendering other objects
	SDL_RenderPresent(render);
	SDL_UpdateWindowSurface(window);


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