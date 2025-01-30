#pragma once

#include <xaudio2.h>

// �T�E���h�t�@�C��
typedef enum
{
	SOUND_LABEL_TITLE = 0,		// �T���v��BGM
	SOUND_LABEL_BATTLE,			// �T���v��BGM
	SOUND_LABEL_RESULT,			// �T���v��SE
	SOUND_LABEL_ADVAGO,
	SOUND_LABEL_ADV,			// �T���v��SE
	SOUND_LABEL_LINK,
	SOUND_LABEL_FRAP,
	SOUND_LABEL_FRAPBOSS,



	SOUND_LABEL_MAX,
} SOUND_LABEL;

class Sound {
private:
	// �p�����[�^�\����
	typedef struct
	{
		LPCSTR filename;	// �����t�@�C���܂ł̃p�X��ݒ�
		bool bLoop;			// true�Ń��[�v�B�ʏ�BGM��ture�ASE��false�B
	} PARAM;

	PARAM m_param[SOUND_LABEL_MAX] =
	{
		{"asset/BGM/title.mp3", true},	// �T���v��BGM�i���[�v������̂�true�ݒ�j
		{"asset/BGM/battle.mp3", true},	// �T���v��BGM
		{"asset/BGM/result.mp3", true},  		// �T���v��SE�i���[�v���Ȃ��̂�false�ݒ�j
		{"asset/SE/advago.mp3", false},
		{"asset/SE/adv.mp3", false},		// �T���v��SE
		{"asset/SE/link.mp3", false},
		{"asset/SE/frap.mp3", false},
		{"asset/SE/frapb.mp3", false}


	};

	IXAudio2* m_pXAudio2 = NULL;
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;
	IXAudio2SourceVoice* m_pSourceVoice[SOUND_LABEL_MAX];
	WAVEFORMATEXTENSIBLE m_wfx[SOUND_LABEL_MAX]; // WAV�t�H�[�}�b�g
	XAUDIO2_BUFFER m_buffer[SOUND_LABEL_MAX];
	BYTE* m_DataBuffer[SOUND_LABEL_MAX];

	HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
	HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

public:
	// �Q�[�����[�v�J�n�O�ɌĂяo���T�E���h�̏���������
	HRESULT Init(void);

	// �Q�[�����[�v�I����ɌĂяo���T�E���h�̉������
	void Uninit(void);

	// �����Ŏw�肵���T�E���h���Đ�����
	void Play(SOUND_LABEL label);

	// �����Ŏw�肵���T�E���h���~����
	void Stop(SOUND_LABEL label);

	// �����Ŏw�肵���T�E���h�̍Đ����ĊJ����
	void Resume(SOUND_LABEL label);

};