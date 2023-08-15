/******************************************* 
*プログラミング実習
*マッチ3ゲームの制作
*******************************************/
#include"DxLib.h"
#include"FreamControl.h"
#include"InputControl.h"
#include"SceneManager.h"

/*******************************************
*マクロ定義
********************************************/
#define SCREEN_HEIGHT (480) //スクリーンサイズ（高さ）
#define SCREEN_WIDTH (640) //スクリーンサイズ（幅）
#define SCREEN_COLORBIT (32) //スクリーンカラービット
#define FONT_SIZE (20) //文字サイズ

/*******************************************
*型定義
/*******************************************/

/*******************************************
*グローバル変数定義宣言
*******************************************/

/*******************************************
*プロトタイプ宣言
*******************************************/

/*******************************************
*プログラムの開始
*******************************************/
int WINAPI WinMain(_In_HINSTANCE hInstance, _In_opt_HINSTANCE hPrevInstance,
_In_LPSTR lpCmdLine, _In_int nShowCmd)
{

	//ウィンドウタイトル設定
	SetMainWindowText("Match3 Puzzle");
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);
	//画面サイズの最大サイズ、カラービット数を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//Dxライブラリ初期化処理
	//エラーが発生したら、終了する
	if(DxLib_INit()==D_ERROR)
	{
		return D_ERROR;
	}

	//各機能の初期化処理
	FreamControl_Initialize();    //フレームレート制御機能
	Input_Initialize();   //入力制御機能

	
	
	

	//シーンマネージャー初期化処理
	//エラーが発生したら終了する
	if (SceneMangger_Initialize(E_TITLE) == D_ERROR)
	{
		return D_ERROR;
	}

	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//文字サイズを設定
	SetFontSize(FONT_SIZE);

	//ゲームループ
	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		//入力制御機能変更処理
		Input_Update();

		//シーンマネージャー更新処理
		SceneManager_Update();

		//画面クリア
		ClearDrawScreen();

		//シーンマネージャー画面処理
		SceneManager_Draw();

		//フレームレート制御処理
		FreamControl_Update();

		//画面の内容を表画面に反映
		ScreenFlip();

	}
	//Dxライブラリ使用の終了処理
	DxLib_End();

	return0;
}


	




