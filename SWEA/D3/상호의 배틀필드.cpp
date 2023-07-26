#include<iostream>
#include<string>
#include<vector>

using namespace std;

void result(vector<vector<char>> &map, string command, int posi, int posj)
{
	int posx = posj;
	int posy = posi;
	for (int i = 0; i < command.size(); i++)
	{
		switch (command[i])
		{
			case 'U':
			{
				map[posy][posx] = '^';
				if (posy != 0 && map[posy - 1][posx] == '.')
				{
					map[posy][posx] = '.';
					posy -= 1; 
					map[posy][posx] = '^';
				}
				break;
			}
		
			case 'D':
			{
				map[posy][posx] = 'v';
				if (posy != map.size()-1 && map[posy + 1][posx] == '.')
				{
					map[posy][posx] = '.';
					posy += 1;
					map[posy][posx] = 'v';
				}
				break;
			}

			case 'L':
			{
				map[posy][posx] = '<';
				if (posx != 0 && map[posy][posx-1] == '.')
				{
					map[posy][posx] = '.';
					posx -= 1;
					map[posy][posx] = '<';
				}
				break;
			}
		
			case 'R':
			{
				map[posy][posx] = '>';
				if (posx != map[posy].size()-1 && map[posy][posx + 1] == '.')
				{
					map[posy][posx] = '.';
					posx += 1;
					map[posy][posx] = '>';
				}
				break;
			}

			case 'S':
			{
				switch (map[posy][posx])
				{
					case '^':
					{
						for (int i = posy; i >= 0; i--)
						{
							if (map[i][posx] == '#')
								break;
							if (map[i][posx] == '*')
							{
								map[i][posx] = '.';
								break;
							}
						}

						break;
					}
					case 'v':
					{
						for (int i = posy; i < map.size(); i++)
						{
							if (map[i][posx] == '#')
								break;
							if (map[i][posx] == '*')
							{
								map[i][posx] = '.';
								break;
							}
						}
						break;
					}
					case '<':
					{
						for (int i = posx; i >= 0; i--)
						{
							if (map[posy][i] == '#')
								break;
							if (map[posy][i] == '*')
							{
								map[posy][i] = '.';
								break;
							}
						}
						break;
					}
					case '>':
					{
					
						for (int i = posx; i < map[posy].size(); i++)
						{
							if (map[posy][i] == '#')
								break;
							if (map[posy][i] == '*')
							{
								map[posy][i] = '.';
								break;
							}
						}
						break;
					}

					default:
						break;
				}
				break;
			}

		default:
			break;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T, H, W, N;
	int posi, posj;
	string command;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> H >> W;
		vector<vector<char>> map(H, vector<char>(W));
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '<' || map[i][j] == '>')
				{
					posi = i;
					posj = j;
				}
			}
		}
		cin >> N;
		cin >> command;
		result(map, command, posi, posj);
		cout << "#" << test_case << " ";
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}
		
	}
	return 0;
}
