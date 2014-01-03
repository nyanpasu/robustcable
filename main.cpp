#include <iostream>
#include <SDL/SDL.h>

SDL_Surface *dots = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

SDL_Rect clip[72];

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
        SDL_Rect offset;

        offset.x = x;
        offset.y = y;

        SDL_BlitSurface ( source, clip, destination, &offset );

}

int main(int argc, const char *argv[])
{
        // Get the correct offsets for each sprite.
        for (int y = 0; y < 8; y++) { 
                for (int x = 0; x < 9; x++) { 
                        // Top left
                        clip[ (x+1) * y ].x = x * 32;
                        clip[ (x+1) * y ].y = y * 32;
                        
                        // Top right
                        clip[ (x+1) * y ].x = x * 32 + 32;
                        clip[ (x+1) * y ].y = y * 32 + 32;
                }
                
        }

         // Fill the screen white
         SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 

        // Apply the images to the screen
        //
        // TODO: Use a loop and display each sprite with a boundary of 2 pixels.
        for (i = 0; i < 5; i++) {
                apply_surface( i * 50, 0, dots, screen, &clip[ i ]);
        }

        // Update the screen
        if ( SDL_Flip( screen ) == -1 )
        {
                return 1;
        }
        
        return 0;
}
