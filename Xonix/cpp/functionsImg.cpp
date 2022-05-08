#include "../config.h"
#include "../headers/dataStructs.h"
#include "../headers/dataImg.h"
#include "../headers/dataText.h"
#include "../headers/functionsStructs.h"
#include "../headers/functionsText.h"
#include "../headers/functionsImg.h"
#include "../headers/functionsView.h"
#include "../headers/renderBlocks.h"

//Параметры экрана
extern int FULLSCREEN_WIDTH;
extern int FULLSCREEN_HEIGHT;

//Инициализация SDL структур
extern SDL_DisplayMode DM;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
//Инициализация картинок
extern Images images;

void initImages(Images* images) {
	SDL_Surface* headImg = loadImgBmp("img/head.bmp");
	SDL_Surface* startImg = loadImgBmp("img/start.bmp");
	SDL_Surface* recordsImg = loadImgBmp("img/records.bmp");
	SDL_Surface* exitImg = loadImgBmp("img/exit.bmp");
	SDL_Surface* returnImg = loadImgBmp("img/return.bmp");
	SDL_Surface* menuImg = loadImgBmp("img/menu.bmp");
	SDL_Surface* backImg = loadImgBmp("img/back.bmp");
	SDL_Surface* lifeBuffImg = loadImgBmp("img/lifeBuff.bmp");
	SDL_Surface* lifeDebuffImg = loadImgBmp("img/lifeDebuff.bmp");
	SDL_Surface* timeBuffImg = loadImgBmp("img/timeBuff.bmp");
	SDL_Surface* timeDebuffImg = loadImgBmp("img/timeDebuff.bmp");
	SDL_Surface* scoreBuffImg = loadImgBmp("img/scoreBuff.bmp");
	SDL_Surface* scoreDebuffImg = loadImgBmp("img/scoreDebuff.bmp");
	SDL_Surface* areaLevelImg = loadImgBmp("img/areaLevel.bmp");
	SDL_Surface* lockLevelImg = loadImgBmp("img/lockLevel.bmp");

	SDL_SetColorKey(headImg, SDL_TRUE, SDL_MapRGB(headImg->format, 255, 255, 255));
	images->headImg = SDL_CreateTextureFromSurface(renderer, headImg);
	images->destHeadImg.x = (FULLSCREEN_WIDTH - headImg->w) / 2;
	images->destHeadImg.y = (FULLSCREEN_HEIGHT / 6);
	images->destHeadImg.w = headImg->w;
	images->destHeadImg.h = headImg->h;

	images->startImg = SDL_CreateTextureFromSurface(renderer, startImg);
	images->destStartImg.x = (FULLSCREEN_WIDTH - recordsImg->w - startImg->w - exitImg->w - 120) / 2;
	images->destStartImg.y = FULLSCREEN_HEIGHT / 3 * 2;
	images->destStartImg.w = startImg->w;
	images->destStartImg.h = startImg->h;

	images->recordsImg = SDL_CreateTextureFromSurface(renderer, recordsImg);
	images->destRecordsImg.x = images->destStartImg.x + startImg->w + 60;
	images->destRecordsImg.y = FULLSCREEN_HEIGHT / 3 * 2;
	images->destRecordsImg.w = recordsImg->w;
	images->destRecordsImg.h = recordsImg->h;

	images->exitImg = SDL_CreateTextureFromSurface(renderer, exitImg);
	images->destExitMenuImg.x = images->destRecordsImg.x + recordsImg->w + 60;
	images->destExitMenuImg.y = FULLSCREEN_HEIGHT / 3 * 2;
	images->destExitMenuImg.w = exitImg->w;
	images->destExitMenuImg.h = exitImg->h;
	images->destExitGameImg.x = (FULLSCREEN_WIDTH - exitImg->w) / 2;
	images->destExitGameImg.y = 600;
	images->destExitGameImg.w = exitImg->w;
	images->destExitGameImg.h = exitImg->h;

	images->returnImg = SDL_CreateTextureFromSurface(renderer, returnImg);
	images->destReturnImg.x = (FULLSCREEN_WIDTH - returnImg->w) / 2;
	images->destReturnImg.y = 200;
	images->destReturnImg.w = returnImg->w;
	images->destReturnImg.h = returnImg->h;
	images->destReturnLoseImg.x = (FULLSCREEN_WIDTH - returnImg->w) / 2;
	images->destReturnLoseImg.y = 300;
	images->destReturnLoseImg.w = returnImg->w;
	images->destReturnLoseImg.h = returnImg->h;

	images->menuImg = SDL_CreateTextureFromSurface(renderer, menuImg);
	images->destMenuImg.x = (FULLSCREEN_WIDTH - menuImg->w) / 2;
	images->destMenuImg.y = 400;
	images->destMenuImg.w = menuImg->w;
	images->destMenuImg.h = menuImg->h;
	images->destMenuLoseImg.x = (FULLSCREEN_WIDTH - menuImg->w) / 2;
	images->destMenuLoseImg.y = 500;
	images->destMenuLoseImg.w = menuImg->w;
	images->destMenuLoseImg.h = menuImg->h;
	images->destMenuWinImg.x = (FULLSCREEN_WIDTH - menuImg->w) / 2;
	images->destMenuWinImg.y = 700;
	images->destMenuWinImg.w = menuImg->w;
	images->destMenuWinImg.h = menuImg->h;

	images->backImg = SDL_CreateTextureFromSurface(renderer, backImg);
	images->destBackImg.x = 0;
	images->destBackImg.y = 0;
	images->destBackImg.w = backImg->w;
	images->destBackImg.h = backImg->h;

	SDL_SetColorKey(lifeBuffImg, SDL_TRUE, SDL_MapRGB(lifeBuffImg->format, 255, 255, 255));
	images->lifeBuffImg = SDL_CreateTextureFromSurface(renderer, lifeBuffImg);

	SDL_SetColorKey(lifeDebuffImg, SDL_TRUE, SDL_MapRGB(lifeDebuffImg->format, 255, 255, 255));
	images->lifeDebuffImg = SDL_CreateTextureFromSurface(renderer, lifeDebuffImg);

	SDL_SetColorKey(timeBuffImg, SDL_TRUE, SDL_MapRGB(timeBuffImg->format, 255, 255, 255));
	images->timeBuffImg = SDL_CreateTextureFromSurface(renderer, timeBuffImg);

	SDL_SetColorKey(timeDebuffImg, SDL_TRUE, SDL_MapRGB(timeDebuffImg->format, 255, 255, 255));
	images->timeDebuffImg = SDL_CreateTextureFromSurface(renderer, timeDebuffImg);

	SDL_SetColorKey(scoreBuffImg, SDL_TRUE, SDL_MapRGB(scoreBuffImg->format, 255, 255, 255));
	images->scoreBuffImg = SDL_CreateTextureFromSurface(renderer, scoreBuffImg);

	SDL_SetColorKey(scoreDebuffImg, SDL_TRUE, SDL_MapRGB(scoreDebuffImg->format, 255, 255, 255));
	images->scoreDebuffImg = SDL_CreateTextureFromSurface(renderer, scoreDebuffImg);

	images->areaLevelImg = SDL_CreateTextureFromSurface(renderer, areaLevelImg);
	SDL_SetColorKey(lockLevelImg, SDL_TRUE, SDL_MapRGB(lockLevelImg->format, 255, 255, 255));
	images->lockLevelImg = SDL_CreateTextureFromSurface(renderer, lockLevelImg);
}
