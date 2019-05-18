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

	actor A;
	actor B("mihai", "1234123", "got", "principal", 5000);
	regizor R("mihaita", "124514512", "got", 1000000);
	personalTehnic P("mitza", "1244514", "got", "efecte speciale", 2);
	cout << R;
	cout << "\n";
	cout << B;
	cout << "\n";
	//cin >> A;
	//cout << A;
	cout << P;
	personal* p;
	p = &R;
	regizor *S;
	S = (regizor*)p;
	cout << *S;
	freopen("personal.txt", "r", stdin);
	cin >> F;
	cout << F;
	return 0;
}