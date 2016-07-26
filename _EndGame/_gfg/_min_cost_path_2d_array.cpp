#include<iostream>
using namespace std;
#define m 3
#define n 3
int minof3(int a, int b, int c) {
	return (a<b && a<c)?a:((b<a&&b<c)?b:c);
}
int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
int mincost(int arr[m][n], int i, int j){
	if(i<0 || j<0){
		//cout<<"\nLess than zero:"<<arr[i][j]<<endl;
		//cout<<endl<<mincost(arr,2,2);
		return 0;
	}else{
		//cout<<endl<<"Blocked!!";
		// cout<<endl<<mincost(arr,i-1,j-1);
		// cout<<endl<<mincost(arr,i-1,j);
		// cout<<endl<<mincost(arr,i,j-1);
		return arr[i][j] + minof3(mincost(arr,i-1,j-1),mincost(arr,i-1,j),mincost(arr,i,j-1));
	}
}
int dpmincost(int arr[m][n], int row, int col){
	int tc[row+1][col+1],i,j;
	tc[0][0]=arr[0][0];
	//Fill columns
	for (i=1;i<=row;i++) {
		tc[i][0]=arr[i][0]+tc[i-1][0];
	}
	for (j=1;j<=col;j++) {
		tc[0][j]=arr[0][j]+tc[0][j-1];
	}
	for (i=1;i<=row;i++) {
		for (j=1;j<=col;j++) {
			tc[i][j]=arr[i][j]+minof3(tc[i-1][j-1],tc[i-1][j],tc[i][j-1]);
		}
	}
	for (i=0;i<=row;i++) {
		for (j=0;j<=col;j++) {
			cout<<tc[i][j]<<" ";
		}
		cout<<"\n";
	}
	return tc[row][col];
}
int _minCost(int cost[m][n], int mm, int nn)
{
   if (nn < 0 || mm < 0)
      return 0;
   else if (mm == 0 && nn == 0)
      return cost[mm][nn];
   else
      return cost[mm][nn] + min( _minCost(cost, mm-1, nn-1),
                               _minCost(cost, mm-1, nn), 
                               _minCost(cost, mm, nn-1) );
}
int main (){
	int arr[3][3]= {{1,2,3},
					{4,8,2},
					{1,5,3}};
	cout<<"--"<<mincost(arr,2,0)<<endl;
	cout<<"--"<<_minCost(arr,2,0)<<endl;
	cout<<"--"<<dpmincost(arr,2,0)<<endl;
	return 0;
}