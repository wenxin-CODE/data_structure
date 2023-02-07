#数据结构创建方法
#%%
#字符串
a='i am dly\n'
b="i am dly\n"
c='''
i am dly
you are who
'''
print(a,b,c)
# %%
#列表
a=[1,2,3]
b=list((1,2,3))#里面可以是任何类型
#对于字典，生成key列表
c=list(range(3))
d=[i for i in range(3)]
print(a,b,c,d)
# %%
#字典
a={'aaa':'mike','bbb':'mike','ccc':''}
b=dict([('aaa','bbb'),(1,2)])
x=[1,2,3]
y=['aaa','bbb','ccc']
c=dict(zip(x,y))
d=dict.fromkeys([1,2,3])#值为空
print(a,b,c,d)
# %%
