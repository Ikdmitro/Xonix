
//������ � ������ ������ �� ������
struct TextGame {
	SDL_Surface* textLives; //����� ������ "Lives:"
	SDL_Rect posTextLives; //������� textLives

	SDL_Surface* valueLives; //����� ��������� �������� "Lives:"
	SDL_Rect posValueLives; //������� valueLives

	SDL_Surface* textArea; //����� ������ "Area:"
	SDL_Rect posTextArea; //������� textArea

	SDL_Surface* valueArea; //����� ��������� �������� "Area:"
	SDL_Rect posValueArea; //������� valueArea

	SDL_Surface* textPersent; //����� ������ "%"
	SDL_Rect posTextPersent; //������� textPersent

	SDL_Surface* textScore; //����� ������ "Score:"
	SDL_Rect posTextScore; //������� textScore

	SDL_Surface* valueScore; //����� ��������� �������� "Score:"
	SDL_Rect posValueScore; //������� valueScore

	SDL_Surface* textTime; //����� ������ "Time:"
	SDL_Rect posTextTime; //������� textTime

	SDL_Surface* valueTime; //����� ��������� �������� "Time:"
	SDL_Rect posValueTime; //������� valueTime
};
//������ � ������ ������ � ���� ��������
struct TextRecords {
	SDL_Surface* textRecord; //����� ������ "RECORDS"
	SDL_Rect posTextRecord; //������� textRecord

	SDL_Surface* textLevel; //����� ������ "Level"
	SDL_Rect posTextLevel; //������� textLevel

	SDL_Surface* keysRecord[6]; //����� ������� �������� �������� �������� - ������ �������
	SDL_Rect posKeysRecord; //������� posKeysRecord ������� ��������

	SDL_Surface* valuesRecord[6]; //����� ������� �������� �������� ��������
	SDL_Rect posValuesRecord; //������� posTextRecord ������� ��������
};
//������ � ������ ������ ��� �������� 
struct TextWin {
	SDL_Surface* textWin; //����� ������ "You win!"
	SDL_Rect posTextWin; //������� textWin

	SDL_Surface* textScore; //����� ������ "Score"
	SDL_Rect posTextScore; //������� textScore

	SDL_Surface* valueScore; //����� ������ ��������� �������� "Score"
	SDL_Rect posValueScore; //������� valueScore

	SDL_Surface* textBonus; //����� ������ "Bonus"
	SDL_Rect posTextBonus; //������� textBonus

	SDL_Surface* valueBonus; //����� ������ ��������� �������� "Bonus"
	SDL_Rect posValueBonus; //������� valueBonus

	SDL_Surface* textTotal; //����� ������ "Total"
	SDL_Rect posTextTotal; //������� textTotal

	SDL_Surface* valueTotal; //����� ������ ��������� �������� "Total"
	SDL_Rect posValueTotal; //������� valueTotal
};
//������ � ������ ������ � ������ �������
struct TextLevels {
	SDL_Surface* textLevels; //����� ������ "LEVELS"
	SDL_Rect posTextLevels; //������� textLevels

	SDL_Surface* valueLevels; //�������� (�����) ������
	SDL_Rect* posValueLevels; //������� valueLevels
};
