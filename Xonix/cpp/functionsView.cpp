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

void renderPlayer(Player* player) {
	setRenderColor(renderer, player->r, player->g, player->b, 1);
	SDL_Rect playerView = { player->x,player->y,player->w,player->h };
	renderFillRect(renderer, &playerView);
}
void renderFieldState(FieldState* fieldState) {
	setRenderColor(renderer, fieldState->r, fieldState->g, fieldState->b, 1);
	SDL_Rect fieldStateView = { fieldState->x,fieldState->y,fieldState->w,fieldState->h };
	renderFillRect(renderer, &fieldStateView);
}
void renderFoes(listFoes* listFoes) {
	setRenderColor(renderer, listFoes->foes[0].r, listFoes->foes[0].g, listFoes->foes[0].b, 1);
	for (int i = 0; i < listFoes->length; i++) {
		SDL_Rect rect;
		rect.x = listFoes->foes[i].x;
		rect.y = listFoes->foes[i].y;
		rect.w = listFoes->foes[i].w;
		rect.h = listFoes->foes[i].h;
		renderFillRect(renderer, &rect);
	}
}
void renderFieldGame(FieldGame fieldGame) {
	setRenderColor(renderer, 0, 0, 0, 1);
	renderClear(renderer);

	setRenderColor(renderer, 0, 0, 0, 1);
	SDL_Rect rect = { fieldGame.x,fieldGame.y,fieldGame.w,fieldGame.h };
	renderFillRect(renderer, &rect);
	rect = { fieldGame.x,fieldGame.y,10,10 };
	setRenderColor(renderer, 0, 168, 168, 1);
	for (int i = 0; i < fieldGame.heightCell; i++) {
		rect.y = fieldGame.y + i * 10;
		rect.x = fieldGame.x;
		rect.w = 10;;
		for (int j = 0; j < fieldGame.widthCell - 1; j++) {
			if (*(fieldGame.matrix + i * fieldGame.widthCell + j) != *(fieldGame.matrix + i * fieldGame.widthCell + j + 1) || j == fieldGame.widthCell - 2) {
				if (j == fieldGame.widthCell - 2) rect.w += 10;
				switch (*(fieldGame.matrix + i * fieldGame.widthCell + j)) {
				case 1: setRenderColor(renderer, 0, 168, 168, 1);
					break;
				case 2: setRenderColor(renderer, 0, 168, 168, 1);
					break;
				default: setRenderColor(renderer, 0, 0, 0, 1);
				}
				renderFillRect(renderer, &rect);
				rect.x += rect.w;
				rect.w = 10;
			}
			else {
				rect.w += 10;
			}
		}
	}
}
void renderTextState(TextGame* textGame) {
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(renderer, textGame->textLives);
	renderCopy(renderer, texture, NULL, &textGame->posTextLives);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->valueLives);
	renderCopy(renderer, texture, NULL, &textGame->posValueLives);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->textArea);
	renderCopy(renderer, texture, NULL, &textGame->posTextArea);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->valueArea);
	renderCopy(renderer, texture, NULL, &textGame->posValueArea);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->textPersent);
	renderCopy(renderer, texture, NULL, &textGame->posTextPersent);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->textScore);
	renderCopy(renderer, texture, NULL, &textGame->posTextScore);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->valueScore);
	renderCopy(renderer, texture, NULL, &textGame->posValueScore);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->textTime);
	renderCopy(renderer, texture, NULL, &textGame->posTextTime);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textGame->valueTime);
	renderCopy(renderer, texture, NULL, &textGame->posValueTime);
	destroyTexture(texture);
}
void renderMenu(SDL_Renderer* renderer, Images* images) {
	setRenderColor(renderer, 0, 162, 232, 1);
	renderClear(renderer);
	renderCopy(renderer, images->headImg, NULL, &images->destHeadImg);
	renderCopy(renderer, images->startImg, NULL, &images->destStartImg);
	renderCopy(renderer, images->recordsImg, NULL, &images->destRecordsImg);
	renderCopy(renderer, images->exitImg, NULL, &images->destExitMenuImg);
	SDL_RenderPresent(renderer);
}
void renderMenuInGame(SDL_Renderer* renderer, Images* images) {
	setRenderColor(renderer, 0, 162, 232, 1);
	renderClear(renderer);
	renderCopy(renderer, images->returnImg, NULL, &images->destReturnImg);
	renderCopy(renderer, images->menuImg, NULL, &images->destMenuImg);
	renderCopy(renderer, images->exitImg, NULL, &images->destExitGameImg);
	SDL_RenderPresent(renderer);
}
void renderRecords(TextRecords* textRecords, Records* records) {
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(renderer, textRecords->textRecord);
	renderCopy(renderer, texture, NULL, &textRecords->posTextRecord);

	for (int i = 0; i < records->length; i++) {
		texture = SDL_CreateTextureFromSurface(renderer, textRecords->textLevel);
		renderCopy(renderer, texture, NULL, &textRecords->posTextLevel);
		destroyTexture(texture);
		textRecords->posTextLevel.y += textRecords->posTextLevel.h;

		texture = SDL_CreateTextureFromSurface(renderer, textRecords->keysRecord[i]);
		renderCopy(renderer, texture, NULL, &textRecords->posKeysRecord);
		destroyTexture(texture);
		textRecords->posKeysRecord.y += textRecords->posKeysRecord.h;

		texture = SDL_CreateTextureFromSurface(renderer, textRecords->valuesRecord[i]);
		renderCopy(renderer, texture, NULL, &textRecords->posValuesRecord);
		destroyTexture(texture);
		textRecords->posValuesRecord.y += textRecords->posValuesRecord.h;
	}
}
void renderBonuses(Bonuses* bonuses, Images* images) {
	SDL_Texture* texture = NULL;
	SDL_Rect rect;
	for (int i = 0; i <= bonuses->top; i++) {
		rect.x = bonuses->listBonuses[i].x;
		rect.y = bonuses->listBonuses[i].y;
		rect.w = bonuses->listBonuses[i].w;
		rect.h = bonuses->listBonuses[i].h;
		switch (bonuses->listBonuses[i].typeBonus) {
		case 0: renderCopy(renderer, images->lifeBuffImg, NULL, &rect);
			break;
		case 1: renderCopy(renderer, images->lifeDebuffImg, NULL, &rect);
			break;
		case 2: renderCopy(renderer, images->timeBuffImg, NULL, &rect);
			break;
		case 3: renderCopy(renderer, images->timeDebuffImg, NULL, &rect);
			break;
		case 4: renderCopy(renderer, images->scoreBuffImg, NULL, &rect);
			break;
		case 5: renderCopy(renderer, images->scoreDebuffImg, NULL, &rect);
			break;
		}
	}
}
void renderLevels(Levels* levels, TextLevels* textLevels, Records* records) {
	TTF_Init();
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 112,146,190 };
	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	char* text = new char[10];
	SDL_Texture* texture = NULL;
	int index = 0;
	texture = SDL_CreateTextureFromSurface(renderer, textLevels->textLevels);
	renderCopy(renderer, texture, NULL, &textLevels->posTextLevels);
	destroyTexture(texture);
	SDL_Rect posLevel = { textLevels->posTextLevels.x,textLevels->posTextLevels.y + textLevels->posTextLevels.h,260,260 };
	SDL_Rect posLevelText = { textLevels->posTextLevels.x + posLevel.w / 6 + 20,textLevels->posTextLevels.y + posLevel.y / 6 + +textLevels->posTextLevels.h,posLevel.w / 3 * 2,posLevel.h / 3 * 2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			_itoa(levels->masLevels[index].numberLevel, text, 10);
			textLevels->valueLevels = TTF_RenderText_Shaded(font, text, fore_color, back_color);
			texture = SDL_CreateTextureFromSurface(renderer, textLevels->valueLevels);
			renderCopy(renderer, images.areaLevelImg, NULL, &textLevels->posValueLevels[index]);
			renderCopy(renderer, texture, NULL, &posLevelText);
			destroyTexture(texture);
			if (index > records->top) {
				renderCopy(renderer, images.lockLevelImg, NULL, &textLevels->posValueLevels[index]);
			}
			posLevelText.x += 350;
			index++;
		}
		posLevelText.x = textLevels->posTextLevels.x + posLevel.w / 6 + 20;
		posLevelText.y += 320;
	}
	TTF_Quit();
}

void renderLose(Images* images) {
	setRenderColor(renderer, 0, 162, 232, 1);
	renderClear(renderer);
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 0,162,232 };
	SDL_Surface* textLose = TTF_RenderText_Shaded(font, "YOU LOSE!", fore_color, back_color);
	TTF_Quit();
	SDL_Rect posTextLose = { (FULLSCREEN_WIDTH - 500) / 2,100,500,200 };
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textLose);
	renderCopy(renderer, texture, NULL, &posTextLose);
	destroyTexture(texture);
	renderCopy(renderer, images->menuImg, NULL, &images->destMenuLoseImg);
	renderCopy(renderer, images->returnImg, NULL, &images->destReturnLoseImg);
	renderPresent(renderer);
}
void renderWin(FieldGame* fieldGame, Player* player, Images* images) {
	TextWin textWin = createTextWin(fieldGame, player);
	SDL_Texture* texture = NULL;
	setRenderColor(renderer, 0, 162, 232, 1);
	renderClear(renderer);
	texture = SDL_CreateTextureFromSurface(renderer, textWin.textWin);
	renderCopy(renderer, texture, NULL, &textWin.posTextWin);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textWin.textScore);
	renderCopy(renderer, texture, NULL, &textWin.posTextScore);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textWin.valueScore);
	renderCopy(renderer, texture, NULL, &textWin.posValueScore);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textWin.textBonus);
	renderCopy(renderer, texture, NULL, &textWin.posTextBonus);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textWin.valueBonus);
	renderCopy(renderer, texture, NULL, &textWin.posValueBonus);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textWin.textTotal);
	renderCopy(renderer, texture, NULL, &textWin.posTextTotal);
	destroyTexture(texture);

	texture = SDL_CreateTextureFromSurface(renderer, textWin.valueTotal);
	renderCopy(renderer, texture, NULL, &textWin.posValueTotal);
	destroyTexture(texture);

	renderCopy(renderer, images->menuImg, NULL, &images->destMenuWinImg);
	renderPresent(renderer);
}
