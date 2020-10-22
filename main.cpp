#include <iostream>
#include "editImages.h"
#include "imageio.h"

int main()
{
    std::string img = "inImage.pgm";
    invert(img);
    invert_half(img);

    return 0;
}