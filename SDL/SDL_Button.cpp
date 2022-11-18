/* Lucas de Azevedo
https://github.com/Fuguety
date: 11/18/2022

This file creates a button, every time the pink button is being pressed, the background color changes
Feel free to use this file as an example for making buttons on SDL
I tried to make the logic very simple to understand
Have a nice day :)*/


#include <SDL2/SDL.h>
#include <iostream>


struct Button
{
	//creates button class
	int x, y, w, h;
	bool pressed;
};



void mouseDown(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
}


void mouseUp(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);

}


void renderRect(SDL_Renderer* renderer, int x, int y, int h, int w)
{
	// Creates and renders the button/square
	SDL_Rect rect;
	rect = {x, y, h, w};
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);	
	SDL_RenderFillRect(renderer, &rect);
}


int main(int argc, char * argv[])
{
	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);

	int width = 640;
	int height = 480;

	window = SDL_CreateWindow("SDL Button attempt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);




	//red when it starts
	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderClear(render);

	// Button parameters
	Button btn;
	btn = {25, 25, 234, 123};

	
	int coordX, coordY;
	// logic for detecting a click on the square: coordX >= btn.x && coordY >= btn.y && coordX <= (btn.x + btn.w) && coordY <= (btn.y + btn.h) 	


	bool running = true;
	SDL_Event ev;

	while(running)
	{
		// Events, where everything happens
		while(SDL_PollEvent(&ev) != 0)
		{
			SDL_GetMouseState(&coordX, &coordY);
			if(ev.type == SDL_QUIT)
				running = false;
		
			//Click on the square to change background color
			if(ev.type == SDL_MOUSEBUTTONDOWN){
				if(ev.button.button == SDL_BUTTON_LEFT && coordX >= btn.x && coordY >= btn.y && coordX <= (btn.x + btn.w) && coordY <= (btn.y + btn.h))
					//hold click it becomes blue
					mouseDown(render);
			}
			
			if(ev.type == SDL_MOUSEBUTTONUP){
				//release click it becomes green
				mouseUp(render);

					
			}
			
		
		
		}

		// Render what's left
		renderRect(render, btn.x, btn.y, btn.w, btn.h);
		
		SDL_RenderPresent(render);
		SDL_UpdateWindowSurface(window);
	}


	SDL_DestroyWindow(window);
	SDL_Quit();

}
