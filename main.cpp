#include <iostream>
#include "editImages.h"
#include "imageio.h"

int main()
{
    std::string image = "image1.pgm";
    
    invert(image); // Task A
    invert_half(image); // Task B
    box(image); // Task C
    frame(image); // Task D
    scale(image); // Task E 
    pixelate(image); // Task F
    kernal(image); // Task G (bonus)
    
    return 0;
}