#include "InventoryStack.h"
#include "iostream"
using namespace std;

int main() {
	Inventory inv;
	inv.push("a");
	inv.push("b");
	inv.push("c");
	inv.push("d");
	inv.printStack();
	inv.findTool("b");
	inv.printStack();

}