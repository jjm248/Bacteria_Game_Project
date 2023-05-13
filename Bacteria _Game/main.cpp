#include <doodle/doodle.hpp>
#include<iostream>
using namespace std;
using namespace doodle;
int count_num = 1;
class Stage1 {
	int finish_count = 0;
public:
	void init() {

	}
	void logic() {

	}
	void draw() {

	}
	int end() {
		return finish_count;
	}
};
class Stage2 {
	int finish_count = 0;
public:
	void init() {

	}
	void logic() {

	}
	void draw() {

	}
	int end() {
		return finish_count;
	}
};
class Stage3 {
	int finish_count = 0;
public:
	void init() {

	}
	void logic() {

	}
	void draw() {

	}
	int end() {
		return finish_count;
	}
};
class Stage4 {
	int finish_count = 0;
public:
	void init() {

	}
	void logic() {

	}
	void draw() {

	}
	int end() {
		return finish_count;
	}
};
class Stage5 {
	int finish_count = 0;
public:	
	void init() {

	}
	void logic() {

	}
	void draw() {

	}
	int end() {
		return finish_count;
	}
};
int main() {
	Stage1 stage1;
	stage1.init();
	Stage2 stage2;
	stage2.init();
	Stage3 stage3;
	stage3.init();
	Stage4 stage4;
	stage4.init();
	Stage5 stage5;
	stage5.init();
	create_window(720, 720);
	while (!is_window_closed()) {
		switch (count_num)
		{
		case 1:
			stage1.logic();
			stage1.draw();
			count_num += stage1.end();
			break;
		case 2:
			stage2.logic();
			stage2.draw();
			count_num += stage2.end();
			break;
		case 3:
			stage3.logic();
			stage3.draw();
			count_num += stage3.end();
			break;
		case 4:
			stage4.logic();
			stage4.draw();
			count_num += stage4.end();
			break;
		case 5:
			stage5.logic();
			stage5.draw();
			count_num += stage5.end();
			break;
		}
	}
	
}