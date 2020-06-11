#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <graphics.h>
using namespace std;
class Block {
private:
	int x, y;//转轴坐标
	int id;//0=I青,1=J蓝,2=L橙,3=O黄,4=S绿,5=T紫,6=Z红
	int state;//旋转状态
	int** i;//四个格子坐标
public:
	Block(Block& b) {
		x = b.x;
		y = b.y;
		id = b.id;
		state = b.state;
		i = new int* [4];
		for (int j = 0; j < 4; j++)i[j] = new int[2];
	}
	Block(int y1, int x1, int id1, int state1 = 0) :y(y1), x(x1), id(id1), state(state1) {
		i = new int* [4];
		for (int j = 0; j < 4; j++)i[j] = new int[2];
	}
	void Delete() {
		for (int j = 0; j < 4; j++)delete[] i[j];
		delete[] i;
	}//释放方块内存
	int** coordinate() {
		i[0][0] = y;
		i[0][1] = x;
		if (id == 0) {
			if (state == 0 || state == 2) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y;
				i[2][1] = x + 1;
				i[3][0] = y;
				i[3][1] = x + 2;
			}
			else if (state == 1 || state == 3) {
				i[1][0] = y + 1;
				i[1][1] = x;
				i[2][0] = y - 1;
				i[2][1] = x;
				i[3][0] = y - 2;
				i[3][1] = x;
			}
		}
		else if (id == 1) {
			if (state == 0) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y - 1;
				i[2][1] = x - 1;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 1) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y - 1;
				i[2][1] = x + 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
			if (state == 2) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y + 1;
				i[2][1] = x + 1;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 3) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y + 1;
				i[2][1] = x - 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
		}
		else if (id == 2) {
			if (state == 0) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y - 1;
				i[2][1] = x + 1;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 1) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y + 1;
				i[2][1] = x + 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
			if (state == 2) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y + 1;
				i[2][1] = x - 1;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 3) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y - 1;
				i[2][1] = x - 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
		}
		else if (id == 3) {
			i[1][0] = y - 1;
			i[1][1] = x;
			i[2][0] = y - 1;
			i[2][1] = x + 1;
			i[3][0] = y;
			i[3][1] = x + 1;
		}
		else if (id == 4) {
			if (state == 0 || state == 2) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y;
				i[2][1] = x - 1;
				i[3][0] = y - 1;
				i[3][1] = x + 1;
			}
			else if (state == 1 || state == 3) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y;
				i[2][1] = x + 1;
				i[3][0] = y + 1;
				i[3][1] = x + 1;
			}
		}
		else if (id == 5) {
			if (state == 0) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y - 1;
				i[2][1] = x;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 1) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y;
				i[2][1] = x + 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
			if (state == 2) {
				i[1][0] = y;
				i[1][1] = x - 1;
				i[2][0] = y + 1;
				i[2][1] = x;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 3) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y;
				i[2][1] = x - 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
		}
		else if (id == 6) {
			if (state == 0 || state == 2) {
				i[1][0] = y - 1;
				i[1][1] = x;
				i[2][0] = y - 1;
				i[2][1] = x - 1;
				i[3][0] = y;
				i[3][1] = x + 1;
			}
			else if (state == 1 || state == 3) {
				i[1][0] = y - 1;
				i[1][1] = x + 1;
				i[2][0] = y;
				i[2][1] = x + 1;
				i[3][0] = y + 1;
				i[3][1] = x;
			}
		}
		return i;
	}//根据私有变量返回方块四个格子的坐标
	void rotate() {
		if (state < 3)state++;
		else state = 0;
	}
	void Lmove() { x--; }
	void Rmove() { x++; }
	void drop() { y++; }
	int getid() { return id; }
};


class Player {
private:
	int refuse;//积攒垃圾行数，放置下一个方块的瞬间上涨
	Block now, next;//目前方块及下一方块


public:
	int wall[26][16];//边界及所有屏幕内存在方块的位置
	Player() :refuse(0), now(2, 7, rand() % 7), next(2, 7, rand() % 7) {
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 16; j++)
				wall[i][j] = 0;
		for (int i = 0; i < 23; i++)
			wall[i][2] = wall[i][13] = 1;
		for (int j = 3; j <= 12; j++)
			wall[22][j] = 1;
	}


	void produce() {
		now.Delete();
		now = next;
		next = Block(2, 7, rand() % 7);
	}//产生新方块，设置now和next对象


	int clear() {
		int sum = 0, t;
		int i, j, k;
		for (i = 2; i < 22; i++) {
			t = 0;
			for (j = 3; j <= 12; j++) {
				if (wall[i][j] == 0) {
					t++;
				}
			}
			if (t == 0) {
				sum++;
				for (j = i; j >= 2; j--) {
					for (k = 3; k <= 12; k++) {
						wall[j][k] = wall[j - 1][k];
					}
				}
			}
		}
		return sum;
	}//消行，返回消除行数


	void add_refuse(int x) { refuse += x; }


	void rise() {
		int i, j;
		if (height() + refuse <= 20 && refuse != 0) {
			for (i = 2; i < 22 - refuse; i++) {
				for (j = 3; j <= 12; j++) {
					wall[i][j] = wall[i + refuse][j];
				}
			}
			for (i = 22 - refuse; i < 22; i++) {
				for (j = 3; j <= 12; j++) {
					wall[i][j] = 1;
				}
			}
			for (i = 22 - refuse; i < 22; i++) {
				wall[i][rand() % 10 + 3] = 0;
			}
			refuse = 0;
		}
	}//根据refuse数值上涨垃圾行，refuse归零


	int height() {
		for (int i = 2; i < 22; i++) {
			for (int j = 3; j <= 12; j++) {
				if (wall[i][j] == 1)
					return 22 - i;
			}
		}
		return 0;
	}//返回屏幕内方块高度


	bool judge_fail() {
		for (int i = 0; i <= 1; i++)
			for (int j = 3; j <= 12; j++)
				if (wall[i][j] == 1)
					return true;
		if (height() + refuse > 20)
			return true;
		rise();
		return false;
	}//3<=x<=12,0<=y<=1内有方块或height+refuse>20时判定失败


	bool judge_coincide(Block test) {
		int t = 0;
		int** i = test.coordinate();
		for (int j = 0; j < 4; j++)
			if (wall[i[j][0]][i[j][1]] == 1) {
				t++;
				break;
			}
		test.Delete();
		if (t == 1)return true;
		return false;
	}//判断测试砖块与墙是否重合


	void rotate() {
		Block test = now;
		test.rotate();
		if (judge_coincide(test) == false)
			now.rotate();
		else {
			test.Rmove();
			if (judge_coincide(test) == false) {
				now.rotate();
				now.Rmove();
			}
			else {
				test.Lmove();
				test.Lmove();
				if (judge_coincide(test) == false) {
					now.rotate();
					now.Lmove();
				}
				else {
					test.Lmove();
					if (judge_coincide(test) == false) {
						now.rotate();
						now.Lmove();
						now.Lmove();
					}
				}
			}
		}
		test.Delete();
	}//旋转并判断合法性以及踢墙


	void Lmove() {
		Block test = now;
		test.Lmove();
		if (judge_coincide(test) == false)
			now.Lmove();
		test.Delete();
	}//左移


	void Rmove() {
		Block test = now;
		test.Rmove();
		if (judge_coincide(test) == false)
			now.Rmove();
		test.Delete();
	}//右移


	bool drop() {
		Block test = now;
		test.drop();
		if (judge_coincide(test) == false) {
			now.drop();
			test.Delete();
			return false;
		}
		else {
			set();
			test.Delete();
			return true;
		}
	}//下降


	void set() {
		int** i = now.coordinate();
		for (int j = 0; j < 4; j++)
			wall[i[j][0]][i[j][1]] = 1;
		produce();
	}//放置方块


	void Delete() {
		now.Delete();
		next.Delete();
	}//释放方块内存
	int** getnow_coordinate() {
		return now.coordinate();
	}
	int** getnext_coordinate() {
		return next.coordinate();
	}
	int getnow_id() {
		return now.getid();
	}
	int getnext_id() {
		return next.getid();
	}
	int getrefuse() {
		return refuse;
	}
};


class Render {
public:
	void display(Player p1, Player p2) {
		cleardevice();
		setfillcolor(DARKGRAY);
		for (int i = 2; i < 23; i++) {
			for (int j = 2; j < 14; j++) {
				if (p1.wall[i][j] == 1)fillrectangle(j * 20, (i - 2) * 20, (j + 1) * 20, (i - 1) * 20);
				if (p2.wall[i][j] == 1)fillrectangle((j+16) * 20, (i - 2) * 20, (j + 17) * 20, (i - 1) * 20);
			}
		}
		switch (p1.getnow_id())
		{
		case 0:	setfillcolor(CYAN); break;
		case 1:	setfillcolor(BLUE); break;
		case 2:	setfillcolor(BROWN); break;
		case 3:	setfillcolor(YELLOW); break;
		case 4:	setfillcolor(GREEN); break;
		case 5:	setfillcolor(MAGENTA); break;
		case 6:	setfillcolor(RED); break;
		}
		for (int i = 0; i < 4; i++) {
			int** j = p1.getnow_coordinate();
			fillrectangle(j[i][1] * 20,(j[i][0]-2) * 20,(j[i][1]+1) * 20,(j[i][0] - 1) * 20);
		}
		switch (p2.getnow_id())
		{
		case 0:	setfillcolor(CYAN); break;
		case 1:	setfillcolor(BLUE); break;
		case 2:	setfillcolor(BROWN); break;
		case 3:	setfillcolor(YELLOW); break;
		case 4:	setfillcolor(GREEN); break;
		case 5:	setfillcolor(MAGENTA); break;
		case 6:	setfillcolor(RED); break;
		}
		for (int i = 0; i < 4; i++) {
			int** j = p2.getnow_coordinate();
			fillrectangle((j[i][1]+16) * 20, (j[i][0] - 2) * 20, (j[i][1] + 17) * 20, (j[i][0] - 1) * 20);
		}
		switch (p1.getnext_id())
		{
		case 0:	setfillcolor(CYAN); break;
		case 1:	setfillcolor(BLUE); break;
		case 2:	setfillcolor(BROWN); break;
		case 3:	setfillcolor(YELLOW); break;
		case 4:	setfillcolor(GREEN); break;
		case 5:	setfillcolor(MAGENTA); break;
		case 6:	setfillcolor(RED); break;
		}
		for (int i = 0; i < 4; i++) {
			int** j = p1.getnext_coordinate();
			fillrectangle((j[i][1]-1) * 20, (j[i][0] +20) * 20+10, (j[i][1]) * 20, (j[i][0] +21) * 20+10);
		}
		switch (p2.getnext_id())
		{
		case 0:	setfillcolor(CYAN); break;
		case 1:	setfillcolor(BLUE); break;
		case 2:	setfillcolor(BROWN); break;
		case 3:	setfillcolor(YELLOW); break;
		case 4:	setfillcolor(GREEN); break;
		case 5:	setfillcolor(MAGENTA); break;
		case 6:	setfillcolor(RED); break;
		}
		for (int i = 0; i < 4; i++) {
			int** j = p2.getnext_coordinate();
			fillrectangle((j[i][1] + 15) * 20, (j[i][0] + 20) * 20+10, (j[i][1] + 16) * 20, (j[i][0] + 21) * 20+10);
		}
		TCHAR s1[5];
		_stprintf(s1, _T("%d"), p1.getrefuse());
		outtextxy(220, 430, s1);
		TCHAR s2[5];
		_stprintf(s2, _T("%d"), p2.getrefuse());
		outtextxy(540, 430, s2);

	}
};

class Game {
public:
	bool start() {
		srand((int)time(0));
		Render r;
		Player p1, p2;
		int p1_u = 0, p1_l = 0, p1_r = 0, p2_u = 0, p2_l = 0, p2_r = 0;
		int p1_t = 0, p2_t = 0;
		while (1) {
			r.display(p1, p2);
			if (GetAsyncKeyState('W')) {
				if (p1_u == 0) {
					p1.rotate();
					p1_u = 1;
				}
			}
			else p1_u = 0;
			if (GetAsyncKeyState('A')) {
				if (p1_l == 0) {
					p1.Lmove();
					p1_l = 1;
				}
			}
			else p1_l = 0;
			if (GetAsyncKeyState('D')) {
				if (p1_r == 0) {
					p1.Rmove();
					p1_r = 1;
				}
			}
			else p1_r = 0;
			if (GetAsyncKeyState(VK_UP)) {
				if (p2_u == 0) {
					p2.rotate();
					p2_u = 1;
				}
			}
			else p2_u = 0;
			if (GetAsyncKeyState(VK_LEFT)) {
				if (p2_l == 0) {
					p2.Lmove();
					p2_l = 1;
				}
			}
			else p2_l = 0;
			if (GetAsyncKeyState(VK_RIGHT)) {
				if (p2_r == 0) {
					p2.Rmove();
					p2_r = 1;
				}
			}
			else p2_r = 0;
			if (p1_t >= 50) {
				p1_t -= 50;
				if (p1.drop()) {
					p2.add_refuse(p1.clear());
					if (p1.judge_fail()) {
						p1.Delete();
						p2.Delete();
						return false;
					}
					p1.rise();
				}
			}
			if (p2_t >= 50) {
				p2_t -= 50;
				if (p2.drop()) {
					p1.add_refuse(p2.clear());
					if (p2.judge_fail()) {
						p1.Delete();
						p2.Delete();
						return true;
					}
					p2.rise();
				}
			}
			if (GetAsyncKeyState('S')) p1_t += 10;		
			else p1_t++;
			if (GetAsyncKeyState(VK_DOWN)) p2_t += 10;
			else p2_t++;
			Sleep(20);
		}
	}
};

int main() {
	initgraph(640, 480);
	settextstyle(40, 20, _T("黑体"));
	Game g;
	if (g.start()) {
		settextstyle(20, 10, _T("黑体"));
		TCHAR s[] = _T("p1win");
		outtextxy(290, 240, s);
	}
	else {
		settextstyle(20, 10, _T("黑体"));
		TCHAR s[] = _T("p2win");
		outtextxy(290, 240, s);
	}
	Sleep(3000);
}