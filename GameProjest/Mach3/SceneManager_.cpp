#include"SceneManager.h"
#include"TitiScene.h"
#include"GameMainScene.h"
#include"GameClearScene"
#include"GameOverScene.h"

/***************************
*�}�N����`
****************************/

GAME_MODE Game_Mode;
GAME_MODE Next_Mode;

/***************************
*�v���g�^�C�v�錾
***************************/

/**************************
*�V�[���Ǘ��@�\�F����������
*�����F�Q�[�����[�h���
*�߂�l�F�Ȃ�
**************************/

int SceneManager_Initialize(GAME_MODE mode)
{
	int Read_Error;

	//�V�[���ǂݍ��ݏ���
	//�^�C�g�����

	Read_Error = TitieScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR;
	}

	//�Q�[�����C�����
	Read_Error = GameMainScene_Initialize();
	if (read_Error == D_ERROR)
	{
		return D_ERROR;
	}

	//�Q�[���N���A���
	Read_Error = GameClearScene_Initialize();
	if (read_Error == D_ERROR)
	{
		return D_ERROR;
	}

	//�Q�[���N���A���
	Read_Error = GameOverScene_Initialize();
	if (Read_Error == D_ERROR)
	{
		return D_ERROR
	}

	Game_Mode = mode;
	Next_Mode = Game_Mode;

	return Read_Error
}

//�Q�[���I�[�o�[���
Read_Error = GameOverScene_Initialize();
if (Read_Error == D_ERROR)
{
	return D_ERROR;
}

Game_Mode = mode;
Nextde = Game_Mode;
}

/******************************
*�V�[���Ǘ��@�\
*�����F�Ȃ�
*�߂�l�F�Ȃ�
******************************/

void SceneManager_Update(void)
{
	//�O�t���[���ƃQ�[�����[�h������Ă�����V�[����؂�ւ���
	if (Game_Mode != Next_Mode)
	{
		SceneManager_Initialize(Next_Mode);
	}

	//�e��ʂ̍X�V����

	switch (Game_Mode)
	{
	case E_TITLE:
		TitieScene_Update();
		break;
	case E_GAMEMAIN:
		GameMainScene_Update();
		break;
	case E_GAME_CLEAR:
		GameOverScene_Update();
		break;
		default;
		break;
	}
}

/******************************
*�V�[���Ǘ��@�\�F�`�揈��
*�����F�Ȃ�
*�߂�l�F�Ȃ�
******************************/

void SceneManager_Draw(void)
{
	//�e��ʂ̕`�揈��
	switch (Game_Mode)
	{
	case E_TITLE:
		TitieScene_Draw();
		break;
	case E_GAMEMAIN:
		GameMainScene_Draw();
		break;
	case E_GAME_CLEAR:
		GameClearScene_Draw();
		break;
	case E_GAME_OVER:
		GameOverScene_Draw();
		break;
	dafault:
		break;
	}
}

/******************************
*�V�[���Ǘ��@�\�F�V�[���ؑ֏���
*�����F�ύX����Q�[�����[�h
*�߂�l�F�Ȃ�
******************************/
void Change_Scene(GAME_MODE mode)
{
	Next_Mode = mode;
}
