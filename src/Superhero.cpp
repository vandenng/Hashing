#include "Superhero.h"
#include <iostream>
#include <sstream>

/********************************************************************************************
*Take the input from the davabase.csv file and split it up into the designated state.
********************************************************************************************/
Superhero::Superhero(std::string *input){
	if(input[0].size() > 0){
		std::stringstream convert(input[0]);
		convert >> this->page_id;
	}

	this->name = input[1];
	this->urlslug = input[2];
	this->id = input[3];
	this->alignment = input[4];
	this->eye_color = input[5];
	this->hair_color = input[6];

	if(input[7].size() > 0)
		this->sex = input[7].at(0);

	this->gsm = input[8];

	if(input[9].size() > 0){
	 	if(input[9].at(0) == 'L')
			this->alive = true;
		else
			this->alive = false;
	}

	if(input[10].size() > 0){
		std::stringstream convert(input[10]);
		convert >> this->appearances;
	}

	this->first_appearance = input[11];

	if(input[12].size() > 0){
		std::stringstream convert(input[12]);
		convert >> this->year;
	}
}

/********************************************************************************************
*Will return the page_id of this Superhero.
********************************************************************************************/
int Superhero::getPage_Id() const{
	return this->page_id;
}

/********************************************************************************************
*Will return the name of this Superhero.
********************************************************************************************/
std::string Superhero::getName() const{
	return this->name;
}

/********************************************************************************************
*Will return the urlslug fo this Superhero.
********************************************************************************************/
std::string Superhero::getUrlslug() const{
	return this->urlslug;
}

/********************************************************************************************
*Will return the id of this Superhero.
********************************************************************************************/
std::string Superhero::getId() const{
	return this->id;
}

/********************************************************************************************
*Will return ths Alignment of this Superhero.
********************************************************************************************/
std::string Superhero::getAlignment() const{
	return this->alignment;
}

/********************************************************************************************
*Will return the eye color of this Superhero.
********************************************************************************************/
std::string Superhero::getEye_Color() const{
	return this->eye_color;
}

/********************************************************************************************
*Will return the hair color of this Superhero.
********************************************************************************************/
std::string Superhero::getHair_Color() const{
	return this->hair_color;
}

/********************************************************************************************
*Will return the sex of this Superhero.
********************************************************************************************/
char Superhero::getSex() const{
	return this->sex;
}

/********************************************************************************************
*Will return the gsm of this Superhero.
********************************************************************************************/
std::string Superhero::getGsm() const{
	return this->gsm;
}

/********************************************************************************************
*Will return the life status of this Superhero.
********************************************************************************************/
bool Superhero::getAlive() const{
	return this->alive;
}

/********************************************************************************************
*Will return the appearances of this Superhero.
********************************************************************************************/
int Superhero::getAppearances() const{
	return this->appearances;
}

/********************************************************************************************
*Will return the first appearance of this Superhero
********************************************************************************************/
std::string Superhero::getFirst_Appearance() const{
	return this->first_appearance;
}

/********************************************************************************************
*Will return the year of this Superhero.
********************************************************************************************/
int Superhero::getYear() const{
	return this->year;
}
