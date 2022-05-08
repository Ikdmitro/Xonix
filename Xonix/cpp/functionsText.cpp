#include "../config.h"
#include "../headers/dataStructs.h"
#include "../headers/dataImg.h"
#include "../headers/dataText.h"
#include "../headers/functionsStructs.h"
#include "../headers/functionsText.h"
#include "../headers/functionsImg.h"
#include "../headers/functionsView.h"

//Параметры экрана
extern int FULLSCREEN_WIDTH;
extern int FULLSCREEN_HEIGHT;

//Инициализация SDL структур
extern SDL_DisplayMode DM;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
//Инициализация картинок
extern Images images;

//Остальные переменные
extern char* text = new char[10];

TextGame createTextGame(Player* player, FieldGame* fieldGame) {
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	SDL_Color fore_color = { 255,255,255 };
	SDL_Color back_color = { 0,0,0 };
	TextGame textGame;

	textGame.textLives = TTF_RenderText_Shaded(font, "Lives:", fore_color, back_color);
	textGame.posTextLives = { 10,0,FULLSCREEN_WIDTH / 9,100 };

	textGame.textArea = TTF_RenderText_Shaded(font, "Area:", fore_color, back_color);
	textGame.posTextArea = { FULLSCREEN_WIDTH * 2 / 9,0,FULLSCREEN_WIDTH / 9,100 };

	textGame.textPersent = TTF_RenderText_Shaded(font, "%", fore_color, back_color);
	textGame.posTextPersent = { FULLSCREEN_WIDTH * 4 / 9 - 30,0,FULLSCREEN_WIDTH / 12,100 };

	textGame.textScore = TTF_RenderText_Shaded(font, "Score:", fore_color, back_color);
	textGame.posTextScore = { FULLSCREEN_WIDTH * 5 / 9,0,FULLSCREEN_WIDTH / 9,100 };

	textGame.textTime = TTF_RenderText_Shaded(font, "Time:", fore_color, back_color);
	textGame.posTextTime = { FULLSCREEN_WIDTH * 7 / 9,0,FULLSCREEN_WIDTH / 9,100 };

	TTF_Quit();
	return textGame;
}
void updateTextGame(TextGame* textGame, FieldGame* fieldGame, Player* player) {
	char* text = new char[10];
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	SDL_Color fore_color = { 255,255,255 };
	SDL_Color back_color = { 0,0,0 };
	_itoa(player->lives, text, 10);
	textGame->valueLives = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textGame->posValueLives = { FULLSCREEN_WIDTH / 9 + 10,0,FULLSCREEN_WIDTH / 12,100 };


	_itoa((fieldGame->area * 100 / (fieldGame->widthCell * fieldGame->heightCell - fieldGame->areaWrap) / 0.75), text, 10);
	textGame->valueArea = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textGame->posValueArea = { FULLSCREEN_WIDTH * 3 / 9 + 10,0,FULLSCREEN_WIDTH / 12,100 };


	_itoa(fieldGame->score, text, 10);
	textGame->valueScore = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textGame->posValueScore = { FULLSCREEN_WIDTH * 6 / 9,0,FULLSCREEN_WIDTH / 9,100 };

	_itoa(fieldGame->time / 1000, text, 10);
	textGame->valueTime = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textGame->posValueTime = { FULLSCREEN_WIDTH * 8 / 9,0,FULLSCREEN_WIDTH / 9,100 };
	TTF_Quit();
}
TextRecords createTextRecords(Records* records) {
	char* text = new char[10];
	TextRecords textRecords;
	TTF_Init();

	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 0,162,232 };

	textRecords.textRecord = TTF_RenderText_Shaded(font, "RECORDS", fore_color, back_color);
	textRecords.posTextRecord = { (FULLSCREEN_WIDTH - 1000) / 2,0,1000,200 };

	textRecords.textLevel = TTF_RenderText_Shaded(font, "Level ", fore_color, back_color);
	textRecords.posTextLevel = { (FULLSCREEN_WIDTH - 1000) / 2,200,300,100 };

	for (int i = 0; i < records->length; i++) {
		_itoa(i + 1, text, 10);
		textRecords.keysRecord[i] = TTF_RenderText_Shaded(font, text, fore_color, back_color);

		_itoa(records->masRecords[i], text, 10);
		textRecords.valuesRecord[i] = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	}
	textRecords.posKeysRecord = { textRecords.posTextLevel.x + textRecords.posTextLevel.w,200,50,100 };
	textRecords.posValuesRecord = { textRecords.posKeysRecord.x + textRecords.posKeysRecord.w + 300,200,350,100 };

	TTF_Quit();
	return textRecords;
}
TextLevels createTextLevels(Levels* levels) {
	char* text = new char[10];
	TextLevels textLevels;
	TTF_Init();
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 0,162,232 };
	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	int index = 0;
	textLevels.textLevels = TTF_RenderText_Shaded(font, "LEVELS", fore_color, back_color);
	textLevels.posTextLevels = { (FULLSCREEN_WIDTH - 1000) / 2,0,1000,200 };
	textLevels.posValueLevels = (SDL_Rect*)malloc(levels->length * sizeof(SDL_Rect));
	SDL_Rect posLevel = { textLevels.posTextLevels.x,textLevels.posTextLevels.y + textLevels.posTextLevels.h,260,260 };
	SDL_Rect posLevelText = { textLevels.posTextLevels.x + posLevel.w / 6 + 20,textLevels.posTextLevels.y + posLevel.y / 6 + textLevels.posTextLevels.h,posLevel.w / 3 * 2,posLevel.h / 3 * 2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			textLevels.posValueLevels[index].x = posLevel.x;
			textLevels.posValueLevels[index].y = posLevel.y;
			textLevels.posValueLevels[index].w = posLevel.w;
			textLevels.posValueLevels[index].h = posLevel.h;
			index++;
			posLevel.x += 350;
			posLevelText.x += 350;
		}
		posLevel.x = textLevels.posTextLevels.x;
		posLevelText.x = textLevels.posTextLevels.x + posLevel.w / 6 + 20;
		posLevel.y += 320;
		posLevelText.y += 320;
	}
	TTF_Quit();
	return textLevels;
}
TextWin createTextWin(FieldGame* fieldGame, Player* player) {
	char* text = new char[10];
	TextWin textWin;
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("19783.ttf", 100);
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 0,162,232 };

	textWin.textWin = TTF_RenderText_Shaded(font, "YOU WIN!", fore_color, back_color);
	textWin.posTextWin = { (FULLSCREEN_WIDTH - 500) / 2,0,500,150 };

	textWin.textScore = TTF_RenderText_Shaded(font, "Score", fore_color, back_color);
	textWin.posTextScore = { (FULLSCREEN_WIDTH - 500) / 5,150,500,150 };

	_itoa(fieldGame->score, text, 10);
	textWin.valueScore = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textWin.posValueScore = { textWin.posTextScore.x + textWin.posTextScore.w + 50,150,400,150 };

	fore_color = { 34,177,76 };
	textWin.textBonus = TTF_RenderText_Shaded(font, "Bonus", fore_color, back_color);
	textWin.posTextBonus = { (FULLSCREEN_WIDTH - 500) / 5,300,500,150 };

	_itoa(player->lives * 2000 + fieldGame->time / 10, text, 10);
	textWin.valueBonus = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textWin.posValueBonus = { textWin.posTextBonus.x + textWin.posTextBonus.w + 50,300,400,150 };

	fore_color = { 0,0,0 };
	textWin.textTotal = TTF_RenderText_Shaded(font, "Total", fore_color, back_color);
	textWin.posTextTotal = { (FULLSCREEN_WIDTH - 500) / 5,450,500,150 };

	_itoa(fieldGame->score + player->lives * 2000 + fieldGame->time / 10, text, 10);
	textWin.valueTotal = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	textWin.posValueTotal = { textWin.posTextTotal.x + textWin.posTextTotal.w + 50,450,400,150 };
	TTF_Quit();

	return textWin;
}
