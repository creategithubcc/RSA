#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int num,cot=0; 
int c[100]; 
bool gcd(int p,int q)//�ж��������ǲ��ǻ��ʡ�
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
int de_key(int e,int t)//��˽Կ 
{
	for(int d=0;d<t;d++)
	{
		if(e*d%t==1)
		{
			return d;
		}
	}
}
 
bool prime(int s)//�ж������p��q�ǲ�������
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
 
void en(int e,int n)//���ܺ���
{ 
	cot=0;
	string m;
	cout<<"�����������ַ�����";
	cin>>m;
	num=m.size();
	int mingwen[num];   //������������ 
	cout<<"��������Ϊ��";
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
	cout<<"������������Ϊ��";
	for(int i=0;i<num;i++) 
	{
		cot++; 
		cout<<c[i]<<" ";
	}
	cout<<endl<<"�ַ���������"<<cot<<endl;
} 


int main()
{
	int p,q,e,k,n,fai_n,d,ans,op,flag;
	loop:
	cout<<"///////////////////////////////////////////////"<<endl<< 
		  "////��ӭ�����ԲԵ�RSA���ܽ���С������ѡ��////"<<endl<<
		  "////1.����                                 ////"<<endl<<
		  "////2.����                                 ////"<<endl<<
		  "///////////////////////////////////////////////"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			cout<<"���뻥�ʵ�p��q��"; 
			while(cin>>p>>q)
			{
				k=0,d=0,ans=0,fai_n=0,num=0;
				memset(c,0,sizeof(c));
				e=prime(p);
				n=prime(q);
				if(e==0||n==0||p<10||q<10)
				{
					cout<<"����������p��q(10���ڲ���)��"; 
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
				cout<<endl<<endl<<"Ҫ���س�ʼ���������ǵĻ��밴1,���ǵĻ������"<<endl;
				cin>>flag;
				if(flag==1)
				{
					goto loop;
				}
				cout<<endl<<endl<<"���뻥�ʵ�p��q��"; 
			}
		case 2:
			while(1)
			{
				cout<<"�������������������"<<endl;
				int num,ans=1;
				string C;
				cin>>num;
				int decode[num+1];
				cout<<"�������������,ÿ������֮���ÿո������"<<endl;
				for(int i=0;i<num;i++)
				{
					cin>>decode[i];
				} 
				cout<<"��������Ľ�����Կd��";
				cin>>d;
				cout<<"���������ģ��n��";
				cin>>n;
				cout<<"��������������k��";
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
				cout<<"���ܺ����������Ϊ��";
				for(int i=0;i<num;i++) 
				{
					cout<<decode[i];
				}
				cout<<endl;
				cout<<"���ܺ�ķ�������Ϊ��";
				for(int i=0;i<num;i++)
				{
					C[i]=decode[i];
					cout<<C[i];
				}
				cout<<endl;
				cout<<"Ҫ���س�ʼ���������ǵĻ��밴1,���ǵĻ������"<<endl;
				cin>>flag;
				if(flag==1)
				{
					goto loop;
				}
			} 
	}
}
