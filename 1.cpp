#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
//0-1 背包问题变形
//时间O（volume*n）,空间O（volume*n）
//一维空间，自底向上
bool canPutbag(vector<int>& weights,int volume) {
        int len = weights.size();
        //一维数组,i表示weights索引，j表示volume可表达值
        vector<int>dp(volume+1,0);
        //第0列置为True
        dp[0] = true;
        if(weights[0]<=volume) {
            dp[weights[0]]=true;
        } 
        for(int i=1;i<len;i++){
            int weight = weights[i];
            for(int j=volume;j >=0 && j >= weight;j--){
                dp[j] = dp[j] | dp[j - weight];
            }
        }
        return dp[volume];
    }
int main(){
    vector<int>weights={1,3,11,7};
    if(canPutbag(weights,11)){
        cout << "I can"<<endl;
    }
    else{
        cout << "I can't"<<endl;
    }
    return 0;
}