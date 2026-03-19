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
	file >> actualLevel;
	file >> Boot;
	file >> RezPos.x;
	file >> RezPos.y;
	file >> DBUnlock;
	file >> FloatUnlock;

	if (actualLevel <= 0 || actualLevel > 3) {
		actualLevel = 1;
	}
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
	filename << pawn.pos.y - 200 << "\n";
	filename << z << "\n";
	filename << "0" << "\n";
	filename << pawn.Rez.x << "\n" << pawn.Rez.y << "\n";
	filename << pawn.canDB << "\n";
	filename << pawn.canFloat;
	filename.close();
}

void Global::reset() {
	std::ofstream filename;
	filename.open("save/Save.txt");
	filename << "0" << "\n";
	filename << "0" << "\n";
	filename << "0" << "\n";
	filename << "1" << "\n";
	filename << 0 << "\n" << 0 << "\n";
	filename << 0 << "\n" << 0;
	filename.close();
}