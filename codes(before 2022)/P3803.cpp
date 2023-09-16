// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=1e7+10;
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const double Pi=acos(-1.0);
struct complex
{
    double x,y;
    complex (double xx=0,double yy=0){x=xx,y=yy;}
}a[MAXN],b[MAXN];
complex operator + (complex a,complex b){ return complex(a.x+b.x , a.y+b.y);}
complex operator - (complex a,complex b){ return complex(a.x-b.x , a.y-b.y);}
complex operator * (complex a,complex b){ return complex(a.x*b.x-a.y*b.y , a.x*b.y+a.y*b.x);}//�����Ŀ������������ǲ��� 
int N,M;
int l,r[MAXN];
int limit=1;
void fast_fast_tle(complex *A,int type)
{
    for(int i=0;i<limit;i++) 
        if(i<r[i]) swap(A[i],A[r[i]]);//���Ҫ���������� 
    for(int mid=1;mid<limit;mid<<=1)//���ϲ�������е�
    {
        complex Wn( cos(Pi/mid) , type*sin(Pi/mid) ); //��λ�� 
        for(int R=mid<<1,j=0;j<limit;j+=R)//R��������Ҷ˵㣬j��ʾǰ�Ѿ����ĸ�λ���� 
        {
            complex w(1,0);//�� 
            for(int k=0;k<mid;k++,w=w*Wn)//ö����벿�� 
            {
                 complex x=A[j+k],y=w*A[j+mid+k];//����ЧӦ 
                A[j+k]=x+y;
                A[j+mid+k]=x-y;
            }
        }
    }
}
int main()
{
    int N=read(),M=read();
    for(int i=0;i<=N;i++) a[i].x=read();
    for(int i=0;i<=M;i++) b[i].x=read();
    while(limit<=N+M) limit<<=1,l++;
    for(int i=0;i<limit;i++)
        r[i]= ( r[i>>1]>>1 )| ( (i&1)<<(l-1) ) ;
    // ��ԭ������ i �� i/2 �Ĺ�ϵ�� �� i���Կ�����i/2�Ķ������ϵ�ÿһλ����һλ����
    // ��ô�ڷ�ת��������о���Ҫ����һλ��ͬʱ���⴦��һ�¸��� 
    fast_fast_tle(a,1);
    fast_fast_tle(b,1);
    for(int i=0;i<=limit;i++) a[i]=a[i]*b[i];
    fast_fast_tle(a,-1);
    for(int i=0;i<=N+M;i++)
        printf("%d ",(int)(a[i].x/limit+0.5));
    return 0;
}
