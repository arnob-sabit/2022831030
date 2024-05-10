#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
int R=75;
SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
bool gameIsRunning=false;

int X=-R;
int Y=SCREEN_HEIGHT/2;

int x=SCREEN_WIDTH/2;
int y=SCREEN_HEIGHT-R;
bool col=false;
int r_color1=0;
int  g_color1=50;
int  b_color1=100;
int r_color2=255;
int  g_color2=140;
int  b_color2=0;
int  f=0;

int initializing(){
if(SDL_Init(SDL_INIT_VIDEO)!=0){
std::cout<<"Error: SDL failed to initialize\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
return 0;
}


 win = SDL_CreateWindow("Drawing Circle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
if (!win)
    {
       std::cout<<"Error: SDL failed to open window\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
       return 0;;
    }



    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!rend)
    {
        std::cout<<"Error: SDL failed to create renderer\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
        return 0;;
    }

	return 1;
}


bool collision(int x,int y,int X,int Y)
{
int d;
d=(x-X)*(x-X)+(y-Y)*(y-Y);
if(d<=4*R*R) return true;
return false;
}


void update()
{
 col=collision(x,y,X,Y);
 if(col) {
    
    X=-R;

    int temp_r = r_color1;
    int temp_g = g_color1;
    int temp_b = b_color1;
    r_color1 = r_color2;
    g_color1 = g_color2;
    b_color1 = b_color2;
    r_color2 = temp_r;
    g_color2 = temp_g;
    b_color2 = temp_b;
    if(f==0){r_color1=255;g_color1=140;b_color1=0; f=1;}
    else {r_color1=0;g_color1=50;b_color1=100; f=0;}
    
    }

else
{
 X+=2;
if(X>=SCREEN_WIDTH+R) X=0;
}


}
void draw_Circle( int centerX, int centerY, int radius) {
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (x*x + y*y <= radius*radius) {
                SDL_RenderDrawPoint(rend, centerX + x, centerY + y);
            }
        }
    }
}



void Draw()
{
    SDL_SetRenderDrawColor(rend, 153, 196, 210, 255); 

    SDL_RenderClear(rend);

    update();

    SDL_SetRenderDrawColor(rend, r_color1, g_color1, b_color1, 255);
    draw_Circle(X, Y, R);

    SDL_SetRenderDrawColor(rend, r_color2, g_color2, b_color2, 255);
    draw_Circle(x, y, R);

    SDL_RenderPresent(rend);
}


void  event_loop()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
     {
       if(event.type==SDL_QUIT) {gameIsRunning=false; break;}
       else if (event.type == SDL_KEYDOWN) {
                        if(event.key.keysym.sym==SDLK_UP) 
                        {
                            y-=10;
                            if(y==R) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}
                        }
                        if(event.key.keysym.sym== SDLK_DOWN)
                        {
                             y+=10;
                            if(y+R>SCREEN_HEIGHT) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}

                        }
                        if(event.key.keysym.sym== SDLK_LEFT)
                        {
                            x-=10;
                            if(x==R) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}
                             
                        }
                        if(event.key.keysym.sym==SDLK_RIGHT)
                        {
                          
                            x+=10;
                            if(x+R==SCREEN_WIDTH) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}
                        }
                    }
     
     }

}


int main(int argc,char *argv[])
{
gameIsRunning=initializing();

while(gameIsRunning)
{
	event_loop();
    Draw();
}

SDL_DestroyWindow(win);
SDL_Quit();

return 0;
}
