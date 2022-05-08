//Функции создания текста и действий с ним

//Создание внутриигрового текста
TextGame createTextGame(Player* player, FieldGame* fieldGame);
//Обновление внутриигрового текста 
void updateTextGame(TextGame* textGame, FieldGame* fieldGame, Player* player);
//Создание текста в окне рекордов
TextRecords createTextRecords(Records* records);
//Инициализация всех картинок
void initImages(Images* images);
//Создание текста в выборе уровней
TextLevels createTextLevels(Levels* levels);
//Создание текста при выигрыше
TextWin createTextWin(FieldGame* fieldGame, Player* player);
