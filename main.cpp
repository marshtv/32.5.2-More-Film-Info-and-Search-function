#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

std::string input_title() {
	std::cout << "***************************" << std::endl;
	std::string _title;
	std::cout << "Input title:";
	std::getline(std::ws(std::cin), _title);
	return _title;
}

void input_json_one_str(const std::string& _title, const std::string& _left_field, nlohmann::json& _dict) {
	std::cout << _title << std::endl;
	for (int i = 0; i < _title.length(); ++i) {
		std::cout << "-";
	}
	std::cout << std::endl;
	std::string _str;
	std::cout << "Input " << _left_field << ":";
	std::getline(std::ws(std::cin), _str);
	_dict = {
		{_left_field, _str}
	};
}

void input_json_year(const std::string& _title, nlohmann::json& _dict) {
	std::cout << _title << std::endl;
	for (int i = 0; i < _title.length(); ++i) {
		std::cout << "-";
	}
	std::cout << std::endl;
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
		std::cout << _title << std::endl;
		for (int i = 0; i < _title.length(); ++i) {
			std::cout << "-";
		}
		std::cout << std::endl;
		std::string _str;
		std::cout << "Input " << _left_field << " (or \"-1\" for exit):";
		std::getline(std::ws(std::cin),_str);
		if (_str == "-1") {
			break;
		} else {
			if (count > 1) {
				nlohmann::json temp = {
					{(_left_field + "_" + std::to_string(count)), _str}
				};
				_dict.push_back(temp);
			} else {
				nlohmann::json temp = {
					{_left_field, _str}
				};
				_dict.push_back(temp);
			}
		}
		count++;
	}
}

void input_json_pairs(const std::string& _title, const std::string& _left_field, nlohmann::json& _dict) {
	int count = 1;
	while (true) {
		std::cout << _title<< std::endl;
		for (int i = 0; i < _title.length(); ++i) {
			std::cout << "-";
		}
		std::cout << std::endl;
		std::string first_name, last_name;
		std::cout << "Input " << _left_field << "'s first name and last name (or \"-1\" for exit):" << std::endl;
		std::cout << "First name:";
		std::getline(std::ws(std::cin), first_name);
		if (first_name == "-1") {
			break;
		}
		std::cout << "Last name:";
		std::getline(std::ws(std::cin), last_name);
		if (last_name == "-1") {
			break;
		}
		nlohmann::json person = {
			{"First name", first_name},
			{"Last name",  last_name}
		};
		if (count == 1)
			_dict.push_back({_left_field, person});
		else
			_dict.push_back({(_left_field + "_" + std::to_string(count)), person});
		count++;
	}
}

void input_json_triple(const std::string& _title, const std::string& _left_field, nlohmann::json& _dict) {
	int count = 1;
	while (true) {
		std::cout << _title << std::endl;
		for (int i = 0; i < _title.length(); ++i) {
			std::cout << "-";
		}
		std::cout << std::endl;
		std::string first_name, last_name, character;
		std::cout 	<< "Input " << _left_field << R"('s "first name", "last name")"
					<< R"(and his(her) "character" (or "-1" for exit):)" << std::endl;
		std::cout << "First name:";
		std::getline(std::ws(std::cin), first_name);
		if (first_name == "-1") {
			break;
		}
		std::cout << "Last name:";
		std::getline(std::ws(std::cin), last_name);
		if (last_name == "-1") {
			break;
		}
		std::cout << "Character:";
		std::getline(std::ws(std::cin), character);
		if (character == "-1") {
			break;
		}
		nlohmann::json temp = {
			{"First name", first_name},
			{"Last name",  last_name},
			{"Character", character}
		};
		if (count == 1)
			_dict.push_back({_left_field, temp});
		else
			_dict.push_back({(_left_field + "_" + std::to_string(count)), temp});
		count++;
	}
}

void input_film_catalog_json(nlohmann::json& _film_catalog) {
	nlohmann::json _film_info, _film_year;
	std::string _title = input_title();

	input_json_year(_title, _film_year);
	_film_info.push_back(_film_year);

	nlohmann::json _film_country;
	input_json_str(_title, "Country", _film_country);
	_film_info.push_back({"Countries", _film_country});

	nlohmann::json _film_studio;
	input_json_str(_title, "Cinema Studio", _film_studio);
	_film_info.push_back({"Cinema Studios", _film_studio});

	nlohmann::json _film_genres;
	input_json_str(_title, "Genre", _film_genres);
	_film_info.push_back({"Genres", _film_genres});

	nlohmann::json _film_directors;
	input_json_pairs(_title, "Director", _film_directors);
	_film_info.push_back({"Directors", _film_directors});

	nlohmann::json _film_actors;
	input_json_triple(_title, "Actor", _film_actors);
	_film_info.push_back({"Actors", _film_actors});

	nlohmann::json _film_writers;
	input_json_pairs(_title, "Writer", _film_writers);
	_film_info.push_back({"Writers", _film_writers});

	nlohmann::json _film_producers;
	input_json_pairs(_title, "Producer", _film_producers);
	_film_info.push_back({"Producers", _film_producers});

	_film_catalog.push_back({_title, _film_info});
}

int main() {
	std::ofstream file("film_catalog.json");
	nlohmann::json film_catalog;

	input_film_catalog_json(film_catalog);
	/*input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);*/

	file << film_catalog;
	std::cout << "File \"film_catalog.json\" is created and ready to load for analysing!" << std::endl;
	file.close();
}
