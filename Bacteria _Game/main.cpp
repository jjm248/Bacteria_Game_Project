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


void reset();
int count_num = 4;




bool shouldFollowMouse = false;

void on_mouse_pressed(MouseButtons button)           // 따라오는 마우스 키 받는 키
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
	Image over;
	Image Back;
	Image next;
	Image Back_maxe;
	Image game_clear;
	Image Stage1_Start;
	Image Opening;
	Image Opening2;
	Image Opening3;
	Image Opening4;

	bool is_trigger = false;
	bool clear = false;
	bool Start = false;
	bool Manager = false;
	bool is_Opening = true;
	bool is_Opening2 = false;
	bool is_Opening3 = false;
	bool is_Opening4 = false;
	bool is_Stage1_Start = false;
	bool game_over = false;
	bool cl = true;

	int op_num = 0;

	double x1{ 310 };
	double y1{ 300 };

	void start() {
		is_trigger = false;
		clear = false;
		Start = false;
		Manager = false;
		is_Opening = true;
		is_Opening2 = false;
		is_Opening3 = false;
		is_Opening4 = false;
		is_Stage1_Start = false;
		game_over = false;

		op_num = 0;

		x1 = 310;
		y1 = 300;
		finish_count = 0;
	}
	void init() {
		op_num = 0;

		germ = Image{ "./Game characters/germ_1.png" };            // 병균 캐릭터
		germ2 = Image{ "./Game characters/germ_3.png" };     // 사망한 병균 캐릭터
		over = Image{ "./Game_Stage/GAME_OVER.jpg" };              // 게임 오버 이미지 
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };      // 스테이지1 배경 이미지
		next = Image{ "./Game_Stage/NEXT.png" };                   // 화살표 이미지
		Back_maxe = Image{ "./Game_Stage/maze.png" };         // 미로 이미지
		game_clear = Image{ "./Game_Stage/game_clear.jpg" };
		Stage1_Start = Image{ "./Game_Stage/Stage1_Start.jpg" };
		Opening = Image{ "./Game_Stage/Opening.jpg" };
		Opening2 = Image{ "./Game_Stage/Opening2.jpg" };
		Opening3 = Image{ "./Game_Stage/Opening3.jpg" };
		Opening4 = Image{ "./Game_Stage/Opening4.jpg" };

	}





	void logic() {
		//이곳에 캐릭터또는 마우스를 이용한 움직임
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {       // 처음 오프닝 이미지
			if (op_num < 4) {
				op_num++;
			}
			/*if (op_num == 4) {
				ST = true;
				cout << "들어오니" << endl;
			}*/

		}

		if (op_num == 4)
		{
			if (GetAsyncKeyState(VK_RETURN) & 0x0001 && Start != true) {
				Start = true;
				//cout << "스타트" << endl;

			}
		}

		if (Start == true) {
			if (shouldFollowMouse)
			{
				const double easing = 3.0 * DeltaTime;                     // 마우스 키 받는 코드
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
				if (x1 >= 360) {                                       // 캐릭터 범위 설정 코드
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
							is_trigger = true;                      // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= -360) {
				if (x1 <= 130) {
					if (y1 <= 70) {
						if (y1 >= -70) {
							is_trigger = true;                         // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= 225) {
				if (x1 <= 360) {
					if (y1 <= 70) {
						if (y1 >= -70) {
							is_trigger = true;                       // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= -122) {
				if (x1 <= 360) {
					if (y1 <= -120) {
						if (y1 >= -256) {
							is_trigger = true;                     // 게임오버 화면 실행
						}
					}
				}
			}

			if (x1 >= -360) {
				if (x1 <= -200) {
					if (y1 <= -120) {
						if (y1 >= -256) {
							is_trigger = true;  	           // 게임오버 화면 실행	
						}
					}
				}
			}

			if (is_trigger) {
				if (GetAsyncKeyState(VK_TAB) & 0x8000) {
					cout << "탭" << endl;
					game_over = true;
					cl = false;
				}
			}

			if (game_over) {
				reset();
			}

			if (is_trigger == false)
			{
				if (x1 >= 300) {
					if (x1 <= 350) {
						if (y1 <= -250) {
							if (y1 >= -350) {
								//	cout << "다음 스테이지" << endl;
								clear = true;

							}
						}
					}
				}
			}

			if (clear == true) {
				//cout << "실행" << endl;
				if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
					//	cout << "넘아가기" << endl;
					finish_count += 1;
				}
			}
		}
	}

	void draw() {
		//cout << "나 왔다감 " << endl;
		//이곳에 스테이지 배경 캐릭터사진
		clear_background(255, 255, 255, 255);   // 화면 색
		switch (op_num) {
		case 0:
			draw_image(Opening, 0, 0, 720, 720);
			break;
		case 1:
			draw_image(Opening2, 0, 0, 720, 720);
			break;
		case 2:
			draw_image(Opening3, 0, 0, 720, 720);
			break;
		case 3:
			draw_image(Opening4, 0, 0, 720, 720);
			break;
		}

		if (op_num == 4) {
			draw_image(Stage1_Start, 0, 0, 720, 720);
		}


		if (Start) {
			draw_image(Back, 0, 0, 720, 720);                         // 몸 속 배경
			draw_image(Back_maxe, 80, 155, 670, 500);                // 미로 (1 ~      
			draw_image(Back_maxe, -210, -25, 680, 500);
			draw_image(Back_maxe, 550, -25, 650, 500);
			draw_image(Back_maxe, 200, -220, 650, 500);
			draw_image(Back_maxe, -550, -220, 690, 500);             // 미로 5)
			draw_image(next, 320, -300, 50, 80);                       // 화살표
			draw_image(germ, x1, y1, 100, 120);                          // 병균 캐릭터

			if (is_trigger) {
				draw_image(over, 0, 0, 720, 720);
			}
			if (clear) {
				draw_image(game_clear, 0, 0, 720, 720);

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
	int ruru_x = 250;
	int ruru_y = 330;
	bool is_trigger = false;
	bool clear = false;
	bool Start = false;
	bool game_over = false;
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
	Image Back;
	Image game_clear;
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

	void start() {
		rd1 = rand() % 720 - 360;
		rd2 = rand() % 720 - 360;
		ruru_x = 250;
		ruru_y = 250;
		is_trigger = false;
		clear = false;
		Start = false;
		game_over = false;
		count_heart = 0;
		finish_count = 0;
		y1 = 340;
		y2 = 340;
		germ_x = -300;
		x = -20;
	}

	void init() {
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		over = Image{ "./Game_Stage/GAME_OVER.jpg" };
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
		game_clear = Image{ "./Game_Stage/game_clear.jpg" };
		Stage2_Start = Image{ "./Game_Stage/Stage2_Start.jpg" };
	}
	void logic() {

		//이곳에 캐릭터또는 키보드를 이용한 움직임

		if (GetAsyncKeyState(VK_RETURN) & 0x0001 && Start != true) {
			Start = true;
			//	cout << "스타트" << endl;
		}

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
			if (rd2 <= x + 50 && rd2 >= x - 50) {
				if (y2 <= germ_x + 70 && y2 >= germ_x - 70) {
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

			if (is_trigger) {
				if (GetAsyncKeyState(VK_TAB) & 0x8000) {
					cout << "탭" << endl;
					game_over = true;
				}
			}

			if (game_over) {
				reset();
			}

			if (clear == true) {
				if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
					finish_count += 1;

				}
			}

		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진

		draw_image(Stage2_Start, 0, 0, 720, 720);


		if (Start)
		{
			draw_image(Background, 0, -0, 720, 720);					//배경화면
			draw_image(orangeHero, x, germ_x, 50, 50);						//캐릭터
			draw_image(gastric, rd1, y1, 50, 50);							//장애물
			draw_image(heart, rd2, y2, 50, 50);
			draw_image(number_of_hearts, ruru_x - 20, 230, 500, 500, 200, 200, 400, 400);
			if (clear == false)
			{
				if (is_trigger) {
					draw_image(over, 0, 0, 720, 720);
				}
			}

			if (is_trigger == false) {
				switch (count_heart) {
				case 1:
					draw_image(one, ruru_x, ruru_y, 30, 30);
					break;
				case 2:
					draw_image(two, ruru_x, ruru_y, 30, 30);
					break;
				case 3:
					draw_image(three, ruru_x, ruru_y, 30, 30);
					break;
				case 4:
					draw_image(four, ruru_x, ruru_y, 30, 30);
					break;
				case 5:
					draw_image(five, ruru_x, ruru_y, 30, 30);
					break;
				case 6:
					draw_image(six, ruru_x, ruru_y, 30, 30);
					break;
				case 7:
					draw_image(seven, ruru_x, ruru_y, 30, 30);
					break;
				case 8:
					draw_image(eight, ruru_x, ruru_y, 30, 30);
					break;
				case 9:
					draw_image(nine, ruru_x, ruru_y, 30, 30);
					break;
				case 10:
					draw_image(ten, ruru_x, ruru_y, 30, 30);
					break;
				}
			}


			if (clear) {
				draw_image(game_clear, 0, 0, 720, 720);

			}
		}
	}
	int end() {
		return finish_count;
	}
};
class Stage3 {

	bool state_key = false;
	bool is_trigger = false;
	bool clear = false;
	bool Start = false;
	bool game_over = false;
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
	Image Mold;
	Image Mold3;
	Image Gaugeba;
	Image Gaugeba2;
	Image Gauge;
	Image Gauge2;
	Image GAME_OVER2;
	Image game_clear;
	Image Space_bar;
	Image Stage3_Start;
	int finish_count = 0;
	int is_push = 0;
public:

	void start() {
		state_key = false;
		is_trigger = false;
		clear = false;
		Start = false;
		Gauge_x = -310;
		Gauge2_x = 50;
		counter = 0;
		counter2 = 0;
		prev_time = 0;
		mini_counter = 0;
		Key = 0;
		i;
		j;
		finish_count = 0;
		is_push = false;
	}

	void init() {
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		germ3 = Image{ "./Game characters/germ_3.png" };
		germ2 = Image{ "./Game characters/germ_2.png" };
		germ1 = Image{ "./Game characters/germ_1.png" };
		Mold = Image{ "./Game characters/Mold_1.png" };
		Mold3 = Image{ "./Game characters/Mold_2.png" };
		Gaugeba = Image{ "./Game_Stage/Gaugeba.png" };
		Gaugeba2 = Image{ "./Game_Stage/Gaugeba2.png" };
		Gauge = Image{ "./Game_Stage/Gauge.png" };
		Gauge2 = Image{ "./Game_Stage/Gauge2.png" };
		game_clear = Image{ "./Game_Stage/game_clear.jpg" };
		Stage3_Start = Image{ "./Game_Stage/Stage3_Start.jpg" };
		GAME_OVER2 = Image{ "./Game_Stage/GAME_OVER2.jpg" };
	}
	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임



		if (Start == true) {

			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				//cout << "입력 받는 중" << endl;
				if (!state_key) {
					cout << "작동됨?" << endl;
					state_key = true;
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

			}
			else {
				state_key = false;
			}

			prev_time += DeltaTime;

			if (prev_time > 1.3) {                                    // 팡이 게이지 채워지는 시간
				prev_time = 0;
				if (counter2 < 14) counter2++;
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

		if (GetAsyncKeyState(VK_RETURN) & 0x0001 && Start == false) {
			Start = true;
			cout << "스타트" << endl;
		}

		if (Start) {
			clear_background(255, 255, 255, 255);
			draw_image(Back, 0, 0, 720, 720);
			draw_image(Gaugeba, 180, 250, 300, 50);
			draw_image(Gaugeba2, -180, 250, 300, 50);
			draw_image(germ1, -180, -150, 220, 320);
			draw_image(Mold, 180, -150, 200, 300);

			if (prev_time > 1.6) {                                    // 팡이 게이지 채워지는 시간
				prev_time = 0;
				if (counter2 < 14) counter2++;
			}

			for (int i = 0; i < counter; ++i) {
				draw_image(Gauge, Gauge_x + i * 20, 250, 20, 25);
			}
			for (int j = 0; j < counter2; ++j) {
				draw_image(Gauge2, Gauge2_x + ((13 - j) * 20), 250, 20, 25);
			}

			if (is_trigger) {

				draw_image(GAME_OVER2, 0, 0, 720, 720);
			}

			if (is_trigger) {
				if (GetAsyncKeyState(VK_TAB) & 0x8000) {
					cout << "탭" << endl;
					game_over = true;
				}
			}

			if (game_over) {
				reset();
			}

		}
		if (clear) {
			draw_image(game_clear, 0, 0, 720, 720);
		}
	}
	int end() {
		return finish_count;
	}
};
class Stage4 {

	int sum_x[3];
	int sum_y[3];
	int square_x[3];
	int square_y[3];
	int finish_count = 0;
	int size = 80;
	int x_p1 = 330;
	int x_p2 = 330;
	int x_p3 = 330;
	int rd1;
	int rd2;
	int rd3;
	int speed1 = 1;
	int speed2 = 1;
	int speed3 = 1;
	int germ_x = -250;
	int germ_y = -50;
	int red_cell_size = 80;
	int count_speed1 = 0;
	int count_speed2 = 0;
	int count_speed3 = 0;
	double s = 1;
	bool Manager = false;
	bool mouse_press = false;
	bool is_trigger = false;
	bool Start = false;
	bool game_cl = false;
	bool game_over;
	Image over;
	Image d_germ;
	Image Back;
	Image Stage_4_Background;
	Image red_blood_cell[3];
	Image germ_2;
	Image red_cell_come;
	Image Stage4_Start;
	Image game_clear;

public:
	void start() {
		finish_count = 0;
		size = 80;
		x_p1 = 330;
		x_p2 = 330;
		x_p3 = 330;
		rd1;
		rd2;
		rd3;
		speed1 = 1;
		speed2 = 1;
		speed3 = 1;
		germ_x = -250;
		germ_y = -50;
		red_cell_size = 80;
		count_speed1 = 0;
		count_speed2 = 0;
		count_speed3 = 0;
		s = 1;
		Manager = false;
		mouse_press = false;
		is_trigger = false;
		Start = false;
		game_cl = false;

		game_over;
	}

	void remake1() {
		rd1 = rand() % 300 - 150;
		x_p1 = 330 + rand() % 100;

	}
	void remake2() {
		rd2 = rand() % 300 - 150;
		x_p2 = 330 + rand() % 100;

	}
	void remake3() {
		rd3 = rand() % 300 - 150;
		x_p3 = 330 + rand() % 100;

	}
	void Circle() {
		sum_x[0] = germ_x - x_p1;
		sum_x[1] = germ_x - x_p2;
		sum_x[2] = germ_x - x_p3;

		sum_y[0] = germ_y - rd1;
		sum_y[1] = germ_y - rd2;
		sum_y[2] = germ_y - rd3;

		for (int i = 0; i < 3; ++i) {
			square_x[i] = sum_x[i] * sum_x[i];
			square_y[i] = sum_y[i] * sum_y[i];
		}

	}
	void init() {
		germ_2 = Image{ "./Game characters/germ_2.png" };
		Stage_4_Background = Image{ "./Game_Stage/Stage_4_Background.jpg" };
		red_blood_cell[0] = Image{ "./Game characters/red_blood_cell.png" };
		red_blood_cell[1] = Image{ "./Game characters/red_blood_cell.png" };
		red_blood_cell[2] = Image{ "./Game characters/red_blood_cell.png" };
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		over = Image{ "./Game_Stage/GAME_OVER.jpg" };
		Stage4_Start = Image{ "./Game_Stage/Stage4_Start.jpg" };
		game_clear = Image{ "./Game_Stage/game_clear.jpg" };
		remake1();
		remake2();
		remake3();
	}
	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임

		draw_image(Stage4_Start, 0, 0, 720, 720);

		if (GetAsyncKeyState(VK_RETURN) & 0x0001) {

			if (Start == false) {
				Start = true;
				cout << "스타트" << endl;
			}

			if (game_cl) {				
				cout << "들어와" << endl;
				finish_count = 1;				
			}
		}

		if (Start)
		{
			if (shouldFollowMouse)
			{
				const double easing = 30.0 * DeltaTime;
				germ_y += easing * (get_mouse_y() - germ_y);
				if (germ_y >= 150) {
					is_trigger = true;
				}

				if (germ_y <= -150) {
					is_trigger = true;
				}
			}
			//적혈구1 여기부터
			if (x_p1 <= -330) {
				remake1();
			}
			else {
				x_p1 -= speed1;
				if (x_p1 <= -330) {
					speed1 += s;
					count_speed1 += 1;
				}
			}
			//여기까지


			//적혈구2 여기부터
			if (x_p2 <= -330) {
				remake2();
			}
			else {
				x_p2 -= speed2;
				if (x_p2 <= -330) {
					speed2 += s;
					count_speed2 += 1;
				}
			}
			//여기까지

			//적혈구3 여기부터
			if (x_p3 <= -330) {
				remake3();

			}
			else {
				x_p3 -= speed3;
				if (x_p3 <= -330) {
					speed3 += s;
					count_speed3 += 1;
				}
			}
			//여기까지

		}
		Circle();
		//여기까지
		if (square_x[0] + square_y[0] <= 2500) {


			is_trigger = true;
		}
		if (square_x[1] + square_y[1] <= 2500) {


			is_trigger = true;
		}
		if (square_x[2] + square_y[2] <= 2500) {


			is_trigger = true;
		}
		if (is_trigger == false) {
			if (count_speed1 == 10) {
				if (count_speed2 == 10) {
					if (count_speed3 == 10) {							//5스테이지로 넘어가는 조건
						game_cl = true;
					}
				}
			}
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {						// 관리자 비밀(버그)키
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (GetAsyncKeyState(VK_TAB) & 0x8000) {
					cout << "관리자키 on" << endl;
					game_cl = true;
				}
			}
		}
		if (Manager) {
			game_cl = true;
		}

		if (game_cl == false) {
			if (is_trigger) {
				cout << "실행중" << endl;
				if (GetAsyncKeyState(VK_TAB) & 0x8000) {
					cout << "탭" << endl;
					game_over = true;
				}
			}
		}

		

		if (game_over) {
			reset();
		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진
		draw_image(Stage4_Start, 0, 0, 720, 720);
		if (Start)
		{
			draw_image(Stage_4_Background, 0, 0, 1440, 720);
			draw_image(germ_2, germ_x, germ_y, size, size);
			draw_image(red_blood_cell[0], x_p1, rd1, red_cell_size, red_cell_size);
			draw_image(red_blood_cell[1], x_p2, rd2, red_cell_size, red_cell_size);
			draw_image(red_blood_cell[2], x_p3, rd3, red_cell_size, red_cell_size);
		}

		if (game_cl == false)
		{
			if (is_trigger) {
				draw_image(over, 0, 0, 720, 720);						//게임오버화면 그리기
			}
		}

		if (game_cl) {
			draw_image(game_clear, 0, 0, 720, 720);
		}
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
	bool GAMEOVER = false;
	bool heart_gauge = false;
	bool heart_gauge2 = false;
	bool heart_gauge3 = false;
	bool Start = false;
	bool Manager = true;
	bool Ending = false;
	bool RETURN_key = false;
	bool game_over = false;

	int counter = 0;
	int counter2 = 0;
	int mini_counter = 0;
	int Gauge_x = -300;
	int Gauge2_x = 163;
	double prev_time = 0;
	int Heart_L = 1000;
	int Heart_T = 700;
	int en_num = 0;

	Image Back;
	Image germ1;
	Image germ3;
	Image Gaugeba;
	Image Gaugeba2;
	Image Gauge;
	Image Gauge2;
	Image GAME_OVER;
	Image GAME_OVER3;
	Image game_clear;
	Image gateway;  // 마지막 관문
	Image Heart_stage;
	Image blood;
	Image Ending1;
	Image Ending2;
	Image Ending3;
	Image Ending4;
	Image Stage5_Start;

	double y5_1{ -200 };
	double x5{ 0.0 };
	double y5{ -250 };


public:

	void start() {
		Last = false;
		characters = false;
		Heart = false;
		is_Gauge2 = false;
		is_trigger = false;
		GAMEOVER = false;
		heart_gauge = false;
		heart_gauge2 = false;
		heart_gauge3 = false;
		Start = false;
		Manager = true;
		Ending = false;
		RETURN_key = false;

		counter = 0;
		counter2 = 0;
		mini_counter = 0;
		Gauge_x = -300;
		Gauge2_x = 163;
		prev_time = 0;
		Heart_L = 1000;
		Heart_T = 700;
		en_num = 0;

		y5_1 = -200;
		x5 = 0;
		y5 = -250;

		finish_count = 0;
	}

	void init() {
		en_num = 0;
		Back = Image{ "./Game_Stage/Stage1_Background.jpg" };
		germ1 = Image{ "./Game characters/germ_1.png" };
		germ3 = Image{ "./Game characters/germ_3.png" };
		Heart_stage = Image{ "./Game_Stage/Heart_stage.png" };
		blood = Image{ "./Game_Stage/blood.png" };
		Gaugeba = Image{ "./Game_Stage/Gaugeba.png" };
		Gaugeba2 = Image{ "./Game_Stage/Gaugeba2.png" };
		Gauge = Image{ "./Game_Stage/Gauge.png" };
		Gauge2 = Image{ "./Game_Stage/Gauge2.png" };
		GAME_OVER = Image{ "./Game_Stage/GAME_OVER.jpg" };
		GAME_OVER3 = Image{ "./Game_Stage/GAME_OVER3.jpg" };
		game_clear = Image{ "./Game_Stage/game_clear.jpg" };
		gateway = Image{ "./Game_Stage/gateway.png" };
		Ending1 = Image{ "./Game_Stage/Ending.jpg" };
		Ending2 = Image{ "./Game_Stage/Ending2.jpg" };
		Ending3 = Image{ "./Game_Stage/Ending3.jpg" };
		Ending4 = Image{ "./Game_Stage/Ending4.jpg" };
		Stage5_Start = Image{ "./Game_Stage/Stage5_Start.jpg" };
	}

	void logic() {
		//이곳에 캐릭터또는 키보드를 이용한 움직임

		draw_image(Stage5_Start, 0, 0, 720, 720);

		if (GetAsyncKeyState(VK_RETURN) & 0x0001 && Ending != true) {
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
					if (prev_time > 0.4) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지2" << endl;
					}
				}
				else {
					if (prev_time > 0.8) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지" << endl;
					}
				}
				if (heart_gauge2) {
					if (prev_time > 0.2) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지3" << endl;
					}
				}
				if (heart_gauge3) {
					if (prev_time > 0.05) {                                    // 심장 게이지
						prev_time = 0;
						if (counter2 < 14) counter2++;
						//		cout << "심장 게이지4" << endl;
					}
				}
				Heart = false;
			}



			if (counter2 == 14) {
				Heart = true;
				is_Gauge2 = true;

			}

			if (Heart) {
				Heart_L = 1100;
				Heart_T = 800;
				counter2 = 0;
				is_Gauge2 = false;
			}

			if (Heart == false) {
				Heart_L = 1000;
				Heart_T = 700;
			}






			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				if (y5_1 <= -100) {
					y5_1 += 2;
				}
			}
			else {
				if (y5_1 >= -200) {
					y5_1 -= 4;
				}
			}

			for (int i = 0; i < counter; ++i) {
				draw_image(Gauge, Gauge_x + i * 5, 300, 5, 25);

			}

			if (y5_1 >= -100) {
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



			if (counter == 35) {
				heart_gauge = true;
				cout << "심장 게이지 ON" << endl;
			}
			if (counter == 58) {
				heart_gauge2 = true;
				heart_gauge = false;
				cout << "심장 게이지2 ON" << endl;
			}
			if (counter == 100) {
				heart_gauge2 = false;
				heart_gauge3 = true;
				cout << "심장 게이지3 ON" << endl;
			}
		}

		if (Manager)
		{
			if (Heart == true) {
				if (y5_1 <= 0) {
					if (y5_1 >= -150) {
						is_trigger = true;
						Start = false;

					}
				}
			}
		}

		if (is_trigger) {
			if (GetAsyncKeyState(VK_TAB) & 0x8000) {
				cout << "탭" << endl;
				game_over = true;
			}
		}

		if (game_over) {
			reset();
		}


		if (counter == 122) {
			draw_image(game_clear, 0, 250, 650, 450);
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
							Ending = true;

						}
					}
				}
			}

			if (x5 >= 80) {
				if (x5 <= 270) {
					if (y5 <= 250) {
						if (y5 >= -10) {
							GAMEOVER = true;
							Start = false;
						}
					}
				}
			}

			if (GAMEOVER) {
				if (GetAsyncKeyState(VK_TAB) & 0x8000) {
					cout << "탭" << endl;
					game_over = true;
				}
			}

		}

		if (Ending)
		{
			bool Last = false;
			bool characters = false;
			bool Heart = false;
			bool is_Gauge2 = false;
			bool is_trigger = false;
			bool GAMEOVER = false;
			bool heart_gauge = false;
			bool heart_gauge2 = false;
			bool Start = false;
			bool Manager = true;

			if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {

				if (en_num < 3 && RETURN_key == false) {
					en_num++;
				}
				RETURN_key = true;
			}
			else {
				RETURN_key = false;
			}
		}

	}
	void draw() {
		//이곳에 스테이지 배경 캐릭터사진 

		if (Start == true) {
			draw_image(Back, 0, 0, 720, 720);
			draw_image(Heart_stage, 0, 0, Heart_L, Heart_T);
			draw_image(Gaugeba, 0, 300, 650, 50);
			draw_image(Gaugeba2, 240, 230, 150, 40);

			for (int j = 0; j < counter2; ++j) {
				draw_image(Gauge2, Gauge2_x + (13 + j * 9.9), 230, 9.9, 20);
			}

			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				draw_image(germ3, 0, y5_1, 150, 170);
				draw_image(blood, -4, -30, 920, 650);
				if (y5_1 <= -10) {
					y5_1 += 5;
				}
			}
			else {
				draw_image(germ3, 0, y5_1, 120, 170);
				draw_image(blood, -4, -30, 920, 650);
				if (y5_1 >= -200) {
					y5_1 -= 5;
				}
			}

			for (int i = 0; i < counter; ++i) {
				draw_image(Gauge, Gauge_x + i * 5, 300, 5, 25);
			}
		}

		if (is_trigger) {
			draw_image(GAME_OVER, 0, 0, 720, 720);
			Start = false;
		}


		if (counter == 122) {
			draw_image(game_clear, 0, 0, 720, 720);
			if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
				Last = true;
				Start = false;
			}
		}

		if (Last) {
			draw_image(gateway, 0, 0, 720, 720);
			draw_image(germ1, x5, y5, 80, 150);
		}

		if (GAMEOVER) {
			draw_image(GAME_OVER3, 0, 0, 720, 720);
		}
		if (Ending) {
			switch (en_num) {
			case 0:
				draw_image(Ending1, 0, 0, 720, 720);
				break;
			case 1:
				draw_image(Ending2, 0, 0, 720, 720);
				break;
			case 2:
				draw_image(Ending3, 0, 0, 720, 720);
				break;
			case 3:
				draw_image(Ending4, 0, 0, 720, 720);
				break;
			}
		}


	} // draw 끝

	int end() {
		return finish_count;
	}
};

Stage1 stage1;
Stage2 stage2;
Stage3 stage3;
Stage4 stage4;
Stage5 stage5;

void reset() {
	count_num = 1;
	stage1.start();
	stage2.start();
	stage3.start();
	stage4.start();
	stage5.start();
}
//스테이지를 넘어가는곳 건드릴 필요없음
int main() {

	stage1.init();

	stage2.init();

	stage3.init();

	stage4.init();

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