#pragma once

#include <xaudio2.h>

// �T�E���h�t�@�C��
typedef enum
{
	SOUND_LABEL_TITLE = 0,		// �^�C�g��
	SOUND_LABEL_BATTLE,			// �o�g��
	SOUND_LABEL_RESULT,			// ���U���g
	SOUND_LABEL_ADVANM,
	SOUND_LABEL_ADVRAIN,			// �T���v��SE
	SOUND_LABEL_LINK,//�����N
	SOUND_LABEL_FRAP,//�͂���
	SOUND_LABEL_FRAPBOSS,//��������
	SOUND_LABEL_WIN,
	SOUND_LABEL_LOSE,

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
		{"asset/BGM/TITLE.wav", true},	// �T���v��BGM�i���[�v������̂�true�ݒ�j
		{"asset/BGM/BATTLE.wav", true},	// �T���v��BGM
		{"asset/BGM/RESULT.wav", true},  		// �T���v��SE�i���[�v���Ȃ��̂�false�ݒ�j
		{"asset/SE/ADVANIM.wav", false},
		{"asset/SE/ADVRAIN.wav", false},		// �T���v��SE
		{"asset/SE/LINKSOOT.wav", false},
		{"asset/SE/FLAP.wav", false},
		{"asset/SE/FLAPHIT.wav", false},
		{"asset/SE/WIN.wav", false},
		{"asset/SE/LOSE.wav", false}


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