#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

// Певый этап - формирование базы данных о фильмах.
/*std::string input_title() {
	std::cout << "Next Film Info ****************" << std::endl;
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
		if (_str == "-1")
			break;
		else {
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
		if (first_name == "-1")
			break;
		std::cout << "Last name:";
		std::getline(std::ws(std::cin), last_name);
		if (last_name == "-1")
			break;
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
		if (first_name == "-1")
			break;
		std::cout << "Last name:";
		std::getline(std::ws(std::cin), last_name);
		if (last_name == "-1")
			break;
		std::cout << "Character:";
		std::getline(std::ws(std::cin), character);
		if (character == "-1")
			break;
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
}*/

// Второй этап - анализ базы данных.
struct Actor_character {
	std::string film_title;
	std::string character;
};

int main() {
	nlohmann::json film_catalog;
	// Заполнение базы данных путём ввода.
	/*std::ofstream file("film_catalog.json");

	input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);
	input_film_catalog_json(film_catalog);

	file << film_catalog;
	std::cout << "File \"film_catalog.json\" is created and ready to load for analysing!" << std::endl;
	file.close();*/

	// Реализация анализа БД о фильмах путём поиска по актёрам.
	std::ifstream bd_file("film_catalog.json");
	if (bd_file.is_open()) {
		bd_file >> film_catalog;
		bd_file.close();
	} else {
		std::cout << "No file exist." << std::endl;
		return 0;
	}

	while (true) {
		std::string first_name, last_name;
		std::cout << "---------------------------------------------------------------------" << std::endl;
		std::cout << "Input actor's First name and Last name for search (or \"-1\" for EXIT):" << std::endl;
		std::cout << "---------------------------------------------------------------------" << std::endl;
		std::cout << "First name:";
		std::getline(std::ws(std::cin), first_name);
		if (first_name == "-1") {
			std::cout << "---Exit---" << std::endl;
			break;
		}
		std::cout << "Last name:";
		std::getline(std::ws(std::cin), last_name);
		if (last_name == "-1") {
			std::cout << "---Exit---" << std::endl;
			break;
		}
		std::vector<Actor_character> actor_characters;
		for (int i = 0; i < 5; ++i) {
			for (auto it = film_catalog[i][1][5][1].begin();
				it != film_catalog[i][1][5][1].end(); ++it) {
				nlohmann::json actor_json = *it;
				if (actor_json[1]["First name"] == first_name &&
					actor_json[1]["Last name"] == last_name) {
					Actor_character actorCharacter;
					actorCharacter.film_title = film_catalog[i][0];
					actorCharacter.character = actor_json[1]["Character"];
					actor_characters.push_back(actorCharacter);
				}
			}
		}
		if (actor_characters.empty()) {
			std::cout << "No one actors was found! Try to change name!" << std::endl;
			std::cout << "--------------------------------------------" << std::endl;
		}
		else {
			std::cout << "Result of search:" << std::endl;
			for (int i = 0; i < actor_characters.size(); ++i) {
				std::cout << "----";
				for (int j = 0; j < actor_characters[i].film_title.length(); ++j) {
					std::cout << "-";
				}
				std::cout << std::endl;
				std::cout << i + 1 << ". " << actor_characters[i].film_title << ":" << std::endl;
				std::cout << actor_characters[i].character << ";" << std::endl;
			}
		}
	}
}