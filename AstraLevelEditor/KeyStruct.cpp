#include "KeyStruct.h"

keys::keys() {
	myKeys = nullptr;
}

keys::~keys() {
	delete myKeys;
	myKeys = nullptr;
}

void keys::initKeys(const bool* _keys) {
	myKeys = _keys;
}