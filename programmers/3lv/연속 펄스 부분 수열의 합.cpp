#include <string>
#include <vector>

using namespace std;

long long pnum=0; // plus
long long mnum=0; // minus

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long sum=0;
    for(int i=0;i<sequence.size();i++)
    {
        if(i%2==0){
            sum+=sequence[i];
        }
        else{
            sum-=sequence[i];
        }
        if(sum>0)
        {
            if(sum>pnum) pnum=sum;
            if(sum-mnum>answer)
            {
                answer=sum-mnum;  
            }
        }
        else
        {
            if(sum<mnum) mnum=sum;
            if(abs(sum-pnum)>answer)
            {
                answer=abs(sum-pnum);  
            }
        }
    }
    return answer;
}

/*
값이 +라면 그전까지 -중 가장큰- 를 빼고 비교
값이 -라면 그전까지 +중 가장큰+ 를 빼고 abs 후 비교
*/