/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include <set>
#include <map>
#include <list>
#include <array>
#include <cmath>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <utility>
#include <fstream>
#include <iostream>
#include <typeindex>
#include <algorithm>
#include <filesystem>
#include <functional>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define QUIT -1
#define AUDIO_FOLDER "./data/audios/"
#define FONT_FOLDER "./data/fonts/"
#define IMAGE_FOLDER "./data/images/"
#define MAP_FOLDER "./data/maps/"

#define SCREEN_WIDTH 800
#define SCREEN_H_WIDTH SCREEN_WIDTH/2
#define SCREEN_HEIGHT 600
#define SCREEN_H_HEIGHT SCREEN_HEIGHT/2 

class Common final {
public:
    inline static const char NAME[] = "- doodi engine 0.0.2 -";

    static const int FPS = 144;
    static const int MILLISECS_PER_FRAME = 1000 / FPS; 
};
