#include <DxLib.h>

struct Vector2 {
	float x, y;
};

using Posision2 = Vector2;

struct Rect {
	Posision2 center;
	float w, h;
	float Left()const {
		return center.x - w;
	}
	float Right()const {
		return center.x + w;
	}
	float Top()const {
		return center.y - h;
	}
	float Bottom()const {
		return center.y + h;
	}
};


int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {

	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rcA = { 200, 200, 50, 50 };
	char keystate[256];
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();
		constexpr float speed = 4.0f;

		GetHitKeyStateAll(keystate);
		if (keystate[KEY_INPUT_W]) {
			rcA.center.y -= speed;
		}
		if (keystate[KEY_INPUT_A]) {
			rcA.center.x -= speed;
		}
		if (keystate[KEY_INPUT_S]) {
			rcA.center.x += speed;
		}
		if (keystate[KEY_INPUT_D]) {
			rcA.center.y += speed;
		}
		DrawBox(rcA.Left(), rcA.Right(), rcA.Top(), rcA.Bottom(), 0xffffff, true);



		ScreenFlip();
	}
	DxLib_End();
}