#%%
#字符列表转换为字符串
l=['I','love','you']
j=' '.join(l)
print(l,'\n',j)
#字符串变字符列表
'i love her'.split()
# %%
#字符居中
k="i love you"
k.center(20)
k.center(20,'*')
# %%
#字符串中找子串
a="i love you"
a.find('you')
# %%
#列表元素第一次出现的索引
a=['i','love','you']
a.index("love")
# %%
#列表插入元素
#末尾插入列表
a=[1,2,3]
b=[4]
a.extend(b)
print(a)
#插入列表指定位置
a.insert(2,10)
print(a)
#切片
a[2:2]=[11]
#2:3表示删除2，3号元素，改为11
print(a)
# %%
#转置列表
a=[1,2,3]
print(a[::-1])
a.reverse()
print(a)
# %%
#批量替换字符串元素
'i love you so much'.replace('o','$')
# %%
import webbrowser
webbrowser.open('http://www.python.org')
# %%
#为函数编写文档
def hanshu():
    '''这是一个函数
    我用来尝试编写文档
    不知道行不行'''
    print("i love you")

hanshu()
print(hanshu.__doc__)
# %%
class Person:
    def __name(self):
        '''用import无法导入私有方法'''
        print('私有方法')
    def say(self):
        self.__name()
        print(self.__name.__doc__)

a=Person()
a.say()
# %%
#从序列中随即返回n个元素
import random
a=[1,2,3,4,5,6,7,8,9,0]
print(random.sample(a,2))
#生成两个数间的随机实数
print(random.uniform(10,20))
#等差数列随机数
print(random.randrange(0,100,10))
# %%
#文件读写
# with open('G:/python/AIpython/新建文本文档.txt','w') as f:
#     f.write("hello world")

with open('G:/python/AIpython/新建文本文档.txt','r') as f:
    f.read()
# %%
#追加，不删除原有的
with open('G:/python/AIpython/新建文本文档.txt','a') as f:
    f.write("hello VScode")
# %%
#随机打乱列表顺序
import random
a=list(range(10))
random.shuffle(a)
print(a)
# %%
#⽤for循环实现把字符串变成Unicode码位的列表
a="@#$%^^*(~,."
codes=[]
for s in a:
    codes.append(ord(s))
print(codes)
# %%
#就收不确定值或参数
a,*b,c = range(8)
#*b可以位于任意位置
print(a,b,c)
# %%
a=[1,2,3]
print(id(a))
a*=2
print(id(a))

b=(1,2,3)
print(id(b))
b*=2
print(id(b))
#对不可变序列重复拼接效率低，要建新对象
# %%
#numpy将一维数组变为二维数组
import numpy as np
a=np.arange(20)
a.shape=4,5
print(a)
# %%
#m中元素在n中出现次数
a={1,2,3,4}
b={2,3,4,5}
len(a&b)
#这种方法只适用于集合，不是集合要转换
# %%
#修改系统编码方式
fp=open('G:/python/AIpython/新建文本文档.txt','w',encoding='utf-8')
fp.encoding
fp.close()
# %%
#高效阶乘
from functools import reduce
from operator import mul
def fact(n):
    return reduce(mul,range(1,n+1))

print(fact(5))