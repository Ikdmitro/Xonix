//Функции для рендера объектов

//Рендер игрока
void renderPlayer(Player* player);
//Рендер поля состояний
void renderFieldState(FieldState* fieldState);
//Рендер врагов
void renderFoes(listFoes* listFoes);
//Рендер игрового поля
void renderFieldGame(FieldGame fieldGame);
//Рендер текста с состояниями
void renderTextState(TextGame* textGame);
//Рендер стартового меню
void renderMenu(SDL_Renderer* renderer, Images* images);
//Рендер внутриигрового меню
void renderMenuInGame(SDL_Renderer* renderer, Images* images);
//Рендер таблицы рекордов
void renderRecords(TextRecords* textRecords, Records* records);
//Рендер бонусов
void renderBonuses(Bonuses* bonuses, Images* images);
//Рендер выбора уровней
void renderLevels(Levels* levels, TextLevels* textLevels, Records* records);
//Рендер проигрыша
void renderLose(Images* images);
//Рендер выигрыша
void renderWin(FieldGame* fieldGame, Player* player, Images* images);