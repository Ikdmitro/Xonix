//Данные о картинках
struct Images {
	//Картинка-лого
	SDL_Texture* headImg;
	SDL_Rect destHeadImg;

	//Картинка "START"
	SDL_Texture* startImg;
	SDL_Rect destStartImg;

	//Картинка "RECORDS"
	SDL_Texture* recordsImg;
	SDL_Rect destRecordsImg;

	//Картинка "EXIT"
	SDL_Texture* exitImg;
	SDL_Rect destExitMenuImg;
	SDL_Rect destExitGameImg;

	//Картика "RETURN"
	SDL_Texture* returnImg;
	SDL_Rect destReturnImg;
	SDL_Rect destReturnLoseImg;

	//Картика "MENU"
	SDL_Texture* menuImg;
	SDL_Rect destMenuImg;
	SDL_Rect destMenuLoseImg;
	SDL_Rect destMenuWinImg;

	//Картика со стрелкой "Back"
	SDL_Texture* backImg;
	SDL_Rect destBackImg;

	//Картинка-бонус "liveBuff"
	SDL_Texture* lifeBuffImg;

	//Картинка-бонус "liveDebuff"
	SDL_Texture* lifeDebuffImg;

	//Картинка-бонус "timeBuff"
	SDL_Texture* timeBuffImg;

	//Картинка-бонус "timeDebuff"
	SDL_Texture* timeDebuffImg;

	//Картинка-бонус "scoreBuff"
	SDL_Texture* scoreBuffImg;

	//Картинка-бонус "scoreDebuff"
	SDL_Texture* scoreDebuffImg;

	//Картинка-поле для цифры уровня
	SDL_Texture* areaLevelImg;

	//Картинка замка для закрытого уровня
	SDL_Texture* lockLevelImg;
};
