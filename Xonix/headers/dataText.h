
//Данные о выводе текста на уровне
struct TextGame {
	SDL_Surface* textLives; //Вывод текста "Lives:"
	SDL_Rect posTextLives; //Позиция textLives

	SDL_Surface* valueLives; //Вывод числового значения "Lives:"
	SDL_Rect posValueLives; //Позиция valueLives

	SDL_Surface* textArea; //Вывод текста "Area:"
	SDL_Rect posTextArea; //Позиция textArea

	SDL_Surface* valueArea; //Вывод числового значения "Area:"
	SDL_Rect posValueArea; //Позиция valueArea

	SDL_Surface* textPersent; //Вывод текста "%"
	SDL_Rect posTextPersent; //Позиция textPersent

	SDL_Surface* textScore; //Вывод текста "Score:"
	SDL_Rect posTextScore; //Позиция textScore

	SDL_Surface* valueScore; //Вывод числового значения "Score:"
	SDL_Rect posValueScore; //Позиция valueScore

	SDL_Surface* textTime; //Вывод текста "Time:"
	SDL_Rect posTextTime; //Позиция textTime

	SDL_Surface* valueTime; //Вывод числового значения "Time:"
	SDL_Rect posValueTime; //Позиция valueTime
};
//Данные о выводе текста в меню рекордов
struct TextRecords {
	SDL_Surface* textRecord; //Вывод текста "RECORDS"
	SDL_Rect posTextRecord; //Позиция textRecord

	SDL_Surface* textLevel; //Вывод текста "Level"
	SDL_Rect posTextLevel; //Позиция textLevel

	SDL_Surface* keysRecord[6]; //Вывод массива числовых значений рекордов - номера уровней
	SDL_Rect posKeysRecord; //Позиция posKeysRecord первого элемента

	SDL_Surface* valuesRecord[6]; //Вывод массива числовых значений рекордов
	SDL_Rect posValuesRecord; //Позиция posTextRecord первого элемента
};
//Данные о выводе текста при выигрыше 
struct TextWin {
	SDL_Surface* textWin; //Вывод текста "You win!"
	SDL_Rect posTextWin; //Позиция textWin

	SDL_Surface* textScore; //Вывод текста "Score"
	SDL_Rect posTextScore; //Позиция textScore

	SDL_Surface* valueScore; //Вывод текста числового значения "Score"
	SDL_Rect posValueScore; //Позиция valueScore

	SDL_Surface* textBonus; //Вывод текста "Bonus"
	SDL_Rect posTextBonus; //Позиция textBonus

	SDL_Surface* valueBonus; //Вывод текста числового значения "Bonus"
	SDL_Rect posValueBonus; //Позиция valueBonus

	SDL_Surface* textTotal; //Вывод текста "Total"
	SDL_Rect posTextTotal; //Позиция textTotal

	SDL_Surface* valueTotal; //Вывод текста числового значения "Total"
	SDL_Rect posValueTotal; //Позиция valueTotal
};
//Данные о выводе текста в выборе уровней
struct TextLevels {
	SDL_Surface* textLevels; //Вывод текста "LEVELS"
	SDL_Rect posTextLevels; //Позиция textLevels

	SDL_Surface* valueLevels; //Значение (число) уровня
	SDL_Rect* posValueLevels; //Позиция valueLevels
};
