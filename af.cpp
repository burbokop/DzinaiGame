#include <af.h>
#include <pf.h>

std::string bts(bool val)
{
  return val ? "true" : "false";
}

int set_step(int coordinate, int step)
{
    return coordinate / step * step;
}

//SBI Functions ---->>

int SBI_N_InitButton(SBI_nonS_Button *button, int x1, int y1, int x2, int y2)
{
    button->x = x1;
    button->y = y1;
    button->w = x2 - x1;
    button->h = y2 - y1;
    button->mor = false;
    button->push = false;
    button->existance = true;
    return 0;
}

int SBI_H_InitButton(SBI_halfS_Button *button, int x, int y, std::string image_path)
{
    button->x = x;
    button->y = y;
    button->surface = IMG_Load(image_path.c_str());
    button->mor = false;
    button->push = false;
    button->existance = true;
    return 0;
}

int SBI_F_InitButton(SBI_fullS_Button *button, int x, int y, std::string images_path, std::string default_image, std::string mor_image, std::string push_image)
{
    button->x = x;
    button->y = y;
    button->default_surface = IMG_Load((images_path + default_image).c_str());
    button->mor_surface = IMG_Load((images_path + mor_image).c_str());
    button->push_surface = IMG_Load((images_path + push_image).c_str());
    button->mor = false;
    button->push = false;
    button->signal = false;
    button->pwmor = false;
    button->existance = true;
    return 0;
}

int SBI_N_ButtonEvent(SBI_nonS_Button *button, SDL_Event event)
{
    if (button->existance == true)
    {
        if (event.motion.x >= button->x && event.motion.x <= button->x + button->w && event.motion.y >= button->y && event.motion.y <= button->y + button->h)
        {
            button->mor = true;
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                button->push = true;
            }
            else if (event.type == SDL_MOUSEBUTTONUP) button->push = false;
        }
        else {button->mor = false; button->push = false;}
        return 0;
    }
    else return -1;
}

int SBI_H_ButtonEvent(SBI_halfS_Button *button, SDL_Event event)
{
    if (button->existance == true)
    {
        if (event.motion.x >= button->x && event.motion.x <= button->x + button->surface->w && event.motion.y >= button->y && event.motion.y <= button->y + button->surface->h)
        {
            button->mor = true;
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                button->push = true;
            }
            else if (event.type == SDL_MOUSEBUTTONUP) button->push = false;
        }
        else {button->mor = false; button->push = false;}
        return 0;
    }
    else return -1;
}

int SBI_F_ButtonEvent(SBI_fullS_Button *button, SDL_Event event)
{
    if (button->existance == true)
    {
        if (event.motion.x >= button->x && event.motion.x <= button->x + button->default_surface->w && event.motion.y >= button->y && event.motion.y <= button->y + button->default_surface->h)
        {
            button->mor = true;
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                button->push = true;
                button->pwmor = true;
            }
            else if (event.type == SDL_MOUSEBUTTONUP) {button->push = false; button->signal = true;}
        }
        else {button->mor = false; button->push = false;}
        if (event.type == SDL_MOUSEBUTTONUP) button->pwmor = false;
        return 0;
    }
    else return -1;
}

int SBI_H_ButtonImage(SBI_halfS_Button *button, SDL_Surface *surface)
{
    if (button->existance == true)
    {
        SDL_Rect rect;
        rect.x = button->x;
        rect.y = button->y;
        SDL_BlitSurface(button->surface, NULL, surface, &rect);
        return 0;
    }
    else return -1;
}

int SBI_F_ButtonAnim(SBI_fullS_Button *button, SDL_Surface *surface)
{
    if (button->existance == true)
    {
        SDL_Rect rect;
        rect.x = button->x;
        rect.y = button->y;
        if (button->push == false && button->pwmor == false && button->mor == false) SDL_BlitSurface(button->default_surface, NULL, surface, &rect);
        else if (button->push == false && button->pwmor == false && button->mor == true) SDL_BlitSurface(button->mor_surface, NULL, surface, &rect);
        else if ((button->push == true || button->pwmor == true) && button->mor == true) SDL_BlitSurface(button->push_surface, NULL, surface, &rect);
        return 0;
    }
    else return -1;
}

//SBI Functions ----<<

void GAME_Init(GAME *game)
{
    game->level = 0;
    game->score = 0;
    game->lose = false;
    game->pause = false;
    game->win = false;
    game->quit = false;
    game->mouse.x = 0;
    game->mouse.y = 0;
    game->a = 0;
}

bool logic(GAME *game, SBI_fullS_Button *button)
{
    if (game->a == 1) game->a = -1;
    else
    {
    if (button->push == true)
    {
        if (game->a == 0) game->a = 1;
    }
    }
    if (button->push == 0) game->a = 0;
    return game->a;
}

void GAME_MousOverRect(int x1, int y1, int x2, int y2, GAME *game, int event)
{
    if (game->mouse.x >= x1 && game->mouse.x <= x2 && game->mouse.y >= y1 && game->mouse.y <= y2)
    {
        game->events[event] = true;
    }
    else game->events[event] = false;
}

void EL_AddElement(EL *el, std::string label, std::string text, int icon)
{
    for(int i = 0; i < 256; i++)
    {
        if (el[i].existance == 0)
        {
            el[i].existance = 1;
            el[i].label = label;
            el[i].text = text;
            el[i].icon = icon;
            break;
        }
    }
}


int ts_rand(time_t time_seed, int min_val, int max_val)
{
    int rand32  = rand() + time_seed;
    if (rand32 > 0)
        return ((rand32 % (max_val - min_val)) + min_val);
    else if (rand32 < 0)
        return (((-rand32) % (max_val - min_val)) + min_val);
}

/*
int SPM_TTF_BlendedText(SDL_Surface *surface, std::string text_line, TTF_Font *text_font, int text_x, int text_y, SDL_Color text_color)
{
    SDL_Surface *text_surface = NULL;
    SDL_Rect text_rect;
    text_surface = TTF_RenderText_Blended(text_font, text_line.c_str(), text_color);
    text_rect.x = text_x;
    text_rect.y = text_y;
    SDL_BlitSurface(text_surface, NULL, surface, &text_rect);
    SDL_FreeSurface(text_surface);
    return 0;
}
*/
std::string getvof(std::string id, std::string filepath, std::string filename)
{
    filepath = filepath + filename + ".vof";
    const char *path = filepath.c_str();
    ifstream fin;
    fin.open(path, ios::in);
    if (fin.is_open() == false) return "#{nf}#";
    else
    {
        while(true)
        {
            string n_line, v_line;
            char itext[256];
            fin.getline(itext, 256);
            v_line = strchr(itext, '(');
            n_line = strtok(itext, " (");
            if (n_line == id)
            {
                v_line.erase(0, 1);
                return v_line;
                break;
            }
            else if(fin.eof() == true)
            {
                return "#{ni}#";
                break;
            }
        }
    }
    fin.close();
}


void setvof(std::string id, std::string value, std::string filepath, std::string filename)
{
    filepath = filepath + filename + ".vof";
    const char *path = filepath.c_str();
    bool action = false;
    int i = 0;
    ifstream fin;
    ofstream fout;
    string temp[128];
    fin.open(path, ios::in);
    if (fin.is_open() == false)
    {
        fout.open(path, ios::out);
        fout << "filetype (.vof\n";
        fout << id << " (" << value;
        fout.close();
    }
    else
    {
        while(!fin.eof())
        {
            string n_line, v_line;
            char itext[256];
            fin.getline(itext, 256);
            v_line = strchr(itext, '(');
            n_line = strtok(itext, " (");
            if (n_line == id)
            {
                action = true;
                temp[i] = n_line + " (" + value;
            }
            else temp[i] = n_line + " " + v_line;
            i++;
        }
        fin.close();
        if (action == false)
        {
            fout.open(path, ios::app);
            fout << "\n" << id + " (" + value;
            fout.close();
        }
        else
        {
            fout.open(path, ios::out);
            for(int j = 0; j < i; j++)
            {
                if (j == i - 1) fout << temp[j];
                else fout << temp[j] << "\n";
            }
            fout.close();
        }
    }
}
