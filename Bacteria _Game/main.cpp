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
		//이곳에 캐릭터또는 키보드를 이용한 움직임
	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
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
		//이곳에 캐릭터또는 키보드를 이용한 움직임
	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
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
		//이곳에 캐릭터또는 키보드를 이용한 움직임
	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
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
		//이곳에 캐릭터또는 키보드를 이용한 움직임
	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
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
		//이곳에 캐릭터또는 키보드를 이용한 움직임
	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진 
	}
	int end() {
		return finish_count;
	}
};
//스테이지를 넘어가는곳 건드릴 필요없음
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