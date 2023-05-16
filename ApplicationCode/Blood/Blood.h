#pragma once
#include "Sprite.h"
#include <vector>
#include <map>
class Blood
{
public:
	enum STATE {
		NONE,
		solid,
		liquid,
		gas
	};

	Blood();

	~Blood();

	static Blood* Create(DirectX::XMFLOAT2 position, STATE state);

	static std::unique_ptr<Blood> UniquePtrCreate(DirectX::XMFLOAT2 position, STATE state, DirectX::XMFLOAT2 goal);

	/// <summary>
	/// 
	/// </summary>
	void Update();

	/// <summary>
	/// 温度を上昇させる
	/// </summary>
	void Rising();

	/// <summary>
	/// 温度を減少させる
	/// </summary>
	void Decrease();

	void Draw();

	bool GetDead();

	void SetDead();

	int GetTemperature() { return state_; }

	DirectX::XMFLOAT2 Learp(DirectX::XMFLOAT2 p, DirectX::XMFLOAT2 p2, float time);

	DirectX::XMFLOAT2  GetPos() { return position_; }

private:

public:

private:
	int state_ = NONE;
	DirectX::XMFLOAT2 startPosition_{};
	DirectX::XMFLOAT2 position_{};
	DirectX::XMFLOAT2 vec_{};
	std::map<int, Sprite*> sprites_;
	int deadTimer = 100;
	bool isDead = false;
	DirectX::XMFLOAT2 goal_{};
	float time_ = 0;
};