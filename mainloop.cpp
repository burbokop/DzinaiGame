#include <af.h>
#include <pf.h>

using namespace std;

void mf_mainloop()
{
    time(&st);
    PCA_Object player1Actor;
    PCA_Object player2Actor;
    PCA_Object player3Actor;
    int computerActorsAmount = stoi(getvof("bots_amount", "", "mp_config"), NULL, 10);
    PCA_Object computerActor[computerActorsAmount];

    bool p_quit = 0;
    bool quit = 0;
    time_t p_quit_ht = 0;

    bool showVectors = 0;
    bool endGame = 1;
    background_color = SPM_ColorRGB2(stoi(getvof("background_color", "", "mp_config"), NULL, 10));

    SDL_ShowCursor(SDL_DISABLE);

    if (getvof("mode", "", "mp_config") == "random")
    {
        PCA_Init(&player1Actor, screen->w / 2 - 128, screen->h / 2 - 128, ts_rand(st, 32, 86), ts_rand(st, 64, 256), 0, 0, ts_rand(st, 4, 24), SPM_ColorRGB2(stoi(getvof("player1_color", "", "mp_config"), NULL, 10)));
        PCA_Init(&player2Actor, screen->w / 2 + 128, screen->h / 2 - 128, ts_rand(st, 32, 86), ts_rand(st, 64, 256), 1, 0, ts_rand(st, 4, 24), SPM_ColorRGB2(stoi(getvof("player2_color", "", "mp_config"), NULL, 10)));
        PCA_Init(&player3Actor, screen->w / 2 - 128, screen->h / 2 + 128, ts_rand(st, 32, 86), ts_rand(st, 64, 256), 2, 0, ts_rand(st, 4, 24), SPM_ColorRGB2(stoi(getvof("player3_color", "", "mp_config"), NULL, 10)));
    }
    else
    {
        PCA_Init(&player1Actor, screen->w / 2 - 128, screen->h / 2 - 128, 64, 128, 0, 0, 12, SPM_ColorRGB2(stoi(getvof("player1_color", "", "mp_config"), NULL, 10)));
        PCA_Init(&player2Actor, screen->w / 2 + 128, screen->h / 2 - 128, 64, 128, 1, 0, 12, SPM_ColorRGB2(stoi(getvof("player2_color", "", "mp_config"), NULL, 10)));
        PCA_Init(&player3Actor, screen->w / 2 - 128, screen->h / 2 + 128, 64, 128, 2, 0, 12, SPM_ColorRGB2(stoi(getvof("player3_color", "", "mp_config"), NULL, 10)));
    }

    if (playersNumber == 1)
    {
        player1Actor.A_Existence = 1;
        player2Actor.A_Existence = 0;
        player3Actor.A_Existence = 0;
    }
    else if (playersNumber == 2)
    {
        player1Actor.A_Existence = 1;
        player2Actor.A_Existence = 1;
        player3Actor.A_Existence = 0;
    }
    else if (playersNumber == 3)
    {
        player1Actor.A_Existence = 1;
        player2Actor.A_Existence = 1;
        player3Actor.A_Existence = 1;
    }

    if (getvof("mode", "", "mp_config") == "easy")
    {
        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Init(&computerActor[i], screen->w / 2 + 128, screen->h / 2 + 128, 8, 32, -1, 2, ts_rand(st, 4, 22), SPM_ColorRGB2(stoi(getvof("com_color", "", "mp_config"), NULL, 10)));
    }
    else if (getvof("mode", "", "mp_config") == "normal")
    {
        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Init(&computerActor[i], screen->w / 2 + 128, screen->h / 2 + 128, 16, 32, -1, 2, ts_rand(st, 4, 32), SPM_ColorRGB2(stoi(getvof("com_color", "", "mp_config"), NULL, 10)));
    }
    else if (getvof("mode", "", "mp_config") == "hard")
    {
        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Init(&computerActor[i], screen->w / 2 + 128, screen->h / 2 + 128, 48, 64, -1, 2, ts_rand(st, 4, 48), SPM_ColorRGB2(stoi(getvof("com_color", "", "mp_config"), NULL, 10)));
    }
    else if (getvof("mode", "", "mp_config") == "random")
    {
        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Init(&computerActor[i], screen->w / 2 + 128, screen->h / 2 + 128, ts_rand(st, 4, 64), ts_rand(st, 16, 128), -1, ts_rand(st, 1, 3), ts_rand(st, 2, 64), SPM_ColorRGB2(stoi(getvof("com_color", "", "mp_config"), NULL, 10)));
    }

    while (!quit)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                time(&p_quit_ht);
                p_quit = true;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                time(&p_quit_ht);
                p_quit = true;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_RETURN && p_quit == true) quit = true;
            if (event.type == SDL_KEYUP && event.key.keysym.scancode == SDL_SCANCODE_F1)
            {
                showVectors = !showVectors;
            }

            PCA_Event(&player1Actor, &event);
            PCA_Event(&player2Actor, &event);
            PCA_Event(&player3Actor, &event);
        }

        SDL_FillRect(screen, NULL, background_color);

        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Rend(&computerActor[i]);

        PCA_Loop(&player1Actor, screen);
        PCA_Loop(&player2Actor, screen);
        PCA_Loop(&player3Actor, screen);
        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Loop(&computerActor[i], screen);

        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Collision(&player1Actor, &computerActor[i]);

        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Collision(&player2Actor, &computerActor[i]);

        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Collision(&player3Actor, &computerActor[i]);

        PCA_Collision(&player1Actor, &player2Actor);
        PCA_Collision(&player2Actor, &player3Actor);
        PCA_Collision(&player3Actor, &player1Actor);

        int comActorsGlobalExistence = computerActorsAmount;
        for(int i = 0; i < computerActorsAmount; i++)
        {
            if(computerActor[i].A_Existence  == 1)
                break;
            else
                comActorsGlobalExistence--;
        }




        //SPM_TTF_BlendedText(screen, to_string(endGame), main_font, 4, 4, {255, 128, 0, 128});

        SDL_LockSurface(screen);

        PCA_Draw(&player1Actor, screen);
        PCA_Draw(&player2Actor, screen);
        PCA_Draw(&player3Actor, screen);
        for (int i = 0; i < computerActorsAmount; i++)
            PCA_Draw(&computerActor[i], screen);

        if (showVectors == 1)
        {
            if (player1Actor.A_Existence == 1)
            {
            SPM_Line(screen, player1Actor.A_X, player1Actor.A_Y, player1Actor.A_X + player1Actor.AV_Vector.PmX - player1Actor.AV_Vector.P1X, player1Actor.A_Y + player1Actor.AV_Vector.PmY - player1Actor.AV_Vector.P1Y, 0xff2200);
            SPM_Square(screen, player1Actor.A_X + player1Actor.AV_Vector.VCoX - 2, player1Actor.A_Y + player1Actor.AV_Vector.VCoY - 2, 4, 0xff2200);
            }
            if (player2Actor.A_Existence == 1)
            {
            SPM_Line(screen, player2Actor.A_X, player2Actor.A_Y, player2Actor.A_X + player2Actor.AV_Vector.PmX - player2Actor.AV_Vector.P1X, player2Actor.A_Y + player2Actor.AV_Vector.PmY - player2Actor.AV_Vector.P1Y, 0xff2200);
            SPM_Square(screen, player2Actor.A_X + player2Actor.AV_Vector.VCoX - 2, player2Actor.A_Y + player2Actor.AV_Vector.VCoY - 2, 4, 0xff2200);
            }
            if (player3Actor.A_Existence == 1)
            {
            SPM_Line(screen, player3Actor.A_X, player3Actor.A_Y, player3Actor.A_X + player3Actor.AV_Vector.PmX - player3Actor.AV_Vector.P1X, player3Actor.A_Y + player3Actor.AV_Vector.PmY - player3Actor.AV_Vector.P1Y, 0xff2200);
            SPM_Square(screen, player3Actor.A_X + player3Actor.AV_Vector.VCoX - 2, player3Actor.A_Y + player3Actor.AV_Vector.VCoY - 2, 4, 0xff2200);
            }
            for (int i = 0; i < computerActorsAmount; i++)
            {
                if (computerActor[i].A_Existence == 1)
                {
                SPM_Line(screen, computerActor[i].A_X, computerActor[i].A_Y, computerActor[i].A_X + computerActor[i].AV_Vector.PmX - computerActor[i].AV_Vector.P1X, computerActor[i].A_Y + computerActor[i].AV_Vector.PmY - computerActor[i].AV_Vector.P1Y, 0xff2200);
                SPM_Square(screen, computerActor[i].A_X + computerActor[i].AV_Vector.VCoX - 2, computerActor[i].A_Y + computerActor[i].AV_Vector.VCoY - 2, 4, 0xff2200);
                }
            }
        }

        SDL_UnlockSurface(screen);

        if (player1Actor.A_Existence == 0 && player2Actor.A_Existence == 0 && player3Actor.A_Existence == 0 && comActorsGlobalExistence > 0) //bots
        {
            SPM_TTF_BlendedText(screen, "bots won", main_font3, 16, 22, {255, 128, 0, 128});
            if (playersNumber == 1)
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
            else if (playersNumber == 2)
            {
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
            }
            else if (playersNumber == 3)
            {
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 3 score = " + to_string(player3Actor.A_R), main_font, 64, 168, {255, 128, 0, 128});
            }
            if (endGame == 1)
            {
                if (player1Actor.A_R > stof(getvof("player1_high_score", "", "mp_config"), NULL))
                {
                    setvof("player1_high_score", to_string(player1Actor.A_R), "", "mp_config");
                }
                if (player2Actor.A_R > stof(getvof("player2_high_score", "", "mp_config"), NULL))
                {
                    setvof("player2_high_score", to_string(player2Actor.A_R), "", "mp_config");
                }
                if (player3Actor.A_R > stof(getvof("player3_high_score", "", "mp_config"), NULL))
                {
                    setvof("player3_high_score", to_string(player3Actor.A_R), "", "mp_config");
                }
                endGame = 0;
            }
        }
        else if (player1Actor.A_Existence == 1 && player2Actor.A_Existence == 0 && player3Actor.A_Existence == 0 && comActorsGlobalExistence <= 0) //player1
        {
            SPM_TTF_BlendedText(screen, "player 1 won", main_font3, 16, 22, {255, 128, 0, 128});
            if (playersNumber == 1)
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
            else if (playersNumber == 2)
            {
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
            }
            else if (playersNumber == 3)
            {
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 3 score = " + to_string(player3Actor.A_R), main_font, 64, 168, {255, 128, 0, 128});
            }
            if (endGame == 1)
            {
                if (player1Actor.A_R > stof(getvof("player1_high_score", "", "mp_config"), NULL))
                {
                    setvof("player1_high_score", to_string(player1Actor.A_R), "", "mp_config");
                }
                if (player2Actor.A_R > stof(getvof("player2_high_score", "", "mp_config"), NULL))
                {
                    setvof("player2_high_score", to_string(player2Actor.A_R), "", "mp_config");
                }
                if (player3Actor.A_R > stof(getvof("player3_high_score", "", "mp_config"), NULL))
                {
                    setvof("player3_high_score", to_string(player3Actor.A_R), "", "mp_config");
                }
                endGame = 0;
            }
        }
        else if (player1Actor.A_Existence == 0 && player2Actor.A_Existence == 1 && player3Actor.A_Existence == 0 && comActorsGlobalExistence <= 0) //player2
        {
            SPM_TTF_BlendedText(screen, "player 2 won", main_font3, 16, 22, {255, 128, 0, 128});
            if (playersNumber == 2)
            {
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
            }
            else if (playersNumber == 3)
            {
                SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
                SPM_TTF_BlendedText(screen, "player 3 score = " + to_string(player3Actor.A_R), main_font, 64, 168, {255, 128, 0, 128});
            }
            if (endGame == 1)
            {
                if (player1Actor.A_R > stof(getvof("player1_high_score", "", "mp_config"), NULL))
                {
                    setvof("player1_high_score", to_string(player1Actor.A_R), "", "mp_config");
                }
                if (player2Actor.A_R > stof(getvof("player2_high_score", "", "mp_config"), NULL))
                {
                    setvof("player2_high_score", to_string(player2Actor.A_R), "", "mp_config");
                }
                if (player3Actor.A_R > stof(getvof("player3_high_score", "", "mp_config"), NULL))
                {
                    setvof("player3_high_score", to_string(player3Actor.A_R), "", "mp_config");
                }
                endGame = 0;
            }
        }
        else if (player1Actor.A_Existence == 0 && player2Actor.A_Existence == 0 && player3Actor.A_Existence == 1 && comActorsGlobalExistence <= 0) //player3
        {
            SPM_TTF_BlendedText(screen, "player 3 won", main_font3, 16, 22, {255, 128, 0, 128});
            SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
            SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
            SPM_TTF_BlendedText(screen, "player 3 score = " + to_string(player3Actor.A_R), main_font, 64, 168, {255, 128, 0, 128});
            if (endGame == 1)
            {
                if (player1Actor.A_R > stof(getvof("player1_high_score", "", "mp_config"), NULL))
                {
                    setvof("player1_high_score", to_string(player1Actor.A_R), "", "mp_config");
                }
                if (player2Actor.A_R > stof(getvof("player2_high_score", "", "mp_config"), NULL))
                {
                    setvof("player2_high_score", to_string(player2Actor.A_R), "", "mp_config");
                }
                if (player3Actor.A_R > stof(getvof("player3_high_score", "", "mp_config"), NULL))
                {
                    setvof("player3_high_score", to_string(player3Actor.A_R), "", "mp_config");
                }
                endGame = 0;
            }
        }
        else if (player1Actor.A_Existence == 0 && player2Actor.A_Existence == 0 && player3Actor.A_Existence == 0 && comActorsGlobalExistence <= 0)
        {
            SPM_TTF_BlendedText(screen, "error / score woun't be saved", main_font3, 16, 22, {255, 128, 0, 128});
            SPM_TTF_BlendedText(screen, "player 1 score = " + to_string(player1Actor.A_R), main_font, 64, 144, {255, 128, 0, 128});
            SPM_TTF_BlendedText(screen, "player 2 score = " + to_string(player2Actor.A_R), main_font, 64, 156, {255, 128, 0, 128});
            SPM_TTF_BlendedText(screen, "player 3 score = " + to_string(player3Actor.A_R), main_font, 64, 168, {255, 128, 0, 128});
        }

        if (p_quit == true)
        {
            SPM_TTF_BlendedText(screen, "press ENTER to quit " + to_string(4 - (time(NULL) - p_quit_ht)), main_font, 8, 8, {255, 128, 0, 128});
            if (time(NULL) - p_quit_ht > 4)
            {
                p_quit = false;
            }
        }


        SDL_UpdateWindowSurface(window);
    }
    SDL_ShowCursor(SDL_ENABLE);
}
