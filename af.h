#ifndef AF_H
#define AF_H

#include <math.h>

#include <time.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#include <spm.h>


using namespace std;


struct EL
{
    bool existance;
    std::string label;
    std::string text;
    int icon;
};

struct DEL
{
    bool existance;
    int x;
    int y;
    int icon;
};

struct GAME
{
    struct MOUSE
    {
        int x;
        int y;
    };
    bool quit;
    bool pause;
    bool lose;
    bool win;
    int score;
    int level;
    bool events[16];
    MOUSE mouse;
    int a;
};

struct SBI_nonS_Button
{
    bool existance;
    int x;
    int y;
    int w;
    int h;
    bool mor;
    bool push;
};

struct SBI_halfS_Button
{
    bool existance;
    int x;
    int y;
    bool mor;
    bool push;
    SDL_Surface *surface;
};

struct SBI_fullS_Button
{
    bool existance;
    int x;
    int y;
    bool mor;
    bool push;
    bool pwmor;
    bool signal;
    SDL_Surface *default_surface;
    SDL_Surface *mor_surface;
    SDL_Surface *push_surface;
};

std::string bts(bool val);
int set_step(int coordinate, int step);
bool logic(GAME *game, SBI_fullS_Button *button);

int SBI_N_InitButton(SBI_nonS_Button *button, int x1, int y1, int x2, int y2);
int SBI_H_InitButton(SBI_halfS_Button *button, int x, int y, std::string image_path);
int SBI_F_InitButton(SBI_fullS_Button *button, int x, int y, std::string images_path, std::string default_image, std::string mor_image, std::string push_image);
int SBI_N_ButtonEvent(SBI_nonS_Button *button, SDL_Event event);
int SBI_H_ButtonEvent(SBI_halfS_Button *button, SDL_Event event);
int SBI_F_ButtonEvent(SBI_fullS_Button *button, SDL_Event event);
int SBI_H_ButtonImage(SBI_halfS_Button *button, SDL_Surface *surface);
int SBI_F_ButtonAnim(SBI_fullS_Button *button, SDL_Surface *surface);

void GAME_Init(GAME *game);
void GAME_MousOverRect(int x1, int y1, int x2, int y2, GAME *game, int event);
void EL_AddElement(EL *el, std::string label, std::string text, int icon);
int ts_rand(time_t time_seed, int min_val, int max_val);

//int SPM_TTF_BlendedText(SDL_Surface *surface, std::string text_line, TTF_Font *text_font, int text_x, int text_y, SDL_Color text_color);

std::string getvof(std::string id, std::string filepath, std::string filename);
void setvof(std::string id, std::string value, std::string filepath, std::string filename);

#endif // AF_H
