#include <pf.h>

//VVC - Velocity Vector Calculator

void VVC_ObjectInit(VVC_Object *object, int moduleChangeingVelocity, int maxModule, int point1X, int point1Y)
{
    object->MCV = moduleChangeingVelocity;
    object->MM = maxModule;

    object->Key.state.left = 0;
    object->Key.state.right = 0;
    object->Key.state.up = 0;
    object->Key.state.down = 0;

    object->Key.timer.left = 0;
    object->Key.timer.right = 0;
    object->Key.timer.up = 0;
    object->Key.timer.down = 0;

    object->Mm = 0;

    object->P1X = point1X;
    object->P1Y = point1Y;

    object->PmX = point1X;
    object->PmY = point1Y;

    object->P2X = point1X;
    object->P2Y = point1Y;

    object->VCoX = 0;
    object->VCoY = 0;
}

void VVC_ObjectEvent(VVC_Object *object, SDL_Event *event)
{
    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_LEFT) object->Key.state.left = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_LEFT) object->Key.state.left = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_RIGHT) object->Key.state.right = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_RIGHT) object->Key.state.right = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_UP) object->Key.state.up = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_UP) object->Key.state.up = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_DOWN) object->Key.state.down = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_DOWN) object->Key.state.down = 0;
}

void VVC_ObjectEventWASD(VVC_Object *object, SDL_Event *event)
{
    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_A) object->Key.state.left = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_A) object->Key.state.left = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_D) object->Key.state.right = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_D) object->Key.state.right = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_W) object->Key.state.up = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_W) object->Key.state.up = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_S) object->Key.state.down = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_S) object->Key.state.down = 0;
}

void VVC_ObjectEventIJKL(VVC_Object *object, SDL_Event *event)
{
    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_J) object->Key.state.left = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_J) object->Key.state.left = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_L) object->Key.state.right = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_L) object->Key.state.right = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_I) object->Key.state.up = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_I) object->Key.state.up = 0;

    if (event->key.type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_K) object->Key.state.down = 1;
    else if (event->key.type == SDL_KEYUP && event->key.keysym.scancode == SDL_SCANCODE_K) object->Key.state.down = 0;
}

void VVC_ObjectCalculation(VVC_Object *object)
{
    if (clock() - object->Key.timer.left >= (1000000 / object->MCV))
    {
        if (object->Key.state.left == 1)
        {
            if (abs(object->PmX - object->P1X) < object->MM)
                object->PmX--;
        }
        else if (object->PmX < object->P1X)
            object->PmX++;
        object->Key.timer.left = clock();
    }
    if (clock() - object->Key.timer.right >= (1000000 / object->MCV))
    {
        if (object->Key.state.right == 1)
        {
            if (abs(object->PmX - object->P1X) < object->MM)
                object->PmX++;
        }
        else if (object->PmX > object->P1X)
            object->PmX--;
        object->Key.timer.right = clock();
    }
    if (clock() - object->Key.timer.up >= (1000000 / object->MCV))
    {
        if (object->Key.state.up == 1)
        {
            if (abs(object->PmY - object->P1Y) < object->MM)
                object->PmY--;
        }
        else if (object->PmY < object->P1Y)
            object->PmY++;
        object->Key.timer.up = clock();
    }
    if (clock() - object->Key.timer.down >= (1000000 / object->MCV))
    {
        if (object->Key.state.down == 1)
        {
            if (abs(object->PmY - object->P1Y) < object->MM)
                object->PmY++;
        }
        else if (object->PmY > object->P1Y)
            object->PmY--;
        object->Key.timer.down = clock();
    }

    object->Mm = sqrt(pow(abs(object->PmX - object->P1X), 2) + pow(abs(object->PmY - object->P1Y), 2));

    if (object->Mm > object->MM)
    {
        if (object->PmX > object->P1X)
        {
            object->P2X = object->P1X + abs(object->PmX - object->P1X) * object->MM / object->Mm;
            if (object->PmY > object->P1Y)
            {
                object->P2Y = object->P1Y + abs(object->PmY - object->P1Y) * object->MM / object->Mm;
            }
            if (object->PmY < object->P1Y)
            {
                object->P2Y = object->P1Y - abs(object->PmY - object->P1Y) * object->MM / object->Mm;
            }
        }
        if (object->PmX < object->P1X)
        {
            object->P2X = object->P1X - abs(object->PmX - object->P1X) * object->MM / object->Mm;
            if (object->PmY > object->P1Y)
            {
                object->P2Y = object->P1Y + abs(object->PmY - object->P1Y) * object->MM / object->Mm;
            }
            if (object->PmY < object->P1Y)
            {
                object->P2Y = object->P1Y - abs(object->PmY - object->P1Y) * object->MM / object->Mm;
            }
        }

    }
    else
    {
        object->P2X = object->PmX;
        object->P2Y = object->PmY;
    }
    object->VCoX = object->P2X - object->P1X;
    object->VCoY = object->P2Y - object->P1Y;
}

//PCA - Player Control Actor

void PCA_Init(PCA_Object *object, int setupPoint_X, int setupPoint_Y, int acceleration, int maxVelocity, int controlTipe, int randChangeTime, int radius, Uint32 color)
{
    object->A_Existence = 1;
    object->A_Tipe = controlTipe;

    object->A_Color = color;
    object->AV_TimerX = 0;
    object->AV_TimerY = 0;

    object->AV_RandTimer = 0;
    object->AV_RandTime = randChangeTime;

    object->A_X = setupPoint_X;
    object->A_Y = setupPoint_Y;
    object->A_R = radius;

    VVC_ObjectInit(&object->AV_Vector, acceleration, maxVelocity, setupPoint_X, setupPoint_Y);
    time(&object->initTime_TT);
    object->initTime_UI = object->initTime_TT * rand();
}

void PCA_Event(PCA_Object *object, SDL_Event *event)
{
    if (object->A_Tipe == 0)
        VVC_ObjectEvent(&(object->AV_Vector), event);
    else if (object->A_Tipe == 1)
        VVC_ObjectEventWASD(&(object->AV_Vector), event);
    else if (object->A_Tipe == 2)
        VVC_ObjectEventIJKL(&(object->AV_Vector), event);
}

void PCA_Rend(PCA_Object *object)
{
    if (clock() - object->AV_RandTimer >= (object->AV_RandTime * 1000000))
    {
    object->AV_Vector.Key.state.left = (rand_r(&object->initTime_UI) % 2) - 1;
    object->AV_Vector.Key.state.right = !object->AV_Vector.Key.state.left;

    object->AV_Vector.Key.state.up = (rand_r(&object->initTime_UI) % 2) - 1;
    object->AV_Vector.Key.state.down = !object->AV_Vector.Key.state.up;

    object->AV_RandTimer = clock();
    }
}

void PCA_Loop(PCA_Object *object, SDL_Surface *surface)
{
    if (object->A_Existence == 1)
    {
        VVC_ObjectCalculation(&object->AV_Vector);

        if (object->AV_Vector.VCoX > 0 && object->A_X < surface->w - object->A_R - 1)
        {
            if (clock() - object->AV_TimerX >= (1000000 / object->AV_Vector.VCoX))
            {
                object->A_X++;
                object->AV_TimerX = clock();
            }
        }
        else if (object->AV_Vector.VCoX < 0 && object->A_X > object->A_R)
        {
            if (clock() - object->AV_TimerX >= (1000000 / -object->AV_Vector.VCoX))
            {
                object->A_X--;
                object->AV_TimerX = clock();
            }
        }

        if (object->AV_Vector.VCoY > 0 && object->A_Y < surface->h - object->A_R - 1)
        {
            if (clock() - object->AV_TimerY >= (1000000 / object->AV_Vector.VCoY))
            {
                object->A_Y++;
                object->AV_TimerY = clock();
            }
        }
        else if (object->AV_Vector.VCoY < 0 && object->A_Y > object->A_R)
        {
            if (clock() - object->AV_TimerY >= (1000000 / -object->AV_Vector.VCoY))
            {
                object->A_Y--;
                object->AV_TimerY = clock();
            }
        }
    }
}

void PCA_Draw(PCA_Object *object, SDL_Surface *surface)
{
    if (object->A_Existence == 1)
        SPM_Circle(surface, object->A_X, object->A_Y, round(object->A_R), object->A_Color);
    else
        SPM_Square(surface, object->A_X - 2, object->A_Y - 2, 4, object->A_Color);
}

void PCA_Collision(PCA_Object *object1, PCA_Object *object2)
{
    if (sqrt(pow(object1->A_X - object2->A_X, 2) + pow(object1->A_Y - object2->A_Y, 2)) <= (object1->A_R + object2->A_R) && object1->A_Existence == 1 && object2->A_Existence == 1)
    {
        if (object1->A_R > object2->A_R)
        {
            object2->A_Existence = 0;
            object1->A_R = sqrt(pow(object2->A_R, 2) + pow(object1->A_R, 2));
        }
        else if (object1->A_R < object2->A_R)
        {
            object1->A_Existence = 0;
            object2->A_R = sqrt(pow(object2->A_R, 2) + pow(object1->A_R, 2));
        }
    }
}
