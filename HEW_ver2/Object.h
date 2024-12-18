#pragma once
#include"direct3d.h"
#include"WICTextureLoader.h" //テクスチャ読み込みライブラリ
class Object {
private:
	// 頂点データを決める
	Vertex vertexList[4] =
	{                       //R,   G,   B,   A
		{ -0.5f,  0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 0.0f,0.0f },  // ０番目の頂点座標　{ x, y, z }
		{  0.5f,  0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 1.0f,0.0f },  // １番目の頂点座標
		{ -0.5f, -0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 0.0f,1.0f },  // ２番目の頂点座標
		{  0.5f, -0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f },  // ３番目の頂点座標
	};
	
	// 頂点バッファ
	ID3D11Buffer* m_pVertexBuffer;
	//テクスチャ用変数　　　　　　　　　
	ID3D11ShaderResourceView* m_pTextureView;            //※これを増やせばテクスチャが増える　　　　　　　　　

	//座標
	 DirectX::XMFLOAT3 pos = {0.0f,0.0f,0.0f};
	 //大きさ
	 DirectX::XMFLOAT3 size = { 100.0f,100.0f,0.0f };

	 //角度
	 float angle =0.0f;

	 //色
	 DirectX::XMFLOAT4 color = { 1.0f,1.0f,1.0f,1.0f };

	//
	 DirectX::XMFLOAT2 UV = { 0.0f,1.0f};


	 //テクスチャが縦横にに何分割されているか
	 int splitX = 1;
	 int splitY = 1;
	 
	 //半径用
	 float r;

public:
	//左から何段目を切り抜いて表示するか
	int numU = 0;
	int numV = 0;
	
	void Init(const wchar_t* imgname,int sx=1,int sy=1);  //初期化
	void Draw(void);                       //描画
	void Uninit(void);                    //終了
	void SetPos(float x, float y, float z);//座標をセット
	void SetSize(float x, float y, float z);//大きさをセット
	void SetAngle(float a);//角度をセット
	void SetColor(float r, float g, float b, float a); //色をセット
	void SetUV(float u, float v);
	void CutUV(float U, float V);
	DirectX::XMFLOAT3 GetPos(void); //座標をゲット
	DirectX::XMFLOAT3 GetSize(void); //大きさをゲット
	float GetAngle(void);            //角度をゲット
	DirectX::XMFLOAT4 GetColor(void); //色をゲット
	DirectX::XMFLOAT2 GetUV(void); //切り取りの値ゲット


};