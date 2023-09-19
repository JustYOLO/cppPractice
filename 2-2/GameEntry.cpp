#include <iostream>
#include <string>
using std::string;

class GameEntry {
    public:
        GameEntry(const string& n = "", int s = 0);
        string getName() const;
        int getScore() const;
    private:
        string name;
        int score;
};

class Scores {
    public:
        Scores(int maxEnt = 10);
        ~Scores();
        void add(const GameEntry& e);
        GameEntry remove(int i) throw(IndexOutOfBounds);
    private:
        int maxEntries;
        int numEntries;
        GameEntry* entries; // make a GameEntry Array
};

GameEntry::GameEntry(const string& n, int s):
name(n), score(s) {}

string GameEntry::getName() const
{ return name; }

int GameEntry::getScore() const 
{ return score; }

Scores::Scores(int maxEnt) // constructor
{
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}
Scores::~Scores() // destructor
{
    delete[] entries;
}