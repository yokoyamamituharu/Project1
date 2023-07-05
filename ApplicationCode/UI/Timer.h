#pragma once
#include "Sprite.h"

class Timer
{
public: //メンバ関数
    Timer() = default;
    ~Timer() = default;
    /// <summary>
    /// 初期化
    /// </summary>
    void Initialize(const int32_t maxTime);
    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

private: //メンバ関数
    /// <summary>
    /// 時間から回転角を求める
    /// </summary>
    void RotCulc();

private: //メンバ変数
    //現在時間
    int32_t nowTime_;
    //最大時間
    int32_t maxTime_;
    //時計
    std::unique_ptr<Sprite> watch_;
    //長針
    std::unique_ptr<Sprite> bigHand_;
    //短針
    std::unique_ptr<Sprite> littleHand_;
    //長針回転
    float bigHandRot_;
    //短針回転
    float littleHandRot_;
};