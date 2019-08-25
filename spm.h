#ifndef SPM_H
#define SPM_H

#define SPM_PI 3.141592653589793238462643383279502884

#include <SDL2/SDL.h>
#include <SDL2/SDL2_rotozoom.h>
#include <SDL2/SDL_ttf.h>
#include <string>

Uint32 SPM_ColorRGB(Uint8 R, Uint8 G, Uint8 B);

Uint32 SPM_ColorRGB2(Uint32 c);

void SPM_FillPixel(SDL_Surface *surface, int x, int y, Uint32 color);
Uint32 SPM_GetPixel(SDL_Surface *surface, int x, int y);

void SPM_Line(SDL_Surface *surface, int point1_x, int point1_y, int point2_x, int point2_y, Uint32 color);
void SPM_VerticalLine(SDL_Surface *surface, int point_x, int point_y, int l, Uint32 color);
void SPM_HorizontalLine(SDL_Surface *surface, int point_x, int point_y, int l, Uint32 color);
void SPM_Square(SDL_Surface *surface, int point_x, int point_y, int l, Uint32 color);
void SPM_FillSquare(SDL_Surface *surface, int point_x, int point_y, int l, Uint32 color);
void SPM_Rect(SDL_Surface *surface, int point1_x, int point1_y, int point2_x, int point2_y, Uint32 color);
void SPM_FillArea(SDL_Surface *surface, int point1_x, int point1_y, int point2_x, int point2_y, Uint32 color);
void SPM_Circle(SDL_Surface *surface, int point1_x, int point1_y, int radius, Uint32 color);
void SPM_Grid(SDL_Surface *surface, int point1_x, int point1_y, int point2_x, int point2_y, int interval, Uint32 color);

void SPM_BlitRotatedSurface(SDL_Surface *surface, SDL_Surface *screen_surface, int x, int y, int angle, double zoom, int smooth);

void SPM_TTF_BlendedText(SDL_Surface *surface, std::string text_line, TTF_Font *text_font, int text_x, int text_y, SDL_Color text_color);
void SPM_TTF_BlendedText(SDL_Surface *surface, std::string text_line, TTF_Font *text_font, int text_x, int text_y, Uint32 color);

SDL_Surface *SPM_CutOutSurface(SDL_Surface *surface, int x, int y, int w, int h);
SDL_Surface *SPM_Flip(SDL_Surface *surface, bool xFlip, bool yFlip);

#endif // SPM_H
