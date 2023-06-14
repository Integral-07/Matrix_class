#include<iostream>

/*
	�ȈՍs��N���X Matrix
	
	�ȈՔłȂ̂Ő�����v�f�Ƃ���s��݈̂�����.
	�|���o���@��K���A�s��ςȂǒǉ��\��.


	�ȉ��ɊȒP�Ȏg�p�@���L��
*/

// matrix�w�b�_���C���N���[�h����
#include"matrix.h"


int main(void) {

	//�C�ӂ̗v�f���܂񂾔z���p�ӂ���

	int arr[3 * 2] = {
		3, 6, 
		2, 4,
		1, 2
	};

	int arr_2[][2] = {
		{1, 1},
		{2, 2},
		{3, 3}
	};


	//�s��𐶐�����(�C���X�^���X�̐���)
	Matrix A(arr, 3, 2);    // arr�̗v�f�𔽉f�����s��A�̐���
	Matrix B(*arr_2, 3, 2); // arr_2�̗v�f�𔽉f�����s��B�̐���

	Matrix _A;              //�ڍׂ��w�肵�Ȃ���2�s2��̒P�ʍs��𐶐�����

	/*
		�s�񓯎m�̉��Z

		��`����Ă��鉉�Z�q
		+, -, *, ==, +=, -=, *=
	*/

	Matrix C = A + B;

	C -= B;

	/*
	�P�ʍs��A�[���s��𐶐�����
	*/
	Matrix D = D.Identity(3, 3);  //3�s3��̒P�ʍs��
	Matrix _D = D.Identity(2, 3); //�����s��łȂ��w��͖���

	Matrix E = E.Zero(2, 3);

	/*
	�s����o�͂���

	�}���q << ���I�[�o�[���[�h����Ă���
	*/
	std::cout << A << "\n   +\n\n" << B << "\n  ||\n\n" << A + B << std::endl;


	/*
	
	�g��W���s������

	���Z�q | ���I�[�o�[���[�h����Ă���
	*/

	Matrix F = A | B;
	std::cout << "  (A | B)  \n\n    ||\n\n" << F << std::endl;

	return 0;
}