# RSA
一款基于RSA非对称加密算法的小程序\n
m^e mod n = c
c^d mod n = m
m^ed mod n = m
m^&(n) mod n = 1
&(n)是在<=n的正整数中，有多少个数字和n互质，比如&(6)=2 <1和5>
假设m,n互质
m^&(n) mod n = 1 ，接下来互乘k次方 
m^(&(n)*k) mod n = 1^k ，接下来互乘m
m*m^(&(n)*k) mod n = (1^k) *m ，变换公式 
m^(k*&(n)+1) mod n = m  ，可以发现
m^(k*&(n)+1) mod n = m^ed mod n  ，因此
k*&(n)+1 = e*d ，变换公式 
d = (k*&(n)+1)/e ,因此我们需要k、n、e
同时&(n)的大数质因数分解非常难，因此n用质数的
&(n)=n-1(n=质数)，另外对于任意两个互质的数p、q
可以得知&(p*q)=&(p)*&(q)
e要与&(n)互质，k随机，n=p*q(pq互质)，求d、e、n公布作为公钥 

这个代码是根据(https://www.freesion.com/article/42341433559/)
这篇博客上的代码改编的，修正了一些bug，但还是有许多问题没得到解决，我的技术还远远不够
相关的程序结果运行可以看这个链接 https://www.bilibili.com/video/BV1ef4y1K7p7
