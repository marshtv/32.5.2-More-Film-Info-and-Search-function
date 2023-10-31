#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

void input_json_one_str(const std::string& _title, const std::string& _left_field, nlohmann::json& _dict) {
	std::cout << _title <<": -----------------------------------------------------" << std::endl;
	std::string _str;
	std::cout << "Input " << _left_field << ":";
	std::getline(std::ws(std::cin), _str);
	_dict = {
		{_left_field, _str}
	};
}

void input_json_year(const std::string& _title, nlohmann::json& _dict) {
	std::cout << _title <<": -----------------------------------------------------" << std::endl;
	int year;
	std::cout << "Input Year:";
	std::cin >> year;
	_dict = {
		{"Year", year}
	};
}

void input_json_str(const std::string& _title, const std::string& _left_field, nlohmann::json& _dict) {
	int count = 1;
	while (true) {
		std::cout << _title <<": -----------------------------------------------------" << std::endl;
		std::string _str;
		std::cout << "Input " << _left_field << " (or \"-1\" for exit):";
		std::cin >> _str;
		if (_str == "-1") {
			std::cout << "-----EXIT---------------------------------------------------------------------" << std::endl;
			break;
		} else {
			nlohmann::json temp = {
				{(_left_field + "_" + std::to_string(count)), _str}
			};
			_dict.push_back(temp);
		}
		count++;
	}
}

void input_json_pairs(const std::string& _title, nlohmann::json& _dict) {
	while (true) {
		std::cout << _title <<": -----------------------------------------------------" << std::endl;
		std::string first_name, last_name;
		std::cout << "Input actor's first name and last name (or \"-1\" for exit):";
		std::cin >> first_name >> last_name;
		if (first_name == "-1" || last_name == "-1") {
			std::cout << "-----EXIT---------------------------------------------------------------------" << std::endl;
			break;
		} else {
			nlohmann::json person = {
				{"First name", first_name},
				{"Last name",  last_name}
			};
			_dict.push_back(person);
		}
	}
}

void input_json_triple(const std::string& _title, nlohmann::json& _dict) {
	while (true) {
		std::cout << _title <<": -----------------------------------------------------" << std::endl;
		std::string first_name, last_name, character;
		std::cout 	<< "Input actor's \"first name\", \"last name\""
					<< "and his(her) \"character\" (or \"-1\" for exit):";
		std::cin >> first_name >> last_name;
		std::getline(std::ws(std::cin), character);
		if (first_name == "-1" || last_name == "-1" || character == "-1") {
			std::cout << "-----EXIT---------------------------------------------------------------------" << std::endl;
			break;
		} else {
			nlohmann::json actor = {
				{"First name", first_name},
				{"Last name",  last_name},
				{"Character", character}
			};
			_dict.push_back(actor);
		}
	}
}

void input_film_catalog_json(const std::string& _title, nlohmann::json& _film_catalog) {
	nlohmann::json _film_info, _film_year;
	input_json_year(_title, _film_year);
	_film_info.push_back(_film_year);

	nlohmann::json _film_studio;
	input_json_one_str(_title, "Cinema Studio", _film_studio);
	_film_info.push_back(_film_studio);

	nlohmann::json _film_genres;
	input_json_str(_title, "Genre", _film_genres);
	_film_info.push_back(_film_genres);

	nlohmann::json _film_directors;
	input_json_pairs(_title, _film_directors);
	_film_info.push_back(_film_directors);

	nlohmann::json _film_actors;
	input_json_triple(_title, _film_actors);
	_film_info.push_back(_film_actors);

	nlohmann::json _film_writers;
	input_json_pairs(_title, _film_writers);
	_film_info.push_back(_film_writers);

	nlohmann::json _film_producers;
	input_json_pairs(_title, _film_producers);
	_film_info.push_back(_film_producers);

	_film_catalog.push_back({_title, _film_info});
}

int main() {
	std::ofstream file("F:\\__C++\\Skillbox\\32 JSON\\32.5.2 More Film Info and Search function\\film_catalog.json");
	nlohmann::json film_catalog;

	input_film_catalog_json("Ace Ventura: Animal Detective", film_catalog);
	input_film_catalog_json("Mask", film_catalog);
	input_film_catalog_json("Ace Ventura 2: When Nature Calls", film_catalog);
	input_film_catalog_json("The Cable Guy", film_catalog);
	input_film_catalog_json("Liar Liar", film_catalog);

	file << film_catalog;
	std::cout << "File \"film_catalog.json\" is created and ready to load for analysing!" << std::endl;
	file.close();
}
