#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
 
 
 int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(string str)
{
	size_t		i;
	int			one;
	long int	nbr;

	i = 0;
	nbr = 0;
	one = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			one = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * one);
}

// A utility function to print the adjacency list
void addEdgeRed(vector<int> adj[], int u)
{
    for(int i = 0; i < u / 2; i++)
        adj[i].push_back(i + 1);
}

void addEdgeBlue(vector<int> adj[], int u)
{
    int j = 0;
    for(int i = (u / 2); i < u; i++)
        adj[j++].push_back(i + 1);
}

void printGraph(vector<int> adj[], int u)
{
    int n;

    n = 0;
    for(int i = 0; i < u / 2; i++)
    {
        printf("%d => ", adj[i][0]);
        for (int j = 1; j < adj[i].size() ; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void    makeGraph(vector<int> red[], vector<int> blue[], int lenght, int m)
{
    int tab[m];
    int save = 0;
    int j;
    int k = 0;
    int rest = lenght;
    
    for(int i = 0; i < lenght;)
    {
        for (j = save; j < m + save; j++)
        {
            tab[k++] = blue[j][0];
        }
        save = j;
        k = 0;

        for(int k = 0; k < m; k++)
        {
            for (int k = 0; k < m; k++)
            {
                red[i].push_back(tab[k]);
            }
            i++;
        }

        if (rest - m < m) m = rest - m;
        else rest = rest - m;
    }
}

int testGraph(vector<int> adj[],int len, int m)
{
    for(int i = 0; i < len; i++)
    {
        if(adj[i].size() - 1 != m) return 0;
    }
    return (1);
}

int main()
{
    string  line;
    int t, n, m;
    int i;
    
    ifstream MyReadFile("test.txt");

    getline (MyReadFile, line);
    t = ft_atoi(line);

    while (t)
    {
        getline (MyReadFile, line);
        i = 0;
        n = ft_atoi(line);
        while (line[i] != ' ')
        i++;
        m = ft_atoi(&line[i]);

       if (m > n/2)
       {
            cout << "No";
            return 0;
       }

vector<int> red[n / 2];
    vector<int> blue[n / 2];

       addEdgeRed(red, n);
       addEdgeBlue(blue, n);
       makeGraph(red, blue, n / 2, m);
       //printGraph(red, n);
       if (testGraph(red, n / 2, m)) cout << "Yes" << endl;
       else cout << "No" << endl;
       t--;
    }
    return (0);
}