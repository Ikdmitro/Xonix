//������� ������� � ����

//������ ���� - ��������� ����
void createMenu();
//���� ����
int startGame(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* renderer, Level* level);
//���� ��������
void checkRecords(SDL_Renderer* renderer);
//���� ������ ������
void choiceLevel(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* renderer);
//������� ������ �� ����������
void exitFromGame();