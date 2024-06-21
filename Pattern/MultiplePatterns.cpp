#include<bits/stdc++.h>
using namespace std;

void nForest(int n) {
	// Write your code here.
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << "*";
		}
		cout << "\n";
	}
}

/*
O/P
*****
*****
*****
*****
*/

void nRightTriangle(int n){
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}

/*
O/P
*
**
***
****
*/

void nRightTriangleVariant(int n){
    int start=1;
    for(int i=0;i<5;i++){
        if(i%2==0) {
            start = 1;
        } else {
            start = 0;
        }
        for(int j=0;j<=i;j++){
            printf("%d",start);
            start=1-start;
        }
        printf("\n");
    }
}
/*
O/P
1
01
101
0101
10101
*/

void nStarTriangle(int n) {
    // Write your code here.
    for(int i=1;i<=5;i++){
        for(int k=i;k<5;k++){
            cout << " ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout << "*";
        }
		printf("\n");
    }
}
/*

O/P
    *
   ***
  *****
 *******
*********

*/

void nStarDiamond(int n) {
    // Write your code here.
	for(int i=1;i<=5;i++){
        for(int k=i;k<5;k++){
            cout << " ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout << "*";
        }
		printf("\n");
    }
	for(int x=5;x>=0;x--){
		for(int y=x;y<5;y++){
			printf(" ");
		}
		for(int z=x*2-1;z>=1;z--){
			printf("*");
		}
		printf("\n");
	}
}
/*
O/P
    *
   ***
  *****
 *******
*********  9
*********
 *******
  *****
   ***
    *
*/
void pattern2triangle(int n)
{
      int spaces = 2*n-2;
      for(int i = 1;i<=2*n-1;i++){
          int stars = i;
          if(i>n) stars = 2*n - i;
          for(int j=1;j<=stars;j++){
              cout<<"*";
          }
          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }
          for(int j = 1;j<=stars;j++){
              cout<<"*";
          }
          cout<<endl;
          if(i<n) spaces -=2;
          else spaces +=2;
      }
}

/*
*          *
**        **
***      ***
****    ****
*****  *****
************
*****  *****
****    ****
***      ***
**        **
*          *
*/

void patternBox(int n)
{
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(i==0 || j==0 || i==n-1 || j==n-1)
                cout<<"*";
             else cout<<" ";
         }
          cout<<endl;
     }
}

/*
****
*  *
*  *
****
*/

void patternNumbers(int n)
{
     for(int i=0;i<2*n-1;i++){
         for(int j=0;j<2*n-1;j++){
             int top = i;
             int bottom = j;
             int right = (2*n - 2) - j;
             int left = (2*n - 2) - i;
             cout<<(n- min(min(top,bottom), min(left,right)))<<" ";
         }
         cout<<endl;
     }
}

/*
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5 
*/

int main(){
	pattern2triangle(5);
	return 0;
}