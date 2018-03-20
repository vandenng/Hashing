#ifndef MY_HASH_H
#define MY_HASH_H

#include "Superhero.h"
#include <iostream>
#include <vector>
#include <string>

#define SIZE 17011

/*******************************************************************************************
 *This class will store Superheros in an array of vectors. Each indecie is caclualted using
 *three hashing funciotns to eleminate the amount of collisions. Access to this data
 *structure will be insert, and get.
 *******************************************************************************************/
class Hash{
	public:
		/****************************************************************************
		*Insert will return ture if a collision occured, and false if it did not.
		*The superhero will be added into the data structure regardless.
 		****************************************************************************/
		bool insert(const Superhero & s){
			return insert(s,hash1(s));
		}

		/****************************************************************************
		*Get will return the superhero matching the given string. The string is the 
		*name of the superhero wished to locate.
 		****************************************************************************/
		Superhero & get(const std::string name){
			Superhero* s;
			for(int i = 0; i < SIZE; i++){
				for(unsigned int j = 0; j < arr[i].size(); j++){
					if(name.compare(arr[i].at(j).getName()) == 0){
						s = &arr[i].at(j);
						return *s;
					}
				}
			}
			std::cerr << "ERROR" << std::endl;
			exit(1);
		}
	private:
		std::vector<Superhero> arr[SIZE];
		bool collision = false; 

		/****************************************************************************
		*The bulk of the insert method is private so that the hashing is kept
		*unknowen.
 		****************************************************************************/ 
		bool insert(const Superhero & s, int loc){
			collision = false;
			
			if( arr[loc].size() > 1 )
				loc = hash2(s);
			if(arr[loc].size() > 1 )
				loc = hash3(s);
			
			arr[loc].insert(arr[loc].begin() + arr[loc].size(), s);
			
			if(arr[loc].size() > 1)
				collision = true;
 			
			return collision;
		}

		/****************************************************************************
		*This hash function will return teh page_id * the year of a superhero.
 		****************************************************************************/
		int hash1(const Superhero & s){
			return (s.getPage_Id() * s.getYear()) % SIZE;
		}

		/****************************************************************************
		*This hash function will take the nume of the superhero & multiply it by the
		*page id to get the index. 
 		****************************************************************************/
		unsigned int hash2(const Superhero & s){
			unsigned int val = 0;
			
			for(char ch: s.getName()){
				val += ch;
			}
			
			return (val +  s.getPage_Id()) % SIZE;
		}

		/****************************************************************************
		*This hash will start with a prime number and then multiply it by more prime
		*numbers & an urlslug.
 		****************************************************************************/
		unsigned int hash3(const Superhero & s){
			unsigned int val = 37;
			
			if(s.getAlive()){
				val = 3527;
			}

			for(char ch: s.getUrlslug()){
				val = (val * 19) ^ (ch * 76963);	
			}
			
 			return val % SIZE;
		}
};

#endif
