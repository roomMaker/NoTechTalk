#pragma once

#include <iostream>

using namespace std;

#define NOT_VISITED 0

class Snail
{

public :
	void Make(int size)
	{
		_size = size;
		_arr = new int[_size * _size];
		// arr[2][3]
		// arr [2 * size + 3]; ���� size�� ���α���
		memset(_arr, 0, sizeof(int) * _size * _size);

		
		int r = 0; // ������ ���� ��ǥ
		int c = 0; // ������ ���� ��ǥ
		int footstep = 1; // �Դ� ��
		Direction direction = DIR_RIGHT;
		int arrNum = 0;

		for (int i = 0; i < _size * _size; i++)
		{
			// 2-2. ���ڱ��� �����.
			_arr[r * _size + c] = footstep;
			++footstep;

			// 2-3, �̵��� ��ġ�� ����Ѵ�.
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[direction];
			int nc = c + dc[direction];

			

			// 2-4. �̵��� �������� �Ǻ��Ѵ�.
			// 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size]
			// 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0 
			if (nr < 0 || nr >= _size || nc < 0 || nc >= _size || _arr[nr * _size + nc] != NOT_VISITED)
			{
				// 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. ��ġ���� �ٽ� ����Ѵ�.
				nr = r + dr[direction];
				nc = c + dc[direction];
			}

			// 2-7 �̵��Ѵ�.
			r = nr;
			c = nc;
		}
	}

	void Print()
	{
		for (int r = 0; r < _size; r++)
		{
			for (int c = 0; c < _size; c++)
			{
				cout << _arr[r * _size + c] << "\t";
			}
			cout << "\n";
		}
	}

	void Clear()
	{
		delete[] _arr;
	}

private :
	int*	_arr;
	int		_size;
	enum	Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
};
