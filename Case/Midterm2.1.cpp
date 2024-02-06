#include "math.h"
#include <iostream>
#include "Repo.h"
#include "Case.h"
using namespace std;
int Case::numOfCase = 0;
float Repository::volOfCases = 0;
int main()
{
	Repository repo("Warehouse", 100);
	cout << Case::count() << endl; //0
	try {
		repo.add(new BrickCase("books", 0x000000, 5, 3.5, 4)); //5 x 3.5 x 4
		repo.add(new TubeCase("posters", 0x00ff00, 1, 3)); //radius=1, height=3
		repo.add(new PrismCase("toys", 0x800080, 4, 2)); //base=4, height=2
		repo.add(new BrickCase("jewels", 0xffff00, 2, 2, 2)); //2 x 2 x 2
		repo.add(new BrickCase("trinkets", 0x000080, 5, 1, 1)); //5 x 1 x 1
	}
	catch (Repository::CapacityError& e) {
		cout << e.what() << endl; //trinkets too large - only 4.8 free space
	}
	cout << repo;
	cout << Case::count() << endl; //4
	cout << repo.summaryVolume() << endl; //95.2
	repo.remove("toys");
	cout << Case::count() << endl; //3
	cout << repo.summaryVolume() << endl; //87.4
	try {
		cout << repo[1].getCapacity() << endl; //70.0
		cout << repo[5].getCapacity() << endl; //IndexError exception
	}
	catch (Repository::IndexError& e) {
		cout << e.what() << endl; //item no. 5 not found
	}
	repo.clear();
	cout << Case::count() << endl; //0
}


