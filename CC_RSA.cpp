#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int num,cot=0; 
int c[100]; 
bool gcd(int p,int q)//判断两个数是不是互质。
{
	int t,s;   //q=s*p+t;
	if(q<p)
	{
		t=p;
		p=q;
		q=t;
	}
	t=q%p;
	s=q/p; 
	while(t!=0)
	{
		
	    q=p;
		p=t;
		t=q%p;
		s=q/p;
	}
	if(t==0&&s==q)
	{
		return true;
    }
    else
	{
    	return false;
	}
}
int de_key(int e,int t)//求私钥 
{
	for(int d=0;d<t;d++)
	{
		if(e*d%t==1)
		{
			return d;
		}
	}
}
 
bool prime(int s)//判断输入的p和q是不是素数
{
	for(int i=2;i<s;i++)
	{
		if(s%i==0)
		{
			return false;
		} 
	}
	return true;
}
 
void en(int e,int n)//加密函数
{ 
	cot=0;
	string m;
	cout<<"请输入明文字符串：";
	cin>>m;
	num=m.size();
	int mingwen[num];   //定义数字明文 
	cout<<"明文数字为：";
	for(int i=0;i<num;i++)
	{
		mingwen[i]=m[i];  
		cout<<mingwen[i]; 
	} 
	cout<<endl;
	int ans=1; 
	for(int i=0;i<num;i++)
	{
	 
	   for(int j=0;j<e;j++)
	   {
			ans=ans*mingwen[i]%n;
	   }
	   c[i]=ans;
	   ans=1;
	} 
	cout<<"加密密文数字为：";
	for(int i=0;i<num;i++) 
	{
		cot++; 
		cout<<c[i]<<" ";
	}
	cout<<endl<<"字符串字数："<<cot<<endl;
} 


int main()
{
	int p,q,e,k,n,fai_n,d,ans,op,flag;
	loop:
	cout<<"///////////////////////////////////////////////"<<endl<< 
		  "////欢迎来到苍苍的RSA加密解密小程序！请选择////"<<endl<<
		  "////1.加密                                 ////"<<endl<<
		  "////2.解密                                 ////"<<endl<<
		  "///////////////////////////////////////////////"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			cout<<"输入互质的p和q："; 
			while(cin>>p>>q)
			{
				k=0,d=0,ans=0,fai_n=0,num=0;
				memset(c,0,sizeof(c));
				e=prime(p);
				n=prime(q);
				if(e==0||n==0||p<10||q<10)
				{
					cout<<"输入素数的p和q(10以内不行)："; 
					continue;
				}   
				n=p*q;
				fai_n=(p-1)*(q-1); 
			    cout<<"&(t)=(p-1)*(q-1)="<<fai_n<<endl;
				ans=0;
				while(ans==0)
				{
					e=rand()%100;
					while(e==0)
				    {
						e=rand()%100;
					}
					ans=gcd(e,fai_n);
				}
				k=rand()%100;
				while(k==0)
			    {
					k=rand()%100;
				}
				d=de_key(e,fai_n); 
				cout<<"k="<<k<<endl;
				cout<<"e="<<e<<endl;
				cout<<"n="<<n<<endl;
				cout<<"d="<<d<<endl;
				en(e,n);
				cout<<endl<<endl<<"要返回初始主界面吗？是的话请按1,不是的话任意键"<<endl;
				cin>>flag;
				if(flag==1)
				{
					goto loop;
				}
				cout<<endl<<endl<<"输入互质的p和q："; 
			}
		case 2:
			while(1)
			{
				cout<<"请输入你的密文字数："<<endl;
				int num,ans=1;
				string C;
				cin>>num;
				int decode[num+1];
				cout<<"请输入你的密文,每个数字之间用空格隔开："<<endl;
				for(int i=0;i<num;i++)
				{
					cin>>decode[i];
				} 
				cout<<"请输入你的解密密钥d：";
				cin>>d;
				cout<<"请输入你的模数n：";
				cin>>n;
				cout<<"请输入你的随机数k：";
				cin>>k;
				for(int i=0;i<num;i++)
				{
				   for(int j=0;j<d;j++)
				   {
					ans=ans*decode[i]%n;///
				   }
				   decode[i]=ans;
				   ans=1;
				} 
				cout<<"解密后的数字明文为：";
				for(int i=0;i<num;i++) 
				{
					cout<<decode[i];
				}
				cout<<endl;
				cout<<"解密后的符号明文为：";
				for(int i=0;i<num;i++)
				{
					C[i]=decode[i];
					cout<<C[i];
				}
				cout<<endl;
				cout<<"要返回初始主界面吗？是的话请按1,不是的话任意键"<<endl;
				cin>>flag;
				if(flag==1)
				{
					goto loop;
				}
			} 
	}
}
