//Функции создания структур и действий с ними

//Создание структуры с данными о игроке
Player createPlayer(int lives = 3);
//Создание структуры с данными о игровом поле
FieldGame createFieldGame(Level* level);
//Создание структуры с данными о поле состояний
FieldState createFieldState();
//Создание структуры с данными поля-границы игрового поля
FieldWrap createFieldWrap();
//Создание врага
Foe createFoe(FieldGame *fieldGame);
//Удаление врага (для предотвращения бага с неподвижным врагом)
void deleteFoe(listFoes* listFoes, int index);
//Обновление данных о игровом поле (при отрезании замкнутой области)
void updateFieldGame(FieldGame* fieldGame, Level* level, listFoes* listFoes);
//Закрашивание области при отсутвии врагов
void paintingField(FieldGame* fieldGame, int posX, int posY);
//Уничтожение игрока (его пересоздание с потерянной жизнью)
void destructPlayer(FieldGame* fieldGame, Player* player);
//Проверка на нахождение в области врага
int checkFoe(FieldGame* fieldGame, int posX, int posY, listFoes* listFoes);
//Создание структуры с данными о бонусах
Bonuses createListBonuses();
//Обновление структуры с данными о бонусах
void updateBonuses(Bonuses* bonuses, FieldGame* fieldGame);
//Создание структуры с данными о уровнях
Levels createLevels();
//Парсинг файла рекордов
Records getFromFile();
//Запись рекордов в файл
void writeInFile(Records* records, int index, int newScore);
//Проверка на номер уровня
int checkNumberLevel(SDL_Event* event, Levels* levels, TextLevels* textLevels, Records* records);