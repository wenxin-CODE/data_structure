#%%
print(bin(10))
print(hex(10))
print(oct(10))
#%%
print(pow(10,2,3))
#a的b次幂, 如果有三个参数. 则求完次幂后对第三个数取余
print(divmod(20,3))
print(round(4.51))
#%%
lst = list((1,2,3,4,5))
#list expected at most 1 argument, got 5
print(list(reversed(lst)))
#reversed() 将一个序列翻转, 返回翻转序列的迭代器
#%%
s = "hello world!"
print(format(s, "^20"))  #剧中
print(format(s, "<20"))  #左对齐
print(format(s, ">20"))  #右对齐

print(format(123456789, '0.2E' ))   # 科学计数法. 保留2位小数(大写):1.23E+08
print(format(1.23456789, 'f' ))     # 小数点计数法. 保留6位小数:1.234568
print(format(1.23456789, '0.2f' ))  # 小数点计数法. 保留2位小数:1.23
#%%
print(ord('a'))  # 字母a在编码表中的码位:97
print(ord('中'))  # '中'字在编码表中的位置:20013

print(chr(65))  # 已知码位,求字符是什么:A
print(chr(19999))  #丟
#%%
lst = [1,5,3,2,8]
lst.sort()#输出为none
print(lst)
print(sorted(lst))#返回新列表

#根据字符串长度给列表排序
lst = ['one', 'two', 'three', 'four', 'five', 'six']
def f(s):
    return len(s)
l1 = sorted(lst, key=f, )
print(l1)
#%%
print(all([1,2,3,"china","hello",True]))
print(any([0,0,0,1,False,"vscode"]))
# all() 可迭代对象中全部是True, 结果才是True
# any() 可迭代对象中有一个是True, 结果就是True
# %%
lst1 = [1, 2, 3, 4, 5, 6]
lst2 = ['醉乡民谣', '驴得水', '放牛班的春天', '美丽人生', '辩护人', '被嫌弃的松子的一生']
lst3 = ['美国', '中国', '法国', '意大利', '韩国', '日本']
print(zip(lst1, lst1, lst3))  #<zip object at 0x00000256CA6C7A88>
for el in zip(lst1, lst2, lst3):
    print(el)
# zip() 函数用于将可迭代的对象作为参数, 
# 将对象中对应的元素打包成一个元组, 
# 然后返回由这些元组组成的列表. 
# 如果各个迭代器的元素个数不一致, 则返回列表长度与最短的对象相同
# %%
def func(i):    # 判断奇数
    return i % 2 == 1
lst = [1,2,3,4,5,6,7,8,9]
l1 = filter(func, lst)  #l1是迭代器
print(l1)  
print(list(l1))
# %%
def f(i):
    return i+1#列表整体加一

lst = [1,2,3,4,5,6]
print(list(map(f,lst)))
# %%
def f():
    print("hello")
# 用于检查一个对象是否是可调用的. 
# 如果返回True, object有可能调用失败,
# 但如果返回False. 那调用绝对不会成功
a = 10
print(callable(a))
print(callable(f))
# %%
s1=input("请输入")
#eval() 执行字符串类型的代码. 并返回最终结果
#没懂
print(eval(s1))
# %%
code1 = "for i in range(3): print(i)"
com = compile(code1, "", mode="exec")   # compile并不会执行你的代码.只是编译
exec(com)   # 执行编译的结果

code2 = "5+6+7"
com2 = compile(code2, "", mode=~"eval")
print(eval(com2))  
# %%
print(dir(tuple))
#查看对象的内置属性
# %%
