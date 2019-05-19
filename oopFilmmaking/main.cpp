#include <iostream>
#include  "film.h"
#include <fstream>
using namespace std;

int main()
{
	film F;
	//vector<personal> P;
	//F.read(cin);
	//film G("got", "aventura", 108, P);
	//G.print(cout);
	//cin >> F;
	//cout << F;


	//cin >> A;
	//cout << A;

	//freopen("personal.txt", "r", stdin);
	firmaDistributie<unsigned> f;
	f.read(cin);
	cout << "-------------------";
	f.print(cout);

	return 0;
}