#include <iostream>
#include "imageio.h"

void invert(std::string input) {
    // inverts all colors, so white shades become black, and black become white:

    // input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            out[row][col] = 255 - img[row][col];
        }
    }

    writeImage("taskA.pgm",out, h, w);
}

void invert_half(std::string input) {
    //inverts the colors only in the right half of the picture.
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < (w / 2); col++) {
            out[row][col] = img[row][col];
        }
        for(int col = (w / 2); col < w; col++) {
            out[row][col] = 255 - img[row][col];
        }
    }
    writeImage("taskB.pgm", out, h, w);
}

void box(std::string input) {
    
}