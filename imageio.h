#pragma once

const int MAX_H = 512;
const int MAX_W = 512;
const int MAX_H2 = 1024;
const int MAX_W2 = 1024;


void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width);
void writeImage2(std::string filename, int image[MAX_H2][MAX_W2], int height, int width);