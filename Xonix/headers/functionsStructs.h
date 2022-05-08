//������� �������� �������� � �������� � ����

//�������� ��������� � ������� � ������
Player createPlayer(int lives = 3);
//�������� ��������� � ������� � ������� ����
FieldGame createFieldGame(Level* level);
//�������� ��������� � ������� � ���� ���������
FieldState createFieldState();
//�������� ��������� � ������� ����-������� �������� ����
FieldWrap createFieldWrap();
//�������� �����
Foe createFoe(FieldGame *fieldGame);
//�������� ����� (��� �������������� ���� � ����������� ������)
void deleteFoe(listFoes* listFoes, int index);
//���������� ������ � ������� ���� (��� ��������� ��������� �������)
void updateFieldGame(FieldGame* fieldGame, Level* level, listFoes* listFoes);
//������������ ������� ��� �������� ������
void paintingField(FieldGame* fieldGame, int posX, int posY);
//����������� ������ (��� ������������ � ���������� ������)
void destructPlayer(FieldGame* fieldGame, Player* player);
//�������� �� ���������� � ������� �����
int checkFoe(FieldGame* fieldGame, int posX, int posY, listFoes* listFoes);
//�������� ��������� � ������� � �������
Bonuses createListBonuses();
//���������� ��������� � ������� � �������
void updateBonuses(Bonuses* bonuses, FieldGame* fieldGame);
//�������� ��������� � ������� � �������
Levels createLevels();
//������� ����� ��������
Records getFromFile();
//������ �������� � ����
void writeInFile(Records* records, int index, int newScore);
//�������� �� ����� ������
int checkNumberLevel(SDL_Event* event, Levels* levels, TextLevels* textLevels, Records* records);