#%%
#重复元素判定
def all_unique(lst):
    return len(lst)==len(set(lst))

x=[1,1,2,2,3,5,4,5,]
y=[1,2,3,4,5,6]
print(all_unique(x))
all_unique(y)
# %%
#字符元素组成判定
from collections import Counter
def anagram(x,y):
    return Counter(x)==Counter(y)

print(anagram("love","love"))
anagram("like","love")
# %%
#内存占用,以字节为单位
import sys
a=[1,2,3,4,5]
print(sys.getsizeof(a))
# %%
#按指定大小切割列表,这个不太懂
from math import ceil
def chunk(lst,size):
    return list(
        map(lambda x:lst[x*size:x*size+size],
        list(range(0,ceil(len(lst)/size))))
    )

chunk([1,2,3,4,5,6,7,8,9,0,11],3)
#lambda & map使用
# %%
#逗号连接
a=['i','love','you']
print("i say "+",".join(a))
# %%
#元音统计：正则表达式
import re
def count_vowels(str):
    return len(len(re.findall(r'[aeiou]', str, re.IGNORECASE)))
count_vowels('foobar') # 3
count_vowels('gym') # 0
#re.IGNORECASE作用
# %%
#展开列表：该方法将通过递归的方式将列表的嵌套展开为单个列表。
def spread(arg):
    ret = []
    for i in arg:
        if isinstance(i, list):
            ret.extend(i)
        else:
            ret.append(i)
        return ret
def deep_flatten(lst):
    result = []
    result.extend(
    spread(list(map(lambda x: deep_flatten(x) if type(x) == list else x, lst))))
    return result

a=deep_flatten([1, [2], [[3], 4], 5])
print(a)
# %%
#枚举列表的索引与值。
list = ["a", "b", "c", "d"]
for index, element in enumerate(list): 
    print("Value", element, "Index ", index)
# %%
#合并两个字典
def merge_dictionaries(a, b):
    return {**a, **b}

a = { 'x': 1, 'y': 2}
b = { 'y': 3, 'z': 4}
print(merge_dictionaries(a, b))
# %%
#链式函数调用:在一行代码内调用多个函数
def add(a, b):
    return a + b
def subtract(a, b):
    return a - b
a, b = 4, 5
print((subtract if a > b else add)(a, b)) # 9
# %%
#执行时间
import time
start_time = time.time()
a = 1
b = 2
c = a + b
print(c) #3
end_time = time.time()
total_time = end_time - start_time
print("Time: ", total_time)
# %%
#异常
try:
    2*3
except TypeError:
    print("An exception was raised")
else:
    print("Thank God, no exceptions were raised.")
# %%
