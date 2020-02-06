#include < iostream>
#include< queue >
#include< vector>
#include < algorithm>

using namespace std;

class roomno
{
public:
int x;
int y;

roomno(int x,int y)
{
    this->x=x;
    this->y=y;
}
void print()
{
    cout<<"location"<<"("<<x<<","<<y<<")"<<endl;
}
int distance ()
{
return (xx+yy);
}

};
class roomcompare
{
public:
bool operator() (roomno r1,roomno r2)
{
return r1.distance()>r2.distance();
}
};

int main()
{
int x[1000]},y[1000];
int l,k=0;

priority_queue<roomno,vector,roomcompare> pq;
int n,i,j;
cin>>n>>l;
//cin>>n;
cin.ignore();
for( i=0;i<n;i++)
{
cin>>x[i];
}
cin.ignore();
for( j=0;j<n;j++)
{
cin>>y[j];
}
cin.ignore();

for(i=0;i<n;i++ )
{
    roomno r1(x[i],y[i]);
    pq.push(r1);
}
while(!pq.empty()&&k!=l)
{   k++;
    roomno r2=pq.top();
    r2.print();
    pq.pop();

}
return 0;
}
