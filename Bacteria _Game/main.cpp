#include <doodle/doodle.hpp>
#include <conio.h>
#include<windows.h>
#include <string>
#include <exception>
#include <iostream>

using namespace std;
using namespace doodle;

int count_num = 1;
double x = -20;
double y = -300;
	
	
	class Stage1 {

		int finish_count = 0;
	public:
		Image germ;
		Image d_germ;
		Image over;
		Image Back;
		Image next;
		Image Back_maxe;
		Image Back_maxe2;
		Image Back_maxe3;
		Image Back_maxe4;
		Image Back_maxe5;

		bool is_trigger = false;

		void init() {

			germ = Image{ "./Game characters/germ_1.png" };            // 병균 캐릭터
			d_germ = Image{ "./Game characters/dead_germ.png" };       // 사망한 병균 캐릭터
			over = Image{ "./Game_Stage/GAME_OVER.png" };              // 게임 오버 이미지 
			Back = Image{ "./Game_Stage/Stage1_Background.jpg" };      // 스테이지1 배경 이미지
			next = Image{ "./Game_Stage/NEXT.png" };                   // 화살표 이미지
			Back_maxe = Image{ "./Game_Stage/maze1.png" };             // 미로 이미지(1 ~
			Back_maxe2 = Image{ "./Game_Stage/maze2.png" };
			Back_maxe3 = Image{ "./Game_Stage/maze3.png" };
			Back_maxe4 = Image{ "./Game_Stage/maze4.png" };
			Back_maxe5 = Image{ "./Game_Stage/maze5.png" };            // 미로 이미지 5)
		}

		double                   angle{ 0.0 };
		double                   grey{ 0 };
		double                   x1{ -360 };
		double                   y1{ 360 };

		void on_mouse_moved(int mouse_x, int mouse_y) // 마우스 인식 코드
		{
			angle += to_radians(3.0);
			grey = 255 * (std::sin(angle) * 0.5 + 0.5);
			x1 = mouse_x;
			y1 = mouse_y;

		}

		void logic() {
			//이곳에 캐릭터또는 마우스를 이용한 움직임
			x1 = get_mouse_x();
			y1 = get_mouse_y();

			set_image_mode(RectMode::Center);
			set_rectangle_mode(RectMode::Center);

			// 미로 충돌 코드 ↓↓↓↓
			if (x1 >= -258) {
				if (x1 <= 360) {
					if (y1 <= 255) {
						if (y1 >= 115) {
							cout << "충돌" << endl;
							is_trigger = true;                      // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= -360) {
				if (x1 <= 130) {
					if (y1 <= 70) {
						if (y1 >= -70) {
							cout << "충돌" << endl;
							is_trigger = true;                     // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= 225) {
				if (x1 <= 360) {
					if (y1 <= 70) {
						if (y1 >= -70) {
							cout << "충돌" << endl;
							is_trigger = true;                    // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= -122) {
				if (x1 <= 360) {
					if (y1 <= -120) {
						if (y1 >= -256) {
							cout << "충돌" << endl;
							is_trigger = true;                  // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= -360) {
				if (x1 <= -200) {
					if (y1 <= -120) {
						if (y1 >= -256) {
							cout << "충돌" << endl;
							is_trigger = true;			    	// 게임오버 화면 실행	
						}
					}
				}
			}

			if (x1 >= 300) {
				if (x1 <= 350) {
					if (y1 <= -250) {
						if (y1 >= -350) {
							cout << "다음 스테이지" << endl;
							finish_count = 1;

						}
					}
				}
			}



		}

		void draw() {
			//cout << "나 왔다감 " << endl;
			//이곳에 스테이지 배경 캐릭터사진
			clear_background(255, 255, 255, 255);                         // 화면 색
			draw_image(Back, 0, 0, 720, 720);                         // 몸 속 배경
			draw_image(Back_maxe, 80, 190, 750, 200);                // 미로 (1 ~      
			draw_image(Back_maxe2, -210, 0, 720, 200);
			draw_image(Back_maxe3, 550, 0, 720, 200);
			draw_image(Back_maxe4, 200, -190, 720, 200);
			draw_image(Back_maxe5, -550, -190, 720, 200);             // 미로 5)
			draw_image(next, 320, -300, 50, 80);                       // 화살표
			draw_image(germ, x1, y1, 100, 120);                          // 병균 캐릭터

			if (is_trigger) {
				draw_image(Back, 0, 0, 720, 720);
				draw_image(over, 0, 150, 600, 800);
				draw_image(d_germ, 0, -180, 300, 250);
			}
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
		Background = Image("./Game_Stage/Stage1_Background.jpg");
		gastric = Image("./Game_Stage/gastric_juice.png");
		heart = Image("./Game_Stage/heart.png");
		orangeHero = Image("./Game characters/germ_1.png");
	}
	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임
		switch (_getch()) {
		case 75:
			x -= 1;
			break;
		case 77:
			x += 1;
			break;
		}
		
	}
		
		
	
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
		draw_image(Background, -360,360, 720, 720);
		draw_image(orangeHero, x, y,50,50);
		draw_image(gastric, rand() % 360, 340, 50, 50);
		draw_image(heart, rand() % 360, 340, 50, 50);
		



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