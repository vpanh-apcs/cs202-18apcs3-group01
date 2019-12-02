﻿#include "Route.h"

class CGAME 
{
	//CTRUCK* axt;
	//CCAR* axh;
	//CDINOSAUR* akl;
	//CBIRD* ac;
	//CPEOPLE cn;
	//vector<Obstacle> obstacles;
	int level = 1;
	int width, height;
	Pos location;
	int map[10][10];
	Route* routes[10];
	CPEOPLE people = CPEOPLE(Pos(19,25));
	bool stop = false;
public:
	CGAME(Pos locationt, int heightt, int widtht); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	~CGAME() { delete[] routes; }; // Hủy tài nguyên đã cấp phát
	//CPEOPLE getPeople() {};//Lấy thông tin người
	//CVEHICLE* getVehicle();//Lấy danh sách các xe
	//CANIMAL* getAnimal(); //Lấy danh sách các thú
	void resetGame() {}; // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE) {}; // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void loadGame(ostream) {}; // Thực hiện tải lại trò chơi đã lưu
	void saveGame(ostream) {}; // Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(); // Tạm dừng Thread
	void resumeGame(HANDLE) {}; //Quay lai Thread
	//void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	//void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	//void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void routesMove();
	void controller();
};
