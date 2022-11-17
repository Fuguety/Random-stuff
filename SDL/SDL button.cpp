// SImple function of mouse button down of SDL

#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char * argv[])
{
	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("hello there", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	//red when it starts
	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderClear(render);



	bool running = true;
	SDL_Event ev;

	while(running)
	{
		while(SDL_PollEvent(&ev) != 0)
		{
			if(ev.type == SDL_QUIT)
				running = false;
		
			if(ev.type == SDL_MOUSEBUTTONDOWN){
				//hold click it becomes blue
				SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
				
			}
			if(ev.type == SDL_MOUSEBUTTONUP){
				//release click it becomes green
				SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
					
				
			}
			
		
		
		}

			
		SDL_RenderClear(render);
		
		SDL_RenderPresent(render);
		SDL_UpdateWindowSurface(window);
	}


	SDL_DestroyWindow(window);
	SDL_Quit();

}
