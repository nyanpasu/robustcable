/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/2014 06:23:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
         */
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int TOTAL_WIRE_SPRITES_ACROSS = 9;
const int TOTAL_WIRE_SPRITES_DOWN   = 8;
const int TOTAL_WIRE_SPRITES        = TOTAL_WIRE_SPRITES_ACROSS * TOTAL_WIRE_SPRITES_DOWN;

const std::string SPRITE_DIR = "images/";

/**
 * Makes a lot of noise when something goes wrong.
 */
void logSDLError( const std::string &message ) 
{
        std::cout << "Error: " << message << " " << SDL_GetError() << std::endl;
}

/**
 * Loads a BMP image into a texture, then onto the rendering device
 * TODO: Add PNG support
 * @param file The BMP image to load
 * @param renderer The renderer to load the texture onto
 * @return the loaded texture, or nullptr if something went wrong.
 */
SDL_Texture *loadTexture( const std::string &file, SDL_Renderer *renderer )
{
        SDL_Texture *texture = IMG_LoadTexture( renderer, file.c_str() );

        if ( texture == nullptr )
        {
               logSDLError("Texture at loadTexture()");
        }

        return texture;
}

/**
 * Draw an SDL_Texture onto an SDL_Renderer at a selected postion
 * @param texture The source texture
 * @param renderer The destination renderer
 * @param x x coordinate
 * @param y y coordinate
 * @param w width of texture
 * @param h height of texture
 */
void renderTexture( SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h )
{
        SDL_Rect destination;
        destination.x = x;
        destination.y = y;
        destination.w = w;
        destination.h = h;

        SDL_RenderCopy( renderer, texture, NULL, &destination );
}


int main(int argc, const char *argv[])
{
        // - Load the sprites from the green cable.png and build an array containing each of the sprites (wires)
        //
        // - 
        // // As you hover over the sprite box,  the sprite will expand by one pixel on all edges
        // // If you click it, the sprite display on the top left of the screen 
        // // will change to reflect the new sprite.
        //
        // - Load the menu to the side that will let you select a sprite
        // - Initialize a main grid that displays the wires
        // - Each wire is assigned a code
        //
        // Process the commands
        // The following commands are accpeted and interpreted:
        // - Left mouse click on grid to draw selected sprite
        // - Right mouse click on grid to remove a sprite, if any, from grid
        // - Left mouse on the the button at the bottom right will open a menu with the option
        // to choose spritesheet and individual sprite
        //
        // There should be an option to save or load sprites
        // TODO: Custom grid size, option to just drag out a pattern and have the program
        // choose the most appropriate sprite
        // TODO: Load image in background.
        // 

        // Start SDL
        if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
        {
                logSDLError("SDL");
                return 1;
        }

        // Start SDL and the main renderer
        SDL_Window *window = nullptr;
        window = SDL_CreateWindow( "New window", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        if ( window == nullptr )
        {
                logSDLError("Window");
                return 1;
        }

        SDL_Renderer *mainRenderer = nullptr;
        mainRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

        if ( mainRenderer == nullptr )
        {
                logSDLError("Renderer");
                return 1;
        }

        // Load the all the sprites in images
        // for each *.png images in SPRITES_DIR
        // load image into spritesheets[]
        //
        // Currently place holder that will only load green cables.
        SDL_Texture *spriteSheet = loadTexture( "./image/power_cond_green.png", mainRenderer);

        // And check every file to see if it loaded successfully
        //
        // Currently just checking the only spritesheet loaded
        if ( spriteSheet == nullptr )
        {
               logSDLError("Failed to read texture");
        }
        
        // Do teh render routine
        // TODO have to write a render function that does the following:
        // - Look at the state of the canvas
        // - Draw the canvas
        // - Draw the current "pen" sprite
        // - Draw the menu if it's enabled
        //
        // Currently just viewing the spritesheet.
        SDL_RenderClear( mainRenderer );
        renderTexture( spriteSheet, mainRenderer, 0, 0 , SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_RenderPresent( mainRenderer );
        SDL_Delay(2000);

        SDL_DestroyTexture(spriteSheet);
        SDL_DestroyRenderer(mainRenderer);
        SDL_DestroyWindow(window);

        SDL_Quit();

        return 0;
}
