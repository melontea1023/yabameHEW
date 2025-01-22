#pragma once

#include <d3d11.h>  // DirectX11を使うためのヘッダーファイル
#include<DirectXMath.h> //DirectXの数学関連のヘッダーファイル
#include "input.h"

#define SCREEN_WIDTH (1920)	// ウインドウの幅
#define SCREEN_HEIGHT (1080)	// ウインドウの高さ

// 関数のプロトタイプ宣言
HRESULT D3D_Create(HWND hwnd);
void    D3D_Release();
void    D3D_StartRender();
void    D3D_FinishRender();

// 構造体の定義
// 頂点データを表す構造体
struct Vertex
{
	// 頂点の位置座標
	float x, y, z;

	//色
	float r, g, b, a;

	//テクスチャ座標(UV座標)
	float u, v;

};

//定数バッファ用構造体
struct ConstBuffer
{
	//頂点カラー行列
	DirectX::XMFLOAT4 color;
	//UV座標移動行列
	DirectX::XMMATRIX matrixTex;
	//プロジェクション変換行列
	DirectX::XMMATRIX matrixProj;
	//ワールド変換行列
	DirectX::XMMATRIX matrixWorld;
};

extern ID3D11Device* g_pDevice;
extern ID3D11DeviceContext* g_pDeviceContext;
extern ID3D11Buffer* g_pConstantBuffer;


// Direct3D解放の簡略化マクロ
#define SAFE_RELEASE(p) { if( NULL != p ) { p->Release(); p = NULL; } }
