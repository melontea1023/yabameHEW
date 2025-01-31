#pragma once

#include <xaudio2.h>

// サウンドファイル
typedef enum
{
	SOUND_LABEL_TITLE = 0,		// タイトル
	SOUND_LABEL_BATTLE,			// バトル
	SOUND_LABEL_RESULT,			// リザルト
	SOUND_LABEL_ADVANM,
	SOUND_LABEL_ADVRAIN,			// サンプルSE
	SOUND_LABEL_LINK,//リンク
	SOUND_LABEL_FRAP,//はたく
	SOUND_LABEL_FRAPBOSS,//当たった
	SOUND_LABEL_WIN,
	SOUND_LABEL_LOSE,

	SOUND_LABEL_MAX,
} SOUND_LABEL;

class Sound {
private:
	// パラメータ構造体
	typedef struct
	{
		LPCSTR filename;	// 音声ファイルまでのパスを設定
		bool bLoop;			// trueでループ。通常BGMはture、SEはfalse。
	} PARAM;

	PARAM m_param[SOUND_LABEL_MAX] =
	{
		{"asset/BGM/TITLE.wav", true},	// サンプルBGM（ループさせるのでtrue設定）
		{"asset/BGM/BATTLE.wav", true},	// サンプルBGM
		{"asset/BGM/RESULT.wav", true},  		// サンプルSE（ループしないのでfalse設定）
		{"asset/SE/ADVANIM.wav", false},
		{"asset/SE/ADVRAIN.wav", false},		// サンプルSE
		{"asset/SE/LINKSOOT.wav", false},
		{"asset/SE/FLAP.wav", false},
		{"asset/SE/FLAPHIT.wav", false},
		{"asset/SE/WIN.wav", false},
		{"asset/SE/LOSE.wav", false}


	};

	IXAudio2* m_pXAudio2 = NULL;
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;
	IXAudio2SourceVoice* m_pSourceVoice[SOUND_LABEL_MAX];
	WAVEFORMATEXTENSIBLE m_wfx[SOUND_LABEL_MAX]; // WAVフォーマット
	XAUDIO2_BUFFER m_buffer[SOUND_LABEL_MAX];
	BYTE* m_DataBuffer[SOUND_LABEL_MAX];

	HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
	HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

public:
	// ゲームループ開始前に呼び出すサウンドの初期化処理
	HRESULT Init(void);

	// ゲームループ終了後に呼び出すサウンドの解放処理
	void Uninit(void);

	// 引数で指定したサウンドを再生する
	void Play(SOUND_LABEL label);

	// 引数で指定したサウンドを停止する
	void Stop(SOUND_LABEL label);

	// 引数で指定したサウンドの再生を再開する
	void Resume(SOUND_LABEL label);

};