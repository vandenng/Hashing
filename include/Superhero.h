#include <iostream>

#ifndef SUPERHERO_H
#define SUPERHERO_H
class Superhero{
	public:
		Superhero(std::string input[]);
		int getPage_Id() const;
		std::string getName() const;
		std::string getUrlslug() const;
		std::string getId() const;
		std::string getAlignment() const;
		std::string  getEye_Color() const;
		std::string getHair_Color() const;
		char getSex() const;
		std::string getGsm() const;
		bool getAlive() const;
		int getAppearances() const;
		std::string getFirst_Appearance() const;
		int getYear() const;

	private:
		int page_id;
		std::string name;
		std::string urlslug;
		std::string id;
		std::string alignment;
		std::string eye_color;
		std::string hair_color;
		char sex;
		std::string gsm;
		bool alive;
		int appearances;
		std::string first_appearance;
		int year;
};

#endif
