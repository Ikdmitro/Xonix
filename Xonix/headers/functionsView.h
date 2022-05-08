//������� ��� ������� ��������

//������ ������
void renderPlayer(Player* player);
//������ ���� ���������
void renderFieldState(FieldState* fieldState);
//������ ������
void renderFoes(listFoes* listFoes);
//������ �������� ����
void renderFieldGame(FieldGame fieldGame);
//������ ������ � �����������
void renderTextState(TextGame* textGame);
//������ ���������� ����
void renderMenu(SDL_Renderer* renderer, Images* images);
//������ �������������� ����
void renderMenuInGame(SDL_Renderer* renderer, Images* images);
//������ ������� ��������
void renderRecords(TextRecords* textRecords, Records* records);
//������ �������
void renderBonuses(Bonuses* bonuses, Images* images);
//������ ������ �������
void renderLevels(Levels* levels, TextLevels* textLevels, Records* records);
//������ ���������
void renderLose(Images* images);
//������ ��������
void renderWin(FieldGame* fieldGame, Player* player, Images* images);