#pragma once
#include <list>
#include <string>
using namespace std;

class Tool {
private:
	string name;
public:
	Tool(string nameIn) {
		name = nameIn;
	}
	string getName() {
		return name;
	 }
};

class Inventory {
private:
	list<Tool> tools;
public:
	Inventory() {
		Tool tool1{ "hammer" };
		Tool tool2{ "saw" };
		Tool tool3{ "screwdriver" };
		Tool tool4{ "drill" };
		tools.push_back(tool1);
		tools.push_back(tool2);
		tools.push_back(tool3);
		tools.push_back(tool4);
	}

	Tool findTool(string toolName) {
		cout << tools.begin().getName();
	}
};