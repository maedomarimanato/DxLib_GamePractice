#include"InputControl.h"
#include"DxLib.h"

/**********************
*�}�N����`
***********************/

#define XINPUT_BUTTON_MAX (16)  //�R���g���[���[�̃{�^����

/**********************
*�^��`
***********************/

enum KEY_STATE
{
	E_NONE, //������
	E_CLICK,//�������u��
	E_PRESS,//���������Ă�
	E_RELEASED,//������
	E_KEY_STATE_MAX
};

/*******************
*�ϐ��錾
********************/

KEY_STATE button_state[XINPUT_BUTTON_MAX]; //�e�{�^�����͏��

/********************
*�v���g�^�C�v�錾
*********************/

/********************
*���͐���@�\�F����������
*�����F�Ȃ�
*�߂�l�F�Ȃ�
*********************/

void InputControl_Initialize(void)
{
	int i; //���[�v�J�E���^

	//���͏�Ԃ̏�����
	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		button_state[i] = E_NONE;
	}
}

/**********************
*���͐���@�\�F�X�V����
*�����F�Ȃ�
*�߂�l�F�Ȃ�
***********************/

void InputControl_Update(void)
{
	int i;
	XINPUT_STATE input_controller; //�R���g���[���[���͏��

	//�R���g���[���[�̓��͏����擾
	GetJoypadXInputState(DX_INPUT_PAD1,&input_controller);

	//���͏�Ԃ̍X�V
	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		if (input_controller.Buttons[i] == TRUE)
		{
			switch (button_state[i])
			{
			case E_NONE:
			case E_RELEASED:
				button_state[i] = E_CLICK;
				break;
			case E_CLICK:
			case E_PRESS:
				button_state[i] = E_PRESS;
				break;
			default:
				button_state[i] = E_NONE;
				break;
			}
		}
		else
		{
			switch (button_state[i])
			{
			case E_NONE:
			case E_RELEASED:
				button_state[i] = E_NONE;
				break;
			case E_CLICK:
			case E_PRESS:
				button_state[i] = E_RELEASED;
				break;
			default:
				button_state[i] = E_NONE;
				break;
			}
		}
	}
}

/***************************************************
*���͐���@�\�F������Ă��邩���菈��
*�����FXINPUT�̃{�^����� 
*XINPUT_BUTTON_DOAD_UP(0)�@//�f�W�^�������{�^����
*XINPUT_BUTTON_DOAD_DOWN(1)//�f�W�^�������{�^����
*XINPUT_BUTTON_DOAD_LEFT(2)//�f�W�^�������{�^����
*XINPUT_BUTTON_DOAD_RIGHT(3)//�f�W�^�������{�^���E
*XINPUT_BUTTON_STATE(4)//START�{�^��
*XINPUT_BUTTON_BACK(5)//BACK�{�^��
*XINPUT_BUTTON_LEFT_THUMB(6)//���X�e�B�b�N��������
*XINPUT_BUTTON_RIGHT_THUMB(7)//�E�X�e�B�b�N��������
*XINPUT_BUTTON_LEFT_SHOULDER(8)//LB�{�^��
*XINPUT_BUTTON_RIGHT_SHOULDER (9)//RB�{�^��
*XINPUT_BUTTON_A(12) //A�{�^��
*XINPUT_BUTTON_B(13)//B�{�^��
*XINPUT_BUTTON_X(14)//X�{�^��
*XINPUT_BUTTON_Y(15)//Y�{�^��
*�߂�l�FTRUE�i������Ă���j,FALSE�i������ĂȂ��j
***************************************************/

int GetButton(int button)
{
	int ret = FALSE;

	if (button_state[button] == E_CLICK || button_state[button] == E_PRESS)
	{
		ret = TRUE;
	}

	return ret;
}

/***************************************************
*���͐���@�\�F�������u�Ԃ����菈��
*�����FXINPUT�̃{�^����� 
*XINPUT_BUTTON_DPAD_UP(0) //�f�W�^�������{�^����
*XINPUT_BUTTON_DPAD_Down(1)//�f�W�^�������{�^����
*XINPUT_BUTTON_DPAD_LEFT(2)//�f�W�^�������{�^����
*XINPUT_BUTTON_DPAD_RIGHT(3)//�f�W�^�������{�^���E
*XINPUT_BUTTON_STATE(4)START�{�^��
*XINPUT_BUTTON_BACK(5)//BACK�{�^��
*XINPUT_BUTTON_LEFT_THUMB(6)//���X�e�B�b�N��������
*XINPUT_BUTTON_RIGHT_THUMB(7)//�E�X�e�B�b�N��������
*XINPUT_BUTTON_LEFT_SHOULDER�@�i8�j
*XINPUT_BUTTON_RIGHT_SHOULDER (9)
*XINPUT_BUTTON_A(12)
*XINPUT_BUTTON_B(13)
*XINPUT_BUTTON_X(14)
*XINPUT_BUTTON_Y(15)
*�߂�l�FTRUE�i�������u�ԁj,FALSE�i�������u�Ԃł͂Ȃ��j
****************************************************/
	
int GetButtonDown(int button)
{
	int ret = FALSE;

if(button_state[button]== E_CLICK)
{
	ret = TRUE;
}
return ret;
}

/******************************************************
*���͐���@�\�F�����������菈��
*�����FXINPUT�̃{�^�����
*XINPUT_BUTTON_DPAD_UP (0)//�f�W�^��������{�^��
*XINPUT_BUTTON_DPAD_DOWN�i1�j//�f�W�^���{�^��������
*XINPUT_BUTTON_DPAD_LEFT�i2�j//�f�W�^�������{�^����
*XINPUT_BUTTON_DPAD_RIGHT�i3�j//�f�W�^�������{�^���E
*XINPUT_BUTTON_STATE�i4�j//START�{�^��
*XINPUT_BUTTON_BACK�i5�j//BACK�{�^��
*XINPUT_BUTTON_LEFT_THUMB�i6�j//���X�e�B�b�N��������
*XINPUT_BUTTON_RIGHT_THUMB�i7�j//�E�X�e�B�b�N��������
*XINPUT_BUTTON_LEFT_SHOULDER�i8�j//LB�{�^��
*XINPUT_BUTTON_SHOULDER�i9�j//RB�{�^��
*XINPUT_BUTTON_A�i12�j//A�{�^��
*XINPUT_BUTTON_B�i13�j//B�{�^��
*XINPUT_BUTTON_X�i14�j//X�{�^��
*XINPUT_BUTTON_Y�i15�j//Y�{�^��
*�߂�l�FTRUE�i�������u��),FALSE(�������u�Ԃł͂Ȃ��j
*****************************************************/

int GetButtonUp(int button)
{
	int ret = FALSE;

	if (button_state[button] == E_RELEASED)
	{
		ret = TRUE;
	}

	return ret;
}

/*********************************************************
*���͐���@�\�F�Q�[���I���p�̃{�^�����菈��
*�����F�Ȃ�
*�߂�l�FTRUE�i�������u�ԁj,(FALSE(�������u�Ԃł͂Ȃ��j
*********************************************************/

int GetExitButton(void)
{
	int ret = FALSE;

	if ((GetButtonDown(XINPUT_BUTTON_BACK) == TRUE) || (CheckHitKey(KEY_INPUT_ESCAPE) ==
		TRUE))
	{
		ret = TRUE;
	}
	return ret;
}
