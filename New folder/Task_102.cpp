#include <SDL2/SDL.h>
#include <iostream>

const int screenWidth = 1000;
const int screenHeight = 600;
const int initialRadius = 100;

void drawCircle(SDL_Renderer *renderer, int x, int y, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    for (int dy = -radius; dy <= radius; ++dy)
    {
        int dySquared = dy * dy;
        for (int dx = -radius; dx <= radius; ++dx)
        {
            int dxSquared = dx * dx;
            if (dxSquared + dySquared <= radius * radius)
            {
                int pixelX = x + dx;
                int pixelY = y + dy;
                if (pixelX >= 0 && pixelX < screenWidth && pixelY >= 0 && pixelY < screenHeight)
                {
                    SDL_RenderDrawPoint(renderer, pixelX, pixelY);
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Circle Collision",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    int radius = initialRadius;
    int x = screenWidth / 2;
    int y = screenHeight / 2;

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 125, 50, 180, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 153, 196, 210, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255); 
        drawCircle(renderer, x, y, radius, 128, 0, 128, 255);

        SDL_RenderPresent(renderer);

        radius++;

        if (x - radius < 0 || x + radius > screenWidth || y - radius < 0 || y + radius > screenHeight)
        {
            radius = initialRadius;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
