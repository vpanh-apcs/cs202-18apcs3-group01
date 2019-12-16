#include "Route.h"

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
	int map[20][20];
	Route* routes[20];
	CPEOPLE people = CPEOPLE(Pos(0,10));
	bool stop;
	bool pause;
	char key = '0';
	
public:
	//int map[10][10];
	CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void init();
	//void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	~CGAME() {}; // Hủy tài nguyên đã cấp phát
	//CPEOPLE getPeople() {};//Lấy thông tin người
	//CVEHICLE* getVehicle();//Lấy danh sách các xe
	//CANIMAL* getAnimal(); //Lấy danh sách các thú
	void resetGame() {}; // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE) {}; // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void loadGame(); // Thực hiện tải lại trò chơi đã lưu
	void saveGame(); // Thực hiện lưu lại dữ liệu trò chơi
	void deadGame();
	void pauseGame(); // Tạm dừng Thread
	void resumeGame(HANDLE) {}; //Quay lai Thread
	//void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	//void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	//void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void routesMove();
	void displaySFML();
	void nextLevel();
	int getLevel() { return level; }
	void test();
};
