#include <doodle/doodle.hpp>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include <string>
#include <exception>
#include <iostream>

using namespace std;
using namespace doodle;

int count_num = 1;

bool shouldFollowMouse = false;

void on_mouse_pressed(MouseButtons button)
{
	if (button == MouseButtons::Left)
		shouldFollowMouse = true;
}

void on_mouse_released(MouseButtons button)
{
	if (button == MouseButtons::Left)
		shouldFollowMouse = false;
}


class Stage1 {

	int finish_count = 0;
public:
	Image germ;
	Image germ2;
	Image d_germ;
	Image over;
	Image Back;
	Image next;
	Image Back_maxe;
	Image Back_maxe2;
	Image Back_maxe3;
	Image Back_maxe4;
	Image Back_maxe5;
	Image game_clear;
	Image Space_bar;
	Image Stage1_Start;
	bool is_trigger = false;
	bool clear = false;
	bool Start = false;
	double x1{ 330};
	double y1{ 330};
	

	void init() {

		germ = Image{ "./Game characters/germ_1.png" };            // 병균 캐릭터
		germ2 = Image{ "./Game characters/germ_3.png" };
		d_germ = Image{ "./Game characters/dead_germ.png" };       // 사망한 병균 캐릭터
		over = Image{ "./Game_Stage/GAME_OVER.png" };              // 게임 오버 이미지 
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };      // 스테이지1 배경 이미지
		next = Image{ "./Game_Stage/NEXT.png" };                   // 화살표 이미지
		Back_maxe = Image{ "./Game_Stage/maze1.png" };             // 미로 이미지(1 ~
		Back_maxe2 = Image{ "./Game_Stage/maze2.png" };
		Back_maxe3 = Image{ "./Game_Stage/maze3.png" };
		Back_maxe4 = Image{ "./Game_Stage/maze4.png" };
		Back_maxe5 = Image{ "./Game_Stage/maze5.png" };            // 미로 이미지 5)
		Space_bar = Image{ "./Game_Stage/Space_bar.png" };
		game_clear = Image{ "./Game_Stage/game_clear.png" };
		Stage1_Start = Image{ "./Game_Stage/Stage1_Start.jpg" };
	}

	

	

	void logic() {
		//이곳에 캐릭터또는 마우스를 이용한 움직임
		if (Start == true) {
			if (shouldFollowMouse)
			{
				const double easing = 3.0 * DeltaTime;
				x1 += easing * (get_mouse_x() - x1);
				y1 += easing * (get_mouse_y() - y1);
			}

			if (x1 >= 360) {
				x1 = 360;
			}

			if (x1 <= -360) {
				x1 = -360;
			}

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
							is_trigger = true;	           // 게임오버 화면 실행	
						}
					}
				}
			}

			if (x1 >= 300) {
				if (x1 <= 350) {
					if (y1 <= -250) {
						if (y1 >= -350) {
							cout << "다음 스테이지" << endl;
							clear = true;

						}
					}
				}
			}
			
			if (clear == true) {
				if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
					finish_count = 1;
				}
			}
		}
	}

	void draw() {
		//cout << "나 왔다감 " << endl;
		//이곳에 스테이지 배경 캐릭터사진
		clear_background(255, 255, 255, 255);                         // 화면 색
		draw_image(Stage1_Start, 0, 0, 720, 720);
		
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			Start = true;
			cout << "스타트" << endl;
			draw_image(germ2, 330, 330, 200, 300);
			
		}

		if (Start) {
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
			if (clear) {
				draw_image(Back, 0, 0, 720, 720);
				draw_image(germ2, 0, -80, 200, 300);
				draw_image(game_clear, 0, 240, 700, 500);
				draw_image(Space_bar, 0, -300, 300, 50);
			}
			
		}
	}
	int end() {
		return finish_count;
	}
};

class Stage2 {

	int rd1 = rand() % 720 - 360;
	int rd2 = rand() % 720 - 360;
	bool is_trigger = false;
	bool clear = false;
	bool Start = false;
	int count_heart = 0;
	int finish_count = 0;
	int y1 = 340;
	int y2 = 340;
	int germ_x = -300;
	int x = -20;
	Image orangeHero;
	Image germ_3;
	Image Background;
	Image gastric;
	Image heart;
	Image over;
	Image d_germ;
	Image Back;
	Image game_clear;
	Image Space_bar;
	Image Stage2_Start;
	Image number;
	Image number_of_hearts;
	Image one;
	Image two;
	Image three;
	Image four;
	Image five;
	Image six;
	Image seven;
	Image eight;
	Image nine;
	Image ten;

public:
	void remake1() {
		rd1 = rand() % 680 - 340;
	}
	void remake2() {
		rd2 = rand() % 680 - 340;
	}
	void init() {
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		d_germ = Image{ "./Game characters/dead_germ.png" };
		over = Image{ "./Game_Stage/GAME_OVER.png" };
		Background = Image("./Game_Stage/Stage1_Background.jpg");
		gastric = Image("./Game_Stage/gastric_juice.png");
		heart = Image("./Game_Stage/heart.png");
		orangeHero = Image("./Game characters/germ_1.png");
		number_of_hearts = Image("./Game_Stage/number_of_hearts.png");
		one = Image("./Game_Stage/1.png");
		two = Image("./Game_Stage/2.png");
		three = Image("./Game_Stage/3.png");
		four = Image("./Game_Stage/4.png");
		five = Image("./Game_Stage/5.png");
		six = Image("./Game_Stage/6.png");
		seven = Image("./Game_Stage/7.png");
		eight = Image("./Game_Stage/8.png");
		nine = Image("./Game_Stage/9.png");
		ten = Image("./Game_Stage/10.png");
		germ_3 = Image("./Game characters/germ_3.png");
		Space_bar = Image{ "./Game_Stage/Space_bar.png" };
		game_clear = Image{ "./Game_Stage/game_clear.png" };
		Stage2_Start = Image{ "./Game_Stage/Stage2_Start.jpg" };
	}
	void logic() {

		//이곳에 캐릭터또는 키보드를 이용한 움직임

		if (Start == true) {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {						//키보드움직임
				x -= 6;
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {						//키보드움직임
				x += 6;
			}
			if (y1 <= -340) {
				remake1();													//충돌체크
				y1 = 340;
			}
			else {
				y1 -= rand() % 12;											//gastric움직임
			}
			if (y2 <= -340) {
				remake2();													//heart움직임
				y2 = 340;
			}
			else {
				y2 -= rand() % 10;
			}
			if (count_heart == 10) {
				clear = true;

			}
			if (rd2 <= x + 70 && rd2 >= x - 70) {
				if (y2 <= germ_x + 70 && y2 >= germ_x - 70) {				// 
					count_heart += 1;
					remake2();
					y2 = 320;
					cout << count_heart;

				}
			}
			if (rd1 <= x + 30 && rd1 >= x - 30) {
				if (y1 <= germ_x + 50 && y1 >= germ_x - 50) {				// 게임오버 화면 실행
					is_trigger = true;
				}
			}
			if (clear == true) {
				if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
					finish_count += 1;

				}
			}
		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진

		draw_image(Stage2_Start, -360, -360, 720, 720);

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			Start = true;
			cout << "스타트" << endl;
		}
		if (Start)
		{
			draw_image(Background, -360, -360, 720, 720);					//배경화면
			draw_image(orangeHero, x, germ_x, 50, 50);						//캐릭터
			draw_image(gastric, rd1, y1, 50, 50);							//장애물
			draw_image(heart, rd2, y2, 50, 50);
			draw_image(number_of_hearts, 0, 0, 500, 500, 200, 200, 400, 400);

			if (is_trigger) {
				draw_image(Back, -360, -360, 720, 720);
				draw_image(over, -300, -360, 600, 800);						//게임오버화면 그리기
				draw_image(d_germ, -100, -360, 300, 250);
			}
			if(is_trigger == false){
				switch (count_heart) {
				case 1:
					draw_image(one, 250, 330, 30, 30);
					break;
				case 2:
					draw_image(two, 250, 330, 30, 30);
					break;
				case 3:
					draw_image(three, 250, 330, 30, 30);
					break;
				case 4:
					draw_image(four, 250, 330, 30, 30);
					break;
				case 5:
					draw_image(five, 250, 330, 30, 30);
					break;
				case 6:
					draw_image(six, 250, 330, 30, 30);
					break;
				case 7:
					draw_image(seven, 250, 300, 30, 30);
					break;
				case 8:
					draw_image(eight, 250, 330, 30, 30);
					break;
				case 9:
					draw_image(nine, 250, 330, 30, 30);
					break;
				case 10:
					draw_image(ten, 250, 330, 30, 30);
					break;
				}
			}
			
			if (clear) {
				draw_image(Background, -360, -360, 720, 720);
				draw_image(germ_3, -100, -200, 200, 300);
				draw_image(game_clear, -360, 0, 700, 500);
				draw_image(Space_bar, -150, -300, 300, 50);
			}
		}
	}
	int end() {
		return finish_count;
	}
};
class Stage3 {

	bool is_trigger = false;
	bool clear = false;
	bool Start = false;
	int Gauge_x = -310;
	int Gauge2_x = 50;
	int counter = 0;
	int counter2 = 0;
	double prev_time = 0;
	int mini_counter = 0;
	int  Key = 0;
	int i;
	int j;
	Image Back;
	Image germ3;
	Image germ2;
	Image germ1;
	Image D_germ;
	Image Mold;
	Image Mold3;
	Image D_Mold;
	Image Gaugeba;
	Image Gaugeba2;
	Image Gauge;
	Image Gauge2;
	Image GAME_OVER;
	Image game_clear;
	Image Space_bar;
	Image Stage3_Start;
	int finish_count = 0;
public:
	void init() {
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		germ3 = Image{ "./Game characters/germ_3.png" };
		germ2 = Image{ "./Game characters/germ_2.png" };
		germ1 = Image{ "./Game characters/germ_1.png" };
		D_germ = Image{ "./Game characters/dead_germ.png" };
		Mold = Image{ "./Game characters/Mold_1.png" };
		Mold3 = Image{ "./Game characters/Mold_2.png" };
		D_Mold = Image{ "./Game characters/dead_Mold.png" };
		Gaugeba = Image{ "./Game_Stage/Gaugeba.png" };
		Gaugeba2 = Image{ "./Game_Stage/Gaugeba2.png" };
		Gauge = Image{ "./Game_Stage/Gauge.png" };
		Gauge2 = Image{ "./Game_Stage/Gauge2.png" };
		GAME_OVER = Image{ "./Game_Stage/GAME_OVER.png" };
		game_clear = Image{ "./Game_Stage/game_clear.png" };
		Space_bar = Image{ "./Game_Stage/Space_bar.png" };
		Stage3_Start = Image{ "./Game_Stage/Stage3_Start.jpg" };
	}
	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임
		if (Start == true) {
			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				//cout << "입력 받는 중" << endl;
				draw_image(germ1, -180, -150, 220, 320);
				if (counter < 14) {
					if (mini_counter < 8) {
						mini_counter++;
					}
					else {
						counter++;
						mini_counter = 0;
					}
				}
			}
			else {
				draw_image(germ2, -180, -150, 220, 320);
			}

			prev_time += DeltaTime;

			if (prev_time > 1.6) {                                    // 팡이 게이지 채워지는 시간
				prev_time = 0;
				draw_image(Mold, 180, -150, 200, 300);
				if (counter2 < 14) counter2++;
			}
			else {
				draw_image(Mold3, 180, -150, 200, 300);
			}

			if (counter2 == 14) {
				cout << "죽음" << endl;
				is_trigger = true;

			}
		}

		if (counter == 14) {
			cout << "다음 스테이지" << endl;
			clear = true;
			Start = false;
		}

		if (clear == true) {
			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				finish_count = 1;
			}
		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
		draw_image(Stage3_Start, 0, 0, 720, 720);

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			Start = true;
			cout << "스타트" << endl;
		}

		if (Start) {
			clear_background(255, 255, 255, 255);
			draw_image(Back, 0, 0, 720, 720);
			draw_image(Gaugeba, 180, 250, 300, 50);
			draw_image(Gaugeba2, -180, 250, 300, 50);

			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				//cout << "입력 받는 중" << endl;
				draw_image(germ1, -180, -150, 220, 320);
				if (counter < 14) {
					if (mini_counter < 8) {
						mini_counter++;
					}
					else {
						counter++;
						mini_counter = 0;
					}
				}
			}
			else {
				draw_image(germ2, -180, -150, 220, 320);
			}
			if (prev_time > 1.6) {                                    // 팡이 게이지 채워지는 시간
				prev_time = 0;
				draw_image(Mold, 180, -150, 200, 300);
				if (counter2 < 14) counter2++;
			}
			else {
				draw_image(Mold3, 180, -150, 200, 300);
			}

			for (int i = 0; i < counter; ++i) {
				draw_image(Gauge, Gauge_x + i * 20, 250, 20, 25);
			}
			for (int j = 0; j < counter2; ++j) {
				draw_image(Gauge2, Gauge2_x + ((13 - j) * 20), 250, 20, 25);
			}

			if (is_trigger) {
				draw_image(Back, 0, 0, 720, 720);
				draw_image(D_germ, 0, -100, 200, 350);
				draw_image(GAME_OVER, 0, 180, 550, 450);
			}
		}
		if (clear) {
			draw_image(Back, 0, 0, 720, 720);
			draw_image(D_Mold, 0, -150, 250, 150);
			draw_image(germ3, 0, 20, 180, 250);
			draw_image(game_clear, 0, 250, 650, 450);
			draw_image(Space_bar, 0, -280, 300, 50);
		}
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
			set_image_mode(RectMode::Center);
			stage1.logic();
			stage1.draw();
			count_num += stage1.end();
			break;
		case 2:
			set_image_mode(RectMode::Corner);
			stage2.logic();
			stage2.draw();
			count_num += stage2.end();
			break;
		case 3:
			set_image_mode(RectMode::Center);
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