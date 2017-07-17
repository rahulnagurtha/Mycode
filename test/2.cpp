#include <bits/stdc++.h>

using namespace std;

enum note { middleC, Csharp, Cflat }; // Etc.


class Instrument {
public:
	virtual void play(note) const = 0;
	virtual string what() const = 0;
	// Assume this will modify the object:
	virtual void adjust(int) = 0;
};


class Wind : public Instrument {
public:
	void play(note) const {
		cout << "Wind::play" << endl;
	}
	string what() const { return "Wind"; }
	void adjust(int i) {}
};

class Percussion : public Instrument {
public:
	void play(note) const {
		cout << "Percussion::play" << endl;
	}
	string what() const { return "Percussion"; }
	void adjust(int) {}
};

class Stringed : public Instrument {
public:
	void play(note) const {
		cout << "Stringed::play" << endl;
	}
	string what() const { return "Stringed"; }
	void adjust(int) {}
};

class Brass : public Wind {
public:
	void play(note) const {
		cout << "Brass::play" << endl;
	}
	string what() const { return "Brass"; }
};

class Woodwind : public Wind {
public:
	void play(note) const {
		cout << "Woodwind::play" << endl;
	}
	string what() const { return "Woodwind"; }
};

void tune(Instrument& i) {
	i.play(middleC);
}


void f(Instrument& i) { i.adjust(1); }


Instrument* A[] = {
	new Wind,
	new Percussion,
	new Stringed,
	new Brass,
};

int main() {
	Wind flute;
	Percussion drum;
	Stringed violin;
	Brass flugelhorn;
	Woodwind recorder;
	tune(flute);
	tune(drum);
	tune(violin);
	tune(flugelhorn);
	tune(recorder);
	f(flugelhorn);
}