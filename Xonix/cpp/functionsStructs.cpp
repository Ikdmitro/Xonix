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

FieldGame createFieldGame(Level* level) {
	FieldGame fieldGame;
	fieldGame.x = 0;
	fieldGame.y = 110;
	fieldGame.w = FULLSCREEN_WIDTH - fieldGame.x * 2 - FULLSCREEN_WIDTH % 10;
	fieldGame.h = FULLSCREEN_HEIGHT - fieldGame.y - fieldGame.x - FULLSCREEN_HEIGHT % 10;
	fieldGame.widthCell = fieldGame.w / 10;
	fieldGame.heightCell = fieldGame.h / 10;
	fieldGame.area = fieldGame.areaWrap = fieldGame.area = 0;
	fieldGame.score = 0;
	fieldGame.time = 100000;
	switch (level->numberLevel) {
	case 1: level->numberFoes = 2;
		break;
	case 2: level->numberFoes = 3;
		level->lengthAreas = 2;
		level->areas = (Area*)malloc(level->lengthAreas * sizeof(Area));
		level->areas->widthCell = 30;
		level->areas->heightCell = 30;
		level->areas->xCell = (fieldGame.widthCell - level->areas->widthCell) / 2;
		level->areas->yCell = 2;
		level->areas[1].widthCell = 30;
		level->areas[1].heightCell = 30;
		level->areas[1].xCell = (fieldGame.widthCell - level->areas->widthCell) / 2;
		level->areas[1].yCell = (fieldGame.heightCell - level->areas->heightCell - 2);
		break;
	case 3: level->numberFoes = 4;
		level->lengthAreas = 4;
		level->areas = (Area*)malloc(level->lengthAreas * sizeof(Area));
		level->areas->widthCell = 15;
		level->areas->heightCell = 15;
		level->areas->xCell = (fieldGame.widthCell - level->areas->widthCell) / 2;
		level->areas->yCell = 2;
		level->areas[1].widthCell = 15;
		level->areas[1].heightCell = 15;
		level->areas[1].xCell = (fieldGame.widthCell - level->areas->widthCell) / 2;
		level->areas[1].yCell = (fieldGame.heightCell - level->areas->heightCell - 2);
		level->areas[2].widthCell = 15;
		level->areas[2].heightCell = 15;
		level->areas[2].xCell = 2;
		level->areas[2].yCell = (fieldGame.heightCell - level->areas->heightCell)/2;
		level->areas[3].widthCell = 15;
		level->areas[3].heightCell = 15;
		level->areas[3].xCell = (fieldGame.widthCell - level->areas->widthCell - 2);
		level->areas[3].yCell = (fieldGame.heightCell - level->areas->heightCell) / 2;

		break;
	case 4: level->numberFoes = 4;
		level->lengthAreas = 4;
		level->areas = (Area*)malloc(level->lengthAreas * sizeof(Area));
		level->areas->widthCell = 20;
		level->areas->heightCell = 20;
		level->areas->xCell = (fieldGame.widthCell - level->areas->widthCell - 128) / 2;
		level->areas->yCell = (fieldGame.heightCell - level->areas->heightCell - 50) / 2;
		level->areas[1].widthCell = 20;
		level->areas[1].heightCell = 20;
		level->areas[1].xCell = (fieldGame.widthCell - level->areas->widthCell - 128) / 2;
		level->areas[1].yCell = (fieldGame.heightCell - level->areas->heightCell + 51) / 2;
		level->areas[2].widthCell = 20;
		level->areas[2].heightCell = 20;
		level->areas[2].xCell = (fieldGame.widthCell - level->areas->widthCell + 129) / 2;
		level->areas[2].yCell = (fieldGame.heightCell - level->areas->heightCell + 51) / 2;
		level->areas[3].widthCell = 20;
		level->areas[3].heightCell = 20;
		level->areas[3].xCell = (fieldGame.widthCell - level->areas->widthCell + 129) / 2;
		level->areas[3].yCell = (fieldGame.heightCell - level->areas->heightCell - 50) / 2;
		break;
	case 5: level->numberFoes = 5;
		level->lengthAreas = 1;
		level->areas = (Area*)malloc(level->lengthAreas * sizeof(Area));
		level->areas->widthCell = 10;
		level->areas->heightCell = (fieldGame.heightCell - 4);
		level->areas->xCell = (fieldGame.widthCell - level->areas->widthCell) / 2;
		level->areas->yCell = 2;
		break;
	case 6: level->numberFoes = 6;
		level->lengthAreas = 3;
		level->areas = (Area*)malloc(level->lengthAreas * sizeof(Area));
		level->areas->widthCell = 10;
		level->areas->heightCell = (fieldGame.heightCell - 4);
		level->areas->xCell = (fieldGame.widthCell - level->areas->widthCell) / 2;
		level->areas->yCell = 2;
		level->areas[1].widthCell = (fieldGame.widthCell - level->areas->widthCell - 4) / 2;
		level->areas[1].heightCell = 10;
		level->areas[1].xCell = 2;
		level->areas[1].yCell = (fieldGame.heightCell - level->areas[1].heightCell) / 2;
		level->areas[2].widthCell = (fieldGame.widthCell - level->areas->widthCell - 4) / 2 + 1;
		level->areas[2].heightCell = 10;
		level->areas[2].xCell = level->areas->widthCell + level->areas->xCell;
		level->areas[2].yCell = (fieldGame.heightCell - level->areas[1].heightCell) / 2;
	}
	fieldGame.matrix = (int*)malloc(fieldGame.widthCell * fieldGame.heightCell * sizeof(int));
	for (int i = 0; i < fieldGame.heightCell; i++) {
		for (int j = 0; j < fieldGame.widthCell; j++) {
			*(fieldGame.matrix + i * fieldGame.widthCell + j) = 0;
			if (i <= 1 || i >= fieldGame.heightCell - 2 || j <= 1 || j >= fieldGame.widthCell - 2)
			{
				*(fieldGame.matrix + i * fieldGame.widthCell + j) = 2;
				fieldGame.areaWrap++;
			}
		}
	}
	for (int k = 0; k < level->lengthAreas; k++) {
		for (int i = level->areas[k].yCell; i < level->areas[k].yCell + level->areas[k].heightCell; i++) {
			for (int j = level->areas[k].xCell; j < level->areas[k].xCell + level->areas[k].widthCell; j++) {
				*(fieldGame.matrix + i * fieldGame.widthCell + j) = 2;
				fieldGame.areaWrap++;
			}
		}
	}
	fieldGame.r = 17;
	fieldGame.g = 236;
	fieldGame.b = 247;
	return fieldGame;
}
int checkFoe(FieldGame* fieldGame, int posX, int posY, listFoes* listFoes) {
	for (int i = 0; i < listFoes->length; i++) {
		if (posX == listFoes->foes[i].posMatrixX && posY == listFoes->foes[i].posMatrixY) return 0;
	}
	if (*(fieldGame->matrix + posY * fieldGame->widthCell + posX) == 0) {
		*(fieldGame->matrix + posY * fieldGame->widthCell + posX) = 3;
	}
	int k = 1;
	if (*(fieldGame->matrix + posY * fieldGame->widthCell + (posX + 1)) == 0) k = checkFoe(fieldGame, posX+1, posY, listFoes);
	if (!k) return 0;
	if (*(fieldGame->matrix + (posY - 1) * fieldGame->widthCell + posX) == 0) k = checkFoe(fieldGame, posX, posY - 1, listFoes);
	if (!k) return 0;
	if (*(fieldGame->matrix + posY * fieldGame->widthCell + (posX - 1)) == 0) k = checkFoe(fieldGame, posX - 1, posY, listFoes);
	if (!k) return 0;
	if (*(fieldGame->matrix + (posY + 1) * fieldGame->widthCell + posX) == 0) k = checkFoe(fieldGame, posX, posY + 1, listFoes);
	if (!k) return 0;
	return 1;
}
void paintingField(FieldGame* fieldGame, int posX, int posY) {
	if (*(fieldGame->matrix + posY * fieldGame->widthCell + posX) == 3) {
		*(fieldGame->matrix + posY * fieldGame->widthCell + posX) = 2;
		fieldGame->newArea++;
	}
	if (*(fieldGame->matrix + (posY + 1) * fieldGame->widthCell + posX) == 3) paintingField(fieldGame, posX, posY + 1);
	if (*(fieldGame->matrix + posY * fieldGame->widthCell + (posX + 1)) == 3) paintingField(fieldGame, posX + 1, posY);
	if (*(fieldGame->matrix + (posY - 1) * fieldGame->widthCell + posX) == 3) paintingField(fieldGame, posX, posY - 1);
	if (*(fieldGame->matrix + posY * fieldGame->widthCell + (posX - 1)) == 3) paintingField(fieldGame, posX - 1, posY);
	
}
void updateFieldGame(FieldGame* fieldGame, Level* level, listFoes* listFoes) {
	bool flag = false;
	fieldGame->newArea = 0;
	for (int i = 2; i < fieldGame->heightCell - 2; i++) {
		for (int j = 2; j < fieldGame->widthCell - 2; j++) {
			if (*(fieldGame->matrix + i * fieldGame->widthCell + j) == 1) {
				if (*(fieldGame->matrix + i * fieldGame->widthCell + (j - 1)) == 0 && *(fieldGame->matrix + i * fieldGame->widthCell + (j + 1)) == 0) {
					if (checkFoe(fieldGame, j + 1, i, listFoes)) {
						paintingField(fieldGame, j + 1, i);
					}
					else if (checkFoe(fieldGame, j - 1, i, listFoes)) {
						paintingField(fieldGame, j - 1, i);
					}
					flag = true;
					break;
				}
				else if (*(fieldGame->matrix + (i - 1) * fieldGame->widthCell + j) == 0 && *(fieldGame->matrix + (i + 1) * fieldGame->widthCell + j) == 0) {
					if (checkFoe(fieldGame, j, i + 1, listFoes)) {
						paintingField(fieldGame, j, i + 1);
					}
					else if (checkFoe(fieldGame, j, i - 1, listFoes)) {
						paintingField(fieldGame, j, i - 1);
					}
					break;
					flag = true;
				}
			}
		}
		if (flag) break;
	}
	for (int i = 0; i < fieldGame->heightCell; i++) {
		for (int j = 0; j < fieldGame->widthCell; j++) {
			if (*(fieldGame->matrix + i * fieldGame->widthCell + j) == 1) {
				*(fieldGame->matrix + i * fieldGame->widthCell + j) = 2;
				fieldGame->newArea++;
			}
			else if (*(fieldGame->matrix + i * fieldGame->widthCell + j) == 3) {
				*(fieldGame->matrix + i * fieldGame->widthCell + j) = 0;
			}
		}
	}
	fieldGame->area += fieldGame->newArea;
	fieldGame->score += fieldGame->newArea;
}
void destructPlayer(FieldGame* fieldGame, Player* player) {
	for (int i = 0; i < fieldGame->heightCell; i++) {
		for (int j = 0; j < fieldGame->widthCell; j++) {
			if (*(fieldGame->matrix + i * fieldGame->widthCell + j) == 1) {
				*(fieldGame->matrix + i * fieldGame->widthCell + j) = 0;
			}
		}
	}
	SDL_Delay(500);
	player->lives--;
	*player = createPlayer(player->lives);
}
FieldState createFieldState() {
	FieldState fieldState;
	fieldState.x = 0;
	fieldState.y = 0;
	fieldState.w = FULLSCREEN_WIDTH;
	fieldState.h = 104;
	fieldState.r = 0;
	fieldState.g = 0;
	fieldState.b = 0;
	return fieldState;
}
Player createPlayer(int lives) {
	Player player;
	player.w = 10;
	player.h = 10;
	player.x = 0;
	player.y = 120;
	player.posMatrixX = 0;
	player.posMatrixY = 1;
	player.speed = 10;
	player.lives = lives;
	player.direction = -1;
	player.r = 28;
	player.g = 153;
	player.b = 51;

	return player;
}

Foe createFoe(FieldGame* fieldGame) {
	Foe foe;
	do {
		foe.x = rand() % (FULLSCREEN_WIDTH - 50) + 20;
		foe.y = rand() % (FULLSCREEN_HEIGHT - 200) + 130;
		foe.w = 10;
		foe.h = 10;
		foe.x = foe.x - foe.x % foe.w;
		foe.y = foe.y - foe.y % foe.h;
		foe.posMatrixX = (foe.x) / 10;
		foe.posMatrixY = (foe.y - 110) / 10;
	} while (*(fieldGame->matrix + foe.posMatrixY * fieldGame->widthCell + foe.posMatrixX) == 2); //Для того чтобы враг не попал внутрь закрашеной части
	foe.direction = rand() % 4;
	foe.speed = 10;
	foe.r = 100;
	foe.g = 100;
	foe.b = 100;

	return foe;
}
void deleteFoe(listFoes* listFoes, int index) {
	for (int i = index; i < listFoes->length - 1; i++) {
		listFoes->foes[i].x = listFoes->foes[i + 1].x;
		listFoes->foes[i].y = listFoes->foes[i + 1].y;
		listFoes->foes[i].posMatrixX = listFoes->foes[i + 1].posMatrixX;
		listFoes->foes[i].posMatrixY = listFoes->foes[i + 1].posMatrixY;
		listFoes->foes[i].direction = listFoes->foes[i + 1].direction;
	}
	listFoes->foes[listFoes->length - 1].x = -100;
	listFoes->foes[listFoes->length - 1].y = -100;
	listFoes->foes[listFoes->length - 1].posMatrixX = -100;
	listFoes->foes[listFoes->length - 1].posMatrixY = -100;
	listFoes->foes[listFoes->length - 1].direction = -100;
}
Records getFromFile() {
	Records records;
	records.length = 6;
	records.masRecords = (int*)malloc(records.length * sizeof(int));
	FILE* fileRecords = fopen("records.bin", "rt");
	if (fileRecords == NULL) {
		fileRecords = fopen("records.bin", "w+");
		int value = 0;
		for (int i = 0; i < records.length; i++) {
			fwrite(&value, sizeof(int), 1, fileRecords);
		}
		fclose(fileRecords);
		fileRecords = fopen("records.bin", "rt");
	}
	bool flag = false;
	for (int i = 0; i < records.length; i++) {
		fread(&records.masRecords[i], sizeof(int), 1, fileRecords);
		if (records.masRecords[i] == 0 && !flag) {
			records.top = i;
			flag = true;
		}
		if (records.length == i + 1 && !flag) records.top = records.length;
	}
	fclose(fileRecords);
	return records;
}
void writeInFile(Records* records, int index, int newScore) {
	FILE* fileRecords = fopen("records.bin", "w+");
	for (int i = 0; i < index; i++) {
		fwrite(&records->masRecords[i], sizeof(int), 1, fileRecords);
	}
	fwrite(&newScore, sizeof(int), 1, fileRecords);
	for (int i = index + 1; i < 6; i++) {
		fwrite(&records->masRecords[i], sizeof(int), 1, fileRecords);
	}
	fclose(fileRecords);
}
Bonuses createListBonuses() {
	Bonuses bonuses;
	bonuses.length = 6;
	bonuses.listBonuses = (Bonus*)malloc(bonuses.length * sizeof(Bonus));
	bonuses.top = -1;
	bonuses.time = 0;
	bonuses.interval = 2000;
	return bonuses;
}
void updateBonuses(Bonuses* bonuses, FieldGame* fieldGame) {
	if (bonuses->top + 1 != bonuses->length) {
		bonuses->time += 21;
		if (bonuses->time >= bonuses->interval) {
			bonuses->time = 0;
			bonuses->top++;
			bonuses->listBonuses[bonuses->top].typeBonus = rand() % 6;
			bonuses->listBonuses[bonuses->top].x = ((rand() % fieldGame->widthCell)+3) * 10;
			bonuses->listBonuses[bonuses->top].y = ((rand() % fieldGame->heightCell)+3) * 10 + 80;
			bonuses->listBonuses[bonuses->top].w = 30;
			bonuses->listBonuses[bonuses->top].h = 30;
		}
	}
}
Levels createLevels() {
	Levels levels;
	levels.length = 6;
	levels.masLevels = (Level*)malloc(levels.length * sizeof(Level));
	for (int i = 0; i < levels.length; i++)
		levels.masLevels[i].numberLevel = i + 1;
	return levels;
}
int checkNumberLevel(SDL_Event* event, Levels* levels, TextLevels* textLevels, Records* records) {
	for (int i = 0; i < levels->length; i++) {
		if (event->button.x >= textLevels->posValueLevels[i].x && event->button.y >= textLevels->posValueLevels[i].y && event->button.x <= textLevels->posValueLevels[i].x + textLevels->posValueLevels[i].w && event->button.y <= textLevels->posValueLevels[i].y + textLevels->posValueLevels[i].h) {
			if (i <= records->top) return i + 1;
		}
	}
	return 0;
}