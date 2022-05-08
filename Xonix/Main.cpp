#include "config.h"
#include "headers/dataStructs.h"
#include "headers/dataImg.h"
#include "headers/dataText.h"
#include "headers/functionsStructs.h"
#include "headers/functionsText.h"
#include "headers/functionsImg.h"
#include "headers/functionsView.h"
#include "headers/renderBlocks.h"

//Параметры экрана
int FULLSCREEN_WIDTH;
int FULLSCREEN_HEIGHT;

//Инициализация SDL структур
SDL_DisplayMode DM;
SDL_Window* window;
SDL_Renderer* renderer;
//Инициализация картинок 
Images images;

int main(int argc, char** argv)
{
	createMenu();
    return 0;
}
