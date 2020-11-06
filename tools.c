#include "wolf3d.h"

int   init_window(wolf_t *wolf)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Initialisation error\n");
        return (FALSE);
    }
    wolf->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!wolf->window)
    {
        printf("Error creating window\n");
        return (FALSE);
    }
    wolf->renderer = SDL_CreateRenderer(wolf->window, -1, 0);
    if (!wolf->renderer)
    {
        printf("Error creating renderer\n");
        return (FALSE);
    }
    return (TRUE);
}

void    destroy_window(wolf_t *wolf)
{
    //free(wolf->walltex);
    free (wolf->colorbuffer);
    SDL_DestroyRenderer(wolf->renderer);
    SDL_DestroyWindow(wolf->window);
    SDL_Quit();
}

float   normalizeangle(float angle)
{
    angle = remainder(angle, TWO_PI);
    if (angle < 0)
    {
        angle = TWO_PI + angle;
    }
    return (angle);
}

float   distancecalc(float x1, float y1, float x2, float y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void    tex(wolf_t *wolf)
{
    if (wolf->pngTex != NULL)
    {
        upng_decode(wolf->pngTex);
        if (upng_get_error(wolf->pngTex) == UPNG_EOK)
            wolf->walltex = (int *)upng_get_buffer(wolf->pngTex);
        
    }
}

void    imgs(wolf_t *wolf)
{
    wolf->pics = (char **)malloc(sizeof(char *) * 9);
    wolf->pics[0] = ft_strdup("./pics/wood.png");
    wolf->pics[1] = ft_strdup("./pics/colorstone.png");
    wolf->pics[2] = ft_strdup("./pics/eagle.png");
    wolf->pics[3] = ft_strdup("./pics/bluestone.png");
    wolf->pics[4] = ft_strdup("./pics/graystone.png");
    wolf->pics[5] = ft_strdup("./pics/mossystone.png");
    wolf->pics[6] = ft_strdup("./pics/purplestone.png");
    wolf->pics[7] = ft_strdup("./pics/redbrick.png");
    wolf->pics[8] = ft_strdup("./pics/brick.png");
}

void    tex2(wolf_t *wolf, player_t *p)
{
    (void)p;
    wolf->walltex = (int *) malloc(sizeof(int) * tex_w * tex_h);
    wolf->surface = IMG_Load(wolf->pics[0]);
    wolf->walltex = (int*)wolf->surface->pixels;
    
    wolf->walltex1= (int *) malloc(sizeof(int) * tex_w * tex_h);
    wolf->surface = IMG_Load(wolf->pics[1]);
    wolf->walltex1 = (int*)wolf->surface->pixels;

    wolf->walltex2 = (int *) malloc(sizeof(int) * tex_w * tex_h);
    wolf->surface = IMG_Load(wolf->pics[2]);
    wolf->walltex2 = (int*)wolf->surface->pixels;

    wolf->walltex3 = (int *) malloc(sizeof(int) * tex_w * tex_h);
    wolf->surface = IMG_Load(wolf->pics[3]);
    wolf->walltex3 = (int*)wolf->surface->pixels;

    wolf->walltex4 = (int *) malloc(sizeof(int) * tex_w * tex_h);
    wolf->surface = IMG_Load(wolf->pics[5]);
    wolf->walltex4 = (int*)wolf->surface->pixels;
}

void    gun(wolf_t *wolf, player_t *p)
{
    SDL_Rect rect;
    SDL_Rect rectpos;

    rect.x = 0;
    rect.y = 0;
    rect.h = 100;
    rect.w = 500 / 5;

    rectpos.x = 100;
    rectpos.y = 100;
    rectpos.h = 100;
    rectpos.w = 500 / 5;


            wolf->surface = IMG_Load(wolf->pics[8]);
            p->colorbuffertexture = SDL_CreateTextureFromSurface(wolf->renderer, wolf->surface);
            //SDL_RenderCopy(wolf->renderer, p->colorbuffertexture, &rect, &rectpos);
           // SDL_RenderPresent(wolf->renderer);

}