#include "parse.h"
#include "Exception.h"

using namespace std;
void main(){
	
	try {
		while (true) {
			string code;
			cin >> code;
			parse pa(code);
			while (true) {
				Token * t = pa.getToken();
				if (t->type == _end) {
					delete t;
					t = NULL;
					break;
				}
				t->test_print(cout);
				delete t;
				t = NULL;
			}
		}
	}
	catch (Exception& e) {
		e.print(cerr);
		cerr << endl << endl << "����봦������Ĵ������в��ܼ���" << endl;
		abort();
	}
}