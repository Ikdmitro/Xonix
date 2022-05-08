//”корачивание названий стандартных SDL-функций
#define renderRect SDL_RenderDrawRect
#define renderFillRect SDL_RenderFillRect
#define renderFillRects SDL_RenderFillRects
#define renderLine SDL_RenderDrawLine
#define renderPoint SDL_RenderDrawPoint
#define setRenderColor SDL_SetRenderDrawColor
#define renderPoints SDL_RenderDrawPoints
#define renderRects SDL_RenderDrawRects
#define renderLines SDL_RenderDrawLines
#define loadImgBmp SDL_LoadBMP
#define renderClear SDL_RenderClear
#define renderPresent SDL_RenderPresent
#define renderCopy SDL_RenderCopy
#define destroyTexture SDL_DestroyTexture

#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <ctime>
#include <malloc.h>
#include"stdlib.h"
#pragma comment(linker, "/STACK:306777216") //дл€ решени€ проблемы с переполнением стека
