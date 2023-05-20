#include <doodle/doodle.hpp>
#include <conio.h>
#include<windows.h>
#include <string>
#include <exception>
#include <iostream>
using namespace std;
using namespace doodle;
int Space1[720];
int Space2[720];
int count_num = 2;
int count_heart = 0;  
int x = -20;
int y = 340;
class Stage1 {
	
	int finish_count = 0;
public:
	void init() {

	}
	void logic() {
		//�̰��� ĳ���ͶǴ� Ű���带 �̿��� ������
	}
	void draw() {
		//�̰��� �������� ��� ĳ���ͻ���
	}
	int end() {
		return finish_count;
	}
};

class Stage2 {
	int finish_count = 0;
	Image orangeHero;
	Image Background;
	Image gastric;
	Image heart;
public:
	void init() {
		Background = Image("./Game_Stage/Stage1_Background.png");
		gastric = Image("./Game_Stage/gastric_juice.png");
		heart = Image("./Game_Stage/heart.png");
		orangeHero = Image("./Game characters/germ_1.png");
	}
	void logic() {
		//�̰��� ĳ���ͶǴ� Ű���带 �̿��� ������
		switch (_getch()) {
		case 75:
			x -= 1;
			draw();
			break;
		case 77:
			x += 1;
			draw();
			break;
		}
		while (count_heart == 10) {
			y -= 1;
			draw();
			if (y == -350) {

			}
		}
		if (count_heart == 10) {
			finish_count += 1;
		}
	}
	void draw() {
		//�̰��� �������� ��� ĳ���ͻ���
		draw_image(Background, -360,360, 720, 720);
		draw_image(orangeHero, Space1[x],-300, 50, 50);
		draw_image(gastric, rand() % 360, y, 50, 50);
		draw_image(heart, rand() % 360, y, 50, 50);
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
		//�̰��� ĳ���ͶǴ� Ű���带 �̿��� ������
	}
	void draw() {
		//�̰��� �������� ��� ĳ���ͻ���
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
		//�̰��� ĳ���ͶǴ� Ű���带 �̿��� ������
	}
	void draw() {
		//�̰��� �������� ��� ĳ���ͻ���
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
		//�̰��� ĳ���ͶǴ� Ű���带 �̿��� ������
	}
	void draw() {
		//�̰��� �������� ��� ĳ���ͻ��� 
	}
	int end() {
		return finish_count;
	}
};
//���������� �Ѿ�°� �ǵ帱 �ʿ����
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
		update_window();
		clear_background(HexColor{ 0xFFFFFFFF });
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