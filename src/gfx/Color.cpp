/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#include "Color.h"

Color::Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

Uint32 Color::createRGBA(SDL_Color color) {
    return createRGBA(color.r, color.g, color.b, color.a);
}

Uint32 Color::createRGBA(int r, int g, int b, int a) {
    return ((a & 0xff) << 24)
        + ((r & 0xff) << 16)
        + ((g & 0xff) << 8)
        + (b & 0xff);
}

Uint32 Color::createARGB(SDL_Color color) {
    return createARGB(color.a, color.r, color.g, color.b);
}

Uint32 Color::createARGB(int a, int r, int g, int b) {
    return ((r & 0xff) << 24)
        + ((g & 0xff) << 16)
        + ((b & 0xff) << 8)
        + (a & 0xff);
}

unsigned long Color::getHex() {
    return createRGBA(this->r, this->g, this->b, this->a);
}

SDL_Color Color::getRed() {
    SDL_Color red = { 255, 0, 0, 255 };
    return red;
}

SDL_Color Color::getGreen() {
    SDL_Color green = { 0, 255, 0, 255 };
    return green;
}

SDL_Color Color::getBlue() {
    SDL_Color blue = { 0, 0, 255, 255 };
    return blue;
}

SDL_Color Color::getWhite() {
    SDL_Color white = { 255, 255, 255, 255 };
    return white;
}

SDL_Color Color::getBlack() {
    SDL_Color black = { 0, 0, 0, 255 };
    return black;
}

SDL_Color Color::getGray() {
    SDL_Color gray = { 128, 128, 128, 255 };
    return gray;
}

SDL_Color Color::getOrange() {
    SDL_Color orange = { 255, 200, 0, 255 };
    return orange;
}

SDL_Color Color::getYellow() {
    SDL_Color yellow = { 255, 255, 0, 255 };
    return yellow;
}

SDL_Color Color::getPink() {
    SDL_Color pink = { 255, 175, 175, 255 };
    return pink;
}

SDL_Color Color::getBrown() {
    SDL_Color brown = { 78, 53, 36, 255 };
    return brown;
}
