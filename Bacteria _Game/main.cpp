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

int count_num = 4;

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
	bool Manager = false;
	double x1{ 310 };
	double y1{ 300 };


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

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {						// 관리자 비밀(버그)키
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					if (GetAsyncKeyState(VK_TAB) & 0x8000) {
						Manager = true;
						cout << "관리자키 ON" << endl;
					}
				}
			}

			if (Manager == false)
			{
				if (x1 >= 360) {
					x1 = 360;
				}

				if (x1 <= -360) {
					x1 = -360;
				}
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
				if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
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

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			Start = true;
			cout << "스타트" << endl;

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

			if (GetAsyncKeyState(VK_UP) & 0x8000) {						// 관리자 비밀(버그)키
				if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
					if (GetAsyncKeyState(VK_TAB) & 0x8000) {
						clear = true;
						cout << "관리자키 ON" << endl;
					}
				}
			}



			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {						//키보드움직임
				x -= 8;
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {						//키보드움직임
				x += 8;
			}
			if (count_heart <= 5)
			{
				if (y1 <= -340) {
					remake1();													//충돌체크
					y1 = 340;
				}
				else {
					y1 -= rand() % 25;											//gastric움직임
				}
				if (y2 <= -340) {
					remake2();													//heart움직임
					y2 = 340;
				}
				else {
					y2 -= rand() % 20;
				}
				if (x >= 350) {
					x = 330;
				}
				else if (x <= -360) {
					x = -360;
				}
				if (count_heart == 10) {
					clear = true;

				}
			}
			else {
				if (y1 <= -340) {
					remake1();													//충돌체크
					y1 = 340;
				}
				else {
					y1 -= rand() % 35;											//gastric움직임
				}
				if (y2 <= -340) {
					remake2();													//heart움직임
					y2 = 340;
				}
				else {
					y2 -= rand() % 30;
				}
				if (x >= 350) {
					x = 330;
				}
				else if (x <= -360) {
					x = -360;
				}
				if (count_heart == 10) {
					clear = true;

				}
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
				if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
					finish_count += 1;

				}
			}

		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진

		draw_image(Stage2_Start, -360, -360, 720, 720);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
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
				draw_image(over, -300, -340, 600, 800);						//게임오버화면 그리기
				draw_image(d_germ, -100, -360, 300, 250);
			}
			if (is_trigger == false) {
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
					if (mini_counter < 10) {
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

			if (prev_time > 1.5) {                                    // 팡이 게이지 채워지는 시간
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
			if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
				finish_count = 1;
			}
		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
		draw_image(Stage3_Start, 0, 0, 720, 720);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
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
	int size = 130;
	int x_p1 = 330;
	int x_p2 = 330;
	int x_p3 = 330;
	int rd1;
	int rd2;
	int rd3;
	int germ_x = -250;
	int germ_y = -50;
	int red_cell_size = 80;
	bool Manager = false;
	bool mouse_press = false;
	Image Stage_4_Background;
	Image red_blood_cell[3];
	Image germ_2;
	Image red_cell_come;
public:
	void remake1() {
		rd1 = rand() % 300 - 150;
	}
	void remake2() {
		rd2 = rand() % 300 - 150;
	}
	void remake3() {
		rd3 = rand() % 300 - 150;
	}
	void init() {
		germ_2 = Image{ "./Game characters/germ_2.png" };
		Stage_4_Background = Image{ "./Game_Stage/Stage_4_Background.jpg" };
		red_blood_cell[0] = Image{ "./Game characters/red_blood_cell.png" };
		red_blood_cell[1] = Image{ "./Game characters/red_blood_cell.png" };
		red_blood_cell[2] = Image{ "./Game characters/red_blood_cell.png" };
	}
	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임
		
		if (shouldFollowMouse)
		{
			const double easing = 30.0 * DeltaTime;
			germ_y += easing * (get_mouse_y() - germ_y);
			if (germ_y >= 150) {
				germ_y = 150;
			}

			if (germ_y <= -150) {
				germ_y = -150;
			}
		}
		if (x_p1 <= -330) {
			remake1();
			x_p1 = 330;
		}
		else
			x_p1 -= rand()%60;

		if (x_p2 <= -330) {
			remake2();
			x_p2 = 330;
		}
		else
			x_p2 -= rand()%60;

		if (x_p3 <= -330) {
			remake3();
			x_p3 = 330;
		}
		else
			x_p3 -= rand() % 60;
	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
		draw_image(Stage_4_Background, 0, 0,1440,720);
		draw_image(germ_2, germ_x, germ_y ,size, size);
		draw_image(red_blood_cell[0], x_p1, rd1, red_cell_size, red_cell_size);
		draw_image(red_blood_cell[1], x_p2, rd2, red_cell_size, red_cell_size);
		draw_image(red_blood_cell[2], x_p3, rd3, red_cell_size, red_cell_size);
	}
	int end() {
		return finish_count;
	}
};

class Stage5 {
	int finish_count = 0;

	bool Last = false;
	bool characters = false;
	bool Heart = false;
	bool is_Gauge2 = false;
	bool is_trigger = false;
	bool Ending = false;
	bool GAMEOVER = false;
	bool heart_gauge = false;
	bool heart_gauge2 = false;
	bool Start = false;
	bool Manager = true;

	int counter = 0;
	int counter2 = 0;
	int mini_counter = 0;
	int Gauge_x = -300;
	int Gauge2_x = 163;
	double prev_time = 0;
	int Heart_L = 500;
	int Heart_T = 550;

	Image Back;
	Image germ1;
	Image germ3;
	Image D_germ;
	Image Gaugeba;
	Image Gaugeba2;
	Image Gauge;
	Image Gauge2;
	Image GAME_OVER;
	Image game_clear;
	Image Door;
	Image Door2;
	Image speech_bubble;
	Image Leukocyte;
	Image Heart_stage;
	Image blood;
	Image Space_bar;

	double y5_1{ -200 };
	double x5{ 0.0 };
	double y5{ -250 };


public:
	void init() {
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		germ1 = Image{ "./Game characters/germ_1.png" };
		germ3 = Image{ "./Game characters/germ_3.png" };
		D_germ = Image{ "./Game characters/dead_germ.png" };
		Heart_stage = Image{ "./Game_Stage/Heart_stage.png" };
		blood = Image{ "./Game_Stage/blood.png" };
		Gaugeba = Image{ "./Game_Stage/Gaugeba.png" };
		Gaugeba2 = Image{ "./Game_Stage/Gaugeba2.png" };
		Gauge = Image{ "./Game_Stage/Gauge.png" };
		Gauge2 = Image{ "./Game_Stage/Gauge2.png" };
		GAME_OVER = Image{ "./Game_Stage/GAME_OVER.png" };
		game_clear = Image{ "./Game_Stage/game_clear.png" };
		Leukocyte = Image{ "./Game_Stage/Leukocyte.png" };
		speech_bubble = Image{ "./Game_Stage/speech_bubble.png" };
		Space_bar = Image{ "./Game_Stage/Space_bar.png" };
		Door = Image{ "./Game_Stage/Door.png" };
		Door2 = Image{ "./Game_Stage/Door2.png" };
	}

	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임

		//draw_image(Stage5_Start, 0, 0, 720, 720);

		if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
			Start = true;
			cout << "스타트" << endl;
		}

		if (Start == true)
		{

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {						// 관리자 비밀(버그)키
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					if (GetAsyncKeyState(VK_TAB) & 0x8000) {
						Manager = false;
						cout << "관리자키 ON" << endl;
					}
				}
			}


			for (int j = 0; j < counter2; ++j) {
				draw_image(Gauge2, Gauge2_x + (13 + j * 9.9), 230, 9.9, 20);
			}

			prev_time += DeltaTime;

			if (is_Gauge2 == false) {
				if (heart_gauge) {
					if (prev_time > 0.3) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지2" << endl;
					}
				}
				else {
					if (prev_time > 0.5) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지" << endl;
					}
				}
				if (heart_gauge2) {
					if (prev_time > 0.1) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지3" << endl;
					}
				}
				Heart = false;
			}



			if (counter2 == 14) {
				Heart = true;
				is_Gauge2 = true;

			}

			if (Heart) {
				Heart_L = 570;
				Heart_T = 600;
				counter2 = 0;
				is_Gauge2 = false;
			}

			if (Heart == false) {
				Heart_L = 500;
				Heart_T = 550;
			}






			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				draw_image(germ3, 0, y5_1, 150, 200);
				draw_image(blood, 0, -300, 900, 500);
				if (y5_1 <= -10) {
					cout << "올라감" << endl;
					y5_1 += 4;
				}
			}
			else {
				draw_image(germ3, 0, y5_1, 150, 200);
				draw_image(blood, 0, -300, 900, 500);
				if (y5_1 >= -200) {
					cout << "떨어짐" << endl;
					y5_1 -= 4;
				}
			}

			for (int i = 0; i < counter; ++i) {
				draw_image(Gauge, Gauge_x + i * 5, 300, 5, 25);
				cout << counter << endl;
			}

			if (y5_1 >= -10) {
				if (counter < 122) {
					if (mini_counter < 10) {
						mini_counter++;

					}
					else {
						counter++;
						mini_counter = 0;
					}
				}
			}
			else if (y5_1 <= -80) {
				//cout << "-80 언더" << endl;
				// 게이지바 깎이게 만들기.

			}

			for (int j = 0; j < counter2; ++j) {

			}

			if (counter == 61) {
				heart_gauge = true;
			}
			if (counter == 85) {
				heart_gauge2 = true;
				heart_gauge = false;
			}
		}

		if (Manager)
		{
			if (Heart == true) {
				if (y5_1 <= -5) {
					if (y5_1 >= -85) {
						is_trigger = true;
						Start = false;

					}
				}
			}
		}

		if (counter == 122) {                                      //게임 클리어
			draw_image(Back, 0, 0, 720, 720);
			draw_image(germ3, 0, 20, 180, 250);
			draw_image(game_clear, 0, 250, 650, 450);
			draw_image(Space_bar, 0, -280, 300, 50);
			if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				Last = true;
				Start = false;
			}
		}
		if (Last) {                                              // 마지막 관문 

			if (shouldFollowMouse)
			{
				const double easing = 3.0 * DeltaTime;
				x5 += easing * (get_mouse_x() - x5);
				y5 += easing * (get_mouse_y() - y5);
			}

			if (x5 <= -80) {
				if (x5 >= -270) {
					if (y5 <= 250) {
						if (y5 >= -10) {
							cout << "좌심" << endl;
							Ending = true;
							Start = false;
						}
					}
				}
			}

			if (x5 >= 80) {
				if (x5 <= 270) {
					if (y5 <= 250) {
						if (y5 >= -10) {
							cout << "우심" << endl;
							GAMEOVER = true;
							Start = false;
						}
					}
				}
			}
		}


	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진 

		if (Start == true) {
			draw_image(Back, 0, 0, 720, 720);
			draw_image(Heart_stage, 0, -50, Heart_L, Heart_T);
			draw_image(blood, 0, -300, 900, 550);
			draw_image(Gaugeba, 0, 300, 650, 50);
			draw_image(Gaugeba2, 240, 230, 150, 40);

			for (int j = 0; j < counter2; ++j) {
				draw_image(Gauge2, Gauge2_x + (13 + j * 9.9), 230, 9.9, 20);
			}

			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				draw_image(germ3, 0, y5_1, 150, 200);
				draw_image(blood, 0, -300, 900, 500);
				if (y5_1 <= -10) {
					cout << "올라감" << endl;
					y5_1 += 5;
				}
			}
			else {
				draw_image(germ3, 0, y5_1, 150, 200);
				draw_image(blood, 0, -300, 900, 500);
				if (y5_1 >= -200) {
					cout << "떨어짐" << endl;
					y5_1 -= 5;
				}
			}

			for (int i = 0; i < counter; ++i) {
				draw_image(Gauge, Gauge_x + i * 5, 300, 5, 25);
			}
		}

		if (is_trigger) {
			draw_image(Back, 0, 0, 720, 720);
			draw_image(D_germ, 0, -100, 200, 350);
			draw_image(GAME_OVER, 0, 180, 550, 450);
			Start = false;
		}


		if (counter == 122) {                                      //게임 클리어
			draw_image(Back, 0, 0, 720, 720);
			draw_image(germ3, 0, 20, 180, 250);
			draw_image(game_clear, 0, 250, 650, 450);
			draw_image(Space_bar, 0, -280, 300, 50);
			if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
				Last = true;
				Start = false;
			}
		}

		if (Last) {
			draw_image(Back, 0, 0, 720, 720);
			draw_image(Door, -180, 100, 150, 350);
			draw_image(Door2, 180, 100, 150, 350);
			draw_image(germ1, x5, y5, 80, 150);
		}

		if (GAMEOVER) {

			draw_image(Back, 0, 0, 720, 720);
			draw_image(GAME_OVER, 0, 200, 570, 520);
			draw_image(D_germ, -250, -280, 150, 100);
			draw_image(Leukocyte, 0, -160, 600, 700);
			draw_image(speech_bubble, 270, 100, 280, 330);

		}


	} // draw 끝
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
			set_image_mode(RectMode::Center);
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
			set_image_mode(RectMode::Center);
			stage4.logic();
			stage4.draw();
			count_num += stage4.end();
			break;
		case 5:
			set_image_mode(RectMode::Center);
			stage5.logic();
			stage5.draw();
			count_num += stage5.end();
			break;
		}
	}

}