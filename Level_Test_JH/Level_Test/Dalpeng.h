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
		// arr [2 * size + 3]; 에서 size는 가로길이
		memset(_arr, 0, sizeof(int) * _size * _size);

		
		int r = 0; // 달팽이 가로 좌표
		int c = 0; // 달팽이 세로 좌표
		int footstep = 1; // 왔던 길
		Direction direction = DIR_RIGHT;
		int arrNum = 0;

		for (int i = 0; i < _size * _size; i++)
		{
			// 2-2. 발자국을 남긴다.
			_arr[r * _size + c] = footstep;
			++footstep;

			// 2-3, 이동할 위치를 계산한다.
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[direction];
			int nc = c + dc[direction];

			

			// 2-4. 이동이 가능한지 판별한다.
			// 2-4-1. 벽에 닿았을 때 => r, c의 위치가 [0, size]
			// 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0 
			if (nr < 0 || nr >= _size || nc < 0 || nc >= _size || _arr[nr * _size + nc] != NOT_VISITED)
			{
				// 2-5. 이동이 불가능하므로 방향 전환을 한다.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. 위치값을 다시 계산한다.
				nr = r + dr[direction];
				nc = c + dc[direction];
			}

			// 2-7 이동한다.
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
