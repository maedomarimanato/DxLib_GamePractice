#include "TitlScene.h"
#include "DxLib.h"
#include "InputControl.h"
#include "SceneManager.h"

/******************
*�}�N����`
*******************/

/******************
*�^��`
*******************/

/******************
*�ϐ��錾
*******************/

int Titlemage;
int TitleBGM;


/******************
*�v���g�^�C�v�錾
******************/

/*****************
*�^�C�g����ʁF����������
*�����F����
*�߂�l�F�G���[���
******************/

int TitleScene_Initialize(void)
{
	int ret = 0;

	//��ǂݍ��ݏ���
	TitleImage = LoadGraph("image/title.pug");

	if (TitleImage == D_ERROR)
	{
		ret = D_ERROR;
	}
	if (TitleBGM == D_ERROR)
	{
		ret = D_ERROR;
	}

	return ret;
}

/*******************
*�^�C�g����ʁF�X�V����
*�����F�Ȃ�
*�߂�l�F�Ȃ�
********************/

void TitleScene_update(void)
{
	//	�^�C�g��BGM
	if (CheckSoundMem(TitleBGM) == 0)
	{
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK);
	}

	if(GetKeyFlg(MOUSE_INPUT_LEFT)==TRUE)
    {
	if (GetMousePositionX() > 120 && GetMousePositionX()_<290 &&
		GetMousePosition() > 260 && GetMousePositionY() < 315)
	{
		Change_Scene(E_GAMEMAIN);

		StopSoundMen(TitleBGM);
	}
	if (GetMousePositionX() > 120 && GetMouseX() < 220 &&
		GetMousePositionY() > 345 && GetMOusePositionY() < 400)
	{
		Change_Scene(E_END);
		StopSoundMem(TitleBGM);
	}
  }
}

/***********************
*�^�C�g����ʁF�`�揈��
*�����F�Ȃ�
*�߂�l�F�Ȃ�
************************/

void TitleScene_Draw(void)
{
	//�^�C�g����ʂ�\��
	DrawGraph(0, 0, TitleImage, FALSE);
}





