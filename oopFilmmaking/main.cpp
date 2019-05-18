#include <iostream>
#include  "film.h"
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

	actor A;
	actor B("mihai", "1234123", "got", "principal", 5000);
	regizor R("mihaita", "124514512", "got", 1000000);
	cout << R;
	cout << B;
	cin >> A;
	cout << A;
	return 0;
}