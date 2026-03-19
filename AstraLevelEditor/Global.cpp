#include "Global.h"
#include "Pawn.h"

Global::Global() {
	pos = {0, 0};
	Boot = true;
};
Global::~Global() {};

void Global::load() {
	std::ifstream file("save/Save.txt");
	if (!file) {
		std::ofstream Char_Pertama("save/Save.txt", std::ios::out);
		reset();
	}

	file >> pos.x;
	file >> pos.y;
	pos.y += 50;
	file >> actualLevel;
	file >> Boot;
}


void Global::save(Pawn& pawn, int z) {
	std::ifstream file("save/Save.txt");
	if (!file) {
		std::ofstream Char_Pertama("save/Save.txt", std::ios::out);
		reset();
	}

	std::ofstream filename;
	filename.open("save/Save.txt");
	filename << pawn.pos.x << "\n";
	filename << pawn.pos.y << "\n";
	filename << z << "\n";
	filename << "0" << "\n";
	filename.close();
}

void Global::reset() {
	std::ofstream filename;
	filename.open("save/Save.txt");
	filename << "0" << "\n";
	filename << "0" << "\n";
	filename << "scene actuel" << "\n";
	filename << "1" << "\n";
	filename.close();
}