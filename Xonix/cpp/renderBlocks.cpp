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

void createMenu() {
	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	setlocale(LC_ALL, "Russian");
	SDL_GetCurrentDisplayMode(0, &DM);
	FULLSCREEN_WIDTH = DM.w;
	FULLSCREEN_HEIGHT = DM.h;
	SDL_CreateWindowAndRenderer(FULLSCREEN_WIDTH, FULLSCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_SetWindowTitle(window, "Xonix");
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_Surface* cursorSurface = loadImgBmp("img/cursor.bmp");
	SDL_SetColorKey(cursorSurface, SDL_TRUE, SDL_MapRGB(cursorSurface->format, 255, 255, 255));
	SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, 0, 0);
	SDL_SetCursor(cursor);
	initImages(&images);
	renderMenu(renderer, &images);

	SDL_Event event;
	while (true)
	{
		SDL_PollEvent(&event);
		if ((event.button.button == SDL_SCANCODE_ESCAPE && event.type == SDL_KEYDOWN) || event.type == SDL_QUIT) exitFromGame();
		if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.x >= images.destExitMenuImg.x && event.button.x <= images.destExitMenuImg.x + images.destExitMenuImg.w && event.button.y >= images.destExitMenuImg.y && event.button.y <= images.destExitMenuImg.y + images.destExitMenuImg.h) {
				exitFromGame();
			}
			else if (event.button.x >= images.destStartImg.x && event.button.x <= images.destStartImg.x + images.destStartImg.w && event.button.y >= images.destStartImg.y && event.button.y <= images.destStartImg.y + images.destStartImg.h) {
				choiceLevel(window, screenSurface, renderer);
				renderClear(renderer);
				renderMenu(renderer, &images);
				event = {};
			}
			else if (event.button.x >= images.destRecordsImg.x && event.button.x <= images.destRecordsImg.x + images.destRecordsImg.w && event.button.y >= images.destRecordsImg.y && event.button.y <= images.destRecordsImg.y + images.destRecordsImg.h) {
				checkRecords(renderer);
				renderMenu(renderer, &images);
				event = {};
			}
		}
	}
}
int startGame(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* renderer, Level* level) {
	FieldGame fieldGame = createFieldGame(level);
	SDL_Event event;
	Player player = createPlayer();
	FieldState fieldState = createFieldState();
	listFoes listFoes;
	Bonuses bonuses = createListBonuses();
	listFoes.length = level->numberFoes;
	listFoes.foes = (Foe*)malloc(listFoes.length * sizeof(Foe));
	for (int i = 0; i < listFoes.length; i++) {
		listFoes.foes[i] = createFoe(&fieldGame);
	}
	TextGame textGame = createTextGame(&player, &fieldGame);
	while (true) {
		//Логика
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) exitFromGame();
		if (event.type == SDL_KEYDOWN) {
			if (event.button.button == SDL_SCANCODE_RIGHT) {
				if (!(*(fieldGame.matrix + player.posMatrixY * fieldGame.widthCell + player.posMatrixX) == 0 && player.direction == 1))
					player.direction = 0;
			}
			if (event.button.button == SDL_SCANCODE_LEFT) {
				if (!(*(fieldGame.matrix + player.posMatrixY * fieldGame.widthCell + player.posMatrixX) == 0 && player.direction == 0))
					player.direction = 1;
			}
			if (event.button.button == SDL_SCANCODE_UP) {
				if (!(*(fieldGame.matrix + player.posMatrixY * fieldGame.widthCell + player.posMatrixX) == 0 && player.direction == 3))
					player.direction = 2;
			}
			if (event.button.button == SDL_SCANCODE_DOWN) {
				if (!(*(fieldGame.matrix + player.posMatrixY * fieldGame.widthCell + player.posMatrixX) == 0 && player.direction == 2))
					player.direction = 3;
			}
		}
		if (player.lives == 0 || fieldGame.time <= 0)
		{
			renderLose(&images);
			while (true) {
				SDL_PollEvent(&event);
				if (event.type == SDL_QUIT) exitFromGame();
				if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
					if (event.button.x >= images.destMenuLoseImg.x && event.button.x <= images.destMenuLoseImg.x + images.destMenuLoseImg.w && event.button.y >= images.destMenuLoseImg.y && event.button.y <= images.destMenuLoseImg.y + images.destMenuLoseImg.h) {
						return 0;
					}
					else if (event.button.x >= images.destReturnLoseImg.x && event.button.x <= images.destReturnLoseImg.x + images.destReturnLoseImg.w && event.button.y >= images.destReturnLoseImg.y && event.button.y <= images.destReturnLoseImg.y + images.destReturnLoseImg.h) {
						return 1;
					}
				}
			}
		} //ПРОИГРЫШ
		updateBonuses(&bonuses, &fieldGame);
		switch (*(fieldGame.matrix + player.posMatrixY * fieldGame.widthCell + player.posMatrixX)) {
		case 0: *(fieldGame.matrix + player.posMatrixY * fieldGame.widthCell + player.posMatrixX) = 1;
			break;
		case 1: destructPlayer(&fieldGame, &player);
			break;
		case 2: updateFieldGame(&fieldGame, level, &listFoes);
			//Проверка на ВЫИГРЫШ
			if (fieldGame.area >= (fieldGame.widthCell * fieldGame.heightCell - fieldGame.areaWrap) * 0.75) {
				renderWin(&fieldGame, &player, &images);
				while (true) {
					SDL_PollEvent(&event);
					if (event.type == SDL_QUIT) exitFromGame();
					if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
						if (event.button.x >= images.destMenuWinImg.x && event.button.x <= images.destMenuWinImg.x + images.destMenuWinImg.w && event.button.y >= images.destMenuWinImg.y && event.button.y <= images.destMenuWinImg.y + images.destMenuWinImg.h) {
							break;
						}
					}
				}
				Records records = getFromFile();
				if (records.masRecords[level->numberLevel] < fieldGame.score) writeInFile(&records, level->numberLevel - 1, fieldGame.score + player.lives * 2000 + fieldGame.time / 10);
				return 0;
			}
		}
		updateTextGame(&textGame, &fieldGame, &player);
		switch (player.direction) {
		case 0:
			if (player.x + player.w < fieldGame.w + fieldGame.x) {
				player.x += player.speed;
				player.posMatrixX++;
			}
			break;
		case 1:
			if (player.x > fieldGame.x) {
				player.posMatrixX--;
				player.x -= player.speed;
			}
			break;
		case 2:
			if (player.y > fieldGame.y) {
				player.y -= player.speed;
				player.posMatrixY--;
			}
			break;
		case 3:
			if (player.y + player.h < fieldGame.y + fieldGame.h) {
				player.y += player.speed;
				player.posMatrixY++;
			}
			break;
		}
		for (int i = 0; i < listFoes.length; i++) {
			if (*(fieldGame.matrix + listFoes.foes[i].posMatrixY * fieldGame.widthCell + listFoes.foes[i].posMatrixX) == 2) {
				deleteFoe(&listFoes, i);
			}
			if (*(fieldGame.matrix + listFoes.foes[i].posMatrixY * fieldGame.widthCell + listFoes.foes[i].posMatrixX) == 1) {
				destructPlayer(&fieldGame, &player);
			}
			switch (listFoes.foes[i].direction) {
			case 0:
				if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY - 1) * fieldGame.widthCell + listFoes.foes[i].posMatrixX) == 2) {
					listFoes.foes[i].direction = 3;
				}
				else if (*(fieldGame.matrix + listFoes.foes[i].posMatrixY * fieldGame.widthCell + (listFoes.foes[i].posMatrixX + 1)) == 2) {
					listFoes.foes[i].direction = 1;
				}
				else if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY - 1) * fieldGame.widthCell + (listFoes.foes[i].posMatrixX + 1)) == 2) {
					listFoes.foes[i].direction = 2;
				}
				else {
					listFoes.foes[i].x += listFoes.foes[i].speed;
					listFoes.foes[i].y -= listFoes.foes[i].speed;
					listFoes.foes[i].posMatrixX++;
					listFoes.foes[i].posMatrixY--;
				}
				break;
			case 1:
				if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY - 1) * fieldGame.widthCell + listFoes.foes[i].posMatrixX) == 2) {
					listFoes.foes[i].direction = 2;
				}
				else if (*(fieldGame.matrix + listFoes.foes[i].posMatrixY * fieldGame.widthCell + (listFoes.foes[i].posMatrixX - 1)) == 2) {
					listFoes.foes[i].direction = 0;
				}
				else if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY - 1) * fieldGame.widthCell + (listFoes.foes[i].posMatrixX - 1)) == 2) {
					listFoes.foes[i].direction = 3;
				}
				else {
					listFoes.foes[i].x -= listFoes.foes[i].speed;
					listFoes.foes[i].y -= listFoes.foes[i].speed;
					listFoes.foes[i].posMatrixX--;
					listFoes.foes[i].posMatrixY--;
				}
				break;
			case 2:
				if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY + 1) * fieldGame.widthCell + listFoes.foes[i].posMatrixX) == 2) {
					listFoes.foes[i].direction = 1;
				}
				else if (*(fieldGame.matrix + listFoes.foes[i].posMatrixY * fieldGame.widthCell + (listFoes.foes[i].posMatrixX - 1)) == 2) {
					listFoes.foes[i].direction = 3;
				}
				else if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY + 1) * fieldGame.widthCell + (listFoes.foes[i].posMatrixX - 1)) == 2) {
					listFoes.foes[i].direction = 0;
				}
				else {
					listFoes.foes[i].x -= listFoes.foes[i].speed;
					listFoes.foes[i].y += listFoes.foes[i].speed;
					listFoes.foes[i].posMatrixX--;
					listFoes.foes[i].posMatrixY++;
				}
				break;
			case 3:
				if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY + 1) * fieldGame.widthCell + listFoes.foes[i].posMatrixX) == 2) {
					listFoes.foes[i].direction = 0;
				}
				else if (*(fieldGame.matrix + listFoes.foes[i].posMatrixY * fieldGame.widthCell + (listFoes.foes[i].posMatrixX + 1)) == 2) {
					listFoes.foes[i].direction = 2;
				}
				else if (*(fieldGame.matrix + (listFoes.foes[i].posMatrixY + 1) * fieldGame.widthCell + (listFoes.foes[i].posMatrixX + 1)) == 2) {
					listFoes.foes[i].direction = 1;
				}
				else {
					listFoes.foes[i].x += listFoes.foes[i].speed;
					listFoes.foes[i].y += listFoes.foes[i].speed;
					listFoes.foes[i].posMatrixX++;
					listFoes.foes[i].posMatrixY++;
				}
				break;
			}
		}
		for (int i = 0; i <= bonuses.top; i++) {
			if (player.x >= bonuses.listBonuses[i].x && player.y >= bonuses.listBonuses[i].y && player.x + player.w <= bonuses.listBonuses[i].x + bonuses.listBonuses[i].w && player.y + player.h <= bonuses.listBonuses[i].y + bonuses.listBonuses[i].h) {
				switch (bonuses.listBonuses[i].typeBonus) {
				case 0: player.lives++;
					break;
				case 1: player.lives--;
					break;
				case 2: fieldGame.time += 15000;
					break;
				case 3: fieldGame.time -= 15000;
					break;
				case 4: fieldGame.score += rand() % 9000 + 1000;
					break;
				case 5: fieldGame.score -= rand() % 9000 + 1000;
					if (fieldGame.score < 0) fieldGame.score = 0;
					break;
				}
				for (int j = i; j < bonuses.length - 1; j++) {
					bonuses.listBonuses[j] = bonuses.listBonuses[j + 1];
				}
				bonuses.top--;
			}
		}

		//Рендер
		renderFieldGame(fieldGame);
		renderPlayer(&player);
		renderFieldState(&fieldState);
		renderFoes(&listFoes);
		renderTextState(&textGame);
		renderBonuses(&bonuses, &images);
		renderPresent(renderer);
		SDL_Delay(21);
		fieldGame.time -= 26;

		if (event.button.button == SDL_SCANCODE_ESCAPE && event.type != SDL_KEYDOWN) {
			renderMenuInGame(renderer, &images);
			while (true) {
				SDL_PollEvent(&event);
				if (event.type == SDL_QUIT) exitFromGame();
				if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
					if (event.button.x >= images.destExitGameImg.x && event.button.x <= images.destExitGameImg.x + images.destExitGameImg.w && event.button.y >= images.destExitGameImg.y && event.button.y <= images.destExitGameImg.y + images.destExitGameImg.h) {
						exitFromGame();
					}
					else if (event.button.x >= images.destMenuImg.x && event.button.x <= images.destMenuImg.x + images.destMenuImg.w && event.button.y >= images.destMenuImg.y && event.button.y <= images.destMenuImg.y + images.destMenuImg.h) {
						return 0;
					}
					else if (event.button.x >= images.destReturnImg.x && event.button.x <= images.destReturnImg.x + images.destReturnImg.w && event.button.y >= images.destReturnImg.y && event.button.y <= images.destReturnImg.y + images.destReturnImg.h) {
						break;
					}
				}
			}
		}
	}
}
void checkRecords(SDL_Renderer* renderer) {
	setRenderColor(renderer, 0, 162, 232, 1);
	renderClear(renderer);
	Records records = getFromFile();
	TextRecords textRecords = createTextRecords(&records);
	renderRecords(&textRecords, &records);
	renderCopy(renderer, images.backImg, NULL, &images.destBackImg);
	renderPresent(renderer);
	SDL_Event event;
	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) exitFromGame();
		if (event.button.button == SDL_SCANCODE_ESCAPE && event.type == SDL_KEYUP) return;
		else if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.x >= images.destBackImg.x && event.button.x <= images.destBackImg.x + images.destBackImg.w && event.button.y >= images.destBackImg.y && event.button.y <= images.destBackImg.y + images.destBackImg.h) {
				return;
			}
		}
	}
}
void choiceLevel(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* renderer) {
	setRenderColor(renderer, 0, 162, 232, 1);
	renderClear(renderer);
	Levels levels = createLevels();
	Records records = getFromFile();
	TextLevels textLevels = createTextLevels(&levels);
	SDL_Event event;
	renderCopy(renderer, images.backImg, NULL, &images.destBackImg);
	renderLevels(&levels, &textLevels, &records);
	renderPresent(renderer);
	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) exitFromGame();
		if (event.button.button == SDL_SCANCODE_ESCAPE && event.type == SDL_KEYUP) return;
		else if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.x >= images.destBackImg.x && event.button.x <= images.destBackImg.x + images.destBackImg.w && event.button.y >= images.destBackImg.y && event.button.y <= images.destBackImg.y + images.destBackImg.h) {
				return;
			}
			else {
				int currentLevel = checkNumberLevel(&event, &levels, &textLevels, &records);
				if (currentLevel) {
					int isReturn;
					do {
						isReturn = startGame(window, screenSurface, renderer, &levels.masLevels[currentLevel - 1]);
					} while (isReturn);
					levels = createLevels();
					records = getFromFile();
					textLevels = createTextLevels(&levels);
					setRenderColor(renderer, 0, 162, 232, 1);
					renderClear(renderer);
					renderCopy(renderer, images.backImg, NULL, &images.destBackImg);
					renderLevels(&levels, &textLevels, &records);
					renderPresent(renderer);
					event = {};
				}
			}
		}
	}
}
void exitFromGame() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(1);
}