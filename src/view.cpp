#include "view.h"

View::View()
{
    Scale = 4;                  // Integral scaling of a 16:9 base resolution
    Width = 320 * Scale;        // ** Width & Height **
    Height = 180 * Scale;       // Currently a Scale of a 16:9 resolution
   
    // Center of Viewport at scale
    Center.X = Width / 2;
    Center.Y = Height / 2;
}