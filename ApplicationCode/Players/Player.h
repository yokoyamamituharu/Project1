#pragma once
#include "Sprite.h"
#include "Blood.h"
#include "list"
#include "Vector2.h"
#include "ScrollCamera.h"

class KeyInputHandler;
class Player
{
private:
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMVECTOR = DirectX::XMVECTOR;

public:
	enum class State
	{
		none,
		idle,
		heat
	};

	enum class AnimationType
	{
		none,
		front,
		RightSide,
		back,
		LeftSide,
	};

	Player() = default;

	~Player();

	/// <summary>
	/// プレイヤーの生成
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="rote"></param>
	/// <param name="hp"></param>
	/// <param name="maxBlood"></param>
	/// <returns></returns>
	static Player* Create(Vector2 pos, float rote, int hp, int maxBlood);

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="camera"></param>
	void Update(ScrollCamera* camera);

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="scroll"></param>
	void Draw(ScrollCamera* scroll);

	/// <summary>
	/// プレイヤーを指定した位置に進める
	/// </summary>
	/// <param name="vec"></param>
	void AddPlayerVector(Vector2 vec);

	/// <summary>
	/// 座標をセットする
	/// </summary>
	/// <param name="position"></param>
	void SetPosition(Vector2 position) { position_ = position; }

	/// <summary>
	/// プレイヤーの移動速度の取得
	/// </summary>
	/// <returns></returns>
	float GetSpeed() { return speed_; }

	/// <summary>
	/// 座標の取得
	/// </summary>
	Vector2 GetPosition() { return position_; }

	/// <summary>
	/// プレイヤーのHPの取得
	/// </summary>
	int GetPlayerHp() { return playerHp_; }

	/// <summary>
	/// プレイヤーのHPをセットする
	/// </summary>
	/// <param name="playerHp"></param>
	void SetPlayerHp(int playerHp) { this->playerHp_ = playerHp; }

	/// <summary>
	/// 血を取得する
	/// </summary>
	/// <returns></returns>
	std::list<std::unique_ptr<Blood>>& GetBloods() { return bloods_; }

	/// <summary>
	/// 使える血の残量を取得
	/// </summary>
	/// <returns></returns>
	int GetBloodGauge() { return bloodGauge_; }

	/// <summary>
	/// 血の最大値を取得
	/// </summary>
	/// <returns></returns>
	int GetMaxBloodGauge() { return maxBlood_; }	

	/// <summary>
	/// ウルトゲージの値を取得
	/// </summary>
	float GetUltGauge() { return ultGauge; }

	/// <summary>
	/// ウルト最大値
	/// </summary>
	float GetUltMaxGauge() { return ultMaxGauge; }

private:
	/// <summary>
	/// アニメーション画像の生成
	/// </summary>
	/// <param name="imageName"></param>
	/// <param name="animationCount"></param>
	/// <param name="enemyPos"></param>
	/// <returns></returns>
	static std::vector<Sprite*> SpritesCreateP(int imageName, int32_t animationCount, Vector2& pos);

	/// <summary>
	/// 血の発射
	/// </summary>
	/// <param name="camera"></param>
	void Shot(ScrollCamera* camera);

	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="camera"></param>
	/// <returns>移動処理を実行したかどうか</returns>
	bool Move(ScrollCamera* camera);

	/// <summary>
	/// 熱波、寒波の更新
	/// </summary>
	void Wave();

	static  int32_t frontAnimationCount;
	static  int32_t backAnimationCount;
	static  int32_t animationTime;

private:
	std::vector<Sprite*> frontSprites_;
	std::vector<Sprite*> backSprites_;
	Vector2 position_{};
	float heat_ = 0;
	int maxHeatDiray_ = 0;
	int heatDiray_ = maxHeatDiray_;
	int state_ = (int)State::none;
	KeyInputHandler* handler_ = nullptr;
	float speed_ = 4.0f;
	int playerHp_ = 10;
	int maxBlood_ = 0;
	int bloodGauge_ = 0;
	std::list<std::unique_ptr<Blood>>bloods_;
	const int maxShotDiray_ = 10;
	int shotDiray_ = maxShotDiray_;

	Sprite* heatWave_ = nullptr;
	Sprite* coldWave_ = nullptr;

	// 熱波
	bool isHeatWave = false;
	float heatExtend = 0;
	float heatAlpha = 1;

	// 寒波
	bool isColdWave = false;
	float coldExtend = 0;
	float coldAlpha = 1;
	bool isRecall_ = false;

	// ウルト状態
	bool ultState = false;			// ゲージ状態
	float ultGauge = 0;				// ゲージ値
	const float ultMaxGauge = 10;	// ゲージ最大値
	const float maxUltDiray = 60;	// ゲージが減る速度
	float ultDiray = maxUltDiray;

	bool isMove_ = false;
	float angle = 0;
	int useAnimation = 0;
	int useDirectionSide = 0;
	//アニメーションタイマー
	int32_t animationTimer_ = 0;
	//前向きアニメーションカウンター
	int32_t frontAnimationCounter_ = 0;
	//後ろ向きアニメーションカウンター
	int32_t backAnimationCounter_ = 0;
};