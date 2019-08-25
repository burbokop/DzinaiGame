#ifndef PF_H
#define PF_H

#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <spm.h>

//VVC - Velocity Vector Calculator

struct VVC_Object
{
    struct ArrowKey
    {
        struct State
        {
            bool up;
            bool down;
            bool right;
            bool left;
        };
        State state;
        struct Timer
        {
            clock_t up;
            clock_t down;
            clock_t right;
            clock_t left;
        };
        Timer timer;
    };
    ArrowKey Key;

    int MCV;                        //moduleChangeingVelocity
    int MM;                         //maxModule
    int P1X;                        //point1X
    int P1Y;                        //point1Y

    int PmX;                        //point2Xmediate
    int PmY;                        //point2Ymediate
    int P2X;                        //point2X
    int P2Y;                        //point2Y
    int Mm;                         //Module mediate

    int VCoX;
    int VCoY;
};

//functions:
void VVC_ObjectInit(VVC_Object *object, int moduleChangeingVelocity, int maxModule, int point1X, int point1Y);
void VVC_ObjectEvent(VVC_Object *object, SDL_Event *event);
void VVC_ObjectEventWASD(VVC_Object *object, SDL_Event *event);
void VVC_ObjectEventIJKL(VVC_Object *object, SDL_Event *event);
void VVC_ObjectCalculation(VVC_Object *object);

//PCA - Player Control Actor

struct PCA_Object
{
    bool A_Existence;
    int A_Tipe;
    Uint32 A_Color;
    VVC_Object AV_Vector;

    clock_t AV_TimerX;
    clock_t AV_TimerY;

    clock_t AV_RandTimer;
    int AV_RandTime;

    int A_X;
    int A_Y;
    float A_R;

    time_t initTime_TT;
    unsigned int initTime_UI;
};

//functions:
void PCA_Init(PCA_Object *object, int setupPoint_X, int setupPoint_Y, int acceleration, int maxVelocity, int controlTipe, int randChangeTime, int radius, Uint32 color);
void PCA_Event(PCA_Object *object, SDL_Event *event);
void PCA_Rend(PCA_Object *object);
void PCA_Loop(PCA_Object *object, SDL_Surface *surface);
void PCA_Draw(PCA_Object *object, SDL_Surface *surface);
void PCA_Collision(PCA_Object *object1, PCA_Object *object2);


void mf_mainmanu();
void mf_mainloop();

extern bool mainQuit;
extern SDL_Window *window;
extern SDL_Surface *screen;
extern TTF_Font *main_font;
extern TTF_Font *main_font2;
extern TTF_Font *main_font3;
extern int selectButton[6];
extern int playersNumber;
extern time_t st;
extern Uint32 menuback_color;
extern Uint32 background_color;

#endif // PF_H
