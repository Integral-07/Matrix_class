#pragma once

#include<iostream>


class Matrix {

private:

	int** array;
	int row = 0, col = 0;


	static int Sigma_array(const Matrix& x, const Matrix& y, int _row, int _col)  {
		//�z��v�f�̐ς̑��a��Ԃ�

		/*
		_row, _col�͉��Z�̑Ώۂ̍s�y�ї�
		*/

		if (x.col == y.row) {
			
			int result = 0;

			for (int k = 0; k < x.col; k++) {
				result += x.array[_row][k] * y.array[k][_col];
			}

			return result;
		}

		else {
			return -1;
		}
	};

public:
	
	//�R���X�g���N�^
	Matrix(int* x, int _row, int _col) {

		row = _row; col = _col;

		//array�z��𓮓I�m��
		array = new int* [row];
		for (int i = 0; i < row; i++) {

			array[i] = new int[col];
		}

		//�z����R�s�[
		for (int c = 0; c < row; c++) {
			for (int d = 0; d < col; d++) {

				array[c][d] = x[d + c * col];
			}
		}
	}

	//�f�t�H���g�R���X�g���N�^
	Matrix() {

		row = 2, col = 2;

		int temp[4] = { 1, 0, 0, 1 };

		//array�z��𓮓I�m��
		array = new int* [row];
		for (int i = 0; i < row; i++) {
			array[i] = new int[col];
		}

		//�z����R�s�[
		for (int c = 0; c < row; c++) {
			for (int d = 0; d < col; d++) {

				array[c][d] = temp[c * col + d];
			}
		}

	}

	//�f�X�g���N�^
	~Matrix() {
		for (int u = 0; u < this->row; u++)
			delete[] array[u];
	}

	//�P�ʍs��ɂ���
	void to_Identity() {

		if (row == col) {

			for (int i = 0; i < this->row; i++)
				for (int j = 0; j < this->col; j++) {

					if (i == j) {
						this->array[i][j] = 1;
					}
					else {
						this->array[i][j] = 0;
					}
				}
		}

		else {

			std::cout << "�^������������܂���." << std::endl;
		}
	}

	//�[���s��ɂ���
	void to_Zero() {

		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < this->col; j++) {
				
				this->array[i][j] = 0;
			}
	}

	//�P�ʍs��𐶐�
	static Matrix Identity(int _row, int _col) {

		if (_row == _col) {

			int* temp_array;
			temp_array = new int[_row * _col];

			for (int i = 0; i < _row; i++)
				for (int j = 0; j < _col; j++) {

					if (i == j)
						temp_array[_col * i + j] = 1;
					else
						temp_array[_col * i + j] = 0;
				}

			return Matrix(temp_array, _row, _col);
		}

		else {

			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}

	//�[���s��𐶐�
	static Matrix Zero(int _row, int _col) {

		int* temp_array;
		temp_array = new int[_row * _col];

		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {

				temp_array[_col * i + j] = 0;
			}
		}
		
		return Matrix(temp_array, _row, _col);
	}

	//�]�u�s��ɂ���
	Matrix T() {

		int* temp_array;
		temp_array = new int[row * col];

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				temp_array[col * j + i] = array[i][j];
			}
		}

		return Matrix(temp_array, col, row); //�s�Ɨ���t�ɂ킽��
	}


//���Z�q�̃I�[�o�[���[�h

	//+���Z�q�̃I�[�o�[���[�h
	friend Matrix operator+(const Matrix& x, const Matrix& y) {

		int* temp_array;
		temp_array = new int[x.row * x.col];

		if (x.row == y.row && x.col == y.col) {

			for (int i = 0; i < x.row; i++) {
				for (int j = 0; j < x.col; j++) {
					temp_array[i * x.col + j] = x.array[i][j] + y.array[i][j];
				}
			}
			return Matrix(temp_array, x.row, x.col);
		}
		
		else {

			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}

	//+=���Z�q�̃I�[�o�[���[�h
	Matrix operator+=(Matrix& x) {
		int* temp_array;
		temp_array = new int[x.row * x.col];

		if (x.row == this->row && x.col == this->col) {

			for (int i = 0; i < x.row; i++) {
				for (int j = 0; j < x.col; j++) {
					temp_array[i * x.col + j] = x.array[i][j] + this->array[i][j];
				}
			}

			return Matrix(temp_array, x.row, x.col);
		}
		
		else {

			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}

	//-���Z�q�̃I�[�o�[���[�h
	friend Matrix operator-(const Matrix& x, const Matrix& y) {

		int* temp_array;
		temp_array = new int[x.row * x.col];

		if (x.row == y.row && x.col == y.col) {

			for (int i = 0; i < x.row; i++) {
				for (int j = 0; j < x.col; j++) {

					temp_array[x.col * i + j] = x.array[i][j] - y.array[i][j];
				}
			}

			return Matrix(temp_array, x.row, x.col);
		}
		
		else {
			
			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}

	//-=���Z�q�̃I�[�o�[���[�h
	Matrix operator-=(Matrix& x) {

		int* temp_array;
		temp_array = new int[x.row * x.col];

		if (x.row == this->row && x.col == this->col) {

			for (int i = 0; i < x.row; i++) {
				for (int j = 0; j < x.col; j++) {

					temp_array[i * this->col + j] = x.array[i][j] - this->array[i][j];
				}
			}

			return Matrix(temp_array, x.row, x.col);
		}
		
		else {

			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}


	//*���Z�q�̃I�[�o�[���[�h(�����{)
	Matrix operator*(int n) {

		int* temp_array;
		temp_array = new int[this->row * this->col];

		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {

				temp_array[i * this->col + j] = (this->array[i][j]) * n;
			}
		}

		return Matrix(temp_array, this->row, this->col);
	}

	//*���Z�q�̃I�[�o�[���[�h(�s�񓯎m)
	friend Matrix operator*(const Matrix& x, const Matrix& y) {

		int* temp_array;
		temp_array = new int[x.row * y.col];

		if (x.col == y.row) {

			for (int i = 0; i < x.row; i++)
				for (int j = 0; j < y.col; j++) {

					temp_array[i * y.col + j] = Sigma_array(x, y, i, j);
				}

			return Matrix(temp_array, x.row, y.col);
		}
	
		else {

			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}

	//*=���Z�q�̃I�[�o�[���[�h(�����{)
	Matrix operator*=(int n) {

		int* temp_array;
		temp_array = new int[this->row * this->col];

		for (int i = 0; i < this->col; i++)
			for (int j = 0; j < this->row; j++) {
				
				temp_array[i * this->col + j] = this->array[i][j] * n;
			}

		return Matrix(temp_array, this->row, this->col);
	}

	//*=���Z�q�̃I�[�o�[���[�h(�s�񓯎m)
	Matrix operator*=(Matrix& x) {

		int* temp_array;
		temp_array = new int[this->row * this->col];

		if (this->col == x.row) {

			for (int i = 0; i < this->col; i++)
				for (int j = 0; j < x.row; j++) {

					temp_array[i * this->col + j] = Sigma_array(*this, x, i, j);
				}
		}

		else {

			std::cout << "�^������������܂���." << std::endl;
			return Zero(1, 1);
		}
	}

	//==���Z�q�̃I�[�o�[���[�h
	friend bool operator==(const Matrix& x, const Matrix& y) {
		
		if (x.row == y.row && x.col == y.col) {

			for (int i = 0; i < x.row; i++) {
				for (int j = 0; j < x.col; j++) {

					if ((double)x.array[i][j] == (double)y.array[i][j])
						continue;

					else
						return false;
				}
			}

			return true;
		}
		
		else {

			return false;
		}
	}

	// |���Z�q�̃I�[�o�[���[�h (�s��̌���)
	friend Matrix operator|(const Matrix& x, const Matrix& y) {

		if (x.row == y.row) {

			int* temp_array;
			temp_array = new int[x.row * (x.col + y.col)];

			for (int i = 0; i < x.row; i++) {
				for (int s = 0; s < x.col; s++) {

					temp_array[i * (x.col + y.col) + s] = x.array[i][s];
				}

				for (int t = 0; t < y.col; t++) {

					temp_array[i * (x.col + y.col) + t + x.col] = y.array[i][t];
				}
			}

			return Matrix(temp_array, x.row, (x.col + y.col));
		}

		else {

			std::cout << "�^������������܂���" << std::endl;
			return Zero(1, 1);
		}
	}

	//�}���q�̃I�[�o�[���[�h
	friend std::ostream& operator<<(std::ostream& s, const Matrix& x) {

		for (int i = 0; i < x.row; i++) {

			s << "| ";
			for (int j = 0; j < x.col; j++) {

				s << x.array[i][j] << " ";
			}
			s << "|\n" ;
		}

		return s;
	}

};
