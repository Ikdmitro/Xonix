//������� �������� ������ � �������� � ���

//�������� �������������� ������
TextGame createTextGame(Player* player, FieldGame* fieldGame);
//���������� �������������� ������ 
void updateTextGame(TextGame* textGame, FieldGame* fieldGame, Player* player);
//�������� ������ � ���� ��������
TextRecords createTextRecords(Records* records);
//������������� ���� ��������
void initImages(Images* images);
//�������� ������ � ������ �������
TextLevels createTextLevels(Levels* levels);
//�������� ������ ��� ��������
TextWin createTextWin(FieldGame* fieldGame, Player* player);
