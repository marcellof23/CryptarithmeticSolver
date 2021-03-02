#include <bits/stdc++.h>
#include "time.h"
using namespace std;

int power(int a, unsigned int b) 
{ 
    int result = 1;  
    while (b > 0) 
    { 
        if (b & 1)
        { 
            result *= a; 
        }
        b = b >> 1; 
        a = a * a;  
    } 
    return result; 
}

void reversed(int i, int j, int arr[10])
{
	int temp[10], k=0, x=i;
	memset(temp,-1,sizeof(temp));
	for(;i<j;++i,++k)
	{
		temp[k]=arr[i];
	}
	k--;
	for(;k>=0;k--)
	{
		arr[x++]=temp[k];
	}
}

bool next_permutation(int left, int right,int arr[10])
{
	int itr = right-1;
	while(1)
	{
		int a = itr;
		--itr;
		if (arr[a] > arr[itr])
		{
            int x = right;
            while (!(arr[itr] < arr[--x]));
            {
            	swap(arr[itr],arr[x]);
            }
            reversed(a, right, arr);
            return true;
        }
        if (itr == left)
        {
            reversed(left, right, arr);
            return false;
        }
	}
}

int main()
{
	int arr[10],alphabet[26];

	fstream input_stream;
	ofstream output_stream;
	string filename;
	cout<<"Masukkan input nama file : ";
	cin >> filename;
	filename = "../test/" + filename;
	input_stream.open(filename,ios::in);
	output_stream.open("output.txt");

	vector <string> input_data,raw_data;
	string str;

	bool isAlpha[26];
 	vector <char> alpha;

	while(input_stream>>str)
	{
		raw_data.push_back(str);
		input_data.push_back(str);
	}	
	vector <string> v;
	
	input_stream.close();
	memset(isAlpha,false,sizeof(isAlpha));

	int max_row = -1;
	for(int i=0;i<input_data.size();i++)
	{
		if(max_row < (int)input_data[i].size())
		{
			max_row = (int)input_data[i].size();
		}
		for(int j=0;j<input_data[i].size();j++)
		{

			if(input_data[i][j] == '+' )
			{
				input_data[i].pop_back();
				continue;
			}
			if(input_data[i][j] == '-' )
			{
				input_data[i].erase(input_data[i].begin(),input_data[i].begin()+input_data[i].size());
				continue;
			}
			if(!isAlpha[input_data[i][j]-'A'])
			{
				alpha.push_back(input_data[i][j]);
			}
			isAlpha[input_data[i][j]-'A'] = true;
		}
	}
	for(int i=0 ;i<input_data.size();i++)
	{
	    if(i == input_data.size()-2)
	    {
	        continue;
	    }
	    v.push_back(input_data[i]);
	}
	for(int i=0;i<10;i++)
	{
		arr[i] = i;
	}
	pair <char,int> ans[10];
	memset(alphabet,-1,sizeof(alphabet));
	for(int i=0;i<alpha.size();i++)
	{
		ans[i] = {alpha[i] , arr[i]};
		alphabet[alpha[i] - 'A'] = arr[i];
	}

	bool bisa = false;

 	clock_t tStart = clock();
 	float time;
 	int banyak_tes = 0;
	do 
	{ 
		++banyak_tes;
	    int answer[10];
	    bool flag = false;
		memset(answer,0,sizeof(answer));
		for(int i=0;i<alpha.size();i++)
		{
			alphabet[alpha[i] - 'A'] = arr[i];
		}
		for(int i=0;i<v.size();i++)
		{
			if(alphabet[v[i][0]-'A'] == 0)
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				answer[i] += ((alphabet[v[i][j]-'A'])*(power(10,v[i].size()-j-1)));
			}
		}
		int total=0;
		for(int i=0;i<v.size()-1;i++)
		{
			total += answer[i];
		}
		if(total == answer[v.size()-1])
		{
			bisa = true;
			time=(double)(clock() - tStart)/CLOCKS_PER_SEC;
			break;
		}
    } while (next_permutation(0, 10 , arr)); 	
	
	for(int i=0;i<alpha.size();i++)
	{
		ans[i] = {alpha[i] , arr[i]};
		alphabet[alpha[i] - 'A'] = arr[i];
	}
	for(int i=0;i<raw_data.size();i++)
	{
		int a = 0;
		a = max_row - raw_data[i].size();
		if(i==raw_data.size()-3)
		{
			a++;
		}
		while(a>0)
		{
			cout<<' ';
			output_stream<<' ';
			a = a - 1;
		}
		for(int j=0;j<raw_data[i].size();j++)
		{
			cout <<raw_data[i][j];
			output_stream<<raw_data[i][j];
		}
		cout<<endl;
		output_stream<<endl;
	}
	cout << endl;
	output_stream<<endl;

	for(int i=0;i<raw_data.size();i++)
	{
		int a = 0;
		a = max_row - raw_data[i].size();
		if(i==raw_data.size()-3)
		{
			a++;
		}
		while(a>0)
		{
			cout<<' ';
			output_stream<<' ';
			a = a - 1;
		}
		for(int j=0;j<raw_data[i].size();j++)
		{
			if(i==raw_data.size()-2)
			{
				cout<<'-';
				output_stream<<'-';
				continue;
			}
			cout<<alphabet[input_data[i][j]-'A'];
			output_stream<<alphabet[input_data[i][j]-'A'];
			if(j==input_data[i].size()-1 && i==input_data.size()-3)
			{
				cout<<'+';
				output_stream<<'+';
				break;
			}
		}
		cout<<endl;
		output_stream<<endl;
	}
	cout<<endl;
	output_stream<<endl;
	cout << "Waktu yang dibutuhkan : " << time << " detik" << endl;
	cout << "Jumlah tes yang dibutuhkan : " << banyak_tes << endl;
	output_stream << "Waktu yang dibutuhkan : " << time << " detik" << endl;
	output_stream << "Jumlah tes yang dibutuhkan : " << banyak_tes << endl;
	output_stream.close();
	return 0;
}
