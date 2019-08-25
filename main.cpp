#include <af.h>
#include <pf.h>



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <errno.h>




using namespace std;

SDL_Window *window;
SDL_Surface *screen = NULL;
TTF_Font *main_font;
TTF_Font *main_font2;
TTF_Font *main_font3;
int selectButton[6];
int playersNumber = 0;
time_t st;
Uint32 menuback_color;
Uint32 background_color;
bool mainQuit = 0;



int main()
{
    int window_width, window_height;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    main_font = TTF_OpenFont("Data/Fonts/OpenSans-Bold.ttf", 12);
    main_font2 = TTF_OpenFont("Data/Fonts/OpenSans-Bold.ttf", 8);
    main_font3 = TTF_OpenFont("Data/Fonts/SF_Archery_Black.ttf", 86);

    char *cwd = new char[256];
    getcwd(cwd, 256);
    std::cout << "cwd: " << cwd << "\n";



    std::cout << getvof("window_width", "", "mp_config") << "\n";
    std::cout << getvof("window_height", "", "mp_config") << "\n";

    window_width = std::stoi(getvof("window_width", "", "mp_config"), NULL, 10);
    window_height = std::stoi(getvof("window_height", "", "mp_config"), NULL, 10);

    //window_width = 840;
    //window_height = 640;

    if (getvof("fullscreen", "", "mp_config") == "true")
    {
        window = SDL_CreateWindow("DzinaiGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    else
    {
        window = SDL_CreateWindow("DzinaiGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
    }

    screen = SDL_GetWindowSurface(window);

    mf_mainmanu();

    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
