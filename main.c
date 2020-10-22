#include "wolf3d.h"

void    init_wolf(wolf_t *wolf)
{
    wolf->window = NULL;
    wolf->renderer = NULL;
    wolf->loop = 0;
    wolf->tickslastframe = 0;
    wolf->colorbuffer =  (uint32_t*)malloc(sizeof(uint32_t) * (uint32_t)WIDTH * (uint32_t)HEIGHT);
    //wolf->colorbuffertexture = SDL_CreateTexture(wolf->renderer, SDL_PIXELFORMAT_ABGR8888,
      //                              SDL_TEXTUREACCESS_STREAMING ,WIDTH, HEIGHT );
    wolf->walltex = (uint32_t*) malloc(sizeof(uint32_t) * (uint32_t) tex_w * (uint32_t) tex_h);
}

void    init_player(player_t *player, wolf_t *wolf)
{
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    player->width = 2;
    player->height = 2;
    player->turndirection = 0;
    player->walkdirection = 0;
    player->rotatangle = PI;
    player->walkspeed = 100;
    player->turnspeed = 70 * (PI / 180);
    player->colorbuffertexture = SDL_CreateTexture(wolf->renderer, SDL_PIXELFORMAT_RGBA32,
                                    SDL_TEXTUREACCESS_STREAMING ,WIDTH, HEIGHT );
    
}

void    init_tab(ray_t *rays)//[NUM_RAY])
{
    int j = 0;
    while (j < NUM_RAY)
    {
        rays[j].distance = 0;
        rays[j].hitver = 0;
        rays[j].rayangle = 0;
        rays[j].raydown = 0;
        rays[j].rayleft = 0;
        rays[j].rayright = 0;
        rays[j].rayup = 0;
        rays[j].wallhitcontent = 0;
        rays[j].wallhitx = 0;
        rays[j].wallhity = 0;
        j++;
    }
}

int main(int ac, char **av)
{
    wolf_t wolf;
    player_t player;
    ray_t   rays[NUM_RAY];

    int **map;
    map = ft_check(ac, av);
    if (map == 0)
    {
        printf("map is invalid !!!\n");
        return (0);
    }
    init_wolf(&wolf);
    wolf.loop = init_window(&wolf);
    init_player(&player, &wolf);
    (void)map;
    init_tab(rays);
    while (wolf.loop)
    {
        process_input(&wolf, &player);
        update(map, &wolf.tickslastframe, &player, rays);
        render(&wolf, &player, map, rays);
    }
    destroy_window(&wolf);
}