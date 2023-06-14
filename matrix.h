#pragma once

#include<iostream>


class Matrix {

private:

	int** array;
	int row = 0, col = 0;


	static int Sigma_array(const Matrix& x, const Matrix& y, int _row, int _col)  {
		//配列要素の積の総和を返す

		/*
		_row, _colは演算の対象の行及び列
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
	
	//コンストラクタ
	Matrix(int* x, int _row, int _col) {

		row = _row; col = _col;

		//array配列を動的確保
		array = new int* [row];
		for (int i = 0; i < row; i++) {

			array[i] = new int[col];
		}

		//配列をコピー
		for (int c = 0; c < row; c++) {
			for (int d = 0; d < col; d++) {

				array[c][d] = x[d + c * col];
			}
		}
	}

	//デフォルトコンストラクタ
	Matrix() {

		row = 2, col = 2;

		int temp[4] = { 1, 0, 0, 1 };

		//array配列を動的確保
		array = new int* [row];
		for (int i = 0; i < row; i++) {
			array[i] = new int[col];
		}

		//配列をコピー
		for (int c = 0; c < row; c++) {
			for (int d = 0; d < col; d++) {

				array[c][d] = temp[c * col + d];
			}
		}

	}

	//デストラクタ
	~Matrix() {
		for (int u = 0; u < this->row; u++)
			delete[] array[u];
	}

	//単位行列にする
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

			std::cout << "型が正しくありません." << std::endl;
		}
	}

	//ゼロ行列にする
	void to_Zero() {

		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < this->col; j++) {
				
				this->array[i][j] = 0;
			}
	}

	//単位行列を生成
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

			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}

	//ゼロ行列を生成
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

	//転置行列にする
	Matrix T() {

		int* temp_array;
		temp_array = new int[row * col];

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				temp_array[col * j + i] = array[i][j];
			}
		}

		return Matrix(temp_array, col, row); //行と列を逆にわたす
	}


//演算子のオーバーロード

	//+演算子のオーバーロード
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

			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}

	//+=演算子のオーバーロード
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

			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}

	//-演算子のオーバーロード
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
			
			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}

	//-=演算子のオーバーロード
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

			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}


	//*演算子のオーバーロード(整数倍)
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

	//*演算子のオーバーロード(行列同士)
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

			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}

	//*=演算子のオーバーロード(整数倍)
	Matrix operator*=(int n) {

		int* temp_array;
		temp_array = new int[this->row * this->col];

		for (int i = 0; i < this->col; i++)
			for (int j = 0; j < this->row; j++) {
				
				temp_array[i * this->col + j] = this->array[i][j] * n;
			}

		return Matrix(temp_array, this->row, this->col);
	}

	//*=演算子のオーバーロード(行列同士)
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

			std::cout << "型が正しくありません." << std::endl;
			return Zero(1, 1);
		}
	}

	//==演算子のオーバーロード
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

	// |演算子のオーバーロード (行列の結合)
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

			std::cout << "型が正しくありません" << std::endl;
			return Zero(1, 1);
		}
	}

	//挿入子のオーバーロード
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
