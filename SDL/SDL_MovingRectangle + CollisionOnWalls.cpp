#include <iostream>
#include <SDL2/SDL.h>
using namespace std;


int CollisionWallX(int posX, int blockWidth, int screenWidth)
{
    // Check collision on X

    if(posX < 0)
        posX = posX + 10;
    
    if(posX + blockWidth > screenWidth)
        posX = posX - 10;

    return(posX);

}




int CollisionWallY(int posY, int blockHeight, int screenHeight)
{
    // Check collision on Y

    if(posY < 0)
        posY = posY + 10;
    
    if(posY + blockHeight > screenHeight)
        posY = posY - 10;

    return(posY);

}







void RenderRect(SDL_Renderer* render, int x, int y, int blockWidth, int blockHeight)
{

    // Rectangle coordinates and dimention
    SDL_Rect rect = {x, y, blockWidth, blockHeight};

        
    SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
	SDL_RenderFillRect(render, &rect);

}







int main(int argc, char* argv[])
{


	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);

    // Window dimentions
	int width = 640;
	int height = 480;

	window = SDL_CreateWindow("Title here", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	bool running = true;
	SDL_Event ev;
    
    // Initial coordinates of block(0, 0)
    int x, y;
    x = 80;
    y = 80;

    // Rectangle dimenstions
    int blockWidth, blockHeight;
    blockWidth = 50;
    blockHeight = 50;



    // Loop of window running
    while(running)
	{
		// Events, where everything happens
		while(SDL_PollEvent(&ev) != 0)
		{
			if(ev.type == SDL_QUIT)
				running = false;
            


            else if(ev.type == SDL_KEYDOWN)
            {
                switch( ev.key.keysym.sym )
                {
                    case SDLK_UP:
                    y = y - 5;
                    break;

                    case SDLK_DOWN:
                    y = y + 5;
                    break;

                    case SDLK_LEFT:
                    x = x - 5;
                    break;

                    case SDLK_RIGHT:
                    x = x + 5;
                    break;

                    case SDLK_ESCAPE:
                    running = false;
                    break;
                    
                }
            }

		}

        
        // Update window
        SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
        SDL_RenderClear(render);


        // Check Collision
        x = CollisionWallX(x, blockWidth, width);
        y = CollisionWallY(y, blockHeight, height);

        // Render Rectangle
        RenderRect(render, x, y, blockWidth, blockHeight);

        // Render what's left
        SDL_RenderPresent(render);
		SDL_UpdateWindowSurface(window);
    }



    // End/Destroy everything
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;

}
