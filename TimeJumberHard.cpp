// Link Problem is : https://a2oj.com/p?ID=136
#include <bits/stdc++.h>
using namespace std;
int  arr[101];
bool boole [10000*100+2];
int t , i , n ,y , sum ,j ;
int main() {
    scanf("%d", &t);

    while (t--) {
        sum=0;
        cin>>y>>n;
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        memset(boole,0,sizeof(boole));

        boole [0]=1;
        for (i=0;i<n;i++)
        {
            for (j=sum;j>=0;j--)
                if (boole[j]==1)
                    boole[j+arr[i]]=1;
        }
        for (i=1;i<=sum;i++)
            if(boole[i]==1)
                printf("%d\n",i+y);

    }

    return 0;
}