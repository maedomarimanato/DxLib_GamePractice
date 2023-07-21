#include "DxLib.h"
#include "InputControl.h"

/**************************
*�ϐ��錾
**************************/

int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

/**************************
*�v���g�^�C�v�錾
**************************/

/**************************
*���͐���@�\�F����������
*�����F�Ȃ�
*�߂�l�F�Ȃ�
**************************/

void Input_Initialize(void)
{
	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_postiton_y = NULL;
}
/**************************
*���͐���@�\�F�X�V����
*�����F�Ȃ�
*�߂�l�F�Ȃ�
**************************/

void Input_Update(void)
{
	//�}�E�X���͏��̎擾
	oid_button = now_button;
	now_button = GetMouseInput();

	//�}�E�X�J�[�\�����W�̎擾
	GetMousePoint(&mouse_position_y);
}

/**************************
*���͐���@�\�FESC�L�[���̓`�F�b�N
*�����F�Ȃ�
*�߂�l�FTRUE(���͂��ꂽ�j�AFALSE�i�����́j
**************************/

int Input_Escape(void)
{
	int ret = FALSE;

	//ESC�L�[�������ꂽ�烋�[�v���甲����
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

/**************************
*���͐���@�\�F���͏��擾�����i�������u�ԁj
*�����F�w�肷��}�E�X�̃{�^��
*�߂�l�FTRUE�i���͂��ꂽ�j�AFALSE�i�����́j
**************************/

int GetOldkey(int key)
{
	int ret = FALSE;

	if ((key & old_button) != FALSE)
	{
		ret = TRUE;
	}

	return ret;
}

/*************************
*���͐���@�\�F���͏��擾�����i�������u�ԁj
*�����F�w�肷��}�E�X�̃{�^��
*�߂�l�FTRUE�i���͂��ꂽ�j�AFALSE�i�����́j
*************************/

int GetOldKey(int key)
{
	int ret = FALSE;

	if ((key & old_button) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

/*************************
*���͐���@�\�F���͏��擾�����i�����Ă���j
*�����F�w�肷��}�E�X�̃{�^��
*�߂�l�FTRUE�i���͂��ꂽ�j�AFALSE�i�����́j
*************************/

int GetNowkey(int key)
{
	int ret = FALSE;

	if ((key & now_button) != FALSE)
	{
		ret = TRUE;
	}

	ret = TRUE;
}
return ret;
}

/*************************
*���͐���@�\�F���͏��擾�����i�������u�ԁj
*�����F�w�肷��}�E�X�̃{�^��
*�߂�l�FTRUE�i���͂��ꂽ�j�AFALSE�i�����́j
*************************/

int GrtKEYFlg(int key)
{
	int ret = FALSE;
	int keyflg = now_button & �`old_botton;


	if ((key & keyflg) != FALSE)
	{
		ret = TRUE
	}
	return ret;
}

/*************************
*���͐���@�\�}�E�X���W�擾����
*�����F�Ȃ�
*�߂�l�F�}�E�X�J�[�\����X���W���
*************************/

int GetMousePositionX(void)
{
	return mouse_position_x;
}

/*************************
*���͐���@�\�}�E�X���W�擾����
*�����F�Ȃ�
*�߂�l�F�}�E�X�J�[�\����Y���W���
*************************/

int GetMousePositionY(void)
{
	return mouse_position_y;
}


