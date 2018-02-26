#include "NameSpaceStudy.h"


//定义一个命名空间
namespace spaceA{
	int g_a = 10;
}

namespace spaceB{
	int a = 20;
	namespace spaceC{
		struct  teacher
		{
			int id;
			char name[64];
		};
	}
	namespace spaceD{
		struct  teacher
		{
			int id;
			char name[64];
		};
	}
	using namespace spaceC;
}

void NameSpaceStudy::run(){
	//spaceB::spaceC::teacher t1;

	//using spaceB::spaceC::teacher;
	//teacher t1;

	//using namespace spaceB::spaceC;
	//teacher t1;

	//using namespace spaceB;
	//teacher t1;

	using namespace spaceA;

}