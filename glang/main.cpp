#include "parse.h"
#include "Exception.h"

using namespace std;
void main(){
	parse *pa = NULL;
	Token * t = NULL;
	try {
		while (true) {
			string code;
			cin >> code;
			pa = new parse(code);
			while (true) {
				t = pa->getToken();
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
		if (t != NULL) {
			delete t;
		}
		if (pa != NULL) {
			delete pa;
		}
		e.print(cerr);
		cerr << endl << endl << "你必须处理上面的错误，运行才能继续" << endl;
		abort();
	}
	_CrtDumpMemoryLeaks();//检查内存泄漏
}