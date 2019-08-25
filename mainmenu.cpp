#include <af.h>
#include <pf.h>

void mf_mainmanu()
{
    int high_score[3];
    SDL_Surface *staticPictures[4];
    SDL_Rect staticPictures_rects[4];
    SDL_Surface *dynamicPictures[1];
    SDL_Rect dynamicPictures_rects[6];

    SBI_fullS_Button button[29];

    menuback_color = SPM_ColorRGB2(stoi(getvof("menuback_color", "", "mp_config"), NULL, 10));

    //--
    /*
    setvof("player1_color", "034255128", "", "mp_config");
    setvof("player2_color", "255034000", "", "mp_config");
    setvof("player3_color", "034034170", "", "mp_config");
    setvof("com_color", "128128128", "", "mp_config");
    setvof("menuback_color", "128128128", "", "mp_config");
    setvof("background_color", "024024024", "", "mp_config");
    */
    //--
    high_score[0] = stoi(getvof("player1_high_score", "", "mp_config"), NULL, 10);
    high_score[1] = stoi(getvof("player2_high_score", "", "mp_config"), NULL, 10);
    high_score[2] = stoi(getvof("player3_high_score", "", "mp_config"), NULL, 10);

    staticPictures[0] = IMG_Load("Data/Textures/static_surface_tipe3.png");
    staticPictures[1] = IMG_Load("Data/Textures/static_surface_tipe4.png");
    staticPictures[2] = IMG_Load("Data/Textures/static_surface_tipe5.png");
    staticPictures[3] = IMG_Load("Data/Textures/static_surface_tipe6.png");

    dynamicPictures[0] = IMG_Load("Data/Textures/dynamic_surface_tipe1.png");

    staticPictures_rects[0].x = screen->w - 344;
    staticPictures_rects[0].y = screen->h - 50;

    staticPictures_rects[1].x = 16;
    staticPictures_rects[1].y = screen->h - 96;

    staticPictures_rects[2].x = 0;
    staticPictures_rects[2].y = 0;

    staticPictures_rects[3].x = screen->w - 344;
    staticPictures_rects[3].y = 64;



    selectButton[0] = stoi(getvof("player1_skin", "", "mp_config"), NULL, 10);
    selectButton[1] = stoi(getvof("player2_skin", "", "mp_config"), NULL, 10);
    selectButton[2] = stoi(getvof("player3_skin", "", "mp_config"), NULL, 10);

    if (getvof("window_width", "", "mp_config") == "640") selectButton[5] = 1;
    else if (getvof("window_width", "", "mp_config") == "800") selectButton[5] = 2;
    else if (getvof("window_width", "", "mp_config") == "1280") selectButton[5] = 3;
    else if (getvof("window_width", "", "mp_config") == "1360") selectButton[5] = 4;
    else if (getvof("window_width", "", "mp_config") == "1920") selectButton[5] = 5;

    if (getvof("mode", "", "mp_config") == "easy") selectButton[3] = 1;
    else if (getvof("mode", "", "mp_config") == "normal") selectButton[3] = 2;
    else if (getvof("mode", "", "mp_config") == "hard") selectButton[3] = 3;
    else if (getvof("mode", "", "mp_config") == "random") selectButton[3] = 4;

    if (getvof("bots_amount", "", "mp_config") == "16") selectButton[4] = 1;
    else if (getvof("bots_amount", "", "mp_config") == "48") selectButton[4] = 2;
    else if (getvof("bots_amount", "", "mp_config") == "128") selectButton[4] = 3;

    //easy mormal hard random mode

    SBI_F_InitButton(&button[0], screen->w - 144, screen->h - 48, "Data/Textures/", "default_button_tipe1.png", "mor_button_tipe1.png", "push_button_tipe1.png");
    SBI_F_InitButton(&button[1], 16, 64, "Data/Textures/", "default_button_tipe1.png", "mor_button_tipe1.png", "push_button_tipe1.png");
    SBI_F_InitButton(&button[2], 16, 64 + 36, "Data/Textures/", "default_button_tipe1.png", "mor_button_tipe1.png", "push_button_tipe1.png");
    SBI_F_InitButton(&button[3], 16, 64 + 36 + 36, "Data/Textures/", "default_button_tipe1.png", "mor_button_tipe1.png", "push_button_tipe1.png");

    SBI_F_InitButton(&button[4], screen->w - 338, screen->h - 44, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[5], screen->w - 304, screen->h - 44, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[6], screen->w - 270, screen->h - 44, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[7], screen->w - 236, screen->h - 44, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[8], screen->w - 202, screen->h - 44, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");

    SBI_F_InitButton(&button[9], screen->w - 142, 90, "Data/Textures/", "default_button_tipe2.png", "mor_button_tipe2.png", "push_button_tipe2.png");
    SBI_F_InitButton(&button[10], screen->w - 142, 90 + 68, "Data/Textures/", "default_button_tipe2.png", "mor_button_tipe2.png", "push_button_tipe2.png");
    SBI_F_InitButton(&button[11], screen->w - 142, 90 + 68 + 68, "Data/Textures/", "default_button_tipe2.png", "mor_button_tipe2.png", "push_button_tipe2.png");
    SBI_F_InitButton(&button[12], screen->w - 142, 90 + 68 + 68 + 68, "Data/Textures/", "default_button_tipe2.png", "mor_button_tipe2.png", "push_button_tipe2.png");
    SBI_F_InitButton(&button[13], screen->w - 216, 90, "Data/Textures/", "default_button_tipe3.png", "mor_button_tipe3.png", "push_button_tipe3.png");
    SBI_F_InitButton(&button[14], screen->w - 216, 90 + 68, "Data/Textures/", "default_button_tipe3.png", "mor_button_tipe3.png", "push_button_tipe3.png");
    SBI_F_InitButton(&button[15], screen->w - 216, 90 + 68 + 68, "Data/Textures/", "default_button_tipe3.png", "mor_button_tipe3.png", "push_button_tipe3.png");

    SBI_F_InitButton(&button[16], screen->w - 326, 102, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[17], screen->w - 326 + 36, 102, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[18], screen->w - 326, 102 + 36, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[19], screen->w - 326 + 36, 102 + 36, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[20], screen->w - 326, 186, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[21], screen->w - 326 + 36, 186, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[22], screen->w - 326, 186 + 36, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[23], screen->w - 326 + 36, 186 + 36, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[24], screen->w - 326, 270, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[25], screen->w - 326 + 36, 270, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[26], screen->w - 326, 270 + 36, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");
    SBI_F_InitButton(&button[27], screen->w - 326 + 36, 270 + 36, "Data/Textures/", "default_button_tipe4.png", "mor_button_tipe4.png", "push_button_tipe4.png");

    SBI_F_InitButton(&button[28], 16, 64 + 36 + 36 + 70, "Data/Textures/", "default_button_tipe1.png", "mor_button_tipe1.png", "push_button_tipe1.png");

    SDL_ShowCursor(SDL_ENABLE);

    bool fullscreen = false;
    if(getvof("fullscreen", "", "mp_config") == "true") fullscreen = true;
    else fullscreen = false;
    while (!mainQuit)
    {
        SDL_Event event;
        if (SDL_WaitEventTimeout(&event, 100))
        {
            if (event.type == SDL_QUIT)
                mainQuit = true;

            SBI_F_ButtonEvent(&button[0], event);
            SBI_F_ButtonEvent(&button[1], event);
            SBI_F_ButtonEvent(&button[2], event);
            SBI_F_ButtonEvent(&button[3], event);

            SBI_F_ButtonEvent(&button[4], event);
            SBI_F_ButtonEvent(&button[5], event);
            SBI_F_ButtonEvent(&button[6], event);
            SBI_F_ButtonEvent(&button[7], event);
            SBI_F_ButtonEvent(&button[8], event);

            SBI_F_ButtonEvent(&button[9], event);
            SBI_F_ButtonEvent(&button[10], event);
            SBI_F_ButtonEvent(&button[11], event);
            SBI_F_ButtonEvent(&button[12], event);
            SBI_F_ButtonEvent(&button[13], event);
            SBI_F_ButtonEvent(&button[14], event);
            SBI_F_ButtonEvent(&button[15], event);

            SBI_F_ButtonEvent(&button[16], event);
            SBI_F_ButtonEvent(&button[17], event);
            SBI_F_ButtonEvent(&button[18], event);
            SBI_F_ButtonEvent(&button[19], event);
            SBI_F_ButtonEvent(&button[20], event);
            SBI_F_ButtonEvent(&button[21], event);
            SBI_F_ButtonEvent(&button[22], event);
            SBI_F_ButtonEvent(&button[23], event);
            SBI_F_ButtonEvent(&button[24], event);
            SBI_F_ButtonEvent(&button[25], event);
            SBI_F_ButtonEvent(&button[26], event);
            SBI_F_ButtonEvent(&button[27], event);

            SBI_F_ButtonEvent(&button[28], event);
        }

        SDL_FillRect(screen, NULL, menuback_color);

        if (selectButton[0]  == 1) {dynamicPictures_rects[0].x = 1 + screen->w - 326; dynamicPictures_rects[0].y = 1 + 102;}
        else if (selectButton[0]  == 2) {dynamicPictures_rects[0].x = 1 + screen->w - 326 + 36; dynamicPictures_rects[0].y = 1 + 102;}
        else if (selectButton[0]  == 3) {dynamicPictures_rects[0].x = 1 + screen->w - 326; dynamicPictures_rects[0].y = 1 + 102 + 36;}
        else if (selectButton[0]  == 4) {dynamicPictures_rects[0].x = 1 + screen->w - 326 + 36; dynamicPictures_rects[0].y = 1 + 102 + 36;}

        if (selectButton[1]  == 1) {dynamicPictures_rects[1].x = 1 + screen->w - 326; dynamicPictures_rects[1].y = 1 + 186;}
        else if (selectButton[1]  == 2) {dynamicPictures_rects[1].x = 1 + screen->w - 326 + 36; dynamicPictures_rects[1].y = 1 + 186;}
        else if (selectButton[1]  == 3) {dynamicPictures_rects[1].x = 1 + screen->w - 326; dynamicPictures_rects[1].y = 1 + 186 + 36;}
        else if (selectButton[1]  == 4) {dynamicPictures_rects[1].x = 1 + screen->w - 326 + 36; dynamicPictures_rects[1].y = 1 + 186 + 36;}

        if (selectButton[2]  == 1) {dynamicPictures_rects[2].x = 1 + screen->w - 326; dynamicPictures_rects[2].y = 1 + 270;}
        else if (selectButton[2]  == 2) {dynamicPictures_rects[2].x = 1 + screen->w - 326 + 36; dynamicPictures_rects[2].y = 1 + 270;}
        else if (selectButton[2]  == 3) {dynamicPictures_rects[2].x = 1 + screen->w - 326; dynamicPictures_rects[2].y = 1 + 270 + 36;}
        else if (selectButton[2]  == 4) {dynamicPictures_rects[2].x = 1 + screen->w - 326 + 36; dynamicPictures_rects[2].y = 1 + 270 + 36;}

        if (selectButton[3]  == 1) {dynamicPictures_rects[3].x = 1 + screen->w - 142; dynamicPictures_rects[3].y = 1 + 90;}
        else if (selectButton[3]  == 2) {dynamicPictures_rects[3].x = 1 + screen->w - 142; dynamicPictures_rects[3].y = 1 + 90 + 68;}
        else if (selectButton[3]  == 3) {dynamicPictures_rects[3].x = 1 + screen->w - 142; dynamicPictures_rects[3].y = 1 + 90 + 68 + 68;}
        else if (selectButton[3]  == 4) {dynamicPictures_rects[3].x = 1 + screen->w - 142; dynamicPictures_rects[3].y = 1 + 90 + 68 + 68 + 68;}

        if (selectButton[4]  == 1) {dynamicPictures_rects[4].x = 1 + screen->w - 216; dynamicPictures_rects[4].y = 1 + 90;}
        else if (selectButton[4]  == 2) {dynamicPictures_rects[4].x = 1 + screen->w - 216; dynamicPictures_rects[4].y = 1 + 90 + 68;}
        else if (selectButton[4]  == 3) {dynamicPictures_rects[4].x = 1 + screen->w - 216; dynamicPictures_rects[4].y = 1 + 90 + 68 + 68;}

        if (selectButton[5]  == 1) {dynamicPictures_rects[5].x = 1 + screen->w - 338; dynamicPictures_rects[5].y = 1 + screen->h - 44;}
        else if (selectButton[5]  == 2) {dynamicPictures_rects[5].x = 1 + screen->w - 338 + 34; dynamicPictures_rects[5].y = 1 + screen->h - 44;}
        else if (selectButton[5]  == 3) {dynamicPictures_rects[5].x = 1 + screen->w - 338 + 34 + 34; dynamicPictures_rects[5].y = 1 + screen->h - 44;}
        else if (selectButton[5]  == 4) {dynamicPictures_rects[5].x = 1 + screen->w - 338 + 34 + 34 + 34; dynamicPictures_rects[5].y = 1 + screen->h - 44;}
        else if (selectButton[5]  == 5) {dynamicPictures_rects[5].x = 1 + screen->w - 338 + 34 + 34 + 34 + 34; dynamicPictures_rects[5].y = 1 + screen->h - 44;}

        // else SDL functions ---- //

        SDL_BlitSurface(staticPictures[0], NULL, screen, &staticPictures_rects[0]);
        SDL_BlitSurface(staticPictures[1], NULL, screen, &staticPictures_rects[1]);
        SDL_BlitSurface(staticPictures[2], NULL, screen, &staticPictures_rects[2]);
        SDL_BlitSurface(staticPictures[3], NULL, screen, &staticPictures_rects[3]);


        SBI_F_ButtonAnim(&button[0], screen);
        SBI_F_ButtonAnim(&button[1], screen);
        SBI_F_ButtonAnim(&button[2], screen);
        SBI_F_ButtonAnim(&button[3], screen);

        SBI_F_ButtonAnim(&button[4], screen);
        SBI_F_ButtonAnim(&button[5], screen);
        SBI_F_ButtonAnim(&button[6], screen);
        SBI_F_ButtonAnim(&button[7], screen);
        SBI_F_ButtonAnim(&button[8], screen);

        SBI_F_ButtonAnim(&button[9], screen);
        SBI_F_ButtonAnim(&button[10], screen);
        SBI_F_ButtonAnim(&button[11], screen);
        SBI_F_ButtonAnim(&button[12], screen);
        SBI_F_ButtonAnim(&button[13], screen);
        SBI_F_ButtonAnim(&button[14], screen);
        SBI_F_ButtonAnim(&button[15], screen);

        SBI_F_ButtonAnim(&button[16], screen);
        SBI_F_ButtonAnim(&button[17], screen);
        SBI_F_ButtonAnim(&button[18], screen);
        SBI_F_ButtonAnim(&button[19], screen);
        SBI_F_ButtonAnim(&button[20], screen);
        SBI_F_ButtonAnim(&button[21], screen);
        SBI_F_ButtonAnim(&button[22], screen);
        SBI_F_ButtonAnim(&button[23], screen);
        SBI_F_ButtonAnim(&button[24], screen);
        SBI_F_ButtonAnim(&button[25], screen);
        SBI_F_ButtonAnim(&button[26], screen);
        SBI_F_ButtonAnim(&button[27], screen);

        SBI_F_ButtonAnim(&button[28], screen);

        SDL_BlitSurface(dynamicPictures[0], NULL, screen, &dynamicPictures_rects[0]);
        SDL_BlitSurface(dynamicPictures[0], NULL, screen, &dynamicPictures_rects[1]);
        SDL_BlitSurface(dynamicPictures[0], NULL, screen, &dynamicPictures_rects[2]);
        SDL_BlitSurface(dynamicPictures[0], NULL, screen, &dynamicPictures_rects[3]);
        SDL_BlitSurface(dynamicPictures[0], NULL, screen, &dynamicPictures_rects[4]);
        SDL_BlitSurface(dynamicPictures[0], NULL, screen, &dynamicPictures_rects[5]);


        SPM_TTF_BlendedText(screen, "fullscreen " + bts(fullscreen), main_font, screen->w - 122, screen->h - 40, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "resolution", main_font, screen->w - 286, screen->h - 66, {20, 20, 20, 20});

        SPM_TTF_BlendedText(screen, "640 x      800 x     1280 x   1360 x    1920 x", main_font2, screen->w - 334, screen->h - 34, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "480          600         720         768         1080", main_font2, screen->w - 334, screen->h - 24, {20, 20, 20, 20});

        SPM_TTF_BlendedText(screen, "1 Player", main_font, 56, 74, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "2 Players", main_font, 56, 74 + 36, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "3 Players", main_font, 56, 74 + 36 + 36, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "Exit", main_font, 68, 74 + 36 + 36 + 70, {20, 20, 20, 20});

        SPM_TTF_BlendedText(screen, "16             Easy - low velocity", main_font, screen->w - 192, 112, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "48             Normal - middle of", main_font, screen->w - 192, 112 + 68, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "128           Hard - high velocity", main_font, screen->w - 192, 112 + 68 + 68, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "                  Random - random", main_font, screen->w - 192, 112 + 68 + 68 + 68, {20, 20, 20, 20});

        SPM_TTF_BlendedText(screen, "and power of bots", main_font, screen->w - 132, 132, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "velocity and power", main_font, screen->w - 132, 132 + 68, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "and power of bots", main_font, screen->w - 132, 132 + 68 + 68, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, "all of values", main_font, screen->w - 132, 132 + 68 + 68 + 68, {20, 20, 20, 20});

        SPM_TTF_BlendedText(screen, to_string(high_score[0]), main_font, 18, screen->h - 60, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, to_string(high_score[1]), main_font, 80, screen->h - 60, {20, 20, 20, 20});
        SPM_TTF_BlendedText(screen, to_string(high_score[2]), main_font, 138, screen->h - 60, {20, 20, 20, 20});

        if(button[0].signal == true)
        {
            fullscreen = !fullscreen;
            if (fullscreen == true)
            {
                setvof("fullscreen", "true", "", "mp_config");
            }
            else
            {
                setvof("fullscreen", "false", "", "mp_config");
            }
        }
        if(button[1].signal == true)
        {
            playersNumber = 1;
            mf_mainloop();
        }
        if(button[2].signal == true)
        {
            playersNumber = 2;
            mf_mainloop();
        }
        if(button[3].signal == true)
        {
            playersNumber = 3;
            mf_mainloop();
        }

        if (button[4].signal == true)
        {
            setvof("window_width", "640", "", "mp_config");
            setvof("window_height", "480", "", "mp_config");
            selectButton[5] = 1;
        }
        else if (button[5].signal == true)
        {
            setvof("window_width", "800", "", "mp_config");
            setvof("window_height", "600", "", "mp_config");
            selectButton[5] = 2;
        }
        else if (button[6].signal == true)
        {
            setvof("window_width", "1280", "", "mp_config");
            setvof("window_height", "720", "", "mp_config");
            selectButton[5] = 3;
        }
        else if (button[7].signal == true)
        {
            setvof("window_width", "1360", "", "mp_config");
            setvof("window_height", "768", "", "mp_config");
            selectButton[5] = 4;
        }
        else if (button[8].signal == true)
        {
            setvof("window_width", "1920", "", "mp_config");
            setvof("window_height", "1080", "", "mp_config");
            selectButton[5] = 5;
        }
        else if (button[9].signal == true)
        {
            setvof("mode", "easy", "", "mp_config");
            selectButton[3] = 1;
        }
        else if (button[10].signal == true)
        {
            setvof("mode", "normal", "", "mp_config");
            selectButton[3] = 2;
        }
        else if (button[11].signal == true)
        {
            setvof("mode", "hard", "", "mp_config");
            selectButton[3] = 3;
        }
        else if (button[12].signal == true)
        {
            setvof("mode", "random", "", "mp_config");
            selectButton[3] = 4;
        }
        else if (button[13].signal == true)
        {
            setvof("bots_amount", "16", "", "mp_config");
            selectButton[4] = 1;
        }
        else if (button[14].signal == true)
        {
            setvof("bots_amount", "48", "", "mp_config");
            selectButton[4] = 2;
        }
        else if (button[15].signal == true)
        {
            setvof("bots_amount", "128", "", "mp_config");
            selectButton[4] = 3;
        }
        else if (button[16].signal == true)
        {
            setvof("player1_skin", "1", "", "mp_config");
            selectButton[0] = 1;
        }
        else if (button[17].signal == true)
        {
            setvof("player1_skin", "2", "", "mp_config");
            selectButton[0] = 2;
        }
        else if (button[18].signal == true)
        {
            setvof("player1_skin", "3", "", "mp_config");
            selectButton[0] = 3;
        }
        else if (button[19].signal == true)
        {
            setvof("player1_skin", "4", "", "mp_config");
            selectButton[0] = 4;
        }
        else if (button[20].signal == true)
        {
            setvof("player2_skin", "1", "", "mp_config");
            selectButton[1] = 1;
        }
        else if (button[21].signal == true)
        {
            setvof("player2_skin", "2", "", "mp_config");
            selectButton[1] = 2;
        }
        else if (button[22].signal == true)
        {
            setvof("player2_skin", "3", "", "mp_config");
            selectButton[1] = 3;
        }
        else if (button[23].signal == true)
        {
            setvof("player2_skin", "4", "", "mp_config");
            selectButton[1] = 4;
        }
        else if (button[24].signal == true)
        {
            setvof("player3_skin", "1", "", "mp_config");
            selectButton[2] = 1;
        }
        else if (button[25].signal == true)
        {
            setvof("player3_skin", "2", "", "mp_config");
            selectButton[2] = 2;
        }
        else if (button[26].signal == true)
        {
            setvof("player3_skin", "3", "", "mp_config");
            selectButton[2] = 3;
        }
        else if (button[27].signal == true)
        {
            setvof("player3_skin", "4", "", "mp_config");
            selectButton[2] = 4;
        }
        if(button[28].signal == true)
        {
            mainQuit = true;
        }
        // ---- //

        button[0].signal = false;
        button[1].signal = false;
        button[2].signal = false;
        button[3].signal = false;

        button[4].signal = false;
        button[5].signal = false;
        button[6].signal = false;
        button[7].signal = false;
        button[8].signal = false;

        button[9].signal = false;
        button[10].signal = false;
        button[11].signal = false;
        button[12].signal = false;
        button[13].signal = false;
        button[14].signal = false;
        button[15].signal = false;

        button[16].signal = false;
        button[17].signal = false;
        button[18].signal = false;
        button[19].signal = false;
        button[20].signal = false;
        button[21].signal = false;
        button[22].signal = false;
        button[23].signal = false;
        button[24].signal = false;
        button[25].signal = false;
        button[26].signal = false;
        button[27].signal = false;

        button[28].signal = false;

        SDL_UpdateWindowSurface(window);
    }
    for(int i = 0; i < 4; i++)
    {
        SDL_FreeSurface(staticPictures[i]);
    }
    SDL_FreeSurface(dynamicPictures[0]);
}
