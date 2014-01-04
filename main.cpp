/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Help plans out wire art for the game known as SS13
 *
 *        Version:  1.0
 *        Created:  01/04/2014 08:21:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <SDL/SDL.h>

const int SPRITE_WIDTH = 32;
const int SPRITE_HEIGHT = 32;
const int TOTAL_SPRITES_ACROSS = 9;
const int TOTAL_SPRITES_DOWN = 8;
const int TOTAL_SPRITE = TOTAL_SPRITES_ACROSS * TOTAL_SPRITES_DOWN;

int SPRITE_DIR = "images/";

class Button
{
        private:
                SDL_Rect box;

        public:
                Button ( int x, int y, int w, int h);

                void handle_events();
                void show();
};

Button::Button ( int x, int y, int w, int h)
{
        box.x = x;
        box.y = y;
        box.w = w;
        box.h = h;
}

void Button::handle_events()
{
        int x = 0, y = 0;

        if ( event.type == SDL_MOUSEMOTION )
        {
                x = event.motion.x;
                y = event.motion.y;

                // If the mouse is over the button
                if ( ( x > box.x ) && ( x < box.x + box.w) && ( y > box. y) && ( y < box.y + box.h) )
                {
                        // Enlarge the box.
                }
                else
                {
                        // Set it to the regular size.
                }
        }

        if ( event.type == SDL_MOUSEBUTTONDOWN )
        {
                if (event.button.button == SDL_BUTTON_LEFT )
                {
                        // Change the button to that of the corresponding sprite
                }
        }
}

void Button::show()
{
        // Display the button in its current state.
}

void cut_surface ( int x, int y, SDL_Surface *source, SDL_Surface *destination )
{
        SDL_Rect offset;

        offset.x = x;
        offset.y = y;

        SDL_BlitSurface ( source, clip, destination, &offset );
}

void load_sprites_from_spritesheet ( SDL_Surface *spritesheet, SDL_Surface *spritearray ) // TODO Complete the load_sprites function
{
        // 
        // For every sprite across
        // and every sprite below
        // Clip it according to the sprite width and height
        // and store it into the sprite array.
        //
}

// Maybe a function to set the clips?

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
        return 0;
}
