#include <DxLib.h>
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {

	ChangeWindowMode(true);
	SetWindowText("1916042_ç◊êÏãP");
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();

		DrawString(100, 100, "Test", 0xffffff);

		ScreenFlip();
	}
	DxLib_End();
}