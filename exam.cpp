//
// Created by cooler on 20-9-3.
//

/**
 * 华为机考
 * */
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//typedef struct {
//    int w;
//    int v;
//    float rate;
//}BOX;
//bool cmp(BOX A,BOX B){
//    float e=1e-9;
//    if(fabs(A.rate-B.rate)<=e){
//        return A.w>B.w;
//    }
//    else{
//        return A.rate>B.rate;
//    }
//}
//int main(){
//    vector<int> Vw;
//    vector<int> Vv;
//    vector<float> Rate;
//    vector<BOX> CAR_Box;
//    int K;
//    cin>>K;
//    int N;
//    cin>>N;
//    for(int i=0;i<N;i++){
//        int temp;
//        cin>>temp;
//        Vw.push_back(temp);
//    }
//    for(int i=0;i<N;i++){
//        float t_rate=(float)Vv[i]/(float)Vw[i];
//        Rate.push_back(t_rate);
//    }
//    BOX t_BOX;
//    for(int i=0;i<N;i++){
//        t_BOX.w = Vw[i];
//        t_BOX.v = Vv[i];
//        t_BOX.rate = Rate[i];
//        CAR_Box.push_back(t_BOX);
//    }
//    sort(CAR_Box.begin(),CAR_Box.end(),cmp);
//    int W_cur = 0;
//    int V_cur = 0;
//    int p =0;
//    int res = 0;
//    while(p<CAR_Box.size()){
//        if(CAR_Box[p].w<=K-W_cur){
//            W_cur += CAR_Box[p].w;
//            V_cur += CAR_Box[p].v;
//        }
//        p++;
//    }
//    res = V_cur;
//    cout<<res<<endl;
//    return 0;
//}



//
//#include <string>
//#include <iostream>
//#include <vector>
//using namespace std;
//void dfs(vector<vector<char>> &grid,int x,int y){
//    grid[x][y] = 'H';
//    int dx[4] = {-1,0,1,0};
//    int dy[4] = {0,1,0,-1};
//    for(int i=0;i<4;i++){
//        int a = x+dx[i],b = y+dy[i];
//        if(a>=0 && b>=0 && a<grid.size() && b<grid[0].size() && grid[a][b]=='S')
//            dfs(grid,a,b);
//    }
//}
//int main(){
//    int n,m;
//    cin>>n>>m;
//    vector<vector<char>> grid(n,vector<char>(m));
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++)
//            cin>>grid[i][j];
//    }
//    int res = 0;
//    for(int i=0;i<grid.size();i++){
//        for(int j=0;j<grid[0].size();j++){
//            if(grid[i][j]=='S'){
//                res++;
//                dfs(grid,i,j);
//            }
//        }
//    }
//    cout<<res;
//}

//
//void test(){
//    int n;
//    cin>>n;
//    vector<int> color(n,0);
//    vector<int> nums(n,0);
//    int i=0,num_color1=0,num_color2=0;
//    while(i<n){
//        cin>>nums[i]>>color[i];
//        i++;
//    }
//    int size = i;
//    for(int j=0;j<i;j++){
//        if(color[j]==1) num_color1++;
//        else num_color2++;
//    }
//    if(num_color1<3 && num_color2<3){
//        cout<<"null";
//        return;
//    }
//    int max_1=0,max_2=0;
//    int max1_1=0,max1_2=0,max1_3=0;
//    int max2_1=0,max2_2=0,max2_3=0;
//    for(i=0;i<size;i++){
//        if(color[i]==1 && nums[i]>max1_1)
//            max1_1 = nums[i];
//    }
//    vector<int> max1_1_num;
//    vector<int> max1_2_num;
//    vector<int> max1_3_num;
//    for(i=0;i<size;i++){
//        if(color[i]==1 && nums[i]==max1_1)
//            max1_1_num.push_back(i);
//    }
//    if(max1_1_num.size()>=3){
//        max_1 = max1_1*3;
//    }
//    else{
//        for(i=0;i<size;i++){
//            if(color[i]==1 && nums[i]>max1_2 && nums[i]!=max1_1)
//                max1_2 = nums[i];
//        }
//
//        for(i=0;i<size;i++){
//            if(color[i]==1 && nums[i]==max1_2)
//                max1_2_num.push_back(i);
//        }
//        if(max1_1_num.size()>=2){
//            if(max1_1_num.size()==1) max_1 = max1_1+max1_2*2;
//            else max_1 = max1_1*2+max1_2;
//        }
//        else{
//            for(i=0;i<size;i++){
//                if(color[i]==1 && nums[i]>max1_3 && nums[i]!=max1_1 && nums[i]!=max1_2)
//                    max1_3 = nums[i];
//            }
//
//            for(i=0;i<size;i++){
//                if(color[i]==1 && nums[i]==max1_3)
//                    max1_3_num.push_back(i);
//            }
//            max_1 = max1_1+max1_2+max1_3;
//        }
//    }
//
//
//    for(i=0;i<size;i++){
//        if(color[i]==2 && nums[i]>max2_1)
//            max2_1 = nums[i];
//    }
//    vector<int> max2_1_num;
//    vector<int> max2_2_num;
//    vector<int> max2_3_num;
//    for(i=0;i<size;i++){
//        if(color[i]==2 && nums[i]==max2_1)
//            max2_1_num.push_back(i);
//    }
//    if(max2_1_num.size()>=3){
//        max_2 = max2_1*3;
//    }
//    else{
//        for(i=0;i<size;i++){
//            if(color[i]==2 && nums[i]>max2_2 && nums[i]!=max2_1)
//                max2_2 = nums[i];
//        }
//
//        for(i=0;i<size;i++){
//            if(color[i]==2 && nums[i]==max2_2)
//                max2_2_num.push_back(i);
//        }
//        if(max2_1_num.size()>=2){
//            if(max2_1_num.size()==1) max_2 = max2_1+max2_2*2;
//            else max_2 = max2_1*2+max2_2;
//        }
//        else{
//            for(i=0;i<size;i++){
//                if(color[i]==2 && nums[i]>max2_3 && nums[i]!=max2_1 && nums[i]!=max2_2)
//                    max2_3 = nums[i];
//            }
//
//            for(i=0;i<size;i++){
//                if(color[i]==2 && nums[i]==max2_3)
//                    max2_3_num.push_back(i);
//            }
//            max_2 = max2_1+max2_2+max2_3;
//        }
//    }
//    vector<int> res;
//    int color_res=0;
//    int max_res = 0;
//    if(max_1>max_2){
//        color_res=1;
//        max_res = max_1;
//        if(max1_1_num.size()>=3){
//            res.push_back(max1_1_num[0]);
//            res.push_back(max1_1_num[1]);
//            res.push_back(max1_1_num[2]);
//        }
//        else if(max1_2_num.size()>=2){
//            res.push_back(max1_1_num[0]);
//            res.push_back(max1_2_num[0]);
//            res.push_back(max1_2_num[1]);
//        }
//        else{
//            res.push_back(max1_1_num[0]);
//            res.push_back(max1_2_num[0]);
//            res.push_back(max1_3_num[0]);
//        }
//    }
//    else{
//        color_res=2;
//        max_res = max_2;
//        if(max2_1_num.size()>=3){
//            res.push_back(max2_1_num[0]);
//            res.push_back(max2_1_num[1]);
//            res.push_back(max2_1_num[2]);
//        }
//        else if(max2_2_num.size()>=2){
//            res.push_back(max2_1_num[0]);
//            res.push_back(max2_2_num[0]);
//            res.push_back(max2_2_num[1]);
//        }
//        else{
//            res.push_back(max2_1_num[0]);
//            res.push_back(max2_2_num[0]);
//            res.push_back(max2_3_num[0]);
//        }
//    }
//    int min = INT32_MAX,mid=INT32_MAX,max=INT32_MAX;
//    if(res[0]>res[1]){
//        if(res[2]>res[0]){max=res[2];mid=res[0];min=res[1];}
//        else if(res[2]<res[1]){max=res[0];mid=res[1];min=res[2];}
//        else {max=res[0];mid=res[2];min=res[1];}
//    }
//    else{
//        if(res[2]>res[1]){max=res[2];mid=res[1];min=res[0];}
//        else if(res[2]<res[0]){max=res[1];mid=res[0];min=res[2];}
//        else {max=res[1];mid=res[2];min=res[0];}
//    }
//    cout<<min+1<<' '<<mid+1<<' '<<max+1<<endl;
//    cout<<color_res<<endl;
//    cout<<max_res<<endl;
//
//}