﻿#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1A_ウエダリョウタ";

const int kWindowWith = 1280;
const int kWindowHeight = 720;

int Enemy::isEnemy = 1;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Novice::AllowWindowSizeChanged(TRUE);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player;
	player = new Player({ 640,640,40 }, 6);

	Enemy* enemy[2];
	enemy[0] = new Enemy(100, 300, player);
	enemy[1] = new Enemy(200, 400, player);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Update(keys, preKeys);
		if (Enemy::isEnemy) {
			enemy[0]->Update();
			enemy[1]->Update();
		}

		if (keys[DIK_R]) {
			Enemy::isEnemy = 1;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		if (Enemy::isEnemy) {
			enemy[0]->Draw();
			enemy[1]->Draw();
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}