//Главные функции с меню

//Запуск игры - начальное меню
void createMenu();
//Окно игры
int startGame(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* renderer, Level* level);
//Окно рекордов
void checkRecords(SDL_Renderer* renderer);
//Окно выбора уровня
void choiceLevel(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* renderer);
//Функция выхода из приложения
void exitFromGame();