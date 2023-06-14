#include<iostream>

/*
	簡易行列クラス Matrix
	
	簡易版なので整数を要素とする行列のみ扱える.
	掃き出し法や階級、行列積など追加予定.


	以下に簡単な使用法を記す
*/

// matrixヘッダをインクルードする
#include"matrix.h"


int main(void) {

	//任意の要素を含んだ配列を用意する

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


	//行列を生成する(インスタンスの生成)
	Matrix A(arr, 3, 2);    // arrの要素を反映した行列Aの生成
	Matrix B(*arr_2, 3, 2); // arr_2の要素を反映した行列Bの生成

	Matrix _A;              //詳細を指定しないと2行2列の単位行列を生成する

	/*
		行列同士の演算

		定義されている演算子
		+, -, *, ==, +=, -=, *=
	*/

	Matrix C = A + B;

	C -= B;

	/*
	単位行列、ゼロ行列を生成する
	*/
	Matrix D = D.Identity(3, 3);  //3行3列の単位行列
	Matrix _D = D.Identity(2, 3); //正方行列でない指定は無効

	Matrix E = E.Zero(2, 3);

	/*
	行列を出力する

	挿入子 << がオーバーロードされている
	*/
	std::cout << A << "\n   +\n\n" << B << "\n  ||\n\n" << A + B << std::endl;


	/*
	
	拡大係数行列を作る

	演算子 | がオーバーロードされている
	*/

	Matrix F = A | B;
	std::cout << "  (A | B)  \n\n    ||\n\n" << F << std::endl;

	return 0;
}