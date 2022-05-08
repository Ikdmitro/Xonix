//������ ������
struct Player {
	int x; //���������� �� x � ��������
	int y; //���������� �� y � ��������
	int posMatrixX; //���������� �� x � ������� FieldGame.matrix
	int posMatrixY; //���������� �� y � ������� FieldGame.matrix
	int w; //������ ������ � ��������
	int h; //������ ������ � ��������
	int speed; //�������� ������ � ��������
	int lives; //���������� ������ ������
	int direction; //����������� ������ 
	int r, g, b; //���� ������
};
//������ ��� ������ ������ 
struct Bonus {
	int x; //���������� �� x � ��������
	int y; //���������� �� y � ��������
	int w; //������ � ��������
	int h; //������ � ��������
	int typeBonus; //��� ������
		//�������� �������
	//0,1 - ����/������ �� ���� (� �������� 100 - 5000)
	//2,3 - ����/������ �� ����� (+-1)
	//4,5 - ����/������ �� ����� (+-15�)
};
//������ � �������� �������
struct Bonuses {
	Bonus* listBonuses; //������ ����� length �� �����, ������������ ����� (����������� ��� �������������� ������� �� ���� ����������)
	int length; //����� �������
	int top; //��������� ������������ �����
	int interval; //�������� ��������� ������� (� �������������)
	int time; //������� ����� �� ��������� (� �������������)
};
//������ � ��������
struct Records {
	int* masRecords; //������ �������� �������� �� �������
	int top; //��������� �� ������� � ����� ������
	int length;  //����� �������
};
//������ ���� � ����������
struct FieldState {
	int x; //���������� �� x
	int y; //���������� �� y
	int w; //������ ����
	int h; //������ ����
	int r, g, b; //���� ����
	int score; //��������� ����
};
//������ ����-������� �������� ����
struct FieldWrap {
	int x; //���������� �� x
	int y; //���������� �� y
	int w; //������ ���� � ��������
	int h; //������ ���� � ��������
	int widthCell; //
	int r, g, b; //���� ����
};
//������ �������� ����
struct FieldGame {
	int x; //���������� �� x � ��������
	int y; //���������� �� y � ��������
	int w; //������ ���� � ��������
	int h; //������ ���� � ��������
	int widthCell; //������ ���� � �������
	int heightCell; //������ ���� � �������
	int score; //��������� ����
	int* matrix; //��������� �� ������� �������� ����
	//�������� ��������� �������� ���� (�� ����������� �������������� ������ � ������):
	//0 - ������ �����
	//1 - ������ ��������� ������
	//2 - ������ ���������
	//3 - ������ ������������ � ������������ (�� �� ����������� ��� ����� ���������)
	int time; //����� � �������������
	int area; //������� ������������ ����
	int newArea; //����� ������� ������������ ����
	int areaWrap; //������� �����, ������������ ��� ����� ������� ������
	int r, g, b; //���� ����
};
//������ � ����� 
struct Foe {
	int x; //���������� �� x � ��������
	int y; //���������� �� y � ��������
	int posMatrixX; //���������� �� x � ������� FieldGame.matrix
	int posMatrixY; //���������� �� y � ������� FieldGame.matrix
	int w; //������ ����� � ��������
	int h; //������ ������ � ��������
	int direction; //����������� �� ��������� (0 - ����� �����, 1 - ������ �����, 2 - ������ ����, 3 - ����� ����)
	int speed; //�������� ����� �� ��������� � �������

	int r, g, b; //���� �����
};
//������ ������
struct listFoes {
	Foe* foes; //������ ������
	int length; //����� ������� ������
};

//������ � �������, ���������� ����� ������� ������
struct Area {
	int xCell; //���������� �� x � �������
	int yCell; //���������� �� y � �������
	int widthCell; //������ ���� � �������
	int heightCell; //������ ���� � �������
};
//������ � ������
struct Level {
	int numberLevel; //����� ������
	int numberFoes; //���������� ������
	Area* areas; //��������� �� ������ �� ����������� ��������
	int lengthAreas; //����� ������� � ���������
};
//������ � �������
struct Levels {
	Level* masLevels; //��������� �� ������ �� �� �������� ������� ������
	int length; // ����� �������
};