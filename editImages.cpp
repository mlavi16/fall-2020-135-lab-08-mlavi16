#include <iostream>
#include "imageio.h"


void invert(std::string input) {
    // inverts all colors, so white shades become black, and black become white:
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
    // draws a white box exactly in the middle of the picture 
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if ((row > (h / 4)) && (row <= ((h / 4) * 3))) {
                if ((col > (w / 4)) && (col <= ((w / 4) * 3))) {
                    out[row][col] = 255;
                } else {
                    out[row][col] = img[row][col];
                }
            } else {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskC.pgm", out, h, w);
}

void frame(std::string input) {
    //draws a frame exactly one pixel thick in the middle of the picture
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        if (row == (h / 4) || row == ((h / 4) * 3)) { // top and bottom of frame
            for (int col = (w / 4); col <= (w / 4) * 3; col++){
                out[row][col] = 255;
            }
        } else if (row > (h / 4) && row < ((h / 4) * 3)) { // sides of frame
            for(int col = 0; col < w; col++) {
                if (col == (w / 4) || col == ((w / 4) * 3)) {
                    out[row][col] = 255;
                } else {
                    out[row][col] = img[row][col];
                }
            }
        } else { // no frame
            for(int col = 0; col < w; col++) {
                out[row][col] = img[row][col];
            }
        }
    }

    writeImage("taskD.pgm", out, h, w);
}

void scale(std::string input) {
    // Scales the original picture to 200% of its size
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int inc = 0;
    int out[MAX_H2][MAX_W2];
    int scale_row = 0;
    int scale_col = 0;
    
    for (int row = 0; row < h; row++) {
        scale_col = 0;
        for (int col = 0; col < w; col++) {
            out[scale_row][scale_col] = img[row][col];
            out[scale_row + 1][scale_col] = img[row][col];
            out[scale_row][scale_col + 1] = img[row][col];
            out[scale_row + 1][scale_col + 1] = img[row][col];
            scale_col += 2;
        }
        scale_row += 2;
    }

    writeImage2("taskE.pgm", out, scale_row, scale_col);
}

void pixelate(std::string input) {
    // pixelates the input image
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w);

    int out[MAX_H][MAX_W];
    int avg;

    for(int row = 0; row < h; row += 2) {
        for(int col = 0; col < w; col += 2) {
            avg = (img[row][col] + img[row + 1][col] + img[row][col + 1] + img[row + 1][col + 1]) / 4;
            out[row][col] = avg;
            out[row + 1][col] = avg;
            out[row][col + 1] = avg;
            out[row + 1][col + 1] = avg;
            
        }
    }
    writeImage("taskF.pgm", out, h, w);
}

void kernal(std::string input) {
    int img[MAX_H][MAX_W];
    int height, width;
    readImage(input, img, height, width);

    int out[MAX_H][MAX_W];
    int kernal, a, b, c, g, h, i;

    for(int row = 1; row < (height - 1); row++) {
        for(int col = 1; col < (width - 1); col++) {
            a = img[row - 1][col - 1];
            b = img[row - 1][col];
            c = img[row - 1][col + 1];
            g = img[row + 1][col - 1];
            h = img[row + 1][col];
            i = img[row + 1][col + 1];
            kernal = (g + (2 * h) + i) - (a + (2 * b) + c);

            if (kernal < 0) {
                kernal = 0;
            } else if (kernal > 255) {
                kernal = 255;
            }

            out[row][col] = kernal;
        }
    }

    //assigns black color to the boundary pixels
    for (int col = 0; col < width; col++) {
        out[0][col] = 0;
        out[height - 1][col] = 0;
    }
    for (int row = 0; row < height; row++) {
        out[row][0] = 0;
        out[row][width - 1] = 0;
    }

    writeImage("taskG.pgm", out, height, width);
}