//������ � ���������
struct Images {
	//��������-����
	SDL_Texture* headImg;
	SDL_Rect destHeadImg;

	//�������� "START"
	SDL_Texture* startImg;
	SDL_Rect destStartImg;

	//�������� "RECORDS"
	SDL_Texture* recordsImg;
	SDL_Rect destRecordsImg;

	//�������� "EXIT"
	SDL_Texture* exitImg;
	SDL_Rect destExitMenuImg;
	SDL_Rect destExitGameImg;

	//������� "RETURN"
	SDL_Texture* returnImg;
	SDL_Rect destReturnImg;
	SDL_Rect destReturnLoseImg;

	//������� "MENU"
	SDL_Texture* menuImg;
	SDL_Rect destMenuImg;
	SDL_Rect destMenuLoseImg;
	SDL_Rect destMenuWinImg;

	//������� �� �������� "Back"
	SDL_Texture* backImg;
	SDL_Rect destBackImg;

	//��������-����� "liveBuff"
	SDL_Texture* lifeBuffImg;

	//��������-����� "liveDebuff"
	SDL_Texture* lifeDebuffImg;

	//��������-����� "timeBuff"
	SDL_Texture* timeBuffImg;

	//��������-����� "timeDebuff"
	SDL_Texture* timeDebuffImg;

	//��������-����� "scoreBuff"
	SDL_Texture* scoreBuffImg;

	//��������-����� "scoreDebuff"
	SDL_Texture* scoreDebuffImg;

	//��������-���� ��� ����� ������
	SDL_Texture* areaLevelImg;

	//�������� ����� ��� ��������� ������
	SDL_Texture* lockLevelImg;
};
