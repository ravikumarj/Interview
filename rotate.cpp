#include<iostream>

using namespace std;

void rotate(int a[][4],int n)
{

	int layer=0;
	for(layer=0;layer<n/2;++layer)
	{
		int first=layer;
		int last=n-1-layer;
		for(int i=first;i<last;++i)
		{
		int offset=i-first;
		int top=a[first][i];
		a[first][i]=a[last-offset][first];
		a[last-offset][first]=a[last][last-offset];
		a[last][last-offset]=a[i][last];
		a[i][last]=top;

		}
	}
}

void print(int a[][4],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
	}
}

void transpose(int a[][4],int n)
{
	int b[4][4];
	int temp;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{

			if(i==j)
			{
				continue;
			}
			else
			{
				if(j>i)
				{

					temp=a[i][j];
					a[i][j]=a[j][i];
					a[j][i]=temp;
				}
			}
		}
	}
	//cout<<"\nInside Transpose\n";
	//print(a,4);
}
void reverse_rows(int a[][4],int n)
{
	int num_row=n;
	int temp,j,end;
	for(int i=0;i<num_row;i++)
	{
		j=0;
		end=n-1;
		while(j<end)
		{
			temp=a[i][j];
			a[i][j]=a[i][end];
			a[i][end]=temp;
			j++;
			end--;
		}
	}


}
void reverse_cols(int a[][4],int n)
{

	int num_cols=n;
        int temp,i,end;
        for(int j=0;j<num_cols;j++)
        {
                i=0;
                end=n-1;
                while(i<end)
                {
                        temp=a[i][j];
                        a[i][j]=a[end][j];
                        a[end][j]=temp;
                        i++;
                        end--;
                }
        }

}
main()
{
	int a[4][4]={{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}};

	print(a,4);
	//rotate(a,4);
	transpose(a,4);
	reverse_rows(a,4);
	cout<<"\n90 deg rotation\n"; 
	print(a,4);

	transpose(a,4);
        reverse_cols(a,4);
        cout<<"\n90 deg rotation\n";
        print(a,4);

}



